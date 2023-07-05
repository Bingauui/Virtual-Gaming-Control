// pch.h: 这是预编译标头文件。
// 下方列出的文件仅编译一次，提高了将来生成的生成性能。
// 这还将影响 IntelliSense 性能，包括代码完成和许多代码浏览功能。
// 但是，如果此处列出的文件中的任何一个在生成之间有更新，它们全部都将被重新编译。
// 请勿在此处添加要频繁更新的文件，这将使得性能优势无效。

#ifndef PCH_H
#define PCH_H
#define DLLEXPORT extern "C" __declspec(dllexport) 
#define IOCTL_VHFDEL CTL_CODE(FILE_DEVICE_UNKNOWN,0x800,METHOD_BUFFERED,FILE_ANY_ACCESS)
#define IOCTL_VHFCREAT CTL_CODE(FILE_DEVICE_UNKNOWN,0x801,METHOD_BUFFERED,FILE_ANY_ACCESS)
typedef unsigned char byte;
DLLEXPORT int sun(int i, int y);

typedef union {
	struct {
		byte reprotid;
		byte const1;
		unsigned short button;
		int AsixXorY;
		int AsixZorRx;
		int AsixRyorRz;
		int Wheel;

	}AsixData;
	struct {
		byte reprotid;
		byte const1;
		byte button;
		byte button1;
		byte x;
		byte x1;
		byte y;
		byte y1;
		byte z;
		byte z1;
		byte Rx;
		byte Rx1;
		byte Ry;
		byte Ry1;
		byte Rz;
		byte Rz1;
		byte Whell;
		byte Whell1;
		
	}AsixDataChra;

}Data;

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
// 添加要在此处预编译的标头
#include "framework.h"

#endif //PCH_H
