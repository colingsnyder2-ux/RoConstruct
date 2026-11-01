// from server: 100% by auto
// roc 2007-03 005fca70  unit: seg_005f0000  size: 159 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005fca70
//
// 005fca70  56                   push esi
// 005fca71  8b742408             mov esi, dword ptr [esp + 8]
// 005fca75  8b4668               mov eax, dword ptr [esi + 0x68]
// 005fca78  85c0                 test eax, eax
// 005fca7a  57                   push edi
// 005fca7b  8b7e10               mov edi, dword ptr [esi + 0x10]
// 005fca7e  0f8488000000         je 0x5fcb0c
// 005fca84  55                   push ebp
// 005fca85  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 005fca89  53                   push ebx
// 005fca8a  8d9b00000000         lea ebx, [ebx]
// 005fca90  396808               cmp dword ptr [eax + 8], ebp
// 005fca93  7275                 jb 0x5fcb0a
// 005fca95  8b08                 mov ecx, dword ptr [eax]
// 005fca97  894e68               mov dword ptr [esi + 0x68], ecx
// 005fca9a  0fb65005             movzx edx, byte ptr [eax + 5]
// 005fca9e  0fb64f14             movzx ecx, byte ptr [edi + 0x14]
// 005fcaa2  f7d1                 not ecx
// 005fcaa4  83e203               and edx, 3
// 005fcaa7  84d1                 test cl, dl
// 005fcaa9  8d4810               lea ecx, [eax + 0x10]
// 005fcaac  7425                 je 0x5fcad3
// 005fcaae  394808               cmp dword ptr [eax + 8], ecx
// 005fcab1  7410                 je 0x5fcac3
// 005fcab3  8b5014               mov edx, dword ptr [eax + 0x14]
// 005fcab6  8b19                 mov ebx, dword ptr [ecx]
// 005fcab8  895a10               mov dword ptr [edx + 0x10], ebx
// 005fcabb  8b09                 mov ecx, dword ptr [ecx]
// 005fcabd  8b5014               mov edx, dword ptr [eax + 0x14]
// 005fcac0  895114               mov dword ptr [ecx + 0x14], edx
// 005fcac3  6a00                 push 0
// 005fcac5  6a20                 push 0x20
// 005fcac7  50                   push eax
// 005fcac8  56                   push esi
// 005fcac9  e8d2080000           call 0x5fd3a0
// 005fcace  83c410               add esp, 0x10
// 005fcad1  eb30                 jmp 0x5fcb03
// 005fcad3  8b5014               mov edx, dword ptr [eax + 0x14]
// 005fcad6  8b19                 mov ebx, dword ptr [ecx]
// 005fcad8  895a10               mov dword ptr [edx + 0x10], ebx
// 005fcadb  8b11                 mov edx, dword ptr [ecx]
// 005fcadd  8b5814               mov ebx, dword ptr [eax + 0x14]
// 005fcae0  895a14               mov dword ptr [edx + 0x14], ebx
// 005fcae3  8b5008               mov edx, dword ptr [eax + 8]
// 005fcae6  8b1a                 mov ebx, dword ptr [edx]
// 005fcae8  8919                 mov dword ptr [ecx], ebx
// 005fcaea  8b5a04               mov ebx, dword ptr [edx + 4]
// 005fcaed  895904               mov dword ptr [ecx + 4], ebx
// 005fcaf0  8b5208               mov edx, dword ptr [edx + 8]
// 005fcaf3  50                   push eax
// 005fcaf4  895108               mov dword ptr [ecx + 8], edx
// 005fcaf7  56                   push esi
// 005fcaf8  894808               mov dword ptr [eax + 8], ecx
// 005fcafb  e830ceffff           call 0x5f9930
// 005fcb00  83c408               add esp, 8
// 005fcb03  8b4668               mov eax, dword ptr [esi + 0x68]
// 005fcb06  85c0                 test eax, eax
// 005fcb08  7586                 jne 0x5fca90
// 005fcb0a  5b                   pop ebx
// 005fcb0b  5d                   pop ebp
// 005fcb0c  5f                   pop edi
// 005fcb0d  5e                   pop esi
// 005fcb0e  c3                   ret 
// library lua-5.1.1/lfunc.c (function _luaF_close)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lfunc.c
