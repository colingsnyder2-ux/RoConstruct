// from server: 100% by auto
// roc 2007-08 005be4f0  unit: RBX::VPVInstance::?$EnumPropDescriptor  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005be4f0
//
// 005be4f0  8b442408             mov eax, dword ptr [esp + 8]
// 005be4f4  56                   push esi
// 005be4f5  8b742408             mov esi, dword ptr [esp + 8]
// 005be4f9  8bce                 mov ecx, esi
// 005be4fb  e830efffff           call 0x5bd430
// 005be500  8b4e08               mov ecx, dword ptr [esi + 8]
// 005be503  8b10                 mov edx, dword ptr [eax]
// 005be505  83e910               sub ecx, 0x10
// 005be508  51                   push ecx
// 005be509  52                   push edx
// 005be50a  56                   push esi
// 005be50b  e8c03a0500           call 0x611fd0
// 005be510  83c40c               add esp, 0xc
// 005be513  85c0                 test eax, eax
// 005be515  7406                 je 0x5be51d
// 005be517  83460810             add dword ptr [esi + 8], 0x10
// 005be51b  5e                   pop esi
// 005be51c  c3                   ret 
// 005be51d  834608f0             add dword ptr [esi + 8], -0x10
// 005be521  5e                   pop esi
// 005be522  c3                   ret 
// library lua-5.1/lapi.c (function _lua_next)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
