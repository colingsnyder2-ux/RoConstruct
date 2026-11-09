// from server: 100% by auto
// roc 2009-12 007d0e90  unit: seg_007d0000  size: 161 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007d0e90
//
// 007d0e90  56                   push esi
// 007d0e91  8b742408             mov esi, dword ptr [esp + 8]
// 007d0e95  837e6800             cmp dword ptr [esi + 0x68], 0
// 007d0e99  57                   push edi
// 007d0e9a  8b7e10               mov edi, dword ptr [esi + 0x10]
// 007d0e9d  0f848b000000         je 0x7d0f2e
// 007d0ea3  55                   push ebp
// 007d0ea4  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 007d0ea8  53                   push ebx
// 007d0ea9  8da42400000000       lea esp, [esp]
// 007d0eb0  8b4668               mov eax, dword ptr [esi + 0x68]
// 007d0eb3  396808               cmp dword ptr [eax + 8], ebp
// 007d0eb6  7274                 jb 0x7d0f2c
// 007d0eb8  8b08                 mov ecx, dword ptr [eax]
// 007d0eba  894e68               mov dword ptr [esi + 0x68], ecx
// 007d0ebd  0fb65005             movzx edx, byte ptr [eax + 5]
// 007d0ec1  0fb64f14             movzx ecx, byte ptr [edi + 0x14]
// 007d0ec5  f7d1                 not ecx
// 007d0ec7  83e203               and edx, 3
// 007d0eca  84d1                 test cl, dl
// 007d0ecc  8d4810               lea ecx, [eax + 0x10]
// 007d0ecf  7425                 je 0x7d0ef6
// 007d0ed1  394808               cmp dword ptr [eax + 8], ecx
// 007d0ed4  7410                 je 0x7d0ee6
// 007d0ed6  8b5014               mov edx, dword ptr [eax + 0x14]
// 007d0ed9  8b19                 mov ebx, dword ptr [ecx]
// 007d0edb  895a10               mov dword ptr [edx + 0x10], ebx
// 007d0ede  8b09                 mov ecx, dword ptr [ecx]
// 007d0ee0  8b5014               mov edx, dword ptr [eax + 0x14]
// 007d0ee3  895114               mov dword ptr [ecx + 0x14], edx
// 007d0ee6  6a00                 push 0
// 007d0ee8  6a20                 push 0x20
// 007d0eea  50                   push eax
// 007d0eeb  56                   push esi
// 007d0eec  e8bf080000           call 0x7d17b0
// 007d0ef1  83c410               add esp, 0x10
// 007d0ef4  eb30                 jmp 0x7d0f26
// 007d0ef6  8b5014               mov edx, dword ptr [eax + 0x14]
// 007d0ef9  8b19                 mov ebx, dword ptr [ecx]
// 007d0efb  895a10               mov dword ptr [edx + 0x10], ebx
// 007d0efe  8b11                 mov edx, dword ptr [ecx]
// 007d0f00  8b5814               mov ebx, dword ptr [eax + 0x14]
// 007d0f03  895a14               mov dword ptr [edx + 0x14], ebx
// 007d0f06  8b5008               mov edx, dword ptr [eax + 8]
// 007d0f09  8b1a                 mov ebx, dword ptr [edx]
// 007d0f0b  8919                 mov dword ptr [ecx], ebx
// 007d0f0d  8b5a04               mov ebx, dword ptr [edx + 4]
// 007d0f10  895904               mov dword ptr [ecx + 4], ebx
// 007d0f13  8b5208               mov edx, dword ptr [edx + 8]
// 007d0f16  50                   push eax
// 007d0f17  895108               mov dword ptr [ecx + 8], edx
// 007d0f1a  56                   push esi
// 007d0f1b  894808               mov dword ptr [eax + 8], ecx
// 007d0f1e  e86dceffff           call 0x7cdd90
// 007d0f23  83c408               add esp, 8
// 007d0f26  837e6800             cmp dword ptr [esi + 0x68], 0
// 007d0f2a  7584                 jne 0x7d0eb0
// 007d0f2c  5b                   pop ebx
// 007d0f2d  5d                   pop ebp
// 007d0f2e  5f                   pop edi
// 007d0f2f  5e                   pop esi
// 007d0f30  c3                   ret 
// library lua-5.1.2/lfunc.c (function _luaF_close)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.2 lfunc.c
