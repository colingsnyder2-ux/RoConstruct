// from server: 100% by auto
// roc 2007-03 005c73c0  unit: seg_005c0000  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c73c0
//
// 005c73c0  56                   push esi
// 005c73c1  8b742408             mov esi, dword ptr [esp + 8]
// 005c73c5  56                   push esi
// 005c73c6  e895ffffff           call 0x5c7360
// 005c73cb  6a01                 push 1
// 005c73cd  6800735c00           push 0x5c7300
// 005c73d2  56                   push esi
// 005c73d3  e8b81dffff           call 0x5b9190
// 005c73d8  83c410               add esp, 0x10
// 005c73db  b801000000           mov eax, 1
// 005c73e0  5e                   pop esi
// 005c73e1  c3                   ret 
// library lua-5.1.1/lbaselib.c (function _luaB_cowrap)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lbaselib.c
