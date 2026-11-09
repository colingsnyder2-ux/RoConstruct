// from server: 100% by auto
// roc 2011-06 007632e0  unit: seg_00760000  size: 16 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 007632e0
//
// 007632e0  8b442404             mov eax, dword ptr [esp + 4]
// 007632e4  50                   push eax
// 007632e5  e876a80100           call 0x77db60
// 007632ea  83c404               add esp, 4
// 007632ed  33c0                 xor eax, eax
// 007632ef  c3                   ret 
// library lua-5.1/lapi.c (function _lua_error)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
