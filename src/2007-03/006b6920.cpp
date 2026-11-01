// from server: 100% by auto
// roc 2007-03 006b6920  unit: seg_006b0000  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006b6920
//
// 006b6920  8b442414             mov eax, dword ptr [esp + 0x14]
// 006b6924  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006b6928  8b54240c             mov edx, dword ptr [esp + 0xc]
// 006b692c  50                   push eax
// 006b692d  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006b6931  51                   push ecx
// 006b6932  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 006b6936  6a01                 push 1
// 006b6938  52                   push edx
// 006b6939  50                   push eax
// 006b693a  e8ad410800           call 0x73aaec
// 006b693f  c21400               ret 0x14
// library xtp-15.2.1/Source\ReportControl\XTPReportPaintManager.cpp (function ?DrawVerticalLine@CXTPReportPaintManager@@QAEXPAVCDC@@HHHK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportPaintManager.cpp
