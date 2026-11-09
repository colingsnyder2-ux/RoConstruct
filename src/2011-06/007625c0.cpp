// from server: 100% by auto
// roc 2011-06 007625c0  unit: seg_00760000  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 007625c0
//
// 007625c0  8b442408             mov eax, dword ptr [esp + 8]
// 007625c4  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007625c8  83ec10               sub esp, 0x10
// 007625cb  e8e0fbffff           call 0x7621b0
// 007625d0  83780803             cmp dword ptr [eax + 8], 3
// 007625d4  7415                 je 0x7625eb
// 007625d6  8d0c24               lea ecx, [esp]
// 007625d9  51                   push ecx
// 007625da  50                   push eax
// 007625db  e8904e0700           call 0x7d7470
// 007625e0  83c408               add esp, 8
// 007625e3  85c0                 test eax, eax
// 007625e5  7504                 jne 0x7625eb
// 007625e7  83c410               add esp, 0x10
// 007625ea  c3                   ret 
// 007625eb  b801000000           mov eax, 1
// 007625f0  83c410               add esp, 0x10
// 007625f3  c3                   ret 
// library lua-5.1/lapi.c (function _lua_isnumber)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
