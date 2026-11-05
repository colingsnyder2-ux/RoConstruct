// from server: 100% by auto
// roc 2007-08 005cc640  unit: seg_005c0000  size: 206 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005cc640
//
// 005cc640  83ec64               sub esp, 0x64
// 005cc643  56                   push esi
// 005cc644  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 005cc648  57                   push edi
// 005cc649  6a01                 push 1
// 005cc64b  56                   push esi
// 005cc64c  e86f14ffff           call 0x5bdac0
// 005cc651  8bf8                 mov edi, eax
// 005cc653  83c408               add esp, 8
// 005cc656  85ff                 test edi, edi
// 005cc658  7510                 jne 0x5cc66a
// 005cc65a  68d4a47b00           push 0x7ba4d4
// 005cc65f  6a01                 push 1
// 005cc661  56                   push esi
// 005cc662  e8192bffff           call 0x5bf180
// 005cc667  83c40c               add esp, 0xc
// 005cc66a  3bf7                 cmp esi, edi
// 005cc66c  751b                 jne 0x5cc689
// 005cc66e  6a07                 push 7
// 005cc670  68b0a07b00           push 0x7ba0b0
// 005cc675  56                   push esi
// 005cc676  e83515ffff           call 0x5bdbb0
// 005cc67b  83c40c               add esp, 0xc
// 005cc67e  5f                   pop edi
// 005cc67f  b801000000           mov eax, 1
// 005cc684  5e                   pop esi
// 005cc685  83c464               add esp, 0x64
// 005cc688  c3                   ret 
// 005cc689  57                   push edi
// 005cc68a  e8511dffff           call 0x5be3e0
// 005cc68f  83c404               add esp, 4
// 005cc692  83e800               sub eax, 0
// 005cc695  7420                 je 0x5cc6b7
// 005cc697  83e801               sub eax, 1
// 005cc69a  7457                 je 0x5cc6f3
// 005cc69c  6a04                 push 4
// 005cc69e  6814a57b00           push 0x7ba514
// 005cc6a3  56                   push esi
// 005cc6a4  e80715ffff           call 0x5bdbb0
// 005cc6a9  83c40c               add esp, 0xc
// 005cc6ac  5f                   pop edi
// 005cc6ad  b801000000           mov eax, 1
// 005cc6b2  5e                   pop esi
// 005cc6b3  83c464               add esp, 0x64
// 005cc6b6  c3                   ret 
// 005cc6b7  8d442408             lea eax, [esp + 8]
// 005cc6bb  50                   push eax
// 005cc6bc  6a00                 push 0
// 005cc6be  57                   push edi
// 005cc6bf  e84c9fffff           call 0x5c6610
// 005cc6c4  83c40c               add esp, 0xc
// 005cc6c7  85c0                 test eax, eax
// 005cc6c9  7e1b                 jle 0x5cc6e6
// 005cc6cb  6a06                 push 6
// 005cc6cd  680ca57b00           push 0x7ba50c
// 005cc6d2  56                   push esi
// 005cc6d3  e8d814ffff           call 0x5bdbb0
// 005cc6d8  83c40c               add esp, 0xc
// 005cc6db  5f                   pop edi
// 005cc6dc  b801000000           mov eax, 1
// 005cc6e1  5e                   pop esi
// 005cc6e2  83c464               add esp, 0x64
// 005cc6e5  c3                   ret 
// 005cc6e6  57                   push edi
// 005cc6e7  e8940effff           call 0x5bd580
// 005cc6ec  83c404               add esp, 4
// 005cc6ef  85c0                 test eax, eax
// 005cc6f1  74a9                 je 0x5cc69c
// 005cc6f3  6a09                 push 9
// 005cc6f5  6800a57b00           push 0x7ba500
// 005cc6fa  56                   push esi
// 005cc6fb  e8b014ffff           call 0x5bdbb0
// 005cc700  83c40c               add esp, 0xc
// 005cc703  5f                   pop edi
// 005cc704  b801000000           mov eax, 1
// 005cc709  5e                   pop esi
// 005cc70a  83c464               add esp, 0x64
// 005cc70d  c3                   ret 
// library lua-5.1.2/lbaselib.c (function _luaB_costatus)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.2 lbaselib.c
