// from server: 100% by auto
// roc 2009-12 008215e0  unit: CXTPReportGroupRow_Batch  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008215e0
//
// 008215e0  56                   push esi
// 008215e1  8bf1                 mov esi, ecx
// 008215e3  e84828fdff           call 0x7f3e30
// 008215e8  8bce                 mov ecx, esi
// 008215ea  e891deffff           call 0x81f480
// 008215ef  5e                   pop esi
// 008215f0  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxpaneframewnd.cpp (function ?OnMoving@CPaneFrameWnd@@IAEXIPAUtagRECT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxpaneframewnd.cpp
