// from server: 100% by auto
// roc 2009-12 0079f8a0  unit: seg_00790000  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079f8a0
//
// 0079f8a0  56                   push esi
// 0079f8a1  8b742408             mov esi, dword ptr [esp + 8]
// 0079f8a5  56                   push esi
// 0079f8a6  e8e596feff           call 0x788f90
// 0079f8ab  83c404               add esp, 4
// 0079f8ae  85c0                 test eax, eax
// 0079f8b0  7409                 je 0x79f8bb
// 0079f8b2  56                   push esi
// 0079f8b3  e88894feff           call 0x788d40
// 0079f8b8  83c404               add esp, 4
// 0079f8bb  b801000000           mov eax, 1
// 0079f8c0  5e                   pop esi
// 0079f8c1  c3                   ret 
// library lua-5.1.3/lbaselib.c (function _luaB_corunning)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.3 lbaselib.c
