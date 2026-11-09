// from server: 100% by auto
// roc 2009-12 0089a710  unit: CXTPReportPaintManager  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0089a710
//
// 0089a710  8b8108010000         mov eax, dword ptr [ecx + 0x108]
// 0089a716  83f8ff               cmp eax, -1
// 0089a719  7506                 jne 0x89a721
// 0089a71b  8b8104010000         mov eax, dword ptr [ecx + 0x104]
// 0089a721  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0089a725  50                   push eax
// 0089a726  8d44240c             lea eax, [esp + 0xc]
// 0089a72a  50                   push eax
// 0089a72b  e8ce9ef5ff           call 0x7f45fe
// 0089a730  c21400               ret 0x14
// library xtp-13.2.1/Source\ReportControl\XTPReportPaintManager.cpp (function ?FillIndent@CXTPReportPaintManager@@UAEXPAVCDC@@VCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportPaintManager.cpp
