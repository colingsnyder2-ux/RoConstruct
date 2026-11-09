// from server: 100% by auto
// roc 2012-06 008323a0  unit: RBX::PAVPrimitive::$$A6AXU?$pair::?$signal::Vslot::?$callable  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008323a0
//
// 008323a0  8b442408             mov eax, dword ptr [esp + 8]
// 008323a4  56                   push esi
// 008323a5  8b742408             mov esi, dword ptr [esp + 8]
// 008323a9  8bce                 mov ecx, esi
// 008323ab  e890f5ffff           call 0x831940
// 008323b0  8b4e08               mov ecx, dword ptr [esi + 8]
// 008323b3  8b10                 mov edx, dword ptr [eax]
// 008323b5  83e910               sub ecx, 0x10
// 008323b8  51                   push ecx
// 008323b9  52                   push edx
// 008323ba  e801371000           call 0x935ac0
// 008323bf  8b4e08               mov ecx, dword ptr [esi + 8]
// 008323c2  8b10                 mov edx, dword ptr [eax]
// 008323c4  83e910               sub ecx, 0x10
// 008323c7  8911                 mov dword ptr [ecx], edx
// 008323c9  8b5004               mov edx, dword ptr [eax + 4]
// 008323cc  895104               mov dword ptr [ecx + 4], edx
// 008323cf  8b4008               mov eax, dword ptr [eax + 8]
// 008323d2  83c408               add esp, 8
// 008323d5  894108               mov dword ptr [ecx + 8], eax
// 008323d8  5e                   pop esi
// 008323d9  c3                   ret 
// library lua-5.1/lapi.c (function _lua_rawget)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
