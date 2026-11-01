// from server: 100% by auto
// roc 2007-03 005fb980  unit: seg_005f0000  size: 224 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005fb980
//
// 005fb980  8b442404             mov eax, dword ptr [esp + 4]
// 005fb984  53                   push ebx
// 005fb985  56                   push esi
// 005fb986  8b742410             mov esi, dword ptr [esp + 0x10]
// 005fb98a  57                   push edi
// 005fb98b  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 005fb98f  56                   push esi
// 005fb990  50                   push eax
// 005fb991  e82affffff           call 0x5fb8c0
// 005fb996  8b4e1c               mov ecx, dword ptr [esi + 0x1c]
// 005fb999  83c001               add eax, 1
// 005fb99c  83c408               add esp, 8
// 005fb99f  3bc1                 cmp eax, ecx
// 005fb9a1  7d1c                 jge 0x5fb9bf
// 005fb9a3  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 005fb9a6  8bd0                 mov edx, eax
// 005fb9a8  c1e204               shl edx, 4
// 005fb9ab  8d541a08             lea edx, [edx + ebx + 8]
// 005fb9af  90                   nop 
// 005fb9b0  833a00               cmp dword ptr [edx], 0
// 005fb9b3  7540                 jne 0x5fb9f5
// 005fb9b5  83c001               add eax, 1
// 005fb9b8  83c210               add edx, 0x10
// 005fb9bb  3bc1                 cmp eax, ecx
// 005fb9bd  7cf1                 jl 0x5fb9b0
// 005fb9bf  2bc1                 sub eax, ecx
// 005fb9c1  8a4e07               mov cl, byte ptr [esi + 7]
// 005fb9c4  ba01000000           mov edx, 1
// 005fb9c9  d3e2                 shl edx, cl
// 005fb9cb  3bc2                 cmp eax, edx
// 005fb9cd  7d20                 jge 0x5fb9ef
// 005fb9cf  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 005fb9d2  8bd8                 mov ebx, eax
// 005fb9d4  c1e305               shl ebx, 5
// 005fb9d7  8d5c0b08             lea ebx, [ebx + ecx + 8]
// 005fb9db  eb03                 jmp 0x5fb9e0
// 005fb9dd  8d4900               lea ecx, [ecx]
// 005fb9e0  833b00               cmp dword ptr [ebx], 0
// 005fb9e3  7544                 jne 0x5fba29
// 005fb9e5  83c001               add eax, 1
// 005fb9e8  83c320               add ebx, 0x20
// 005fb9eb  3bc2                 cmp eax, edx
// 005fb9ed  7cf1                 jl 0x5fb9e0
// 005fb9ef  5f                   pop edi
// 005fb9f0  5e                   pop esi
// 005fb9f1  33c0                 xor eax, eax
// 005fb9f3  5b                   pop ebx
// 005fb9f4  c3                   ret 
// 005fb9f5  8d4801               lea ecx, [eax + 1]
// 005fb9f8  894c2414             mov dword ptr [esp + 0x14], ecx
// 005fb9fc  db442414             fild dword ptr [esp + 0x14]
// 005fba00  c7470803000000       mov dword ptr [edi + 8], 3
// 005fba07  c1e004               shl eax, 4
// 005fba0a  dd1f                 fstp qword ptr [edi]
// 005fba0c  03460c               add eax, dword ptr [esi + 0xc]
// 005fba0f  8b10                 mov edx, dword ptr [eax]
// 005fba11  895710               mov dword ptr [edi + 0x10], edx
// 005fba14  8b4804               mov ecx, dword ptr [eax + 4]
// 005fba17  894f14               mov dword ptr [edi + 0x14], ecx
// 005fba1a  8b5008               mov edx, dword ptr [eax + 8]
// 005fba1d  895718               mov dword ptr [edi + 0x18], edx
// 005fba20  5f                   pop edi
// 005fba21  5e                   pop esi
// 005fba22  b801000000           mov eax, 1
// 005fba27  5b                   pop ebx
// 005fba28  c3                   ret 
// 005fba29  c1e005               shl eax, 5
// 005fba2c  8b540110             mov edx, dword ptr [ecx + eax + 0x10]
// 005fba30  8917                 mov dword ptr [edi], edx
// 005fba32  8b540114             mov edx, dword ptr [ecx + eax + 0x14]
// 005fba36  895704               mov dword ptr [edi + 4], edx
// 005fba39  8b4c0118             mov ecx, dword ptr [ecx + eax + 0x18]
// 005fba3d  894f08               mov dword ptr [edi + 8], ecx
// 005fba40  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 005fba43  8b1401               mov edx, dword ptr [ecx + eax]
// 005fba46  03c8                 add ecx, eax
// 005fba48  895710               mov dword ptr [edi + 0x10], edx
// 005fba4b  8b4104               mov eax, dword ptr [ecx + 4]
// 005fba4e  894714               mov dword ptr [edi + 0x14], eax
// 005fba51  8b4908               mov ecx, dword ptr [ecx + 8]
// 005fba54  894f18               mov dword ptr [edi + 0x18], ecx
// 005fba57  5f                   pop edi
// 005fba58  5e                   pop esi
// 005fba59  b801000000           mov eax, 1
// 005fba5e  5b                   pop ebx
// 005fba5f  c3                   ret 
// library lua-5.1.1/ltable.c (function _luaH_next)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 ltable.c
