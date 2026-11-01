// from server: 100% by auto
// roc 2007-03 005c4260  unit: seg_005c0000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c4260
//
// 005c4260  56                   push esi
// 005c4261  8b742408             mov esi, dword ptr [esp + 8]
// 005c4265  6a01                 push 1
// 005c4267  56                   push esi
// 005c4268  e81364ffff           call 0x5ba680
// 005c426d  83c408               add esp, 8
// 005c4270  e889b60500           call 0x61f8fe
// 005c4275  83ec08               sub esp, 8
// 005c4278  dd1c24               fstp qword ptr [esp]
// 005c427b  56                   push esi
// 005c427c  e8bf4dffff           call 0x5b9040
// 005c4281  83c40c               add esp, 0xc
// 005c4284  b801000000           mov eax, 1
// 005c4289  5e                   pop esi
// 005c428a  c3                   ret 
// library lua-5.1.1/lmathlib.c (function _math_sin)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lmathlib.c
