// from server: 100% by auto
// roc 2007-03 006151c0  unit: seg_00610000  size: 121 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006151c0
//
// 006151c0  53                   push ebx
// 006151c1  56                   push esi
// 006151c2  8b74240c             mov esi, dword ptr [esp + 0xc]
// 006151c6  57                   push edi
// 006151c7  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 006151cb  57                   push edi
// 006151cc  56                   push esi
// 006151cd  e85efcffff           call 0x614e30
// 006151d2  83c408               add esp, 8
// 006151d5  833f0c               cmp dword ptr [edi], 0xc
// 006151d8  7516                 jne 0x6151f0
// 006151da  8b4708               mov eax, dword ptr [edi + 8]
// 006151dd  a900010000           test eax, 0x100
// 006151e2  750c                 jne 0x6151f0
// 006151e4  0fb64e32             movzx ecx, byte ptr [esi + 0x32]
// 006151e8  3bc1                 cmp eax, ecx
// 006151ea  7c04                 jl 0x6151f0
// 006151ec  834624ff             add dword ptr [esi + 0x24], -1
// 006151f0  8b16                 mov edx, dword ptr [esi]
// 006151f2  8b5e24               mov ebx, dword ptr [esi + 0x24]
// 006151f5  0fb6424b             movzx eax, byte ptr [edx + 0x4b]
// 006151f9  83c301               add ebx, 1
// 006151fc  3bd8                 cmp ebx, eax
// 006151fe  7e1e                 jle 0x61521e
// 00615200  81fbfa000000         cmp ebx, 0xfa
// 00615206  7c11                 jl 0x615219
// 00615208  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 0061520b  6894207c00           push 0x7c2094
// 00615210  51                   push ecx
// 00615211  e85abdfeff           call 0x600f70
// 00615216  83c408               add esp, 8
// 00615219  8b16                 mov edx, dword ptr [esi]
// 0061521b  885a4b               mov byte ptr [edx + 0x4b], bl
// 0061521e  83462401             add dword ptr [esi + 0x24], 1
// 00615222  8b4624               mov eax, dword ptr [esi + 0x24]
// 00615225  83c0ff               add eax, -1
// 00615228  50                   push eax
// 00615229  8bc7                 mov eax, edi
// 0061522b  8bce                 mov ecx, esi
// 0061522d  e86efeffff           call 0x6150a0
// 00615232  83c404               add esp, 4
// 00615235  5f                   pop edi
// 00615236  5e                   pop esi
// 00615237  5b                   pop ebx
// 00615238  c3                   ret 
// library lua-5.1.1/lcode.c (function _luaK_exp2nextreg)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lcode.c
