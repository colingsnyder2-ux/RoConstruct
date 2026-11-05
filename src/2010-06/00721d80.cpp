// from server: 100% by auto
// roc 2010-06 00721d80  unit: RBX::UniversalTool  size: 56 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00721d80
//
// 00721d80  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00721d84  8b4108               mov eax, dword ptr [ecx + 8]
// 00721d87  83e810               sub eax, 0x10
// 00721d8a  83780806             cmp dword ptr [eax + 8], 6
// 00721d8e  7522                 jne 0x721db2
// 00721d90  8b00                 mov eax, dword ptr [eax]
// 00721d92  80780600             cmp byte ptr [eax + 6], 0
// 00721d96  751a                 jne 0x721db2
// 00721d98  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00721d9c  8b4010               mov eax, dword ptr [eax + 0x10]
// 00721d9f  6a00                 push 0
// 00721da1  52                   push edx
// 00721da2  8b542410             mov edx, dword ptr [esp + 0x10]
// 00721da6  52                   push edx
// 00721da7  50                   push eax
// 00721da8  51                   push ecx
// 00721da9  e8b2cb0500           call 0x77e960
// 00721dae  83c414               add esp, 0x14
// 00721db1  c3                   ret 
// 00721db2  b801000000           mov eax, 1
// 00721db7  c3                   ret 
// library lua-5.1/lapi.c (function _lua_dump)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
