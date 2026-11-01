// from server: 100% by auto
// roc 2009-12 0079c6d0  unit: seg_00790000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079c6d0
//
// 0079c6d0  56                   push esi
// 0079c6d1  8b742408             mov esi, dword ptr [esp + 8]
// 0079c6d5  6a01                 push 1
// 0079c6d7  56                   push esi
// 0079c6d8  e853e1feff           call 0x78a830
// 0079c6dd  83c408               add esp, 8
// 0079c6e0  e8ad8b0500           call 0x7f5292
// 0079c6e5  83ec08               sub esp, 8
// 0079c6e8  dd1c24               fstp qword ptr [esp]
// 0079c6eb  56                   push esi
// 0079c6ec  e86fc6feff           call 0x788d60
// 0079c6f1  83c40c               add esp, 0xc
// 0079c6f4  b801000000           mov eax, 1
// 0079c6f9  5e                   pop esi
// 0079c6fa  c3                   ret 
// library lua-5.1/lmathlib.c (function _math_sin)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lmathlib.c
