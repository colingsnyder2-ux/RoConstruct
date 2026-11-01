// from server: 100% by auto
// roc 2007-03 005c14b0  unit: seg_005c0000  size: 149 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c14b0
//
// 005c14b0  56                   push esi
// 005c14b1  8b742408             mov esi, dword ptr [esp + 8]
// 005c14b5  57                   push edi
// 005c14b6  6a01                 push 1
// 005c14b8  56                   push esi
// 005c14b9  e8d290ffff           call 0x5ba590
// 005c14be  6a01                 push 1
// 005c14c0  56                   push esi
// 005c14c1  e89a7affff           call 0x5b8f60
// 005c14c6  68f4987b00           push 0x7b98f4
// 005c14cb  68f0d8ffff           push 0xffffd8f0
// 005c14d0  56                   push esi
// 005c14d1  8bf8                 mov edi, eax
// 005c14d3  e8f87dffff           call 0x5b92d0
// 005c14d8  83c41c               add esp, 0x1c
// 005c14db  85ff                 test edi, edi
// 005c14dd  7455                 je 0x5c1534
// 005c14df  6a01                 push 1
// 005c14e1  56                   push esi
// 005c14e2  e8097fffff           call 0x5b93f0
// 005c14e7  83c408               add esp, 8
// 005c14ea  85c0                 test eax, eax
// 005c14ec  7446                 je 0x5c1534
// 005c14ee  6aff                 push -1
// 005c14f0  6afe                 push -2
// 005c14f2  56                   push esi
// 005c14f3  e82878ffff           call 0x5b8d20
// 005c14f8  83c40c               add esp, 0xc
// 005c14fb  85c0                 test eax, eax
// 005c14fd  7435                 je 0x5c1534
// 005c14ff  833f00               cmp dword ptr [edi], 0
// 005c1502  7518                 jne 0x5c151c
// 005c1504  6a0b                 push 0xb
// 005c1506  68e8987b00           push 0x7b98e8
// 005c150b  56                   push esi
// 005c150c  e86f7bffff           call 0x5b9080
// 005c1511  83c40c               add esp, 0xc
// 005c1514  5f                   pop edi
// 005c1515  b801000000           mov eax, 1
// 005c151a  5e                   pop esi
// 005c151b  c3                   ret 
// 005c151c  6a04                 push 4
// 005c151e  6824607800           push 0x786024
// 005c1523  56                   push esi
// 005c1524  e8577bffff           call 0x5b9080
// 005c1529  83c40c               add esp, 0xc
// 005c152c  5f                   pop edi
// 005c152d  b801000000           mov eax, 1
// 005c1532  5e                   pop esi
// 005c1533  c3                   ret 
// 005c1534  56                   push esi
// 005c1535  e8e67affff           call 0x5b9020
// 005c153a  83c404               add esp, 4
// 005c153d  5f                   pop edi
// 005c153e  b801000000           mov eax, 1
// 005c1543  5e                   pop esi
// 005c1544  c3                   ret 
// library lua-5.1.1/liolib.c (function _io_type)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 liolib.c
