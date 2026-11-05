// from server: 100% by auto
// roc 2010-06 00803000  unit: CXTPPropertyGrid  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00803000
//
// 00803000  56                   push esi
// 00803001  57                   push edi
// 00803002  8bf1                 mov esi, ecx
// 00803004  e847ffffff           call 0x802f50
// 00803009  8b06                 mov eax, dword ptr [esi]
// 0080300b  8b9060010000         mov edx, dword ptr [eax + 0x160]
// 00803011  6a00                 push 0
// 00803013  8bce                 mov ecx, esi
// 00803015  ffd2                 call edx
// 00803017  8b3e                 mov edi, dword ptr [esi]
// 00803019  8bce                 mov ecx, esi
// 0080301b  e8e69f1700           call 0x97d006
// 00803020  50                   push eax
// 00803021  8b8754010000         mov eax, dword ptr [edi + 0x154]
// 00803027  6a01                 push 1
// 00803029  8bce                 mov ecx, esi
// 0080302b  ffd0                 call eax
// 0080302d  5f                   pop edi
// 0080302e  5e                   pop esi
// 0080302f  c3                   ret 
// library xtp-13.2.1-shared-mfc/Source\PropertyGrid\XTPPropertyGrid.cpp (function ?OnSortChanged@CXTPPropertyGrid@@MAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/PropertyGrid/XTPPropertyGrid.cpp
