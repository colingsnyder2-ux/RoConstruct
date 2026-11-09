// from server: 100% by auto
// roc 2007-08 005bdc90  unit: RBX::VPVInstance::?$EnumPropDescriptor  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005bdc90
//
// 005bdc90  56                   push esi
// 005bdc91  8b742408             mov esi, dword ptr [esp + 8]
// 005bdc95  8b4610               mov eax, dword ptr [esi + 0x10]
// 005bdc98  8b4844               mov ecx, dword ptr [eax + 0x44]
// 005bdc9b  3b4840               cmp ecx, dword ptr [eax + 0x40]
// 005bdc9e  7209                 jb 0x5bdca9
// 005bdca0  56                   push esi
// 005bdca1  e85a210500           call 0x60fe00
// 005bdca6  83c404               add esp, 4
// 005bdca9  8b44240c             mov eax, dword ptr [esp + 0xc]
// 005bdcad  8d542410             lea edx, [esp + 0x10]
// 005bdcb1  52                   push edx
// 005bdcb2  50                   push eax
// 005bdcb3  56                   push esi
// 005bdcb4  e8270f0500           call 0x60ebe0
// 005bdcb9  83c40c               add esp, 0xc
// 005bdcbc  5e                   pop esi
// 005bdcbd  c3                   ret 
// library lua-5.1/lapi.c (function _lua_pushfstring)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
