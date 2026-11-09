// from server: 100% by auto
// roc 2008-06 006ce090  unit: CXTPReportGroupRow_Batch  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006ce090
//
// 006ce090  56                   push esi
// 006ce091  8bf1                 mov esi, ecx
// 006ce093  e8d02bfdff           call 0x6a0c68
// 006ce098  8bce                 mov ecx, esi
// 006ce09a  e891deffff           call 0x6cbf30
// 006ce09f  5e                   pop esi
// 006ce0a0  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxpaneframewnd.cpp (function ?OnMoving@CPaneFrameWnd@@IAEXIPAUtagRECT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxpaneframewnd.cpp
