// from server: 100% by auto
// roc 2008-06 00611f20  unit: seg_00610000  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00611f20
//
// 00611f20  8b442408             mov eax, dword ptr [esp + 8]
// 00611f24  56                   push esi
// 00611f25  8b742408             mov esi, dword ptr [esp + 8]
// 00611f29  57                   push edi
// 00611f2a  8bce                 mov ecx, esi
// 00611f2c  e85ffbffff           call 0x611a90
// 00611f31  8bf8                 mov edi, eax
// 00611f33  8b442414             mov eax, dword ptr [esp + 0x14]
// 00611f37  8bce                 mov ecx, esi
// 00611f39  e852fbffff           call 0x611a90
// 00611f3e  81ff80488400         cmp edi, 0x844880
// 00611f44  7415                 je 0x611f5b
// 00611f46  3d80488400           cmp eax, 0x844880
// 00611f4b  740e                 je 0x611f5b
// 00611f4d  50                   push eax
// 00611f4e  57                   push edi
// 00611f4f  56                   push esi
// 00611f50  e80bad0400           call 0x65cc60
// 00611f55  83c40c               add esp, 0xc
// 00611f58  5f                   pop edi
// 00611f59  5e                   pop esi
// 00611f5a  c3                   ret 
// 00611f5b  5f                   pop edi
// 00611f5c  33c0                 xor eax, eax
// 00611f5e  5e                   pop esi
// 00611f5f  c3                   ret 
// library lua-5.1/lapi.c (function _lua_lessthan)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
