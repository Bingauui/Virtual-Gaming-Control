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
    //UCHAR buff[64] = { 0 };
    switch (HidTransferPacket->reportId)
    {
    case 1:
        memcpy(&(((PSET_GET_EFFECT_STRUCTURE)VhfClientContext)->SET_EFFECT_REPROT), HidTransferPacket->reportBuffer, HidTransferPacket->reportBufferLen);
        break;
    case 5:
        memcpy(&(((PSET_GET_EFFECT_STRUCTURE)VhfClientContext)->READ_CONSTANT_FROCE_DATA), HidTransferPacket->reportBuffer, HidTransferPacket->reportBufferLen);
        break;
    case 10:
        memcpy(&(((PSET_GET_EFFECT_STRUCTURE)VhfClientContext)->EFFECT_OPERATION), HidTransferPacket->reportBuffer, HidTransferPacket->reportBufferLen);
        break;
    case 12:
        memcpy(&(((PSET_GET_EFFECT_STRUCTURE)VhfClientContext)->DEVICE_CONTROL), HidTransferPacket->reportBuffer, HidTransferPacket->reportBufferLen);
        break;
    case 13:
        memcpy(&(((PSET_GET_EFFECT_STRUCTURE)VhfClientContext)->GAIN_REPORT), HidTransferPacket->reportBuffer, HidTransferPacket->reportBufferLen);
        break;
    default:
        memcpy(&(((PSET_GET_EFFECT_STRUCTURE)VhfClientContext)->UNDEFINED_DATA), HidTransferPacket->reportBuffer, HidTransferPacket->reportBufferLen);
        break;
    }
    //memcpy(VhfClientContext, HidTransferPacket->reportBuffer, HidTransferPacket->reportBufferLen);
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
UCHAR buffer1[5] = {0};
VOID GetFeature(
    _In_
    PVOID VhfClientContext,
    _In_
    VHFOPERATIONHANDLE VhfOperationHandle,
    _In_opt_
    PVOID VhfOperationContext,
    _In_
    PHID_XFER_PACKET HidTransferPacket) {
    //KdBreakPoint();
    if (HidTransferPacket->reportId == 2)
    {
        //KdBreakPoint();
        buffer1[0] = HidTransferPacket->reportId;
        buffer1[1] = ((PSET_GET_EFFECT_STRUCTURE)VhfClientContext)->PID_BLOCK_LOAD_REPORT.effect_block_index;
        buffer1[2] = ((PSET_GET_EFFECT_STRUCTURE)VhfClientContext)->PID_BLOCK_LOAD_REPORT.block_load_status;
        buffer1[3] = ((PSET_GET_EFFECT_STRUCTURE)VhfClientContext)->PID_BLOCK_LOAD_REPORT.ram_pool_available >> 8;
        buffer1[4] = (CHAR)((PSET_GET_EFFECT_STRUCTURE)VhfClientContext)->PID_BLOCK_LOAD_REPORT.ram_pool_available;
        //memcpy(VhfClientContext, HidTransferPacket->reportBuffer, HidTransferPacket->reportBufferLen);
        memcpy(HidTransferPacket->reportBuffer, buffer1, sizeof(buffer1));
        //KdPrint(("%d %d %d %d %d", buffer1[0], buffer1[1], buffer1[2], buffer1[3], buffer1[4]));
        //KdPrint(("GetFeature Sureess"));
    }
    VhfAsyncOperationComplete(VhfOperationHandle, STATUS_SUCCESS);
}