// from server: 100% by auto
// roc 2008-06 00611f60  unit: seg_00610000  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00611f60
//
// 00611f60  8b442408             mov eax, dword ptr [esp + 8]
// 00611f64  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00611f68  83ec10               sub esp, 0x10
// 00611f6b  e820fbffff           call 0x611a90
// 00611f70  83780803             cmp dword ptr [eax + 8], 3
// 00611f74  7417                 je 0x611f8d
// 00611f76  8d0c24               lea ecx, [esp]
// 00611f79  51                   push ecx
// 00611f7a  50                   push eax
// 00611f7b  e8e0a60400           call 0x65c660
// 00611f80  83c408               add esp, 8
// 00611f83  85c0                 test eax, eax
// 00611f85  7506                 jne 0x611f8d
// 00611f87  d9ee                 fldz 
// 00611f89  83c410               add esp, 0x10
// 00611f8c  c3                   ret 
// 00611f8d  dd00                 fld qword ptr [eax]
// 00611f8f  83c410               add esp, 0x10
// 00611f92  c3                   ret 
// library lua-5.1/lapi.c (function _lua_tonumber)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
