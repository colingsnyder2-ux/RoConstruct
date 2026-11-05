// from server: 100% by auto
// roc 2011-06 008357d0  unit: CXTPReportGroupRow_Batch  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008357d0
//
// 008357d0  56                   push esi
// 008357d1  8bf1                 mov esi, ecx
// 008357d3  e8564efdff           call 0x80a62e
// 008357d8  8bce                 mov ecx, esi
// 008357da  e891deffff           call 0x833670
// 008357df  5e                   pop esi
// 008357e0  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxpaneframewnd.cpp (function ?OnMoving@CPaneFrameWnd@@IAEXIPAUtagRECT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxpaneframewnd.cpp
