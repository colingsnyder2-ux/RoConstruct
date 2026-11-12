// from server: 100% by auto
// roc 2008-06 004bf2c0  unit: ProfiledRakPeer  size: 315 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004bf2c0
//
// 004bf2c0  81eca0000000         sub esp, 0xa0
// 004bf2c6  53                   push ebx
// 004bf2c7  55                   push ebp
// 004bf2c8  33c0                 xor eax, eax
// 004bf2ca  56                   push esi
// 004bf2cb  8bb424b0000000       mov esi, dword ptr [esp + 0xb0]
// 004bf2d2  57                   push edi
// 004bf2d3  b908000000           mov ecx, 8
// 004bf2d8  8d7c2410             lea edi, [esp + 0x10]
// 004bf2dc  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 004bf2de  89442430             mov dword ptr [esp + 0x30], eax
// 004bf2e2  89442434             mov dword ptr [esp + 0x34], eax
// 004bf2e6  89442438             mov dword ptr [esp + 0x38], eax
// 004bf2ea  8944243c             mov dword ptr [esp + 0x3c], eax
// 004bf2ee  89442440             mov dword ptr [esp + 0x40], eax
// 004bf2f2  89442444             mov dword ptr [esp + 0x44], eax
// 004bf2f6  89442448             mov dword ptr [esp + 0x48], eax
// 004bf2fa  8944244c             mov dword ptr [esp + 0x4c], eax
// 004bf2fe  8b8424b8000000       mov eax, dword ptr [esp + 0xb8]
// 004bf305  50                   push eax
// 004bf306  8d4c2414             lea ecx, [esp + 0x14]
// 004bf30a  51                   push ecx
// 004bf30b  e880daffff           call 0x4bcd90
// 004bf310  8bb424c8000000       mov esi, dword ptr [esp + 0xc8]
// 004bf317  33c0                 xor eax, eax
// 004bf319  b908000000           mov ecx, 8
// 004bf31e  8d7c2458             lea edi, [esp + 0x58]
// 004bf322  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 004bf324  8d542418             lea edx, [esp + 0x18]
// 004bf328  89442478             mov dword ptr [esp + 0x78], eax
// 004bf32c  8944247c             mov dword ptr [esp + 0x7c], eax
// 004bf330  89842480000000       mov dword ptr [esp + 0x80], eax
// 004bf337  89842484000000       mov dword ptr [esp + 0x84], eax
// 004bf33e  89842488000000       mov dword ptr [esp + 0x88], eax
// 004bf345  8984248c000000       mov dword ptr [esp + 0x8c], eax
// 004bf34c  89842490000000       mov dword ptr [esp + 0x90], eax
// 004bf353  89842494000000       mov dword ptr [esp + 0x94], eax
// 004bf35a  52                   push edx
// 004bf35b  8d44245c             lea eax, [esp + 0x5c]
// 004bf35f  50                   push eax
// 004bf360  8bca                 mov ecx, edx
// 004bf362  51                   push ecx
// 004bf363  e818ecffff           call 0x4bdf80
// 004bf368  8b9c24d0000000       mov ebx, dword ptr [esp + 0xd0]
// 004bf36f  8bac24d8000000       mov ebp, dword ptr [esp + 0xd8]
// 004bf376  b908000000           mov ecx, 8
// 004bf37b  8d742424             lea esi, [esp + 0x24]
// 004bf37f  8dbc24a4000000       lea edi, [esp + 0xa4]
// 004bf386  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 004bf388  b908000000           mov ecx, 8
// 004bf38d  8bf3                 mov esi, ebx
// 004bf38f  8bfd                 mov edi, ebp
// 004bf391  83c414               add esp, 0x14
// 004bf394  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 004bf396  b807000000           mov eax, 7
// 004bf39b  eb03                 jmp 0x4bf3a0
// 004bf39d  8d4900               lea ecx, [ecx]
// 004bf3a0  8b0c83               mov ecx, dword ptr [ebx + eax*4]
// 004bf3a3  8b948490000000       mov edx, dword ptr [esp + eax*4 + 0x90]
// 004bf3aa  3bca                 cmp ecx, edx
// 004bf3ac  7731                 ja 0x4bf3df
// 004bf3ae  7205                 jb 0x4bf3b5
// 004bf3b0  83e801               sub eax, 1
// 004bf3b3  79eb                 jns 0x4bf3a0
// 004bf3b5  8d842490000000       lea eax, [esp + 0x90]
// 004bf3bc  50                   push eax
// 004bf3bd  55                   push ebp
// 004bf3be  e83dd5ffff           call 0x4bc900
// 004bf3c3  8b8c24c8000000       mov ecx, dword ptr [esp + 0xc8]
// 004bf3ca  51                   push ecx
// 004bf3cb  55                   push ebp
// 004bf3cc  e8afd3ffff           call 0x4bc780
// 004bf3d1  83c410               add esp, 0x10
// 004bf3d4  5f                   pop edi
// 004bf3d5  5e                   pop esi
// 004bf3d6  5d                   pop ebp
// 004bf3d7  5b                   pop ebx
// 004bf3d8  81c4a0000000         add esp, 0xa0
// 004bf3de  c3                   ret 
// 004bf3df  8d942490000000       lea edx, [esp + 0x90]
// 004bf3e6  52                   push edx
// 004bf3e7  55                   push ebp
// 004bf3e8  e813d5ffff           call 0x4bc900
// 004bf3ed  83c408               add esp, 8
// 004bf3f0  5f                   pop edi
// 004bf3f1  5e                   pop esi
// 004bf3f2  5d                   pop ebp
// 004bf3f3  5b                   pop ebx
// 004bf3f4  81c4a0000000         add esp, 0xa0
// 004bf3fa  c3                   ret 
// library openrbx-raknet/RakPeer.cpp (function ??$SubMulMod@$$BY07I@big@@YAXAAY07I0000@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
