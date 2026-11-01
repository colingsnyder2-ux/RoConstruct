// from server: 100% by auto
// roc 2007-03 005ba770  unit: seg_005b0000  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005ba770
//
// 005ba770  56                   push esi
// 005ba771  8b74240c             mov esi, dword ptr [esp + 0xc]
// 005ba775  57                   push edi
// 005ba776  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 005ba77a  56                   push esi
// 005ba77b  57                   push edi
// 005ba77c  e8bfe4ffff           call 0x5b8c40
// 005ba781  83c408               add esp, 8
// 005ba784  85c0                 test eax, eax
// 005ba786  7f07                 jg 0x5ba78f
// 005ba788  8b442414             mov eax, dword ptr [esp + 0x14]
// 005ba78c  5f                   pop edi
// 005ba78d  5e                   pop esi
// 005ba78e  c3                   ret 
// 005ba78f  56                   push esi
// 005ba790  57                   push edi
// 005ba791  e86affffff           call 0x5ba700
// 005ba796  83c408               add esp, 8
// 005ba799  5f                   pop edi
// 005ba79a  5e                   pop esi
// 005ba79b  c3                   ret 
// library lua-5.1.1/lauxlib.c (function _luaL_optinteger)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lauxlib.c
