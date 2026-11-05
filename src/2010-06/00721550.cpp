// from server: 100% by auto
// roc 2010-06 00721550  unit: RBX::UniversalTool  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00721550
//
// 00721550  56                   push esi
// 00721551  8b742408             mov esi, dword ptr [esp + 8]
// 00721555  8b4610               mov eax, dword ptr [esi + 0x10]
// 00721558  8b4844               mov ecx, dword ptr [eax + 0x44]
// 0072155b  57                   push edi
// 0072155c  3b4840               cmp ecx, dword ptr [eax + 0x40]
// 0072155f  7209                 jb 0x72156a
// 00721561  56                   push esi
// 00721562  e8f9980500           call 0x77ae60
// 00721567  83c404               add esp, 4
// 0072156a  8b542414             mov edx, dword ptr [esp + 0x14]
// 0072156e  8b442410             mov eax, dword ptr [esp + 0x10]
// 00721572  8b7e08               mov edi, dword ptr [esi + 8]
// 00721575  52                   push edx
// 00721576  50                   push eax
// 00721577  56                   push esi
// 00721578  e863c80500           call 0x77dde0
// 0072157d  83c40c               add esp, 0xc
// 00721580  8907                 mov dword ptr [edi], eax
// 00721582  c7470804000000       mov dword ptr [edi + 8], 4
// 00721589  83460810             add dword ptr [esi + 8], 0x10
// 0072158d  5f                   pop edi
// 0072158e  5e                   pop esi
// 0072158f  c3                   ret 
// library lua-5.1/lapi.c (function _lua_pushlstring)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
