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
  printf(tsend((char*)"A1234567890B1234567890C1234567890D1234567890E1234567890F1234567890e1234567890f1234567890g1234567890h1234567890"));

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
  return (send(sock,data,strlen(data),0))?
}

char* transferclient::tread(){
  int bufsize = 1024;
  char* rbuf = (char*) malloc(bufsize);
  int valread = read(sock,rbuf,bufsize);
  return rbuf;
}
