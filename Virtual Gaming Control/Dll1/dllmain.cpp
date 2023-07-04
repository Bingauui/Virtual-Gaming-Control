// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "pch.h"
#include <stdio.h>
#include <windows.h>
#include <iostream>
#include <hidclass.h>
#include <hidsdi.h>
#include <SetupAPI.h>
#include <winioctl.h>
#include <conio.h>
// 添加要在此处预编译的标头

HANDLE Device = NULL;
SET_GET_EFFECT_STRUCTURE buffer = {0};
Data data = { 0 };
bool b;
DLLEXPORT void sum(PUCHAR s, int y) {
	for (int i = 0; i < y; i++) {
		printf("%d ", s[i]);
	}
}

DLLEXPORT void setDevice() {
	if (Device != NULL) {
		printf("设备对象已打开，请关闭后在试");
		return;
	}
    Device = CreateFile(L"\\\\.\\.GameControl", GENERIC_ALL, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, NULL);
    if (Device == NULL || Device == INVALID_HANDLE_VALUE)
    {
        printf("设备对象打开失败，错误原因(%08X)\n", GetLastError());
        system("pause");
    }
}

HANDLE getDevice() {
    return Device;
}
DLLEXPORT int bReadFile() {
	if (Device == NULL || Device == INVALID_HANDLE_VALUE) {
		printf("请初始化Device在调用");
		return 0;
	}
	b = ReadFile(Device, &buffer, 60, NULL, NULL);
	if (b) {
		
		return (buffer.READ_CONSTANT_FROCE_DATA.Magnitude1 << 8) + buffer.READ_CONSTANT_FROCE_DATA.Magnitude;
	}
	return 0;
}
DLLEXPORT int bWriteFile(int reprot, int button,int x,int y,int z,int whell) {
	if (Device == NULL || Device == INVALID_HANDLE_VALUE) {
		printf("请初始化Device在调用");
		return 0;
	}
	
	data.AsixData.AsixXorY = x;
	data.AsixData.AsixZorRx = y;
	data.AsixData.AsixRyorRz = z;
	data.AsixData.Wheel = whell;
	data.AsixData.const1 = whell>>16;
	data.AsixData.button = button;
	data.AsixData.reprotid = reprot;
    bool suer = 0;
    DWORD OperBytes = 0;
	switch (reprot) {
		case 1:
			suer = WriteFile(Device, &data, 18, &OperBytes, NULL);
			if (!suer) {
				std::cout << "发送失败 Device:" << Device;
			}
			break;
		case 2:
			data.AsixData.button = 0;
			data.AsixData.const1 = button;
			suer = WriteFile(Device, &data, 4, &OperBytes, NULL);
			if (!suer) {
				std::cout << "发送失败 Device:" << Device;
			}
			break;

	}
    return suer;
}

DLLEXPORT void GetReprot() {
	byte buffer[64];
	DWORD Oper = 0;
	bool b = ReadFile(Device, &buffer,64,&Oper,NULL);
	for (int i = 0; i < sizeof(buffer); i++) {
		printf("%x", buffer[i]);
	}
	
}

DLLEXPORT BOOL FindHidDevice(int vid) {
	if (Device != NULL) {
		printf("设备对象已打开，请关闭后在试");
		return false;
	}
	GUID HidGuid;
	HDEVINFO hDEVInfoSet;
	SP_DEVICE_INTERFACE_DATA DevInterfaceData;
	PSP_DEVICE_INTERFACE_DETAIL_DATA pDevDetailData;
	HIDD_ATTRIBUTES DevAttributes;
	DWORD RequiredSize;
	BOOL Result;
	DWORD MemberIndex = 0;
	DWORD FoundDevice_Num = 0;
	DevInterfaceData.cbSize = sizeof(DevInterfaceData);
	DevAttributes.Size = sizeof(DevAttributes);
	HidD_GetHidGuid(&HidGuid);
	hDEVInfoSet = SetupDiGetClassDevs(&HidGuid, NULL, NULL, DIGCF_DEVICEINTERFACE | DIGCF_PRESENT | DIGCF_INTERFACEDEVICE);
	while (TRUE) {
		Result = SetupDiEnumDeviceInterfaces(hDEVInfoSet, NULL, &HidGuid, MemberIndex, &DevInterfaceData);
		if (Result == FALSE)
			break;
		MemberIndex++;
		Result = SetupDiGetDeviceInterfaceDetail(hDEVInfoSet, &DevInterfaceData, NULL, NULL, &RequiredSize, NULL);
		pDevDetailData = (PSP_DEVICE_INTERFACE_DETAIL_DATA)malloc(RequiredSize);
		if (pDevDetailData == NULL) {
			SetupDiDestroyDeviceInfoList(hDEVInfoSet);
			return FALSE;
		}
		pDevDetailData->cbSize = sizeof(SP_DEVICE_INTERFACE_DETAIL_DATA);
		Result = SetupDiGetDeviceInterfaceDetail(hDEVInfoSet, &DevInterfaceData, pDevDetailData, RequiredSize, NULL, NULL);

		if (Result == FALSE)
			continue;
		Device = CreateFile(pDevDetailData->DevicePath, NULL, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
		free(pDevDetailData);
		if (Device != INVALID_HANDLE_VALUE) {
			Result = HidD_GetAttributes(Device, &DevAttributes);
			if (Result == FALSE)
				continue;
			if (DevAttributes.VendorID == vid) {
				return Result;
				//DeviceIoControl(Device, IOCTL_HID_SET_FEATURE, &buffer, 50, &outbuffer, 50, NULL, NULL);
				//DeviceIoControl(Device, IOCTL_HID_GET_FEATURE, &buffer, 50, &outbuffer, 50, NULL, NULL);
			}
		}
	}

	return Result;
}

DLLEXPORT void CreatVhf(PUCHAR Reprot,int Len){
	HANDLE vDevice = CreateFile(L"\\\\.\\.GameControl", GENERIC_ALL, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, NULL);
	if (vDevice == NULL || vDevice == INVALID_HANDLE_VALUE)
	{
		printf("设备对象打开失败，错误原因(%08X)\n", GetLastError());
		system("pause");
		return;
	}
	DeviceIoControl(vDevice, IOCTL_VHFCREAT, Reprot, Len, NULL, NULL, NULL, NULL);
	if (GetLastError() == 0xC1) {
		printf("设备对象打开失败，已存在VHF实列\n");
	}
	CloseHandle(vDevice);
}

DLLEXPORT void DeleteVhf() {
	HANDLE vDevice = CreateFile(L"\\\\.\\.GameControl", GENERIC_ALL, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, NULL);
	if (vDevice == NULL || vDevice == INVALID_HANDLE_VALUE)
	{
		printf("设备对象打开失败，错误原因(%08X)\n", GetLastError());
		system("pause");
		return;
	}
	DeviceIoControl(vDevice, IOCTL_VHFDEL, NULL, NULL, NULL, NULL, NULL, NULL);
	CloseHandle(vDevice);
}

DLLEXPORT void CloseDevice() {
	if (Device != NULL) {
		CloseHandle(Device);
	}
}