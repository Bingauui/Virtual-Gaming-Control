#include "Froce.h"

VOID WriterReport(
	_In_
	PVOID VhfClientContext,
	_In_
	VHFOPERATIONHANDLE VhfOperationHandle,
	_In_opt_
	PVOID VhfOperationContext,
	_In_
	PHID_XFER_PACKET HidTransferPacket) {
	PWRITEREPORTBUFFER Temp = VhfClientContext;
	if (HidTransferPacket->reportBufferLen <= 60) {
		Temp->buffer[HidTransferPacket->reportId].length = HidTransferPacket->reportBufferLen;
		memcpy(Temp->buffer[HidTransferPacket->reportId].buffer, HidTransferPacket->reportBuffer, HidTransferPacket->reportBufferLen);
	}
	VhfAsyncOperationComplete(VhfOperationHandle, STATUS_SUCCESS);
}

VOID SetFeature(
	_In_
	PVOID VhfClientContext,
	_In_
	VHFOPERATIONHANDLE VhfOperationHandle,
	_In_opt_
	PVOID VhfOperationContext,
	_In_
	PHID_XFER_PACKET HidTransferPacket) {
	//KdBreakPoint();
	SetEffect(VhfClientContext, HidTransferPacket->reportBuffer);
	//KdPrint(("Set effet Feature Sureess"));
	VhfAsyncOperationComplete(VhfOperationHandle, STATUS_SUCCESS);
}
UCHAR buffer1[5] = { 0 };
VOID GetFeature(
	_In_
	PVOID VhfClientContext,
	_In_
	VHFOPERATIONHANDLE VhfOperationHandle,
	_In_opt_
	PVOID VhfOperationContext,
	_In_
	PHID_XFER_PACKET HidTransferPacket) {
	if (HidTransferPacket->reportId == 2)
	{
		buffer1[0] = HidTransferPacket->reportId;
		buffer1[1] = ((PID_BLOCK_LOAD_REPORT*)VhfClientContext)->effect_block_index;
		buffer1[2] = ((PID_BLOCK_LOAD_REPORT*)VhfClientContext)->block_load_status;
		buffer1[3] = ((PID_BLOCK_LOAD_REPORT*)VhfClientContext)->ram_pool_available >> 8;
		buffer1[4] = (CHAR)((PID_BLOCK_LOAD_REPORT*)VhfClientContext)->ram_pool_available;
		memcpy(HidTransferPacket->reportBuffer, buffer1, sizeof(buffer1));

	}
	VhfAsyncOperationComplete(VhfOperationHandle, STATUS_SUCCESS);
}