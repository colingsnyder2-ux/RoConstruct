// from server: 100% by auto
// roc 2009-06 006b9380  unit: RBX::UniversalTool  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006b9380
//
// 006b9380  56                   push esi
// 006b9381  8b742408             mov esi, dword ptr [esp + 8]
// 006b9385  8b4610               mov eax, dword ptr [esi + 0x10]
// 006b9388  8b4844               mov ecx, dword ptr [eax + 0x44]
// 006b938b  57                   push edi
// 006b938c  3b4840               cmp ecx, dword ptr [eax + 0x40]
// 006b938f  7209                 jb 0x6b939a
// 006b9391  56                   push esi
// 006b9392  e829080300           call 0x6e9bc0
// 006b9397  83c404               add esp, 4
// 006b939a  8b542414             mov edx, dword ptr [esp + 0x14]
// 006b939e  8b442410             mov eax, dword ptr [esp + 0x10]
// 006b93a2  8b7e08               mov edi, dword ptr [esi + 8]
// 006b93a5  52                   push edx
// 006b93a6  50                   push eax
// 006b93a7  56                   push esi
// 006b93a8  e893370300           call 0x6ecb40
// 006b93ad  83c40c               add esp, 0xc
// 006b93b0  8907                 mov dword ptr [edi], eax
// 006b93b2  c7470804000000       mov dword ptr [edi + 8], 4
// 006b93b9  83460810             add dword ptr [esi + 8], 0x10
// 006b93bd  5f                   pop edi
// 006b93be  5e                   pop esi
// 006b93bf  c3                   ret 
// library lua-5.1/lapi.c (function _lua_pushlstring)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
