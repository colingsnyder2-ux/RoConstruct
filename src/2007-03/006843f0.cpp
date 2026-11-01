// from server: 100% by auto
// roc 2007-03 006843f0  unit: seg_00680000  size: 40 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006843f0
//
// 006843f0  56                   push esi
// 006843f1  8d44240c             lea eax, [esp + 0xc]
// 006843f5  50                   push eax
// 006843f6  8bf1                 mov esi, ecx
// 006843f8  e8b31b0000           call 0x685fb0
// 006843fd  85c0                 test eax, eax
// 006843ff  7409                 je 0x68440a
// 00684401  b857000780           mov eax, 0x80070057
// 00684406  5e                   pop esi
// 00684407  c21400               ret 0x14
// 0068440a  8d4ee0               lea ecx, [esi - 0x20]
// 0068440d  e8def3ffff           call 0x6837f0
// 00684412  33c0                 xor eax, eax
// 00684414  5e                   pop esi
// 00684415  c21400               ret 0x14
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGridItem.cpp (function ?AccessibleSelect@CXTPPropertyGridItem@@MAEJJUtagVARIANT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGridItem.cpp
