// from server: 100% by auto
// roc 2007-03 005b99b0  unit: seg_005b0000  size: 16 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005b99b0
//
// 005b99b0  8b442404             mov eax, dword ptr [esp + 4]
// 005b99b4  50                   push eax
// 005b99b5  e866960000           call 0x5c3020
// 005b99ba  83c404               add esp, 4
// 005b99bd  33c0                 xor eax, eax
// 005b99bf  c3                   ret 
// library lua-5.1.1/lapi.c (function _lua_error)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lapi.c
