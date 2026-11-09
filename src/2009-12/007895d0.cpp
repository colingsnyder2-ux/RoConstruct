// from server: 100% by auto
// roc 2009-12 007895d0  unit: RBX::UniversalTool  size: 56 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007895d0
//
// 007895d0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007895d4  8b4108               mov eax, dword ptr [ecx + 8]
// 007895d7  83e810               sub eax, 0x10
// 007895da  83780806             cmp dword ptr [eax + 8], 6
// 007895de  7522                 jne 0x789602
// 007895e0  8b00                 mov eax, dword ptr [eax]
// 007895e2  80780600             cmp byte ptr [eax + 6], 0
// 007895e6  751a                 jne 0x789602
// 007895e8  8b54240c             mov edx, dword ptr [esp + 0xc]
// 007895ec  8b4010               mov eax, dword ptr [eax + 0x10]
// 007895ef  6a00                 push 0
// 007895f1  52                   push edx
// 007895f2  8b542410             mov edx, dword ptr [esp + 0x10]
// 007895f6  52                   push edx
// 007895f7  50                   push eax
// 007895f8  51                   push ecx
// 007895f9  e812810400           call 0x7d1710
// 007895fe  83c414               add esp, 0x14
// 00789601  c3                   ret 
// 00789602  b801000000           mov eax, 1
// 00789607  c3                   ret 
// library lua-5.1/lapi.c (function _lua_dump)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
