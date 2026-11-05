// from server: 100% by auto
// roc 2007-08 005be360  unit: RBX::VPVInstance::?$EnumPropDescriptor  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005be360
//
// 005be360  83ec14               sub esp, 0x14
// 005be363  56                   push esi
// 005be364  57                   push edi
// 005be365  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 005be369  85ff                 test edi, edi
// 005be36b  7505                 jne 0x5be372
// 005be36d  bfd8de7900           mov edi, 0x79ded8
// 005be372  8b442428             mov eax, dword ptr [esp + 0x28]
// 005be376  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 005be37a  8b742420             mov esi, dword ptr [esp + 0x20]
// 005be37e  50                   push eax
// 005be37f  51                   push ecx
// 005be380  8d542410             lea edx, [esp + 0x10]
// 005be384  52                   push edx
// 005be385  56                   push esi
// 005be386  e805500500           call 0x613390
// 005be38b  57                   push edi
// 005be38c  8d44241c             lea eax, [esp + 0x1c]
// 005be390  50                   push eax
// 005be391  56                   push esi
// 005be392  e8b9810000           call 0x5c6550
// 005be397  83c41c               add esp, 0x1c
// 005be39a  5f                   pop edi
// 005be39b  5e                   pop esi
// 005be39c  83c414               add esp, 0x14
// 005be39f  c3                   ret 
// library lua-5.1/lapi.c (function _lua_load)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
