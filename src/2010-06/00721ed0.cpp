// from server: 100% by auto
// roc 2010-06 00721ed0  unit: RBX::UniversalTool  size: 16 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00721ed0
//
// 00721ed0  8b442404             mov eax, dword ptr [esp + 4]
// 00721ed4  50                   push eax
// 00721ed5  e8361c0100           call 0x733b10
// 00721eda  83c404               add esp, 4
// 00721edd  33c0                 xor eax, eax
// 00721edf  c3                   ret 
// library lua-5.1/lapi.c (function _lua_error)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
