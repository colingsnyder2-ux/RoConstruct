// from server: 100% by auto
// roc 2009-12 00789720  unit: RBX::UniversalTool  size: 16 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00789720
//
// 00789720  8b442404             mov eax, dword ptr [esp + 4]
// 00789724  50                   push eax
// 00789725  e8861b0100           call 0x79b2b0
// 0078972a  83c404               add esp, 4
// 0078972d  33c0                 xor eax, eax
// 0078972f  c3                   ret 
// library lua-5.1/lapi.c (function _lua_error)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
