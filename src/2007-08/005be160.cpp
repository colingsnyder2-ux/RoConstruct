// from server: 100% by auto
// roc 2007-08 005be160  unit: RBX::VPVInstance::?$EnumPropDescriptor  size: 161 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005be160
//
// 005be160  8b442408             mov eax, dword ptr [esp + 8]
// 005be164  56                   push esi
// 005be165  57                   push edi
// 005be166  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 005be16a  8bcf                 mov ecx, edi
// 005be16c  e8bff2ffff           call 0x5bd430
// 005be171  8b4f08               mov ecx, dword ptr [edi + 8]
// 005be174  8379f800             cmp dword ptr [ecx - 8], 0
// 005be178  7504                 jne 0x5be17e
// 005be17a  33c9                 xor ecx, ecx
// 005be17c  eb03                 jmp 0x5be181
// 005be17e  8b49f0               mov ecx, dword ptr [ecx - 0x10]
// 005be181  8b5008               mov edx, dword ptr [eax + 8]
// 005be184  8bf2                 mov esi, edx
// 005be186  83ee05               sub esi, 5
// 005be189  7449                 je 0x5be1d4
// 005be18b  83ee02               sub esi, 2
// 005be18e  7416                 je 0x5be1a6
// 005be190  8b4710               mov eax, dword ptr [edi + 0x10]
// 005be193  898c9098000000       mov dword ptr [eax + edx*4 + 0x98], ecx
// 005be19a  834708f0             add dword ptr [edi + 8], -0x10
// 005be19e  5f                   pop edi
// 005be19f  b801000000           mov eax, 1
// 005be1a4  5e                   pop esi
// 005be1a5  c3                   ret 
// 005be1a6  85c9                 test ecx, ecx
// 005be1a8  8b10                 mov edx, dword ptr [eax]
// 005be1aa  894a08               mov dword ptr [edx + 8], ecx
// 005be1ad  7446                 je 0x5be1f5
// 005be1af  f6410503             test byte ptr [ecx + 5], 3
// 005be1b3  7440                 je 0x5be1f5
// 005be1b5  8b00                 mov eax, dword ptr [eax]
// 005be1b7  f6400504             test byte ptr [eax + 5], 4
// 005be1bb  7438                 je 0x5be1f5
// 005be1bd  51                   push ecx
// 005be1be  50                   push eax
// 005be1bf  57                   push edi
// 005be1c0  e82b1d0500           call 0x60fef0
// 005be1c5  83c40c               add esp, 0xc
// 005be1c8  834708f0             add dword ptr [edi + 8], -0x10
// 005be1cc  5f                   pop edi
// 005be1cd  b801000000           mov eax, 1
// 005be1d2  5e                   pop esi
// 005be1d3  c3                   ret 
// 005be1d4  85c9                 test ecx, ecx
// 005be1d6  8b10                 mov edx, dword ptr [eax]
// 005be1d8  894a08               mov dword ptr [edx + 8], ecx
// 005be1db  7418                 je 0x5be1f5
// 005be1dd  f6410503             test byte ptr [ecx + 5], 3
// 005be1e1  7412                 je 0x5be1f5
// 005be1e3  8b00                 mov eax, dword ptr [eax]
// 005be1e5  f6400504             test byte ptr [eax + 5], 4
// 005be1e9  740a                 je 0x5be1f5
// 005be1eb  50                   push eax
// 005be1ec  57                   push edi
// 005be1ed  e83e1d0500           call 0x60ff30
// 005be1f2  83c408               add esp, 8
// 005be1f5  834708f0             add dword ptr [edi + 8], -0x10
// 005be1f9  5f                   pop edi
// 005be1fa  b801000000           mov eax, 1
// 005be1ff  5e                   pop esi
// 005be200  c3                   ret 
// library lua-5.1/lapi.c (function _lua_setmetatable)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
