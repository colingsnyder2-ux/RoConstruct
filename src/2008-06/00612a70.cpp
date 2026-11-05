// from server: 100% by auto
// roc 2008-06 00612a70  unit: seg_00610000  size: 9 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00612a70
//
// 00612a70  8b442404             mov eax, dword ptr [esp + 4]
// 00612a74  0fb64006             movzx eax, byte ptr [eax + 6]
// 00612a78  c3                   ret 
// library lua-5.1/lapi.c (function _lua_status)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
