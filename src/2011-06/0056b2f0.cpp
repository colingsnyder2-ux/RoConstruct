// from server: 100% by auto
// roc 2011-06 0056b2f0  unit: seg_00560000  size: 302 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0056b2f0
//
// 0056b2f0  83ec24               sub esp, 0x24
// 0056b2f3  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 0056b2f7  55                   push ebp
// 0056b2f8  56                   push esi
// 0056b2f9  8b742430             mov esi, dword ptr [esp + 0x30]
// 0056b2fd  57                   push edi
// 0056b2fe  8d442410             lea eax, [esp + 0x10]
// 0056b302  50                   push eax
// 0056b303  33ff                 xor edi, edi
// 0056b305  51                   push ecx
// 0056b306  56                   push esi
// 0056b307  c64424207a           mov byte ptr [esp + 0x20], 0x7a
// 0056b30c  c644242154           mov byte ptr [esp + 0x21], 0x54
// 0056b311  c644242258           mov byte ptr [esp + 0x22], 0x58
// 0056b316  c644242374           mov byte ptr [esp + 0x23], 0x74
// 0056b31b  c644242400           mov byte ptr [esp + 0x24], 0
// 0056b320  897c2430             mov dword ptr [esp + 0x30], edi
// 0056b324  897c2434             mov dword ptr [esp + 0x34], edi
// 0056b328  897c2438             mov dword ptr [esp + 0x38], edi
// 0056b32c  897c2428             mov dword ptr [esp + 0x28], edi
// 0056b330  897c242c             mov dword ptr [esp + 0x2c], edi
// 0056b334  e8c7fcffff           call 0x56b000
// 0056b339  8be8                 mov ebp, eax
// 0056b33b  83c40c               add esp, 0xc
// 0056b33e  3bef                 cmp ebp, edi
// 0056b340  7515                 jne 0x56b357
// 0056b342  8b542410             mov edx, dword ptr [esp + 0x10]
// 0056b346  52                   push edx
// 0056b347  56                   push esi
// 0056b348  e85363ffff           call 0x5616a0
// 0056b34d  83c408               add esp, 8
// 0056b350  5f                   pop edi
// 0056b351  5e                   pop esi
// 0056b352  5d                   pop ebp
// 0056b353  83c424               add esp, 0x24
// 0056b356  c3                   ret 
// 0056b357  8b54243c             mov edx, dword ptr [esp + 0x3c]
// 0056b35b  53                   push ebx
// 0056b35c  3bd7                 cmp edx, edi
// 0056b35e  0f849b000000         je 0x56b3ff
// 0056b364  803a00               cmp byte ptr [edx], 0
// 0056b367  0f8492000000         je 0x56b3ff
// 0056b36d  8b5c2448             mov ebx, dword ptr [esp + 0x48]
// 0056b371  83fbff               cmp ebx, -1
// 0056b374  0f8485000000         je 0x56b3ff
// 0056b37a  8bc2                 mov eax, edx
// 0056b37c  8d7801               lea edi, [eax + 1]
// 0056b37f  90                   nop 
// 0056b380  8a08                 mov cl, byte ptr [eax]
// 0056b382  40                   inc eax
// 0056b383  84c9                 test cl, cl
// 0056b385  75f9                 jne 0x56b380
// 0056b387  2bc7                 sub eax, edi
// 0056b389  8bc8                 mov ecx, eax
// 0056b38b  52                   push edx
// 0056b38c  8d7c2424             lea edi, [esp + 0x24]
// 0056b390  8bc3                 mov eax, ebx
// 0056b392  8bd6                 mov edx, esi
// 0056b394  e807f7ffff           call 0x56aaa0
// 0056b399  8d442802             lea eax, [eax + ebp + 2]
// 0056b39d  50                   push eax
// 0056b39e  8d4c2420             lea ecx, [esp + 0x20]
// 0056b3a2  51                   push ecx
// 0056b3a3  56                   push esi
// 0056b3a4  e807f6ffff           call 0x56a9b0
// 0056b3a9  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 0056b3ad  45                   inc ebp
// 0056b3ae  55                   push ebp
// 0056b3af  57                   push edi
// 0056b3b0  56                   push esi
// 0056b3b1  e86af6ffff           call 0x56aa20
// 0056b3b6  57                   push edi
// 0056b3b7  56                   push esi
// 0056b3b8  e8e362ffff           call 0x5616a0
// 0056b3bd  83c424               add esp, 0x24
// 0056b3c0  885c2413             mov byte ptr [esp + 0x13], bl
// 0056b3c4  85f6                 test esi, esi
// 0056b3c6  741d                 je 0x56b3e5
// 0056b3c8  6a01                 push 1
// 0056b3ca  8d542417             lea edx, [esp + 0x17]
// 0056b3ce  52                   push edx
// 0056b3cf  56                   push esi
// 0056b3d0  e86bf4feff           call 0x55a840
// 0056b3d5  6a01                 push 1
// 0056b3d7  8d442423             lea eax, [esp + 0x23]
// 0056b3db  50                   push eax
// 0056b3dc  56                   push esi
// 0056b3dd  e86e54feff           call 0x550850
// 0056b3e2  83c418               add esp, 0x18
// 0056b3e5  8d442420             lea eax, [esp + 0x20]
// 0056b3e9  e832f9ffff           call 0x56ad20
// 0056b3ee  56                   push esi
// 0056b3ef  e86cf6ffff           call 0x56aa60
// 0056b3f4  83c404               add esp, 4
// 0056b3f7  5b                   pop ebx
// 0056b3f8  5f                   pop edi
// 0056b3f9  5e                   pop esi
// 0056b3fa  5d                   pop ebp
// 0056b3fb  83c424               add esp, 0x24
// 0056b3fe  c3                   ret 
// 0056b3ff  57                   push edi
// 0056b400  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 0056b404  52                   push edx
// 0056b405  57                   push edi
// 0056b406  56                   push esi
// 0056b407  e8d4fdffff           call 0x56b1e0
// 0056b40c  57                   push edi
// 0056b40d  56                   push esi
// 0056b40e  e88d62ffff           call 0x5616a0
// 0056b413  83c418               add esp, 0x18
// 0056b416  5b                   pop ebx
// 0056b417  5f                   pop edi
// 0056b418  5e                   pop esi
// 0056b419  5d                   pop ebp
// 0056b41a  83c424               add esp, 0x24
// 0056b41d  c3                   ret 
// library libpng-1.2.35/pngwutil.c (function _png_write_zTXt)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.35 pngwutil.c
