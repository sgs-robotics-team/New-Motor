import socket
import threading
import os
import selectors


HOST = '127.0.0.2'
PORT = 50008

while True:
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
                data = conn.recv(1024)
                if not data:
                    break
                conn.sendall(b'testingtesting')
                print(data)
                print(list(data))
                #print(data.decode("ascii"))
