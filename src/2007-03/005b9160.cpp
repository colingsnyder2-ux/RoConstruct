// from server: 100% by auto
// roc 2007-03 005b9160  unit: seg_005b0000  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005b9160
//
// 005b9160  56                   push esi
// 005b9161  8b742408             mov esi, dword ptr [esp + 8]
// 005b9165  8b4610               mov eax, dword ptr [esi + 0x10]
// 005b9168  8b4844               mov ecx, dword ptr [eax + 0x44]
// 005b916b  3b4840               cmp ecx, dword ptr [eax + 0x40]
// 005b916e  7209                 jb 0x5b9179
// 005b9170  56                   push esi
// 005b9171  e83a060400           call 0x5f97b0
// 005b9176  83c404               add esp, 4
// 005b9179  8b44240c             mov eax, dword ptr [esp + 0xc]
// 005b917d  8d542410             lea edx, [esp + 0x10]
// 005b9181  52                   push edx
// 005b9182  50                   push eax
// 005b9183  56                   push esi
// 005b9184  e807f40300           call 0x5f8590
// 005b9189  83c40c               add esp, 0xc
// 005b918c  5e                   pop esi
// 005b918d  c3                   ret 
// library lua-5.1.1/lapi.c (function _lua_pushfstring)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lapi.c
