// from server: 100% by auto
// roc 2008-06 00623a90  unit: lua_exception  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00623a90
//
// 00623a90  8b442408             mov eax, dword ptr [esp + 8]
// 00623a94  83780804             cmp dword ptr [eax + 8], 4
// 00623a98  7504                 jne 0x623a9e
// 00623a9a  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00623a9e  c744240c5c4a8400     mov dword ptr [esp + 0xc], 0x844a5c
// 00623aa6  89442408             mov dword ptr [esp + 8], eax
// 00623aaa  e951ffffff           jmp 0x623a00
// library lua-5.1.2/ldebug.c (function _luaG_concaterror)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.2 ldebug.c
