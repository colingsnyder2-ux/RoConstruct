// from server: 100% by auto
// roc 2009-06 006b96b0  unit: RBX::UniversalTool  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006b96b0
//
// 006b96b0  56                   push esi
// 006b96b1  8b742408             mov esi, dword ptr [esp + 8]
// 006b96b5  8b4610               mov eax, dword ptr [esi + 0x10]
// 006b96b8  8b4844               mov ecx, dword ptr [eax + 0x44]
// 006b96bb  57                   push edi
// 006b96bc  3b4840               cmp ecx, dword ptr [eax + 0x40]
// 006b96bf  7209                 jb 0x6b96ca
// 006b96c1  56                   push esi
// 006b96c2  e8f9040300           call 0x6e9bc0
// 006b96c7  83c404               add esp, 4
// 006b96ca  8b542414             mov edx, dword ptr [esp + 0x14]
// 006b96ce  8b442410             mov eax, dword ptr [esp + 0x10]
// 006b96d2  8b7e08               mov edi, dword ptr [esi + 8]
// 006b96d5  52                   push edx
// 006b96d6  50                   push eax
// 006b96d7  56                   push esi
// 006b96d8  e8732a0300           call 0x6ec150
// 006b96dd  83c40c               add esp, 0xc
// 006b96e0  8907                 mov dword ptr [edi], eax
// 006b96e2  c7470805000000       mov dword ptr [edi + 8], 5
// 006b96e9  83460810             add dword ptr [esi + 8], 0x10
// 006b96ed  5f                   pop edi
// 006b96ee  5e                   pop esi
// 006b96ef  c3                   ret 
// library lua-5.1/lapi.c (function _lua_createtable)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
