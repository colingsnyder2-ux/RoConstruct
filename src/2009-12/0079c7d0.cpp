// from server: 100% by auto
// roc 2009-12 0079c7d0  unit: seg_00790000  size: 67 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079c7d0
//
// 0079c7d0  83ec08               sub esp, 8
// 0079c7d3  56                   push esi
// 0079c7d4  8b742410             mov esi, dword ptr [esp + 0x10]
// 0079c7d8  6a01                 push 1
// 0079c7da  56                   push esi
// 0079c7db  e850e0feff           call 0x78a830
// 0079c7e0  dd5c240c             fstp qword ptr [esp + 0xc]
// 0079c7e4  6a02                 push 2
// 0079c7e6  56                   push esi
// 0079c7e7  e844e0feff           call 0x78a830
// 0079c7ec  dd442414             fld qword ptr [esp + 0x14]
// 0079c7f0  83c410               add esp, 0x10
// 0079c7f3  d9c9                 fxch st(1)
// 0079c7f5  e89a8b0500           call 0x7f5394
// 0079c7fa  83ec08               sub esp, 8
// 0079c7fd  dd1c24               fstp qword ptr [esp]
// 0079c800  56                   push esi
// 0079c801  e85ac5feff           call 0x788d60
// 0079c806  83c40c               add esp, 0xc
// 0079c809  b801000000           mov eax, 1
// 0079c80e  5e                   pop esi
// 0079c80f  83c408               add esp, 8
// 0079c812  c3                   ret 
// library lua-5.1/lmathlib.c (function _math_atan2)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lmathlib.c
