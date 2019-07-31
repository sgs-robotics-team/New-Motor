#ifndef SERIALIZE_H
#define SERIALIZE_H

class serialize{

public:
  serialize(int size);
  ~serialize();

  void initialize();
  void print(int* a);

  char* itoC(int *a);

  char* getNull();
  char* getChar();
  int* getInt();

  void test();

private:

  void setibuf(int* a);
  bool checksame(int* a,int* b);
  char* convert(int* a);

  int* ibuf;
  char* cbuf;
  char* nbuf;
  int size;
};

#endif
