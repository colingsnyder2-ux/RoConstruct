// from server: 100% by auto
// roc 2007-03 005c1e20  unit: seg_005c0000  size: 71 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c1e20
//
// 005c1e20  56                   push esi
// 005c1e21  8b742408             mov esi, dword ptr [esp + 8]
// 005c1e25  57                   push edi
// 005c1e26  6a01                 push 1
// 005c1e28  68efd8ffff           push 0xffffd8ef
// 005c1e2d  56                   push esi
// 005c1e2e  e83d75ffff           call 0x5b9370
// 005c1e33  6aff                 push -1
// 005c1e35  56                   push esi
// 005c1e36  e82571ffff           call 0x5b8f60
// 005c1e3b  8b38                 mov edi, dword ptr [eax]
// 005c1e3d  83c414               add esp, 0x14
// 005c1e40  85ff                 test edi, edi
// 005c1e42  7514                 jne 0x5c1e58
// 005c1e44  a128987b00           mov eax, dword ptr [0x7b9828]
// 005c1e49  50                   push eax
// 005c1e4a  6840997b00           push 0x7b9940
// 005c1e4f  56                   push esi
// 005c1e50  e8fb7cffff           call 0x5b9b50
// 005c1e55  83c40c               add esp, 0xc
// 005c1e58  6a01                 push 1
// 005c1e5a  8bc7                 mov eax, edi
// 005c1e5c  e81ffeffff           call 0x5c1c80
// 005c1e61  83c404               add esp, 4
// 005c1e64  5f                   pop edi
// 005c1e65  5e                   pop esi
// 005c1e66  c3                   ret 
// library lua-5.1.1/liolib.c (function _io_read)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 liolib.c
