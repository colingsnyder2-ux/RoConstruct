// from server: 100% by auto
// roc 2009-06 007bf970  unit: CXTPReportPaintManager  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007bf970
//
// 007bf970  8b442414             mov eax, dword ptr [esp + 0x14]
// 007bf974  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007bf978  8b54240c             mov edx, dword ptr [esp + 0xc]
// 007bf97c  50                   push eax
// 007bf97d  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007bf981  51                   push ecx
// 007bf982  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 007bf986  6a01                 push 1
// 007bf988  52                   push edx
// 007bf989  50                   push eax
// 007bf98a  e8a1c50800           call 0x84bf30
// 007bf98f  c21400               ret 0x14
// library xtp-15.2.1/Source\ReportControl\XTPReportPaintManager.cpp (function ?DrawVerticalLine@CXTPReportPaintManager@@QAEXPAVCDC@@HHHK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportPaintManager.cpp
