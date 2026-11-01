// from server: 100% by auto
// roc 2007-03 00624760  unit: seg_00620000  size: 16 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00624760
//
// 00624760  e8ab150600           call 0x685d10
// 00624765  8bc8                 mov ecx, eax
// 00624767  e804160600           call 0x685d70
// 0062476c  0fb6c0               movzx eax, al
// 0062476f  c3                   ret 
// library xtp-15.2.1/Source\Calendar\XTPCalendarUtils.cpp (function ?IsWin9x@CXTPCalendarUtils@@SAHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Calendar/XTPCalendarUtils.cpp
