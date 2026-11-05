// from server: 100% by auto
// roc 2008-06 00612240  unit: seg_00610000  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00612240
//
// 00612240  56                   push esi
// 00612241  8b742408             mov esi, dword ptr [esp + 8]
// 00612245  8b4610               mov eax, dword ptr [esi + 0x10]
// 00612248  8b4844               mov ecx, dword ptr [eax + 0x44]
// 0061224b  57                   push edi
// 0061224c  3b4840               cmp ecx, dword ptr [eax + 0x40]
// 0061224f  7209                 jb 0x61225a
// 00612251  56                   push esi
// 00612252  e839a10400           call 0x65c390
// 00612257  83c404               add esp, 4
// 0061225a  8b542414             mov edx, dword ptr [esp + 0x14]
// 0061225e  8b442410             mov eax, dword ptr [esp + 0x10]
// 00612262  8b7e08               mov edi, dword ptr [esi + 8]
// 00612265  52                   push edx
// 00612266  50                   push eax
// 00612267  56                   push esi
// 00612268  e893d00400           call 0x65f300
// 0061226d  83c40c               add esp, 0xc
// 00612270  8907                 mov dword ptr [edi], eax
// 00612272  c7470804000000       mov dword ptr [edi + 8], 4
// 00612279  83460810             add dword ptr [esi + 8], 0x10
// 0061227d  5f                   pop edi
// 0061227e  5e                   pop esi
// 0061227f  c3                   ret 
// library lua-5.1/lapi.c (function _lua_pushlstring)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
