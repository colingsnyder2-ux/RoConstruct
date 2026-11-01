// from server: 100% by auto
// roc 2007-03 005c6d40  unit: seg_005c0000  size: 95 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c6d40
//
// 005c6d40  56                   push esi
// 005c6d41  8b742408             mov esi, dword ptr [esp + 8]
// 005c6d45  57                   push edi
// 005c6d46  6a00                 push 0
// 005c6d48  68cca47b00           push 0x7ba4cc
// 005c6d4d  6a02                 push 2
// 005c6d4f  56                   push esi
// 005c6d50  e8cb38ffff           call 0x5ba620
// 005c6d55  6a06                 push 6
// 005c6d57  6a01                 push 1
// 005c6d59  56                   push esi
// 005c6d5a  8bf8                 mov edi, eax
// 005c6d5c  e8df37ffff           call 0x5ba540
// 005c6d61  6a03                 push 3
// 005c6d63  56                   push esi
// 005c6d64  e8f71cffff           call 0x5b8a60
// 005c6d69  57                   push edi
// 005c6d6a  6a00                 push 0
// 005c6d6c  68c06c5c00           push 0x5c6cc0
// 005c6d71  56                   push esi
// 005c6d72  e8b92affff           call 0x5b9830
// 005c6d77  83c434               add esp, 0x34
// 005c6d7a  85c0                 test eax, eax
// 005c6d7c  7508                 jne 0x5c6d86
// 005c6d7e  5f                   pop edi
// 005c6d7f  b801000000           mov eax, 1
// 005c6d84  5e                   pop esi
// 005c6d85  c3                   ret 
// 005c6d86  56                   push esi
// 005c6d87  e89422ffff           call 0x5b9020
// 005c6d8c  6afe                 push -2
// 005c6d8e  56                   push esi
// 005c6d8f  e86c1dffff           call 0x5b8b00
// 005c6d94  83c40c               add esp, 0xc
// 005c6d97  5f                   pop edi
// 005c6d98  b802000000           mov eax, 2
// 005c6d9d  5e                   pop esi
// 005c6d9e  c3                   ret 
// library lua-5.1.1/lbaselib.c (function _luaB_load)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lbaselib.c
