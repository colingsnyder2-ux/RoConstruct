// from server: 100% by auto
// roc 2011-06 00762870  unit: seg_00760000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00762870
//
// 00762870  8b442408             mov eax, dword ptr [esp + 8]
// 00762874  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00762878  e833f9ffff           call 0x7621b0
// 0076287d  83780808             cmp dword ptr [eax + 8], 8
// 00762881  7403                 je 0x762886
// 00762883  33c0                 xor eax, eax
// 00762885  c3                   ret 
// 00762886  8b00                 mov eax, dword ptr [eax]
// 00762888  c3                   ret 
// library lua-5.1/lapi.c (function _lua_tothread)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
