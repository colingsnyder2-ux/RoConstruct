// from server: 100% by auto
// roc 2012-06 008323e0  unit: RBX::PAVPrimitive::$$A6AXU?$pair::?$signal::Vslot::?$callable  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008323e0
//
// 008323e0  8b442408             mov eax, dword ptr [esp + 8]
// 008323e4  56                   push esi
// 008323e5  8b742408             mov esi, dword ptr [esp + 8]
// 008323e9  8bce                 mov ecx, esi
// 008323eb  e850f5ffff           call 0x831940
// 008323f0  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 008323f4  8b10                 mov edx, dword ptr [eax]
// 008323f6  51                   push ecx
// 008323f7  52                   push edx
// 008323f8  e8e3351000           call 0x9359e0
// 008323fd  8b10                 mov edx, dword ptr [eax]
// 008323ff  8b4e08               mov ecx, dword ptr [esi + 8]
// 00832402  8911                 mov dword ptr [ecx], edx
// 00832404  8b5004               mov edx, dword ptr [eax + 4]
// 00832407  895104               mov dword ptr [ecx + 4], edx
// 0083240a  8b4008               mov eax, dword ptr [eax + 8]
// 0083240d  83c408               add esp, 8
// 00832410  894108               mov dword ptr [ecx + 8], eax
// 00832413  83460810             add dword ptr [esi + 8], 0x10
// 00832417  5e                   pop esi
// 00832418  c3                   ret 
// library lua-5.1/lapi.c (function _lua_rawgeti)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
