// from server: 100% by auto
// roc 2008-06 00707460  unit: CXTPDockingPane  size: 9 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00707460
//
// 00707460  33c0                 xor eax, eax
// 00707462  394130               cmp dword ptr [ecx + 0x30], eax
// 00707465  0f94c0               sete al
// 00707468  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxdockingpanesrow.cpp (function ?IsEmpty@CDockingPanesRow@@UBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxdockingpanesrow.cpp
