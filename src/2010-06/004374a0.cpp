// from server: 100% by auto
// roc 2010-06 004374a0  unit: MVCXTPPropertyGridItem::?$XItem  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004374a0
//
// 004374a0  8b01                 mov eax, dword ptr [ecx]
// 004374a2  ffa0f0000000         jmp dword ptr [eax + 0xf0]
// library xtp-13.2.1/Source\Calendar\XTPCalendarCaptionBarControl.cpp (function ??_9CXTPCalendarCaptionBarTheme@@$BPA@AE)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Calendar/XTPCalendarCaptionBarControl.cpp
