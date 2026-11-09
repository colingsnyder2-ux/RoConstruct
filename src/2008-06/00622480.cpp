// from server: 100% by auto
// roc 2008-06 00622480  unit: lua_exception  size: 252 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00622480
//
// 00622480  83ec08               sub esp, 8
// 00622483  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 00622487  53                   push ebx
// 00622488  55                   push ebp
// 00622489  56                   push esi
// 0062248a  8b742418             mov esi, dword ptr [esp + 0x18]
// 0062248e  0fb74634             movzx eax, word ptr [esi + 0x34]
// 00622492  8a4e37               mov cl, byte ptr [esi + 0x37]
// 00622495  8b5e14               mov ebx, dword ptr [esi + 0x14]
// 00622498  2b5e28               sub ebx, dword ptr [esi + 0x28]
// 0062249b  57                   push edi
// 0062249c  8b7e74               mov edi, dword ptr [esi + 0x74]
// 0062249f  89442414             mov dword ptr [esp + 0x14], eax
// 006224a3  8b442424             mov eax, dword ptr [esp + 0x24]
// 006224a7  884c241c             mov byte ptr [esp + 0x1c], cl
// 006224ab  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 006224af  50                   push eax
// 006224b0  51                   push ecx
// 006224b1  56                   push esi
// 006224b2  897c241c             mov dword ptr [esp + 0x1c], edi
// 006224b6  895674               mov dword ptr [esi + 0x74], edx
// 006224b9  e862f4ffff           call 0x621920
// 006224be  8be8                 mov ebp, eax
// 006224c0  83c40c               add esp, 0xc
// 006224c3  85ed                 test ebp, ebp
// 006224c5  0f84a6000000         je 0x622571
// 006224cb  8b7e20               mov edi, dword ptr [esi + 0x20]
// 006224ce  037c2428             add edi, dword ptr [esp + 0x28]
// 006224d2  57                   push edi
// 006224d3  56                   push esi
// 006224d4  e827d10300           call 0x65f600
// 006224d9  57                   push edi
// 006224da  55                   push ebp
// 006224db  56                   push esi
// 006224dc  e80ff3ffff           call 0x6217f0
// 006224e1  8b4e28               mov ecx, dword ptr [esi + 0x28]
// 006224e4  668b542428           mov dx, word ptr [esp + 0x28]
// 006224e9  8d0419               lea eax, [ecx + ebx]
// 006224ec  66895634             mov word ptr [esi + 0x34], dx
// 006224f0  894614               mov dword ptr [esi + 0x14], eax
// 006224f3  8b10                 mov edx, dword ptr [eax]
// 006224f5  89560c               mov dword ptr [esi + 0xc], edx
// 006224f8  8b500c               mov edx, dword ptr [eax + 0xc]
// 006224fb  895618               mov dword ptr [esi + 0x18], edx
// 006224fe  8a542430             mov dl, byte ptr [esp + 0x30]
// 00622502  83c414               add esp, 0x14
// 00622505  817e30204e0000       cmp dword ptr [esi + 0x30], 0x4e20
// 0062250c  885637               mov byte ptr [esi + 0x37], dl
// 0062250f  7e4f                 jle 0x622560
// 00622511  2bc1                 sub eax, ecx
// 00622513  8bc8                 mov ecx, eax
// 00622515  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0062251a  f7e9                 imul ecx
// 0062251c  c1fa02               sar edx, 2
// 0062251f  8bc2                 mov eax, edx
// 00622521  c1e81f               shr eax, 0x1f
// 00622524  8d4c0201             lea ecx, [edx + eax + 1]
// 00622528  81f9204e0000         cmp ecx, 0x4e20
// 0062252e  7d1f                 jge 0x62254f
// 00622530  68204e0000           push 0x4e20
// 00622535  56                   push esi
// 00622536  e895f5ffff           call 0x621ad0
// 0062253b  8b542418             mov edx, dword ptr [esp + 0x18]
// 0062253f  83c408               add esp, 8
// 00622542  5f                   pop edi
// 00622543  895674               mov dword ptr [esi + 0x74], edx
// 00622546  5e                   pop esi
// 00622547  8bc5                 mov eax, ebp
// 00622549  5d                   pop ebp
// 0062254a  5b                   pop ebx
// 0062254b  83c408               add esp, 8
// 0062254e  c3                   ret 
// 0062254f  8b442410             mov eax, dword ptr [esp + 0x10]
// 00622553  5f                   pop edi
// 00622554  894674               mov dword ptr [esi + 0x74], eax
// 00622557  5e                   pop esi
// 00622558  8bc5                 mov eax, ebp
// 0062255a  5d                   pop ebp
// 0062255b  5b                   pop ebx
// 0062255c  83c408               add esp, 8
// 0062255f  c3                   ret 
// 00622560  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00622564  5f                   pop edi
// 00622565  894e74               mov dword ptr [esi + 0x74], ecx
// 00622568  5e                   pop esi
// 00622569  8bc5                 mov eax, ebp
// 0062256b  5d                   pop ebp
// 0062256c  5b                   pop ebx
// 0062256d  83c408               add esp, 8
// 00622570  c3                   ret 
// 00622571  897e74               mov dword ptr [esi + 0x74], edi
// 00622574  5f                   pop edi
// 00622575  5e                   pop esi
// 00622576  5d                   pop ebp
// 00622577  5b                   pop ebx
// 00622578  83c408               add esp, 8
// 0062257b  c3                   ret 
// library lua-5.1.2/ldo.c (function _luaD_pcall)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.2 ldo.c
