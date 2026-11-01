// from server: 100% by auto
// roc 2009-12 0085ca10  unit: CXTPDockingPane  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0085ca10
//
// 0085ca10  83791000             cmp dword ptr [ecx + 0x10], 0
// 0085ca14  7503                 jne 0x85ca19
// 0085ca16  33c0                 xor eax, eax
// 0085ca18  c3                   ret 
// 0085ca19  8b4910               mov ecx, dword ptr [ecx + 0x10]
// 0085ca1c  8b01                 mov eax, dword ptr [ecx]
// 0085ca1e  8b501c               mov edx, dword ptr [eax + 0x1c]
// 0085ca21  ffe2                 jmp edx
// library xtp-15.2.1/Source\DockingPane\XTPDockingPane.cpp (function ?IsHidden@CXTPDockingPane@@UBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPane.cpp
