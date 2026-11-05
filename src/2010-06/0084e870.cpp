// from server: 100% by auto
// roc 2010-06 0084e870  unit: CXTPReportPaintManager  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0084e870
//
// 0084e870  8b8108010000         mov eax, dword ptr [ecx + 0x108]
// 0084e876  83f8ff               cmp eax, -1
// 0084e879  7506                 jne 0x84e881
// 0084e87b  8b8104010000         mov eax, dword ptr [ecx + 0x104]
// 0084e881  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0084e885  50                   push eax
// 0084e886  8d44240c             lea eax, [esp + 0xc]
// 0084e88a  50                   push eax
// 0084e88b  e8ae9ef5ff           call 0x7a873e
// 0084e890  c21400               ret 0x14
// library xtp-13.2.1/Source\ReportControl\XTPReportPaintManager.cpp (function ?FillIndent@CXTPReportPaintManager@@UAEXPAVCDC@@VCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportPaintManager.cpp
