// from server: 100% by auto
// roc 2007-08 00698d50  unit: CXTPPropertyGridItem  size: 80 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00698d50
//
// 00698d50  56                   push esi
// 00698d51  57                   push edi
// 00698d52  8bf9                 mov edi, ecx
// 00698d54  8b07                 mov eax, dword ptr [edi]
// 00698d56  8b9084000000         mov edx, dword ptr [eax + 0x84]
// 00698d5c  ffd2                 call edx
// 00698d5e  8bf0                 mov esi, eax
// 00698d60  85f6                 test esi, esi
// 00698d62  7439                 je 0x698d9d
// 00698d64  837e2000             cmp dword ptr [esi + 0x20], 0
// 00698d68  7433                 je 0x698d9d
// 00698d6a  39bea0000000         cmp dword ptr [esi + 0xa0], edi
// 00698d70  752b                 jne 0x698d9d
// 00698d72  8bce                 mov ecx, esi
// 00698d74  e88b72f9ff           call 0x630004
// 00698d79  8b4620               mov eax, dword ptr [esi + 0x20]
// 00698d7c  8b3dd8ec7700         mov edi, dword ptr [0x77ecd8]
// 00698d82  6aff                 push -1
// 00698d84  6a00                 push 0
// 00698d86  68b1000000           push 0xb1
// 00698d8b  50                   push eax
// 00698d8c  ffd7                 call edi
// 00698d8e  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 00698d91  6a00                 push 0
// 00698d93  6a00                 push 0
// 00698d95  68b7000000           push 0xb7
// 00698d9a  51                   push ecx
// 00698d9b  ffd7                 call edi
// 00698d9d  5f                   pop edi
// 00698d9e  5e                   pop esi
// 00698d9f  c3                   ret 
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGridItem.cpp (function ?SetFocusToInplaceControl@CXTPPropertyGridItem@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGridItem.cpp
