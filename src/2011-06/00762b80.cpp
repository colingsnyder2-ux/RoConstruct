// from server: 100% by auto
// roc 2011-06 00762b80  unit: seg_00760000  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00762b80
//
// 00762b80  8b442408             mov eax, dword ptr [esp + 8]
// 00762b84  56                   push esi
// 00762b85  8b742408             mov esi, dword ptr [esp + 8]
// 00762b89  8bce                 mov ecx, esi
// 00762b8b  e820f6ffff           call 0x7621b0
// 00762b90  8b4e08               mov ecx, dword ptr [esi + 8]
// 00762b93  83c1f0               add ecx, -0x10
// 00762b96  51                   push ecx
// 00762b97  51                   push ecx
// 00762b98  50                   push eax
// 00762b99  56                   push esi
// 00762b9a  e8714b0700           call 0x7d7710
// 00762b9f  83c410               add esp, 0x10
// 00762ba2  5e                   pop esi
// 00762ba3  c3                   ret 
// library lua-5.1/lapi.c (function _lua_gettable)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
