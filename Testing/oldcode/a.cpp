
//printf("%d %d\n",(int)sizeof(rpmcharbuffer),(int)strlen(rpmcharbuffer));

/*
  for(int i = 0;i < 1000;i++){
    targetRPM[5]=i+1;
    char* rpmcharbuffer = so.toChar(targetRPM);
    tco.tsend(rpmcharbuffer);
  }
*/

/*
while(rpmcharbuffer[i]!='\0'){
  printf("loop 2: %c\n",rpmcharbuffer[i]);
  i++;
}
*/

//#define PORT 50008
//#define HOST "127.0.0.1"

//using namespace std;


//tco.tsend(rpmcharbuffer);

/*
transferclient tc;
char* a = (char*)"client says hello, and asks how server is doing.\0";
tc.tsend(a);

int bufsize = NUMMOTORS;
char buf[bufsize+1];




int d = sizeof(c);
int e = sizeof(int);
printf("%d\n",d);

for(int i = 0;i < NUMMOTORS;i++){
  buf[i]=c[i];
  printf("%d %d\n",buf[i],c[i]);
}
buf[bufsize]='\0';
for(int i = 0;i < sizeof(buf);i++){
  printf("%c\n",buf[i]);
}
printf("%d %d\n",(int)sizeof(buf),(int)strlen(buf));
tc.tsend(buf);

//tsend(a);
//tsend(b);
/*
char *a = (char*)"testing, jacky is a legend and so is gary\0";
int bufsize = strlen(a);
char buffer[bufsize];

cout << bufsize << " " << a << endl;

memcpy(buffer+0,a,bufsize);
cout << buffer << endl;
*/

/*
int main(){

  int sock = 0, valread;
  struct sockaddr_in serv_addr;
  char *hello = (char*)"Hello from client Hello from client2 Hello from client3";
  char buffer[1024] = {0};
  if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
  {
      printf("\n Socket creation error \n");
      return -1;
  }

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(PORT);

  // Convert IPv4 and IPv6 addresses from text to binary form
  if(inet_pton(AF_INET, HOST, &serv_addr.sin_addr)<=0)
  {
      printf("\nInvalid address/ Address not supported \n");
      return -1;
  }

  if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
  {
      printf("\nConnection Failed at %s:%d\n",HOST,PORT);
      return -1;
  }

  for(int i = 0;i < 5;i++){
      send(sock , hello , strlen(hello) , 0 );
      printf("Hello message sent\n");
      valread = read( sock , buffer, 1024);
      printf("%s\n",buffer );
  }
  return 0;
}
*/
