// from server: 100% by colin
// roc 2007-08 004bc460  unit: RakPeer  size: 315 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004bc460
//
// 004bc460  81eca0000000         sub esp, 0xa0
// 004bc466  53                   push ebx
// 004bc467  55                   push ebp
// 004bc468  33c0                 xor eax, eax
// 004bc46a  56                   push esi
// 004bc46b  8bb424b0000000       mov esi, dword ptr [esp + 0xb0]
// 004bc472  57                   push edi
// 004bc473  b908000000           mov ecx, 8
// 004bc478  8d7c2410             lea edi, [esp + 0x10]
// 004bc47c  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 004bc47e  89442430             mov dword ptr [esp + 0x30], eax
// 004bc482  89442434             mov dword ptr [esp + 0x34], eax
// 004bc486  89442438             mov dword ptr [esp + 0x38], eax
// 004bc48a  8944243c             mov dword ptr [esp + 0x3c], eax
// 004bc48e  89442440             mov dword ptr [esp + 0x40], eax
// 004bc492  89442444             mov dword ptr [esp + 0x44], eax
// 004bc496  89442448             mov dword ptr [esp + 0x48], eax
// 004bc49a  8944244c             mov dword ptr [esp + 0x4c], eax
// 004bc49e  8b8424b8000000       mov eax, dword ptr [esp + 0xb8]
// 004bc4a5  50                   push eax
// 004bc4a6  8d4c2414             lea ecx, [esp + 0x14]
// 004bc4aa  51                   push ecx
// 004bc4ab  e8a0daffff           call 0x4b9f50
// 004bc4b0  8bb424c8000000       mov esi, dword ptr [esp + 0xc8]
// 004bc4b7  33c0                 xor eax, eax
// 004bc4b9  b908000000           mov ecx, 8
// 004bc4be  8d7c2458             lea edi, [esp + 0x58]
// 004bc4c2  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 004bc4c4  8d542418             lea edx, [esp + 0x18]
// 004bc4c8  89442478             mov dword ptr [esp + 0x78], eax
// 004bc4cc  8944247c             mov dword ptr [esp + 0x7c], eax
// 004bc4d0  89842480000000       mov dword ptr [esp + 0x80], eax
// 004bc4d7  89842484000000       mov dword ptr [esp + 0x84], eax
// 004bc4de  89842488000000       mov dword ptr [esp + 0x88], eax
// 004bc4e5  8984248c000000       mov dword ptr [esp + 0x8c], eax
// 004bc4ec  89842490000000       mov dword ptr [esp + 0x90], eax
// 004bc4f3  89842494000000       mov dword ptr [esp + 0x94], eax
// 004bc4fa  52                   push edx
// 004bc4fb  8d44245c             lea eax, [esp + 0x5c]
// 004bc4ff  50                   push eax
// 004bc500  8bca                 mov ecx, edx
// 004bc502  51                   push ecx
// 004bc503  e848ecffff           call 0x4bb150
// 004bc508  8b9c24d0000000       mov ebx, dword ptr [esp + 0xd0]
// 004bc50f  8bac24d8000000       mov ebp, dword ptr [esp + 0xd8]
// 004bc516  b908000000           mov ecx, 8
// 004bc51b  8d742424             lea esi, [esp + 0x24]
// 004bc51f  8dbc24a4000000       lea edi, [esp + 0xa4]
// 004bc526  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 004bc528  b908000000           mov ecx, 8
// 004bc52d  8bf3                 mov esi, ebx
// 004bc52f  8bfd                 mov edi, ebp
// 004bc531  83c414               add esp, 0x14
// 004bc534  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 004bc536  b807000000           mov eax, 7
// 004bc53b  eb03                 jmp 0x4bc540
// 004bc53d  8d4900               lea ecx, [ecx]
// 004bc540  8b0c83               mov ecx, dword ptr [ebx + eax*4]
// 004bc543  8b948490000000       mov edx, dword ptr [esp + eax*4 + 0x90]
// 004bc54a  3bca                 cmp ecx, edx
// 004bc54c  7731                 ja 0x4bc57f
// 004bc54e  7205                 jb 0x4bc555
// 004bc550  83e801               sub eax, 1
// 004bc553  79eb                 jns 0x4bc540
// 004bc555  8d842490000000       lea eax, [esp + 0x90]
// 004bc55c  50                   push eax
// 004bc55d  55                   push ebp
// 004bc55e  e85dd5ffff           call 0x4b9ac0
// 004bc563  8b8c24c8000000       mov ecx, dword ptr [esp + 0xc8]
// 004bc56a  51                   push ecx
// 004bc56b  55                   push ebp
// 004bc56c  e8cfd3ffff           call 0x4b9940
// 004bc571  83c410               add esp, 0x10
// 004bc574  5f                   pop edi
// 004bc575  5e                   pop esi
// 004bc576  5d                   pop ebp
// 004bc577  5b                   pop ebx
// 004bc578  81c4a0000000         add esp, 0xa0
// 004bc57e  c3                   ret 
// 004bc57f  8d942490000000       lea edx, [esp + 0x90]
// 004bc586  52                   push edx
// 004bc587  55                   push ebp
// 004bc588  e833d5ffff           call 0x4b9ac0
// 004bc58d  83c408               add esp, 8
// 004bc590  5f                   pop edi
// 004bc591  5e                   pop esi
// 004bc592  5d                   pop ebp
// 004bc593  5b                   pop ebx
// 004bc594  81c4a0000000         add esp, 0xa0
// 004bc59a  c3                   ret 
// copied from an identical function in another client (function ??$SubMulMod@$$BY07I@big@@YAXAAY07I0000@Z)

// from server: 100% by tester
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lang: cpp
// roc-lib: openrbx-raknet RakPeer.cpp