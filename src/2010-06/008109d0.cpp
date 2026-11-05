// from server: 100% by auto
// roc 2010-06 008109d0  unit: CXTPDockingPane  size: 9 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008109d0
//
// 008109d0  33c0                 xor eax, eax
// 008109d2  394130               cmp dword ptr [ecx + 0x30], eax
// 008109d5  0f94c0               sete al
// 008109d8  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxdockingpanesrow.cpp (function ?IsEmpty@CDockingPanesRow@@UBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxdockingpanesrow.cpp
