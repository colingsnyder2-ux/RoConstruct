// from server: 100% by auto
// roc 2012-06 009adde0  unit: CXTPReportGroupRow_Batch  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009adde0
//
// 009adde0  56                   push esi
// 009adde1  8bf1                 mov esi, ecx
// 009adde3  e8f648fdff           call 0x9826de
// 009adde8  8bce                 mov ecx, esi
// 009addea  e881deffff           call 0x9abc70
// 009addef  5e                   pop esi
// 009addf0  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxpaneframewnd.cpp (function ?OnMoving@CPaneFrameWnd@@IAEXIPAUtagRECT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxpaneframewnd.cpp
