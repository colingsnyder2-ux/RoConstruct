// from server: 100% by auto
// roc 2007-03 005c4e20  unit: seg_005c0000  size: 109 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c4e20
//
// 005c4e20  56                   push esi
// 005c4e21  8bf0                 mov esi, eax
// 005c4e23  0fbe06               movsx eax, byte ptr [esi]
// 005c4e26  83c601               add esi, 1
// 005c4e29  83f825               cmp eax, 0x25
// 005c4e2c  7444                 je 0x5c4e72
// 005c4e2e  83f85b               cmp eax, 0x5b
// 005c4e31  7404                 je 0x5c4e37
// 005c4e33  8bc6                 mov eax, esi
// 005c4e35  5e                   pop esi
// 005c4e36  c3                   ret 
// 005c4e37  803e5e               cmp byte ptr [esi], 0x5e
// 005c4e3a  7504                 jne 0x5c4e40
// 005c4e3c  83c601               add esi, 1
// 005c4e3f  90                   nop 
// 005c4e40  803e00               cmp byte ptr [esi], 0
// 005c4e43  7511                 jne 0x5c4e56
// 005c4e45  8b4708               mov eax, dword ptr [edi + 8]
// 005c4e48  68bc9f7b00           push 0x7b9fbc
// 005c4e4d  50                   push eax
// 005c4e4e  e8fd4cffff           call 0x5b9b50
// 005c4e53  83c408               add esp, 8
// 005c4e56  8a0e                 mov cl, byte ptr [esi]
// 005c4e58  83c601               add esi, 1
// 005c4e5b  80f925               cmp cl, 0x25
// 005c4e5e  7508                 jne 0x5c4e68
// 005c4e60  803e00               cmp byte ptr [esi], 0
// 005c4e63  7403                 je 0x5c4e68
// 005c4e65  83c601               add esi, 1
// 005c4e68  803e5d               cmp byte ptr [esi], 0x5d
// 005c4e6b  75d3                 jne 0x5c4e40
// 005c4e6d  8d4601               lea eax, [esi + 1]
// 005c4e70  5e                   pop esi
// 005c4e71  c3                   ret 
// 005c4e72  803e00               cmp byte ptr [esi], 0
// 005c4e75  7511                 jne 0x5c4e88
// 005c4e77  8b5708               mov edx, dword ptr [edi + 8]
// 005c4e7a  68989f7b00           push 0x7b9f98
// 005c4e7f  52                   push edx
// 005c4e80  e8cb4cffff           call 0x5b9b50
// 005c4e85  83c408               add esp, 8
// 005c4e88  8d4601               lea eax, [esi + 1]
// 005c4e8b  5e                   pop esi
// 005c4e8c  c3                   ret 
// library lua-5.1.1/lstrlib.c (function _classend)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lstrlib.c
