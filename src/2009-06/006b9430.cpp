// from server: 100% by auto
// roc 2009-06 006b9430  unit: RBX::UniversalTool  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006b9430
//
// 006b9430  56                   push esi
// 006b9431  8b742408             mov esi, dword ptr [esp + 8]
// 006b9435  8b4610               mov eax, dword ptr [esi + 0x10]
// 006b9438  8b4844               mov ecx, dword ptr [eax + 0x44]
// 006b943b  3b4840               cmp ecx, dword ptr [eax + 0x40]
// 006b943e  7209                 jb 0x6b9449
// 006b9440  56                   push esi
// 006b9441  e87a070300           call 0x6e9bc0
// 006b9446  83c404               add esp, 4
// 006b9449  8b542410             mov edx, dword ptr [esp + 0x10]
// 006b944d  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006b9451  52                   push edx
// 006b9452  50                   push eax
// 006b9453  56                   push esi
// 006b9454  e857f90000           call 0x6c8db0
// 006b9459  83c40c               add esp, 0xc
// 006b945c  5e                   pop esi
// 006b945d  c3                   ret 
// library lua-5.1/lapi.c (function _lua_pushvfstring)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
