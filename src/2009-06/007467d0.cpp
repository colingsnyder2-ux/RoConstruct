// from server: 100% by auto
// roc 2009-06 007467d0  unit: CXTPReportGroupRow_Batch  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007467d0
//
// 007467d0  56                   push esi
// 007467d1  8bf1                 mov esi, ecx
// 007467d3  e83028fdff           call 0x719008
// 007467d8  8bce                 mov ecx, esi
// 007467da  e891deffff           call 0x744670
// 007467df  5e                   pop esi
// 007467e0  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxpaneframewnd.cpp (function ?OnMoving@CPaneFrameWnd@@IAEXIPAUtagRECT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxpaneframewnd.cpp
