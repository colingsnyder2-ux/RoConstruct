// from server: 100% by auto
// roc 2008-06 00628b20  unit: seg_00620000  size: 173 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00628b20
//
// 00628b20  53                   push ebx
// 00628b21  8bd8                 mov ebx, eax
// 00628b23  53                   push ebx
// 00628b24  56                   push esi
// 00628b25  e81690feff           call 0x611b40
// 00628b2a  83c408               add esp, 8
// 00628b2d  85c0                 test eax, eax
// 00628b2f  750e                 jne 0x628b3f
// 00628b31  6840578400           push 0x845740
// 00628b36  57                   push edi
// 00628b37  e82481feff           call 0x610c60
// 00628b3c  83c408               add esp, 8
// 00628b3f  56                   push esi
// 00628b40  e82b9ffeff           call 0x612a70
// 00628b45  83c404               add esp, 4
// 00628b48  85c0                 test eax, eax
// 00628b4a  7522                 jne 0x628b6e
// 00628b4c  56                   push esi
// 00628b4d  e8be90feff           call 0x611c10
// 00628b52  83c404               add esp, 4
// 00628b55  85c0                 test eax, eax
// 00628b57  7515                 jne 0x628b6e
// 00628b59  6a1c                 push 0x1c
// 00628b5b  685c488400           push 0x84485c
// 00628b60  57                   push edi
// 00628b61  e8da96feff           call 0x612240
// 00628b66  83c40c               add esp, 0xc
// 00628b69  83c8ff               or eax, 0xffffffff
// 00628b6c  5b                   pop ebx
// 00628b6d  c3                   ret 
// 00628b6e  53                   push ebx
// 00628b6f  56                   push esi
// 00628b70  57                   push edi
// 00628b71  e82a90feff           call 0x611ba0
// 00628b76  53                   push ebx
// 00628b77  56                   push esi
// 00628b78  e88398ffff           call 0x622400
// 00628b7d  83c414               add esp, 0x14
// 00628b80  85c0                 test eax, eax
// 00628b82  7416                 je 0x628b9a
// 00628b84  83f801               cmp eax, 1
// 00628b87  7411                 je 0x628b9a
// 00628b89  6a01                 push 1
// 00628b8b  57                   push edi
// 00628b8c  56                   push esi
// 00628b8d  e80e90feff           call 0x611ba0
// 00628b92  83c40c               add esp, 0xc
// 00628b95  83c8ff               or eax, 0xffffffff
// 00628b98  5b                   pop ebx
// 00628b99  c3                   ret 
// 00628b9a  56                   push esi
// 00628b9b  e87090feff           call 0x611c10
// 00628ba0  8bd8                 mov ebx, eax
// 00628ba2  53                   push ebx
// 00628ba3  57                   push edi
// 00628ba4  e8978ffeff           call 0x611b40
// 00628ba9  83c40c               add esp, 0xc
// 00628bac  85c0                 test eax, eax
// 00628bae  750e                 jne 0x628bbe
// 00628bb0  6824578400           push 0x845724
// 00628bb5  57                   push edi
// 00628bb6  e8a580feff           call 0x610c60
// 00628bbb  83c408               add esp, 8
// 00628bbe  53                   push ebx
// 00628bbf  57                   push edi
// 00628bc0  56                   push esi
// 00628bc1  e8da8ffeff           call 0x611ba0
// 00628bc6  83c40c               add esp, 0xc
// 00628bc9  8bc3                 mov eax, ebx
// 00628bcb  5b                   pop ebx
// 00628bcc  c3                   ret 
// library lua-5.1.2/lbaselib.c (function _auxresume)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.2 lbaselib.c
