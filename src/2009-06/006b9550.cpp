// from server: 100% by auto
// roc 2009-06 006b9550  unit: RBX::UniversalTool  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006b9550
//
// 006b9550  8b442404             mov eax, dword ptr [esp + 4]
// 006b9554  8b4808               mov ecx, dword ptr [eax + 8]
// 006b9557  8b542408             mov edx, dword ptr [esp + 8]
// 006b955b  8911                 mov dword ptr [ecx], edx
// 006b955d  c7410802000000       mov dword ptr [ecx + 8], 2
// 006b9564  83400810             add dword ptr [eax + 8], 0x10
// 006b9568  c3                   ret 
// library lua-5.1/lapi.c (function _lua_pushlightuserdata)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
