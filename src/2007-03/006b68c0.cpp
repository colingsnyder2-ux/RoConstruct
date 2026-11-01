// from server: 100% by auto
// roc 2007-03 006b68c0  unit: seg_006b0000  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006b68c0
//
// 006b68c0  8b8108010000         mov eax, dword ptr [ecx + 0x108]
// 006b68c6  83f8ff               cmp eax, -1
// 006b68c9  7506                 jne 0x6b68d1
// 006b68cb  8b8104010000         mov eax, dword ptr [ecx + 0x104]
// 006b68d1  8b4c2404             mov ecx, dword ptr [esp + 4]
// 006b68d5  50                   push eax
// 006b68d6  8d44240c             lea eax, [esp + 0xc]
// 006b68da  50                   push eax
// 006b68db  e83a84f6ff           call 0x61ed1a
// 006b68e0  c21400               ret 0x14
// library xtp-13.2.1/Source\ReportControl\XTPReportPaintManager.cpp (function ?FillIndent@CXTPReportPaintManager@@UAEXPAVCDC@@VCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportPaintManager.cpp
