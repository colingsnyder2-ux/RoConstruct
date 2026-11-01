// from server: 100% by auto
// roc 2009-06 0078b340  unit: CXTPPropertyGridItem  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0078b340
//
// 0078b340  56                   push esi
// 0078b341  8bf1                 mov esi, ecx
// 0078b343  e8e20b0c00           call 0x84bf2a
// 0078b348  8d4e20               lea ecx, [esi + 0x20]
// 0078b34b  c7066ce58f00         mov dword ptr [esi], 0x8fe56c
// 0078b351  e8fafaffff           call 0x78ae50
// 0078b356  8bc6                 mov eax, esi
// 0078b358  5e                   pop esi
// 0078b359  c3                   ret 
// library xtp-15.2.1/Source\Calendar\XTPCalendarCaptionBarControl.cpp (function ??0?$CXTPCalendarPtrCollectionT@VCXTPCalendarCaptionBarThemePart@@@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Calendar/XTPCalendarCaptionBarControl.cpp
