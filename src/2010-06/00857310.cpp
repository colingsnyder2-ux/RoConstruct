// from server: 100% by auto
// roc 2010-06 00857310  unit: CXTPReportHyperlinks  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00857310
//
// 00857310  56                   push esi
// 00857311  8bf1                 mov esi, ecx
// 00857313  e8665a1200           call 0x97cd7e
// 00857318  8d4e20               lea ecx, [esi + 0x20]
// 0085731b  c706649ca600         mov dword ptr [esi], 0xa69c64
// 00857321  e8bafeffff           call 0x8571e0
// 00857326  8bc6                 mov eax, esi
// 00857328  5e                   pop esi
// 00857329  c3                   ret 
// library xtp-13.2.1/Source\Calendar\XTPCalendarCaptionBarControl.cpp (function ??0?$CXTPCalendarPtrCollectionT@VCXTPCalendarCaptionBarThemePart@@@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Calendar/XTPCalendarCaptionBarControl.cpp
