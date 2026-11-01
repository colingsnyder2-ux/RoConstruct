// from server: 100% by auto
// roc 2007-03 005c69d0  unit: seg_005c0000  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c69d0
//
// 005c69d0  56                   push esi
// 005c69d1  8b742408             mov esi, dword ptr [esp + 8]
// 005c69d5  6a05                 push 5
// 005c69d7  6a01                 push 1
// 005c69d9  56                   push esi
// 005c69da  e8613bffff           call 0x5ba540
// 005c69df  6a02                 push 2
// 005c69e1  56                   push esi
// 005c69e2  e8a93bffff           call 0x5ba590
// 005c69e7  6a03                 push 3
// 005c69e9  56                   push esi
// 005c69ea  e8a13bffff           call 0x5ba590
// 005c69ef  6a03                 push 3
// 005c69f1  56                   push esi
// 005c69f2  e86920ffff           call 0x5b8a60
// 005c69f7  6a01                 push 1
// 005c69f9  56                   push esi
// 005c69fa  e8512bffff           call 0x5b9550
// 005c69ff  83c42c               add esp, 0x2c
// 005c6a02  b801000000           mov eax, 1
// 005c6a07  5e                   pop esi
// 005c6a08  c3                   ret 
// library lua-5.1.1/lbaselib.c (function _luaB_rawset)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lbaselib.c
