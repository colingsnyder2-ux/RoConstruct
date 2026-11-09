// from server: 100% by auto
// roc 2008-06 006129f0  unit: seg_00610000  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006129f0
//
// 006129f0  83ec14               sub esp, 0x14
// 006129f3  56                   push esi
// 006129f4  57                   push edi
// 006129f5  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 006129f9  85ff                 test edi, edi
// 006129fb  7505                 jne 0x612a02
// 006129fd  bf109e8100           mov edi, 0x819e10
// 00612a02  8b442428             mov eax, dword ptr [esp + 0x28]
// 00612a06  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00612a0a  8b742420             mov esi, dword ptr [esp + 0x20]
// 00612a0e  50                   push eax
// 00612a0f  51                   push ecx
// 00612a10  8d542410             lea edx, [esp + 0x10]
// 00612a14  52                   push edx
// 00612a15  56                   push esi
// 00612a16  e8b5ce0400           call 0x65f8d0
// 00612a1b  57                   push edi
// 00612a1c  8d44241c             lea eax, [esp + 0x1c]
// 00612a20  50                   push eax
// 00612a21  56                   push esi
// 00612a22  e859fb0000           call 0x622580
// 00612a27  83c41c               add esp, 0x1c
// 00612a2a  5f                   pop edi
// 00612a2b  5e                   pop esi
// 00612a2c  83c414               add esp, 0x14
// 00612a2f  c3                   ret 
// library lua-5.1/lapi.c (function _lua_load)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
