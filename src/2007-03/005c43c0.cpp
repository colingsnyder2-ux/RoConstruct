// from server: 100% by auto
// roc 2007-03 005c43c0  unit: seg_005c0000  size: 67 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c43c0
//
// 005c43c0  83ec08               sub esp, 8
// 005c43c3  56                   push esi
// 005c43c4  8b742410             mov esi, dword ptr [esp + 0x10]
// 005c43c8  6a01                 push 1
// 005c43ca  56                   push esi
// 005c43cb  e8b062ffff           call 0x5ba680
// 005c43d0  dd5c240c             fstp qword ptr [esp + 0xc]
// 005c43d4  6a02                 push 2
// 005c43d6  56                   push esi
// 005c43d7  e8a462ffff           call 0x5ba680
// 005c43dc  dd442414             fld qword ptr [esp + 0x14]
// 005c43e0  83c410               add esp, 0x10
// 005c43e3  d9c9                 fxch st(1)
// 005c43e5  e81ab50500           call 0x61f904
// 005c43ea  83ec08               sub esp, 8
// 005c43ed  dd1c24               fstp qword ptr [esp]
// 005c43f0  56                   push esi
// 005c43f1  e84a4cffff           call 0x5b9040
// 005c43f6  83c40c               add esp, 0xc
// 005c43f9  b801000000           mov eax, 1
// 005c43fe  5e                   pop esi
// 005c43ff  83c408               add esp, 8
// 005c4402  c3                   ret 
// library lua-5.1.1/lmathlib.c (function _math_atan2)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lmathlib.c
