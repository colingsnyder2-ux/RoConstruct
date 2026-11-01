// from server: 100% by auto
// roc 2011-06 0086a6b0  unit: CXTPPropertyGrid  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0086a6b0
//
// 0086a6b0  56                   push esi
// 0086a6b1  57                   push edi
// 0086a6b2  8bf1                 mov esi, ecx
// 0086a6b4  e847ffffff           call 0x86a600
// 0086a6b9  8b06                 mov eax, dword ptr [esi]
// 0086a6bb  8b9060010000         mov edx, dword ptr [eax + 0x160]
// 0086a6c1  6a00                 push 0
// 0086a6c3  8bce                 mov ecx, esi
// 0086a6c5  ffd2                 call edx
// 0086a6c7  8b3e                 mov edi, dword ptr [esi]
// 0086a6c9  8bce                 mov ecx, esi
// 0086a6cb  e846211600           call 0x9cc816
// 0086a6d0  50                   push eax
// 0086a6d1  8b8754010000         mov eax, dword ptr [edi + 0x154]
// 0086a6d7  6a01                 push 1
// 0086a6d9  8bce                 mov ecx, esi
// 0086a6db  ffd0                 call eax
// 0086a6dd  5f                   pop edi
// 0086a6de  5e                   pop esi
// 0086a6df  c3                   ret 
// library xtp-15.2.1-shared-mfc/Source\PropertyGrid\XTPPropertyGrid.cpp (function ?OnSortChanged@CXTPPropertyGrid@@MAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/PropertyGrid/XTPPropertyGrid.cpp
