#include <iostream>
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#include "serialize.h"
#include "transferclient.h"
#include "motor.h"

#define RECV 125
#define SEND 255

int main(){

  //transferclient tco;
  //serialize so((int)NUMMOTORS);
  motor mo;
  printf("\n---START---\n");


  uint16_t test = 4598;
  printf("%d\n",test);
  unsigned char a = (unsigned char)(test>>8);
  unsigned char b = (unsigned char)(test & 0xff);
  printf("%d\n",(test>>8));
  char* cbuf = (char*) malloc(2);
  cbuf[0]=a;
  cbuf[1]=b;
  for(int i = 0;i<strlen(cbuf);i++){
    printf("%d\n",(cbuf[i]));
  }
  uint16_t result = (a<<8)+b;
  printf("%d\n",result);
  free(cbuf);
  /*

  mo.setTargetRPM(99);
  for(int i = 0;i < mo.getSize();i++){
    printf("target: %d current: %d\n",mo.getTargetRPM()[i],mo.getCurrentRPM()[i]);
  }
  */
  printf("\n---END---\n\n");
  return 0;
}

void loop(){//main loop?
  printf("test");
}


/*
transferclient tco;
serialize so((int)NUMMOTORS);

int targetRPM[] = {100,1,5,1,1,1,100,101};

targetRPM[4]=100;

char* rpmcharbuffer = so.toChar(targetRPM);
char* nullbuffer = so.toChar();

//tco.tsend(rpmcharbuffer);
char* readvalues = tco.rsend(nullbuffer);
int i = 0;
while(readvalues[i]!='\0'){
  printf("%c",readvalues[i]);
  i++;
}
//tco.tsend(rpmcharbuffer);
*/
