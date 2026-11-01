// from server: 100% by auto
// roc 2009-12 00808910  unit: CXTPCommandBar  size: 16 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00808910
//
// 00808910  e80b2e0300           call 0x83b720
// 00808915  8bc8                 mov ecx, eax
// 00808917  e8642e0300           call 0x83b780
// 0080891c  0fb6c0               movzx eax, al
// 0080891f  c3                   ret 
// library xtp-15.2.1/Source\Calendar\XTPCalendarUtils.cpp (function ?IsWin9x@CXTPCalendarUtils@@SAHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Calendar/XTPCalendarUtils.cpp
