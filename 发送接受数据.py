#Python
# bcdedit.exe /set testsigning on   关闭签名
# bcdedit.exe /set testsigning off  开启签名
#数据处理转发添加CRC验证
import threading
import socket
import json
import sys
sys.path.append("C:\\Users\\Bing\\Documents\\Python") #改成放datastruct.py的文件夹
from datastruct import *
from ctypes import *

pDll = CDLL("./Dll1.dll")
pDll.CloseDevice()
pDll.setDevice()
pDll.bReadFile.restype = GET_EFFECT_STRUCTURE
def data():
    while True:
        stu = pDll.bReadFile()
        s = stu.READ_CONSTANT_FROCE_DATA.Magnitude1 >> 7
        eff = ((stu.READ_CONSTANT_FROCE_DATA.Magnitude1<<8)+stu.READ_CONSTANT_FROCE_DATA.Magnitude)
        if(s): 
            eff -= 2200
        else:
            eff += 2200

def mainprocess():
    thread = threading.Thread(target=data,daemon=True)
    thread.start()
    thread.join()

if __name__ == "__main__":
    mainprocess()
