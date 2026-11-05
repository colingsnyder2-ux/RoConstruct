// from server: 100% by auto
// roc 2009-12 0079f880  unit: seg_00790000  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079f880
//
// 0079f880  56                   push esi
// 0079f881  8b742408             mov esi, dword ptr [esp + 8]
// 0079f885  56                   push esi
// 0079f886  e8158ffeff           call 0x7887a0
// 0079f88b  50                   push eax
// 0079f88c  56                   push esi
// 0079f88d  e81e7effff           call 0x7976b0
// 0079f892  83c40c               add esp, 0xc
// 0079f895  5e                   pop esi
// 0079f896  c3                   ret 
// library lua-5.1/lbaselib.c (function _luaB_yield)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lbaselib.c
