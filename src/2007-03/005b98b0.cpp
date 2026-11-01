// from server: 100% by auto
// roc 2007-03 005b98b0  unit: seg_005b0000  size: 9 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005b98b0
//
// 005b98b0  8b442404             mov eax, dword ptr [esp + 4]
// 005b98b4  0fb64006             movzx eax, byte ptr [eax + 6]
// 005b98b8  c3                   ret 
// library lua-5.1.1/lapi.c (function _lua_status)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lapi.c
