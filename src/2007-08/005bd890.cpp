// from server: 100% by auto
// roc 2007-08 005bd890  unit: RBX::VPVInstance::?$EnumPropDescriptor  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005bd890
//
// 005bd890  8b442408             mov eax, dword ptr [esp + 8]
// 005bd894  56                   push esi
// 005bd895  8b742408             mov esi, dword ptr [esp + 8]
// 005bd899  57                   push edi
// 005bd89a  8bce                 mov ecx, esi
// 005bd89c  e88ffbffff           call 0x5bd430
// 005bd8a1  8bf8                 mov edi, eax
// 005bd8a3  8b442414             mov eax, dword ptr [esp + 0x14]
// 005bd8a7  8bce                 mov ecx, esi
// 005bd8a9  e882fbffff           call 0x5bd430
// 005bd8ae  81ffe82f7c00         cmp edi, 0x7c2fe8
// 005bd8b4  7415                 je 0x5bd8cb
// 005bd8b6  3de82f7c00           cmp eax, 0x7c2fe8
// 005bd8bb  740e                 je 0x5bd8cb
// 005bd8bd  50                   push eax
// 005bd8be  57                   push edi
// 005bd8bf  56                   push esi
// 005bd8c0  e81b2e0500           call 0x6106e0
// 005bd8c5  83c40c               add esp, 0xc
// 005bd8c8  5f                   pop edi
// 005bd8c9  5e                   pop esi
// 005bd8ca  c3                   ret 
// 005bd8cb  5f                   pop edi
// 005bd8cc  33c0                 xor eax, eax
// 005bd8ce  5e                   pop esi
// 005bd8cf  c3                   ret 
// library lua-5.1/lapi.c (function _lua_lessthan)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
