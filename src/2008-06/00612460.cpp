// from server: 100% by auto
// roc 2008-06 00612460  unit: seg_00610000  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00612460
//
// 00612460  8b442408             mov eax, dword ptr [esp + 8]
// 00612464  56                   push esi
// 00612465  8b742408             mov esi, dword ptr [esp + 8]
// 00612469  8bce                 mov ecx, esi
// 0061246b  e820f6ffff           call 0x611a90
// 00612470  8b4e08               mov ecx, dword ptr [esi + 8]
// 00612473  83c1f0               add ecx, -0x10
// 00612476  51                   push ecx
// 00612477  51                   push ecx
// 00612478  50                   push eax
// 00612479  56                   push esi
// 0061247a  e861a40400           call 0x65c8e0
// 0061247f  83c410               add esp, 0x10
// 00612482  5e                   pop esi
// 00612483  c3                   ret 
// library lua-5.1/lapi.c (function _lua_gettable)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
