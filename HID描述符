        UCHAR fbbReport[] = {
            //输入报表1 128位 ： 0-7 报表ID  8-15  8个按钮 15-31   31-128 四个轴 FFFF
            //输入报表2 8位   0：设备暂停 1执行器启用 2安全开关 3执行器超越开关 4执行器功率  高3位固定0
            //8位   0：力反馈开启 1-7： 力反馈效果块（1-40）
            #pragma region 输入入报表
         0x05,0x01, // Usage Page Generic Desktop
         0x09,0x04, // Usage Joystick
         0xA1,0x01, // Collection Application
            0x85,0x01, // Report ID 1
        0x05,0x09, // [0x03]USAGE PAGE (BUTTON)
        0x19,0x01, // [0x04]USAGE_MINIMUM(BUTTON 1)
        0x29,0x08, // [0x05]USAGE_MAXIMUM(BUTTON 8)
        0x15,0x00, // [0x06]LOGICAL_MINIMUM
        0x25,0x01, // [0x07]LOGICAL_MAXIMUM
        0x75,0x01, // [0x0A]REPORT_SIZE
        0x95,0x08, // [0x0B]REPORT_COUNT
        0x81,0x02, // [0x0C]INPUT
        0x75,0x10,
        0x95,0x01,
        0x81,0x01,
        0x05,0x01, // [0x0D]USAGE PAGE (GENERIC DESKTOP CONTROLS)
        0x09,0x30, // [0x1A]USAGE(X)
        0x09,0x31, // [0x1B]USAGE(Y)
        0x09,0x32, // [0x1C]USAGE(Z)
        0x09,0x33, // [0x1D]USAGE(Rx)
        0x16,0x00,0x00, // [0x1E]LOGICAL_MINIMUM
        0x27,0xff,0xff,0x00,0x00, // [0x1F]LOGICAL_MAXIMUM
        0x35,0x00, // Physical Minimum 0
        0x47,0xff,0xff,0x00,0x00, // Physical Maximum 1
        0x75,0x10, // [0x22]REPORT_SIZE
        0x95,0x04, // [0x23]REPORT_COUNT
        0x81,0x02, // [0x24]INPUT



         /*
          Input
          Collection Datalink (sub-collection)
          Physical Interface (Usage: PID State report)
          ID: 2
          state report: 5X1bit
          Padding: 3bit
          PID Device Control: 1bit
          Effect Block Index: 7bit
         */



            0x05,0x0F, // Usage Page Physical Interface
            0x09,0x92, // Usage PID State report 
            0xA1,0x02, // Collection Datalink (logical)

               0x85,0x02, // Report ID 2
               0x09,0x9F, // Usage Device is Pause 
               0x09,0xA0, // Usage Actuators Enabled
               0x09,0xA4, // Usage Safety Switch
               0x09,0xA5, // Usage Actuator Override Switch
               0x09,0xA6, // Usage Actuator Power
               0x15,0x00, // Logical Minimum 0
               0x25,0x01, // Logical Maximum 1
               0x35,0x00, // Physical Minimum 0
               0x45,0x01, // Physical Maximum 1
               0x75,0x01, // Report Size 1
               0x95,0x05, // Report Count 5
               0x81,0x02, // Input (Variable)
               0x95,0x03, // Report Count 3
               0x81,0x03, // Input (Constant, Variable)


               0x09,0x94, // Usage Effect Playing
               0x15,0x00, // Logical Minimum 0
               0x25,0x01, // Logical Maximum 1
               0x35,0x00, // Physical Minimum 0
               0x45,0x01, // Physical Maximum 1
               0x75,0x01, // Report Size 1
               0x95,0x01, // Report Count 1
               0x81,0x02, // Input (Variable)
               0x09,0x22, // Usage Effect Block Index
               0x15,0x01, // Logical Minimum 1
               0x25,0x28, // Logical Maximum 28h (40d)
               0x35,0x01, // Physical Minimum 1
               0x45,0x28, // Physical Maximum 28h (40d)
               0x75,0x07, // Report Size 7
               0x95,0x01, // Report Count 1
               0x81,0x02, // Input (Variable)
            0xC0 , // End Collection
        #pragma endregion
             //   初始化效果报告  ID:1效果块索引号 ：8位 （1-40）
             // 力反馈效果12种：8位 （1-12）96位
            #pragma region output Report ID 1
            0x09,0x21, // Usage Set Effect Report
            0xA1,0x02, // Collection Datalink (Logical)
               0x85,0x01, // Report ID 1
               0x09,0x22, // Usage Effect Block Index
               0x15,0x01, // Logical Minimum 1
               0x25,0x28, // Logical Maximum 28h (40d)
               0x35,0x01, // Physical Minimum 1
               0x45,0x28, // Physical Maximum 28h (40d)
               0x75,0x08, // Report Size 8
               0x95,0x01, // Report Count 1
               0x91,0x02, // Output (Variable)

               0x09,0x25, // Usage Effect Type
               0xA1,0x02, // Collection Datalink
                  0x09,0x26, // Usage ET Constant Force
                  0x09,0x27, // Usage ET Ramp
                  0x09,0x30, // Usage ET Square
                  0x09,0x31, // Usage ET Sine
                  0x09,0x32, // Usage ET Triangle
                  0x09,0x33, // Usage ET Sawtooth Up
                  0x09,0x34, // Usage ET Sawtooth Down
                  0x09,0x40, // Usage ET Spring
                  0x09,0x41, // Usage ET Damper
                  0x09,0x42, // Usage ET Inertia
                  0x09,0x43, // Usage ET Friction
                  0x09,0x28, // Usage ET Custom Force Data
                  0x25,0x0C, // Logical Maximum Ch (12d)
                  0x15,0x01, // Logical Minimum 1
                  0x35,0x01, // Physical Minimum 1
                  0x45,0x0C, // Physical Maximum Ch (12d)
                  0x75,0x08, // Report Size 8
                  0x95,0x01, // Report Count 1
                  0x91,0x00, // Output

               0xC0 , // End Collection

               0x09,0x50, // Usage Duration
               0x09,0x54, // Usage Trigger Repeat Interval
               0x09,0x51, // Usage Sample Period
               0x15,0x00, // Logical Minimum 0
               0x26,0xFF,0x7F, // Logical Maximum 7FFFh (32767d)
               0x35,0x00, // Physical Minimum 0
               0x46,0xFF,0x7F, // Physical Maximum 7FFFh (32767d)
               0x66,0x03,0x10, // Unit 1003h (4099d)
               0x55,0xFD, // Unit Exponent FDh (253d)
               0x75,0x10, // Report Size 10h (16d)
               0x95,0x03, // Report Count 3
               0x91,0x02, // Output (Variable)

               0x55,0x00, // Unit Exponent 0
               0x66,0x00,0x00, // Unit 0
               0x09,0x52, // Usage Gain
               0x15,0x00, // Logical Minimum 0
               0x26,0xFF,0x00, // Logical Maximum FFh (255d)
               0x35,0x00, // Physical Minimum 0
               0x46,0x10,0x27, // Physical Maximum 2710h (10000d)
               0x75,0x08, // Report Size 8
               0x95,0x01, // Report Count 1
               0x91,0x02, // Output (Variable)

               0x09,0x53, // Usage Trigger Button
               0x15,0x01, // Logical Minimum 1
               0x25,0x08, // Logical Maximum 8
               0x35,0x01, // Physical Minimum 1
               0x45,0x08, // Physical Maximum 8
               0x75,0x08, // Report Size 8
               0x95,0x01, // Report Count 1
               0x91,0x02, // Output (Variable)

               0x09,0x55, // Usage Axes Enable
               0xA1,0x02, // Collection Datalink
                  0x05,0x01, // Usage Page Generic Desktop
                  0x09,0x30, // Usage X
                  0x09,0x31, // Usage Y
                  0x15,0x00, // Logical Minimum 0
                  0x25,0x01, // Logical Maximum 1
                  0x75,0x01, // Report Size 1
                  0x95,0x02, // Report Count 2
                  0x91,0x02, // Output (Variable)

               0xC0 , // End Collection

               0x05,0x0F, // Usage Page Physical Interface
               0x09,0x56, // Usage Direction Enable
               0x95,0x01, // Report Count 1
               0x91,0x02, // Output (Variable)

               0x95,0x05, // Report Count 5
               0x91,0x03, // Output (Constant, Variable)

               0x09,0x57, // Usage Direction
               0xA1,0x02, // Collection Datalink
                  0x0B,0x01,0x00,0x0A,0x00, // Usage Ordinals: Instance 1
                  0x0B,0x02,0x00,0x0A,0x00, // Usage Ordinals: Instance 2
                  0x66,0x14,0x00, // Unit 14h (20d)
                  0x55,0xFE, // Unit Exponent FEh (254d)
                  0x15,0x00, // Logical Minimum 0
                  0x26,0xFF,0x00, // Logical Maximum FFh (255d)
                  0x35,0x00, // Physical Minimum 0
                  0x47,0xA0,0x8C,0x00,0x00, // Physical Maximum 8CA0h (36000d)
                  0x66,0x00,0x00, // Unit 0
                  0x75,0x08, // Report Size 8
                  0x95,0x02, // Report Count 2
                  0x91,0x02, // Output (Variable)
                  0x55,0x00, // Unit Exponent 0
                  0x66,0x00,0x00, // Unit 0
               0xC0 , // End Collection

               0x05,0x0F, // Usage Page Physical Interface
               0x09,0xA7, // Usage Undefined
               0x66,0x03,0x10, // Unit 1003h (4099d)
               0x55,0xFD, // Unit Exponent FDh (253d)
               0x15,0x00, // Logical Minimum 0
               0x26,0xFF,0x7F, // Logical Maximum 7FFFh (32767d)
               0x35,0x00, // Physical Minimum 0
               0x46,0xFF,0x7F, // Physical Maximum 7FFFh (32767d)
               0x75,0x10, // Report Size 10h (16d)
               0x95,0x01, // Report Count 1
               0x91,0x02, // Output (Variable)
               0x66,0x00,0x00, // Unit 0
               0x55,0x00, // Unit Exponent 0
            0xC0 , // End Collection
        #pragma endregion

            #pragma region Set Envelope Report ID 2
            0x05,0x0F, // Usage Page Physical Interface
            0x09,0x5A, // Usage Set Envelope Report
            0xA1,0x02, // Collection Datalink
               0x85,0x02, // Report ID 2
               0x09,0x22, // Usage Effect Block Index
               0x15,0x01, // Logical Minimum 1
               0x25,0x28, // Logical Maximum 28h (40d)
               0x35,0x01, // Physical Minimum 1
               0x45,0x28, // Physical Maximum 28h (40d)
               0x75,0x08, // Report Size 8
               0x95,0x01, // Report Count 1
               0x91,0x02, // Output (Variable)
               0x09,0x5B, // Usage Attack Level
               0x09,0x5D, // Usage Fade Level
               0x15,0x00, // Logical Minimum 0
               0x26,0xFF,0x00, // Logical Maximum FFh (255d)
               0x35,0x00, // Physical Minimum 0
               0x46,0x10,0x27, // Physical Maximum 2710h (10000d)
               0x95,0x02, // Report Count 2
               0x91,0x02, // Output (Variable)
               0x09,0x5C, // Usage Attack Time
               0x09,0x5E, // Usage Fade Time
               0x66,0x03,0x10, // Unit 1003h (4099d)
               0x55,0xFD, // Unit Exponent FDh (253d)
               0x26,0xFF,0x7F, // Logical Maximum 7FFFh (32767d)
               0x46,0xFF,0x7F, // Physical Maximum 7FFFh (32767d)
               0x75,0x10, // Report Size 10h (16d)
               0x91,0x02, // Output (Variable)
               0x45,0x00, // Physical Maximum 0
               0x66,0x00,0x00, // Unit 0
               0x55,0x00, // Unit Exponent 0
            0xC0 , // End Collection
        #pragma endregion

            #pragma region Set Condition Report ID 3
            0x09,0x5F, // Usage Set Condition Report
            0xA1,0x02, // Collection Datalink
               0x85,0x03, // Report ID 3
               0x09,0x22, // Usage Effect Block Index
               0x15,0x01, // Logical Minimum 1
               0x25,0x28, // Logical Maximum 28h (40d)
               0x35,0x01, // Physical Minimum 1
               0x45,0x28, // Physical Maximum 28h (40d)
               0x75,0x08, // Report Size 8
               0x95,0x01, // Report Count 1
               0x91,0x02, // Output (Variable)
               0x09,0x23, // Usage Parameter Block Offset
               0x15,0x00, // Logical Minimum 0
               0x25,0x01, // Logical Maximum 1
               0x35,0x00, // Physical Minimum 0
               0x45,0x01, // Physical Maximum 1
               0x75,0x04, // Report Size 4
               0x95,0x01, // Report Count 1
               0x91,0x02, // Output (Variable)
               0x09,0x58, // Usage Type Specific Block Off...
               0xA1,0x02, // Collection Datalink

                  0x0B,0x01,0x00,0x0A,0x00, // Usage Ordinals: Instance 1
                  0x0B,0x02,0x00,0x0A,0x00, // Usage Ordinals: Instance 2
                  0x75,0x02, // Report Size 2
                  0x95,0x02, // Report Count 2
                  0x91,0x02, // Output (Variable)
               0xC0 , // End Collection

               0x15,0x80, // Logical Minimum 80h (-128d)
               0x25,0x7F, // Logical Maximum 7Fh (127d)
               0x36,0xF0,0xD8, // Physical Minimum D8F0h (-10000d)
               0x46,0x10,0x27, // Physical Maximum 2710h (10000d)
               0x09,0x60, // Usage CP Offset
               0x75,0x08, // Report Size 8
               0x95,0x01, // Report Count 1
               0x91,0x02, // Output (Variable)
               0x36,0xF0,0xD8, // Physical Minimum D8F0h (-10000d)
               0x46,0x10,0x27, // Physical Maximum 2710h (10000d)
               0x09,0x61, // Usage Positive Coefficient
               0x09,0x62, // Usage Negative Coefficient
               0x95,0x02, // Report Count 2
               0x91,0x02, // Output (Variable)
               0x15,0x00, // Logical Minimum 0
               0x26,0xFF,0x00, // Logical Maximum FFh (255d)
               0x35,0x00, // Physical Minimum 0
               0x46,0x10,0x27, // Physical Maximum 2710h (10000d)
               0x09,0x63, // Usage Positive Saturation
               0x09,0x64, // Usage Negative Saturation
               0x75,0x08, // Report Size 8
               0x95,0x02, // Report Count 2
               0x91,0x02, // Output (Variable)
               0x09,0x65, // Usage Dead Band
               0x46,0x10,0x27, // Physical Maximum 2710h (10000d)
               0x95,0x01, // Report Count 1
               0x91,0x02, // Output (Variable)
            0xC0 , // End Collection
        #pragma endregion

            #pragma region Set Periodic Report ID 4
            0x09,0x6E, // Usage 
            0xA1,0x02, // Collection Datalink
               0x85,0x04, // Report ID 4
               0x09,0x22, // Usage Effect Block Index
               0x15,0x01, // Logical Minimum 1
               0x25,0x28, // Logical Maximum 28h (40d)
               0x35,0x01, // Physical Minimum 1
               0x45,0x28, // Physical Maximum 28h (40d)
               0x75,0x08, // Report Size 8
               0x95,0x01, // Report Count 1
               0x91,0x02, // Output (Variable)
               0x09,0x70, // Usage Magnitude
               0x15,0x00, // Logical Minimum 0
               0x26,0xFF,0x00, // Logical Maximum FFh (255d)
               0x35,0x00, // Physical Minimum 0
               0x46,0x10,0x27, // Physical Maximum 2710h (10000d)
               0x75,0x08, // Report Size 8
               0x95,0x01, // Report Count 1
               0x91,0x02, // Output (Variable)
               0x09,0x6F, // Usage Offset
               0x15,0x80, // Logical Minimum 80h (-128d)
               0x25,0x7F, // Logical Maximum 7Fh (127d)
               0x36,0xF0,0xD8, // Physical Minimum D8F0h (-10000d)
               0x46,0x10,0x27, // Physical Maximum 2710h (10000d)
               0x95,0x01, // Report Count 1
               0x91,0x02, // Output (Variable)
               0x09,0x71, // Usage Phase
               0x66,0x14,0x00, // Unit 14h (20d)
               0x55,0xFE, // Unit Exponent FEh (254d)
               0x15,0x00, // Logical Minimum 0
               0x26,0xFF,0x00, // Logical Maximum FFh (255d)
               0x35,0x00, // Physical Minimum 0
               0x47,0xA0,0x8C,0x00,0x00, // Physical Maximum 8CA0h (36000d)
               0x91,0x02, // Output (Variable)
               0x09,0x72, // Usage Period
               0x26,0xFF,0x7F, // Logical Maximum 7FFFh (32767d)
               0x46,0xFF,0x7F, // Physical Maximum 7FFFh (32767d)
               0x66,0x03,0x10, // Unit 1003h (4099d)
               0x55,0xFD, // Unit Exponent FDh (253d)
               0x75,0x10, // Report Size 10h (16d)
               0x95,0x01, // Report Count 1
               0x91,0x02, // Output (Variable)
               0x66,0x00,0x00, // Unit 0
               0x55,0x00, // Unit Exponent 0
            0xC0 , // End Collection
        #pragma endregion

            #pragma region Set Constant Force Rep... ID 5
            0x09,0x73, // Usage 
            0xA1,0x02, // Collection Datalink
               0x85,0x05, // Report ID 5
               0x09,0x22, // Usage Effect Block Index
               0x15,0x01, // Logical Minimum 1
               0x25,0x28, // Logical Maximum 28h (40d)
               0x35,0x01, // Physical Minimum 1
               0x45,0x28, // Physical Maximum 28h (40d)
               0x75,0x08, // Report Size 8
               0x95,0x01, // Report Count 1
               0x91,0x02, // Output (Variable)
               0x09,0x70, // Usage Magnitude
               0x16,0x00,0x80, // Logical Minimum FF01h (-32767d)
               0x26,0xFF,0x7F, // Logical Maximum FFh (232767d)
        //       0x36,0xF0,0xD8, // Physical Minimum D8F0h (-10000d)
        //       0x46,0x10,0x27, // Physical Maximum 2710h (10000d)
               0x75,0x10, // Report Size 10h (16d)
               0x95,0x01, // Report Count 1
               0x91,0x02, // Output (Variable)
            0xC0 , // End Collection
        #pragma endregion

            #pragma region Set Ramp Force Report ID 6
            0x09,0x74, // Usage 
            0xA1,0x02, // Collection Datalink
               0x85,0x06, // Report ID 6
               0x09,0x22, // Usage Effect Block Index
               0x15,0x01, // Logical Minimum 1
               0x25,0x28, // Logical Maximum 28h (40d)
               0x35,0x01, // Physical Minimum 1
               0x45,0x28, // Physical Maximum 28h (40d)
               0x75,0x08, // Report Size 8
               0x95,0x01, // Report Count 1
               0x91,0x02, // Output (Variable)
               0x09,0x75, // Usage Ramp Start
               0x09,0x76, // Usage Ramp End
               0x15,0x80, // Logical Minimum 80h (-128d)
               0x25,0x7F, // Logical Maximum 7Fh (127d)
               0x36,0xF0,0xD8, // Physical Minimum D8F0h (-10000d)
               0x46,0x10,0x27, // Physical Maximum 2710h (10000d)
               0x75,0x08, // Report Size 8
               0x95,0x02, // Report Count 2
               0x91,0x02, // Output (Variable)
            0xC0 , // End Collection
        #pragma endregion

            #pragma region Custom Force Data Rep ID 7
            0x09,0x68, // Usage ...
            0xA1,0x02, // Collection Datalink
               0x85,0x07, // Report ID 7
               0x09,0x22, // Usage Effect Block Index
               0x15,0x01, // Logical Minimum 1
               0x25,0x28, // Logical Maximum 28h (40d)
               0x35,0x01, // Physical Minimum 1
               0x45,0x28, // Physical Maximum 28h (40d)
               0x75,0x08, // Report Size 8
               0x95,0x01, // Report Count 1
               0x91,0x02, // Output (Variable)
               0x09,0x6C, // Usage Custom Force Data Offset
               0x15,0x00, // Logical Minimum 0
               0x26,0x10,0x27, // Logical Maximum 2710h (10000d)
               0x35,0x00, // Physical Minimum 0
               0x46,0x10,0x27, // Physical Maximum 2710h (10000d)
               0x75,0x10, // Report Size 10h (16d)
               0x95,0x01, // Report Count 1
               0x91,0x02, // Output (Variable)
               0x09,0x69, // Usage Custom Force Data
               0x15,0x81, // Logical Minimum 81h (-127d)
               0x25,0x7F, // Logical Maximum 7Fh (127d)
               0x35,0x00, // Physical Minimum 0
               0x46,0xFF,0x00, // Physical Maximum FFh (255d)
               0x75,0x08, // Report Size 8
               0x95,0x0C, // Report Count Ch (12d)
               0x92,0x02,0x01, // Output (Variable, Buffered)
            0xC0 , // End Collection
        #pragma endregion

            #pragma region Download Force Sample ID 8 - 14
            0x09,0x66, // Usage 
            0xA1,0x02, // Collection Datalink
               0x85,0x08, // Report ID 8
               0x05,0x01, // Usage Page Generic Desktop
               0x09,0x30, // Usage X
               0x09,0x31, // Usage Y
               0x16,0x00, 0x80, // Logical Minimum 81h (-32768d)
               0x26,0xFF, 0x7F, // Logical Maximum 7Fh (32767d)
        //       0x35,0x00, // Physical Minimum 0
        //       0x46,0xFF,0x00, // Physical Maximum FFh (255d)
               0x75,0x10, // Report Size 16
               0x95,0x02, // Report Count 2
               0x91,0x02, // Output (Variable)
            0xC0 , // End Collection
            0x05,0x0F, // Usage Page Physical Interface

            0x09,0x6B, //Usage set custom force report
            0xA1,0x02, //Collection 
               0x85,0x09, // Report ID 9h (9d)
               0x09,0x22, // Usage Effect Block Index
               0x15, 0x01, // Logical Minimum 1
               0x25, 0x28, // Logical Maximum 28h (40d)
               0x35, 0x01, // Physical Minimum 1
               0x45, 0x28, // Physical Maximum 28h (40d)
               0x75, 0x08, // Report Size 8
               0x95, 0x01, // Report Count 1
               0x91, 0x02, // Output (Variable)
               0x09, 0x6C, // Custom Force Data Offset
               0x09, 0x6D, // Sample Cunt
               0x16, 0x00, 0x80, // Logical Minimum 81h (-32768d)
               0x26, 0xFF, 0x7F, // Logical Maximum 7Fh (32767d)
               0x75, 0x10, //Report Size 16
               0x95, 0x02, // Report Count 2
            0xC0, //end collection
            0x09,0x77, // Usage Effect Operation Report
            0xA1,0x02, // Collection Datalink
               0x85,0x0A, // Report ID Ah (10d)
               0x09,0x22, // Usage Effect Block Index
               0x15,0x01, // Logical Minimum 1
               0x25,0x28, // Logical Maximum 28h (40d)
               0x35,0x01, // Physical Minimum 1
               0x45,0x28, // Physical Maximum 28h (40d)
               0x75,0x08, // Report Size 8
               0x95,0x01, // Report Count 1
               0x91,0x02, // Output (Variable)
               0x09,0x78, // Usage Effect Operation
               0xA1,0x02, // Collection Datalink
                  0x09,0x79, // Usage Op Effect Start
                  0x09,0x7A, // Usage Op Effect Start Solo
                  0x09,0x7B, // Usage Op Effect Stop
                  0x15,0x01, // Logical Minimum 1
                  0x25,0x03, // Logical Maximum 3
                  0x75,0x08, // Report Size 8
                  0x95,0x01, // Report Count 1
                  0x91,0x00, // Output
               0xC0 , // End Collection
               0x09,0x7C, // Usage Loop Count
               0x15,0x00, // Logical Minimum 0
               0x26,0xFF,0x7F, // Logical Maximum FFh (32767d)
               0x35,0x00, // Physical Minimum 0
               0x46,0xFF,0x7F, // Physical Maximum FFh (32767d)
               0x75,0x10, // Report Size 16d
               0x91,0x02, // Output (Variable)
            0xC0 , // End Collection

            0x09,0x90, // Usage PID Block Free Report
            0xA1,0x02, // Collection Datalink
               0x85,0x0B, // Report ID Bh (11d)
               0x09,0x22, // Usage Effect Block Index
               0x25,0x28, // Logical Maximum 28h (40d)
               0x15,0x01, // Logical Minimum 1
               0x35,0x01, // Physical Minimum 1
               0x45,0x28, // Physical Maximum 28h (40d)
               0x75,0x08, // Report Size 8
               0x95,0x01, // Report Count 1
               0x91,0x02, // Output (Variable)
            0xC0 , // End Collection

            0x09,0x96, // Usage PID Device Control
            0xA1,0x02, // Collection Datalink
               0x85,0x0C, // Report ID Ch (12d)
               0x09,0x97, // Usage DC Enable Actuators
               0x09,0x98, // Usage DC Disable Actuators
               0x09,0x99, // Usage DC Stop All Effects
               0x09,0x9A, // Usage DC Device Reset
               0x09,0x9B, // Usage DC Device Pause
               0x09,0x9C, // Usage DC Device Continue
               0x15,0x01, // Logical Minimum 1
               0x25,0x06, // Logical Maximum 6
               0x75,0x08, // Report Size 8
               0x95,0x01, // Report Count 1
               0x91,0x00, // Output
            0xC0 , // End Collection

            0x09,0x7D, // Usage Device Gain Report
            0xA1,0x02, // Collection Datalink
               0x85,0x0D, // Report ID Dh (13d)
               0x09,0x7E, // Usage Device Gain
               0x15,0x00, // Logical Minimum 0
               0x26,0xFF,0x00, // Logical Maximum FFh (255d)
               0x35,0x00, // Physical Minimum 0
               0x46,0x10,0x27, // Physical Maximum 2710h (10000d)
               0x75,0x08, // Report Size 8
               0x95,0x01, // Report Count 1
               0x91,0x02, // Output (Variable)
            0xC0 , // End Collection

            0x09,0x6B, // Usage Set Custom Force Report
            0xA1,0x02, // Collection Datalink
               0x85,0x0E, // Report ID Eh (14d)
               0x09,0x22, // Usage Effect Block Index
               0x15,0x01, // Logical Minimum 1
               0x25,0x28, // Logical Maximum 28h (40d)
               0x35,0x01, // Physical Minimum 1
               0x45,0x28, // Physical Maximum 28h (40d)
               0x75,0x08, // Report Size 8
               0x95,0x01, // Report Count 1
               0x91,0x02, // Output (Variable)
               0x09,0x6D, // Usage Sample Count
               0x15,0x00, // Logical Minimum 0
               0x26,0xFF,0x00, // Logical Maximum FFh (255d)
               0x35,0x00, // Physical Minimum 0
               0x46,0xFF,0x00, // Physical Maximum FFh (255d)
               0x75,0x08, // Report Size 8
               0x95,0x01, // Report Count 1
               0x91,0x02, // Output (Variable)
               0x09,0x51, // Usage Sample Period
               0x66,0x03,0x10, // Unit 1003h (4099d)
               0x55,0xFD, // Unit Exponent FDh (253d)
               0x15,0x00, // Logical Minimum 0
               0x26,0xFF,0x7F, // Logical Maximum 7FFFh (32767d)
               0x35,0x00, // Physical Minimum 0
               0x46,0xFF,0x7F, // Physical Maximum 7FFFh (32767d)
               0x75,0x10, // Report Size 10h (16d)
               0x95,0x01, // Report Count 1
               0x91,0x02, // Output (Variable)
               0x55,0x00, // Unit Exponent 0
               0x66,0x00,0x00, // Unit 0
            0xC0 , // End Collection
        #pragma endregion

            #pragma region Create New Effect Featrue ID 1 - 3
            0x09,0xAB, // Usage 
            0xA1,0x02, // Collection Datalink
               0x85,0x01, // Report ID 1
               0x09,0x25, // Usage Effect Type
               0xA1,0x02, // Collection Datalink
               0x09,0x26, // Usage ET Constant Force
               0x09,0x27, // Usage ET Ramp
               0x09,0x30, // Usage ET Square
               0x09,0x31, // Usage ET Sine
               0x09,0x32, // Usage ET Triangle
               0x09,0x33, // Usage ET Sawtooth Up
               0x09,0x34, // Usage ET Sawtooth Down
               0x09,0x40, // Usage ET Spring
               0x09,0x41, // Usage ET Damper
               0x09,0x42, // Usage ET Inertia
               0x09,0x43, // Usage ET Friction
               0x09,0x28, // Usage ET Custom Force Data
               0x25,0x0C, // Logical Maximum Ch (12d)
               0x15,0x01, // Logical Minimum 1
               0x35,0x01, // Physical Minimum 1
               0x45,0x0C, // Physical Maximum Ch (12d)
               0x75,0x08, // Report Size 8
               0x95,0x01, // Report Count 1
               0xB1,0x00, // Feature
            0xC0 , // End Collection
            0x05,0x01, // Usage Page Generic Desktop
            0x09,0x3B, // Usage Reserved
            0x15,0x00, // Logical Minimum 0
            0x26,0xFF,0x01, // Logical Maximum 1FFh (511d)
            0x35,0x00, // Physical Minimum 0
            0x46,0xFF,0x01, // Physical Maximum 1FFh (511d)
            0x75,0x0A, // Report Size Ah (10d)
            0x95,0x01, // Report Count 1
            0xB1,0x02, // Feature (Variable)
            0x75,0x06, // Report Size 6
            0xB1,0x01, // Feature (Constant)
         0xC0 , // End Collection
         0x05,0x0F, // Usage Page Physical Interface
         0x09,0x89, // Usage Block Load Status
         0xA1,0x02, // Collection Datalink
            0x85,0x02, // Report ID 2
            0x09,0x22, // Usage Effect Block Index
            0x25,0x28, // Logical Maximum 28h (40d)
            0x15,0x01, // Logical Minimum 1
            0x35,0x01, // Physical Minimum 1
            0x45,0x28, // Physical Maximum 28h (40d)
            0x75,0x08, // Report Size 8
            0x95,0x01, // Report Count 1
            0xB1,0x02, // Feature (Variable)
            0x09,0x8B, // Usage Block Load Status
            0xA1,0x02, // Collection Datalink
               0x09,0x8C, // Usage Block Load Success
               0x09,0x8D, // Usage Block Load Full
               0x09,0x8E, // Usage Block Load Error
               0x25,0x03, // Logical Maximum 3
               0x15,0x01, // Logical Minimum 1
               0x35,0x01, // Physical Minimum 1
               0x45,0x03, // Physical Maximum 3
               0x75,0x08, // Report Size 8
               0x95,0x01, // Report Count 1
               0xB1,0x00, // Feature
            0xC0 , // End Collection
            0x09,0xAC, // Usage Undefined
            0x15,0x00, // Logical Minimum 0
            0x27,0xFF,0xFF,0x00,0x00, // Logical Maximum FFFFh (65535d)
            0x35,0x00, // Physical Minimum 0
            0x47,0xFF,0xFF,0x00,0x00, // Physical Maximum FFFFh (65535d)
            0x75,0x10, // Report Size 10h (16d)
            0x95,0x01, // Report Count 1
            0xB1,0x00, // Feature
         0xC0 , // End Collection
         0x09,0x7F, // Usage PID Pool Report
         0xA1,0x02, // Collection Datalink
            0x85,0x03, // Report ID 3
            0x09,0x80, // Usage RAM Pool size
            0x75,0x10, // Report Size 10h (16d)
            0x95,0x01, // Report Count 1
            0x15,0x00, // Logical Minimum 0
            0x35,0x00, // Physical Minimum 0
            0x27,0xFF,0xFF,0x00,0x00, // Logical Maximum FFFFh (65535d)
            0x47,0xFF,0xFF,0x00,0x00, // Physical Maximum FFFFh (65535d)
            0xB1,0x02, // Feature (Variable)
            0x09,0x83, // Usage Simultaneous Effects Max
            0x26,0xFF,0x00, // Logical Maximum FFh (255d)
            0x46,0xFF,0x00, // Physical Maximum FFh (255d)
            0x75,0x08, // Report Size 8
            0x95,0x01, // Report Count 1
            0xB1,0x02, // Feature (Variable)
            0x09,0xA9, // Usage Device Managed Pool
            0x09,0xAA, // Usage Shared Parameter Blocks
            0x75,0x01, // Report Size 1
            0x95,0x02, // Report Count 2
            0x15,0x00, // Logical Minimum 0
            0x25,0x01, // Logical Maximum 1
            0x35,0x00, // Physical Minimum 0
            0x45,0x01, // Physical Maximum 1
            0xB1,0x02, // Feature (Variable)
            0x75,0x06, // Report Size 6
            0x95,0x01, // Report Count 1
            0xB1,0x03, // Feature (Constant, Variable)
            0xC0, // End Collection
         0xC0 // End Collection
        #pragma endregion
        };
