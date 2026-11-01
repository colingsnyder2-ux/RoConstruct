// from server: 100% by auto
// roc 2007-03 005b8cb0  unit: seg_005b0000  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005b8cb0
//
// 005b8cb0  8b442408             mov eax, dword ptr [esp + 8]
// 005b8cb4  8b4c2404             mov ecx, dword ptr [esp + 4]
// 005b8cb8  83ec10               sub esp, 0x10
// 005b8cbb  e8f0fbffff           call 0x5b88b0
// 005b8cc0  83780803             cmp dword ptr [eax + 8], 3
// 005b8cc4  7415                 je 0x5b8cdb
// 005b8cc6  8d0c24               lea ecx, [esp]
// 005b8cc9  51                   push ecx
// 005b8cca  50                   push eax
// 005b8ccb  e8b00d0400           call 0x5f9a80
// 005b8cd0  83c408               add esp, 8
// 005b8cd3  85c0                 test eax, eax
// 005b8cd5  7504                 jne 0x5b8cdb
// 005b8cd7  83c410               add esp, 0x10
// 005b8cda  c3                   ret 
// 005b8cdb  b801000000           mov eax, 1
// 005b8ce0  83c410               add esp, 0x10
// 005b8ce3  c3                   ret 
// library lua-5.1.1/lapi.c (function _lua_isnumber)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lapi.c
