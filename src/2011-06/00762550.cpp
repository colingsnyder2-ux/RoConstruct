// from server: 100% by auto
// roc 2011-06 00762550  unit: seg_00760000  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00762550
//
// 00762550  8b442408             mov eax, dword ptr [esp + 8]
// 00762554  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00762558  e853fcffff           call 0x7621b0
// 0076255d  3db875ab00           cmp eax, 0xab75b8
// 00762562  7504                 jne 0x762568
// 00762564  83c8ff               or eax, 0xffffffff
// 00762567  c3                   ret 
// 00762568  8b4008               mov eax, dword ptr [eax + 8]
// 0076256b  c3                   ret 
// library lua-5.1/lapi.c (function _lua_type)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
