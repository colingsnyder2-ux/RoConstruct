// from server: 100% by auto
// roc 2009-06 006b9d00  unit: RBX::UniversalTool  size: 16 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006b9d00
//
// 006b9d00  8b442404             mov eax, dword ptr [esp + 4]
// 006b9d04  50                   push eax
// 006b9d05  e8a6ea0000           call 0x6c87b0
// 006b9d0a  83c404               add esp, 4
// 006b9d0d  33c0                 xor eax, eax
// 006b9d0f  c3                   ret 
// library lua-5.1/lapi.c (function _lua_error)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
