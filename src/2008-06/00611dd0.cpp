// from server: 100% by auto
// roc 2008-06 00611dd0  unit: seg_00610000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00611dd0
//
// 00611dd0  8b442408             mov eax, dword ptr [esp + 8]
// 00611dd4  56                   push esi
// 00611dd5  8b742408             mov esi, dword ptr [esp + 8]
// 00611dd9  8bce                 mov ecx, esi
// 00611ddb  e8b0fcffff           call 0x611a90
// 00611de0  8b10                 mov edx, dword ptr [eax]
// 00611de2  8b4e08               mov ecx, dword ptr [esi + 8]
// 00611de5  8911                 mov dword ptr [ecx], edx
// 00611de7  8b5004               mov edx, dword ptr [eax + 4]
// 00611dea  895104               mov dword ptr [ecx + 4], edx
// 00611ded  8b4008               mov eax, dword ptr [eax + 8]
// 00611df0  894108               mov dword ptr [ecx + 8], eax
// 00611df3  83460810             add dword ptr [esi + 8], 0x10
// 00611df7  5e                   pop esi
// 00611df8  c3                   ret 
// library lua-5.1/lapi.c (function _lua_pushvalue)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
