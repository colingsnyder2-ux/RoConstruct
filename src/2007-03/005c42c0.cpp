// from server: 100% by auto
// roc 2007-03 005c42c0  unit: seg_005c0000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c42c0
//
// 005c42c0  56                   push esi
// 005c42c1  8b742408             mov esi, dword ptr [esp + 8]
// 005c42c5  6a01                 push 1
// 005c42c7  56                   push esi
// 005c42c8  e8b363ffff           call 0x5ba680
// 005c42cd  83c408               add esp, 8
// 005c42d0  e84fb50500           call 0x61f824
// 005c42d5  83ec08               sub esp, 8
// 005c42d8  dd1c24               fstp qword ptr [esp]
// 005c42db  56                   push esi
// 005c42dc  e85f4dffff           call 0x5b9040
// 005c42e1  83c40c               add esp, 0xc
// 005c42e4  b801000000           mov eax, 1
// 005c42e9  5e                   pop esi
// 005c42ea  c3                   ret 
// library lua-5.1.1/lmathlib.c (function _math_sin)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lmathlib.c
