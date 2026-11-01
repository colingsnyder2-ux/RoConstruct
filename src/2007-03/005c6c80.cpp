// from server: 100% by auto
// roc 2007-03 005c6c80  unit: seg_005c0000  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c6c80
//
// 005c6c80  56                   push esi
// 005c6c81  8b742408             mov esi, dword ptr [esp + 8]
// 005c6c85  6a00                 push 0
// 005c6c87  6a00                 push 0
// 005c6c89  6a01                 push 1
// 005c6c8b  56                   push esi
// 005c6c8c  e88f39ffff           call 0x5ba620
// 005c6c91  50                   push eax
// 005c6c92  56                   push esi
// 005c6c93  e8f834ffff           call 0x5ba190
// 005c6c98  83c418               add esp, 0x18
// 005c6c9b  85c0                 test eax, eax
// 005c6c9d  7507                 jne 0x5c6ca6
// 005c6c9f  b801000000           mov eax, 1
// 005c6ca4  5e                   pop esi
// 005c6ca5  c3                   ret 
// 005c6ca6  56                   push esi
// 005c6ca7  e87423ffff           call 0x5b9020
// 005c6cac  6afe                 push -2
// 005c6cae  56                   push esi
// 005c6caf  e84c1effff           call 0x5b8b00
// 005c6cb4  83c40c               add esp, 0xc
// 005c6cb7  b802000000           mov eax, 2
// 005c6cbc  5e                   pop esi
// 005c6cbd  c3                   ret 
// library lua-5.1.1/lbaselib.c (function _luaB_loadfile)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lbaselib.c
