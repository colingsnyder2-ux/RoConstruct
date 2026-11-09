// from server: 100% by auto
// roc 2007-08 00692320  unit: CXTPStatusBar  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00692320
//
// 00692320  e819dff9ff           call 0x63023e
// 00692325  83e811               sub eax, 0x11
// 00692328  f7d8                 neg eax
// 0069232a  1bc0                 sbb eax, eax
// 0069232c  83e0f0               and eax, 0xfffffff0
// 0069232f  83c011               add eax, 0x11
// 00692332  c20800               ret 8
// library mfc-8.0/atlmfc\src\mfc\barstat.cpp (function ?OnNcHitTest@CStatusBar@@IAEJVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barstat.cpp
