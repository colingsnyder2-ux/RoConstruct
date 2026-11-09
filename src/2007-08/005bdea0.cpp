// from server: 100% by auto
// roc 2007-08 005bdea0  unit: RBX::VPVInstance::?$EnumPropDescriptor  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005bdea0
//
// 005bdea0  8b442408             mov eax, dword ptr [esp + 8]
// 005bdea4  56                   push esi
// 005bdea5  8b742408             mov esi, dword ptr [esp + 8]
// 005bdea9  8bce                 mov ecx, esi
// 005bdeab  e880f5ffff           call 0x5bd430
// 005bdeb0  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005bdeb4  8b10                 mov edx, dword ptr [eax]
// 005bdeb6  51                   push ecx
// 005bdeb7  52                   push edx
// 005bdeb8  e883450500           call 0x612440
// 005bdebd  8b10                 mov edx, dword ptr [eax]
// 005bdebf  8b4e08               mov ecx, dword ptr [esi + 8]
// 005bdec2  8911                 mov dword ptr [ecx], edx
// 005bdec4  8b5004               mov edx, dword ptr [eax + 4]
// 005bdec7  895104               mov dword ptr [ecx + 4], edx
// 005bdeca  8b4008               mov eax, dword ptr [eax + 8]
// 005bdecd  83c408               add esp, 8
// 005bded0  894108               mov dword ptr [ecx + 8], eax
// 005bded3  83460810             add dword ptr [esi + 8], 0x10
// 005bded7  5e                   pop esi
// 005bded8  c3                   ret 
// library lua-5.1/lapi.c (function _lua_rawgeti)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
