// from server: 100% by auto
// roc 2009-12 0079c550  unit: seg_00790000  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079c550
//
// 0079c550  56                   push esi
// 0079c551  8b742408             mov esi, dword ptr [esp + 8]
// 0079c555  6a01                 push 1
// 0079c557  56                   push esi
// 0079c558  e8d3e2feff           call 0x78a830
// 0079c55d  d9e1                 fabs 
// 0079c55f  dd1c24               fstp qword ptr [esp]
// 0079c562  56                   push esi
// 0079c563  e8f8c7feff           call 0x788d60
// 0079c568  83c40c               add esp, 0xc
// 0079c56b  b801000000           mov eax, 1
// 0079c570  5e                   pop esi
// 0079c571  c3                   ret 
// library lua-5.1/lmathlib.c (function _math_abs)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lmathlib.c
