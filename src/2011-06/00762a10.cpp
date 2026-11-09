// from server: 100% by auto
// roc 2011-06 00762a10  unit: seg_00760000  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00762a10
//
// 00762a10  56                   push esi
// 00762a11  8b742408             mov esi, dword ptr [esp + 8]
// 00762a15  8b4610               mov eax, dword ptr [esi + 0x10]
// 00762a18  8b4844               mov ecx, dword ptr [eax + 0x44]
// 00762a1b  3b4840               cmp ecx, dword ptr [eax + 0x40]
// 00762a1e  7209                 jb 0x762a29
// 00762a20  56                   push esi
// 00762a21  e87a470700           call 0x7d71a0
// 00762a26  83c404               add esp, 4
// 00762a29  8b542410             mov edx, dword ptr [esp + 0x10]
// 00762a2d  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00762a31  52                   push edx
// 00762a32  50                   push eax
// 00762a33  56                   push esi
// 00762a34  e8f7a00100           call 0x77cb30
// 00762a39  83c40c               add esp, 0xc
// 00762a3c  5e                   pop esi
// 00762a3d  c3                   ret 
// library lua-5.1/lapi.c (function _lua_pushvfstring)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
