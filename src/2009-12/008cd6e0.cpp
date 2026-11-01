// from server: 100% by auto
// roc 2009-12 008cd6e0  unit: CXTPPropertyGridInplaceList  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008cd6e0
//
// 008cd6e0  56                   push esi
// 008cd6e1  6a00                 push 0
// 008cd6e3  8bf1                 mov esi, ecx
// 008cd6e5  e8b600f8ff           call 0x84d7a0
// 008cd6ea  83c404               add esp, 4
// 008cd6ed  8bce                 mov ecx, esi
// 008cd6ef  5e                   pop esi
// 008cd6f0  e9f162f2ff           jmp 0x7f39e6
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGridInplaceList.cpp (function ?PostNcDestroy@CXTPPropertyGridInplaceList@@MAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGridInplaceList.cpp
