data = bytes([0x01,data[13],data[12],0,0,0,data[3],data[2],data[1],data[0],data[5],data[4],data[7],data[6],data[11],data[10],data[9],data[8]])
#第一位 报表ID  2-18位 定义的按钮和轴数据  

reprot = c_char_p(data)
bWriteFile(reprot,len(data))
