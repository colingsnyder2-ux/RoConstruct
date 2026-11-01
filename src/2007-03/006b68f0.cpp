// from server: 100% by auto
// roc 2007-03 006b68f0  unit: seg_006b0000  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006b68f0
//
// 006b68f0  8b442414             mov eax, dword ptr [esp + 0x14]
// 006b68f4  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006b68f8  8b54240c             mov edx, dword ptr [esp + 0xc]
// 006b68fc  50                   push eax
// 006b68fd  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006b6901  6a01                 push 1
// 006b6903  51                   push ecx
// 006b6904  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006b6908  52                   push edx
// 006b6909  50                   push eax
// 006b690a  e8dd410800           call 0x73aaec
// 006b690f  c21400               ret 0x14
// library xtp-15.2.1/Source\ReportControl\XTPReportPaintManager.cpp (function ?DrawHorizontalLine@CXTPReportPaintManager@@QAEXPAVCDC@@HHHK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportPaintManager.cpp
