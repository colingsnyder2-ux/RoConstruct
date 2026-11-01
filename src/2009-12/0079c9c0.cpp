// from server: 100% by auto
// roc 2009-12 0079c9c0  unit: seg_00790000  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079c9c0
//
// 0079c9c0  56                   push esi
// 0079c9c1  8b742408             mov esi, dword ptr [esp + 8]
// 0079c9c5  6a01                 push 1
// 0079c9c7  56                   push esi
// 0079c9c8  e863defeff           call 0x78a830
// 0079c9cd  dc0d40af9e00         fmul qword ptr [0x9eaf40]
// 0079c9d3  dd1c24               fstp qword ptr [esp]
// 0079c9d6  56                   push esi
// 0079c9d7  e884c3feff           call 0x788d60
// 0079c9dc  83c40c               add esp, 0xc
// 0079c9df  b801000000           mov eax, 1
// 0079c9e4  5e                   pop esi
// 0079c9e5  c3                   ret 
// library lua-5.1/lmathlib.c (function _math_rad)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lmathlib.c
