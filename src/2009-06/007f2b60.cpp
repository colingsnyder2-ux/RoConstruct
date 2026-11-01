// from server: 100% by auto
// roc 2009-06 007f2b60  unit: CXTPPropertyGridInplaceList  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007f2b60
//
// 007f2b60  56                   push esi
// 007f2b61  6a00                 push 0
// 007f2b63  8bf1                 mov esi, ecx
// 007f2b65  e806fff7ff           call 0x772a70
// 007f2b6a  83c404               add esp, 4
// 007f2b6d  8bce                 mov ecx, esi
// 007f2b6f  5e                   pop esi
// 007f2b70  e94960f2ff           jmp 0x718bbe
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGridInplaceList.cpp (function ?PostNcDestroy@CXTPPropertyGridInplaceList@@MAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGridInplaceList.cpp
