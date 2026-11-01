// from server: 100% by auto
// roc 2007-03 005c6fa0  unit: seg_005c0000  size: 74 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c6fa0
//
// 005c6fa0  56                   push esi
// 005c6fa1  8b742408             mov esi, dword ptr [esp + 8]
// 005c6fa5  6a02                 push 2
// 005c6fa7  56                   push esi
// 005c6fa8  e8e335ffff           call 0x5ba590
// 005c6fad  6a02                 push 2
// 005c6faf  56                   push esi
// 005c6fb0  e8ab1affff           call 0x5b8a60
// 005c6fb5  6a01                 push 1
// 005c6fb7  56                   push esi
// 005c6fb8  e8431bffff           call 0x5b8b00
// 005c6fbd  6a01                 push 1
// 005c6fbf  6aff                 push -1
// 005c6fc1  6a00                 push 0
// 005c6fc3  56                   push esi
// 005c6fc4  e8f727ffff           call 0x5b97c0
// 005c6fc9  33c9                 xor ecx, ecx
// 005c6fcb  85c0                 test eax, eax
// 005c6fcd  0f94c1               sete cl
// 005c6fd0  51                   push ecx
// 005c6fd1  56                   push esi
// 005c6fd2  e85922ffff           call 0x5b9230
// 005c6fd7  6a01                 push 1
// 005c6fd9  56                   push esi
// 005c6fda  e8711bffff           call 0x5b8b50
// 005c6fdf  56                   push esi
// 005c6fe0  e86b1affff           call 0x5b8a50
// 005c6fe5  83c43c               add esp, 0x3c
// 005c6fe8  5e                   pop esi
// 005c6fe9  c3                   ret 
// library lua-5.1.1/lbaselib.c (function _luaB_xpcall)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lbaselib.c
