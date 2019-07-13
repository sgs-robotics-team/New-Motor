import sys

def identify(i,val):
    if(val.isDigit()):
        return 0;
    elif(val=="stop"):
        return 1;
    return -1;

def input(val):
    target_rpm = [0 for x in len(0,sys.argv)]
    for i in range(0,len(val)):
        target_rpm=val[i]

def thrust(percent):#code arguments given as "percent of max thrust"
    #which should be a value between 0 and 100
    return max_thrust_value*percent

if(__name__=="__main__"):
    tvals = sys.argv
    target_rpm = [0 for x in range(len(sys.argv)-1)]

    for i in range(0,len(tvals)):
        if(i!=0):
            print(int(sys.argv[i]))
            target_rpm[i-1] = int(sys.argv[i])
        #print(identify(i,sys.argv[i]))
    print(target_rpm)
    return "av10t30a10r100".encode('ASCII','ignore')

def test():
    tvals = sys.argv
    target_rpm = [0 for x in range(len(sys.argv)-1)]

    for i in range(0,len(tvals)):
        if(i!=0):
            print(int(sys.argv[i]))
            target_rpm[i-1] = int(sys.argv[i])
        #print(identify(i,sys.argv[i]))
    print(target_rpm)
    #return "av10t30a10r100".encode('ASCII','ignore')
