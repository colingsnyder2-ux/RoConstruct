// from server: 100% by auto
// roc 2007-08 00659340  unit: CXTPReportGroupRow_Batch  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00659340
//
// 00659340  56                   push esi
// 00659341  8bf1                 mov esi, ecx
// 00659343  e8f66efdff           call 0x63023e
// 00659348  8bce                 mov ecx, esi
// 0065934a  e8c1e0ffff           call 0x657410
// 0065934f  5e                   pop esi
// 00659350  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxpaneframewnd.cpp (function ?OnMoving@CPaneFrameWnd@@IAEXIPAUtagRECT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxpaneframewnd.cpp
