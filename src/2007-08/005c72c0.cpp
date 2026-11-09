// from server: 100% by auto
// roc 2007-08 005c72c0  unit: lua_exception  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005c72c0
//
// 005c72c0  8b442408             mov eax, dword ptr [esp + 8]
// 005c72c4  83780804             cmp dword ptr [eax + 8], 4
// 005c72c8  7504                 jne 0x5c72ce
// 005c72ca  8b44240c             mov eax, dword ptr [esp + 0xc]
// 005c72ce  c744240cc4977b00     mov dword ptr [esp + 0xc], 0x7b97c4
// 005c72d6  89442408             mov dword ptr [esp + 8], eax
// 005c72da  e951ffffff           jmp 0x5c7230
// library lua-5.1.2/ldebug.c (function _luaG_concaterror)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.2 ldebug.c
