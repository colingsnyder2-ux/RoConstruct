// from server: 100% by auto
// roc 2007-03 006dcbe0  unit: seg_006d0000  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006dcbe0
//
// 006dcbe0  56                   push esi
// 006dcbe1  6a00                 push 0
// 006dcbe3  8bf1                 mov esi, ecx
// 006dcbe5  e84610f9ff           call 0x66dc30
// 006dcbea  83c404               add esp, 4
// 006dcbed  8bce                 mov ecx, esi
// 006dcbef  5e                   pop esi
// 006dcbf0  e98716f4ff           jmp 0x61e27c
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGridInplaceList.cpp (function ?PostNcDestroy@CXTPPropertyGridInplaceList@@MAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGridInplaceList.cpp
