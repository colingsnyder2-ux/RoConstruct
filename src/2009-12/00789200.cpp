// from server: 100% by auto
// roc 2009-12 00789200  unit: RBX::UniversalTool  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00789200
//
// 00789200  8b442408             mov eax, dword ptr [esp + 8]
// 00789204  56                   push esi
// 00789205  8b742408             mov esi, dword ptr [esp + 8]
// 00789209  8bce                 mov ecx, esi
// 0078920b  e8e0f3ffff           call 0x7885f0
// 00789210  8b4e08               mov ecx, dword ptr [esi + 8]
// 00789213  8d51f0               lea edx, [ecx - 0x10]
// 00789216  52                   push edx
// 00789217  83c1e0               add ecx, -0x20
// 0078921a  51                   push ecx
// 0078921b  50                   push eax
// 0078921c  56                   push esi
// 0078921d  e82e500400           call 0x7ce250
// 00789222  834608e0             add dword ptr [esi + 8], -0x20
// 00789226  83c410               add esp, 0x10
// 00789229  5e                   pop esi
// 0078922a  c3                   ret 
// library lua-5.1/lapi.c (function _lua_settable)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
