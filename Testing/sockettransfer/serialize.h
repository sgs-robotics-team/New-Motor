#ifndef TRANSFERCLIENT_H
#define TRANSFERCLIENT_H

class serialize{

public:
  serialize(int size);
  ~serialize();

private:
  int a;

  int* pbuf;
  int size;


};

#endif
