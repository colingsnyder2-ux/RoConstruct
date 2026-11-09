// from server: 100% by auto
// roc 2007-08 005cc4b0  unit: seg_005c0000  size: 118 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005cc4b0
//
// 005cc4b0  56                   push esi
// 005cc4b1  57                   push edi
// 005cc4b2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 005cc4b6  6a01                 push 1
// 005cc4b8  57                   push edi
// 005cc4b9  e80216ffff           call 0x5bdac0
// 005cc4be  8bf0                 mov esi, eax
// 005cc4c0  83c408               add esp, 8
// 005cc4c3  85f6                 test esi, esi
// 005cc4c5  7510                 jne 0x5cc4d7
// 005cc4c7  68d4a47b00           push 0x7ba4d4
// 005cc4cc  6a01                 push 1
// 005cc4ce  57                   push edi
// 005cc4cf  e8ac2cffff           call 0x5bf180
// 005cc4d4  83c40c               add esp, 0xc
// 005cc4d7  57                   push edi
// 005cc4d8  e8a310ffff           call 0x5bd580
// 005cc4dd  83c404               add esp, 4
// 005cc4e0  83e801               sub eax, 1
// 005cc4e3  e818ffffff           call 0x5cc400
// 005cc4e8  8bf0                 mov esi, eax
// 005cc4ea  85f6                 test esi, esi
// 005cc4ec  7d1b                 jge 0x5cc509
// 005cc4ee  6a00                 push 0
// 005cc4f0  57                   push edi
// 005cc4f1  e86a18ffff           call 0x5bdd60
// 005cc4f6  6afe                 push -2
// 005cc4f8  57                   push edi
// 005cc4f9  e83211ffff           call 0x5bd630
// 005cc4fe  83c410               add esp, 0x10
// 005cc501  5f                   pop edi
// 005cc502  b802000000           mov eax, 2
// 005cc507  5e                   pop esi
// 005cc508  c3                   ret 
// 005cc509  6a01                 push 1
// 005cc50b  57                   push edi
// 005cc50c  e84f18ffff           call 0x5bdd60
// 005cc511  83c8ff               or eax, 0xffffffff
// 005cc514  2bc6                 sub eax, esi
// 005cc516  50                   push eax
// 005cc517  57                   push edi
// 005cc518  e81311ffff           call 0x5bd630
// 005cc51d  83c410               add esp, 0x10
// 005cc520  5f                   pop edi
// 005cc521  8d4601               lea eax, [esi + 1]
// 005cc524  5e                   pop esi
// 005cc525  c3                   ret 
// library lua-5.1.2/lbaselib.c (function _luaB_coresume)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.2 lbaselib.c
