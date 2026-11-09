// from server: 100% by auto
// roc 2008-06 006122f0  unit: seg_00610000  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006122f0
//
// 006122f0  56                   push esi
// 006122f1  8b742408             mov esi, dword ptr [esp + 8]
// 006122f5  8b4610               mov eax, dword ptr [esi + 0x10]
// 006122f8  8b4844               mov ecx, dword ptr [eax + 0x44]
// 006122fb  3b4840               cmp ecx, dword ptr [eax + 0x40]
// 006122fe  7209                 jb 0x612309
// 00612300  56                   push esi
// 00612301  e88aa00400           call 0x65c390
// 00612306  83c404               add esp, 4
// 00612309  8b542410             mov edx, dword ptr [esp + 0x10]
// 0061230d  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00612311  52                   push edx
// 00612312  50                   push eax
// 00612313  56                   push esi
// 00612314  e8b7040100           call 0x6227d0
// 00612319  83c40c               add esp, 0xc
// 0061231c  5e                   pop esi
// 0061231d  c3                   ret 
// library lua-5.1/lapi.c (function _lua_pushvfstring)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
