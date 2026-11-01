// from server: 100% by auto
// roc 2007-03 0067bd40  unit: seg_00670000  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0067bd40
//
// 0067bd40  e88d29faff           call 0x61e6d2
// 0067bd45  83e811               sub eax, 0x11
// 0067bd48  f7d8                 neg eax
// 0067bd4a  1bc0                 sbb eax, eax
// 0067bd4c  83e0f0               and eax, 0xfffffff0
// 0067bd4f  83c011               add eax, 0x11
// 0067bd52  c20800               ret 8
// library mfc-8.0/atlmfc\src\mfc\barstat.cpp (function ?OnNcHitTest@CStatusBar@@IAEJVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barstat.cpp
