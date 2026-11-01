// from server: 100% by auto
// roc 2009-12 00865bf0  unit: CPropertyGridItemBrickColor  size: 40 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00865bf0
//
// 00865bf0  56                   push esi
// 00865bf1  8d44240c             lea eax, [esp + 0xc]
// 00865bf5  50                   push eax
// 00865bf6  8bf1                 mov esi, ecx
// 00865bf8  e8a35dfdff           call 0x83b9a0
// 00865bfd  85c0                 test eax, eax
// 00865bff  7409                 je 0x865c0a
// 00865c01  b857000780           mov eax, 0x80070057
// 00865c06  5e                   pop esi
// 00865c07  c21400               ret 0x14
// 00865c0a  8d4ee0               lea ecx, [esi - 0x20]
// 00865c0d  e83ef4ffff           call 0x865050
// 00865c12  33c0                 xor eax, eax
// 00865c14  5e                   pop esi
// 00865c15  c21400               ret 0x14
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGridItem.cpp (function ?AccessibleSelect@CXTPPropertyGridItem@@MAEJJUtagVARIANT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGridItem.cpp
