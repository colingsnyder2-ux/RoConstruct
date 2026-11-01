// from server: 100% by auto
// roc 2007-03 005c4290  unit: seg_005c0000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c4290
//
// 005c4290  56                   push esi
// 005c4291  8b742408             mov esi, dword ptr [esp + 8]
// 005c4295  6a01                 push 1
// 005c4297  56                   push esi
// 005c4298  e8e363ffff           call 0x5ba680
// 005c429d  83c408               add esp, 8
// 005c42a0  e873b50500           call 0x61f818
// 005c42a5  83ec08               sub esp, 8
// 005c42a8  dd1c24               fstp qword ptr [esp]
// 005c42ab  56                   push esi
// 005c42ac  e88f4dffff           call 0x5b9040
// 005c42b1  83c40c               add esp, 0xc
// 005c42b4  b801000000           mov eax, 1
// 005c42b9  5e                   pop esi
// 005c42ba  c3                   ret 
// library lua-5.1.1/lmathlib.c (function _math_sin)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lmathlib.c
