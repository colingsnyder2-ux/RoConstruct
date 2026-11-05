// from server: 100% by auto
// roc 2008-06 00611e00  unit: seg_00610000  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00611e00
//
// 00611e00  8b442408             mov eax, dword ptr [esp + 8]
// 00611e04  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00611e08  e883fcffff           call 0x611a90
// 00611e0d  3d80488400           cmp eax, 0x844880
// 00611e12  7504                 jne 0x611e18
// 00611e14  83c8ff               or eax, 0xffffffff
// 00611e17  c3                   ret 
// 00611e18  8b4008               mov eax, dword ptr [eax + 8]
// 00611e1b  c3                   ret 
// library lua-5.1/lapi.c (function _lua_type)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
