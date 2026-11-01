// from server: 100% by auto
// roc 2007-03 005b93b0  unit: seg_005b0000  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005b93b0
//
// 005b93b0  56                   push esi
// 005b93b1  8b742408             mov esi, dword ptr [esp + 8]
// 005b93b5  8b4610               mov eax, dword ptr [esi + 0x10]
// 005b93b8  8b4844               mov ecx, dword ptr [eax + 0x44]
// 005b93bb  3b4840               cmp ecx, dword ptr [eax + 0x40]
// 005b93be  57                   push edi
// 005b93bf  7209                 jb 0x5b93ca
// 005b93c1  56                   push esi
// 005b93c2  e8e9030400           call 0x5f97b0
// 005b93c7  83c404               add esp, 4
// 005b93ca  8b542414             mov edx, dword ptr [esp + 0x14]
// 005b93ce  8b442410             mov eax, dword ptr [esp + 0x10]
// 005b93d2  8b7e08               mov edi, dword ptr [esi + 8]
// 005b93d5  52                   push edx
// 005b93d6  50                   push eax
// 005b93d7  56                   push esi
// 005b93d8  e853290400           call 0x5fbd30
// 005b93dd  83c40c               add esp, 0xc
// 005b93e0  8907                 mov dword ptr [edi], eax
// 005b93e2  c7470805000000       mov dword ptr [edi + 8], 5
// 005b93e9  83460810             add dword ptr [esi + 8], 0x10
// 005b93ed  5f                   pop edi
// 005b93ee  5e                   pop esi
// 005b93ef  c3                   ret 
// library lua-5.1.1/lapi.c (function _lua_createtable)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lapi.c
