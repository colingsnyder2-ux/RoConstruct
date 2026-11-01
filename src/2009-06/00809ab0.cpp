// from server: 100% by auto
// roc 2009-06 00809ab0  unit: CXTCaptionButtonThemeFactory  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00809ab0
//
// 00809ab0  56                   push esi
// 00809ab1  8bf1                 mov esi, ecx
// 00809ab3  e8e8f60000           call 0x8191a0
// 00809ab8  c706dcbf9000         mov dword ptr [esi], 0x90bfdc
// 00809abe  c7461800000000       mov dword ptr [esi + 0x18], 0
// 00809ac5  8bc6                 mov eax, esi
// 00809ac7  5e                   pop esi
// 00809ac8  c3                   ret 
// library xtp-15.2.1/Source\Chart\Drawing\XTPChartTransformationDeviceCommand.cpp (function ??0CXTPChartSaveStateDeviceCommand@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Chart/Drawing/XTPChartTransformationDeviceCommand.cpp
