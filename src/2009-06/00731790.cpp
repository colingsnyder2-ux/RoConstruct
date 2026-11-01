// from server: 100% by auto
// roc 2009-06 00731790  unit: CXTPCommandBar  size: 16 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00731790
//
// 00731790  e8bbf10200           call 0x760950
// 00731795  8bc8                 mov ecx, eax
// 00731797  e814f20200           call 0x7609b0
// 0073179c  0fb6c0               movzx eax, al
// 0073179f  c3                   ret 
// library xtp-15.2.1/Source\Calendar\XTPCalendarUtils.cpp (function ?IsWin9x@CXTPCalendarUtils@@SAHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Calendar/XTPCalendarUtils.cpp
