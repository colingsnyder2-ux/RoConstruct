// from server: 100% by auto
// roc 2009-12 00866350  unit: CXTPPropertyGridItem  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00866350
//
// 00866350  56                   push esi
// 00866351  8bf1                 mov esi, ecx
// 00866353  e8ea000c00           call 0x926442
// 00866358  8d4e20               lea ecx, [esi + 0x20]
// 0086635b  c706fce99f00         mov dword ptr [esi], 0x9fe9fc
// 00866361  e8fafaffff           call 0x865e60
// 00866366  8bc6                 mov eax, esi
// 00866368  5e                   pop esi
// 00866369  c3                   ret 
// library xtp-15.2.1/Source\Calendar\XTPCalendarCaptionBarControl.cpp (function ??0?$CXTPCalendarPtrCollectionT@VCXTPCalendarCaptionBarThemePart@@@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Calendar/XTPCalendarCaptionBarControl.cpp
