// from server: 100% by auto
// roc 2009-06 006b9460  unit: RBX::UniversalTool  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006b9460
//
// 006b9460  56                   push esi
// 006b9461  8b742408             mov esi, dword ptr [esp + 8]
// 006b9465  8b4610               mov eax, dword ptr [esi + 0x10]
// 006b9468  8b4844               mov ecx, dword ptr [eax + 0x44]
// 006b946b  3b4840               cmp ecx, dword ptr [eax + 0x40]
// 006b946e  7209                 jb 0x6b9479
// 006b9470  56                   push esi
// 006b9471  e84a070300           call 0x6e9bc0
// 006b9476  83c404               add esp, 4
// 006b9479  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006b947d  8d542410             lea edx, [esp + 0x10]
// 006b9481  52                   push edx
// 006b9482  50                   push eax
// 006b9483  56                   push esi
// 006b9484  e827f90000           call 0x6c8db0
// 006b9489  83c40c               add esp, 0xc
// 006b948c  5e                   pop esi
// 006b948d  c3                   ret 
// library lua-5.1/lapi.c (function _lua_pushfstring)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
