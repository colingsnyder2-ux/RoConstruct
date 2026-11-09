// from server: 100% by auto
// roc 2007-08 0069d060  unit: CXTPPropertyGridView  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0069d060
//
// 0069d060  e8ebfdffff           call 0x69ce50
// 0069d065  c21000               ret 0x10
// library mfc-9.0/atlmfc\src\mfc\afxtaskspane.cpp (function ?OnMouseWheel@CWnd@@IAEHIFVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxtaskspane.cpp
