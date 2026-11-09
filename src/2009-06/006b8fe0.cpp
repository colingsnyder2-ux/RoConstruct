// from server: 100% by auto
// roc 2009-06 006b8fe0  unit: RBX::UniversalTool  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006b8fe0
//
// 006b8fe0  8b442408             mov eax, dword ptr [esp + 8]
// 006b8fe4  8b4c2404             mov ecx, dword ptr [esp + 4]
// 006b8fe8  83ec10               sub esp, 0x10
// 006b8feb  e8e0fbffff           call 0x6b8bd0
// 006b8ff0  83780803             cmp dword ptr [eax + 8], 3
// 006b8ff4  7415                 je 0x6b900b
// 006b8ff6  8d0c24               lea ecx, [esp]
// 006b8ff9  51                   push ecx
// 006b8ffa  50                   push eax
// 006b8ffb  e8900e0300           call 0x6e9e90
// 006b9000  83c408               add esp, 8
// 006b9003  85c0                 test eax, eax
// 006b9005  7504                 jne 0x6b900b
// 006b9007  83c410               add esp, 0x10
// 006b900a  c3                   ret 
// 006b900b  b801000000           mov eax, 1
// 006b9010  83c410               add esp, 0x10
// 006b9013  c3                   ret 
// library lua-5.1/lapi.c (function _lua_isnumber)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
