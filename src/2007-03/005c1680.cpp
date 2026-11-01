// from server: 100% by auto
// roc 2007-03 005c1680  unit: seg_005c0000  size: 115 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c1680
//
// 005c1680  56                   push esi
// 005c1681  8b742408             mov esi, dword ptr [esp + 8]
// 005c1685  6a01                 push 1
// 005c1687  56                   push esi
// 005c1688  e8b375ffff           call 0x5b8c40
// 005c168d  83c408               add esp, 8
// 005c1690  83f8ff               cmp eax, -1
// 005c1693  7510                 jne 0x5c16a5
// 005c1695  6a02                 push 2
// 005c1697  68efd8ffff           push 0xffffd8ef
// 005c169c  56                   push esi
// 005c169d  e8ce7cffff           call 0x5b9370
// 005c16a2  83c40c               add esp, 0xc
// 005c16a5  68f4987b00           push 0x7b98f4
// 005c16aa  6a01                 push 1
// 005c16ac  56                   push esi
// 005c16ad  e8fe8dffff           call 0x5ba4b0
// 005c16b2  83c40c               add esp, 0xc
// 005c16b5  833800               cmp dword ptr [eax], 0
// 005c16b8  750e                 jne 0x5c16c8
// 005c16ba  68fc987b00           push 0x7b98fc
// 005c16bf  56                   push esi
// 005c16c0  e88b84ffff           call 0x5b9b50
// 005c16c5  83c408               add esp, 8
// 005c16c8  6a01                 push 1
// 005c16ca  56                   push esi
// 005c16cb  e8807dffff           call 0x5b9450
// 005c16d0  681c997b00           push 0x7b991c
// 005c16d5  6aff                 push -1
// 005c16d7  56                   push esi
// 005c16d8  e8f37bffff           call 0x5b92d0
// 005c16dd  83c414               add esp, 0x14
// 005c16e0  56                   push esi
// 005c16e1  6aff                 push -1
// 005c16e3  56                   push esi
// 005c16e4  e84778ffff           call 0x5b8f30
// 005c16e9  83c408               add esp, 8
// 005c16ec  ffd0                 call eax
// 005c16ee  83c404               add esp, 4
// 005c16f1  5e                   pop esi
// 005c16f2  c3                   ret 
// library lua-5.1.1/liolib.c (function _io_close)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 liolib.c
