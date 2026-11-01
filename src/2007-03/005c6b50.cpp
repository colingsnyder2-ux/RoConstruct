// from server: 100% by auto
// roc 2007-03 005c6b50  unit: seg_005c0000  size: 50 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c6b50
//
// 005c6b50  56                   push esi
// 005c6b51  8b742408             mov esi, dword ptr [esp + 8]
// 005c6b55  6a05                 push 5
// 005c6b57  6a01                 push 1
// 005c6b59  56                   push esi
// 005c6b5a  e8e139ffff           call 0x5ba540
// 005c6b5f  68edd8ffff           push 0xffffd8ed
// 005c6b64  56                   push esi
// 005c6b65  e8a620ffff           call 0x5b8c10
// 005c6b6a  6a01                 push 1
// 005c6b6c  56                   push esi
// 005c6b6d  e89e20ffff           call 0x5b8c10
// 005c6b72  56                   push esi
// 005c6b73  e8a824ffff           call 0x5b9020
// 005c6b78  83c420               add esp, 0x20
// 005c6b7b  b803000000           mov eax, 3
// 005c6b80  5e                   pop esi
// 005c6b81  c3                   ret 
// library lua-5.1.1/lbaselib.c (function _luaB_pairs)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lbaselib.c
