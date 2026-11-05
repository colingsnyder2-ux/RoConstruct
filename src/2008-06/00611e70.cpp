// from server: 100% by auto
// roc 2008-06 00611e70  unit: seg_00610000  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00611e70
//
// 00611e70  8b442408             mov eax, dword ptr [esp + 8]
// 00611e74  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00611e78  83ec10               sub esp, 0x10
// 00611e7b  e810fcffff           call 0x611a90
// 00611e80  83780803             cmp dword ptr [eax + 8], 3
// 00611e84  7415                 je 0x611e9b
// 00611e86  8d0c24               lea ecx, [esp]
// 00611e89  51                   push ecx
// 00611e8a  50                   push eax
// 00611e8b  e8d0a70400           call 0x65c660
// 00611e90  83c408               add esp, 8
// 00611e93  85c0                 test eax, eax
// 00611e95  7504                 jne 0x611e9b
// 00611e97  83c410               add esp, 0x10
// 00611e9a  c3                   ret 
// 00611e9b  b801000000           mov eax, 1
// 00611ea0  83c410               add esp, 0x10
// 00611ea3  c3                   ret 
// library lua-5.1/lapi.c (function _lua_isnumber)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
