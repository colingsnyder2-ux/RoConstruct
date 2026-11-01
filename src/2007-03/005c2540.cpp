// from server: 100% by auto
// roc 2007-03 005c2540  unit: seg_005c0000  size: 79 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c2540
//
// 005c2540  56                   push esi
// 005c2541  8b742408             mov esi, dword ptr [esp + 8]
// 005c2545  68f4987b00           push 0x7b98f4
// 005c254a  6a01                 push 1
// 005c254c  56                   push esi
// 005c254d  e85e7fffff           call 0x5ba4b0
// 005c2552  83c40c               add esp, 0xc
// 005c2555  833800               cmp dword ptr [eax], 0
// 005c2558  750e                 jne 0x5c2568
// 005c255a  68fc987b00           push 0x7b98fc
// 005c255f  56                   push esi
// 005c2560  e8eb75ffff           call 0x5b9b50
// 005c2565  83c408               add esp, 8
// 005c2568  6a01                 push 1
// 005c256a  56                   push esi
// 005c256b  e8a066ffff           call 0x5b8c10
// 005c2570  6a00                 push 0
// 005c2572  56                   push esi
// 005c2573  e8b86cffff           call 0x5b9230
// 005c2578  6a02                 push 2
// 005c257a  68b01e5c00           push 0x5c1eb0
// 005c257f  56                   push esi
// 005c2580  e80b6cffff           call 0x5b9190
// 005c2585  83c41c               add esp, 0x1c
// 005c2588  b801000000           mov eax, 1
// 005c258d  5e                   pop esi
// 005c258e  c3                   ret 
// library lua-5.1.1/liolib.c (function _f_lines)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 liolib.c
