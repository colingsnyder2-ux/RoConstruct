// from server: 100% by auto
// roc 2007-03 005c5a00  unit: seg_005c0000  size: 279 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c5a00
//
// 005c5a00  81ec18010000         sub esp, 0x118
// 005c5a06  53                   push ebx
// 005c5a07  55                   push ebp
// 005c5a08  56                   push esi
// 005c5a09  8bb42428010000       mov esi, dword ptr [esp + 0x128]
// 005c5a10  57                   push edi
// 005c5a11  8d442414             lea eax, [esp + 0x14]
// 005c5a15  50                   push eax
// 005c5a16  68edd8ffff           push 0xffffd8ed
// 005c5a1b  56                   push esi
// 005c5a1c  e82f34ffff           call 0x5b8e50
// 005c5a21  6a00                 push 0
// 005c5a23  68ecd8ffff           push 0xffffd8ec
// 005c5a28  56                   push esi
// 005c5a29  8bf8                 mov edi, eax
// 005c5a2b  e82034ffff           call 0x5b8e50
// 005c5a30  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 005c5a34  03cf                 add ecx, edi
// 005c5a36  68ebd8ffff           push 0xffffd8eb
// 005c5a3b  56                   push esi
// 005c5a3c  89442430             mov dword ptr [esp + 0x30], eax
// 005c5a40  89742440             mov dword ptr [esp + 0x40], esi
// 005c5a44  897c2438             mov dword ptr [esp + 0x38], edi
// 005c5a48  894c243c             mov dword ptr [esp + 0x3c], ecx
// 005c5a4c  e88f33ffff           call 0x5b8de0
// 005c5a51  8bd8                 mov ebx, eax
// 005c5a53  03df                 add ebx, edi
// 005c5a55  83c420               add esp, 0x20
// 005c5a58  3b5c241c             cmp ebx, dword ptr [esp + 0x1c]
// 005c5a5c  772c                 ja 0x5c5a8a
// 005c5a5e  8bff                 mov edi, edi
// 005c5a60  8b542410             mov edx, dword ptr [esp + 0x10]
// 005c5a64  52                   push edx
// 005c5a65  8d44241c             lea eax, [esp + 0x1c]
// 005c5a69  53                   push ebx
// 005c5a6a  50                   push eax
// 005c5a6b  c744243000000000     mov dword ptr [esp + 0x30], 0
// 005c5a73  e8f8f8ffff           call 0x5c5370
// 005c5a78  8be8                 mov ebp, eax
// 005c5a7a  83c40c               add esp, 0xc
// 005c5a7d  85ed                 test ebp, ebp
// 005c5a7f  7516                 jne 0x5c5a97
// 005c5a81  83c301               add ebx, 1
// 005c5a84  3b5c241c             cmp ebx, dword ptr [esp + 0x1c]
// 005c5a88  76d6                 jbe 0x5c5a60
// 005c5a8a  5f                   pop edi
// 005c5a8b  5e                   pop esi
// 005c5a8c  5d                   pop ebp
// 005c5a8d  33c0                 xor eax, eax
// 005c5a8f  5b                   pop ebx
// 005c5a90  81c418010000         add esp, 0x118
// 005c5a96  c3                   ret 
// 005c5a97  8bc5                 mov eax, ebp
// 005c5a99  2bc7                 sub eax, edi
// 005c5a9b  3beb                 cmp ebp, ebx
// 005c5a9d  7503                 jne 0x5c5aa2
// 005c5a9f  83c001               add eax, 1
// 005c5aa2  50                   push eax
// 005c5aa3  56                   push esi
// 005c5aa4  e8b735ffff           call 0x5b9060
// 005c5aa9  68ebd8ffff           push 0xffffd8eb
// 005c5aae  56                   push esi
// 005c5aaf  e89c30ffff           call 0x5b8b50
// 005c5ab4  8b442434             mov eax, dword ptr [esp + 0x34]
// 005c5ab8  83c410               add esp, 0x10
// 005c5abb  85c0                 test eax, eax
// 005c5abd  750f                 jne 0x5c5ace
// 005c5abf  85db                 test ebx, ebx
// 005c5ac1  740b                 je 0x5c5ace
// 005c5ac3  be01000000           mov esi, 1
// 005c5ac8  89742410             mov dword ptr [esp + 0x10], esi
// 005c5acc  eb06                 jmp 0x5c5ad4
// 005c5ace  89442410             mov dword ptr [esp + 0x10], eax
// 005c5ad2  8bf0                 mov esi, eax
// 005c5ad4  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 005c5ad8  68f09f7b00           push 0x7b9ff0
// 005c5add  56                   push esi
// 005c5ade  51                   push ecx
// 005c5adf  e8fc40ffff           call 0x5b9be0
// 005c5ae4  83c40c               add esp, 0xc
// 005c5ae7  33ff                 xor edi, edi
// 005c5ae9  85f6                 test esi, esi
// 005c5aeb  7e1d                 jle 0x5c5b0a
// 005c5aed  8d4900               lea ecx, [ecx]
// 005c5af0  8bc5                 mov eax, ebp
// 005c5af2  8bcb                 mov ecx, ebx
// 005c5af4  8d742418             lea esi, [esp + 0x18]
// 005c5af8  e843fcffff           call 0x5c5740
// 005c5afd  83c701               add edi, 1
// 005c5b00  3b7c2410             cmp edi, dword ptr [esp + 0x10]
// 005c5b04  7cea                 jl 0x5c5af0
// 005c5b06  8b742410             mov esi, dword ptr [esp + 0x10]
// 005c5b0a  5f                   pop edi
// 005c5b0b  8bc6                 mov eax, esi
// 005c5b0d  5e                   pop esi
// 005c5b0e  5d                   pop ebp
// 005c5b0f  5b                   pop ebx
// 005c5b10  81c418010000         add esp, 0x118
// 005c5b16  c3                   ret 
// library lua-5.1.1/lstrlib.c (function _gmatch_aux)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lstrlib.c
