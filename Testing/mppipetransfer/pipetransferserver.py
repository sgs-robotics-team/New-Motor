import threading,time
from multiprocessing import Process,Queue,Pipe
from pipetransferclient import puts

def gets():
    parent_conn,child_conn = Pipe()
    p = Process(target=puts,args=(child_conn,))
    p.start()
    print(parent_conn.recv())

def loop():
    i=0
    temp = [0 for x in range(8)]
    while(1==1):
        print(i)
        temp = gets()
        print(temp)
        i+=1

if(__name__=="__main__"):
    thread = threading.Thread(target=loop)
    thread.start()
