// from server: 100% by auto
// roc 2007-03 005b8f90  unit: seg_005b0000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005b8f90
//
// 005b8f90  8b442408             mov eax, dword ptr [esp + 8]
// 005b8f94  8b4c2404             mov ecx, dword ptr [esp + 4]
// 005b8f98  e813f9ffff           call 0x5b88b0
// 005b8f9d  83780808             cmp dword ptr [eax + 8], 8
// 005b8fa1  7403                 je 0x5b8fa6
// 005b8fa3  33c0                 xor eax, eax
// 005b8fa5  c3                   ret 
// 005b8fa6  8b00                 mov eax, dword ptr [eax]
// 005b8fa8  c3                   ret 
// library lua-5.1.1/lapi.c (function _lua_tothread)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lapi.c
