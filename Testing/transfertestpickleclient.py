import pickle

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
    store([1,2,3,4,2126])
    print(load())
    #load array/list into thread
