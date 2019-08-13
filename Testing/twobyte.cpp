#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <cstdlib>
#include <cstdio>
#include <string.h>

#define size 8

unsigned char* iToC(int* a);
int* cToI(unsigned char* a);

unsigned char* cbuf;//cbuf needs to be array of unsigned char
int* ibuf;

int main(){
  int targetRPM[] = {1010,0,5000,121,65537,1,65536,7776};
  for(int i = 0;i < sizeof(targetRPM)/sizeof(int);i++){
    printf("%d ",targetRPM[i]);
  }
  printf("\n");
  printf("size of char array: %d\n",(int)sizeof(targetRPM)/2);
  printf("sizeof(int): %d\n",(int)sizeof(int));
  cbuf = (unsigned char*) malloc(sizeof(targetRPM)/sizeof(int)*2);
  ibuf = (int*) malloc(sizeof(targetRPM));
  cbuf = iToC(targetRPM);
  cToI(cbuf);
}

unsigned char* iToC(int* a){
  printf("size: %d\n",(int)sizeof(a));
  for(int i = 0;i<(int)sizeof(a);i++){//i<number of indices in targetRPM
    cbuf[2*i] = (char)(a[i]>>8);
    cbuf[2*i+1] =(char)(a[i] & 0xff);
    printf("%d %d ",cbuf[2*i],cbuf[2*i+1]);
  }
  printf("\n");
  return cbuf;
}

int* cToI(unsigned char* a){
  printf("size: %d\n",(int)sizeof(a));
  for(int i = 0;i<(int)sizeof(a);i++){//i<number of indices in targetRPM times 2
    ibuf[i] = (a[2*i]<<8)+a[2*i+1];
    printf("%d ",ibuf[i]);
  }
  printf("\n");
  return ibuf;
}