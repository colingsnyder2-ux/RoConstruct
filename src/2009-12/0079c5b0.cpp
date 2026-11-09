// from server: 100% by auto
// roc 2009-12 0079c5b0  unit: seg_00790000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079c5b0
//
// 0079c5b0  56                   push esi
// 0079c5b1  8b742408             mov esi, dword ptr [esp + 8]
// 0079c5b5  6a01                 push 1
// 0079c5b7  56                   push esi
// 0079c5b8  e873e2feff           call 0x78a830
// 0079c5bd  83c408               add esp, 8
// 0079c5c0  e8bd8d0500           call 0x7f5382
// 0079c5c5  83ec08               sub esp, 8
// 0079c5c8  dd1c24               fstp qword ptr [esp]
// 0079c5cb  56                   push esi
// 0079c5cc  e88fc7feff           call 0x788d60
// 0079c5d1  83c40c               add esp, 0xc
// 0079c5d4  b801000000           mov eax, 1
// 0079c5d9  5e                   pop esi
// 0079c5da  c3                   ret 
// library lua-5.1/lmathlib.c (function _math_sin)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lmathlib.c
