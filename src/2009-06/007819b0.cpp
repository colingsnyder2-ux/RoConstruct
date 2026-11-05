// from server: 100% by auto
// roc 2009-06 007819b0  unit: CXTPDockingPane  size: 9 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007819b0
//
// 007819b0  33c0                 xor eax, eax
// 007819b2  394130               cmp dword ptr [ecx + 0x30], eax
// 007819b5  0f94c0               sete al
// 007819b8  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxdockingpanesrow.cpp (function ?IsEmpty@CDockingPanesRow@@UBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxdockingpanesrow.cpp
