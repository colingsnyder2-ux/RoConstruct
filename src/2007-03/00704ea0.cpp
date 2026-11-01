// from server: 100% by auto
// roc 2007-03 00704ea0  unit: seg_00700000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00704ea0
//
// 00704ea0  56                   push esi
// 00704ea1  8bf1                 mov esi, ecx
// 00704ea3  e8c8cd0100           call 0x721c70
// 00704ea8  c706e4d77d00         mov dword ptr [esi], 0x7dd7e4
// 00704eae  c7461800000000       mov dword ptr [esi + 0x18], 0
// 00704eb5  8bc6                 mov eax, esi
// 00704eb7  5e                   pop esi
// 00704eb8  c3                   ret 
// library xtp-15.2.1/Source\Chart\Drawing\XTPChartTransformationDeviceCommand.cpp (function ??0CXTPChartSaveStateDeviceCommand@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Chart/Drawing/XTPChartTransformationDeviceCommand.cpp
