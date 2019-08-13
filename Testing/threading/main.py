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

testcycles=1000000

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
        for x in range(testcycles):
            self.target_rpm[i]=x
            self.current_rpm[i]=x+2
            self.thruster_volts[i]=x+0.2
            self.thruster_temps[i]=x+0.5
            self.thruster_amps[i]=x+1.3

    def normal_update(self,i):
        for x in range(testcycles):
            self.target_rpm[i]=x
            self.current_rpm[i]=x+2
            self.thruster_volts[i]=x+0.2
            self.thruster_temps[i]=x+0.5
            self.thruster_amps[i]=x+1.3

if(__name__=="__main__"):
    t = ThrusterData()

    s1 = time.time()
    print("S1")
    for index in range(N_motors):
        t.normal_update(index)
    s2 = time.time()

    print(t.thruster_amps[:10])

    s2 = time.time()
    print("S2")
    with concurrent.futures.ThreadPoolExecutor(max_workers=N_motors) as executor:
        for index in range(N_motors):
            executor.submit(t.threaded_update,index)
    s3 = time.time()

    print(t.thruster_amps[:10])
    print("S3")
    print("s1-s2: %f"%(s2-s1))
    print("s2-s3: %f"%(s3-s2))
