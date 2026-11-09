// from server: 100% by auto
// roc 2007-08 00615510  unit: seg_00610000  size: 301 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00615510
//
// 00615510  83ec38               sub esp, 0x38
// 00615513  53                   push ebx
// 00615514  8b5c2444             mov ebx, dword ptr [esp + 0x44]
// 00615518  8b4308               mov eax, dword ptr [ebx + 8]
// 0061551b  83f806               cmp eax, 6
// 0061551e  55                   push ebp
// 0061551f  8d6b08               lea ebp, [ebx + 8]
// 00615522  56                   push esi
// 00615523  8b742448             mov esi, dword ptr [esp + 0x48]
// 00615527  57                   push edi
// 00615528  7c05                 jl 0x61552f
// 0061552a  83f809               cmp eax, 9
// 0061552d  7e0e                 jle 0x61553d
// 0061552f  6838357c00           push 0x7c3538
// 00615534  56                   push esi
// 00615535  e886200000           call 0x6175c0
// 0061553a  83c408               add esp, 8
// 0061553d  8b4610               mov eax, dword ptr [esi + 0x10]
// 00615540  83f82c               cmp eax, 0x2c
// 00615543  753e                 jne 0x615583
// 00615545  56                   push esi
// 00615546  e8a5340000           call 0x6189f0
// 0061554b  83c404               add esp, 4
// 0061554e  8d7c2430             lea edi, [esp + 0x30]
// 00615552  895c2428             mov dword ptr [esp + 0x28], ebx
// 00615556  e845f7ffff           call 0x614ca0
// 0061555b  837c243006           cmp dword ptr [esp + 0x30], 6
// 00615560  7509                 jne 0x61556b
// 00615562  8bc3                 mov eax, ebx
// 00615564  8bce                 mov ecx, esi
// 00615566  e845ffffff           call 0x6154b0
// 0061556b  8b442454             mov eax, dword ptr [esp + 0x54]
// 0061556f  83c001               add eax, 1
// 00615572  50                   push eax
// 00615573  8d4c242c             lea ecx, [esp + 0x2c]
// 00615577  51                   push ecx
// 00615578  56                   push esi
// 00615579  e892ffffff           call 0x615510
// 0061557e  83c40c               add esp, 0xc
// 00615581  eb5f                 jmp 0x6155e2
// 00615583  83f83d               cmp eax, 0x3d
// 00615586  7421                 je 0x6155a9
// 00615588  6a3d                 push 0x3d
// 0061558a  56                   push esi
// 0061558b  e8301f0000           call 0x6174c0
// 00615590  8b5634               mov edx, dword ptr [esi + 0x34]
// 00615593  50                   push eax
// 00615594  6870337c00           push 0x7c3370
// 00615599  52                   push edx
// 0061559a  e8f198ffff           call 0x60ee90
// 0061559f  50                   push eax
// 006155a0  56                   push esi
// 006155a1  e81a200000           call 0x6175c0
// 006155a6  83c41c               add esp, 0x1c
// 006155a9  56                   push esi
// 006155aa  e841340000           call 0x6189f0
// 006155af  83c404               add esp, 4
// 006155b2  8d7c2410             lea edi, [esp + 0x10]
// 006155b6  e8f5f4ffff           call 0x614ab0
// 006155bb  8b7c2454             mov edi, dword ptr [esp + 0x54]
// 006155bf  8bd8                 mov ebx, eax
// 006155c1  3bdf                 cmp ebx, edi
// 006155c3  8d4c2410             lea ecx, [esp + 0x10]
// 006155c7  7450                 je 0x615619
// 006155c9  53                   push ebx
// 006155ca  8bd7                 mov edx, edi
// 006155cc  8bc6                 mov eax, esi
// 006155ce  e8fde9ffff           call 0x613fd0
// 006155d3  83c404               add esp, 4
// 006155d6  3bdf                 cmp ebx, edi
// 006155d8  7e08                 jle 0x6155e2
// 006155da  8b4630               mov eax, dword ptr [esi + 0x30]
// 006155dd  2bfb                 sub edi, ebx
// 006155df  017824               add dword ptr [eax + 0x24], edi
// 006155e2  8b7630               mov esi, dword ptr [esi + 0x30]
// 006155e5  8b4624               mov eax, dword ptr [esi + 0x24]
// 006155e8  83e801               sub eax, 1
// 006155eb  89442418             mov dword ptr [esp + 0x18], eax
// 006155ef  8d442410             lea eax, [esp + 0x10]
// 006155f3  50                   push eax
// 006155f4  83c9ff               or ecx, 0xffffffff
// 006155f7  55                   push ebp
// 006155f8  56                   push esi
// 006155f9  894c242c             mov dword ptr [esp + 0x2c], ecx
// 006155fd  894c2430             mov dword ptr [esp + 0x30], ecx
// 00615601  c744241c0c000000     mov dword ptr [esp + 0x1c], 0xc
// 00615609  e8723f0100           call 0x629580
// 0061560e  83c40c               add esp, 0xc
// 00615611  5f                   pop edi
// 00615612  5e                   pop esi
// 00615613  5d                   pop ebp
// 00615614  5b                   pop ebx
// 00615615  83c438               add esp, 0x38
// 00615618  c3                   ret 
// 00615619  8b5630               mov edx, dword ptr [esi + 0x30]
// 0061561c  51                   push ecx
// 0061561d  52                   push edx
// 0061561e  e8fd340100           call 0x628b20
// 00615623  8b4e30               mov ecx, dword ptr [esi + 0x30]
// 00615626  8d442418             lea eax, [esp + 0x18]
// 0061562a  50                   push eax
// 0061562b  55                   push ebp
// 0061562c  51                   push ecx
// 0061562d  e84e3f0100           call 0x629580
// 00615632  83c414               add esp, 0x14
// 00615635  5f                   pop edi
// 00615636  5e                   pop esi
// 00615637  5d                   pop ebp
// 00615638  5b                   pop ebx
// 00615639  83c438               add esp, 0x38
// 0061563c  c3                   ret 
// library lua-5.1.2/lparser.c (function _assignment)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.2 lparser.c
