// from server: 100% by auto
// roc 2007-03 005c4200  unit: seg_005c0000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c4200
//
// 005c4200  56                   push esi
// 005c4201  8b742408             mov esi, dword ptr [esp + 8]
// 005c4205  6a01                 push 1
// 005c4207  56                   push esi
// 005c4208  e87364ffff           call 0x5ba680
// 005c420d  83c408               add esp, 8
// 005c4210  e8e3b60500           call 0x61f8f8
// 005c4215  83ec08               sub esp, 8
// 005c4218  dd1c24               fstp qword ptr [esp]
// 005c421b  56                   push esi
// 005c421c  e81f4effff           call 0x5b9040
// 005c4221  83c40c               add esp, 0xc
// 005c4224  b801000000           mov eax, 1
// 005c4229  5e                   pop esi
// 005c422a  c3                   ret 
// library lua-5.1.1/lmathlib.c (function _math_sin)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lmathlib.c
