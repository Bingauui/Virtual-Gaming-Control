#pragma once
#include "Froce.h"

#define IOCTL_VHFDEL CTL_CODE(FILE_DEVICE_UNKNOWN,0x800,METHOD_BUFFERED,FILE_ANY_ACCESS)
#define IOCTL_VHFCAR CTL_CODE(FILE_DEVICE_UNKNOWN,0x801,METHOD_BUFFERED,FILE_ANY_ACCESS)
#define IOCTL_READREPORTID CTL_CODE(FILE_DEVICE_UNKNOWN,0x802,METHOD_BUFFERED,FILE_ANY_ACCESS)
typedef struct _DEVICE_CONTEXT
{
    VHFHANDLE VhfHandle;
    HID_XFER_PACKET VhfHidReport;
    BOOLEAN VHFRUNING;

} DEVICE_CONTEXT, * PDEVICE_CONTEXT;
VOID WriteDispath(
	_In_
	WDFQUEUE Queue,
	_In_
	WDFREQUEST Request,
	_In_
	size_t Length);
VOID ReadDispath(
    _In_
    WDFQUEUE Queue,
    _In_
    WDFREQUEST Request,
    _In_
    size_t Length);
VOID IoControl(
    _In_
    WDFQUEUE Queue,
    _In_
    WDFREQUEST Request,
    _In_
    size_t OutputBufferLength,
    _In_
    size_t InputBufferLength,
    _In_
    ULONG IoControlCode
);