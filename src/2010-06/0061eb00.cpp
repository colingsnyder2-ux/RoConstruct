// from server: 100% by auto
// roc 2010-06 0061eb00  unit: RBX::Accoutrement  size: 9 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0061eb00
//
// 0061eb00  e88bffffff           call 0x61ea90
// 0061eb05  83c030               add eax, 0x30
// 0061eb08  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\thrdcore.cpp (function ?AfxGetCurrentMessage@@YGPAUtagMSG@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/thrdcore.cpp
