// from server: 100% by auto
// roc 2009-12 0079c530  unit: seg_00790000  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079c530
//
// 0079c530  8b442404             mov eax, dword ptr [esp + 4]
// 0079c534  68b8ac9e00           push 0x9eacb8
// 0079c539  68803f9a00           push 0x9a3f80
// 0079c53e  50                   push eax
// 0079c53f  e8dce5feff           call 0x78ab20
// 0079c544  83c40c               add esp, 0xc
// 0079c547  b801000000           mov eax, 1
// 0079c54c  c3                   ret 
// library lua-5.1/ltablib.c (function _luaopen_table)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ltablib.c
