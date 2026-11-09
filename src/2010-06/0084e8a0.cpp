// from server: 100% by auto
// roc 2010-06 0084e8a0  unit: CXTPReportPaintManager  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0084e8a0
//
// 0084e8a0  8b442414             mov eax, dword ptr [esp + 0x14]
// 0084e8a4  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0084e8a8  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0084e8ac  50                   push eax
// 0084e8ad  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0084e8b1  6a01                 push 1
// 0084e8b3  51                   push ecx
// 0084e8b4  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0084e8b8  52                   push edx
// 0084e8b9  50                   push eax
// 0084e8ba  e8cbe41200           call 0x97cd8a
// 0084e8bf  c21400               ret 0x14
// library xtp-13.2.1/Source\ReportControl\XTPReportPaintManager.cpp (function ?DrawHorizontalLine@CXTPReportPaintManager@@QAEXPAVCDC@@HHHK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportPaintManager.cpp
