// from server: 100% by auto
// roc 2008-06 0070e000  unit: CXTPStatusBar  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0070e000
//
// 0070e000  e8632cf9ff           call 0x6a0c68
// 0070e005  83e811               sub eax, 0x11
// 0070e008  f7d8                 neg eax
// 0070e00a  1bc0                 sbb eax, eax
// 0070e00c  83e0f0               and eax, 0xfffffff0
// 0070e00f  83c011               add eax, 0x11
// 0070e012  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\barstat.cpp (function ?OnNcHitTest@CStatusBar@@IAEJVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/barstat.cpp
