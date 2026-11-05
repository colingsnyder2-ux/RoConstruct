// from server: 100% by auto
// roc 2011-06 00762360  unit: seg_00760000  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00762360
//
// 00762360  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00762364  8b4108               mov eax, dword ptr [ecx + 8]
// 00762367  2b410c               sub eax, dword ptr [ecx + 0xc]
// 0076236a  c1f804               sar eax, 4
// 0076236d  c3                   ret 
// library lua-5.1/lapi.c (function _lua_gettop)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
