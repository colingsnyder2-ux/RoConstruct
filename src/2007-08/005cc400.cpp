// from server: 100% by auto
// roc 2007-08 005cc400  unit: seg_005c0000  size: 173 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005cc400
//
// 005cc400  53                   push ebx
// 005cc401  8bd8                 mov ebx, eax
// 005cc403  53                   push ebx
// 005cc404  56                   push esi
// 005cc405  e8a610ffff           call 0x5bd4b0
// 005cc40a  83c408               add esp, 8
// 005cc40d  85c0                 test eax, eax
// 005cc40f  750e                 jne 0x5cc41f
// 005cc411  68b4a47b00           push 0x7ba4b4
// 005cc416  57                   push edi
// 005cc417  e8c424ffff           call 0x5be8e0
// 005cc41c  83c408               add esp, 8
// 005cc41f  56                   push esi
// 005cc420  e8bb1fffff           call 0x5be3e0
// 005cc425  83c404               add esp, 4
// 005cc428  85c0                 test eax, eax
// 005cc42a  7522                 jne 0x5cc44e
// 005cc42c  56                   push esi
// 005cc42d  e84e11ffff           call 0x5bd580
// 005cc432  83c404               add esp, 4
// 005cc435  85c0                 test eax, eax
// 005cc437  7515                 jne 0x5cc44e
// 005cc439  6a1c                 push 0x1c
// 005cc43b  680c977b00           push 0x7b970c
// 005cc440  57                   push edi
// 005cc441  e86a17ffff           call 0x5bdbb0
// 005cc446  83c40c               add esp, 0xc
// 005cc449  83c8ff               or eax, 0xffffffff
// 005cc44c  5b                   pop ebx
// 005cc44d  c3                   ret 
// 005cc44e  53                   push ebx
// 005cc44f  56                   push esi
// 005cc450  57                   push edi
// 005cc451  e8ba10ffff           call 0x5bd510
// 005cc456  53                   push ebx
// 005cc457  56                   push esi
// 005cc458  e8739fffff           call 0x5c63d0
// 005cc45d  83c414               add esp, 0x14
// 005cc460  85c0                 test eax, eax
// 005cc462  7416                 je 0x5cc47a
// 005cc464  83f801               cmp eax, 1
// 005cc467  7411                 je 0x5cc47a
// 005cc469  6a01                 push 1
// 005cc46b  57                   push edi
// 005cc46c  56                   push esi
// 005cc46d  e89e10ffff           call 0x5bd510
// 005cc472  83c40c               add esp, 0xc
// 005cc475  83c8ff               or eax, 0xffffffff
// 005cc478  5b                   pop ebx
// 005cc479  c3                   ret 
// 005cc47a  56                   push esi
// 005cc47b  e80011ffff           call 0x5bd580
// 005cc480  8bd8                 mov ebx, eax
// 005cc482  53                   push ebx
// 005cc483  57                   push edi
// 005cc484  e82710ffff           call 0x5bd4b0
// 005cc489  83c40c               add esp, 0xc
// 005cc48c  85c0                 test eax, eax
// 005cc48e  750e                 jne 0x5cc49e
// 005cc490  6898a47b00           push 0x7ba498
// 005cc495  57                   push edi
// 005cc496  e84524ffff           call 0x5be8e0
// 005cc49b  83c408               add esp, 8
// 005cc49e  53                   push ebx
// 005cc49f  57                   push edi
// 005cc4a0  56                   push esi
// 005cc4a1  e86a10ffff           call 0x5bd510
// 005cc4a6  83c40c               add esp, 0xc
// 005cc4a9  8bc3                 mov eax, ebx
// 005cc4ab  5b                   pop ebx
// 005cc4ac  c3                   ret 
// library lua-5.1.2/lbaselib.c (function _auxresume)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.2 lbaselib.c
