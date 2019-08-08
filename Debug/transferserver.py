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

<<<<<<< Updated upstream
=======
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

def feedback_thread(m,d):
    while m.running:
        feedback = ""
        for id in m.motors:
            d.set_cRPMS(id,m.rpm[id])
            if(m.target_rpm[id]!=d.target_rpm[id]):
                m.target_rpm[id]=d.target_rpm[id]
            feedback += "M{0}".format(id)
            feedback += "Y" if m.is_on[id] else "N"#Y for On and N for Off.
            feedback += '{:5d}R'.format(m.rpm[id])
            feedback += '{:5.2f}A'.format(m.current[id])
            feedback += '{:5.2f}V'.format(m.voltage[id])
            feedback += '{:5.2f}C'.format(m.driver_temperature[id])
            if m.has_alarm[id]:
                print(m.get_alarm_description(id))
                print("Resetting Alarm...")
                m.reset_alarm(id)
        print()
        print(feedback.replace(" ",""))
        print(len(feedback))
        print(m.target_rpm)
        print(d.target_rpm)
        d.set_str(feedback.replace(" ",""))
        time.sleep(0.025)#Short delay. Remove this later if needed

>>>>>>> Stashed changes
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
                    print("HERE")
                    print(list(data))
                    exit()

updaterpms(m,zeroarr)
m.stop()
