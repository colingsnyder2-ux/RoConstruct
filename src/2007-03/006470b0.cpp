// from server: 100% by auto
// roc 2007-03 006470b0  unit: seg_00640000  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006470b0
//
// 006470b0  56                   push esi
// 006470b1  8bf1                 mov esi, ecx
// 006470b3  e81a76fdff           call 0x61e6d2
// 006470b8  8bce                 mov ecx, esi
// 006470ba  e871e1ffff           call 0x645230
// 006470bf  5e                   pop esi
// 006470c0  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxpaneframewnd.cpp (function ?OnMoving@CPaneFrameWnd@@IAEXIPAUtagRECT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxpaneframewnd.cpp
