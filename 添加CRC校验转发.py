#Python
# bcdedit.exe /set nointegritychecks on   关闭签名
# bcdedit.exe /set nointegritychecks off  开启签名
#数据处理转发添加CRC验证
import serial
import threading
import socket
import json
import sys
sys.path.append("C:\\Users\\Bing\\Documents\\Python")
from datastruct import *
from ctypes import *
from CRC import CRC

ser = serial.Serial('COM5',57600)
#参数 （多项式，初始值,异或值，输入反转，输出反转）
CRC16 = CRC(0x18005,0xFFFF,0,True,True)
def execute(data):
    temp1 = []
    temp2 = ''
    for i in data:
        if len(data[i]) < 4:
            data[i] = data[i].rjust(4,'0')
        temp1.append(data[i][-2:])
        temp1.append(data[i][:-2])
    for i in temp1:
        temp2 = temp2+i
    Hex = CRC16.Check(temp2)
    if len(Hex) <= 3:
        if len(Hex) == 3:
            Hex = '0'+Hex
        elif len(Hex) ==2:
            Hex = '00'+Hex
        else:
            Hex = '000'+Hex
    Hex = Hex[2:] + Hex[:2]
    temp2 += Hex
    try:
        send = bytes.fromhex(temp2)
    except ValueError:
        print('入参数值错误')
        send = 'ERROR'.encode()
    len0 = ser.write(send)
    # print('输入：',send,' 长度：',len0)

def readData():
    while True:
        n = ser.in_waiting
        if n:
            read = ser.read(n)
            if(n != 6):
                continue
            print('输出：',end=" ")
            for i in range(0,n,2):
                print((read[i+1] << 8) + read[i],end=" ")
            print(n)
pDll = CDLL("./Dll1.dll")
pDll.CloseDevice()
pDll.setDevice()
pDll.bReadFile.restype = GET_EFFECT_STRUCTURE
def data():
    client = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
    client.bind(('0.0.0.0',8080))
    a = 0
    while True:
        data = client.recvfrom(128)        
        xyz = str(data[0],'utf-8')
        if(xyz=='Shutdown'):
            break
        share_data = json.loads(xyz)
        stu = pDll.bReadFile()
        s = stu.READ_CONSTANT_FROCE_DATA.Magnitude1 >> 7
        eff = ((stu.READ_CONSTANT_FROCE_DATA.Magnitude1<<8)+stu.READ_CONSTANT_FROCE_DATA.Magnitude)
        bff = 0
        if(s): 
            bff = (eff - 0x10000) -3000
            eff -= 2200
        else:
            eff += 2200
        print(bff,end="   ")
        share_data["Roll"] =  str(hex(eff))[2:].rjust(4,'0')
        execute(share_data)
        #测试用 可删
        # a = a + 1
        # if a == 1000:
        #     break

def mainprocess():
    processing = threading.Thread(target=data,daemon=True)
    thread = threading.Thread(target=readData,daemon=True)
    processing.start()
    thread.start()
    # thread.join()
    processing.join()

if __name__ == "__main__":
    ser.bytesize=8
    ser.parity=serial.PARITY_EVEN
    ser.stopbits=1
    # print(bytes.fromhex('41D86440219AFF7FFE12'))
    mainprocess()
