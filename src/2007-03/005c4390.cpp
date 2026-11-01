// from server: 100% by auto
// roc 2007-03 005c4390  unit: seg_005c0000  size: 40 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c4390
//
// 005c4390  56                   push esi
// 005c4391  8b742408             mov esi, dword ptr [esp + 8]
// 005c4395  6a01                 push 1
// 005c4397  56                   push esi
// 005c4398  e8e362ffff           call 0x5ba680
// 005c439d  dd1c24               fstp qword ptr [esp]
// 005c43a0  e823b20500           call 0x61f5c8
// 005c43a5  dd1c24               fstp qword ptr [esp]
// 005c43a8  56                   push esi
// 005c43a9  e8924cffff           call 0x5b9040
// 005c43ae  83c40c               add esp, 0xc
// 005c43b1  b801000000           mov eax, 1
// 005c43b6  5e                   pop esi
// 005c43b7  c3                   ret 
// library lua-5.1.1/lmathlib.c (function _math_ceil)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lmathlib.c
