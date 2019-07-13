def test(val):
    print(val)
    target_rpm = [0 for x in range(len(val)-1)]

    for i in range(0,len(tvals)):
        if(i!=0):
            print(int(val[i]))
            target_rpm[i-1] = int(val[i])
        #print(identify(i,sys.argv[i]))
    print(target_rpm)
    return "av10t30a10r100".encode('ASCII','ignore')
