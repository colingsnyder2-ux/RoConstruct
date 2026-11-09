// from server: 100% by auto
// roc 2007-08 005be210  unit: RBX::VPVInstance::?$EnumPropDescriptor  size: 128 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005be210
//
// 005be210  8b442408             mov eax, dword ptr [esp + 8]
// 005be214  56                   push esi
// 005be215  8b742408             mov esi, dword ptr [esp + 8]
// 005be219  57                   push edi
// 005be21a  8bce                 mov ecx, esi
// 005be21c  bf01000000           mov edi, 1
// 005be221  e80af2ffff           call 0x5bd430
// 005be226  8b4808               mov ecx, dword ptr [eax + 8]
// 005be229  83e906               sub ecx, 6
// 005be22c  742f                 je 0x5be25d
// 005be22e  2bcf                 sub ecx, edi
// 005be230  741e                 je 0x5be250
// 005be232  2bcf                 sub ecx, edi
// 005be234  7404                 je 0x5be23a
// 005be236  33ff                 xor edi, edi
// 005be238  eb2e                 jmp 0x5be268
// 005be23a  8b08                 mov ecx, dword ptr [eax]
// 005be23c  8b5608               mov edx, dword ptr [esi + 8]
// 005be23f  8b52f0               mov edx, dword ptr [edx - 0x10]
// 005be242  83c148               add ecx, 0x48
// 005be245  8911                 mov dword ptr [ecx], edx
// 005be247  c7410805000000       mov dword ptr [ecx + 8], 5
// 005be24e  eb18                 jmp 0x5be268
// 005be250  8b4e08               mov ecx, dword ptr [esi + 8]
// 005be253  8b10                 mov edx, dword ptr [eax]
// 005be255  8b49f0               mov ecx, dword ptr [ecx - 0x10]
// 005be258  894a0c               mov dword ptr [edx + 0xc], ecx
// 005be25b  eb0b                 jmp 0x5be268
// 005be25d  8b5608               mov edx, dword ptr [esi + 8]
// 005be260  8b08                 mov ecx, dword ptr [eax]
// 005be262  8b52f0               mov edx, dword ptr [edx - 0x10]
// 005be265  89510c               mov dword ptr [ecx + 0xc], edx
// 005be268  8b4e08               mov ecx, dword ptr [esi + 8]
// 005be26b  8b49f0               mov ecx, dword ptr [ecx - 0x10]
// 005be26e  f6410503             test byte ptr [ecx + 5], 3
// 005be272  7413                 je 0x5be287
// 005be274  8b00                 mov eax, dword ptr [eax]
// 005be276  f6400504             test byte ptr [eax + 5], 4
// 005be27a  740b                 je 0x5be287
// 005be27c  51                   push ecx
// 005be27d  50                   push eax
// 005be27e  56                   push esi
// 005be27f  e86c1c0500           call 0x60fef0
// 005be284  83c40c               add esp, 0xc
// 005be287  834608f0             add dword ptr [esi + 8], -0x10
// 005be28b  8bc7                 mov eax, edi
// 005be28d  5f                   pop edi
// 005be28e  5e                   pop esi
// 005be28f  c3                   ret 
// library lua-5.1/lapi.c (function _lua_setfenv)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
