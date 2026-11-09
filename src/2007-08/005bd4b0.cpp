// from server: 100% by auto
// roc 2007-08 005bd4b0  unit: RBX::VPVInstance::?$EnumPropDescriptor  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005bd4b0
//
// 005bd4b0  8b4c2408             mov ecx, dword ptr [esp + 8]
// 005bd4b4  56                   push esi
// 005bd4b5  8b742408             mov esi, dword ptr [esp + 8]
// 005bd4b9  8b4608               mov eax, dword ptr [esi + 8]
// 005bd4bc  8bd0                 mov edx, eax
// 005bd4be  2b560c               sub edx, dword ptr [esi + 0xc]
// 005bd4c1  c1fa04               sar edx, 4
// 005bd4c4  03d1                 add edx, ecx
// 005bd4c6  81fa00080000         cmp edx, 0x800
// 005bd4cc  7e04                 jle 0x5bd4d2
// 005bd4ce  33c0                 xor eax, eax
// 005bd4d0  5e                   pop esi
// 005bd4d1  c3                   ret 
// 005bd4d2  8b561c               mov edx, dword ptr [esi + 0x1c]
// 005bd4d5  57                   push edi
// 005bd4d6  8bf9                 mov edi, ecx
// 005bd4d8  c1e704               shl edi, 4
// 005bd4db  2bd0                 sub edx, eax
// 005bd4dd  3bd7                 cmp edx, edi
// 005bd4df  7f0a                 jg 0x5bd4eb
// 005bd4e1  51                   push ecx
// 005bd4e2  56                   push esi
// 005bd4e3  e828860000           call 0x5c5b10
// 005bd4e8  83c408               add esp, 8
// 005bd4eb  8b4608               mov eax, dword ptr [esi + 8]
// 005bd4ee  8b7614               mov esi, dword ptr [esi + 0x14]
// 005bd4f1  03c7                 add eax, edi
// 005bd4f3  394608               cmp dword ptr [esi + 8], eax
// 005bd4f6  5f                   pop edi
// 005bd4f7  7303                 jae 0x5bd4fc
// 005bd4f9  894608               mov dword ptr [esi + 8], eax
// 005bd4fc  b801000000           mov eax, 1
// 005bd501  5e                   pop esi
// 005bd502  c3                   ret 
// library lua-5.1/lapi.c (function _lua_checkstack)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
