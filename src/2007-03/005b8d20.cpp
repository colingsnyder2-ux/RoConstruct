// from server: 100% by auto
// roc 2007-03 005b8d20  unit: seg_005b0000  size: 63 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005b8d20
//
// 005b8d20  8b442408             mov eax, dword ptr [esp + 8]
// 005b8d24  56                   push esi
// 005b8d25  57                   push edi
// 005b8d26  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 005b8d2a  8bcf                 mov ecx, edi
// 005b8d2c  e87ffbffff           call 0x5b88b0
// 005b8d31  8bf0                 mov esi, eax
// 005b8d33  8b442414             mov eax, dword ptr [esp + 0x14]
// 005b8d37  8bcf                 mov ecx, edi
// 005b8d39  e872fbffff           call 0x5b88b0
// 005b8d3e  81fea0007c00         cmp esi, 0x7c00a0
// 005b8d44  7414                 je 0x5b8d5a
// 005b8d46  3da0007c00           cmp eax, 0x7c00a0
// 005b8d4b  740d                 je 0x5b8d5a
// 005b8d4d  50                   push eax
// 005b8d4e  56                   push esi
// 005b8d4f  e8dcf60300           call 0x5f8430
// 005b8d54  83c408               add esp, 8
// 005b8d57  5f                   pop edi
// 005b8d58  5e                   pop esi
// 005b8d59  c3                   ret 
// 005b8d5a  5f                   pop edi
// 005b8d5b  33c0                 xor eax, eax
// 005b8d5d  5e                   pop esi
// 005b8d5e  c3                   ret 
// library lua-5.1.1/lapi.c (function _lua_rawequal)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lapi.c
