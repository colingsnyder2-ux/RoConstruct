// from server: 100% by auto
// roc 2012-06 00832a80  unit: RBX::PAVPrimitive::$$A6AXU?$pair::?$signal::Vslot::?$callable  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00832a80
//
// 00832a80  8b442408             mov eax, dword ptr [esp + 8]
// 00832a84  56                   push esi
// 00832a85  8b742408             mov esi, dword ptr [esp + 8]
// 00832a89  8bce                 mov ecx, esi
// 00832a8b  e8b0eeffff           call 0x831940
// 00832a90  8b4e08               mov ecx, dword ptr [esi + 8]
// 00832a93  8b10                 mov edx, dword ptr [eax]
// 00832a95  83e910               sub ecx, 0x10
// 00832a98  51                   push ecx
// 00832a99  52                   push edx
// 00832a9a  56                   push esi
// 00832a9b  e8d02a1000           call 0x935570
// 00832aa0  83c40c               add esp, 0xc
// 00832aa3  85c0                 test eax, eax
// 00832aa5  7406                 je 0x832aad
// 00832aa7  83460810             add dword ptr [esi + 8], 0x10
// 00832aab  5e                   pop esi
// 00832aac  c3                   ret 
// 00832aad  834608f0             add dword ptr [esi + 8], -0x10
// 00832ab1  5e                   pop esi
// 00832ab2  c3                   ret 
// library lua-5.1/lapi.c (function _lua_next)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
