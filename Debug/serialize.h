/**
    SGS Robotics
    serialize.h

    @author Stephen Yang
    @version 1.1 8/08/19
*/
#ifndef SERIALIZE_H
#define SERIALIZE_H

class serialize{

public:
  serialize(int size);
  ~serialize();

  void initialize();
  void print(int* a);

  char* iToC(int *a);

  char* getNullBuf();
  char* getCharBuf();
  int* getIntBuf();

  void test();

private:

  void setIntBuf(int* a);
  bool checkSimilarity(int* a,int* b);
  char* convert(int* a);

  int* ibuf;
  char* cbuf;
  char* nbuf;
  int size;
};

#endif
