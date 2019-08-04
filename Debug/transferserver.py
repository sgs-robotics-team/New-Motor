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

class Data:
    def __init__(self):
        self.target_rpm=[0 for x in range(N_motors)]
        self.current_rpm=[0 for x in range(N_motors)]
        self.data_string=""

    def set_tRPMs(self,id,val):
        self.target_rpm[i]=val

    def set_cRPMS(self,id,val):
        self.current_rpms[i]=val

    def set_str(self,val):
        self.data_string=val

def feedback_thread(m,d):
    while m.running:
        feedback = ""
        for id in m.motors:
            d.current_rpm[id] = m.rpm[id]
            feedback += "M{:2d}".format(id)
            feedback += "Y" if m.is_on[id] else "N"
            feedback += '{:5d}R'.format(m.rpm[id])
            feedback += '{:5.2f}A'.format(m.current[id])
            feedback += '{:5.2f}V'.format(m.voltage[id])
            feedback += '{:5.2f}C'.format(m.driver_temperature[id])
            if m.has_alarm[id]:
                print(m.get_alarm_description(id))
                print("Resetting Alarm...")
                m.reset_alarm(id)
        print(feedback)
        d.set_str(feedback)
        time.sleep(0.05)

def command_thread(m,d):
    while m.running:

        time.sleep(0.01)

print("Starting Thrusters...")
m = thrusters.start(N_motors,port)
d = Data()

if(__name__=="__main__"):

    print("Feedback Thread Started")
    t1 = threading.Thread(target=feedback_thread, args=(m,d))
    t1.daemon = True
    t1.start()
    print("Command Thread Started")
    t2 = threading.Thread(target=command_thread, args=(m,d))
    t2.daemon = True
    t2.start()
    print("Main/Server Thread Started")
    #print(m.running)
    while m.running:
        with socket.socket(socket.AF_INET,socket.SOCK_STREAM) as s:
            s.bind((HOST,PORT))
            #s.listen(1)
            #conn, addr = s.accept()
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
                        s = d.data_string
                        conn.sendall(s.encode())
                    elif(list(data)[0]==SEND):
                        for id in m.motors:
                            if(m.target_rpm[id]!=d.target_rpm[id]):
                                m.target_rpm[id]=d.target_rpm[id]
                        print(data[4:])
                        #do stuff with motor commands here
                    #print(data.decode("ascii"))

updaterpms(m,zeroarr)
m.stop()
