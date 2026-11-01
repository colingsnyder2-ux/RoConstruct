// from server: 100% by auto
// roc 2007-03 00684ac0  unit: seg_00680000  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00684ac0
//
// 00684ac0  56                   push esi
// 00684ac1  8bf1                 mov esi, ecx
// 00684ac3  e806600b00           call 0x73aace
// 00684ac8  8d4e20               lea ecx, [esi + 0x20]
// 00684acb  c706d4e37c00         mov dword ptr [esi], 0x7ce3d4
// 00684ad1  e88afbffff           call 0x684660
// 00684ad6  8bc6                 mov eax, esi
// 00684ad8  5e                   pop esi
// 00684ad9  c3                   ret 
// library xtp-15.2.1/Source\Calendar\XTPCalendarCaptionBarControl.cpp (function ??0?$CXTPCalendarPtrCollectionT@VCXTPCalendarCaptionBarThemePart@@@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Calendar/XTPCalendarCaptionBarControl.cpp
