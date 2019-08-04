import socket,threading,os,selectors,time,math,logging
import concurrent.futures

HOST = '127.0.0.2'
PORT = 50008
HEADERSIZE = 5
MESSAGESIZE = 8
BUFSIZE = HEADERSIZE+MESSAGESIZE
RECV = 125
SEND = 255
N_motors = 15
port = '/dev/ttyS3'

MAX_RPM = 5000 #absolute maximum rpm of thrusters
EFC_RPM = 0.75*MAX_RPM #preferably dont use all of the RPM :)

#zeroarr = [0 for x in range(N_motors)]

print("Starting Thrusters...")
m = thrusters.start(N_motors,port)

class ThrusterData:
    def __init__(self):
        self.target_rpm=[0 for x in range(N_motors)]
        self.current_rpm=[0 for x in range(N_motors)]
        self.thruster_volts=[0.0 for x in range(N_motors)]
        self.thruster_temps=[0.0 for x in range(N_motors)]
        self.thruster_amps=[0.0 for x in range(N_motors)]
        self._lock = threading.Lock()

    def threaded_update(self,i):
        self.target_rpm[i]=333
        self.current_rpm[i]=275
        self.thruster_volts[i]=16.10
        self.thruster_temps[i]=42.30
        self.thruster_amps[i]=1.23

    def normal_update(self):
        for i in range(N_motors):
            self.target_rpm[i]=333
            self.current_rpm[i]=275
            self.thruster_volts[i]=16.10
            self.thruster_temps[i]=42.30
            self.thruster_amps[i]=1.23

if(__name__=="__main__"):
    t = ThrusterData()
    s1 = time.time()
    print("S1")
    t.normal_update()
    s2 = time.time()
    with concurrent.futures.ThreadPoolExecutor(max_workers=2) as executor:
        for index in range

    s3 = time.time()
    print("Finished")
    print("s2: %f"%(s2-s1))
    print("s3: %f"%(s3-s2))
