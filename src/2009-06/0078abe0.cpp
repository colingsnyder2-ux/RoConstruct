// from server: 100% by auto
// roc 2009-06 0078abe0  unit: CPropertyGridItemBrickColor  size: 40 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0078abe0
//
// 0078abe0  56                   push esi
// 0078abe1  8d44240c             lea eax, [esp + 0xc]
// 0078abe5  50                   push eax
// 0078abe6  8bf1                 mov esi, ecx
// 0078abe8  e8e35ffdff           call 0x760bd0
// 0078abed  85c0                 test eax, eax
// 0078abef  7409                 je 0x78abfa
// 0078abf1  b857000780           mov eax, 0x80070057
// 0078abf6  5e                   pop esi
// 0078abf7  c21400               ret 0x14
// 0078abfa  8d4ee0               lea ecx, [esi - 0x20]
// 0078abfd  e83ef4ffff           call 0x78a040
// 0078ac02  33c0                 xor eax, eax
// 0078ac04  5e                   pop esi
// 0078ac05  c21400               ret 0x14
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGridItem.cpp (function ?AccessibleSelect@CXTPPropertyGridItem@@MAEJJUtagVARIANT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGridItem.cpp
