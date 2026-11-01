// from server: 100% by auto
// roc 2009-12 0079c670  unit: seg_00790000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079c670
//
// 0079c670  56                   push esi
// 0079c671  8b742408             mov esi, dword ptr [esp + 8]
// 0079c675  6a01                 push 1
// 0079c677  56                   push esi
// 0079c678  e8b3e1feff           call 0x78a830
// 0079c67d  83c408               add esp, 8
// 0079c680  e8098d0500           call 0x7f538e
// 0079c685  83ec08               sub esp, 8
// 0079c688  dd1c24               fstp qword ptr [esp]
// 0079c68b  56                   push esi
// 0079c68c  e8cfc6feff           call 0x788d60
// 0079c691  83c40c               add esp, 0xc
// 0079c694  b801000000           mov eax, 1
// 0079c699  5e                   pop esi
// 0079c69a  c3                   ret 
// library lua-5.1/lmathlib.c (function _math_sin)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lmathlib.c
