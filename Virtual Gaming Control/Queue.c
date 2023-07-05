#include "Queue.h"
#include "Driver.h"


WDF_DECLARE_CONTEXT_TYPE_WITH_NAME(DEVICE_CONTEXT, DeviceGetContext);

VOID WriteDispath(
	_In_
	WDFQUEUE Queue,
	_In_
	WDFREQUEST Request,
	_In_
	size_t Length)
{
	NTSTATUS  status = STATUS_SUCCESS;
	WDFDEVICE device = WdfIoQueueGetDevice(Queue);
	PDEVICE_CONTEXT deviceconext = DeviceGetContext(device);
	PVOID buffer;
	status = WdfRequestRetrieveInputBuffer(Request, Length, &buffer, NULL);
	//KdBreakPoint();
	if (!NT_SUCCESS(status))
		WdfRequestComplete(Request, status);
	deviceconext->VhfHidReport.reportBuffer = buffer;
	deviceconext->VhfHidReport.reportBufferLen = Length;
	deviceconext->VhfHidReport.reportId = ((CHAR*)buffer)[0];
	status = VhfReadReportSubmit(deviceconext->VhfHandle, &deviceconext->VhfHidReport);
	WdfRequestCompleteWithInformation(Request, status, Length);
}

VOID ReadDispath(
	_In_
	WDFQUEUE Queue,
	_In_
	WDFREQUEST Request,
	_In_
	size_t Length)
{
	NTSTATUS  status = STATUS_SUCCESS;
	PVOID buffer;
	status = WdfRequestRetrieveOutputBuffer(Request, Length, &buffer, NULL);
	if (NT_SUCCESS(status)) {
		WdfRequestCompleteWithInformation(Request, status, Length);
	}
	else {
		WdfRequestComplete(Request, status);
	}
};
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
	ULONG IoControlCode)
{
	NTSTATUS  status = STATUS_SUCCESS;
	WDFDEVICE device = WdfIoQueueGetDevice(Queue);
	PVOID buffer;
	switch (IoControlCode)
	{
	case IOCTL_VHFDEL:
		if (Queue != NULL) {
			PDEVICE_CONTEXT deviceconext = DeviceGetContext(device);
			if (deviceconext->VHFRUNING == TRUE) {
				VhfDelete(deviceconext->VhfHandle, TRUE);
				deviceconext->VHFRUNING = FALSE;
			}
		}
		break;
	case IOCTL_VHFCAR:
		PAGED_CODE();
		status = WdfRequestRetrieveInputBuffer(Request, InputBufferLength, &buffer, NULL);
		if (!NT_SUCCESS(status)) {
			goto exit;
		}
		UCHAR buffe[2048];
		memcpy(buffe, buffer, InputBufferLength);
		VHF_CONFIG vhfConfig;
		PDEVICE_CONTEXT deviceContext;

		deviceContext = DeviceGetContext(device);
		VHF_CONFIG_INIT(&vhfConfig,
			WdfDeviceWdmGetDeviceObject(device),
			InputBufferLength,
			buffe);
		vhfConfig.VendorID = 0x0498;
		vhfConfig.ProductID = 0xCF32;
		vhfConfig.VhfClientContext = &WriterReportBuffer;
		vhfConfig.OperationContextSize = 100;
		vhfConfig.EvtVhfAsyncOperationWriteReport = WriterReport;
		vhfConfig.EvtVhfAsyncOperationGetFeature = GetFeature;
		vhfConfig.EvtVhfAsyncOperationSetFeature = SetFeature;
		if (deviceContext->VHFRUNING == FALSE) {
			status = VhfCreate(&vhfConfig, &deviceContext->VhfHandle);
			//KdPrintEx((DPFLTR_IHVDRIVER_ID, DPFLTR_INFO_LEVEL, "Success\n" + status));
			if (!NT_SUCCESS(status))
				goto exit;
			status = VhfStart(deviceContext->VhfHandle);
			deviceContext->VHFRUNING = TRUE;
		}
		else {
			status = STATUS_BAD_INITIAL_PC;
		}
		break;
	case IOCTL_READREPORTID:
		PAGED_CODE();
		PVOID inBuffer, outBuffer;
		status = WdfRequestRetrieveInputBuffer(Request, InputBufferLength, &inBuffer, NULL);
		int id = ((unsigned char*)inBuffer)[0];
		status = WdfRequestRetrieveOutputBuffer(Request, OutputBufferLength, &outBuffer, NULL);
		memcpy(outBuffer, WriterReportBuffer.buffer[id].buffer, WriterReportBuffer.buffer[id].length);
		if (!NT_SUCCESS(status)) {
			goto exit;
		}
		WdfRequestCompleteWithInformation(Request, status, WriterReportBuffer.buffer[id].length);
		return;
	}
exit:
	WdfRequestComplete(Request, status);
}