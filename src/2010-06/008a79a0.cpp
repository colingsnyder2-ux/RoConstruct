// from server: 100% by auto
// roc 2010-06 008a79a0  unit: CXTWndHook  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008a79a0
//
// 008a79a0  56                   push esi
// 008a79a1  6a0a                 push 0xa
// 008a79a3  8bf1                 mov esi, ecx
// 008a79a5  e88e5a0d00           call 0x97d438
// 008a79aa  c7061c3da700         mov dword ptr [esi], 0xa73d1c
// 008a79b0  8bc6                 mov eax, esi
// 008a79b2  5e                   pop esi
// 008a79b3  c3                   ret 
// library xtp-13.2.1/Source\Calendar\XTPCalendarThemeOffice2007.cpp (function ??0?$CXTPCalendarTypedPtrAutoDeleteMap@PAVCXTPCalendarDayViewEvent@@PAVCObject@@@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Calendar/XTPCalendarThemeOffice2007.cpp
