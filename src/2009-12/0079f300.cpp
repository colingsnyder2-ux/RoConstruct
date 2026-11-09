// from server: 100% by auto
// roc 2009-12 0079f300  unit: seg_00790000  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079f300
//
// 0079f300  56                   push esi
// 0079f301  8b742408             mov esi, dword ptr [esp + 8]
// 0079f305  6a01                 push 1
// 0079f307  56                   push esi
// 0079f308  e833b4feff           call 0x78a740
// 0079f30d  83c408               add esp, 8
// 0079f310  6a00                 push 0
// 0079f312  6aff                 push -1
// 0079f314  56                   push esi
// 0079f315  e88694feff           call 0x7887a0
// 0079f31a  83c404               add esp, 4
// 0079f31d  48                   dec eax
// 0079f31e  50                   push eax
// 0079f31f  56                   push esi
// 0079f320  e8fba1feff           call 0x789520
// 0079f325  33c9                 xor ecx, ecx
// 0079f327  85c0                 test eax, eax
// 0079f329  0f94c1               sete cl
// 0079f32c  51                   push ecx
// 0079f32d  56                   push esi
// 0079f32e  e81d9cfeff           call 0x788f50
// 0079f333  6a01                 push 1
// 0079f335  56                   push esi
// 0079f336  e81595feff           call 0x788850
// 0079f33b  56                   push esi
// 0079f33c  e85f94feff           call 0x7887a0
// 0079f341  83c424               add esp, 0x24
// 0079f344  5e                   pop esi
// 0079f345  c3                   ret 
// library lua-5.1/lbaselib.c (function _luaB_pcall)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lbaselib.c
