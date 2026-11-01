// from server: 100% by auto
// roc 2007-03 005b8c10  unit: seg_005b0000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005b8c10
//
// 005b8c10  8b442408             mov eax, dword ptr [esp + 8]
// 005b8c14  56                   push esi
// 005b8c15  8b742408             mov esi, dword ptr [esp + 8]
// 005b8c19  8bce                 mov ecx, esi
// 005b8c1b  e890fcffff           call 0x5b88b0
// 005b8c20  8b10                 mov edx, dword ptr [eax]
// 005b8c22  8b4e08               mov ecx, dword ptr [esi + 8]
// 005b8c25  8911                 mov dword ptr [ecx], edx
// 005b8c27  8b5004               mov edx, dword ptr [eax + 4]
// 005b8c2a  895104               mov dword ptr [ecx + 4], edx
// 005b8c2d  8b4008               mov eax, dword ptr [eax + 8]
// 005b8c30  894108               mov dword ptr [ecx + 8], eax
// 005b8c33  83460810             add dword ptr [esi + 8], 0x10
// 005b8c37  5e                   pop esi
// 005b8c38  c3                   ret 
// library lua-5.1.1/lapi.c (function _lua_pushvalue)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lapi.c
