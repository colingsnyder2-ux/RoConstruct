// from server: 100% by auto
// roc 2010-06 007d5640  unit: CXTPReportGroupRow_Batch  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007d5640
//
// 007d5640  56                   push esi
// 007d5641  8bf1                 mov esi, ecx
// 007d5643  e82829fdff           call 0x7a7f70
// 007d5648  8bce                 mov ecx, esi
// 007d564a  e891deffff           call 0x7d34e0
// 007d564f  5e                   pop esi
// 007d5650  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxpaneframewnd.cpp (function ?OnMoving@CPaneFrameWnd@@IAEXIPAUtagRECT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxpaneframewnd.cpp
