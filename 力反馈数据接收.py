#Python
# bcdedit.exe /set testsigning on   关闭签名
# bcdedit.exe /set testsigning off  开启签名
#接受力反馈数据
import threading
import sys
sys.path.append("C:\\Users\\Bing\\Documents\\Python") #改成放datastruct.py的文件夹
from datastruct import *
from ctypes import *

pDll = CDLL("./Dll1.dll")  #DLL文件放在同目录下
pDll.CloseDevice()
pDll.setDevice()
pDll.bReadFile.restype = GET_EFFECT_STRUCTURE #ctypes 的接受参数设置成自定义的结构体
def data():
    while True:
        stu = pDll.bReadFile()
        s = stu.READ_CONSTANT_FROCE_DATA.Magnitude1 >> 7
        eff = ((stu.READ_CONSTANT_FROCE_DATA.Magnitude1<<8)+stu.READ_CONSTANT_FROCE_DATA.Magnitude)#赛车类游戏力反馈目前都只使用这一个  恒定力 注意大小端转换 16位数据输出
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
