// from server: 100% by auto
// roc 2008-06 004a9a40  unit: seg_004a0000  size: 238 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004a9a40
//
// 004a9a40  56                   push esi
// 004a9a41  8b742408             mov esi, dword ptr [esp + 8]
// 004a9a45  85f6                 test esi, esi
// 004a9a47  0f84dd000000         je 0x4a9b2a
// 004a9a4d  803e00               cmp byte ptr [esi], 0
// 004a9a50  0f84d4000000         je 0x4a9b2a
// 004a9a56  8bc6                 mov eax, esi
// 004a9a58  8d5001               lea edx, [eax + 1]
// 004a9a5b  eb03                 jmp 0x4a9a60
// 004a9a5d  8d4900               lea ecx, [ecx]
// 004a9a60  8a08                 mov cl, byte ptr [eax]
// 004a9a62  40                   inc eax
// 004a9a63  84c9                 test cl, cl
// 004a9a65  75f9                 jne 0x4a9a60
// 004a9a67  2bc2                 sub eax, edx
// 004a9a69  40                   inc eax
// 004a9a6a  57                   push edi
// 004a9a6b  50                   push eax
// 004a9a6c  e8af6e1f00           call 0x6a0920
// 004a9a71  8bf8                 mov edi, eax
// 004a9a73  8bd7                 mov edx, edi
// 004a9a75  83c404               add esp, 4
// 004a9a78  8bc6                 mov eax, esi
// 004a9a7a  2bd6                 sub edx, esi
// 004a9a7c  8d642400             lea esp, [esp]
// 004a9a80  8a08                 mov cl, byte ptr [eax]
// 004a9a82  880c02               mov byte ptr [edx + eax], cl
// 004a9a85  40                   inc eax
// 004a9a86  84c9                 test cl, cl
// 004a9a88  75f6                 jne 0x4a9a80
// 004a9a8a  380f                 cmp byte ptr [edi], cl
// 004a9a8c  7422                 je 0x4a9ab0
// 004a9a8e  8bf7                 mov esi, edi
// 004a9a90  8a06                 mov al, byte ptr [esi]
// 004a9a92  3c2f                 cmp al, 0x2f
// 004a9a94  7404                 je 0x4a9a9a
// 004a9a96  3c5c                 cmp al, 0x5c
// 004a9a98  7510                 jne 0x4a9aaa
// 004a9a9a  57                   push edi
// 004a9a9b  c60600               mov byte ptr [esi], 0
// 004a9a9e  ff156c278000         call dword ptr [0x80276c]
// 004a9aa4  83c404               add esp, 4
// 004a9aa7  c6062f               mov byte ptr [esi], 0x2f
// 004a9aaa  46                   inc esi
// 004a9aab  803e00               cmp byte ptr [esi], 0
// 004a9aae  75e0                 jne 0x4a9a90
// 004a9ab0  53                   push ebx
// 004a9ab1  55                   push ebp
// 004a9ab2  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 004a9ab6  85ed                 test ebp, ebp
// 004a9ab8  7456                 je 0x4a9b10
// 004a9aba  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 004a9abe  85db                 test ebx, ebx
// 004a9ac0  744e                 je 0x4a9b10
// 004a9ac2  8b442414             mov eax, dword ptr [esp + 0x14]
// 004a9ac6  68b43e8200           push 0x823eb4
// 004a9acb  50                   push eax
// 004a9acc  ff1514288000         call dword ptr [0x802814]
// 004a9ad2  8bf0                 mov esi, eax
// 004a9ad4  83c408               add esp, 8
// 004a9ad7  85f6                 test esi, esi
// 004a9ad9  7510                 jne 0x4a9aeb
// 004a9adb  57                   push edi
// 004a9adc  e8996b1f00           call 0x6a067a
// 004a9ae1  83c404               add esp, 4
// 004a9ae4  5d                   pop ebp
// 004a9ae5  5b                   pop ebx
// 004a9ae6  5f                   pop edi
// 004a9ae7  32c0                 xor al, al
// 004a9ae9  5e                   pop esi
// 004a9aea  c3                   ret 
// 004a9aeb  56                   push esi
// 004a9aec  53                   push ebx
// 004a9aed  6a01                 push 1
// 004a9aef  55                   push ebp
// 004a9af0  ff15d0278000         call dword ptr [0x8027d0]
// 004a9af6  56                   push esi
// 004a9af7  ff15d4278000         call dword ptr [0x8027d4]
// 004a9afd  83c414               add esp, 0x14
// 004a9b00  57                   push edi
// 004a9b01  e8746b1f00           call 0x6a067a
// 004a9b06  83c404               add esp, 4
// 004a9b09  5d                   pop ebp
// 004a9b0a  5b                   pop ebx
// 004a9b0b  5f                   pop edi
// 004a9b0c  b001                 mov al, 1
// 004a9b0e  5e                   pop esi
// 004a9b0f  c3                   ret 
// 004a9b10  57                   push edi
// 004a9b11  ff156c278000         call dword ptr [0x80276c]
// 004a9b17  83c404               add esp, 4
// 004a9b1a  57                   push edi
// 004a9b1b  e85a6b1f00           call 0x6a067a
// 004a9b20  83c404               add esp, 4
// 004a9b23  5d                   pop ebp
// 004a9b24  5b                   pop ebx
// 004a9b25  5f                   pop edi
// 004a9b26  b001                 mov al, 1
// 004a9b28  5e                   pop esi
// 004a9b29  c3                   ret 
// 004a9b2a  32c0                 xor al, al
// 004a9b2c  5e                   pop esi
// 004a9b2d  c3                   ret 
// library openrbx-raknet/FileOperations.cpp (function ?WriteFileWithDirectories@@YA_NPBDPADI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet FileOperations.cpp
