// from server: 100% by auto
// roc 2012-06 00832420  unit: RBX::PAVPrimitive::$$A6AXU?$pair::?$signal::Vslot::?$callable  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00832420
//
// 00832420  56                   push esi
// 00832421  8b742408             mov esi, dword ptr [esp + 8]
// 00832425  8b4610               mov eax, dword ptr [esi + 0x10]
// 00832428  8b4844               mov ecx, dword ptr [eax + 0x44]
// 0083242b  57                   push edi
// 0083242c  3b4840               cmp ecx, dword ptr [eax + 0x40]
// 0083242f  7209                 jb 0x83243a
// 00832431  56                   push esi
// 00832432  e8790e1000           call 0x9332b0
// 00832437  83c404               add esp, 4
// 0083243a  8b542414             mov edx, dword ptr [esp + 0x14]
// 0083243e  8b442410             mov eax, dword ptr [esp + 0x10]
// 00832442  8b7e08               mov edi, dword ptr [esi + 8]
// 00832445  52                   push edx
// 00832446  50                   push eax
// 00832447  56                   push esi
// 00832448  e8d3341000           call 0x935920
// 0083244d  83c40c               add esp, 0xc
// 00832450  8907                 mov dword ptr [edi], eax
// 00832452  c7470805000000       mov dword ptr [edi + 8], 5
// 00832459  83460810             add dword ptr [esi + 8], 0x10
// 0083245d  5f                   pop edi
// 0083245e  5e                   pop esi
// 0083245f  c3                   ret 
// library lua-5.1/lapi.c (function _lua_createtable)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
