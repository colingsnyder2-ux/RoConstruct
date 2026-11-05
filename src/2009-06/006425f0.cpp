// from server: 100% by auto
// roc 2009-06 006425f0  unit: RBX::Accoutrement  size: 9 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006425f0
//
// 006425f0  e88bffffff           call 0x642580
// 006425f5  83c030               add eax, 0x30
// 006425f8  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\thrdcore.cpp (function ?AfxGetCurrentMessage@@YGPAUtagMSG@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/thrdcore.cpp
