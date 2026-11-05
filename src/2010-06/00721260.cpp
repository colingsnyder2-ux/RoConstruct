// from server: 100% by auto
// roc 2010-06 00721260  unit: RBX::UniversalTool  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00721260
//
// 00721260  8b442408             mov eax, dword ptr [esp + 8]
// 00721264  56                   push esi
// 00721265  8b742408             mov esi, dword ptr [esp + 8]
// 00721269  57                   push edi
// 0072126a  8bce                 mov ecx, esi
// 0072126c  e82ffbffff           call 0x720da0
// 00721271  8bf8                 mov edi, eax
// 00721273  8b442414             mov eax, dword ptr [esp + 0x14]
// 00721277  8bce                 mov ecx, esi
// 00721279  e822fbffff           call 0x720da0
// 0072127e  81ff78dca400         cmp edi, 0xa4dc78
// 00721284  7415                 je 0x72129b
// 00721286  3d78dca400           cmp eax, 0xa4dc78
// 0072128b  740e                 je 0x72129b
// 0072128d  50                   push eax
// 0072128e  57                   push edi
// 0072128f  56                   push esi
// 00721290  e8bba40500           call 0x77b750
// 00721295  83c40c               add esp, 0xc
// 00721298  5f                   pop edi
// 00721299  5e                   pop esi
// 0072129a  c3                   ret 
// 0072129b  5f                   pop edi
// 0072129c  33c0                 xor eax, eax
// 0072129e  5e                   pop esi
// 0072129f  c3                   ret 
// library lua-5.1/lapi.c (function _lua_lessthan)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
