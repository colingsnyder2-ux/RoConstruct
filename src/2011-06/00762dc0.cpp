// from server: 100% by auto
// roc 2011-06 00762dc0  unit: seg_00760000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00762dc0
//
// 00762dc0  8b442408             mov eax, dword ptr [esp + 8]
// 00762dc4  56                   push esi
// 00762dc5  8b742408             mov esi, dword ptr [esp + 8]
// 00762dc9  8bce                 mov ecx, esi
// 00762dcb  e8e0f3ffff           call 0x7621b0
// 00762dd0  8b4e08               mov ecx, dword ptr [esi + 8]
// 00762dd3  8d51f0               lea edx, [ecx - 0x10]
// 00762dd6  52                   push edx
// 00762dd7  83c1e0               add ecx, -0x20
// 00762dda  51                   push ecx
// 00762ddb  50                   push eax
// 00762ddc  56                   push esi
// 00762ddd  e81e4a0700           call 0x7d7800
// 00762de2  834608e0             add dword ptr [esi + 8], -0x20
// 00762de6  83c410               add esp, 0x10
// 00762de9  5e                   pop esi
// 00762dea  c3                   ret 
// library lua-5.1/lapi.c (function _lua_settable)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
