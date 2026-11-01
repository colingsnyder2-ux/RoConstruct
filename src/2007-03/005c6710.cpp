// from server: 100% by auto
// roc 2007-03 005c6710  unit: seg_005c0000  size: 67 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c6710
//
// 005c6710  56                   push esi
// 005c6711  8b742408             mov esi, dword ptr [esp + 8]
// 005c6715  6a01                 push 1
// 005c6717  56                   push esi
// 005c6718  e8733effff           call 0x5ba590
// 005c671d  6a01                 push 1
// 005c671f  56                   push esi
// 005c6720  e8cb2cffff           call 0x5b93f0
// 005c6725  83c410               add esp, 0x10
// 005c6728  85c0                 test eax, eax
// 005c672a  7510                 jne 0x5c673c
// 005c672c  56                   push esi
// 005c672d  e8ee28ffff           call 0x5b9020
// 005c6732  83c404               add esp, 4
// 005c6735  b801000000           mov eax, 1
// 005c673a  5e                   pop esi
// 005c673b  c3                   ret 
// 005c673c  683ca37b00           push 0x7ba33c
// 005c6741  6a01                 push 1
// 005c6743  56                   push esi
// 005c6744  e8c734ffff           call 0x5b9c10
// 005c6749  83c40c               add esp, 0xc
// 005c674c  b801000000           mov eax, 1
// 005c6751  5e                   pop esi
// 005c6752  c3                   ret 
// library lua-5.1.1/lbaselib.c (function _luaB_getmetatable)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lbaselib.c
