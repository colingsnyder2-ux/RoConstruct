// from server: 100% by auto
// roc 2007-03 005b94c0  unit: seg_005b0000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005b94c0
//
// 005b94c0  8b442408             mov eax, dword ptr [esp + 8]
// 005b94c4  56                   push esi
// 005b94c5  8b742408             mov esi, dword ptr [esp + 8]
// 005b94c9  8bce                 mov ecx, esi
// 005b94cb  e8e0f3ffff           call 0x5b88b0
// 005b94d0  8b4e08               mov ecx, dword ptr [esi + 8]
// 005b94d3  8d51f0               lea edx, [ecx - 0x10]
// 005b94d6  52                   push edx
// 005b94d7  83c1e0               add ecx, -0x20
// 005b94da  51                   push ecx
// 005b94db  50                   push eax
// 005b94dc  56                   push esi
// 005b94dd  e80e090400           call 0x5f9df0
// 005b94e2  834608e0             add dword ptr [esi + 8], -0x20
// 005b94e6  83c410               add esp, 0x10
// 005b94e9  5e                   pop esi
// 005b94ea  c3                   ret 
// library lua-5.1.1/lapi.c (function _lua_settable)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lapi.c
