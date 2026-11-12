// from server: 100% by auto
// roc 2008-06 004a98b0  unit: seg_004a0000  size: 107 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004a98b0
//
// 004a98b0  56                   push esi
// 004a98b1  8bf1                 mov esi, ecx
// 004a98b3  8b06                 mov eax, dword ptr [esi]
// 004a98b5  50                   push eax
// 004a98b6  ff15b82e8000         call dword ptr [0x802eb8]
// 004a98bc  ba0c109700           mov edx, 0x97100c
// 004a98c1  8a08                 mov cl, byte ptr [eax]
// 004a98c3  880a                 mov byte ptr [edx], cl
// 004a98c5  40                   inc eax
// 004a98c6  42                   inc edx
// 004a98c7  84c9                 test cl, cl
// 004a98c9  75f6                 jne 0x4a98c1
// 004a98cb  384c2408             cmp byte ptr [esp + 8], cl
// 004a98cf  7441                 je 0x4a9912
// 004a98d1  57                   push edi
// 004a98d2  bf0c109700           mov edi, 0x97100c
// 004a98d7  4f                   dec edi
// 004a98d8  8a4701               mov al, byte ptr [edi + 1]
// 004a98db  47                   inc edi
// 004a98dc  84c0                 test al, al
// 004a98de  75f8                 jne 0x4a98d8
// 004a98e0  66a148138200         mov ax, word ptr [0x821348]
// 004a98e6  668907               mov word ptr [edi], ax
// 004a98e9  b80c109700           mov eax, 0x97100c
// 004a98ee  8d5001               lea edx, [eax + 1]
// 004a98f1  5f                   pop edi
// 004a98f2  8a08                 mov cl, byte ptr [eax]
// 004a98f4  40                   inc eax
// 004a98f5  84c9                 test cl, cl
// 004a98f7  75f9                 jne 0x4a98f2
// 004a98f9  2bc2                 sub eax, edx
// 004a98fb  0fb75604             movzx edx, word ptr [esi + 4]
// 004a98ff  6a0a                 push 0xa
// 004a9901  8d880c109700         lea ecx, [eax + 0x97100c]
// 004a9907  51                   push ecx
// 004a9908  52                   push edx
// 004a9909  ff15d8278000         call dword ptr [0x8027d8]
// 004a990f  83c40c               add esp, 0xc
// 004a9912  b80c109700           mov eax, 0x97100c
// 004a9917  5e                   pop esi
// 004a9918  c20400               ret 4
// library openrbx-raknet/RakNetTypes.cpp (function ?ToString@SystemAddress@@QBEPAD_N@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakNetTypes.cpp
