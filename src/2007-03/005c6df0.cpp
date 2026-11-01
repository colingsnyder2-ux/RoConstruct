// from server: 100% by auto
// roc 2007-03 005c6df0  unit: seg_005c0000  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c6df0
//
// 005c6df0  56                   push esi
// 005c6df1  8b742408             mov esi, dword ptr [esp + 8]
// 005c6df5  6a01                 push 1
// 005c6df7  56                   push esi
// 005c6df8  e89337ffff           call 0x5ba590
// 005c6dfd  6a01                 push 1
// 005c6dff  56                   push esi
// 005c6e00  e81b20ffff           call 0x5b8e20
// 005c6e05  83c410               add esp, 0x10
// 005c6e08  85c0                 test eax, eax
// 005c6e0a  751f                 jne 0x5c6e2b
// 005c6e0c  50                   push eax
// 005c6e0d  68d4a47b00           push 0x7ba4d4
// 005c6e12  6a02                 push 2
// 005c6e14  56                   push esi
// 005c6e15  e80638ffff           call 0x5ba620
// 005c6e1a  50                   push eax
// 005c6e1b  6844927800           push 0x789244
// 005c6e20  56                   push esi
// 005c6e21  e82a2dffff           call 0x5b9b50
// 005c6e26  83c41c               add esp, 0x1c
// 005c6e29  5e                   pop esi
// 005c6e2a  c3                   ret 
// 005c6e2b  56                   push esi
// 005c6e2c  e81f1cffff           call 0x5b8a50
// 005c6e31  83c404               add esp, 4
// 005c6e34  5e                   pop esi
// 005c6e35  c3                   ret 
// library lua-5.1.1/lbaselib.c (function _luaB_assert)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lbaselib.c
