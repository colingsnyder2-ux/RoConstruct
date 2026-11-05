// from server: 100% by auto
// roc 2009-06 006b9050  unit: RBX::UniversalTool  size: 63 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006b9050
//
// 006b9050  8b442408             mov eax, dword ptr [esp + 8]
// 006b9054  56                   push esi
// 006b9055  57                   push edi
// 006b9056  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 006b905a  8bcf                 mov ecx, edi
// 006b905c  e86ffbffff           call 0x6b8bd0
// 006b9061  8bf0                 mov esi, eax
// 006b9063  8b442414             mov eax, dword ptr [esp + 0x14]
// 006b9067  8bcf                 mov ecx, edi
// 006b9069  e862fbffff           call 0x6b8bd0
// 006b906e  81fe78c38e00         cmp esi, 0x8ec378
// 006b9074  7414                 je 0x6b908a
// 006b9076  3d78c38e00           cmp eax, 0x8ec378
// 006b907b  740d                 je 0x6b908a
// 006b907d  50                   push eax
// 006b907e  56                   push esi
// 006b907f  e8ccfb0000           call 0x6c8c50
// 006b9084  83c408               add esp, 8
// 006b9087  5f                   pop edi
// 006b9088  5e                   pop esi
// 006b9089  c3                   ret 
// 006b908a  5f                   pop edi
// 006b908b  33c0                 xor eax, eax
// 006b908d  5e                   pop esi
// 006b908e  c3                   ret 
// library lua-5.1/lapi.c (function _lua_rawequal)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
