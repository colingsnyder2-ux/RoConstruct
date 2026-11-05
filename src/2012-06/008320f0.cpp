// from server: 100% by auto
// roc 2012-06 008320f0  unit: RBX::PAVPrimitive::$$A6AXU?$pair::?$signal::Vslot::?$callable  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008320f0
//
// 008320f0  56                   push esi
// 008320f1  8b742408             mov esi, dword ptr [esp + 8]
// 008320f5  8b4610               mov eax, dword ptr [esi + 0x10]
// 008320f8  8b4844               mov ecx, dword ptr [eax + 0x44]
// 008320fb  57                   push edi
// 008320fc  3b4840               cmp ecx, dword ptr [eax + 0x40]
// 008320ff  7209                 jb 0x83210a
// 00832101  56                   push esi
// 00832102  e8a9111000           call 0x9332b0
// 00832107  83c404               add esp, 4
// 0083210a  8b542414             mov edx, dword ptr [esp + 0x14]
// 0083210e  8b442410             mov eax, dword ptr [esp + 0x10]
// 00832112  8b7e08               mov edi, dword ptr [esi + 8]
// 00832115  52                   push edx
// 00832116  50                   push eax
// 00832117  56                   push esi
// 00832118  e813421000           call 0x936330
// 0083211d  83c40c               add esp, 0xc
// 00832120  8907                 mov dword ptr [edi], eax
// 00832122  c7470804000000       mov dword ptr [edi + 8], 4
// 00832129  83460810             add dword ptr [esi + 8], 0x10
// 0083212d  5f                   pop edi
// 0083212e  5e                   pop esi
// 0083212f  c3                   ret 
// library lua-5.1/lapi.c (function _lua_pushlstring)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
