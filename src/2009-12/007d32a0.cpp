// from server: 100% by auto
// roc 2009-12 007d32a0  unit: seg_007d0000  size: 347 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007d32a0
//
// 007d32a0  83ec38               sub esp, 0x38
// 007d32a3  53                   push ebx
// 007d32a4  8b5c2440             mov ebx, dword ptr [esp + 0x40]
// 007d32a8  55                   push ebp
// 007d32a9  8b6c2448             mov ebp, dword ptr [esp + 0x48]
// 007d32ad  8d4508               lea eax, [ebp + 8]
// 007d32b0  89442448             mov dword ptr [esp + 0x48], eax
// 007d32b4  8b00                 mov eax, dword ptr [eax]
// 007d32b6  83f806               cmp eax, 6
// 007d32b9  56                   push esi
// 007d32ba  57                   push edi
// 007d32bb  7c05                 jl 0x7d32c2
// 007d32bd  83f809               cmp eax, 9
// 007d32c0  7e0e                 jle 0x7d32d0
// 007d32c2  68b0ef9e00           push 0x9eefb0
// 007d32c7  53                   push ebx
// 007d32c8  e873200000           call 0x7d5340
// 007d32cd  83c408               add esp, 8
// 007d32d0  8b4310               mov eax, dword ptr [ebx + 0x10]
// 007d32d3  83f82c               cmp eax, 0x2c
// 007d32d6  755d                 jne 0x7d3335
// 007d32d8  53                   push ebx
// 007d32d9  e852340000           call 0x7d6730
// 007d32de  83c404               add esp, 4
// 007d32e1  8d7c2430             lea edi, [esp + 0x30]
// 007d32e5  8bf3                 mov esi, ebx
// 007d32e7  896c2428             mov dword ptr [esp + 0x28], ebp
// 007d32eb  e840f7ffff           call 0x7d2a30
// 007d32f0  837c243006           cmp dword ptr [esp + 0x30], 6
// 007d32f5  7509                 jne 0x7d3300
// 007d32f7  8bc5                 mov eax, ebp
// 007d32f9  8bcb                 mov ecx, ebx
// 007d32fb  e840ffffff           call 0x7d3240
// 007d3300  8b4334               mov eax, dword ptr [ebx + 0x34]
// 007d3303  0fb74834             movzx ecx, word ptr [eax + 0x34]
// 007d3307  8b7c2454             mov edi, dword ptr [esp + 0x54]
// 007d330b  bac8000000           mov edx, 0xc8
// 007d3310  2bd1                 sub edx, ecx
// 007d3312  3bfa                 cmp edi, edx
// 007d3314  7e0d                 jle 0x7d3323
// 007d3316  8b7330               mov esi, dword ptr [ebx + 0x30]
// 007d3319  b998ef9e00           mov ecx, 0x9eef98
// 007d331e  e86de5ffff           call 0x7d1890
// 007d3323  47                   inc edi
// 007d3324  57                   push edi
// 007d3325  8d54242c             lea edx, [esp + 0x2c]
// 007d3329  52                   push edx
// 007d332a  53                   push ebx
// 007d332b  e870ffffff           call 0x7d32a0
// 007d3330  83c40c               add esp, 0xc
// 007d3333  eb61                 jmp 0x7d3396
// 007d3335  83f83d               cmp eax, 0x3d
// 007d3338  7421                 je 0x7d335b
// 007d333a  6a3d                 push 0x3d
// 007d333c  53                   push ebx
// 007d333d  e8fe1e0000           call 0x7d5240
// 007d3342  50                   push eax
// 007d3343  8b4334               mov eax, dword ptr [ebx + 0x34]
// 007d3346  68d0ed9e00           push 0x9eedd0
// 007d334b  50                   push eax
// 007d334c  e82f72fcff           call 0x79a580
// 007d3351  50                   push eax
// 007d3352  53                   push ebx
// 007d3353  e8e81f0000           call 0x7d5340
// 007d3358  83c41c               add esp, 0x1c
// 007d335b  53                   push ebx
// 007d335c  e8cf330000           call 0x7d6730
// 007d3361  83c404               add esp, 4
// 007d3364  8d7c2410             lea edi, [esp + 0x10]
// 007d3368  8bf3                 mov esi, ebx
// 007d336a  e8d1f4ffff           call 0x7d2840
// 007d336f  8b742454             mov esi, dword ptr [esp + 0x54]
// 007d3373  8bf8                 mov edi, eax
// 007d3375  3bfe                 cmp edi, esi
// 007d3377  7456                 je 0x7d33cf
// 007d3379  57                   push edi
// 007d337a  8d4c2414             lea ecx, [esp + 0x14]
// 007d337e  8bd6                 mov edx, esi
// 007d3380  8bc3                 mov eax, ebx
// 007d3382  e8e9e9ffff           call 0x7d1d70
// 007d3387  83c404               add esp, 4
// 007d338a  3bfe                 cmp edi, esi
// 007d338c  7e08                 jle 0x7d3396
// 007d338e  8b4330               mov eax, dword ptr [ebx + 0x30]
// 007d3391  2bf7                 sub esi, edi
// 007d3393  017024               add dword ptr [eax + 0x24], esi
// 007d3396  8b5b30               mov ebx, dword ptr [ebx + 0x30]
// 007d3399  8b4324               mov eax, dword ptr [ebx + 0x24]
// 007d339c  8b542450             mov edx, dword ptr [esp + 0x50]
// 007d33a0  83c9ff               or ecx, 0xffffffff
// 007d33a3  894c2420             mov dword ptr [esp + 0x20], ecx
// 007d33a7  894c2424             mov dword ptr [esp + 0x24], ecx
// 007d33ab  8d4c2410             lea ecx, [esp + 0x10]
// 007d33af  51                   push ecx
// 007d33b0  52                   push edx
// 007d33b1  48                   dec eax
// 007d33b2  53                   push ebx
// 007d33b3  c744241c0c000000     mov dword ptr [esp + 0x1c], 0xc
// 007d33bb  89442424             mov dword ptr [esp + 0x24], eax
// 007d33bf  e83c9a0000           call 0x7dce00
// 007d33c4  83c40c               add esp, 0xc
// 007d33c7  5f                   pop edi
// 007d33c8  5e                   pop esi
// 007d33c9  5d                   pop ebp
// 007d33ca  5b                   pop ebx
// 007d33cb  83c438               add esp, 0x38
// 007d33ce  c3                   ret 
// 007d33cf  8b4b30               mov ecx, dword ptr [ebx + 0x30]
// 007d33d2  8d442410             lea eax, [esp + 0x10]
// 007d33d6  50                   push eax
// 007d33d7  51                   push ecx
// 007d33d8  e8b38f0000           call 0x7dc390
// 007d33dd  8b442458             mov eax, dword ptr [esp + 0x58]
// 007d33e1  8b4b30               mov ecx, dword ptr [ebx + 0x30]
// 007d33e4  8d542418             lea edx, [esp + 0x18]
// 007d33e8  52                   push edx
// 007d33e9  50                   push eax
// 007d33ea  51                   push ecx
// 007d33eb  e8109a0000           call 0x7dce00
// 007d33f0  83c414               add esp, 0x14
// 007d33f3  5f                   pop edi
// 007d33f4  5e                   pop esi
// 007d33f5  5d                   pop ebp
// 007d33f6  5b                   pop ebx
// 007d33f7  83c438               add esp, 0x38
// 007d33fa  c3                   ret 
// library lua-5.1.3/lparser.c (function _assignment)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.3 lparser.c
