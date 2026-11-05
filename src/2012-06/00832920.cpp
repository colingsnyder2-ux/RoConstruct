// from server: 100% by auto
// roc 2012-06 00832920  unit: RBX::PAVPrimitive::$$A6AXU?$pair::?$signal::Vslot::?$callable  size: 56 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00832920
//
// 00832920  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00832924  8b4108               mov eax, dword ptr [ecx + 8]
// 00832927  83e810               sub eax, 0x10
// 0083292a  83780806             cmp dword ptr [eax + 8], 6
// 0083292e  7522                 jne 0x832952
// 00832930  8b00                 mov eax, dword ptr [eax]
// 00832932  80780600             cmp byte ptr [eax + 6], 0
// 00832936  751a                 jne 0x832952
// 00832938  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0083293c  8b4010               mov eax, dword ptr [eax + 0x10]
// 0083293f  6a00                 push 0
// 00832941  52                   push edx
// 00832942  8b542410             mov edx, dword ptr [esp + 0x10]
// 00832946  52                   push edx
// 00832947  50                   push eax
// 00832948  51                   push ecx
// 00832949  e872451000           call 0x936ec0
// 0083294e  83c414               add esp, 0x14
// 00832951  c3                   ret 
// 00832952  b801000000           mov eax, 1
// 00832957  c3                   ret 
// library lua-5.1/lapi.c (function _lua_dump)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
