// from server: 100% by auto
// roc 2007-03 005c7360  unit: seg_005c0000  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c7360
//
// 005c7360  56                   push esi
// 005c7361  8b742408             mov esi, dword ptr [esp + 8]
// 005c7365  57                   push edi
// 005c7366  56                   push esi
// 005c7367  e89416ffff           call 0x5b8a00
// 005c736c  6a01                 push 1
// 005c736e  56                   push esi
// 005c736f  8bf8                 mov edi, eax
// 005c7371  e8ca18ffff           call 0x5b8c40
// 005c7376  83c40c               add esp, 0xc
// 005c7379  83f806               cmp eax, 6
// 005c737c  750f                 jne 0x5c738d
// 005c737e  6a01                 push 1
// 005c7380  56                   push esi
// 005c7381  e8fa18ffff           call 0x5b8c80
// 005c7386  83c408               add esp, 8
// 005c7389  85c0                 test eax, eax
// 005c738b  7410                 je 0x5c739d
// 005c738d  6888a57b00           push 0x7ba588
// 005c7392  6a01                 push 1
// 005c7394  56                   push esi
// 005c7395  e85630ffff           call 0x5ba3f0
// 005c739a  83c40c               add esp, 0xc
// 005c739d  6a01                 push 1
// 005c739f  56                   push esi
// 005c73a0  e86b18ffff           call 0x5b8c10
// 005c73a5  6a01                 push 1
// 005c73a7  57                   push edi
// 005c73a8  56                   push esi
// 005c73a9  e8e215ffff           call 0x5b8990
// 005c73ae  83c414               add esp, 0x14
// 005c73b1  5f                   pop edi
// 005c73b2  b801000000           mov eax, 1
// 005c73b7  5e                   pop esi
// 005c73b8  c3                   ret 
// library lua-5.1.1/lbaselib.c (function _luaB_cocreate)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lbaselib.c
