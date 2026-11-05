// from server: 100% by auto
// roc 2012-06 008328e0  unit: RBX::PAVPrimitive::$$A6AXU?$pair::?$signal::Vslot::?$callable  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008328e0
//
// 008328e0  83ec14               sub esp, 0x14
// 008328e3  56                   push esi
// 008328e4  57                   push edi
// 008328e5  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 008328e9  85ff                 test edi, edi
// 008328eb  7505                 jne 0x8328f2
// 008328ed  bf2870b700           mov edi, 0xb77028
// 008328f2  8b442428             mov eax, dword ptr [esp + 0x28]
// 008328f6  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 008328fa  8b742420             mov esi, dword ptr [esp + 0x20]
// 008328fe  50                   push eax
// 008328ff  51                   push ecx
// 00832900  8d542410             lea edx, [esp + 0x10]
// 00832904  52                   push edx
// 00832905  56                   push esi
// 00832906  e815401000           call 0x936920
// 0083290b  57                   push edi
// 0083290c  8d44241c             lea eax, [esp + 0x1c]
// 00832910  50                   push eax
// 00832911  56                   push esi
// 00832912  e8c9280200           call 0x8551e0
// 00832917  83c41c               add esp, 0x1c
// 0083291a  5f                   pop edi
// 0083291b  5e                   pop esi
// 0083291c  83c414               add esp, 0x14
// 0083291f  c3                   ret 
// library lua-5.1/lapi.c (function _lua_load)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
