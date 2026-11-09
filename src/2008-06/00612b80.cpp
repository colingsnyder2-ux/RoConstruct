// from server: 100% by auto
// roc 2008-06 00612b80  unit: seg_00610000  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00612b80
//
// 00612b80  8b442408             mov eax, dword ptr [esp + 8]
// 00612b84  56                   push esi
// 00612b85  8b742408             mov esi, dword ptr [esp + 8]
// 00612b89  8bce                 mov ecx, esi
// 00612b8b  e800efffff           call 0x611a90
// 00612b90  8b4e08               mov ecx, dword ptr [esi + 8]
// 00612b93  8b10                 mov edx, dword ptr [eax]
// 00612b95  83e910               sub ecx, 0x10
// 00612b98  51                   push ecx
// 00612b99  52                   push edx
// 00612b9a  56                   push esi
// 00612b9b  e8d0b90400           call 0x65e570
// 00612ba0  83c40c               add esp, 0xc
// 00612ba3  85c0                 test eax, eax
// 00612ba5  7406                 je 0x612bad
// 00612ba7  83460810             add dword ptr [esi + 8], 0x10
// 00612bab  5e                   pop esi
// 00612bac  c3                   ret 
// 00612bad  834608f0             add dword ptr [esi + 8], -0x10
// 00612bb1  5e                   pop esi
// 00612bb2  c3                   ret 
// library lua-5.1/lapi.c (function _lua_next)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
