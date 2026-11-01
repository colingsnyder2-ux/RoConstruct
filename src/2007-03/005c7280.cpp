// from server: 100% by auto
// roc 2007-03 005c7280  unit: seg_005c0000  size: 118 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c7280
//
// 005c7280  56                   push esi
// 005c7281  57                   push edi
// 005c7282  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 005c7286  6a01                 push 1
// 005c7288  57                   push edi
// 005c7289  e8021dffff           call 0x5b8f90
// 005c728e  8bf0                 mov esi, eax
// 005c7290  83c408               add esp, 8
// 005c7293  85f6                 test esi, esi
// 005c7295  7510                 jne 0x5c72a7
// 005c7297  6874a57b00           push 0x7ba574
// 005c729c  6a01                 push 1
// 005c729e  57                   push edi
// 005c729f  e84c31ffff           call 0x5ba3f0
// 005c72a4  83c40c               add esp, 0xc
// 005c72a7  57                   push edi
// 005c72a8  e8a317ffff           call 0x5b8a50
// 005c72ad  83c404               add esp, 4
// 005c72b0  83e801               sub eax, 1
// 005c72b3  e818ffffff           call 0x5c71d0
// 005c72b8  8bf0                 mov esi, eax
// 005c72ba  85f6                 test esi, esi
// 005c72bc  7d1b                 jge 0x5c72d9
// 005c72be  6a00                 push 0
// 005c72c0  57                   push edi
// 005c72c1  e86a1fffff           call 0x5b9230
// 005c72c6  6afe                 push -2
// 005c72c8  57                   push edi
// 005c72c9  e83218ffff           call 0x5b8b00
// 005c72ce  83c410               add esp, 0x10
// 005c72d1  5f                   pop edi
// 005c72d2  b802000000           mov eax, 2
// 005c72d7  5e                   pop esi
// 005c72d8  c3                   ret 
// 005c72d9  6a01                 push 1
// 005c72db  57                   push edi
// 005c72dc  e84f1fffff           call 0x5b9230
// 005c72e1  83c8ff               or eax, 0xffffffff
// 005c72e4  2bc6                 sub eax, esi
// 005c72e6  50                   push eax
// 005c72e7  57                   push edi
// 005c72e8  e81318ffff           call 0x5b8b00
// 005c72ed  83c410               add esp, 0x10
// 005c72f0  5f                   pop edi
// 005c72f1  8d4601               lea eax, [esi + 1]
// 005c72f4  5e                   pop esi
// 005c72f5  c3                   ret 
// library lua-5.1.1/lbaselib.c (function _luaB_coresume)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lbaselib.c
