// from server: 100% by auto
// roc 2007-03 005c45b0  unit: seg_005c0000  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c45b0
//
// 005c45b0  56                   push esi
// 005c45b1  8b742408             mov esi, dword ptr [esp + 8]
// 005c45b5  6a01                 push 1
// 005c45b7  56                   push esi
// 005c45b8  e8c360ffff           call 0x5ba680
// 005c45bd  dc0dd89d7b00         fmul qword ptr [0x7b9dd8]
// 005c45c3  dd1c24               fstp qword ptr [esp]
// 005c45c6  56                   push esi
// 005c45c7  e8744affff           call 0x5b9040
// 005c45cc  83c40c               add esp, 0xc
// 005c45cf  b801000000           mov eax, 1
// 005c45d4  5e                   pop esi
// 005c45d5  c3                   ret 
// library lua-5.1.1/lmathlib.c (function _math_rad)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lmathlib.c
