// from server: 100% by auto
// roc 2007-03 00642b30  unit: seg_00640000  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00642b30
//
// 00642b30  56                   push esi
// 00642b31  8bf1                 mov esi, ecx
// 00642b33  e8967f0f00           call 0x73aace
// 00642b38  8d4e20               lea ecx, [esi + 0x20]
// 00642b3b  c706c4567c00         mov dword ptr [esi], 0x7c56c4
// 00642b41  e81affffff           call 0x642a60
// 00642b46  8bc6                 mov eax, esi
// 00642b48  5e                   pop esi
// 00642b49  c3                   ret 
// library xtp-15.2.1/Source\Calendar\XTPCalendarCaptionBarControl.cpp (function ??0?$CXTPCalendarPtrCollectionT@VCXTPCalendarCaptionBarThemePart@@@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Calendar/XTPCalendarCaptionBarControl.cpp
