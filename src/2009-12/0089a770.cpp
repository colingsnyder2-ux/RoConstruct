// from server: 100% by auto
// roc 2009-12 0089a770  unit: CXTPReportPaintManager  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0089a770
//
// 0089a770  8b442414             mov eax, dword ptr [esp + 0x14]
// 0089a774  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0089a778  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0089a77c  50                   push eax
// 0089a77d  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0089a781  51                   push ecx
// 0089a782  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0089a786  6a01                 push 1
// 0089a788  52                   push edx
// 0089a789  50                   push eax
// 0089a78a  e807bd0800           call 0x926496
// 0089a78f  c21400               ret 0x14
// library xtp-15.2.1/Source\ReportControl\XTPReportPaintManager.cpp (function ?DrawVerticalLine@CXTPReportPaintManager@@QAEXPAVCDC@@HHHK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportPaintManager.cpp
