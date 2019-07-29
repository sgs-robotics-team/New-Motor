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

if(__name__=="__main__"):
    print("Python Thread Started")
    targetrpms=[0 for x in range(N_motors)]
    #print(m.running)
    while m.running:
        with socket.socket(socket.AF_INET,socket.SOCK_STREAM) as s:
            s.bind((HOST,PORT))
            s.listen(1)
            conn, addr = s.accept()
            for id in m.motors:
                m.target_rpm[id]=250#targetrpms[id]
                motor_feedback = 'Motor {:2d}: '.format(id)
                motor_feedback += "ON  " if m.is_on[id] else "OFF "
                motor_feedback += '{:5d}rpm '.format(m.rpm[id])
                motor_feedback += '{:5.2f}A '.format(m.current[id])
                motor_feedback += '{:5.2f}V '.format(m.voltage[id])
                motor_feedback += '{:5.2f}C '.format(m.driver_temperature[id])
                motor_feedback += 'Alarm: ' + m.get_alarm_description(id)
                print(motor_feedback)
                if m.has_alarm[id]:
                    print("Auto-resetting motor alarm")
                    m.reset_alarm(id)
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

updaterpms(m,zeroarr)
m.stop()
