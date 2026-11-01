// from server: 100% by auto
// roc 2007-03 005c4490  unit: seg_005c0000  size: 67 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c4490
//
// 005c4490  83ec08               sub esp, 8
// 005c4493  56                   push esi
// 005c4494  8b742410             mov esi, dword ptr [esp + 0x10]
// 005c4498  6a01                 push 1
// 005c449a  56                   push esi
// 005c449b  e8e061ffff           call 0x5ba680
// 005c44a0  dd5c240c             fstp qword ptr [esp + 0xc]
// 005c44a4  6a02                 push 2
// 005c44a6  56                   push esi
// 005c44a7  e8d461ffff           call 0x5ba680
// 005c44ac  dd442414             fld qword ptr [esp + 0x14]
// 005c44b0  83c410               add esp, 0x10
// 005c44b3  d9c9                 fxch st(1)
// 005c44b5  e884b10500           call 0x61f63e
// 005c44ba  83ec08               sub esp, 8
// 005c44bd  dd1c24               fstp qword ptr [esp]
// 005c44c0  56                   push esi
// 005c44c1  e87a4bffff           call 0x5b9040
// 005c44c6  83c40c               add esp, 0xc
// 005c44c9  b801000000           mov eax, 1
// 005c44ce  5e                   pop esi
// 005c44cf  83c408               add esp, 8
// 005c44d2  c3                   ret 
// library lua-5.1.1/lmathlib.c (function _math_atan2)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lmathlib.c
