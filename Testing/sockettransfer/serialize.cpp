#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <stdio.h>
#include <string.h>

#include "serialize.h"

serialize::serialize(int size){
  this->size = size;
  this->ibuf = (int*) malloc(size*sizeof(int));
  this->cbuf = (char*) malloc(size+1);
  cbuf[size] = '\0';
  initialize();
  print(ibuf);
}

void serialize::initialize(){
  for(int i = 0;i < size;i++){
    *(ibuf+i)=0;
    *(cbuf+i)=(char)'0';
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

char* serialize::toChar(int *a){
  if(!checkSame(a,ibuf)){
    printf("here\n");
    cbuf = convert(a);
  }
  return cbuf;
}

char* serialize::convert(int* a){
  for(int i = 0;i<size;i++){
    cbuf[i]=a[i];
  }
  return cbuf;
}

bool serialize::checkSame(int* a,int* b){
  for(int i = 0;i < size/2;i++){
    //std::cout << i << " " << a[i] << " " << b[i] << " " << a[size-i-1] << " " << b[size-i-1] << std::endl;
    if(!(a[i]+0==b[i]+0)){
      return false;
    }else if(!(a[size-i-1]+0==b[size-i-1]+0)){
      return false;
    }
  }
  return true;
}

serialize::~serialize(){
  free(ibuf);
  free(cbuf);
}
