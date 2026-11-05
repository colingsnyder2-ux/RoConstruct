// from server: 100% by auto
// roc 2010-06 0084e8d0  unit: CXTPReportPaintManager  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0084e8d0
//
// 0084e8d0  8b442414             mov eax, dword ptr [esp + 0x14]
// 0084e8d4  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0084e8d8  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0084e8dc  50                   push eax
// 0084e8dd  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0084e8e1  51                   push ecx
// 0084e8e2  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0084e8e6  6a01                 push 1
// 0084e8e8  52                   push edx
// 0084e8e9  50                   push eax
// 0084e8ea  e89be41200           call 0x97cd8a
// 0084e8ef  c21400               ret 0x14
// library xtp-13.2.1/Source\ReportControl\XTPReportPaintManager.cpp (function ?DrawVerticalLine@CXTPReportPaintManager@@QAEXPAVCDC@@HHHK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportPaintManager.cpp
