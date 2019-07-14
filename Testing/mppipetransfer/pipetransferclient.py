from multiprocessing import Process,Queue,Pipe

def puts(child_conn):
    val = [7 for x in range(8)]
    child_conn.send(val)
    child_conn.close()
