// from server: 100% by auto
// roc 2009-12 0079c610  unit: seg_00790000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079c610
//
// 0079c610  56                   push esi
// 0079c611  8b742408             mov esi, dword ptr [esp + 8]
// 0079c615  6a01                 push 1
// 0079c617  56                   push esi
// 0079c618  e813e2feff           call 0x78a830
// 0079c61d  83c408               add esp, 8
// 0079c620  e8638d0500           call 0x7f5388
// 0079c625  83ec08               sub esp, 8
// 0079c628  dd1c24               fstp qword ptr [esp]
// 0079c62b  56                   push esi
// 0079c62c  e82fc7feff           call 0x788d60
// 0079c631  83c40c               add esp, 0xc
// 0079c634  b801000000           mov eax, 1
// 0079c639  5e                   pop esi
// 0079c63a  c3                   ret 
// library lua-5.1/lmathlib.c (function _math_sin)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lmathlib.c
