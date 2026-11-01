// from server: 100% by auto
// roc 2009-12 00865970  unit: CXTPPropertyGridItem  size: 80 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00865970
//
// 00865970  56                   push esi
// 00865971  57                   push edi
// 00865972  8bf9                 mov edi, ecx
// 00865974  8b07                 mov eax, dword ptr [edi]
// 00865976  8b9084000000         mov edx, dword ptr [eax + 0x84]
// 0086597c  ffd2                 call edx
// 0086597e  8bf0                 mov esi, eax
// 00865980  85f6                 test esi, esi
// 00865982  7439                 je 0x8659bd
// 00865984  837e2000             cmp dword ptr [esi + 0x20], 0
// 00865988  7433                 je 0x8659bd
// 0086598a  39bea0000000         cmp dword ptr [esi + 0xa0], edi
// 00865990  752b                 jne 0x8659bd
// 00865992  8bce                 mov ecx, esi
// 00865994  e869e2f8ff           call 0x7f3c02
// 00865999  8b4620               mov eax, dword ptr [esi + 0x20]
// 0086599c  8b3dc4cb9800         mov edi, dword ptr [0x98cbc4]
// 008659a2  6aff                 push -1
// 008659a4  6a00                 push 0
// 008659a6  68b1000000           push 0xb1
// 008659ab  50                   push eax
// 008659ac  ffd7                 call edi
// 008659ae  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 008659b1  6a00                 push 0
// 008659b3  6a00                 push 0
// 008659b5  68b7000000           push 0xb7
// 008659ba  51                   push ecx
// 008659bb  ffd7                 call edi
// 008659bd  5f                   pop edi
// 008659be  5e                   pop esi
// 008659bf  c3                   ret 
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGridItem.cpp (function ?SetFocusToInplaceControl@CXTPPropertyGridItem@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGridItem.cpp
