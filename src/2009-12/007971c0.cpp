// from server: 100% by auto
// roc 2009-12 007971c0  unit: lua_exception  size: 142 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007971c0
//
// 007971c0  8b4108               mov eax, dword ptr [ecx + 8]
// 007971c3  2bc2                 sub eax, edx
// 007971c5  c1f804               sar eax, 4
// 007971c8  c1e004               shl eax, 4
// 007971cb  034120               add eax, dword ptr [ecx + 0x20]
// 007971ce  56                   push esi
// 007971cf  894108               mov dword ptr [ecx + 8], eax
// 007971d2  8b4168               mov eax, dword ptr [ecx + 0x68]
// 007971d5  85c0                 test eax, eax
// 007971d7  741e                 je 0x7971f7
// 007971d9  8da42400000000       lea esp, [esp]
// 007971e0  8b7008               mov esi, dword ptr [eax + 8]
// 007971e3  2bf2                 sub esi, edx
// 007971e5  c1fe04               sar esi, 4
// 007971e8  c1e604               shl esi, 4
// 007971eb  037120               add esi, dword ptr [ecx + 0x20]
// 007971ee  897008               mov dword ptr [eax + 8], esi
// 007971f1  8b00                 mov eax, dword ptr [eax]
// 007971f3  85c0                 test eax, eax
// 007971f5  75e9                 jne 0x7971e0
// 007971f7  8b4128               mov eax, dword ptr [ecx + 0x28]
// 007971fa  3b4114               cmp eax, dword ptr [ecx + 0x14]
// 007971fd  773c                 ja 0x79723b
// 007971ff  90                   nop 
// 00797200  8b7008               mov esi, dword ptr [eax + 8]
// 00797203  2bf2                 sub esi, edx
// 00797205  c1fe04               sar esi, 4
// 00797208  c1e604               shl esi, 4
// 0079720b  037120               add esi, dword ptr [ecx + 0x20]
// 0079720e  83c018               add eax, 0x18
// 00797211  8970f0               mov dword ptr [eax - 0x10], esi
// 00797214  8b70e8               mov esi, dword ptr [eax - 0x18]
// 00797217  2bf2                 sub esi, edx
// 00797219  c1fe04               sar esi, 4
// 0079721c  c1e604               shl esi, 4
// 0079721f  037120               add esi, dword ptr [ecx + 0x20]
// 00797222  8970e8               mov dword ptr [eax - 0x18], esi
// 00797225  8b70ec               mov esi, dword ptr [eax - 0x14]
// 00797228  2bf2                 sub esi, edx
// 0079722a  c1fe04               sar esi, 4
// 0079722d  c1e604               shl esi, 4
// 00797230  037120               add esi, dword ptr [ecx + 0x20]
// 00797233  8970ec               mov dword ptr [eax - 0x14], esi
// 00797236  3b4114               cmp eax, dword ptr [ecx + 0x14]
// 00797239  76c5                 jbe 0x797200
// 0079723b  8b410c               mov eax, dword ptr [ecx + 0xc]
// 0079723e  2bc2                 sub eax, edx
// 00797240  c1f804               sar eax, 4
// 00797243  c1e004               shl eax, 4
// 00797246  034120               add eax, dword ptr [ecx + 0x20]
// 00797249  5e                   pop esi
// 0079724a  89410c               mov dword ptr [ecx + 0xc], eax
// 0079724d  c3                   ret 
// library lua-5.1/ldo.c (function _correctstack)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ldo.c
