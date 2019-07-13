import pickle,threading,time

def store(val):
    file = open('data','ab')
    pickle.dump(val,file)
    file.close()

def load():
    file = open('data','rb')
    data = pickle.load(file)
    file.close()
    return data

def loop(): #set delay? rolloff?
    i = 0
    c = Client()
    while(i<1000):
        print(i)
        print(c.getBuf())
        c.detect()
        time.sleep(0.01)
        i=i+1

class Client():

    buffer = ""
    def __init__(self):
        self.buffer = [0 for x in range(8)]
        print(self.buffer)

    def getBuf(self):
        return self.buffer
    def setBuf(self,val):
        self.buffer = val

    def detect(self):
        temp = load()
        if(temp==self.getBuf()):
            return 1
        else:
            print("detecting change")
            self.setBuf(temp)
            return -1


if(__name__=="__main__"):
    thread = threading.Thread(target=loop)
    thread.start()
