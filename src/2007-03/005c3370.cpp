// from server: 100% by auto
// roc 2007-03 005c3370  unit: seg_005c0000  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c3370
//
// 005c3370  8b442408             mov eax, dword ptr [esp + 8]
// 005c3374  83780804             cmp dword ptr [eax + 8], 4
// 005c3378  7504                 jne 0x5c337e
// 005c337a  8b44240c             mov eax, dword ptr [esp + 0xc]
// 005c337e  c744240cb89a7b00     mov dword ptr [esp + 0xc], 0x7b9ab8
// 005c3386  89442408             mov dword ptr [esp + 8], eax
// 005c338a  e951ffffff           jmp 0x5c32e0
// library lua-5.1.1/ldebug.c (function _luaG_concaterror)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 ldebug.c
