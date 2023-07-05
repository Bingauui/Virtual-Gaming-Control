#pragma once
#include <ntddk.h>
#include <wdf.h>
#include <vhf.h>
typedef unsigned char byte;
typedef struct
{
	byte report_id; // 2
	byte effect_block_index; // index dell'effetto
	byte block_load_status; // 1 ok, 2 -out of memory, 3 JC was here, or maybe not ? case: undefined.
	int ram_pool_available;
}PID_BLOCK_LOAD_REPORT;
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

typedef struct _WRITEREPORTBUFFER {
	int bufferLeng;
	unsigned char buffer[2048];
}WRITEREPORTBUFFER, * PWRITEREPORTBUFFER;
void SetEffect(PSET_GET_EFFECT_STRUCTURE pset_get_effect, byte* buffer);

VOID WriterReport(
	_In_
	PVOID VhfClientContext,
	_In_
	VHFOPERATIONHANDLE VhfOperationHandle,
	_In_opt_
	PVOID VhfOperationContext,
	_In_
	PHID_XFER_PACKET HidTransferPacket);

VOID SetFeature(
	_In_
	PVOID VhfClientContext,
	_In_
	VHFOPERATIONHANDLE VhfOperationHandle,
	_In_opt_
	PVOID VhfOperationContext,
	_In_
	PHID_XFER_PACKET HidTransferPacket);

VOID GetFeature(
	_In_
	PVOID VhfClientContext,
	_In_
	VHFOPERATIONHANDLE VhfOperationHandle,
	_In_opt_
	PVOID VhfOperationContext,
	_In_
	PHID_XFER_PACKET HidTransferPacket);
