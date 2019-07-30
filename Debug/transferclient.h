#include <sys/socket.h>
#include <netinet/in.h>

#ifndef TRANSFERCLIENT_H
#define TRANSFERCLIENT_H

class transferclient{

public:
  transferclient();
  ~transferclient();

  bool tconnect();
  int tsend(char* data);//transfer send
  char* rsend(char* data);//receive send
  int ssend(char* data);//simple send
  int csend();//close send (header only)
private:
  int a;

  int valread;
  int sock;
  int size;
  int returnsize;

  struct sockaddr_in serv_addr;

};

#endif
