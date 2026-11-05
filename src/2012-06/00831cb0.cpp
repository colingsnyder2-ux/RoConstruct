// from server: 100% by auto
// roc 2012-06 00831cb0  unit: RBX::PAVPrimitive::$$A6AXU?$pair::?$signal::Vslot::?$callable  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00831cb0
//
// 00831cb0  8b442408             mov eax, dword ptr [esp + 8]
// 00831cb4  56                   push esi
// 00831cb5  8b742408             mov esi, dword ptr [esp + 8]
// 00831cb9  8bce                 mov ecx, esi
// 00831cbb  e880fcffff           call 0x831940
// 00831cc0  8b10                 mov edx, dword ptr [eax]
// 00831cc2  8b4e08               mov ecx, dword ptr [esi + 8]
// 00831cc5  8911                 mov dword ptr [ecx], edx
// 00831cc7  8b5004               mov edx, dword ptr [eax + 4]
// 00831cca  895104               mov dword ptr [ecx + 4], edx
// 00831ccd  8b4008               mov eax, dword ptr [eax + 8]
// 00831cd0  894108               mov dword ptr [ecx + 8], eax
// 00831cd3  83460810             add dword ptr [esi + 8], 0x10
// 00831cd7  5e                   pop esi
// 00831cd8  c3                   ret 
// library lua-5.1/lapi.c (function _lua_pushvalue)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
