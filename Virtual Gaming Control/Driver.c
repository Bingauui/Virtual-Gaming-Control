#include "Driver.h"

WDF_DECLARE_CONTEXT_TYPE_WITH_NAME(DEVICE_CONTEXT, DeviceGetContext);
EVT_WDF_DRIVER_DEVICE_ADD EvtDeviceAdd;
EVT_WDF_DRIVER_UNLOAD EvtDriverUnload;
SET_GET_EFFECT_STRUCTURE set_get_effct = { 0 };
NTSTATUS DriverEntry(_In_ PDRIVER_OBJECT  DriverObject, _In_     PUNICODE_STRING RegistryPath)
{
    NTSTATUS Status;
    WDF_DRIVER_CONFIG config;

    WDF_DRIVER_CONFIG_INIT(&config, EvtDeviceAdd);
    config.EvtDriverUnload = EvtDriverUnload;
    Status = WdfDriverCreate(DriverObject, RegistryPath, WDF_NO_OBJECT_ATTRIBUTES, &config, WDF_NO_HANDLE);
    if (!NT_SUCCESS(Status))
        goto exit;

exit:
    return Status;
}

NTSTATUS EvtDeviceAdd(_In_ WDFDRIVER Driver, _Inout_ PWDFDEVICE_INIT DeviceInit)
{
    PAGED_CODE();
    NTSTATUS Status;
    WDFDEVICE device = NULL;
    WDF_OBJECT_ATTRIBUTES   deviceAttributes;
    UNICODE_STRING DeviceName = { 0 };
    RtlInitUnicodeString(&DeviceName, L"\\Device\\.GameControl");
    Status = WdfDeviceInitAssignName(DeviceInit, &DeviceName);
    UNICODE_STRING SymLinkName = { 0 };
    RtlInitUnicodeString(&SymLinkName, L"\\??\\.GameControl");
    if (!NT_SUCCESS(Status))
        goto exit;
    WDF_OBJECT_ATTRIBUTES_INIT_CONTEXT_TYPE(&deviceAttributes, DEVICE_CONTEXT);

    WDF_IO_QUEUE_CONFIG ioQueueConfig;
    WDF_IO_QUEUE_CONFIG_INIT_DEFAULT_QUEUE(&ioQueueConfig, WdfIoQueueDispatchSequential);
    ioQueueConfig.EvtIoWrite = WriteDispath;
    ioQueueConfig.EvtIoRead = ReadDispath;
    ioQueueConfig.EvtIoDeviceControl = IoControl;
   // ioQueueConfig.EvtIoStop = CloseDispath;

    Status = WdfDeviceCreate(&DeviceInit, &deviceAttributes, &device);
    if (!NT_SUCCESS(Status))
        goto exit;
    Status = WdfIoQueueCreate(device, &ioQueueConfig, WDF_NO_OBJECT_ATTRIBUTES, NULL);
    if (!NT_SUCCESS(Status))
        goto exit;
    WdfDeviceCreateSymbolicLink(device, &SymLinkName);
exit:
    return Status;
}
VOID EvtDriverUnload(
    _In_
    WDFDRIVER Driver
) {

}

