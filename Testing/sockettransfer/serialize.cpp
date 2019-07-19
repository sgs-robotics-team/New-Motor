#include <cstdlib>
#include <cstdio>
#include <iostream>

#include "serialize.h"

serialize::serialize(int size){
  this->size = size;
  this->ibuf = (int*) malloc(size*sizeof(int));
  initialize();
  print(ibuf);
}

void serialize::initialize(){
  for(int i = 0;i < size;i++){
    *(ibuf+i)=0;
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

int serialize::toChar(int *a){
  print(cbuf)


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
}
