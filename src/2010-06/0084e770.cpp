// from server: 100% by auto
// roc 2010-06 0084e770  unit: CXTPReportPaintManager  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0084e770
//
// 0084e770  8b8190000000         mov eax, dword ptr [ecx + 0x90]
// 0084e776  83f8ff               cmp eax, -1
// 0084e779  7506                 jne 0x84e781
// 0084e77b  8b818c000000         mov eax, dword ptr [ecx + 0x8c]
// 0084e781  c20400               ret 4
// library xtp-13.2.1/Source\ReportControl\XTPReportPaintManager.cpp (function ?GetControlBackColor@CXTPReportPaintManager@@UAEKPAVCXTPReportControl@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportPaintManager.cpp
