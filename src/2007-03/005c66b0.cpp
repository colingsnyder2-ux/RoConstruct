// from server: 100% by auto
// roc 2007-03 005c66b0  unit: seg_005c0000  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c66b0
//
// 005c66b0  56                   push esi
// 005c66b1  8b742408             mov esi, dword ptr [esp + 8]
// 005c66b5  57                   push edi
// 005c66b6  6a01                 push 1
// 005c66b8  6a02                 push 2
// 005c66ba  56                   push esi
// 005c66bb  e8b040ffff           call 0x5ba770
// 005c66c0  6a01                 push 1
// 005c66c2  56                   push esi
// 005c66c3  8bf8                 mov edi, eax
// 005c66c5  e89623ffff           call 0x5b8a60
// 005c66ca  6a01                 push 1
// 005c66cc  56                   push esi
// 005c66cd  e81e26ffff           call 0x5b8cf0
// 005c66d2  83c41c               add esp, 0x1c
// 005c66d5  85c0                 test eax, eax
// 005c66d7  741e                 je 0x5c66f7
// 005c66d9  85ff                 test edi, edi
// 005c66db  7e1a                 jle 0x5c66f7
// 005c66dd  57                   push edi
// 005c66de  56                   push esi
// 005c66df  e8fc33ffff           call 0x5b9ae0
// 005c66e4  6a01                 push 1
// 005c66e6  56                   push esi
// 005c66e7  e82425ffff           call 0x5b8c10
// 005c66ec  6a02                 push 2
// 005c66ee  56                   push esi
// 005c66ef  e80c33ffff           call 0x5b9a00
// 005c66f4  83c418               add esp, 0x18
// 005c66f7  56                   push esi
// 005c66f8  e8b332ffff           call 0x5b99b0
// 005c66fd  83c404               add esp, 4
// 005c6700  5f                   pop edi
// 005c6701  5e                   pop esi
// 005c6702  c3                   ret 
// library lua-5.1.1/lbaselib.c (function _luaB_error)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lbaselib.c
