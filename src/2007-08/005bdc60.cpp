// from server: 100% by auto
// roc 2007-08 005bdc60  unit: RBX::VPVInstance::?$EnumPropDescriptor  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005bdc60
//
// 005bdc60  56                   push esi
// 005bdc61  8b742408             mov esi, dword ptr [esp + 8]
// 005bdc65  8b4610               mov eax, dword ptr [esi + 0x10]
// 005bdc68  8b4844               mov ecx, dword ptr [eax + 0x44]
// 005bdc6b  3b4840               cmp ecx, dword ptr [eax + 0x40]
// 005bdc6e  7209                 jb 0x5bdc79
// 005bdc70  56                   push esi
// 005bdc71  e88a210500           call 0x60fe00
// 005bdc76  83c404               add esp, 4
// 005bdc79  8b542410             mov edx, dword ptr [esp + 0x10]
// 005bdc7d  8b44240c             mov eax, dword ptr [esp + 0xc]
// 005bdc81  52                   push edx
// 005bdc82  50                   push eax
// 005bdc83  56                   push esi
// 005bdc84  e8570f0500           call 0x60ebe0
// 005bdc89  83c40c               add esp, 0xc
// 005bdc8c  5e                   pop esi
// 005bdc8d  c3                   ret 
// library lua-5.1/lapi.c (function _lua_pushvfstring)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
