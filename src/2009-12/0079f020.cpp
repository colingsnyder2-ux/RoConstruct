// from server: 100% by auto
// roc 2009-12 0079f020  unit: seg_00790000  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079f020
//
// 0079f020  56                   push esi
// 0079f021  8b742408             mov esi, dword ptr [esp + 8]
// 0079f025  6a00                 push 0
// 0079f027  6a00                 push 0
// 0079f029  6a01                 push 1
// 0079f02b  56                   push esi
// 0079f02c  e89fb7feff           call 0x78a7d0
// 0079f031  50                   push eax
// 0079f032  56                   push esi
// 0079f033  e8c8b2feff           call 0x78a300
// 0079f038  83c418               add esp, 0x18
// 0079f03b  85c0                 test eax, eax
// 0079f03d  7507                 jne 0x79f046
// 0079f03f  b801000000           mov eax, 1
// 0079f044  5e                   pop esi
// 0079f045  c3                   ret 
// 0079f046  56                   push esi
// 0079f047  e8f49cfeff           call 0x788d40
// 0079f04c  6afe                 push -2
// 0079f04e  56                   push esi
// 0079f04f  e8fc97feff           call 0x788850
// 0079f054  83c40c               add esp, 0xc
// 0079f057  b802000000           mov eax, 2
// 0079f05c  5e                   pop esi
// 0079f05d  c3                   ret 
// library lua-5.1/lbaselib.c (function _luaB_loadfile)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lbaselib.c
