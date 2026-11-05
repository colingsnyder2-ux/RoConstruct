// from server: 100% by auto
// roc 2011-06 0086c010  unit: CXTPStatusBar  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0086c010
//
// 0086c010  e819e6f9ff           call 0x80a62e
// 0086c015  83e811               sub eax, 0x11
// 0086c018  f7d8                 neg eax
// 0086c01a  1bc0                 sbb eax, eax
// 0086c01c  83e0f0               and eax, 0xfffffff0
// 0086c01f  83c011               add eax, 0x11
// 0086c022  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\barstat.cpp (function ?OnNcHitTest@CStatusBar@@IAEJVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/barstat.cpp
