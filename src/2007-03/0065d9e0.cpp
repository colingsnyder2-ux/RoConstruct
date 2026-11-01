// from server: 100% by auto
// roc 2007-03 0065d9e0  unit: seg_00650000  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0065d9e0
//
// 0065d9e0  56                   push esi
// 0065d9e1  57                   push edi
// 0065d9e2  8bf1                 mov esi, ecx
// 0065d9e4  e847ffffff           call 0x65d930
// 0065d9e9  8b06                 mov eax, dword ptr [esi]
// 0065d9eb  8b9058010000         mov edx, dword ptr [eax + 0x158]
// 0065d9f1  6a00                 push 0
// 0065d9f3  8bce                 mov ecx, esi
// 0065d9f5  ffd2                 call edx
// 0065d9f7  8b3e                 mov edi, dword ptr [esi]
// 0065d9f9  8bce                 mov ecx, esi
// 0065d9fb  e802d30d00           call 0x73ad02
// 0065da00  50                   push eax
// 0065da01  8b874c010000         mov eax, dword ptr [edi + 0x14c]
// 0065da07  6a01                 push 1
// 0065da09  8bce                 mov ecx, esi
// 0065da0b  ffd0                 call eax
// 0065da0d  5f                   pop edi
// 0065da0e  5e                   pop esi
// 0065da0f  c3                   ret 
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGrid.cpp (function ?OnSortChanged@CXTPPropertyGrid@@MAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGrid.cpp
