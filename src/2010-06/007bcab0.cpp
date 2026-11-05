// from server: 100% by auto
// roc 2010-06 007bcab0  unit: CXTPCommandBar  size: 16 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007bcab0
//
// 007bcab0  e8bb2d0300           call 0x7ef870
// 007bcab5  8bc8                 mov ecx, eax
// 007bcab7  e8142e0300           call 0x7ef8d0
// 007bcabc  0fb6c0               movzx eax, al
// 007bcabf  c3                   ret 
// library xtp-13.2.1/Source\Calendar\XTPCalendarUtils.cpp (function ?IsWin9x@CXTPCalendarUtils@@SAHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Calendar/XTPCalendarUtils.cpp
