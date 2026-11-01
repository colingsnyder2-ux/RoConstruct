// from server: 100% by auto
// roc 2007-03 005ba590  unit: seg_005b0000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005ba590
//
// 005ba590  56                   push esi
// 005ba591  8b74240c             mov esi, dword ptr [esp + 0xc]
// 005ba595  57                   push edi
// 005ba596  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 005ba59a  56                   push esi
// 005ba59b  57                   push edi
// 005ba59c  e89fe6ffff           call 0x5b8c40
// 005ba5a1  83c408               add esp, 8
// 005ba5a4  83f8ff               cmp eax, -1
// 005ba5a7  750f                 jne 0x5ba5b8
// 005ba5a9  68f0917b00           push 0x7b91f0
// 005ba5ae  56                   push esi
// 005ba5af  57                   push edi
// 005ba5b0  e83bfeffff           call 0x5ba3f0
// 005ba5b5  83c40c               add esp, 0xc
// 005ba5b8  5f                   pop edi
// 005ba5b9  5e                   pop esi
// 005ba5ba  c3                   ret 
// library lua-5.1.1/lauxlib.c (function _luaL_checkany)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lauxlib.c
