// from server: 100% by auto
// roc 2010-06 007cf340  unit: PAVCXTPReportInplaceButton::?$CArray  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007cf340
//
// 007cf340  56                   push esi
// 007cf341  8bf1                 mov esi, ecx
// 007cf343  e836da1a00           call 0x97cd7e
// 007cf348  8d4e20               lea ecx, [esi + 0x20]
// 007cf34b  c706dc8ca500         mov dword ptr [esi], 0xa58cdc
// 007cf351  e8fafeffff           call 0x7cf250
// 007cf356  8bc6                 mov eax, esi
// 007cf358  5e                   pop esi
// 007cf359  c3                   ret 
// library xtp-13.2.1/Source\Calendar\XTPCalendarCaptionBarControl.cpp (function ??0?$CXTPCalendarPtrCollectionT@VCXTPCalendarCaptionBarThemePart@@@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Calendar/XTPCalendarCaptionBarControl.cpp
