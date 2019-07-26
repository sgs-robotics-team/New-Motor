import threading,time,math,sys
#import transfertestclient

globalval=123

def changeGlobalVal(val):
    global globalval
    globalval = val

def loop():
    i = 0
    while(i<1000):
        global globalval
        import transfertestclient as ttc
        if(i%10==0 and i>=100):
            changeGlobalVal(123456)
            i+=1;
        if(ttc.val!=globalval):
            changeGlobalVal(ttc.val)
        print("i: %d val: %d ttc.val: %d" % (i,globalval,ttc.val))
        globalval+i
        time.sleep(1)
        i=i+10

if(__name__=="__main__"):
    thread = threading.Thread(target=loop)
    thread.start()
