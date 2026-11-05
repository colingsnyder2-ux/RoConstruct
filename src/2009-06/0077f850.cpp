// from server: 100% by auto
// roc 2009-06 0077f850  unit: CXTPStatusBar  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0077f850
//
// 0077f850  e8b397f9ff           call 0x719008
// 0077f855  83e811               sub eax, 0x11
// 0077f858  f7d8                 neg eax
// 0077f85a  1bc0                 sbb eax, eax
// 0077f85c  83e0f0               and eax, 0xfffffff0
// 0077f85f  83c011               add eax, 0x11
// 0077f862  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\barstat.cpp (function ?OnNcHitTest@CStatusBar@@IAEJVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/barstat.cpp
