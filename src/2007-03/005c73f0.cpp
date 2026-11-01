// from server: 100% by auto
// roc 2007-03 005c73f0  unit: seg_005c0000  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c73f0
//
// 005c73f0  56                   push esi
// 005c73f1  8b742408             mov esi, dword ptr [esp + 8]
// 005c73f5  56                   push esi
// 005c73f6  e85516ffff           call 0x5b8a50
// 005c73fb  50                   push eax
// 005c73fc  56                   push esi
// 005c73fd  e86e8cffff           call 0x5c0070
// 005c7402  83c40c               add esp, 0xc
// 005c7405  5e                   pop esi
// 005c7406  c3                   ret 
// library lua-5.1.1/lbaselib.c (function _luaB_yield)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lbaselib.c
