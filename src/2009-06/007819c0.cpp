// from server: 100% by auto
// roc 2009-06 007819c0  unit: CXTPDockingPane  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007819c0
//
// 007819c0  83791000             cmp dword ptr [ecx + 0x10], 0
// 007819c4  7503                 jne 0x7819c9
// 007819c6  33c0                 xor eax, eax
// 007819c8  c3                   ret 
// 007819c9  8b4910               mov ecx, dword ptr [ecx + 0x10]
// 007819cc  8b01                 mov eax, dword ptr [ecx]
// 007819ce  8b501c               mov edx, dword ptr [eax + 0x1c]
// 007819d1  ffe2                 jmp edx
// library xtp-15.2.1/Source\DockingPane\XTPDockingPane.cpp (function ?IsHidden@CXTPDockingPane@@UBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPane.cpp
