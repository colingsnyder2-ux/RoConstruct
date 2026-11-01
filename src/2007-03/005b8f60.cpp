// from server: 100% by auto
// roc 2007-03 005b8f60  unit: seg_005b0000  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005b8f60
//
// 005b8f60  8b442408             mov eax, dword ptr [esp + 8]
// 005b8f64  8b4c2404             mov ecx, dword ptr [esp + 4]
// 005b8f68  e843f9ffff           call 0x5b88b0
// 005b8f6d  8b4808               mov ecx, dword ptr [eax + 8]
// 005b8f70  83e902               sub ecx, 2
// 005b8f73  740e                 je 0x5b8f83
// 005b8f75  83e905               sub ecx, 5
// 005b8f78  7403                 je 0x5b8f7d
// 005b8f7a  33c0                 xor eax, eax
// 005b8f7c  c3                   ret 
// 005b8f7d  8b00                 mov eax, dword ptr [eax]
// 005b8f7f  83c018               add eax, 0x18
// 005b8f82  c3                   ret 
// 005b8f83  8b00                 mov eax, dword ptr [eax]
// 005b8f85  c3                   ret 
// library lua-5.1.1/lapi.c (function _lua_touserdata)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lapi.c
