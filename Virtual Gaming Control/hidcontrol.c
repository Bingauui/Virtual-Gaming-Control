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
	memcpy(VhfClientContext, &HidTransferPacket->reportBufferLen, sizeof(ULONG));
	memcpy(((char*)VhfClientContext) + sizeof(ULONG), HidTransferPacket->reportBuffer, HidTransferPacket->reportBufferLen);
	//KdPrint(("Reprot ID: %d ; Data: %d %d %d %d %d %d",HidTransferPacket->reportId, HidTransferPacket->reportBuffer[1], HidTransferPacket->reportBuffer[2],
	//HidTransferPacket->reportBuffer[3], HidTransferPacket->reportBuffer[4], HidTransferPacket->reportBuffer[5], HidTransferPacket->reportBuffer[6]));
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