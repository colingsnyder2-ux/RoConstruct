// from server: 100% by auto
// roc 2010-06 007e2270  unit: VCXTPReportRows::?$CXTPHeapObjectT  size: 16 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007e2270
//
// 007e2270  8b01                 mov eax, dword ptr [ecx]
// 007e2272  8b908c000000         mov edx, dword ptr [eax + 0x8c]
// 007e2278  68c01d7e00           push 0x7e1dc0
// 007e227d  ffd2                 call edx
// 007e227f  c3                   ret 
// library xtp-13.2.1-shared-mfc/Source\ReportControl\XTPReportRows.cpp (function ?Sort@CXTPReportRows@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/ReportControl/XTPReportRows.cpp
