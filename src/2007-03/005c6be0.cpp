// from server: 100% by auto
// roc 2007-03 005c6be0  unit: seg_005c0000  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c6be0
//
// 005c6be0  56                   push esi
// 005c6be1  8b742408             mov esi, dword ptr [esp + 8]
// 005c6be5  6a05                 push 5
// 005c6be7  6a01                 push 1
// 005c6be9  56                   push esi
// 005c6bea  e85139ffff           call 0x5ba540
// 005c6bef  68edd8ffff           push 0xffffd8ed
// 005c6bf4  56                   push esi
// 005c6bf5  e81620ffff           call 0x5b8c10
// 005c6bfa  6a01                 push 1
// 005c6bfc  56                   push esi
// 005c6bfd  e80e20ffff           call 0x5b8c10
// 005c6c02  6a00                 push 0
// 005c6c04  56                   push esi
// 005c6c05  e85624ffff           call 0x5b9060
// 005c6c0a  83c424               add esp, 0x24
// 005c6c0d  b803000000           mov eax, 3
// 005c6c12  5e                   pop esi
// 005c6c13  c3                   ret 
// library lua-5.1.1/lbaselib.c (function _luaB_ipairs)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lbaselib.c
