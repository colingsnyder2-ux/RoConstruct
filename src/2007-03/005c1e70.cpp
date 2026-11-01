// from server: 100% by auto
// roc 2007-03 005c1e70  unit: seg_005c0000  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c1e70
//
// 005c1e70  56                   push esi
// 005c1e71  8b742408             mov esi, dword ptr [esp + 8]
// 005c1e75  57                   push edi
// 005c1e76  68f4987b00           push 0x7b98f4
// 005c1e7b  6a01                 push 1
// 005c1e7d  56                   push esi
// 005c1e7e  e82d86ffff           call 0x5ba4b0
// 005c1e83  8bf8                 mov edi, eax
// 005c1e85  83c40c               add esp, 0xc
// 005c1e88  833f00               cmp dword ptr [edi], 0
// 005c1e8b  750e                 jne 0x5c1e9b
// 005c1e8d  68fc987b00           push 0x7b98fc
// 005c1e92  56                   push esi
// 005c1e93  e8b87cffff           call 0x5b9b50
// 005c1e98  83c408               add esp, 8
// 005c1e9b  8b07                 mov eax, dword ptr [edi]
// 005c1e9d  6a02                 push 2
// 005c1e9f  e8dcfdffff           call 0x5c1c80
// 005c1ea4  83c404               add esp, 4
// 005c1ea7  5f                   pop edi
// 005c1ea8  5e                   pop esi
// 005c1ea9  c3                   ret 
// library lua-5.1.1/liolib.c (function _f_read)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 liolib.c
