// from server: 100% by auto
// roc 2009-06 008028a0  unit: CXTColorBase  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 008028a0
//
// 008028a0  56                   push esi
// 008028a1  8bf1                 mov esi, ecx
// 008028a3  8b4620               mov eax, dword ptr [esi + 0x20]
// 008028a6  50                   push eax
// 008028a7  ff15e0ed8900         call dword ptr [0x89ede0]
// 008028ad  85c0                 test eax, eax
// 008028af  7422                 je 0x8028d3
// 008028b1  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 008028b4  6af0                 push -0x10
// 008028b6  51                   push ecx
// 008028b7  ff1558ed8900         call dword ptr [0x89ed58]
// 008028bd  8b5620               mov edx, dword ptr [esi + 0x20]
// 008028c0  0d00010000           or eax, 0x100
// 008028c5  50                   push eax
// 008028c6  6af0                 push -0x10
// 008028c8  52                   push edx
// 008028c9  ff1534ed8900         call dword ptr [0x89ed34]
// 008028cf  b001                 mov al, 1
// 008028d1  5e                   pop esi
// 008028d2  c3                   ret 
// 008028d3  32c0                 xor al, al
// 008028d5  5e                   pop esi
// 008028d6  c3                   ret 
// library xtp-15.2.1/Source\Controls\Dialog\XTPColorPageCustom.cpp (function ?Init@CXTPColorBase@@MAE_NXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Dialog/XTPColorPageCustom.cpp
