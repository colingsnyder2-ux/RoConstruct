// from server: 100% by auto
// roc 2010-06 0081e150  unit: CXTPPropertyGridView  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0081e150
//
// 0081e150  e8ebfdffff           call 0x81df40
// 0081e155  c21000               ret 0x10
// library mfc-9.0/atlmfc\src\mfc\afxtaskspane.cpp (function ?OnMouseWheel@CWnd@@IAEHIFVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxtaskspane.cpp
