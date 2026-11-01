// from server: 100% by auto
// roc 2007-03 005c3a70  unit: seg_005c0000  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c3a70
//
// 005c3a70  56                   push esi
// 005c3a71  8b742408             mov esi, dword ptr [esp + 8]
// 005c3a75  6a05                 push 5
// 005c3a77  6a01                 push 1
// 005c3a79  56                   push esi
// 005c3a7a  e8c16affff           call 0x5ba540
// 005c3a7f  68b89b7b00           push 0x7b9bb8
// 005c3a84  56                   push esi
// 005c3a85  e8c660ffff           call 0x5b9b50
// 005c3a8a  6a01                 push 1
// 005c3a8c  56                   push esi
// 005c3a8d  e87e51ffff           call 0x5b8c10
// 005c3a92  83c41c               add esp, 0x1c
// 005c3a95  b801000000           mov eax, 1
// 005c3a9a  5e                   pop esi
// 005c3a9b  c3                   ret 
// library lua-5.1.1/ltablib.c (function _setn)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 ltablib.c
