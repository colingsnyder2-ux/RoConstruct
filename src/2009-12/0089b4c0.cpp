// from server: 100% by auto
// roc 2009-12 0089b4c0  unit: CXTPReportPaintManager  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0089b4c0
//
// 0089b4c0  8b4178               mov eax, dword ptr [ecx + 0x78]
// 0089b4c3  83f8ff               cmp eax, -1
// 0089b4c6  7503                 jne 0x89b4cb
// 0089b4c8  8b4174               mov eax, dword ptr [ecx + 0x74]
// 0089b4cb  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0089b4cf  50                   push eax
// 0089b4d0  8d44240c             lea eax, [esp + 0xc]
// 0089b4d4  50                   push eax
// 0089b4d5  e82491f5ff           call 0x7f45fe
// 0089b4da  c21400               ret 0x14
// library xtp-13.2.1/Source\ReportControl\XTPReportPaintManager.cpp (function ?FillHeaderControl@CXTPReportPaintManager@@UAEXPAVCDC@@VCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportPaintManager.cpp
