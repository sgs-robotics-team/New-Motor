#ifndef SERIALIZE_H
#define SERIALIZE_H

class serialize{

public:
  serialize(int size);
  ~serialize();

  void initialize();
  void print(int* a);
  char* toChar(int *a);

private:
  int a;

  void setibuf(int* a);
  bool checkSame(int* a,int* b);
  char* convert(int* a);

  int* ibuf;
  char* cbuf;
  int size;
};

#endif
