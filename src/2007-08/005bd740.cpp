// from server: 100% by auto
// roc 2007-08 005bd740  unit: RBX::VPVInstance::?$EnumPropDescriptor  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005bd740
//
// 005bd740  8b442408             mov eax, dword ptr [esp + 8]
// 005bd744  56                   push esi
// 005bd745  8b742408             mov esi, dword ptr [esp + 8]
// 005bd749  8bce                 mov ecx, esi
// 005bd74b  e8e0fcffff           call 0x5bd430
// 005bd750  8b10                 mov edx, dword ptr [eax]
// 005bd752  8b4e08               mov ecx, dword ptr [esi + 8]
// 005bd755  8911                 mov dword ptr [ecx], edx
// 005bd757  8b5004               mov edx, dword ptr [eax + 4]
// 005bd75a  895104               mov dword ptr [ecx + 4], edx
// 005bd75d  8b4008               mov eax, dword ptr [eax + 8]
// 005bd760  894108               mov dword ptr [ecx + 8], eax
// 005bd763  83460810             add dword ptr [esi + 8], 0x10
// 005bd767  5e                   pop esi
// 005bd768  c3                   ret 
// library lua-5.1/lapi.c (function _lua_pushvalue)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
