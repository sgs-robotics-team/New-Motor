#ifndef TRANSFERCLIENT_H
#define TRANSFERCLIENT_H

class serialize{

public:
  serialize(int size);
  ~serialize();

  void initialize();
  void print(int* a);

  int toChar(int *a);

  bool checkSame(int* a,int* b);

private:
  int a;

  int* ibuf;
  char* cbuf;
  int size;
};

#endif
