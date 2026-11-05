// from server: 100% by auto
// roc 2010-06 008818b0  unit: CXTPPropertyGridInplaceList  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008818b0
//
// 008818b0  56                   push esi
// 008818b1  6a00                 push 0
// 008818b3  8bf1                 mov esi, ecx
// 008818b5  e846fff7ff           call 0x801800
// 008818ba  83c404               add esp, 4
// 008818bd  8bce                 mov ecx, esi
// 008818bf  5e                   pop esi
// 008818c0  e96162f2ff           jmp 0x7a7b26
// library xtp-13.2.1/Source\PropertyGrid\XTPPropertyGridInplaceList.cpp (function ?PostNcDestroy@CXTPPropertyGridInplaceList@@MAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/PropertyGrid/XTPPropertyGridInplaceList.cpp
