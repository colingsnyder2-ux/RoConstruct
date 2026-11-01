// from server: 100% by auto
// roc 2007-03 005c1650  unit: seg_005c0000  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c1650
//
// 005c1650  6a01                 push 1
// 005c1652  56                   push esi
// 005c1653  e8f87dffff           call 0x5b9450
// 005c1658  681c997b00           push 0x7b991c
// 005c165d  6aff                 push -1
// 005c165f  56                   push esi
// 005c1660  e86b7cffff           call 0x5b92d0
// 005c1665  83c414               add esp, 0x14
// 005c1668  56                   push esi
// 005c1669  6aff                 push -1
// 005c166b  56                   push esi
// 005c166c  e8bf78ffff           call 0x5b8f30
// 005c1671  83c408               add esp, 8
// 005c1674  ffd0                 call eax
// 005c1676  83c404               add esp, 4
// 005c1679  c3                   ret 
// library lua-5.1.1/liolib.c (function _aux_close)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 liolib.c
