// from server: 100% by auto
// roc 2007-03 005b9250  unit: seg_005b0000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005b9250
//
// 005b9250  8b442404             mov eax, dword ptr [esp + 4]
// 005b9254  8b4808               mov ecx, dword ptr [eax + 8]
// 005b9257  8b542408             mov edx, dword ptr [esp + 8]
// 005b925b  8911                 mov dword ptr [ecx], edx
// 005b925d  c7410802000000       mov dword ptr [ecx + 8], 2
// 005b9264  83400810             add dword ptr [eax + 8], 0x10
// 005b9268  c3                   ret 
// library lua-5.1.1/lapi.c (function _lua_pushlightuserdata)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lapi.c
