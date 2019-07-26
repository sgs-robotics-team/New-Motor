#ifndef SERIALIZE_H
#define SERIALIZE_H

class serialize{

public:
  serialize(int size);
  ~serialize();

  void initialize();
  void print(int* a);

  char* toChar(int *a);
  char* toChar();

private:
  int a;

  void setibuf(int* a);
  bool checksame(int* a,int* b);
  char* convert(int* a);

  int* ibuf;
  char* cbuf;
  char* nbuf;
  int size;
};

#endif
