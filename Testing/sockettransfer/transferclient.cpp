#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#include "transferclient.h"

#define PORT 50008
#define HOST "127.0.0.2"
#define HEADERSIZE 4

struct header{
  uint16_t state; //0 for send,1 for recv
  uint16_t msgsize;
};

struct data{
  int val[8];
};

void htonHead(struct header h,char* sbuf){
  uint16_t u16;
  u16 = htons(h.state);
  memcpy(sbuf+0,&u16,2);
  u16 = htons(h.msgsize);
  memcpy(sbuf+2,&u16,2);
}

void htonAttach(struct header h,char* sbuf,char* data){
  std::cout << data << std::endl;
  htonHead(h,sbuf+0);
  memcpy(sbuf+4,data,strlen(data));
  std::cout << strlen(data) << "\n";
}

transferclient::transferclient(){
  sock = 0;
  if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
  {
      printf("\n Socket creation error \n");
  }
  tconnect();
  char* a = (char*)"client says hello, and asks how server is doing.\0";

  int c[8] = {100,100,100,99,100,23,26,97};
  char* b = (char*) c;

  tsend(a);
  tsend(b);

  printf("success.\n");

}

int transferclient::tconnect(){
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(PORT);

  if(inet_pton(AF_INET, HOST, &serv_addr.sin_addr)<=0)
  {
      printf("\nInvalid address/ Address '%s' not supported \n",HOST);
      return -1;
  }

  if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
  {
      printf("\nConnection Failed at %s:%d\n",HOST,PORT);
      return -1;
  }
  return 1;
}

int transferclient::tsend(char* data){
  //send(sock,)
  int bufsize = HEADERSIZE+strlen(data);
  char buffer[bufsize];
  header h1 = {0,(uint16_t)strlen(data)};
  htonAttach(h1,buffer,data);
  int val =(send(sock,buffer,bufsize,0)!=-1)?1:-1;
  //recv(sock,rbuf,strlen(data),0);
  //std::cout << rbuf << std::endl;
  return val;
}
/*
int transferclient::tsend(int* data){
  int bufsize = HEADERSIZE+strlen(data);
  char buffer[bufsize];
  header h1 = {0,(uint16_t)strlen(data)};
  htonAttach(h1,buffer,data);
  int val = (send(sock,data,sizeof(data),0)!=-1)?1:-1;
  return val;
}
*/
int transferclient::ssend(char* data){
  int val =(send(sock,data,strlen(data),0)!=-1)?1:-1;
  return val;
}

char* transferclient::tread(){
  int bufsize = 1024;
  char* rbuf = (char*) malloc(bufsize);
  int valread = read(sock,rbuf,bufsize);
  return rbuf;
}
