// from server: 100% by auto
// roc 2007-03 005fc360  unit: seg_005f0000  size: 285 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005fc360
//
// 005fc360  83ec7c               sub esp, 0x7c
// 005fc363  53                   push ebx
// 005fc364  8bd8                 mov ebx, eax
// 005fc366  33c0                 xor eax, eax
// 005fc368  89442414             mov dword ptr [esp + 0x14], eax
// 005fc36c  89442418             mov dword ptr [esp + 0x18], eax
// 005fc370  8944241c             mov dword ptr [esp + 0x1c], eax
// 005fc374  89442420             mov dword ptr [esp + 0x20], eax
// 005fc378  89442424             mov dword ptr [esp + 0x24], eax
// 005fc37c  89442428             mov dword ptr [esp + 0x28], eax
// 005fc380  8944242c             mov dword ptr [esp + 0x2c], eax
// 005fc384  89442430             mov dword ptr [esp + 0x30], eax
// 005fc388  89442434             mov dword ptr [esp + 0x34], eax
// 005fc38c  89442438             mov dword ptr [esp + 0x38], eax
// 005fc390  8944243c             mov dword ptr [esp + 0x3c], eax
// 005fc394  89442440             mov dword ptr [esp + 0x40], eax
// 005fc398  89442444             mov dword ptr [esp + 0x44], eax
// 005fc39c  89442448             mov dword ptr [esp + 0x48], eax
// 005fc3a0  8944244c             mov dword ptr [esp + 0x4c], eax
// 005fc3a4  89442450             mov dword ptr [esp + 0x50], eax
// 005fc3a8  89442454             mov dword ptr [esp + 0x54], eax
// 005fc3ac  89442458             mov dword ptr [esp + 0x58], eax
// 005fc3b0  8944245c             mov dword ptr [esp + 0x5c], eax
// 005fc3b4  89442460             mov dword ptr [esp + 0x60], eax
// 005fc3b8  89442464             mov dword ptr [esp + 0x64], eax
// 005fc3bc  89442468             mov dword ptr [esp + 0x68], eax
// 005fc3c0  8944246c             mov dword ptr [esp + 0x6c], eax
// 005fc3c4  89442470             mov dword ptr [esp + 0x70], eax
// 005fc3c8  89442474             mov dword ptr [esp + 0x74], eax
// 005fc3cc  89442478             mov dword ptr [esp + 0x78], eax
// 005fc3d0  8944247c             mov dword ptr [esp + 0x7c], eax
// 005fc3d4  56                   push esi
// 005fc3d5  8d442418             lea eax, [esp + 0x18]
// 005fc3d9  50                   push eax
// 005fc3da  53                   push ebx
// 005fc3db  e8e0f6ffff           call 0x5fbac0
// 005fc3e0  8d4c2410             lea ecx, [esp + 0x10]
// 005fc3e4  51                   push ecx
// 005fc3e5  8d542424             lea edx, [esp + 0x24]
// 005fc3e9  52                   push edx
// 005fc3ea  89442418             mov dword ptr [esp + 0x18], eax
// 005fc3ee  8bf0                 mov esi, eax
// 005fc3f0  e84bf7ffff           call 0x5fbb40
// 005fc3f5  83c410               add esp, 0x10
// 005fc3f8  03f0                 add esi, eax
// 005fc3fa  837f0803             cmp dword ptr [edi + 8], 3
// 005fc3fe  7546                 jne 0x5fc446
// 005fc400  dd07                 fld qword ptr [edi]
// 005fc402  dd5c2410             fstp qword ptr [esp + 0x10]
// 005fc406  dd442410             fld qword ptr [esp + 0x10]
// 005fc40a  db5c240c             fistp dword ptr [esp + 0xc]
// 005fc40e  db44240c             fild dword ptr [esp + 0xc]
// 005fc412  dc5c2410             fcomp qword ptr [esp + 0x10]
// 005fc416  dfe0                 fnstsw ax
// 005fc418  f6c444               test ah, 0x44
// 005fc41b  7a29                 jp 0x5fc446
// 005fc41d  8b44240c             mov eax, dword ptr [esp + 0xc]
// 005fc421  85c0                 test eax, eax
// 005fc423  7e21                 jle 0x5fc446
// 005fc425  3d00000004           cmp eax, 0x4000000
// 005fc42a  7f1a                 jg 0x5fc446
// 005fc42c  83c0ff               add eax, -1
// 005fc42f  50                   push eax
// 005fc430  e8cbbfffff           call 0x5f8400
// 005fc435  8d448420             lea eax, [esp + eax*4 + 0x20]
// 005fc439  83c404               add esp, 4
// 005fc43c  830001               add dword ptr [eax], 1
// 005fc43f  b801000000           mov eax, 1
// 005fc444  eb02                 jmp 0x5fc448
// 005fc446  33c0                 xor eax, eax
// 005fc448  01442408             add dword ptr [esp + 8], eax
// 005fc44c  8d442408             lea eax, [esp + 8]
// 005fc450  50                   push eax
// 005fc451  8d44241c             lea eax, [esp + 0x1c]
// 005fc455  e806f6ffff           call 0x5fba60
// 005fc45a  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005fc45e  8b94248c000000       mov edx, dword ptr [esp + 0x8c]
// 005fc465  2bf0                 sub esi, eax
// 005fc467  83c601               add esi, 1
// 005fc46a  56                   push esi
// 005fc46b  51                   push ecx
// 005fc46c  52                   push edx
// 005fc46d  8bc3                 mov eax, ebx
// 005fc46f  e8bcfcffff           call 0x5fc130
// 005fc474  83c410               add esp, 0x10
// 005fc477  5e                   pop esi
// 005fc478  5b                   pop ebx
// 005fc479  83c47c               add esp, 0x7c
// 005fc47c  c3                   ret 
// library lua-5.1.1/ltable.c (function _rehash)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 ltable.c
