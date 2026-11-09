// from server: 100% by auto
// roc 2009-12 0089a610  unit: CXTPReportPaintManager  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0089a610
//
// 0089a610  8b8190000000         mov eax, dword ptr [ecx + 0x90]
// 0089a616  83f8ff               cmp eax, -1
// 0089a619  7506                 jne 0x89a621
// 0089a61b  8b818c000000         mov eax, dword ptr [ecx + 0x8c]
// 0089a621  c20400               ret 4
// library xtp-13.2.1/Source\ReportControl\XTPReportPaintManager.cpp (function ?GetControlBackColor@CXTPReportPaintManager@@UAEKPAVCXTPReportControl@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportPaintManager.cpp
