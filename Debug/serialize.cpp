#include <cstdlib>
#include <cstdio>
#include <stdio.h>
#include <string.h>

#include "serialize.h"

serialize::serialize(int size){
  this->size = size;
  this->ibuf = (int*) malloc(size*sizeof(int));
  this->cbuf = (char*) malloc(size);
  this->nbuf = (char*) malloc(size);
  initialize();
  printf("Serialize: Buffers Initialized\n");
}

void serialize::initialize(){
  for(int i = 0;i < size;i++){
    ibuf[i]=0;
    nbuf[i]=10;
  }
}

void serialize::print(int* a){
  printf("[");
  for(int i = 0;i < size;i++){
    if(i==size-1){
      printf("%d",a[i]);
      break;
    }
    printf("%d,",a[i]);
  }
  printf("]\n");
}

char* serialize::itoC(int *a){
  if(!checksame(a,ibuf)){
    cbuf = convert(a);
    //setibuf(a);
  }
  return cbuf;
}

char* serialize::getNull(){
  return nbuf;
}

char* serialize::getChar(){
  return cbuf;
}

int* serialize::getInt(){
  return ibuf;
}

char* serialize::convert(int* a){
  for(int i = 0;i<size;i++){
    cbuf[i]=a[i];
    ibuf[i]=a[i];
    //printf("convert: %c %d\n",cbuf[i],a[i]);
  }
  //cbuf[size]='\0';
  //printf("%d \n",(int)sizeof(ibuf));
  return cbuf;
}

void serialize::setibuf(int* a){
  ibuf = a;
}

bool serialize::checksame(int* a,int* b){
  for(int i = 0;i < size/2;i++){
    if(!(a[i]+0==b[i]+0)){
      return false;
    }else if(!(a[size-i-1]+0==b[size-i-1]+0)){
      return false;
    }
  }
  return true;
}

void serialize::test(){
  printf("Serialize class functional\n");
}

serialize::~serialize(){
  printf("Serialize: Shutting down...\n");
  free(ibuf);
  free(cbuf);
  free(nbuf);
  printf("Serialize: Buffers freed.\n");
}
