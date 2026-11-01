// from server: 100% by auto
// roc 2007-03 005b9080  unit: seg_005b0000  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005b9080
//
// 005b9080  56                   push esi
// 005b9081  8b742408             mov esi, dword ptr [esp + 8]
// 005b9085  8b4610               mov eax, dword ptr [esi + 0x10]
// 005b9088  8b4844               mov ecx, dword ptr [eax + 0x44]
// 005b908b  3b4840               cmp ecx, dword ptr [eax + 0x40]
// 005b908e  57                   push edi
// 005b908f  7209                 jb 0x5b909a
// 005b9091  56                   push esi
// 005b9092  e819070400           call 0x5f97b0
// 005b9097  83c404               add esp, 4
// 005b909a  8b542414             mov edx, dword ptr [esp + 0x14]
// 005b909e  8b442410             mov eax, dword ptr [esp + 0x10]
// 005b90a2  8b7e08               mov edi, dword ptr [esi + 8]
// 005b90a5  52                   push edx
// 005b90a6  50                   push eax
// 005b90a7  56                   push esi
// 005b90a8  e873360400           call 0x5fc720
// 005b90ad  83c40c               add esp, 0xc
// 005b90b0  8907                 mov dword ptr [edi], eax
// 005b90b2  c7470804000000       mov dword ptr [edi + 8], 4
// 005b90b9  83460810             add dword ptr [esi + 8], 0x10
// 005b90bd  5f                   pop edi
// 005b90be  5e                   pop esi
// 005b90bf  c3                   ret 
// library lua-5.1.1/lapi.c (function _lua_pushlstring)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lapi.c
