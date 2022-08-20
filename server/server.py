import socket
import os
from telnetlib import NOP
import threading
from datetime import datetime

threadsmax = 2
host = "127.0.0.1"
port = 5175
logspath = ""

def listenfordata(conn, dirpath):
    logpath = dirpath + "/" + str(datetime.time(datetime.now())).replace(":", " ")
    log = open(logpath[:logpath.rfind(".")] + ".log", "wb")
    with conn:
        log.write(str.encode("[" + datetime.ctime(datetime.now()) + "]   " + "Client " + str(addr) + " connected\n"))
        log.flush()
        while True:
            try:
                data = conn.recv(10000)
                if data == "":
                    log.write(str.encode("\n[" + datetime.ctime(datetime.now()) + "]   " + "Error - no data\n"))
                    log.flush()
                else:
                    log.write(data)
                    log.flush()
            except:
                print("Client disconnected")
                log.write(str.encode("\n[" + datetime.ctime(datetime.now()) + "]   " + "Client " + str(addr) + " disconnected\n"))
                log.flush()
                log.close()
                break

dirpath = os.path.join(logspath, str(datetime.date(datetime.now())).replace(" ", "_"))
try:
    os.mkdir(dirpath)
except:
    NOP

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.bind((host, port))
    s.listen()
    threads = []
    buffer = []
    alive = 0
    while True:
        conn, addr = s.accept()
        alive = 0
        for t in threads:
            if t.is_alive():
                buffer.append(t)
                alive = alive + 1
        if alive == threadsmax:
            print("Too much threads")
        else:
            threads.clear()
            threads = buffer.copy()
            buffer.clear()
            thr = threading.Thread(target=listenfordata, args=(conn, dirpath,)) 
            thr.start()
            threads.append(thr)
            print("Active threads: " + str(alive + 1))
