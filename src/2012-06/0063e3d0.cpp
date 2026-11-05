// from server: 100% by auto
// roc 2012-06 0063e3d0  unit: seg_00630000  size: 443 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0063e3d0
//
// 0063e3d0  83ec14               sub esp, 0x14
// 0063e3d3  8b442418             mov eax, dword ptr [esp + 0x18]
// 0063e3d7  c7042401000000       mov dword ptr [esp], 1
// 0063e3de  85c0                 test eax, eax
// 0063e3e0  0f8498010000         je 0x63e57e
// 0063e3e6  837c241c00           cmp dword ptr [esp + 0x1c], 0
// 0063e3eb  53                   push ebx
// 0063e3ec  8b5c2434             mov ebx, dword ptr [esp + 0x34]
// 0063e3f0  55                   push ebp
// 0063e3f1  8b6c2434             mov ebp, dword ptr [esp + 0x34]
// 0063e3f5  56                   push esi
// 0063e3f6  8b742444             mov esi, dword ptr [esp + 0x44]
// 0063e3fa  57                   push edi
// 0063e3fb  8b7c2444             mov edi, dword ptr [esp + 0x44]
// 0063e3ff  7c25                 jl 0x63e426
// 0063e401  837c243000           cmp dword ptr [esp + 0x30], 0
// 0063e406  7e1e                 jle 0x63e426
// 0063e408  837c243400           cmp dword ptr [esp + 0x34], 0
// 0063e40d  7c17                 jl 0x63e426
// 0063e40f  837c243800           cmp dword ptr [esp + 0x38], 0
// 0063e414  7c10                 jl 0x63e426
// 0063e416  85ed                 test ebp, ebp
// 0063e418  7c0c                 jl 0x63e426
// 0063e41a  85db                 test ebx, ebx
// 0063e41c  7c08                 jl 0x63e426
// 0063e41e  85ff                 test edi, edi
// 0063e420  7c04                 jl 0x63e426
// 0063e422  85f6                 test esi, esi
// 0063e424  7d1a                 jge 0x63e440
// 0063e426  68c444b800           push 0xb844c4
// 0063e42b  50                   push eax
// 0063e42c  e82ffe0000           call 0x64e260
// 0063e431  8b442430             mov eax, dword ptr [esp + 0x30]
// 0063e435  83c408               add esp, 8
// 0063e438  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0063e440  b9ffffff7f           mov ecx, 0x7fffffff
// 0063e445  394c242c             cmp dword ptr [esp + 0x2c], ecx
// 0063e449  7f22                 jg 0x63e46d
// 0063e44b  394c2430             cmp dword ptr [esp + 0x30], ecx
// 0063e44f  7f1c                 jg 0x63e46d
// 0063e451  394c2434             cmp dword ptr [esp + 0x34], ecx
// 0063e455  7f16                 jg 0x63e46d
// 0063e457  394c2438             cmp dword ptr [esp + 0x38], ecx
// 0063e45b  7f10                 jg 0x63e46d
// 0063e45d  3be9                 cmp ebp, ecx
// 0063e45f  7f0c                 jg 0x63e46d
// 0063e461  3bd9                 cmp ebx, ecx
// 0063e463  7f08                 jg 0x63e46d
// 0063e465  3bf9                 cmp edi, ecx
// 0063e467  7f04                 jg 0x63e46d
// 0063e469  3bf1                 cmp esi, ecx
// 0063e46b  7e1a                 jle 0x63e487
// 0063e46d  688444b800           push 0xb84484
// 0063e472  50                   push eax
// 0063e473  e8e8fd0000           call 0x64e260
// 0063e478  8b442430             mov eax, dword ptr [esp + 0x30]
// 0063e47c  83c408               add esp, 8
// 0063e47f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0063e487  b9a0860100           mov ecx, 0x186a0
// 0063e48c  2b4c2430             sub ecx, dword ptr [esp + 0x30]
// 0063e490  394c242c             cmp dword ptr [esp + 0x2c], ecx
// 0063e494  7e1a                 jle 0x63e4b0
// 0063e496  686844b800           push 0xb84468
// 0063e49b  50                   push eax
// 0063e49c  e8bffd0000           call 0x64e260
// 0063e4a1  8b442430             mov eax, dword ptr [esp + 0x30]
// 0063e4a5  83c408               add esp, 8
// 0063e4a8  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0063e4b0  baa0860100           mov edx, 0x186a0
// 0063e4b5  2b542438             sub edx, dword ptr [esp + 0x38]
// 0063e4b9  39542434             cmp dword ptr [esp + 0x34], edx
// 0063e4bd  7e1a                 jle 0x63e4d9
// 0063e4bf  685044b800           push 0xb84450
// 0063e4c4  50                   push eax
// 0063e4c5  e896fd0000           call 0x64e260
// 0063e4ca  8b442430             mov eax, dword ptr [esp + 0x30]
// 0063e4ce  83c408               add esp, 8
// 0063e4d1  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0063e4d9  b9a0860100           mov ecx, 0x186a0
// 0063e4de  2bcb                 sub ecx, ebx
// 0063e4e0  3be9                 cmp ebp, ecx
// 0063e4e2  7e1a                 jle 0x63e4fe
// 0063e4e4  683444b800           push 0xb84434
// 0063e4e9  50                   push eax
// 0063e4ea  e871fd0000           call 0x64e260
// 0063e4ef  8b442430             mov eax, dword ptr [esp + 0x30]
// 0063e4f3  83c408               add esp, 8
// 0063e4f6  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0063e4fe  baa0860100           mov edx, 0x186a0
// 0063e503  2bd6                 sub edx, esi
// 0063e505  3bfa                 cmp edi, edx
// 0063e507  7e16                 jle 0x63e51f
// 0063e509  681c44b800           push 0xb8441c
// 0063e50e  50                   push eax
// 0063e50f  e84cfd0000           call 0x64e260
// 0063e514  83c408               add esp, 8
// 0063e517  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0063e51f  2b742438             sub esi, dword ptr [esp + 0x38]
// 0063e523  2b6c2434             sub ebp, dword ptr [esp + 0x34]
// 0063e527  8d44241c             lea eax, [esp + 0x1c]
// 0063e52b  50                   push eax
// 0063e52c  8d4c2418             lea ecx, [esp + 0x18]
// 0063e530  51                   push ecx
// 0063e531  56                   push esi
// 0063e532  55                   push ebp
// 0063e533  e818feffff           call 0x63e350
// 0063e538  2b7c2444             sub edi, dword ptr [esp + 0x44]
// 0063e53c  2b5c2448             sub ebx, dword ptr [esp + 0x48]
// 0063e540  8d542430             lea edx, [esp + 0x30]
// 0063e544  52                   push edx
// 0063e545  8d44242c             lea eax, [esp + 0x2c]
// 0063e549  50                   push eax
// 0063e54a  57                   push edi
// 0063e54b  53                   push ebx
// 0063e54c  e8fffdffff           call 0x63e350
// 0063e551  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 0063e555  83c420               add esp, 0x20
// 0063e558  5f                   pop edi
// 0063e559  5e                   pop esi
// 0063e55a  5d                   pop ebp
// 0063e55b  5b                   pop ebx
// 0063e55c  3b4c2408             cmp ecx, dword ptr [esp + 8]
// 0063e560  7522                 jne 0x63e584
// 0063e562  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0063e566  3b542410             cmp edx, dword ptr [esp + 0x10]
// 0063e56a  7518                 jne 0x63e584
// 0063e56c  8b442418             mov eax, dword ptr [esp + 0x18]
// 0063e570  68e043b800           push 0xb843e0
// 0063e575  50                   push eax
// 0063e576  e8e5fc0000           call 0x64e260
// 0063e57b  83c408               add esp, 8
// 0063e57e  33c0                 xor eax, eax
// 0063e580  83c414               add esp, 0x14
// 0063e583  c3                   ret 
// 0063e584  8b0424               mov eax, dword ptr [esp]
// 0063e587  83c414               add esp, 0x14
// 0063e58a  c3                   ret 
// library libpng-1.2.35/png.c (function _png_check_cHRM_fixed)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.35 png.c
