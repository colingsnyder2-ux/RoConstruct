// from server: 100% by auto
// roc 2007-03 005b9b50  unit: seg_005b0000  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005b9b50
//
// 005b9b50  56                   push esi
// 005b9b51  8b742408             mov esi, dword ptr [esp + 8]
// 005b9b55  6a01                 push 1
// 005b9b57  56                   push esi
// 005b9b58  e883ffffff           call 0x5b9ae0
// 005b9b5d  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 005b9b61  8d442418             lea eax, [esp + 0x18]
// 005b9b65  50                   push eax
// 005b9b66  51                   push ecx
// 005b9b67  56                   push esi
// 005b9b68  e8c3f5ffff           call 0x5b9130
// 005b9b6d  6a02                 push 2
// 005b9b6f  56                   push esi
// 005b9b70  e88bfeffff           call 0x5b9a00
// 005b9b75  56                   push esi
// 005b9b76  e835feffff           call 0x5b99b0
// 005b9b7b  83c420               add esp, 0x20
// 005b9b7e  5e                   pop esi
// 005b9b7f  c3                   ret 
// library lua-5.1.1/lauxlib.c (function _luaL_error)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lauxlib.c
