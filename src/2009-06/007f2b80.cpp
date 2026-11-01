// from server: 100% by tester
// roc 2012-06 00a5d8c0  unit: CXTPPropertyGridInplaceList  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a5d8c0
//
// 00a5d8c0  56                   push esi
// 00a5d8c1  8bf1                 mov esi, ecx
// 00a5d8c3  6a00                 push 0
// 00a5d8c5  c7465400000000       mov dword ptr [esi + 0x54], 0
// 00a5d8cc  e8bf9df7ff           call 0x9d7690
// 00a5d8d1  8b06                 mov eax, dword ptr [esi]
// 00a5d8d3  8b5068               mov edx, dword ptr [eax + 0x68]
// 00a5d8d6  83c404               add esp, 4
// 00a5d8d9  8bce                 mov ecx, esi
// 00a5d8db  5e                   pop esi
// 00a5d8dc  ffe2                 jmp edx
// library xtp-15.2.1-shared-mfc/Source\PropertyGrid\XTPPropertyGridInplaceList.cpp (function ?DestroyItem@CXTPPropertyGridInplaceList@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/PropertyGrid/XTPPropertyGridInplaceList.cpp
