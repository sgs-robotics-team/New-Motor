import smart_thruster as thrusters
import socket,threading,os,selectors,time,math

HOST = '127.0.0.2'
PORT = 50008
HEADERSIZE = 5
MESSAGESIZE = 8
BUFSIZE = HEADERSIZE+MESSAGESIZE
RECV = 125
SEND = 255
N_motors = 8
port = '/dev/ttyS3'

MAX_RPM = 5000 #absolute maximum rpm of thrusters
EFC_RPM = 0.75*MAX_RPM #preferably dont use all of the RPM :)

zeroarr = [0 for x in range(N_motors)]

print("Starting Thrusters...")
m = thrusters.start(N_motors,port)

def updaterpms(m,target):
    for i in range(N_motors):
        m.target_rpm[i]=target[i]

def formatString(m,id):
    feedback = 'M{:2d}'.format(id)
    feedback += "Y" if m.is_on[id] else "N"
    feedback += '{:5d}rpm'.format(m.rpm[id])
    feedback += '{:5.2f}A'.format(m.current[id])
    feedback += '{:5.2f}V'.format(m.voltage[id])
    feedback += '{:5.2f}C'.format(m.driver_temperature[id])
    return feedback

if(__name__=="__main__"):
    thread = threading.Thread(target=main_thread, args=(m,))
    thread.start()

def main_thread(m):
    print("Python Thread Started")
    targetrpms=[0 for x in range(N_motors)]
    #print(m.running)
    while m.running:
        with socket.socket(socket.AF_INET,socket.SOCK_STREAM) as s:
            s.bind((HOST,PORT))
            #s.listen(1)
            #conn, addr = s.accept()
            for id in m.motors:
                m.target_rpm[id]=250#targetrpms[id]
                print(formatString(m,id))
                if m.has_alarm[id]:
                    print("Auto-resetting motor alarm")
                    m.reset_alarm(id)

updaterpms(m,zeroarr)
m.stop()

#youre going to have to use threads.
#you cant have the socket listen() and run the motors on serial in the same thread
# - stephen, 07/31 (1:06 am)




with conn:
                print('Connected by',addr)
                while True:
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
