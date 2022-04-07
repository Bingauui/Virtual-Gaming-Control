from ctypes import *
class SET_REPORT_REQUEST(Structure):
    _fields_ = [
        ("report_id",c_ubyte),
        ("effect_type",c_ubyte),
        ("byte_count",c_ubyte)
    ]
class PID_BLOCK_LOAD_PEPORT(Structure):
    _fields_ = [
        ("report_id",c_ubyte),
        ("effect_block_index",c_ubyte),
        ("block_load_status",c_ubyte),
        ("ram_pool_available",c_int)
    ]
class READ_CONSTANT_FROCE_DATA(Structure):
    _fields_ = [
        ("report_id",c_ubyte),
        ("effect_block_index",c_ubyte),
        ("Magnitude",c_ubyte),
        ("Magnitude1",c_ubyte)
    ]
class SET_EFFECT_REPROT(Structure):
    _fields_ = [
        ("report_id",c_ubyte),
        ("effect_block_index",c_ubyte),
        ("EffectType",c_ubyte),
        ("Duration",c_ubyte),
        ("Duration1",c_ubyte),
        ("RepeatInterval",c_ubyte),
        ("RepeatInterval1",c_ubyte),
        ("SamplePeriod",c_ubyte),
        ("SamplePeriod1",c_ubyte),
        ("Gain",c_ubyte),
        ("Gain1",c_ubyte),
        ("TrigerButton",c_ubyte),
        ("AxesEnable",c_ubyte),
        ("XDirection",c_ubyte),
        ("YDirection",c_ubyte),
        ("Undefined",c_ubyte),
        ("Undefined1",c_ubyte)
    ]
class EFFECT_OPERATION(Structure):
    _fields_ = [
        ("report_id",c_ubyte),
        ("effect_block_index",c_ubyte),
        ("Control",c_ubyte),
        ("LoopCount",c_ubyte),
        ("LoopCount1",c_ubyte)
    ]
class DEVICE_CONTROL(Structure):
    _fields_ = [
        ("report_id",c_ubyte),
        ("Control",c_ubyte)
    ]
class GAIN_REPORT(Structure):
    _fields_ = [
        ("report_id",c_ubyte),
        ("Gain",c_ubyte),
        ("Gain1",c_ubyte)
    ]
class UNDEFINED_DATA(Structure):
    _fields_ = [
        ("report_id",c_ubyte),
        ("effect_block_index",c_ubyte),
        ("EffectType",c_ubyte),
        ("Duration",c_ubyte),
        ("Duration1",c_ubyte),
        ("RepeatInterval",c_ubyte),
        ("RepeatInterval1",c_ubyte),
        ("SamplePeriod",c_ubyte),
        ("SamplePeriod1",c_ubyte),
        ("Gain",c_ubyte),
        ("Gain1",c_ubyte),
        ("TrigerButton",c_ubyte),
        ("AxesEnable",c_ubyte),
        ("XDirection",c_ubyte),
        ("YDirection",c_ubyte),
        ("Undefined",c_ubyte),
        ("Undefined1",c_ubyte)
    ]
class GET_EFFECT_STRUCTURE(Structure):
    _fields_ = [
        ("SET_REPORT_REQUEST",SET_REPORT_REQUEST),
        ("PID_BLOCK_LOAD_PEPORT",PID_BLOCK_LOAD_PEPORT),
        ("READ_CONSTANT_FROCE_DATA",READ_CONSTANT_FROCE_DATA),
        ("SET_EFFECT_REPROT",SET_EFFECT_REPROT),
        ("EFFECT_OPERATION",EFFECT_OPERATION),
        ("DEVICE_CONTROL",DEVICE_CONTROL),
        ("GAIN_REPORT",GAIN_REPORT),
        ("UNDEFINED_DATA",UNDEFINED_DATA)
    ]


