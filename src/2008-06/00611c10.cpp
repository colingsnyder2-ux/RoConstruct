// from server: 100% by auto
// roc 2008-06 00611c10  unit: seg_00610000  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00611c10
//
// 00611c10  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00611c14  8b4108               mov eax, dword ptr [ecx + 8]
// 00611c17  2b410c               sub eax, dword ptr [ecx + 0xc]
// 00611c1a  c1f804               sar eax, 4
// 00611c1d  c3                   ret 
// library lua-5.1/lapi.c (function _lua_gettop)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
