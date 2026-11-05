// from server: 100% by auto
// roc 2012-06 00832310  unit: RBX::PAVPrimitive::$$A6AXU?$pair::?$signal::Vslot::?$callable  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00832310
//
// 00832310  8b442408             mov eax, dword ptr [esp + 8]
// 00832314  56                   push esi
// 00832315  8b742408             mov esi, dword ptr [esp + 8]
// 00832319  8bce                 mov ecx, esi
// 0083231b  e820f6ffff           call 0x831940
// 00832320  8b4e08               mov ecx, dword ptr [esi + 8]
// 00832323  83c1f0               add ecx, -0x10
// 00832326  51                   push ecx
// 00832327  51                   push ecx
// 00832328  50                   push eax
// 00832329  56                   push esi
// 0083232a  e8f1141000           call 0x933820
// 0083232f  83c410               add esp, 0x10
// 00832332  5e                   pop esi
// 00832333  c3                   ret 
// library lua-5.1/lapi.c (function _lua_gettable)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
