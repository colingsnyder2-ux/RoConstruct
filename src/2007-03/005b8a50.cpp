// from server: 100% by auto
// roc 2007-03 005b8a50  unit: seg_005b0000  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005b8a50
//
// 005b8a50  8b4c2404             mov ecx, dword ptr [esp + 4]
// 005b8a54  8b4108               mov eax, dword ptr [ecx + 8]
// 005b8a57  2b410c               sub eax, dword ptr [ecx + 0xc]
// 005b8a5a  c1f804               sar eax, 4
// 005b8a5d  c3                   ret 
// library lua-5.1.1/lapi.c (function _lua_gettop)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lapi.c
