#include <sys/socket.h>
#include <netinet/in.h>

#ifndef TRANSFERCLIENT_H
#define TRANSFERCLIENT_H

class transferclient{

public:
  transferclient();

  int tconnect();
  int tsend(char* data);
  char* tread();
private:


  int a;
  int valread;
  int sock;

  char* rbuf;
  struct sockaddr_in serv_addr;

};

#endif
