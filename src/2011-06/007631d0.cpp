// from server: 100% by auto
// roc 2011-06 007631d0  unit: seg_00760000  size: 9 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 007631d0
//
// 007631d0  8b442404             mov eax, dword ptr [esp + 4]
// 007631d4  0fb64006             movzx eax, byte ptr [eax + 6]
// 007631d8  c3                   ret 
// library lua-5.1/lapi.c (function _lua_status)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
