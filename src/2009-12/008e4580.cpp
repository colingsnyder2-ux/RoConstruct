// from server: 100% by auto
// roc 2009-12 008e4580  unit: CXTCaptionButtonThemeFactory  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008e4580
//
// 008e4580  56                   push esi
// 008e4581  8bf1                 mov esi, ecx
// 008e4583  e808f90000           call 0x8f3e90
// 008e4588  c7064cc4a000         mov dword ptr [esi], 0xa0c44c
// 008e458e  c7461800000000       mov dword ptr [esi + 0x18], 0
// 008e4595  8bc6                 mov eax, esi
// 008e4597  5e                   pop esi
// 008e4598  c3                   ret 
// library xtp-15.2.1/Source\Chart\Drawing\XTPChartTransformationDeviceCommand.cpp (function ??0CXTPChartSaveStateDeviceCommand@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Chart/Drawing/XTPChartTransformationDeviceCommand.cpp
