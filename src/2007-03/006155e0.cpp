// from server: 100% by auto
// roc 2007-03 006155e0  unit: seg_00610000  size: 153 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006155e0
//
// 006155e0  56                   push esi
// 006155e1  8b742408             mov esi, dword ptr [esp + 8]
// 006155e5  57                   push edi
// 006155e6  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 006155ea  57                   push edi
// 006155eb  56                   push esi
// 006155ec  e83ff8ffff           call 0x614e30
// 006155f1  8b07                 mov eax, dword ptr [edi]
// 006155f3  83c0fe               add eax, -2
// 006155f6  83c408               add esp, 8
// 006155f9  83f808               cmp eax, 8
// 006155fc  772c                 ja 0x61562a
// 006155fe  0fb68070566100       movzx eax, byte ptr [eax + 0x615670]
// 00615605  ff248560566100       jmp dword ptr [eax*4 + 0x615660]
// 0061560c  83c8ff               or eax, 0xffffffff
// 0061560f  eb22                 jmp 0x615633
// 00615611  56                   push esi
// 00615612  e829f7ffff           call 0x614d40
// 00615617  83c404               add esp, 4
// 0061561a  eb17                 jmp 0x615633
// 0061561c  8bc7                 mov eax, edi
// 0061561e  8bce                 mov ecx, esi
// 00615620  e88bf3ffff           call 0x6149b0
// 00615625  8b4708               mov eax, dword ptr [edi + 8]
// 00615628  eb09                 jmp 0x615633
// 0061562a  53                   push ebx
// 0061562b  33db                 xor ebx, ebx
// 0061562d  e82effffff           call 0x615560
// 00615632  5b                   pop ebx
// 00615633  50                   push eax
// 00615634  8d4f14               lea ecx, [edi + 0x14]
// 00615637  51                   push ecx
// 00615638  56                   push esi
// 00615639  e812f0ffff           call 0x614650
// 0061563e  8b4710               mov eax, dword ptr [edi + 0x10]
// 00615641  8b5618               mov edx, dword ptr [esi + 0x18]
// 00615644  50                   push eax
// 00615645  8d4620               lea eax, [esi + 0x20]
// 00615648  50                   push eax
// 00615649  56                   push esi
// 0061564a  89561c               mov dword ptr [esi + 0x1c], edx
// 0061564d  e8feefffff           call 0x614650
// 00615652  83c418               add esp, 0x18
// 00615655  c74710ffffffff       mov dword ptr [edi + 0x10], 0xffffffff
// 0061565c  5f                   pop edi
// 0061565d  5e                   pop esi
// 0061565e  c3                   ret 
// 0061565f  90                   nop 
// 00615660  0c56                 or al, 0x56
// 00615662  61                   popal 
// 00615663  0011                 add byte ptr [ecx], dl
// 00615665  56                   push esi
// 00615666  61                   popal 
// 00615667  001c56               add byte ptr [esi + edx*2], bl
// 0061566a  61                   popal 
// 0061566b  002a                 add byte ptr [edx], ch
// 0061566d  56                   push esi
// 0061566e  61                   popal 
// 0061566f  0000                 add byte ptr [eax], al
// 00615671  0100                 add dword ptr [eax], eax
// 00615673  0003                 add byte ptr [ebx], al
// 00615675  0303                 add eax, dword ptr [ebx]
// 00615677  0302                 add eax, dword ptr [edx]
// library lua-5.1.1/lcode.c (function _luaK_goiftrue)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lcode.c
