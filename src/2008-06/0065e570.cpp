// from server: 100% by auto
// roc 2008-06 0065e570  unit: seg_00650000  size: 222 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0065e570
//
// 0065e570  8b442404             mov eax, dword ptr [esp + 4]
// 0065e574  53                   push ebx
// 0065e575  56                   push esi
// 0065e576  8b742410             mov esi, dword ptr [esp + 0x10]
// 0065e57a  57                   push edi
// 0065e57b  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 0065e57f  56                   push esi
// 0065e580  50                   push eax
// 0065e581  e82affffff           call 0x65e4b0
// 0065e586  8b4e1c               mov ecx, dword ptr [esi + 0x1c]
// 0065e589  40                   inc eax
// 0065e58a  83c408               add esp, 8
// 0065e58d  3bc1                 cmp eax, ecx
// 0065e58f  7d1c                 jge 0x65e5ad
// 0065e591  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 0065e594  8bd0                 mov edx, eax
// 0065e596  c1e204               shl edx, 4
// 0065e599  8d541a08             lea edx, [edx + ebx + 8]
// 0065e59d  8d4900               lea ecx, [ecx]
// 0065e5a0  833a00               cmp dword ptr [edx], 0
// 0065e5a3  753e                 jne 0x65e5e3
// 0065e5a5  40                   inc eax
// 0065e5a6  83c210               add edx, 0x10
// 0065e5a9  3bc1                 cmp eax, ecx
// 0065e5ab  7cf3                 jl 0x65e5a0
// 0065e5ad  2bc1                 sub eax, ecx
// 0065e5af  8a4e07               mov cl, byte ptr [esi + 7]
// 0065e5b2  ba01000000           mov edx, 1
// 0065e5b7  d3e2                 shl edx, cl
// 0065e5b9  3bc2                 cmp eax, edx
// 0065e5bb  7d20                 jge 0x65e5dd
// 0065e5bd  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 0065e5c0  8bd8                 mov ebx, eax
// 0065e5c2  c1e305               shl ebx, 5
// 0065e5c5  8d5c0b08             lea ebx, [ebx + ecx + 8]
// 0065e5c9  8da42400000000       lea esp, [esp]
// 0065e5d0  833b00               cmp dword ptr [ebx], 0
// 0065e5d3  7542                 jne 0x65e617
// 0065e5d5  40                   inc eax
// 0065e5d6  83c320               add ebx, 0x20
// 0065e5d9  3bc2                 cmp eax, edx
// 0065e5db  7cf3                 jl 0x65e5d0
// 0065e5dd  5f                   pop edi
// 0065e5de  5e                   pop esi
// 0065e5df  33c0                 xor eax, eax
// 0065e5e1  5b                   pop ebx
// 0065e5e2  c3                   ret 
// 0065e5e3  8d4801               lea ecx, [eax + 1]
// 0065e5e6  894c2414             mov dword ptr [esp + 0x14], ecx
// 0065e5ea  db442414             fild dword ptr [esp + 0x14]
// 0065e5ee  c7470803000000       mov dword ptr [edi + 8], 3
// 0065e5f5  c1e004               shl eax, 4
// 0065e5f8  dd1f                 fstp qword ptr [edi]
// 0065e5fa  03460c               add eax, dword ptr [esi + 0xc]
// 0065e5fd  8b10                 mov edx, dword ptr [eax]
// 0065e5ff  895710               mov dword ptr [edi + 0x10], edx
// 0065e602  8b4804               mov ecx, dword ptr [eax + 4]
// 0065e605  894f14               mov dword ptr [edi + 0x14], ecx
// 0065e608  8b5008               mov edx, dword ptr [eax + 8]
// 0065e60b  895718               mov dword ptr [edi + 0x18], edx
// 0065e60e  5f                   pop edi
// 0065e60f  5e                   pop esi
// 0065e610  b801000000           mov eax, 1
// 0065e615  5b                   pop ebx
// 0065e616  c3                   ret 
// 0065e617  c1e005               shl eax, 5
// 0065e61a  8b540110             mov edx, dword ptr [ecx + eax + 0x10]
// 0065e61e  8917                 mov dword ptr [edi], edx
// 0065e620  8b540114             mov edx, dword ptr [ecx + eax + 0x14]
// 0065e624  895704               mov dword ptr [edi + 4], edx
// 0065e627  8b4c0118             mov ecx, dword ptr [ecx + eax + 0x18]
// 0065e62b  894f08               mov dword ptr [edi + 8], ecx
// 0065e62e  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 0065e631  8b1401               mov edx, dword ptr [ecx + eax]
// 0065e634  03c8                 add ecx, eax
// 0065e636  895710               mov dword ptr [edi + 0x10], edx
// 0065e639  8b4104               mov eax, dword ptr [ecx + 4]
// 0065e63c  894714               mov dword ptr [edi + 0x14], eax
// 0065e63f  8b4908               mov ecx, dword ptr [ecx + 8]
// 0065e642  894f18               mov dword ptr [edi + 0x18], ecx
// 0065e645  5f                   pop edi
// 0065e646  5e                   pop esi
// 0065e647  b801000000           mov eax, 1
// 0065e64c  5b                   pop ebx
// 0065e64d  c3                   ret 
// library lua-5.1/ltable.c (function _luaH_next)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ltable.c
