// from server: 100% by auto
// roc 2007-03 005c4120  unit: seg_005c0000  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c4120
//
// 005c4120  8b442404             mov eax, dword ptr [esp + 4]
// 005c4124  68689b7b00           push 0x7b9b68
// 005c4129  68b05d7a00           push 0x7a5db0
// 005c412e  50                   push eax
// 005c412f  e83c68ffff           call 0x5ba970
// 005c4134  83c40c               add esp, 0xc
// 005c4137  b801000000           mov eax, 1
// 005c413c  c3                   ret 
// library lua-5.1.1/ltablib.c (function _luaopen_table)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 ltablib.c
