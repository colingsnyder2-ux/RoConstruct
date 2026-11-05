// from server: 100% by auto
// roc 2009-06 006b9d10  unit: RBX::UniversalTool  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006b9d10
//
// 006b9d10  8b442408             mov eax, dword ptr [esp + 8]
// 006b9d14  56                   push esi
// 006b9d15  8b742408             mov esi, dword ptr [esp + 8]
// 006b9d19  8bce                 mov ecx, esi
// 006b9d1b  e8b0eeffff           call 0x6b8bd0
// 006b9d20  8b4e08               mov ecx, dword ptr [esi + 8]
// 006b9d23  8b10                 mov edx, dword ptr [eax]
// 006b9d25  83e910               sub ecx, 0x10
// 006b9d28  51                   push ecx
// 006b9d29  52                   push edx
// 006b9d2a  56                   push esi
// 006b9d2b  e880200300           call 0x6ebdb0
// 006b9d30  83c40c               add esp, 0xc
// 006b9d33  85c0                 test eax, eax
// 006b9d35  7406                 je 0x6b9d3d
// 006b9d37  83460810             add dword ptr [esi + 8], 0x10
// 006b9d3b  5e                   pop esi
// 006b9d3c  c3                   ret 
// 006b9d3d  834608f0             add dword ptr [esi + 8], -0x10
// 006b9d41  5e                   pop esi
// 006b9d42  c3                   ret 
// library lua-5.1/lapi.c (function _lua_next)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
