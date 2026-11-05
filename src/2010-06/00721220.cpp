// from server: 100% by auto
// roc 2010-06 00721220  unit: RBX::UniversalTool  size: 63 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00721220
//
// 00721220  8b442408             mov eax, dword ptr [esp + 8]
// 00721224  56                   push esi
// 00721225  57                   push edi
// 00721226  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0072122a  8bcf                 mov ecx, edi
// 0072122c  e86ffbffff           call 0x720da0
// 00721231  8bf0                 mov esi, eax
// 00721233  8b442414             mov eax, dword ptr [esp + 0x14]
// 00721237  8bcf                 mov ecx, edi
// 00721239  e862fbffff           call 0x720da0
// 0072123e  81fe78dca400         cmp esi, 0xa4dc78
// 00721244  7414                 je 0x72125a
// 00721246  3d78dca400           cmp eax, 0xa4dc78
// 0072124b  740d                 je 0x72125a
// 0072124d  50                   push eax
// 0072124e  56                   push esi
// 0072124f  e83c170100           call 0x732990
// 00721254  83c408               add esp, 8
// 00721257  5f                   pop edi
// 00721258  5e                   pop esi
// 00721259  c3                   ret 
// 0072125a  5f                   pop edi
// 0072125b  33c0                 xor eax, eax
// 0072125d  5e                   pop esi
// 0072125e  c3                   ret 
// library lua-5.1/lapi.c (function _lua_rawequal)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
