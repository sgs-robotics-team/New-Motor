import pickle,time

def store(val):
    file = open('data','wb')
    pickle.dump(val,file)
    file.close()

def load():
    file = open('data','rb')
    data = pickle.load(file)
    file.close()
    return data

if(__name__=="__main__"):
    for i in range(0,10000):
        store([1,2,3,i,2*i,121,24,214,24,12,41,24,12,4,124,12,41,2412,4,124,1,20])
        print(load())
        time.sleep(0.025)
