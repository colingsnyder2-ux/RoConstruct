// from server: 100% by auto
// roc 2009-06 007bf820  unit: CXTPReportPaintManager  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007bf820
//
// 007bf820  8b8190000000         mov eax, dword ptr [ecx + 0x90]
// 007bf826  83f8ff               cmp eax, -1
// 007bf829  7506                 jne 0x7bf831
// 007bf82b  8b818c000000         mov eax, dword ptr [ecx + 0x8c]
// 007bf831  c20400               ret 4
// library xtp-13.2.1/Source\ReportControl\XTPReportPaintManager.cpp (function ?GetControlBackColor@CXTPReportPaintManager@@UAEKPAVCXTPReportControl@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportPaintManager.cpp
