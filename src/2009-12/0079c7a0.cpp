// from server: 100% by auto
// roc 2009-12 0079c7a0  unit: seg_00790000  size: 40 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079c7a0
//
// 0079c7a0  56                   push esi
// 0079c7a1  8b742408             mov esi, dword ptr [esp + 8]
// 0079c7a5  6a01                 push 1
// 0079c7a7  56                   push esi
// 0079c7a8  e883e0feff           call 0x78a830
// 0079c7ad  dd1c24               fstp qword ptr [esp]
// 0079c7b0  e801890500           call 0x7f50b6
// 0079c7b5  dd1c24               fstp qword ptr [esp]
// 0079c7b8  56                   push esi
// 0079c7b9  e8a2c5feff           call 0x788d60
// 0079c7be  83c40c               add esp, 0xc
// 0079c7c1  b801000000           mov eax, 1
// 0079c7c6  5e                   pop esi
// 0079c7c7  c3                   ret 
// library lua-5.1/lmathlib.c (function _math_ceil)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lmathlib.c
