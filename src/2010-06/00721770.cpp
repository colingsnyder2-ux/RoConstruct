// from server: 100% by auto
// roc 2010-06 00721770  unit: RBX::UniversalTool  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00721770
//
// 00721770  8b442408             mov eax, dword ptr [esp + 8]
// 00721774  56                   push esi
// 00721775  8b742408             mov esi, dword ptr [esp + 8]
// 00721779  8bce                 mov ecx, esi
// 0072177b  e820f6ffff           call 0x720da0
// 00721780  8b4e08               mov ecx, dword ptr [esi + 8]
// 00721783  83c1f0               add ecx, -0x10
// 00721786  51                   push ecx
// 00721787  51                   push ecx
// 00721788  50                   push eax
// 00721789  56                   push esi
// 0072178a  e8219c0500           call 0x77b3b0
// 0072178f  83c410               add esp, 0x10
// 00721792  5e                   pop esi
// 00721793  c3                   ret 
// library lua-5.1/lapi.c (function _lua_gettable)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
