// from server: 100% by auto
// roc 2007-03 005c70f0  unit: seg_005c0000  size: 212 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c70f0
//
// 005c70f0  56                   push esi
// 005c70f1  8b742408             mov esi, dword ptr [esp + 8]
// 005c70f5  6a01                 push 1
// 005c70f7  56                   push esi
// 005c70f8  e86319ffff           call 0x5b8a60
// 005c70fd  6a00                 push 0
// 005c70ff  56                   push esi
// 005c7100  e87b29ffff           call 0x5b9a80
// 005c7105  6a01                 push 1
// 005c7107  56                   push esi
// 005c7108  e8131dffff           call 0x5b8e20
// 005c710d  83c418               add esp, 0x18
// 005c7110  85c0                 test eax, eax
// 005c7112  0f84a5000000         je 0x5c71bd
// 005c7118  6a01                 push 1
// 005c711a  56                   push esi
// 005c711b  e8201bffff           call 0x5b8c40
// 005c7120  83c408               add esp, 8
// 005c7123  83f801               cmp eax, 1
// 005c7126  753a                 jne 0x5c7162
// 005c7128  6a00                 push 0
// 005c712a  6a00                 push 0
// 005c712c  56                   push esi
// 005c712d  e87e22ffff           call 0x5b93b0
// 005c7132  6aff                 push -1
// 005c7134  56                   push esi
// 005c7135  e8d61affff           call 0x5b8c10
// 005c713a  6a01                 push 1
// 005c713c  56                   push esi
// 005c713d  e8ee20ffff           call 0x5b9230
// 005c7142  68edd8ffff           push 0xffffd8ed
// 005c7147  56                   push esi
// 005c7148  e80324ffff           call 0x5b9550
// 005c714d  83c424               add esp, 0x24
// 005c7150  6a02                 push 2
// 005c7152  56                   push esi
// 005c7153  e8d824ffff           call 0x5b9630
// 005c7158  83c408               add esp, 8
// 005c715b  b801000000           mov eax, 1
// 005c7160  5e                   pop esi
// 005c7161  c3                   ret 
// 005c7162  6a01                 push 1
// 005c7164  56                   push esi
// 005c7165  e88622ffff           call 0x5b93f0
// 005c716a  83c408               add esp, 8
// 005c716d  85c0                 test eax, eax
// 005c716f  7426                 je 0x5c7197
// 005c7171  57                   push edi
// 005c7172  68edd8ffff           push 0xffffd8ed
// 005c7177  56                   push esi
// 005c7178  e8b321ffff           call 0x5b9330
// 005c717d  6aff                 push -1
// 005c717f  56                   push esi
// 005c7180  e89b1cffff           call 0x5b8e20
// 005c7185  6afe                 push -2
// 005c7187  56                   push esi
// 005c7188  8bf8                 mov edi, eax
// 005c718a  e8d118ffff           call 0x5b8a60
// 005c718f  83c418               add esp, 0x18
// 005c7192  85ff                 test edi, edi
// 005c7194  5f                   pop edi
// 005c7195  7510                 jne 0x5c71a7
// 005c7197  681ca57b00           push 0x7ba51c
// 005c719c  6a01                 push 1
// 005c719e  56                   push esi
// 005c719f  e84c32ffff           call 0x5ba3f0
// 005c71a4  83c40c               add esp, 0xc
// 005c71a7  6a01                 push 1
// 005c71a9  56                   push esi
// 005c71aa  e84122ffff           call 0x5b93f0
// 005c71af  83c408               add esp, 8
// 005c71b2  6a02                 push 2
// 005c71b4  56                   push esi
// 005c71b5  e87624ffff           call 0x5b9630
// 005c71ba  83c408               add esp, 8
// 005c71bd  b801000000           mov eax, 1
// 005c71c2  5e                   pop esi
// 005c71c3  c3                   ret 
// library lua-5.1.1/lbaselib.c (function _luaB_newproxy)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lbaselib.c
