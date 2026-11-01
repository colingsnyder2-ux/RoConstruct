// from server: 100% by auto
// roc 2011-06 008ab8e0  unit: CXTPReportPaintManager  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008ab8e0
//
// 008ab8e0  8b8190000000         mov eax, dword ptr [ecx + 0x90]
// 008ab8e6  83f8ff               cmp eax, -1
// 008ab8e9  7506                 jne 0x8ab8f1
// 008ab8eb  8b818c000000         mov eax, dword ptr [ecx + 0x8c]
// 008ab8f1  c20400               ret 4
// library xtp-13.2.1/Source\ReportControl\XTPReportPaintManager.cpp (function ?GetControlBackColor@CXTPReportPaintManager@@UAEKPAVCXTPReportControl@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportPaintManager.cpp
