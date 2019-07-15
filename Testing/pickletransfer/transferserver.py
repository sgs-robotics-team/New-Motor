import pickle,time,os
from pathlib import Path

def store(val):
    with open('data','wb') as file:
        pickle.dump(val,file)
        file.close()

def load():
    with open('data','rb') as file:
        try:
            data = pickle.load(file)
            file.close()
            return data
        except EOFError:
            print("EOFError Caught")
            return 0


class Client():

    buffer = ""
    def __init__(self):
        self.buffer = [0 for x in range(8)]
        my_file = Path("./data")
        if(my_file.is_file()==False):
            store(self.buffer)
        print(self.buffer)

    def getBuf(self):
        return self.buffer
    def setBuf(self,val):
        self.buffer = val

    def detect(self):
        temp = load()
        if(temp==self.getBuf() or temp==0):
            return False
        else:
            #print("detecting change")
            self.setBuf(temp)
            return True

    def close(self):
        print("closing...")
        my_file = Path("./data")
        if(my_file.is_file()):
            try:
                os.remove("./data")
            except OSError as e:
                print("Error: %s - %s" % (e.filename,e.strerror))

    def __del__(self):
        print("1closing...")
        my_file = Path("./data")
        if(my_file.is_file()):
            try:
                os.remove("./data")
            except OSError as e:
                print("Error: %s - %s" % (e.filename,e.strerror))
        #exit(0)

if(__name__=="__main__"):
    c = Client()
    #try:
    for i in range(10000):
        time.sleep(0.0125)
        if(c.detect()):
            print(c.getBuf()[3])
    #except:
        #print("Closing...")
        #print(c.getBuf())
        #c.close()
        #exit(1)
