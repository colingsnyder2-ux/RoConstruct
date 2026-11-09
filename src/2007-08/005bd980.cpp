// from server: 100% by auto
// roc 2007-08 005bd980  unit: RBX::VPVInstance::?$EnumPropDescriptor  size: 110 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005bd980
//
// 005bd980  56                   push esi
// 005bd981  8b742408             mov esi, dword ptr [esp + 8]
// 005bd985  57                   push edi
// 005bd986  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 005bd98a  8bc7                 mov eax, edi
// 005bd98c  8bce                 mov ecx, esi
// 005bd98e  e89dfaffff           call 0x5bd430
// 005bd993  83780804             cmp dword ptr [eax + 8], 4
// 005bd997  743e                 je 0x5bd9d7
// 005bd999  50                   push eax
// 005bd99a  56                   push esi
// 005bd99b  e880270500           call 0x610120
// 005bd9a0  83c408               add esp, 8
// 005bd9a3  85c0                 test eax, eax
// 005bd9a5  7513                 jne 0x5bd9ba
// 005bd9a7  8b442414             mov eax, dword ptr [esp + 0x14]
// 005bd9ab  85c0                 test eax, eax
// 005bd9ad  7406                 je 0x5bd9b5
// 005bd9af  c70000000000         mov dword ptr [eax], 0
// 005bd9b5  5f                   pop edi
// 005bd9b6  33c0                 xor eax, eax
// 005bd9b8  5e                   pop esi
// 005bd9b9  c3                   ret 
// 005bd9ba  8b4610               mov eax, dword ptr [esi + 0x10]
// 005bd9bd  8b4844               mov ecx, dword ptr [eax + 0x44]
// 005bd9c0  3b4840               cmp ecx, dword ptr [eax + 0x40]
// 005bd9c3  7209                 jb 0x5bd9ce
// 005bd9c5  56                   push esi
// 005bd9c6  e835240500           call 0x60fe00
// 005bd9cb  83c404               add esp, 4
// 005bd9ce  8bc7                 mov eax, edi
// 005bd9d0  8bce                 mov ecx, esi
// 005bd9d2  e859faffff           call 0x5bd430
// 005bd9d7  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 005bd9db  85c9                 test ecx, ecx
// 005bd9dd  7407                 je 0x5bd9e6
// 005bd9df  8b10                 mov edx, dword ptr [eax]
// 005bd9e1  8b520c               mov edx, dword ptr [edx + 0xc]
// 005bd9e4  8911                 mov dword ptr [ecx], edx
// 005bd9e6  8b00                 mov eax, dword ptr [eax]
// 005bd9e8  5f                   pop edi
// 005bd9e9  83c010               add eax, 0x10
// 005bd9ec  5e                   pop esi
// 005bd9ed  c3                   ret 
// library lua-5.1/lapi.c (function _lua_tolstring)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
