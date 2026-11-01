// from server: 100% by auto
// roc 2007-08 00698fd0  unit: CPropertyGridItemBrickColor  size: 40 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00698fd0
//
// 00698fd0  56                   push esi
// 00698fd1  8d44240c             lea eax, [esp + 0xc]
// 00698fd5  50                   push eax
// 00698fd6  8bf1                 mov esi, ecx
// 00698fd8  e8f383fdff           call 0x6713d0
// 00698fdd  85c0                 test eax, eax
// 00698fdf  7409                 je 0x698fea
// 00698fe1  b857000780           mov eax, 0x80070057
// 00698fe6  5e                   pop esi
// 00698fe7  c21400               ret 0x14
// 00698fea  8d4ee0               lea ecx, [esi - 0x20]
// 00698fed  e89ef4ffff           call 0x698490
// 00698ff2  33c0                 xor eax, eax
// 00698ff4  5e                   pop esi
// 00698ff5  c21400               ret 0x14
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGridItem.cpp (function ?AccessibleSelect@CXTPPropertyGridItem@@MAEJJUtagVARIANT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGridItem.cpp
