// from server: 100% by auto
// roc 2009-12 00788a00  unit: RBX::UniversalTool  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00788a00
//
// 00788a00  8b442408             mov eax, dword ptr [esp + 8]
// 00788a04  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00788a08  83ec10               sub esp, 0x10
// 00788a0b  e8e0fbffff           call 0x7885f0
// 00788a10  83780803             cmp dword ptr [eax + 8], 3
// 00788a14  7415                 je 0x788a2b
// 00788a16  8d0c24               lea ecx, [esp]
// 00788a19  51                   push ecx
// 00788a1a  50                   push eax
// 00788a1b  e8c0540400           call 0x7cdee0
// 00788a20  83c408               add esp, 8
// 00788a23  85c0                 test eax, eax
// 00788a25  7504                 jne 0x788a2b
// 00788a27  83c410               add esp, 0x10
// 00788a2a  c3                   ret 
// 00788a2b  b801000000           mov eax, 1
// 00788a30  83c410               add esp, 0x10
// 00788a33  c3                   ret 
// library lua-5.1/lapi.c (function _lua_isnumber)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
