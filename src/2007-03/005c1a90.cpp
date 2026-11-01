// from server: 100% by auto
// roc 2007-03 005c1a90  unit: seg_005c0000  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c1a90
//
// 005c1a90  8b442404             mov eax, dword ptr [esp + 4]
// 005c1a94  683ceb7900           push 0x79eb3c
// 005c1a99  6a01                 push 1
// 005c1a9b  e820ffffff           call 0x5c19c0
// 005c1aa0  83c408               add esp, 8
// 005c1aa3  c3                   ret 
// library lua-5.1.1/liolib.c (function _io_input)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 liolib.c
