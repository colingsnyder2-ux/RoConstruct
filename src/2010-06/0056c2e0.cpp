// from server: 100% by auto
// roc 2010-06 0056c2e0  unit: seg_00560000  size: 296 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0056c2e0
//
// 0056c2e0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0056c2e4  53                   push ebx
// 0056c2e5  55                   push ebp
// 0056c2e6  56                   push esi
// 0056c2e7  57                   push edi
// 0056c2e8  85c9                 test ecx, ecx
// 0056c2ea  0f8411010000         je 0x56c401
// 0056c2f0  8b742418             mov esi, dword ptr [esp + 0x18]
// 0056c2f4  85f6                 test esi, esi
// 0056c2f6  0f8405010000         je 0x56c401
// 0056c2fc  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 0056c300  85db                 test ebx, ebx
// 0056c302  0f84f9000000         je 0x56c401
// 0056c308  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 0056c30c  85ed                 test ebp, ebp
// 0056c30e  0f84ed000000         je 0x56c401
// 0056c314  8b442424             mov eax, dword ptr [esp + 0x24]
// 0056c318  85c0                 test eax, eax
// 0056c31a  0f84e1000000         je 0x56c401
// 0056c320  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 0056c324  85ff                 test edi, edi
// 0056c326  0f84d5000000         je 0x56c401
// 0056c32c  8b16                 mov edx, dword ptr [esi]
// 0056c32e  8913                 mov dword ptr [ebx], edx
// 0056c330  8b5604               mov edx, dword ptr [esi + 4]
// 0056c333  895500               mov dword ptr [ebp], edx
// 0056c336  0fb65618             movzx edx, byte ptr [esi + 0x18]
// 0056c33a  8910                 mov dword ptr [eax], edx
// 0056c33c  807e1801             cmp byte ptr [esi + 0x18], 1
// 0056c340  7206                 jb 0x56c348
// 0056c342  807e1810             cmp byte ptr [esi + 0x18], 0x10
// 0056c346  7612                 jbe 0x56c35a
// 0056c348  688030a200           push 0xa23080
// 0056c34d  51                   push ecx
// 0056c34e  e85d570000           call 0x571ab0
// 0056c353  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0056c357  83c408               add esp, 8
// 0056c35a  0fb64619             movzx eax, byte ptr [esi + 0x19]
// 0056c35e  8907                 mov dword ptr [edi], eax
// 0056c360  807e1906             cmp byte ptr [esi + 0x19], 6
// 0056c364  7612                 jbe 0x56c378
// 0056c366  686c30a200           push 0xa2306c
// 0056c36b  51                   push ecx
// 0056c36c  e83f570000           call 0x571ab0
// 0056c371  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0056c375  83c408               add esp, 8
// 0056c378  8b442430             mov eax, dword ptr [esp + 0x30]
// 0056c37c  85c0                 test eax, eax
// 0056c37e  7406                 je 0x56c386
// 0056c380  0fb6561a             movzx edx, byte ptr [esi + 0x1a]
// 0056c384  8910                 mov dword ptr [eax], edx
// 0056c386  8b442434             mov eax, dword ptr [esp + 0x34]
// 0056c38a  85c0                 test eax, eax
// 0056c38c  7406                 je 0x56c394
// 0056c38e  0fb6561b             movzx edx, byte ptr [esi + 0x1b]
// 0056c392  8910                 mov dword ptr [eax], edx
// 0056c394  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0056c398  85c0                 test eax, eax
// 0056c39a  7406                 je 0x56c3a2
// 0056c39c  0fb6561c             movzx edx, byte ptr [esi + 0x1c]
// 0056c3a0  8910                 mov dword ptr [eax], edx
// 0056c3a2  8b03                 mov eax, dword ptr [ebx]
// 0056c3a4  85c0                 test eax, eax
// 0056c3a6  7407                 je 0x56c3af
// 0056c3a8  3dffffff7f           cmp eax, 0x7fffffff
// 0056c3ad  7612                 jbe 0x56c3c1
// 0056c3af  685830a200           push 0xa23058
// 0056c3b4  51                   push ecx
// 0056c3b5  e8f6560000           call 0x571ab0
// 0056c3ba  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0056c3be  83c408               add esp, 8
// 0056c3c1  8b4500               mov eax, dword ptr [ebp]
// 0056c3c4  85c0                 test eax, eax
// 0056c3c6  7407                 je 0x56c3cf
// 0056c3c8  3dffffff7f           cmp eax, 0x7fffffff
// 0056c3cd  7612                 jbe 0x56c3e1
// 0056c3cf  684030a200           push 0xa23040
// 0056c3d4  51                   push ecx
// 0056c3d5  e8d6560000           call 0x571ab0
// 0056c3da  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0056c3de  83c408               add esp, 8
// 0056c3e1  813e7effff1f         cmp dword ptr [esi], 0x1fffff7e
// 0056c3e7  760e                 jbe 0x56c3f7
// 0056c3e9  680c30a200           push 0xa2300c
// 0056c3ee  51                   push ecx
// 0056c3ef  e86c570000           call 0x571b60
// 0056c3f4  83c408               add esp, 8
// 0056c3f7  5f                   pop edi
// 0056c3f8  5e                   pop esi
// 0056c3f9  5d                   pop ebp
// 0056c3fa  b801000000           mov eax, 1
// 0056c3ff  5b                   pop ebx
// 0056c400  c3                   ret 
// 0056c401  5f                   pop edi
// 0056c402  5e                   pop esi
// 0056c403  5d                   pop ebp
// 0056c404  33c0                 xor eax, eax
// 0056c406  5b                   pop ebx
// 0056c407  c3                   ret 
// library libpng-1.2.8/pngget.c (function _png_get_IHDR)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.8 pngget.c
