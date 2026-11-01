// from server: 100% by auto
// roc 2009-12 008a31a0  unit: CXTPReportHyperlinks  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008a31a0
//
// 008a31a0  56                   push esi
// 008a31a1  8bf1                 mov esi, ecx
// 008a31a3  e89a320800           call 0x926442
// 008a31a8  8d4e20               lea ecx, [esi + 0x20]
// 008a31ab  c7067c59a000         mov dword ptr [esi], 0xa0597c
// 008a31b1  e88afeffff           call 0x8a3040
// 008a31b6  8bc6                 mov eax, esi
// 008a31b8  5e                   pop esi
// 008a31b9  c3                   ret 
// library xtp-15.2.1/Source\Calendar\XTPCalendarCaptionBarControl.cpp (function ??0?$CXTPCalendarPtrCollectionT@VCXTPCalendarCaptionBarThemePart@@@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Calendar/XTPCalendarCaptionBarControl.cpp
