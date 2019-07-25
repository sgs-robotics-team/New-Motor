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

#define RECV 125
#define SEND 255

#define NUMMOTORS 8

struct header{
  char state; //255 for send,125 for recv
  char returnsize;
  uint16_t msgsize;
};

struct data{
  int val[8];
};

void htonHead(struct header h,char* buf){
  uint16_t u16;
  char s;
  s = h.state;
  memcpy(buf+0,&s,1);
  s = h.returnsize;
  memcpy(buf+1,&s,1);
  u16 = htons(h.msgsize);
  memcpy(buf+2,&u16,2);
}

void htonAttach(struct header h,char* buf,char* data){
  htonHead(h,buf+0);
  memcpy(buf+HEADERSIZE,data,strlen(data));
}

transferclient::transferclient(){ //CONSTRUCTOR
  sock = 0;
  this->size = size;
  this->returnsize = 9;
  if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
  {
    printf("ERROR: couldn't create socket\n");
  }else{
    printf("socket created\n");
  }
  if(tconnect()){
    printf("connected succesfully at %s:%d\n",HOST,PORT);
  }
}

bool transferclient::tconnect(){
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(PORT);

  if(inet_pton(AF_INET, HOST, &serv_addr.sin_addr)<=0)
  {
      printf("ERROR: invalid address or address '%s' not supported\n",HOST);
      return false;
  }

  if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
  {
      printf("ERROR: connection failed at %s:%d\n",HOST,PORT);
      return false;
  }
  return true;
}

int transferclient::tsend(char* data){
  int bufsize = HEADERSIZE+strlen(data);
  char buffer[bufsize];
  header h1 = {(char)SEND,(char)returnsize,(uint16_t)strlen(data)};
  htonAttach(h1,buffer,data);
  buffer[bufsize]='\0';
  int val =(send(sock,buffer,bufsize,0)!=-1)?1:-1;
}

int transferclient::rsend(char* data){
  int bufsize = HEADERSIZE+strlen(data);
  char buffer[bufsize];
  header h1 = {(char)RECV,(char)returnsize,(uint16_t)strlen(data)};
  htonAttach(h1,buffer,data);
  buffer[bufsize]='\0';
  int val =(send(sock,buffer,bufsize,0)!=-1)?1:-1;
  recv(sock,rbuf,1024,0);
  while(rbuf[i]!='\0'){
    printf("%c\n",rbuf[i]);
  }
  return val;
}

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
