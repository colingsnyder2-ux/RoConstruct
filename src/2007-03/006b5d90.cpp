// from server: 100% by auto
// roc 2007-03 006b5d90  unit: seg_006b0000  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006b5d90
//
// 006b5d90  56                   push esi
// 006b5d91  8bf1                 mov esi, ecx
// 006b5d93  e8364d0800           call 0x73aace
// 006b5d98  8d4e20               lea ecx, [esi + 0x20]
// 006b5d9b  c70634497d00         mov dword ptr [esi], 0x7d4934
// 006b5da1  e84affffff           call 0x6b5cf0
// 006b5da6  8bc6                 mov eax, esi
// 006b5da8  5e                   pop esi
// 006b5da9  c3                   ret 
// library xtp-15.2.1/Source\Calendar\XTPCalendarCaptionBarControl.cpp (function ??0?$CXTPCalendarPtrCollectionT@VCXTPCalendarCaptionBarThemePart@@@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Calendar/XTPCalendarCaptionBarControl.cpp
