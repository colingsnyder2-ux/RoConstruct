// from server: 100% by auto
// roc 2007-03 005b8d60  unit: seg_005b0000  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005b8d60
//
// 005b8d60  8b442408             mov eax, dword ptr [esp + 8]
// 005b8d64  56                   push esi
// 005b8d65  8b742408             mov esi, dword ptr [esp + 8]
// 005b8d69  57                   push edi
// 005b8d6a  8bce                 mov ecx, esi
// 005b8d6c  e83ffbffff           call 0x5b88b0
// 005b8d71  8bf8                 mov edi, eax
// 005b8d73  8b442414             mov eax, dword ptr [esp + 0x14]
// 005b8d77  8bce                 mov ecx, esi
// 005b8d79  e832fbffff           call 0x5b88b0
// 005b8d7e  81ffa0007c00         cmp edi, 0x7c00a0
// 005b8d84  7415                 je 0x5b8d9b
// 005b8d86  3da0007c00           cmp eax, 0x7c00a0
// 005b8d8b  740e                 je 0x5b8d9b
// 005b8d8d  50                   push eax
// 005b8d8e  57                   push edi
// 005b8d8f  56                   push esi
// 005b8d90  e8fb120400           call 0x5fa090
// 005b8d95  83c40c               add esp, 0xc
// 005b8d98  5f                   pop edi
// 005b8d99  5e                   pop esi
// 005b8d9a  c3                   ret 
// 005b8d9b  5f                   pop edi
// 005b8d9c  33c0                 xor eax, eax
// 005b8d9e  5e                   pop esi
// 005b8d9f  c3                   ret 
// library lua-5.1.1/lapi.c (function _lua_lessthan)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lapi.c
