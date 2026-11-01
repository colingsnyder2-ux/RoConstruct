// from server: 100% by auto
// roc 2007-03 005ba080  unit: seg_005b0000  size: 85 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005ba080
//
// 005ba080  53                   push ebx
// 005ba081  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 005ba085  85db                 test ebx, ebx
// 005ba087  7c4a                 jl 0x5ba0d3
// 005ba089  56                   push esi
// 005ba08a  8b742410             mov esi, dword ptr [esp + 0x10]
// 005ba08e  8d860f270000         lea eax, [esi + 0x270f]
// 005ba094  3d0f270000           cmp eax, 0x270f
// 005ba099  57                   push edi
// 005ba09a  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 005ba09e  770d                 ja 0x5ba0ad
// 005ba0a0  57                   push edi
// 005ba0a1  e8aae9ffff           call 0x5b8a50
// 005ba0a6  83c404               add esp, 4
// 005ba0a9  8d740601             lea esi, [esi + eax + 1]
// 005ba0ad  6a00                 push 0
// 005ba0af  56                   push esi
// 005ba0b0  57                   push edi
// 005ba0b1  e8baf2ffff           call 0x5b9370
// 005ba0b6  53                   push ebx
// 005ba0b7  56                   push esi
// 005ba0b8  57                   push edi
// 005ba0b9  e802f5ffff           call 0x5b95c0
// 005ba0be  53                   push ebx
// 005ba0bf  57                   push edi
// 005ba0c0  e89befffff           call 0x5b9060
// 005ba0c5  6a00                 push 0
// 005ba0c7  56                   push esi
// 005ba0c8  57                   push edi
// 005ba0c9  e8f2f4ffff           call 0x5b95c0
// 005ba0ce  83c42c               add esp, 0x2c
// 005ba0d1  5f                   pop edi
// 005ba0d2  5e                   pop esi
// 005ba0d3  5b                   pop ebx
// 005ba0d4  c3                   ret 
// library lua-5.1.1/lauxlib.c (function _luaL_unref)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lauxlib.c
