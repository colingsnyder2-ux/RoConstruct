// from server: 100% by auto
// roc 2009-12 0085ca00  unit: CXTPDockingPane  size: 9 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0085ca00
//
// 0085ca00  33c0                 xor eax, eax
// 0085ca02  394130               cmp dword ptr [ecx + 0x30], eax
// 0085ca05  0f94c0               sete al
// 0085ca08  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxdockingpanesrow.cpp (function ?IsEmpty@CDockingPanesRow@@UBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxdockingpanesrow.cpp
