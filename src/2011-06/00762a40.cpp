// from server: 100% by auto
// roc 2011-06 00762a40  unit: seg_00760000  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00762a40
//
// 00762a40  56                   push esi
// 00762a41  8b742408             mov esi, dword ptr [esp + 8]
// 00762a45  8b4610               mov eax, dword ptr [esi + 0x10]
// 00762a48  8b4844               mov ecx, dword ptr [eax + 0x44]
// 00762a4b  3b4840               cmp ecx, dword ptr [eax + 0x40]
// 00762a4e  7209                 jb 0x762a59
// 00762a50  56                   push esi
// 00762a51  e84a470700           call 0x7d71a0
// 00762a56  83c404               add esp, 4
// 00762a59  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00762a5d  8d542410             lea edx, [esp + 0x10]
// 00762a61  52                   push edx
// 00762a62  50                   push eax
// 00762a63  56                   push esi
// 00762a64  e8c7a00100           call 0x77cb30
// 00762a69  83c40c               add esp, 0xc
// 00762a6c  5e                   pop esi
// 00762a6d  c3                   ret 
// library lua-5.1/lapi.c (function _lua_pushfstring)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
