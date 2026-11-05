// from server: 100% by auto
// roc 2009-06 007bf910  unit: CXTPReportPaintManager  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007bf910
//
// 007bf910  8b8108010000         mov eax, dword ptr [ecx + 0x108]
// 007bf916  83f8ff               cmp eax, -1
// 007bf919  7506                 jne 0x7bf921
// 007bf91b  8b8104010000         mov eax, dword ptr [ecx + 0x104]
// 007bf921  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007bf925  50                   push eax
// 007bf926  8d44240c             lea eax, [esp + 0xc]
// 007bf92a  50                   push eax
// 007bf92b  e8a09ef5ff           call 0x7197d0
// 007bf930  c21400               ret 0x14
// library xtp-13.2.1/Source\ReportControl\XTPReportPaintManager.cpp (function ?FillIndent@CXTPReportPaintManager@@UAEXPAVCDC@@VCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportPaintManager.cpp
