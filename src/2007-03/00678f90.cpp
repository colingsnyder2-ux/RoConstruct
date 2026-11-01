// from server: 100% by auto
// roc 2007-03 00678f90  unit: seg_00670000  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00678f90
//
// 00678f90  83791000             cmp dword ptr [ecx + 0x10], 0
// 00678f94  7503                 jne 0x678f99
// 00678f96  33c0                 xor eax, eax
// 00678f98  c3                   ret 
// 00678f99  8b4910               mov ecx, dword ptr [ecx + 0x10]
// 00678f9c  8b01                 mov eax, dword ptr [ecx]
// 00678f9e  8b501c               mov edx, dword ptr [eax + 0x1c]
// 00678fa1  ffe2                 jmp edx
// library xtp-15.2.1/Source\DockingPane\XTPDockingPane.cpp (function ?IsHidden@CXTPDockingPane@@UBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPane.cpp
