// from server: 100% by auto
// roc 2007-03 005c6b10  unit: seg_005c0000  size: 61 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c6b10
//
// 005c6b10  56                   push esi
// 005c6b11  8b742408             mov esi, dword ptr [esp + 8]
// 005c6b15  6a05                 push 5
// 005c6b17  6a01                 push 1
// 005c6b19  56                   push esi
// 005c6b1a  e8213affff           call 0x5ba540
// 005c6b1f  6a02                 push 2
// 005c6b21  56                   push esi
// 005c6b22  e8391fffff           call 0x5b8a60
// 005c6b27  6a01                 push 1
// 005c6b29  56                   push esi
// 005c6b2a  e8912effff           call 0x5b99c0
// 005c6b2f  83c41c               add esp, 0x1c
// 005c6b32  85c0                 test eax, eax
// 005c6b34  7407                 je 0x5c6b3d
// 005c6b36  b802000000           mov eax, 2
// 005c6b3b  5e                   pop esi
// 005c6b3c  c3                   ret 
// 005c6b3d  56                   push esi
// 005c6b3e  e8dd24ffff           call 0x5b9020
// 005c6b43  83c404               add esp, 4
// 005c6b46  b801000000           mov eax, 1
// 005c6b4b  5e                   pop esi
// 005c6b4c  c3                   ret 
// library lua-5.1.1/lbaselib.c (function _luaB_next)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lbaselib.c
