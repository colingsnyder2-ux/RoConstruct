// from server: 100% by auto
// roc 2008-06 006128a0  unit: seg_00610000  size: 128 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006128a0
//
// 006128a0  8b442408             mov eax, dword ptr [esp + 8]
// 006128a4  56                   push esi
// 006128a5  8b742408             mov esi, dword ptr [esp + 8]
// 006128a9  57                   push edi
// 006128aa  8bce                 mov ecx, esi
// 006128ac  bf01000000           mov edi, 1
// 006128b1  e8daf1ffff           call 0x611a90
// 006128b6  8b4808               mov ecx, dword ptr [eax + 8]
// 006128b9  83e906               sub ecx, 6
// 006128bc  742f                 je 0x6128ed
// 006128be  2bcf                 sub ecx, edi
// 006128c0  741e                 je 0x6128e0
// 006128c2  2bcf                 sub ecx, edi
// 006128c4  7404                 je 0x6128ca
// 006128c6  33ff                 xor edi, edi
// 006128c8  eb2e                 jmp 0x6128f8
// 006128ca  8b08                 mov ecx, dword ptr [eax]
// 006128cc  8b5608               mov edx, dword ptr [esi + 8]
// 006128cf  8b52f0               mov edx, dword ptr [edx - 0x10]
// 006128d2  83c148               add ecx, 0x48
// 006128d5  8911                 mov dword ptr [ecx], edx
// 006128d7  c7410805000000       mov dword ptr [ecx + 8], 5
// 006128de  eb18                 jmp 0x6128f8
// 006128e0  8b4e08               mov ecx, dword ptr [esi + 8]
// 006128e3  8b10                 mov edx, dword ptr [eax]
// 006128e5  8b49f0               mov ecx, dword ptr [ecx - 0x10]
// 006128e8  894a0c               mov dword ptr [edx + 0xc], ecx
// 006128eb  eb0b                 jmp 0x6128f8
// 006128ed  8b5608               mov edx, dword ptr [esi + 8]
// 006128f0  8b08                 mov ecx, dword ptr [eax]
// 006128f2  8b52f0               mov edx, dword ptr [edx - 0x10]
// 006128f5  89510c               mov dword ptr [ecx + 0xc], edx
// 006128f8  8b4e08               mov ecx, dword ptr [esi + 8]
// 006128fb  8b49f0               mov ecx, dword ptr [ecx - 0x10]
// 006128fe  f6410503             test byte ptr [ecx + 5], 3
// 00612902  7413                 je 0x612917
// 00612904  8b00                 mov eax, dword ptr [eax]
// 00612906  f6400504             test byte ptr [eax + 5], 4
// 0061290a  740b                 je 0x612917
// 0061290c  51                   push ecx
// 0061290d  50                   push eax
// 0061290e  56                   push esi
// 0061290f  e86c9b0400           call 0x65c480
// 00612914  83c40c               add esp, 0xc
// 00612917  834608f0             add dword ptr [esi + 8], -0x10
// 0061291b  8bc7                 mov eax, edi
// 0061291d  5f                   pop edi
// 0061291e  5e                   pop esi
// 0061291f  c3                   ret 
// library lua-5.1/lapi.c (function _lua_setfenv)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
