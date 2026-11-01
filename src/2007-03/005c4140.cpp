// from server: 100% by auto
// roc 2007-03 005c4140  unit: seg_005c0000  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c4140
//
// 005c4140  56                   push esi
// 005c4141  8b742408             mov esi, dword ptr [esp + 8]
// 005c4145  6a01                 push 1
// 005c4147  56                   push esi
// 005c4148  e83365ffff           call 0x5ba680
// 005c414d  d9e1                 fabs 
// 005c414f  dd1c24               fstp qword ptr [esp]
// 005c4152  56                   push esi
// 005c4153  e8e84effff           call 0x5b9040
// 005c4158  83c40c               add esp, 0xc
// 005c415b  b801000000           mov eax, 1
// 005c4160  5e                   pop esi
// 005c4161  c3                   ret 
// library lua-5.1.1/lmathlib.c (function _math_abs)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lmathlib.c
