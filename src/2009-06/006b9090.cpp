// from server: 100% by auto
// roc 2009-06 006b9090  unit: RBX::UniversalTool  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006b9090
//
// 006b9090  8b442408             mov eax, dword ptr [esp + 8]
// 006b9094  56                   push esi
// 006b9095  8b742408             mov esi, dword ptr [esp + 8]
// 006b9099  57                   push edi
// 006b909a  8bce                 mov ecx, esi
// 006b909c  e82ffbffff           call 0x6b8bd0
// 006b90a1  8bf8                 mov edi, eax
// 006b90a3  8b442414             mov eax, dword ptr [esp + 0x14]
// 006b90a7  8bce                 mov ecx, esi
// 006b90a9  e822fbffff           call 0x6b8bd0
// 006b90ae  81ff78c38e00         cmp edi, 0x8ec378
// 006b90b4  7415                 je 0x6b90cb
// 006b90b6  3d78c38e00           cmp eax, 0x8ec378
// 006b90bb  740e                 je 0x6b90cb
// 006b90bd  50                   push eax
// 006b90be  57                   push edi
// 006b90bf  56                   push esi
// 006b90c0  e8eb130300           call 0x6ea4b0
// 006b90c5  83c40c               add esp, 0xc
// 006b90c8  5f                   pop edi
// 006b90c9  5e                   pop esi
// 006b90ca  c3                   ret 
// 006b90cb  5f                   pop edi
// 006b90cc  33c0                 xor eax, eax
// 006b90ce  5e                   pop esi
// 006b90cf  c3                   ret 
// library lua-5.1/lapi.c (function _lua_lessthan)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
