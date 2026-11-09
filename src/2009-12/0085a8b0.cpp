// from server: 100% by auto
// roc 2009-12 0085a8b0  unit: CXTPStatusBar  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0085a8b0
//
// 0085a8b0  e87b95f9ff           call 0x7f3e30
// 0085a8b5  83e811               sub eax, 0x11
// 0085a8b8  f7d8                 neg eax
// 0085a8ba  1bc0                 sbb eax, eax
// 0085a8bc  83e0f0               and eax, 0xfffffff0
// 0085a8bf  83c011               add eax, 0x11
// 0085a8c2  c20800               ret 8
// library mfc-8.0/atlmfc\src\mfc\barstat.cpp (function ?OnNcHitTest@CStatusBar@@IAEJVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barstat.cpp
