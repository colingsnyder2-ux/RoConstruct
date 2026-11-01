// from server: 100% by auto
// roc 2009-06 007bf940  unit: CXTPReportPaintManager  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007bf940
//
// 007bf940  8b442414             mov eax, dword ptr [esp + 0x14]
// 007bf944  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007bf948  8b54240c             mov edx, dword ptr [esp + 0xc]
// 007bf94c  50                   push eax
// 007bf94d  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007bf951  6a01                 push 1
// 007bf953  51                   push ecx
// 007bf954  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007bf958  52                   push edx
// 007bf959  50                   push eax
// 007bf95a  e8d1c50800           call 0x84bf30
// 007bf95f  c21400               ret 0x14
// library xtp-15.2.1/Source\ReportControl\XTPReportPaintManager.cpp (function ?DrawHorizontalLine@CXTPReportPaintManager@@QAEXPAVCDC@@HHHK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportPaintManager.cpp
