// from server: 100% by auto
// roc 2007-03 005b8de0  unit: seg_005b0000  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005b8de0
//
// 005b8de0  8b442408             mov eax, dword ptr [esp + 8]
// 005b8de4  8b4c2404             mov ecx, dword ptr [esp + 4]
// 005b8de8  83ec1c               sub esp, 0x1c
// 005b8deb  e8c0faffff           call 0x5b88b0
// 005b8df0  83780803             cmp dword ptr [eax + 8], 3
// 005b8df4  7416                 je 0x5b8e0c
// 005b8df6  8d4c240c             lea ecx, [esp + 0xc]
// 005b8dfa  51                   push ecx
// 005b8dfb  50                   push eax
// 005b8dfc  e87f0c0400           call 0x5f9a80
// 005b8e01  83c408               add esp, 8
// 005b8e04  85c0                 test eax, eax
// 005b8e06  7504                 jne 0x5b8e0c
// 005b8e08  83c41c               add esp, 0x1c
// 005b8e0b  c3                   ret 
// 005b8e0c  dd00                 fld qword ptr [eax]
// 005b8e0e  dd5c2404             fstp qword ptr [esp + 4]
// 005b8e12  dd442404             fld qword ptr [esp + 4]
// 005b8e16  db1c24               fistp dword ptr [esp]
// 005b8e19  8b0424               mov eax, dword ptr [esp]
// 005b8e1c  83c41c               add esp, 0x1c
// 005b8e1f  c3                   ret 
// library lua-5.1.1/lapi.c (function _lua_tointeger)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lapi.c
