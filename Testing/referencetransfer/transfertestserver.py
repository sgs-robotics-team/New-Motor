import threading,time,math,sys

globalval=123

def changeGlobalVal(val):
    global globalval
    globalval = val

import transfertestclient

def loop():
    i = 0
    while(i<1000):
        global globalval
        if(i%10==0 and i>=100):
            changeGlobalVal(123456)
            i+=1;
        print("i: %d val: %d" % (i,globalval))
        globalval+i
        time.sleep(1)
        i=i+10

if(__name__=="__main__"):
    thread = threading.Thread(target=loop)
    thread.start()
