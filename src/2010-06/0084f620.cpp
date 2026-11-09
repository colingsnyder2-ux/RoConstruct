// from server: 100% by auto
// roc 2010-06 0084f620  unit: CXTPReportPaintManager  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0084f620
//
// 0084f620  8b4178               mov eax, dword ptr [ecx + 0x78]
// 0084f623  83f8ff               cmp eax, -1
// 0084f626  7503                 jne 0x84f62b
// 0084f628  8b4174               mov eax, dword ptr [ecx + 0x74]
// 0084f62b  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0084f62f  50                   push eax
// 0084f630  8d44240c             lea eax, [esp + 0xc]
// 0084f634  50                   push eax
// 0084f635  e80491f5ff           call 0x7a873e
// 0084f63a  c21400               ret 0x14
// library xtp-13.2.1/Source\ReportControl\XTPReportPaintManager.cpp (function ?FillHeaderControl@CXTPReportPaintManager@@UAEXPAVCDC@@VCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportPaintManager.cpp
