// from server: 100% by auto
// roc 2009-12 006b0d90  unit: RBX::Accoutrement  size: 9 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006b0d90
//
// 006b0d90  e88bffffff           call 0x6b0d20
// 006b0d95  83c030               add eax, 0x30
// 006b0d98  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\thrdcore.cpp (function ?AfxGetCurrentMessage@@YGPAUtagMSG@@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/thrdcore.cpp
