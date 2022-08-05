// ReadFile.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <stdio.h>
#include <windows.h>
#include <iostream>
#include <conio.h>
#define CharSample_IOCTL_800 CTL_CODE(FILE_DEVICE_UNKNOWN, 0x800, METHOD_BUFFERED, FILE_ANY_ACCESS)


#define DLLEXPORT extern "C" __declspec(dllexport) 
DLLEXPORT int int123() {
    return 500;
}

int main()
{
    HANDLE Device = CreateFile(L"\\\\.\\.min", GENERIC_ALL, FILE_SHARE_READ|FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, NULL);
	if (Device == NULL || Device == INVALID_HANDLE_VALUE)
	{
		printf("设备对象打开失败，错误原因(%08X)\n", GetLastError());
		system("pause");
	}
	DWORD OperBytes = 0;
	//DeviceIoControl(Device,)
    CHAR bufInput[1]; // Input to device
    CHAR bufOutput[2]; // Output from device
    DeviceIoControl(Device,
        CharSample_IOCTL_800,
        bufInput,
        1,
        bufOutput,
        2,
        &OperBytes,
        NULL);

    CHAR str[10];
	bool n = ReadFile(Device, str, 10, &OperBytes, NULL);
    if (n) {
        std::cout << str;
        std::cout << "\n打印成功\n";
    }

    UCHAR str1[5];
    str1[3] = '\0';
    int i = 3;
    unsigned int tmp;
    while (i) {
        std::cout << "请输入数据\n";
        std::cin >>std::hex >> tmp;
        //memcpy(str1, &tmp, 4);
        str1[1] = tmp >> 24;
        str1[0] = tmp >> 16;
        str1[3] = tmp >> 8;
        str1[2] = tmp;
        str1[4] = 0;
        std::cout << str1;    
        WriteFile(Device, &str1, 5, &OperBytes, NULL);
        if (str1[0] == 0xE0) {
            break;
        }
    }
	CloseHandle(Device);
    std::cout << "完成!\n";
    system("pause");

}
