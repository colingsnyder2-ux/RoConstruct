// from server: 100% by auto
// roc 2007-08 005bdee0  unit: RBX::VPVInstance::?$EnumPropDescriptor  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005bdee0
//
// 005bdee0  56                   push esi
// 005bdee1  8b742408             mov esi, dword ptr [esp + 8]
// 005bdee5  8b4610               mov eax, dword ptr [esi + 0x10]
// 005bdee8  8b4844               mov ecx, dword ptr [eax + 0x44]
// 005bdeeb  3b4840               cmp ecx, dword ptr [eax + 0x40]
// 005bdeee  57                   push edi
// 005bdeef  7209                 jb 0x5bdefa
// 005bdef1  56                   push esi
// 005bdef2  e8091f0500           call 0x60fe00
// 005bdef7  83c404               add esp, 4
// 005bdefa  8b542414             mov edx, dword ptr [esp + 0x14]
// 005bdefe  8b442410             mov eax, dword ptr [esp + 0x10]
// 005bdf02  8b7e08               mov edi, dword ptr [esi + 8]
// 005bdf05  52                   push edx
// 005bdf06  50                   push eax
// 005bdf07  56                   push esi
// 005bdf08  e873440500           call 0x612380
// 005bdf0d  83c40c               add esp, 0xc
// 005bdf10  8907                 mov dword ptr [edi], eax
// 005bdf12  c7470805000000       mov dword ptr [edi + 8], 5
// 005bdf19  83460810             add dword ptr [esi + 8], 0x10
// 005bdf1d  5f                   pop edi
// 005bdf1e  5e                   pop esi
// 005bdf1f  c3                   ret 
// library lua-5.1/lapi.c (function _lua_createtable)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
