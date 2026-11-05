// from server: 100% by auto
// roc 2012-06 009e6fa0  unit: CXTPStatusBar  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009e6fa0
//
// 009e6fa0  e839b7f9ff           call 0x9826de
// 009e6fa5  83e811               sub eax, 0x11
// 009e6fa8  f7d8                 neg eax
// 009e6faa  1bc0                 sbb eax, eax
// 009e6fac  83e0f0               and eax, 0xfffffff0
// 009e6faf  83c011               add eax, 0x11
// 009e6fb2  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\barstat.cpp (function ?OnNcHitTest@CStatusBar@@IAEJVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/barstat.cpp
