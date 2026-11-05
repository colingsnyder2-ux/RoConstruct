// from server: 100% by auto
// roc 2009-12 0079c8a0  unit: seg_00790000  size: 67 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079c8a0
//
// 0079c8a0  83ec08               sub esp, 8
// 0079c8a3  56                   push esi
// 0079c8a4  8b742410             mov esi, dword ptr [esp + 0x10]
// 0079c8a8  6a01                 push 1
// 0079c8aa  56                   push esi
// 0079c8ab  e880dffeff           call 0x78a830
// 0079c8b0  dd5c240c             fstp qword ptr [esp + 0xc]
// 0079c8b4  6a02                 push 2
// 0079c8b6  56                   push esi
// 0079c8b7  e874dffeff           call 0x78a830
// 0079c8bc  dd442414             fld qword ptr [esp + 0x14]
// 0079c8c0  83c410               add esp, 0x10
// 0079c8c3  d9c9                 fxch st(1)
// 0079c8c5  e8e6870500           call 0x7f50b0
// 0079c8ca  83ec08               sub esp, 8
// 0079c8cd  dd1c24               fstp qword ptr [esp]
// 0079c8d0  56                   push esi
// 0079c8d1  e88ac4feff           call 0x788d60
// 0079c8d6  83c40c               add esp, 0xc
// 0079c8d9  b801000000           mov eax, 1
// 0079c8de  5e                   pop esi
// 0079c8df  83c408               add esp, 8
// 0079c8e2  c3                   ret 
// library lua-5.1/lmathlib.c (function _math_atan2)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lmathlib.c
