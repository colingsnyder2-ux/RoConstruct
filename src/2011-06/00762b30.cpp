// from server: 100% by auto
// roc 2011-06 00762b30  unit: seg_00760000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00762b30
//
// 00762b30  8b442404             mov eax, dword ptr [esp + 4]
// 00762b34  8b4808               mov ecx, dword ptr [eax + 8]
// 00762b37  8b542408             mov edx, dword ptr [esp + 8]
// 00762b3b  8911                 mov dword ptr [ecx], edx
// 00762b3d  c7410802000000       mov dword ptr [ecx + 8], 2
// 00762b44  83400810             add dword ptr [eax + 8], 0x10
// 00762b48  c3                   ret 
// library lua-5.1/lapi.c (function _lua_pushlightuserdata)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
