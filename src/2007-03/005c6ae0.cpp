// from server: 100% by auto
// roc 2007-03 005c6ae0  unit: seg_005c0000  size: 45 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c6ae0
//
// 005c6ae0  56                   push esi
// 005c6ae1  8b742408             mov esi, dword ptr [esp + 8]
// 005c6ae5  6a01                 push 1
// 005c6ae7  56                   push esi
// 005c6ae8  e8a33affff           call 0x5ba590
// 005c6aed  6a01                 push 1
// 005c6aef  56                   push esi
// 005c6af0  e84b21ffff           call 0x5b8c40
// 005c6af5  50                   push eax
// 005c6af6  56                   push esi
// 005c6af7  e86421ffff           call 0x5b8c60
// 005c6afc  50                   push eax
// 005c6afd  56                   push esi
// 005c6afe  e8bd25ffff           call 0x5b90c0
// 005c6b03  83c420               add esp, 0x20
// 005c6b06  b801000000           mov eax, 1
// 005c6b0b  5e                   pop esi
// 005c6b0c  c3                   ret 
// library lua-5.1.1/lbaselib.c (function _luaB_type)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lbaselib.c
