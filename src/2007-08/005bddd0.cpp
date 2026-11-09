// from server: 100% by auto
// roc 2007-08 005bddd0  unit: RBX::VPVInstance::?$EnumPropDescriptor  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005bddd0
//
// 005bddd0  8b442408             mov eax, dword ptr [esp + 8]
// 005bddd4  56                   push esi
// 005bddd5  8b742408             mov esi, dword ptr [esp + 8]
// 005bddd9  8bce                 mov ecx, esi
// 005bdddb  e850f6ffff           call 0x5bd430
// 005bdde0  8b4e08               mov ecx, dword ptr [esi + 8]
// 005bdde3  83c1f0               add ecx, -0x10
// 005bdde6  51                   push ecx
// 005bdde7  51                   push ecx
// 005bdde8  50                   push eax
// 005bdde9  56                   push esi
// 005bddea  e861250500           call 0x610350
// 005bddef  83c410               add esp, 0x10
// 005bddf2  5e                   pop esi
// 005bddf3  c3                   ret 
// library lua-5.1/lapi.c (function _lua_gettable)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
