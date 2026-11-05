// from server: 100% by auto
// roc 2009-06 006b95a0  unit: RBX::UniversalTool  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006b95a0
//
// 006b95a0  8b442408             mov eax, dword ptr [esp + 8]
// 006b95a4  56                   push esi
// 006b95a5  8b742408             mov esi, dword ptr [esp + 8]
// 006b95a9  8bce                 mov ecx, esi
// 006b95ab  e820f6ffff           call 0x6b8bd0
// 006b95b0  8b4e08               mov ecx, dword ptr [esi + 8]
// 006b95b3  83c1f0               add ecx, -0x10
// 006b95b6  51                   push ecx
// 006b95b7  51                   push ecx
// 006b95b8  50                   push eax
// 006b95b9  56                   push esi
// 006b95ba  e8510b0300           call 0x6ea110
// 006b95bf  83c410               add esp, 0x10
// 006b95c2  5e                   pop esi
// 006b95c3  c3                   ret 
// library lua-5.1/lapi.c (function _lua_gettable)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
