import smart_thruster as thrusters
import socket,threading,os,selectors,time,math

HOST = '127.0.0.2'
PORT = 50008
HEADERSIZE = 5 #in bytes
MESSAGESIZE = 8*2 #in bytes
BUFSIZE = HEADERSIZE+MESSAGESIZE
RECV = 125
SEND = 255

N_motors = 8
port = '/dev/ttyS3'

#print("Starting Thrusters...")
#m = thrusters.start(N_motors,port)

class Data:
    def __init__(self):
        self.target_rpm=[0 for x in range(N_motors+1)]
        self.current_rpm=[0 for x in range(N_motors+1)]
        self.data_string=""
        self.str_length=0

    def get_tRPMs(self):
        return self.target_rpm

    def get_cRPMs(self):
        return self.current_rpm

    def set_tRPMs(self,id,val):
        self.target_rpm[id]=val

    def set_cRPMS(self,id,val):
        self.current_rpm[id]=val

    def set_str(self,val):
        self.data_string=val
        self.str_length=len(val)

def head(): #looks at header



def main_thread():
    while True: #replace with while(m.running):
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

if(__name__=="__main__"):
    thread = threading.Thread(target=main_thread)
    thread.start()
