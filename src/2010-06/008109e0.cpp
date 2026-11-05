// from server: 100% by auto
// roc 2010-06 008109e0  unit: CXTPDockingPane  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008109e0
//
// 008109e0  83791000             cmp dword ptr [ecx + 0x10], 0
// 008109e4  7503                 jne 0x8109e9
// 008109e6  33c0                 xor eax, eax
// 008109e8  c3                   ret 
// 008109e9  8b4910               mov ecx, dword ptr [ecx + 0x10]
// 008109ec  8b01                 mov eax, dword ptr [ecx]
// 008109ee  8b501c               mov edx, dword ptr [eax + 0x1c]
// 008109f1  ffe2                 jmp edx
// library xtp-13.2.1/Source\DockingPane\XTPDockingPane.cpp (function ?IsHidden@CXTPDockingPane@@UBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPane.cpp
