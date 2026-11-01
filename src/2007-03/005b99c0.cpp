// from server: 100% by auto
// roc 2007-03 005b99c0  unit: seg_005b0000  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005b99c0
//
// 005b99c0  8b442408             mov eax, dword ptr [esp + 8]
// 005b99c4  56                   push esi
// 005b99c5  8b742408             mov esi, dword ptr [esp + 8]
// 005b99c9  8bce                 mov ecx, esi
// 005b99cb  e8e0eeffff           call 0x5b88b0
// 005b99d0  8b4e08               mov ecx, dword ptr [esi + 8]
// 005b99d3  8b10                 mov edx, dword ptr [eax]
// 005b99d5  83e910               sub ecx, 0x10
// 005b99d8  51                   push ecx
// 005b99d9  52                   push edx
// 005b99da  56                   push esi
// 005b99db  e8a01f0400           call 0x5fb980
// 005b99e0  83c40c               add esp, 0xc
// 005b99e3  85c0                 test eax, eax
// 005b99e5  7406                 je 0x5b99ed
// 005b99e7  83460810             add dword ptr [esi + 8], 0x10
// 005b99eb  5e                   pop esi
// 005b99ec  c3                   ret 
// 005b99ed  834608f0             add dword ptr [esi + 8], -0x10
// 005b99f1  5e                   pop esi
// 005b99f2  c3                   ret 
// library lua-5.1.1/lapi.c (function _lua_next)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lapi.c
