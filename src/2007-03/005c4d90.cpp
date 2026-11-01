// from server: 100% by auto
// roc 2007-03 005c4d90  unit: seg_005c0000  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c4d90
//
// 005c4d90  8b44240c             mov eax, dword ptr [esp + 0xc]
// 005c4d94  8b4c2408             mov ecx, dword ptr [esp + 8]
// 005c4d98  8b542410             mov edx, dword ptr [esp + 0x10]
// 005c4d9c  50                   push eax
// 005c4d9d  51                   push ecx
// 005c4d9e  52                   push edx
// 005c4d9f  e8dc50ffff           call 0x5b9e80
// 005c4da4  83c40c               add esp, 0xc
// 005c4da7  33c0                 xor eax, eax
// 005c4da9  c3                   ret 
// library lua-5.1.1/lstrlib.c (function _writer)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lstrlib.c
