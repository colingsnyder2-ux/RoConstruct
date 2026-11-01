// from server: 100% by auto
// roc 2009-06 0078a960  unit: CXTPPropertyGridItem  size: 80 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0078a960
//
// 0078a960  56                   push esi
// 0078a961  57                   push edi
// 0078a962  8bf9                 mov edi, ecx
// 0078a964  8b07                 mov eax, dword ptr [edi]
// 0078a966  8b9084000000         mov edx, dword ptr [eax + 0x84]
// 0078a96c  ffd2                 call edx
// 0078a96e  8bf0                 mov esi, eax
// 0078a970  85f6                 test esi, esi
// 0078a972  7439                 je 0x78a9ad
// 0078a974  837e2000             cmp dword ptr [esi + 0x20], 0
// 0078a978  7433                 je 0x78a9ad
// 0078a97a  39bea0000000         cmp dword ptr [esi + 0xa0], edi
// 0078a980  752b                 jne 0x78a9ad
// 0078a982  8bce                 mov ecx, esi
// 0078a984  e851e4f8ff           call 0x718dda
// 0078a989  8b4620               mov eax, dword ptr [esi + 0x20]
// 0078a98c  8b3d90ee8900         mov edi, dword ptr [0x89ee90]
// 0078a992  6aff                 push -1
// 0078a994  6a00                 push 0
// 0078a996  68b1000000           push 0xb1
// 0078a99b  50                   push eax
// 0078a99c  ffd7                 call edi
// 0078a99e  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 0078a9a1  6a00                 push 0
// 0078a9a3  6a00                 push 0
// 0078a9a5  68b7000000           push 0xb7
// 0078a9aa  51                   push ecx
// 0078a9ab  ffd7                 call edi
// 0078a9ad  5f                   pop edi
// 0078a9ae  5e                   pop esi
// 0078a9af  c3                   ret 
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGridItem.cpp (function ?SetFocusToInplaceControl@CXTPPropertyGridItem@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGridItem.cpp
