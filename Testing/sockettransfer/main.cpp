#include <iostream>
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#include "serialize.h"
#include "transferclient.h"


#define NUMMOTORS 8
#define RECV 125
#define SEND 255

int main(){

  printf("\n---START---\n");
  transferclient tco;
  serialize so((int)NUMMOTORS);

  int targetRPM[] = {100,1,5,1,1,1,100,101};

  targetRPM[4]=100;

  char* rpmcharbuffer = so.toChar(targetRPM);
  char* nullbuffer = so.toChar();


  tco.tsend(rpmcharbuffer,0);
  tco.tsend(nullbuffer,125);
  tco.tsend(rpmcharbuffer,255);

  printf("\n---END---\n");
  return 0;
}
