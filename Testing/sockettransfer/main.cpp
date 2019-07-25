#include <iostream>
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#include "serialize.h"
#include "transferclient.h"


#define NUMMOTORS 8


int main(){

  printf("\n---START---\n");
  transferclient tco;
  serialize so((int)NUMMOTORS);

  int targetRPM[] = {100,1,5,1,1,1,100,101};

  targetRPM[4]=100;

  char* rpmcharbuffer = so.toChar(targetRPM);
  printf("%d %d\n",(int)sizeof(rpmcharbuffer),(int)strlen(rpmcharbuffer));


  int i = 0;

  tco.tsend(rpmcharbuffer);


  printf("\n---END---\n");
  return 0;
}
