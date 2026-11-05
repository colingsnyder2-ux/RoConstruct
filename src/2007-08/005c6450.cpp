// from server: 100% by auto
// roc 2007-08 005c6450  unit: lua_exception  size: 252 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005c6450
//
// 005c6450  83ec08               sub esp, 8
// 005c6453  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 005c6457  53                   push ebx
// 005c6458  55                   push ebp
// 005c6459  56                   push esi
// 005c645a  8b742418             mov esi, dword ptr [esp + 0x18]
// 005c645e  0fb74634             movzx eax, word ptr [esi + 0x34]
// 005c6462  8a4e37               mov cl, byte ptr [esi + 0x37]
// 005c6465  8b5e14               mov ebx, dword ptr [esi + 0x14]
// 005c6468  2b5e28               sub ebx, dword ptr [esi + 0x28]
// 005c646b  57                   push edi
// 005c646c  8b7e74               mov edi, dword ptr [esi + 0x74]
// 005c646f  89442414             mov dword ptr [esp + 0x14], eax
// 005c6473  8b442424             mov eax, dword ptr [esp + 0x24]
// 005c6477  884c241c             mov byte ptr [esp + 0x1c], cl
// 005c647b  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 005c647f  50                   push eax
// 005c6480  51                   push ecx
// 005c6481  56                   push esi
// 005c6482  897c241c             mov dword ptr [esp + 0x1c], edi
// 005c6486  895674               mov dword ptr [esi + 0x74], edx
// 005c6489  e842f4ffff           call 0x5c58d0
// 005c648e  8be8                 mov ebp, eax
// 005c6490  83c40c               add esp, 0xc
// 005c6493  85ed                 test ebp, ebp
// 005c6495  0f84a6000000         je 0x5c6541
// 005c649b  8b7e20               mov edi, dword ptr [esi + 0x20]
// 005c649e  037c2428             add edi, dword ptr [esp + 0x28]
// 005c64a2  57                   push edi
// 005c64a3  56                   push esi
// 005c64a4  e817cc0400           call 0x6130c0
// 005c64a9  57                   push edi
// 005c64aa  55                   push ebp
// 005c64ab  56                   push esi
// 005c64ac  e8eff2ffff           call 0x5c57a0
// 005c64b1  8b4e28               mov ecx, dword ptr [esi + 0x28]
// 005c64b4  668b542428           mov dx, word ptr [esp + 0x28]
// 005c64b9  8d0419               lea eax, [ecx + ebx]
// 005c64bc  66895634             mov word ptr [esi + 0x34], dx
// 005c64c0  894614               mov dword ptr [esi + 0x14], eax
// 005c64c3  8b10                 mov edx, dword ptr [eax]
// 005c64c5  89560c               mov dword ptr [esi + 0xc], edx
// 005c64c8  8b500c               mov edx, dword ptr [eax + 0xc]
// 005c64cb  895618               mov dword ptr [esi + 0x18], edx
// 005c64ce  8a542430             mov dl, byte ptr [esp + 0x30]
// 005c64d2  83c414               add esp, 0x14
// 005c64d5  817e30204e0000       cmp dword ptr [esi + 0x30], 0x4e20
// 005c64dc  885637               mov byte ptr [esi + 0x37], dl
// 005c64df  7e4f                 jle 0x5c6530
// 005c64e1  2bc1                 sub eax, ecx
// 005c64e3  8bc8                 mov ecx, eax
// 005c64e5  b8abaaaa2a           mov eax, 0x2aaaaaab
// 005c64ea  f7e9                 imul ecx
// 005c64ec  c1fa02               sar edx, 2
// 005c64ef  8bc2                 mov eax, edx
// 005c64f1  c1e81f               shr eax, 0x1f
// 005c64f4  8d4c0201             lea ecx, [edx + eax + 1]
// 005c64f8  81f9204e0000         cmp ecx, 0x4e20
// 005c64fe  7d1f                 jge 0x5c651f
// 005c6500  68204e0000           push 0x4e20
// 005c6505  56                   push esi
// 005c6506  e885f5ffff           call 0x5c5a90
// 005c650b  8b542418             mov edx, dword ptr [esp + 0x18]
// 005c650f  83c408               add esp, 8
// 005c6512  5f                   pop edi
// 005c6513  895674               mov dword ptr [esi + 0x74], edx
// 005c6516  5e                   pop esi
// 005c6517  8bc5                 mov eax, ebp
// 005c6519  5d                   pop ebp
// 005c651a  5b                   pop ebx
// 005c651b  83c408               add esp, 8
// 005c651e  c3                   ret 
// 005c651f  8b442410             mov eax, dword ptr [esp + 0x10]
// 005c6523  5f                   pop edi
// 005c6524  894674               mov dword ptr [esi + 0x74], eax
// 005c6527  5e                   pop esi
// 005c6528  8bc5                 mov eax, ebp
// 005c652a  5d                   pop ebp
// 005c652b  5b                   pop ebx
// 005c652c  83c408               add esp, 8
// 005c652f  c3                   ret 
// 005c6530  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005c6534  5f                   pop edi
// 005c6535  894e74               mov dword ptr [esi + 0x74], ecx
// 005c6538  5e                   pop esi
// 005c6539  8bc5                 mov eax, ebp
// 005c653b  5d                   pop ebp
// 005c653c  5b                   pop ebx
// 005c653d  83c408               add esp, 8
// 005c6540  c3                   ret 
// 005c6541  897e74               mov dword ptr [esi + 0x74], edi
// 005c6544  5f                   pop edi
// 005c6545  5e                   pop esi
// 005c6546  5d                   pop ebp
// 005c6547  5b                   pop ebx
// 005c6548  83c408               add esp, 8
// 005c654b  c3                   ret 
// library lua-5.1.2/ldo.c (function _luaD_pcall)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.2 ldo.c
