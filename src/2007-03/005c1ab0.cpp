// from server: 100% by auto
// roc 2007-03 005c1ab0  unit: seg_005c0000  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c1ab0
//
// 005c1ab0  8b442404             mov eax, dword ptr [esp + 4]
// 005c1ab4  6850f57900           push 0x79f550
// 005c1ab9  6a02                 push 2
// 005c1abb  e800ffffff           call 0x5c19c0
// 005c1ac0  83c408               add esp, 8
// 005c1ac3  c3                   ret 
// library lua-5.1.1/liolib.c (function _io_output)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 liolib.c
