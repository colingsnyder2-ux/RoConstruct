// from server: 100% by auto
// roc 2007-03 005b9c10  unit: seg_005b0000  size: 90 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005b9c10
//
// 005b9c10  8b442408             mov eax, dword ptr [esp + 8]
// 005b9c14  56                   push esi
// 005b9c15  8b742408             mov esi, dword ptr [esp + 8]
// 005b9c19  50                   push eax
// 005b9c1a  56                   push esi
// 005b9c1b  e8d0f7ffff           call 0x5b93f0
// 005b9c20  83c408               add esp, 8
// 005b9c23  85c0                 test eax, eax
// 005b9c25  742d                 je 0x5b9c54
// 005b9c27  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005b9c2b  51                   push ecx
// 005b9c2c  56                   push esi
// 005b9c2d  e88ef4ffff           call 0x5b90c0
// 005b9c32  6afe                 push -2
// 005b9c34  56                   push esi
// 005b9c35  e8f6f6ffff           call 0x5b9330
// 005b9c3a  6aff                 push -1
// 005b9c3c  56                   push esi
// 005b9c3d  e8feefffff           call 0x5b8c40
// 005b9c42  83c418               add esp, 0x18
// 005b9c45  85c0                 test eax, eax
// 005b9c47  750f                 jne 0x5b9c58
// 005b9c49  6afd                 push -3
// 005b9c4b  56                   push esi
// 005b9c4c  e80feeffff           call 0x5b8a60
// 005b9c51  83c408               add esp, 8
// 005b9c54  33c0                 xor eax, eax
// 005b9c56  5e                   pop esi
// 005b9c57  c3                   ret 
// 005b9c58  6afe                 push -2
// 005b9c5a  56                   push esi
// 005b9c5b  e850eeffff           call 0x5b8ab0
// 005b9c60  83c408               add esp, 8
// 005b9c63  b801000000           mov eax, 1
// 005b9c68  5e                   pop esi
// 005b9c69  c3                   ret 
// library lua-5.1.1/lauxlib.c (function _luaL_getmetafield)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lauxlib.c
