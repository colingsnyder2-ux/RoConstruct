// from server: 100% by auto
// roc 2007-03 005c7600  unit: seg_005c0000  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c7600
//
// 005c7600  56                   push esi
// 005c7601  8b742408             mov esi, dword ptr [esp + 8]
// 005c7605  e8f6feffff           call 0x5c7500
// 005c760a  68f0a27b00           push 0x7ba2f0
// 005c760f  68f4a57b00           push 0x7ba5f4
// 005c7614  56                   push esi
// 005c7615  e85633ffff           call 0x5ba970
// 005c761a  83c40c               add esp, 0xc
// 005c761d  b802000000           mov eax, 2
// 005c7622  5e                   pop esi
// 005c7623  c3                   ret 
// library lua-5.1.1/lbaselib.c (function _luaopen_base)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lbaselib.c
