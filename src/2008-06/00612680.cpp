// from server: 100% by auto
// roc 2008-06 00612680  unit: seg_00610000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00612680
//
// 00612680  8b442408             mov eax, dword ptr [esp + 8]
// 00612684  56                   push esi
// 00612685  8b742408             mov esi, dword ptr [esp + 8]
// 00612689  8bce                 mov ecx, esi
// 0061268b  e800f4ffff           call 0x611a90
// 00612690  8b4e08               mov ecx, dword ptr [esi + 8]
// 00612693  8d51f0               lea edx, [ecx - 0x10]
// 00612696  52                   push edx
// 00612697  83c1e0               add ecx, -0x20
// 0061269a  51                   push ecx
// 0061269b  50                   push eax
// 0061269c  56                   push esi
// 0061269d  e82ea30400           call 0x65c9d0
// 006126a2  834608e0             add dword ptr [esi + 8], -0x20
// 006126a6  83c410               add esp, 0x10
// 006126a9  5e                   pop esi
// 006126aa  c3                   ret 
// library lua-5.1/lapi.c (function _lua_settable)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
