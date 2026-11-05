// from server: 100% by auto
// roc 2007-08 00611fd0  unit: seg_00610000  size: 224 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00611fd0
//
// 00611fd0  8b442404             mov eax, dword ptr [esp + 4]
// 00611fd4  53                   push ebx
// 00611fd5  56                   push esi
// 00611fd6  8b742410             mov esi, dword ptr [esp + 0x10]
// 00611fda  57                   push edi
// 00611fdb  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 00611fdf  56                   push esi
// 00611fe0  50                   push eax
// 00611fe1  e82affffff           call 0x611f10
// 00611fe6  8b4e1c               mov ecx, dword ptr [esi + 0x1c]
// 00611fe9  83c001               add eax, 1
// 00611fec  83c408               add esp, 8
// 00611fef  3bc1                 cmp eax, ecx
// 00611ff1  7d1c                 jge 0x61200f
// 00611ff3  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 00611ff6  8bd0                 mov edx, eax
// 00611ff8  c1e204               shl edx, 4
// 00611ffb  8d541a08             lea edx, [edx + ebx + 8]
// 00611fff  90                   nop 
// 00612000  833a00               cmp dword ptr [edx], 0
// 00612003  7540                 jne 0x612045
// 00612005  83c001               add eax, 1
// 00612008  83c210               add edx, 0x10
// 0061200b  3bc1                 cmp eax, ecx
// 0061200d  7cf1                 jl 0x612000
// 0061200f  2bc1                 sub eax, ecx
// 00612011  8a4e07               mov cl, byte ptr [esi + 7]
// 00612014  ba01000000           mov edx, 1
// 00612019  d3e2                 shl edx, cl
// 0061201b  3bc2                 cmp eax, edx
// 0061201d  7d20                 jge 0x61203f
// 0061201f  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 00612022  8bd8                 mov ebx, eax
// 00612024  c1e305               shl ebx, 5
// 00612027  8d5c0b08             lea ebx, [ebx + ecx + 8]
// 0061202b  eb03                 jmp 0x612030
// 0061202d  8d4900               lea ecx, [ecx]
// 00612030  833b00               cmp dword ptr [ebx], 0
// 00612033  7544                 jne 0x612079
// 00612035  83c001               add eax, 1
// 00612038  83c320               add ebx, 0x20
// 0061203b  3bc2                 cmp eax, edx
// 0061203d  7cf1                 jl 0x612030
// 0061203f  5f                   pop edi
// 00612040  5e                   pop esi
// 00612041  33c0                 xor eax, eax
// 00612043  5b                   pop ebx
// 00612044  c3                   ret 
// 00612045  8d4801               lea ecx, [eax + 1]
// 00612048  894c2414             mov dword ptr [esp + 0x14], ecx
// 0061204c  db442414             fild dword ptr [esp + 0x14]
// 00612050  c7470803000000       mov dword ptr [edi + 8], 3
// 00612057  c1e004               shl eax, 4
// 0061205a  dd1f                 fstp qword ptr [edi]
// 0061205c  03460c               add eax, dword ptr [esi + 0xc]
// 0061205f  8b10                 mov edx, dword ptr [eax]
// 00612061  895710               mov dword ptr [edi + 0x10], edx
// 00612064  8b4804               mov ecx, dword ptr [eax + 4]
// 00612067  894f14               mov dword ptr [edi + 0x14], ecx
// 0061206a  8b5008               mov edx, dword ptr [eax + 8]
// 0061206d  895718               mov dword ptr [edi + 0x18], edx
// 00612070  5f                   pop edi
// 00612071  5e                   pop esi
// 00612072  b801000000           mov eax, 1
// 00612077  5b                   pop ebx
// 00612078  c3                   ret 
// 00612079  c1e005               shl eax, 5
// 0061207c  8b540110             mov edx, dword ptr [ecx + eax + 0x10]
// 00612080  8917                 mov dword ptr [edi], edx
// 00612082  8b540114             mov edx, dword ptr [ecx + eax + 0x14]
// 00612086  895704               mov dword ptr [edi + 4], edx
// 00612089  8b4c0118             mov ecx, dword ptr [ecx + eax + 0x18]
// 0061208d  894f08               mov dword ptr [edi + 8], ecx
// 00612090  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 00612093  8b1401               mov edx, dword ptr [ecx + eax]
// 00612096  03c8                 add ecx, eax
// 00612098  895710               mov dword ptr [edi + 0x10], edx
// 0061209b  8b4104               mov eax, dword ptr [ecx + 4]
// 0061209e  894714               mov dword ptr [edi + 0x14], eax
// 006120a1  8b4908               mov ecx, dword ptr [ecx + 8]
// 006120a4  894f18               mov dword ptr [edi + 0x18], ecx
// 006120a7  5f                   pop edi
// 006120a8  5e                   pop esi
// 006120a9  b801000000           mov eax, 1
// 006120ae  5b                   pop ebx
// 006120af  c3                   ret 
// library lua-5.1/ltable.c (function _luaH_next)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ltable.c
