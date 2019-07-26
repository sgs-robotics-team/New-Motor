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
    for i in range(0,100):
        store([1,2,3,4,i])
        print(load())
        time.sleep(0.02)
    #load array/list into thread
