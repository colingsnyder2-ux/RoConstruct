// from server: 100% by auto
// roc 2011-06 00762840  unit: seg_00760000  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00762840
//
// 00762840  8b442408             mov eax, dword ptr [esp + 8]
// 00762844  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00762848  e863f9ffff           call 0x7621b0
// 0076284d  8b4808               mov ecx, dword ptr [eax + 8]
// 00762850  83e902               sub ecx, 2
// 00762853  740e                 je 0x762863
// 00762855  83e905               sub ecx, 5
// 00762858  7403                 je 0x76285d
// 0076285a  33c0                 xor eax, eax
// 0076285c  c3                   ret 
// 0076285d  8b00                 mov eax, dword ptr [eax]
// 0076285f  83c018               add eax, 0x18
// 00762862  c3                   ret 
// 00762863  8b00                 mov eax, dword ptr [eax]
// 00762865  c3                   ret 
// library lua-5.1/lapi.c (function _lua_touserdata)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
