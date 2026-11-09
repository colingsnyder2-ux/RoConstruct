// from server: 100% by auto
// roc 2008-06 00612320  unit: seg_00610000  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00612320
//
// 00612320  56                   push esi
// 00612321  8b742408             mov esi, dword ptr [esp + 8]
// 00612325  8b4610               mov eax, dword ptr [esi + 0x10]
// 00612328  8b4844               mov ecx, dword ptr [eax + 0x44]
// 0061232b  3b4840               cmp ecx, dword ptr [eax + 0x40]
// 0061232e  7209                 jb 0x612339
// 00612330  56                   push esi
// 00612331  e85aa00400           call 0x65c390
// 00612336  83c404               add esp, 4
// 00612339  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0061233d  8d542410             lea edx, [esp + 0x10]
// 00612341  52                   push edx
// 00612342  50                   push eax
// 00612343  56                   push esi
// 00612344  e887040100           call 0x6227d0
// 00612349  83c40c               add esp, 0xc
// 0061234c  5e                   pop esi
// 0061234d  c3                   ret 
// library lua-5.1/lapi.c (function _lua_pushfstring)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
