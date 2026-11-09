// from server: 100% by auto
// roc 2007-03 006b7570  unit: seg_006b0000  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006b7570
//
// 006b7570  8b4178               mov eax, dword ptr [ecx + 0x78]
// 006b7573  83f8ff               cmp eax, -1
// 006b7576  7503                 jne 0x6b757b
// 006b7578  8b4174               mov eax, dword ptr [ecx + 0x74]
// 006b757b  8b4c2404             mov ecx, dword ptr [esp + 4]
// 006b757f  50                   push eax
// 006b7580  8d44240c             lea eax, [esp + 0xc]
// 006b7584  50                   push eax
// 006b7585  e89077f6ff           call 0x61ed1a
// 006b758a  c21400               ret 0x14
// library xtp-13.2.1/Source\ReportControl\XTPReportPaintManager.cpp (function ?FillHeaderControl@CXTPReportPaintManager@@UAEXPAVCDC@@VCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportPaintManager.cpp
