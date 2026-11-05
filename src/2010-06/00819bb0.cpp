// from server: 100% by auto
// roc 2010-06 00819bb0  unit: CPropertyGridItemBrickColor  size: 40 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00819bb0
//
// 00819bb0  56                   push esi
// 00819bb1  8d44240c             lea eax, [esp + 0xc]
// 00819bb5  50                   push eax
// 00819bb6  8bf1                 mov esi, ecx
// 00819bb8  e8335ffdff           call 0x7efaf0
// 00819bbd  85c0                 test eax, eax
// 00819bbf  7409                 je 0x819bca
// 00819bc1  b857000780           mov eax, 0x80070057
// 00819bc6  5e                   pop esi
// 00819bc7  c21400               ret 0x14
// 00819bca  8d4ee0               lea ecx, [esi - 0x20]
// 00819bcd  e83ef4ffff           call 0x819010
// 00819bd2  33c0                 xor eax, eax
// 00819bd4  5e                   pop esi
// 00819bd5  c21400               ret 0x14
// library xtp-13.2.1/Source\PropertyGrid\XTPPropertyGridItem.cpp (function ?AccessibleSelect@CXTPPropertyGridItem@@MAEJJUtagVARIANT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/PropertyGrid/XTPPropertyGridItem.cpp
