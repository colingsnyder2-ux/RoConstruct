// from server: 100% by auto
// roc 2008-06 00612120  unit: seg_00610000  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00612120
//
// 00612120  8b442408             mov eax, dword ptr [esp + 8]
// 00612124  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00612128  e863f9ffff           call 0x611a90
// 0061212d  8b4808               mov ecx, dword ptr [eax + 8]
// 00612130  83e902               sub ecx, 2
// 00612133  740e                 je 0x612143
// 00612135  83e905               sub ecx, 5
// 00612138  7403                 je 0x61213d
// 0061213a  33c0                 xor eax, eax
// 0061213c  c3                   ret 
// 0061213d  8b00                 mov eax, dword ptr [eax]
// 0061213f  83c018               add eax, 0x18
// 00612142  c3                   ret 
// 00612143  8b00                 mov eax, dword ptr [eax]
// 00612145  c3                   ret 
// library lua-5.1/lapi.c (function _lua_touserdata)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
