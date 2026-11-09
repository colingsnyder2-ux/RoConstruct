// from server: 100% by auto
// roc 2008-06 00612b70  unit: seg_00610000  size: 16 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00612b70
//
// 00612b70  8b442404             mov eax, dword ptr [esp + 4]
// 00612b74  50                   push eax
// 00612b75  e8c60b0100           call 0x623740
// 00612b7a  83c404               add esp, 4
// 00612b7d  33c0                 xor eax, eax
// 00612b7f  c3                   ret 
// library lua-5.1/lapi.c (function _lua_error)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
