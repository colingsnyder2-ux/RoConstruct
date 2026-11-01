// from server: 100% by auto
// roc 2007-03 005c71d0  unit: seg_005c0000  size: 173 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c71d0
//
// 005c71d0  53                   push ebx
// 005c71d1  8bd8                 mov ebx, eax
// 005c71d3  53                   push ebx
// 005c71d4  56                   push esi
// 005c71d5  e85617ffff           call 0x5b8930
// 005c71da  83c408               add esp, 8
// 005c71dd  85c0                 test eax, eax
// 005c71df  750e                 jne 0x5c71ef
// 005c71e1  6854a57b00           push 0x7ba554
// 005c71e6  57                   push edi
// 005c71e7  e86429ffff           call 0x5b9b50
// 005c71ec  83c408               add esp, 8
// 005c71ef  56                   push esi
// 005c71f0  e8bb26ffff           call 0x5b98b0
// 005c71f5  83c404               add esp, 4
// 005c71f8  85c0                 test eax, eax
// 005c71fa  7522                 jne 0x5c721e
// 005c71fc  56                   push esi
// 005c71fd  e84e18ffff           call 0x5b8a50
// 005c7202  83c404               add esp, 4
// 005c7205  85c0                 test eax, eax
// 005c7207  7515                 jne 0x5c721e
// 005c7209  6a1c                 push 0x1c
// 005c720b  689c977b00           push 0x7b979c
// 005c7210  57                   push edi
// 005c7211  e86a1effff           call 0x5b9080
// 005c7216  83c40c               add esp, 0xc
// 005c7219  83c8ff               or eax, 0xffffffff
// 005c721c  5b                   pop ebx
// 005c721d  c3                   ret 
// 005c721e  53                   push ebx
// 005c721f  56                   push esi
// 005c7220  57                   push edi
// 005c7221  e86a17ffff           call 0x5b8990
// 005c7226  53                   push ebx
// 005c7227  56                   push esi
// 005c7228  e88393ffff           call 0x5c05b0
// 005c722d  83c414               add esp, 0x14
// 005c7230  85c0                 test eax, eax
// 005c7232  7416                 je 0x5c724a
// 005c7234  83f801               cmp eax, 1
// 005c7237  7411                 je 0x5c724a
// 005c7239  6a01                 push 1
// 005c723b  57                   push edi
// 005c723c  56                   push esi
// 005c723d  e84e17ffff           call 0x5b8990
// 005c7242  83c40c               add esp, 0xc
// 005c7245  83c8ff               or eax, 0xffffffff
// 005c7248  5b                   pop ebx
// 005c7249  c3                   ret 
// 005c724a  56                   push esi
// 005c724b  e80018ffff           call 0x5b8a50
// 005c7250  8bd8                 mov ebx, eax
// 005c7252  53                   push ebx
// 005c7253  57                   push edi
// 005c7254  e8d716ffff           call 0x5b8930
// 005c7259  83c40c               add esp, 0xc
// 005c725c  85c0                 test eax, eax
// 005c725e  750e                 jne 0x5c726e
// 005c7260  6838a57b00           push 0x7ba538
// 005c7265  57                   push edi
// 005c7266  e8e528ffff           call 0x5b9b50
// 005c726b  83c408               add esp, 8
// 005c726e  53                   push ebx
// 005c726f  57                   push edi
// 005c7270  56                   push esi
// 005c7271  e81a17ffff           call 0x5b8990
// 005c7276  83c40c               add esp, 0xc
// 005c7279  8bc3                 mov eax, ebx
// 005c727b  5b                   pop ebx
// 005c727c  c3                   ret 
// library lua-5.1.1/lbaselib.c (function _auxresume)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lbaselib.c
