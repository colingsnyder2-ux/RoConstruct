// from server: 100% by auto
// roc 2007-03 005b8da0  unit: seg_005b0000  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005b8da0
//
// 005b8da0  8b442408             mov eax, dword ptr [esp + 8]
// 005b8da4  8b4c2404             mov ecx, dword ptr [esp + 4]
// 005b8da8  83ec10               sub esp, 0x10
// 005b8dab  e800fbffff           call 0x5b88b0
// 005b8db0  83780803             cmp dword ptr [eax + 8], 3
// 005b8db4  7417                 je 0x5b8dcd
// 005b8db6  8d0c24               lea ecx, [esp]
// 005b8db9  51                   push ecx
// 005b8dba  50                   push eax
// 005b8dbb  e8c00c0400           call 0x5f9a80
// 005b8dc0  83c408               add esp, 8
// 005b8dc3  85c0                 test eax, eax
// 005b8dc5  7506                 jne 0x5b8dcd
// 005b8dc7  d9ee                 fldz 
// 005b8dc9  83c410               add esp, 0x10
// 005b8dcc  c3                   ret 
// 005b8dcd  dd00                 fld qword ptr [eax]
// 005b8dcf  83c410               add esp, 0x10
// 005b8dd2  c3                   ret 
// library lua-5.1.1/lapi.c (function _lua_tonumber)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lapi.c
