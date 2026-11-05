// from server: 100% by auto
// roc 2010-06 0080e880  unit: CXTPStatusBar  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0080e880
//
// 0080e880  e8eb96f9ff           call 0x7a7f70
// 0080e885  83e811               sub eax, 0x11
// 0080e888  f7d8                 neg eax
// 0080e88a  1bc0                 sbb eax, eax
// 0080e88c  83e0f0               and eax, 0xfffffff0
// 0080e88f  83c011               add eax, 0x11
// 0080e892  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\barstat.cpp (function ?OnNcHitTest@CStatusBar@@IAEJVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/barstat.cpp
