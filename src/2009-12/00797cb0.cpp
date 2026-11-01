// from server: 100% by auto
// roc 2009-12 00797cb0  unit: lua_exception  size: 252 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00797cb0
//
// 00797cb0  83ec08               sub esp, 8
// 00797cb3  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 00797cb7  53                   push ebx
// 00797cb8  55                   push ebp
// 00797cb9  56                   push esi
// 00797cba  8b742418             mov esi, dword ptr [esp + 0x18]
// 00797cbe  0fb74634             movzx eax, word ptr [esi + 0x34]
// 00797cc2  8a4e39               mov cl, byte ptr [esi + 0x39]
// 00797cc5  8b5e14               mov ebx, dword ptr [esi + 0x14]
// 00797cc8  2b5e28               sub ebx, dword ptr [esi + 0x28]
// 00797ccb  57                   push edi
// 00797ccc  8b7e74               mov edi, dword ptr [esi + 0x74]
// 00797ccf  89442414             mov dword ptr [esp + 0x14], eax
// 00797cd3  8b442424             mov eax, dword ptr [esp + 0x24]
// 00797cd7  884c241c             mov byte ptr [esp + 0x1c], cl
// 00797cdb  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00797cdf  50                   push eax
// 00797ce0  51                   push ecx
// 00797ce1  56                   push esi
// 00797ce2  897c241c             mov dword ptr [esp + 0x1c], edi
// 00797ce6  895674               mov dword ptr [esi + 0x74], edx
// 00797ce9  e812f4ffff           call 0x797100
// 00797cee  8be8                 mov ebp, eax
// 00797cf0  83c40c               add esp, 0xc
// 00797cf3  85ed                 test ebp, ebp
// 00797cf5  0f84a6000000         je 0x797da1
// 00797cfb  8b7e20               mov edi, dword ptr [esi + 0x20]
// 00797cfe  037c2428             add edi, dword ptr [esp + 0x28]
// 00797d02  57                   push edi
// 00797d03  56                   push esi
// 00797d04  e887910300           call 0x7d0e90
// 00797d09  57                   push edi
// 00797d0a  55                   push ebp
// 00797d0b  56                   push esi
// 00797d0c  e8bff2ffff           call 0x796fd0
// 00797d11  8b4e28               mov ecx, dword ptr [esi + 0x28]
// 00797d14  668b542428           mov dx, word ptr [esp + 0x28]
// 00797d19  8d0419               lea eax, [ecx + ebx]
// 00797d1c  66895634             mov word ptr [esi + 0x34], dx
// 00797d20  894614               mov dword ptr [esi + 0x14], eax
// 00797d23  8b10                 mov edx, dword ptr [eax]
// 00797d25  89560c               mov dword ptr [esi + 0xc], edx
// 00797d28  8b500c               mov edx, dword ptr [eax + 0xc]
// 00797d2b  895618               mov dword ptr [esi + 0x18], edx
// 00797d2e  8a542430             mov dl, byte ptr [esp + 0x30]
// 00797d32  83c414               add esp, 0x14
// 00797d35  817e30204e0000       cmp dword ptr [esi + 0x30], 0x4e20
// 00797d3c  885639               mov byte ptr [esi + 0x39], dl
// 00797d3f  7e4f                 jle 0x797d90
// 00797d41  2bc1                 sub eax, ecx
// 00797d43  8bc8                 mov ecx, eax
// 00797d45  b8abaaaa2a           mov eax, 0x2aaaaaab
// 00797d4a  f7e9                 imul ecx
// 00797d4c  c1fa02               sar edx, 2
// 00797d4f  8bc2                 mov eax, edx
// 00797d51  c1e81f               shr eax, 0x1f
// 00797d54  8d4c0201             lea ecx, [edx + eax + 1]
// 00797d58  81f9204e0000         cmp ecx, 0x4e20
// 00797d5e  7d1f                 jge 0x797d7f
// 00797d60  68204e0000           push 0x4e20
// 00797d65  56                   push esi
// 00797d66  e845f5ffff           call 0x7972b0
// 00797d6b  8b542418             mov edx, dword ptr [esp + 0x18]
// 00797d6f  83c408               add esp, 8
// 00797d72  5f                   pop edi
// 00797d73  895674               mov dword ptr [esi + 0x74], edx
// 00797d76  5e                   pop esi
// 00797d77  8bc5                 mov eax, ebp
// 00797d79  5d                   pop ebp
// 00797d7a  5b                   pop ebx
// 00797d7b  83c408               add esp, 8
// 00797d7e  c3                   ret 
// 00797d7f  8b442410             mov eax, dword ptr [esp + 0x10]
// 00797d83  5f                   pop edi
// 00797d84  894674               mov dword ptr [esi + 0x74], eax
// 00797d87  5e                   pop esi
// 00797d88  8bc5                 mov eax, ebp
// 00797d8a  5d                   pop ebp
// 00797d8b  5b                   pop ebx
// 00797d8c  83c408               add esp, 8
// 00797d8f  c3                   ret 
// 00797d90  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00797d94  5f                   pop edi
// 00797d95  894e74               mov dword ptr [esi + 0x74], ecx
// 00797d98  5e                   pop esi
// 00797d99  8bc5                 mov eax, ebp
// 00797d9b  5d                   pop ebp
// 00797d9c  5b                   pop ebx
// 00797d9d  83c408               add esp, 8
// 00797da0  c3                   ret 
// 00797da1  897e74               mov dword ptr [esi + 0x74], edi
// 00797da4  5f                   pop edi
// 00797da5  5e                   pop esi
// 00797da6  5d                   pop ebp
// 00797da7  5b                   pop ebx
// 00797da8  83c408               add esp, 8
// 00797dab  c3                   ret 
// library lua-5.1.3/ldo.c (function _luaD_pcall)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.3 ldo.c
