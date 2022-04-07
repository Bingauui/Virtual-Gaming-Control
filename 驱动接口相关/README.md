DLL预留接口

void DeleteVhf() #删除虚拟HID设备
void　CreatVhf(CHAR[] reprot,int length)　＃创建HID设备　　重启会失效　需要重新调用该函数

void CloseDevice()  #关闭设备连接
void setDevice()  #设置虚拟设备连接

void bWriteFile(CHAR[] reprot,int length) #发送HID描述符定义的按钮和轴数据

GET_EFFECT_STRUCTURE bReadFile() #返回力反馈数据的结构体

GET_EFFECT_STRUCTURE.READ_CONSTANT_FROCE_DATA.Magnitude
GET_EFFECT_STRUCTURE.READ_CONSTANT_FROCE_DATA.Magnitude1 赛车游戏力反馈一般只用这个数据 其他的看结构体定义


typedef struct _SET_GET_EFFECT_STRUCTURE
{
    struct
    {
        byte report_id;
        byte effect_type;
        byte byte_count; // valid only for custom force data effect.
             // custom force effects are not supported by this device.
    }SET_REPORT_REQUEST;
    struct
    {
        byte report_id; // 2
        byte effect_block_index; // index dell'effetto
        byte block_load_status; // 1 ok, 2 -out of memory, 3 JC was here, or maybe not ? case: undefined.
        int ram_pool_available;
    }PID_BLOCK_LOAD_REPORT;
    struct
    {
        byte report_id;
        byte index;
        byte Magnitude;
        byte Magnitude1;
    }READ_CONSTANT_FROCE_DATA;

    struct {
        byte report_id;
        byte index;
        byte EffectType;
        byte Duration;
        byte Duration1;
        byte RepeatInterval;
        byte RepeatInterval1;
        byte SamplePeriod;
        byte SamplePeriod1;
        byte Gain;
        byte Gain1;
        byte TrigerButton;
        byte AxesEnable;//  2位XY轴开关 1位方向 5位固定0  00000111
        byte XDirection;
        byte YDirextion;
        byte Undefined;
        byte Undefined1;

    }SET_EFFECT_REPROT;

    struct {
        byte report_id;
        byte index;
        byte Control; // 1 - 3 1:开始 2：单独开始 3：停止
        byte LoopCount;
        byte LoopCount1;
    }EFFECT_OPERATION;

    struct {
        byte report_id;
        byte Control; // 1开启 2关闭 3 停止所有 4设备重置 5设备暂停 6 设备继续
    }DEVICE_CONTROL;

    struct {
        byte report_id;
        byte Gain;
        byte Gain1;
    }GAIN_REPORT;
    
    struct {
        byte report_id;
        byte index;
        byte EffectType;
        byte Duration;
        byte Duration1;
        byte RepeatInterval;
        byte RepeatInterval1;
        byte SamplePeriod;
        byte SamplePeriod1;
        byte Gain;
        byte Gain1;
        byte TrigerButton;
        byte AxesEnable;//  2位XY轴开关 1位方向 5位固定0  00000111
        byte XDirection;
        byte YDirextion;
        byte Undefined;
        byte Undefined1;
    }UNDEFINED_DATA;

}SET_GET_EFFECT_STRUCTURE, * PSET_GET_EFFECT_STRUCTURE;
