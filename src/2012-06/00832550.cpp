// from server: 100% by auto
// roc 2012-06 00832550  unit: RBX::PAVPrimitive::$$A6AXU?$pair::?$signal::Vslot::?$callable  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00832550
//
// 00832550  8b442408             mov eax, dword ptr [esp + 8]
// 00832554  56                   push esi
// 00832555  8b742408             mov esi, dword ptr [esp + 8]
// 00832559  8bce                 mov ecx, esi
// 0083255b  e8e0f3ffff           call 0x831940
// 00832560  8b4e08               mov ecx, dword ptr [esi + 8]
// 00832563  8d51f0               lea edx, [ecx - 0x10]
// 00832566  52                   push edx
// 00832567  83c1e0               add ecx, -0x20
// 0083256a  51                   push ecx
// 0083256b  50                   push eax
// 0083256c  56                   push esi
// 0083256d  e89e131000           call 0x933910
// 00832572  834608e0             add dword ptr [esi + 8], -0x20
// 00832576  83c410               add esp, 0x10
// 00832579  5e                   pop esi
// 0083257a  c3                   ret 
// library lua-5.1/lapi.c (function _lua_settable)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
