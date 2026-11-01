// from server: 100% by auto
// roc 2007-03 005b92a0  unit: seg_005b0000  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005b92a0
//
// 005b92a0  8b442408             mov eax, dword ptr [esp + 8]
// 005b92a4  56                   push esi
// 005b92a5  8b742408             mov esi, dword ptr [esp + 8]
// 005b92a9  8bce                 mov ecx, esi
// 005b92ab  e800f6ffff           call 0x5b88b0
// 005b92b0  8b4e08               mov ecx, dword ptr [esi + 8]
// 005b92b3  83c1f0               add ecx, -0x10
// 005b92b6  51                   push ecx
// 005b92b7  51                   push ecx
// 005b92b8  50                   push eax
// 005b92b9  56                   push esi
// 005b92ba  e8410a0400           call 0x5f9d00
// 005b92bf  83c410               add esp, 0x10
// 005b92c2  5e                   pop esi
// 005b92c3  c3                   ret 
// library lua-5.1.1/lapi.c (function _lua_gettable)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lapi.c
