#include <sys/socket.h>
#include <netinet/in.h>

#ifndef TRANSFERCLIENT_H
#define TRANSFERCLIENT_H

class transferclient{

public:
  transferclient();
  //~tranferclient();

  bool tconnect();
  int tsend(char* data);
  int rsend(char* data);
  int ssend(char* data);
  char* tread();
private:
  int a;

  int valread;
  int sock;
  int size;
  int returnsize;

  char* rbuf;

  struct sockaddr_in serv_addr;

};

#endif
