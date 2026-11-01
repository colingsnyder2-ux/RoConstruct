// from server: 100% by auto
// roc 2007-03 005c41a0  unit: seg_005c0000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c41a0
//
// 005c41a0  56                   push esi
// 005c41a1  8b742408             mov esi, dword ptr [esp + 8]
// 005c41a5  6a01                 push 1
// 005c41a7  56                   push esi
// 005c41a8  e8d364ffff           call 0x5ba680
// 005c41ad  83c408               add esp, 8
// 005c41b0  e83db70500           call 0x61f8f2
// 005c41b5  83ec08               sub esp, 8
// 005c41b8  dd1c24               fstp qword ptr [esp]
// 005c41bb  56                   push esi
// 005c41bc  e87f4effff           call 0x5b9040
// 005c41c1  83c40c               add esp, 0xc
// 005c41c4  b801000000           mov eax, 1
// 005c41c9  5e                   pop esi
// 005c41ca  c3                   ret 
// library lua-5.1.1/lmathlib.c (function _math_sin)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lmathlib.c
