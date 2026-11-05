// from server: 100% by auto
// roc 2010-06 007211b0  unit: RBX::UniversalTool  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007211b0
//
// 007211b0  8b442408             mov eax, dword ptr [esp + 8]
// 007211b4  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007211b8  83ec10               sub esp, 0x10
// 007211bb  e8e0fbffff           call 0x720da0
// 007211c0  83780803             cmp dword ptr [eax + 8], 3
// 007211c4  7415                 je 0x7211db
// 007211c6  8d0c24               lea ecx, [esp]
// 007211c9  51                   push ecx
// 007211ca  50                   push eax
// 007211cb  e8609f0500           call 0x77b130
// 007211d0  83c408               add esp, 8
// 007211d3  85c0                 test eax, eax
// 007211d5  7504                 jne 0x7211db
// 007211d7  83c410               add esp, 0x10
// 007211da  c3                   ret 
// 007211db  b801000000           mov eax, 1
// 007211e0  83c410               add esp, 0x10
// 007211e3  c3                   ret 
// library lua-5.1/lapi.c (function _lua_isnumber)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
