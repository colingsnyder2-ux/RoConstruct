// from server: 100% by auto
// roc 2009-12 00789db0  unit: RBX::UniversalTool  size: 90 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00789db0
//
// 00789db0  8b442408             mov eax, dword ptr [esp + 8]
// 00789db4  56                   push esi
// 00789db5  8b742408             mov esi, dword ptr [esp + 8]
// 00789db9  50                   push eax
// 00789dba  56                   push esi
// 00789dbb  e870f3ffff           call 0x789130
// 00789dc0  83c408               add esp, 8
// 00789dc3  85c0                 test eax, eax
// 00789dc5  742d                 je 0x789df4
// 00789dc7  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00789dcb  51                   push ecx
// 00789dcc  56                   push esi
// 00789dcd  e80ef0ffff           call 0x788de0
// 00789dd2  6afe                 push -2
// 00789dd4  56                   push esi
// 00789dd5  e876f2ffff           call 0x789050
// 00789dda  6aff                 push -1
// 00789ddc  56                   push esi
// 00789ddd  e8aeebffff           call 0x788990
// 00789de2  83c418               add esp, 0x18
// 00789de5  85c0                 test eax, eax
// 00789de7  750f                 jne 0x789df8
// 00789de9  6afd                 push -3
// 00789deb  56                   push esi
// 00789dec  e8bfe9ffff           call 0x7887b0
// 00789df1  83c408               add esp, 8
// 00789df4  33c0                 xor eax, eax
// 00789df6  5e                   pop esi
// 00789df7  c3                   ret 
// 00789df8  6afe                 push -2
// 00789dfa  56                   push esi
// 00789dfb  e800eaffff           call 0x788800
// 00789e00  83c408               add esp, 8
// 00789e03  b801000000           mov eax, 1
// 00789e08  5e                   pop esi
// 00789e09  c3                   ret 
// library lua-5.1/lauxlib.c (function _luaL_getmetafield)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lauxlib.c
