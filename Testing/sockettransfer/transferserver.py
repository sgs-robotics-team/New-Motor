import socket
import threading
import os
import selectors

HOST = '127.0.0.2'
PORT = 50008
HEADERSIZE = 5
MESSAGESIZE = 8
BUFSIZE = HEADERSIZE+MESSAGESIZE
RECV = 125
SEND = 255


with socket.socket(socket.AF_INET,socket.SOCK_STREAM) as s:
    i=0
    s.bind((HOST,PORT))
    s.listen(1)
    conn, addr = s.accept()
    with conn:
        print('Connected by',addr)
        while True:
            print(i)
            i+=1;
            data = conn.recv(BUFSIZE)
            #conn.sendall(b'testingtesting')
            if not data:
                break
            print(data)
            print(list(data))
            #print(list(data[4:]))
            if(list(data)[0]==RECV):
                s = "Hi, server says hi after receiving from client"
                print("sending: %s" % s)
                conn.sendall(s.encode())
            elif(list(data)[0]==SEND):
                print("received:")
                print(data[4:])
                #do stuff with motor commands here
            #print(data.decode("ascii"))
