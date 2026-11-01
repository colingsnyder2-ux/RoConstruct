// from server: 100% by auto
// roc 2007-03 006b6310  unit: seg_006b0000  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006b6310
//
// 006b6310  8b8190000000         mov eax, dword ptr [ecx + 0x90]
// 006b6316  83f8ff               cmp eax, -1
// 006b6319  7506                 jne 0x6b6321
// 006b631b  8b818c000000         mov eax, dword ptr [ecx + 0x8c]
// 006b6321  c20400               ret 4
// library xtp-13.2.1/Source\ReportControl\XTPReportPaintManager.cpp (function ?GetControlBackColor@CXTPReportPaintManager@@UAEKPAVCXTPReportControl@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportPaintManager.cpp
