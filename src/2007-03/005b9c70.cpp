// from server: 100% by auto
// roc 2007-03 005b9c70  unit: seg_005b0000  size: 86 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005b9c70
//
// 005b9c70  56                   push esi
// 005b9c71  8b74240c             mov esi, dword ptr [esp + 0xc]
// 005b9c75  8d860f270000         lea eax, [esi + 0x270f]
// 005b9c7b  3d0f270000           cmp eax, 0x270f
// 005b9c80  57                   push edi
// 005b9c81  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 005b9c85  770d                 ja 0x5b9c94
// 005b9c87  57                   push edi
// 005b9c88  e8c3edffff           call 0x5b8a50
// 005b9c8d  83c404               add esp, 4
// 005b9c90  8d740601             lea esi, [esi + eax + 1]
// 005b9c94  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 005b9c98  51                   push ecx
// 005b9c99  56                   push esi
// 005b9c9a  57                   push edi
// 005b9c9b  e870ffffff           call 0x5b9c10
// 005b9ca0  83c40c               add esp, 0xc
// 005b9ca3  85c0                 test eax, eax
// 005b9ca5  7503                 jne 0x5b9caa
// 005b9ca7  5f                   pop edi
// 005b9ca8  5e                   pop esi
// 005b9ca9  c3                   ret 
// 005b9caa  56                   push esi
// 005b9cab  57                   push edi
// 005b9cac  e85fefffff           call 0x5b8c10
// 005b9cb1  6a01                 push 1
// 005b9cb3  6a01                 push 1
// 005b9cb5  57                   push edi
// 005b9cb6  e8a5faffff           call 0x5b9760
// 005b9cbb  83c414               add esp, 0x14
// 005b9cbe  5f                   pop edi
// 005b9cbf  b801000000           mov eax, 1
// 005b9cc4  5e                   pop esi
// 005b9cc5  c3                   ret 
// library lua-5.1.1/lauxlib.c (function _luaL_callmeta)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lauxlib.c
