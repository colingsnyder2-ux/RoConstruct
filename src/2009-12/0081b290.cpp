// from server: 100% by auto
// roc 2009-12 0081b290  unit: PAVCXTPReportInplaceButton::?$CArray  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0081b290
//
// 0081b290  56                   push esi
// 0081b291  8bf1                 mov esi, ecx
// 0081b293  e8aab11000           call 0x926442
// 0081b298  8d4e20               lea ecx, [esi + 0x20]
// 0081b29b  c706ec499f00         mov dword ptr [esi], 0x9f49ec
// 0081b2a1  e8fafeffff           call 0x81b1a0
// 0081b2a6  8bc6                 mov eax, esi
// 0081b2a8  5e                   pop esi
// 0081b2a9  c3                   ret 
// library xtp-15.2.1/Source\Calendar\XTPCalendarCaptionBarControl.cpp (function ??0?$CXTPCalendarPtrCollectionT@VCXTPCalendarCaptionBarThemePart@@@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Calendar/XTPCalendarCaptionBarControl.cpp
