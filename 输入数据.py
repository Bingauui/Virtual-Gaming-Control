data = bytes([0x01,data[13],data[12],0,0,0,data[3],data[2],data[1],data[0],data[5],data[4],data[7],data[6],data[11],data[10],data[9],data[8]])
#第一位 报表ID  2-18位 定义的按钮和轴数据  

reprot = c_char_p(data)
bWriteFile(reprot,len(data))
#定义了多少byte的数据就发多长的byte数组  byte的整数倍
# UCHAR fbbReport[] = {  
#             
#             #pragma region 输入入报表
#          0x05,0x01, // Usage Page Generic Desktop
#          0x09,0x04, // Usage Joystick
#          0xA1,0x01, // Collection Application
#             0x85,0x01, // Report ID 1
#         0x05,0x09, // [0x03]USAGE PAGE (BUTTON)
#         0x19,0x01, // [0x04]USAGE_MINIMUM(BUTTON 1)
#         0x29,0x08, // [0x05]USAGE_MAXIMUM(BUTTON 8)
#         0x15,0x00, // [0x06]LOGICAL_MINIMUM
#         0x25,0x01, // [0x07]LOGICAL_MAXIMUM
#         0x75,0x01, // [0x0A]REPORT_SIZE
#         0x95,0x08, // [0x0B]REPORT_COUNT
#         0x81,0x02, // [0x0C]INPUT
#         0x75,0x10,
#         0x95,0x01,
#         0x81,0x01,
#         0x05,0x01, // [0x0D]USAGE PAGE (GENERIC DESKTOP CONTROLS)
#         0x09,0x30, // [0x1A]USAGE(X)
#         0x09,0x31, // [0x1B]USAGE(Y)
#         0x09,0x32, // [0x1C]USAGE(Z)
#         0x09,0x33, // [0x1D]USAGE(Rx)
#         0x16,0x00,0x00, // [0x1E]LOGICAL_MINIMUM
#         0x27,0xff,0xff,0x00,0x00, // [0x1F]LOGICAL_MAXIMUM
#         0x35,0x00, // Physical Minimum 0
#         0x47,0xff,0xff,0x00,0x00, // Physical Maximum 1
#         0x75,0x10, // [0x22]REPORT_SIZE
#         0x95,0x04, // [0x23]REPORT_COUNT
#         0x81,0x02, // [0x24]INPUT
# }
