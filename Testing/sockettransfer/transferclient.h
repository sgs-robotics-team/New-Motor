#include <sys/socket.h>
#include <netinet/in.h>

#ifndef TRANSFERCLIENT_H
#define TRANSFERCLIENT_H

class transferclient{

public:
  transferclient();
  //~tranferclient();

  int tconnect();
  int tsend(char* data);
  //int tsend(int* data);
  int ssend(char* data);
  char* tread();
private:


  int a;
  int valread;
  int sock;

  char* rbuf;
  char* sbuf;
  struct sockaddr_in serv_addr;

};

#endif
