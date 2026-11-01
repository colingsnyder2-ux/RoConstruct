// from server: 100% by auto
// roc 2007-03 005b9130  unit: seg_005b0000  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005b9130
//
// 005b9130  56                   push esi
// 005b9131  8b742408             mov esi, dword ptr [esp + 8]
// 005b9135  8b4610               mov eax, dword ptr [esi + 0x10]
// 005b9138  8b4844               mov ecx, dword ptr [eax + 0x44]
// 005b913b  3b4840               cmp ecx, dword ptr [eax + 0x40]
// 005b913e  7209                 jb 0x5b9149
// 005b9140  56                   push esi
// 005b9141  e86a060400           call 0x5f97b0
// 005b9146  83c404               add esp, 4
// 005b9149  8b542410             mov edx, dword ptr [esp + 0x10]
// 005b914d  8b44240c             mov eax, dword ptr [esp + 0xc]
// 005b9151  52                   push edx
// 005b9152  50                   push eax
// 005b9153  56                   push esi
// 005b9154  e837f40300           call 0x5f8590
// 005b9159  83c40c               add esp, 0xc
// 005b915c  5e                   pop esi
// 005b915d  c3                   ret 
// library lua-5.1.1/lapi.c (function _lua_pushvfstring)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lapi.c
