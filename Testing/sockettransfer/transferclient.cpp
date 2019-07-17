#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#include "transferclient.h"

#define PORT 50008
#define HOST "127.0.0.1"

transferclient::transferclient(){
  sock = 0;
  if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
  {
      printf("\n Socket creation error \n");
  }
  tconnect();
  tsend((char*)"Hello Gary u are too good");

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
  return (send(sock,data,strlen(data),0)!=-1)?1:-1;
}

char* transferclient::tread(){
  int bufsize = 1024;
  char* rbuf = (char*) malloc(bufsize);
  int valread = read(sock,rbuf,bufsize);
  return rbuf;
}
