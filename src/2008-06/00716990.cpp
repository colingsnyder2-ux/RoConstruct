// from server: 100% by auto
// roc 2008-06 00716990  unit: CXTPPropertyGridView  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00716990
//
// 00716990  e8ebfdffff           call 0x716780
// 00716995  c21000               ret 0x10
// library mfc-9.0/atlmfc\src\mfc\afxtaskspane.cpp (function ?OnMouseWheel@CWnd@@IAEHIFVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxtaskspane.cpp
