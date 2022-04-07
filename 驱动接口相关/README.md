DLL预留接口

void DeleteVhf() #删除虚拟HID设备
void　CreatVhf(CHAR[] reprot,int length)　＃创建HID设备　　重启会失效　需要重新调用该函数

void CloseDevice()  #关闭设备连接
void setDevice()  #设置虚拟设备连接

void bWriteFile(CHAR[] reprot,int length) #发送HID描述符定义的按钮和轴数据

GET_EFFECT_STRUCTURE bReadFile() #返回力反馈数据的结构体

GET_EFFECT_STRUCTURE.READ_CONSTANT_FROCE_DATA.Magnitude
GET_EFFECT_STRUCTURE.READ_CONSTANT_FROCE_DATA.Magnitude1 赛车游戏力反馈一般只用这个数据 其他的看结构体定义
