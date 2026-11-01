// from server: 100% by auto
// roc 2011-06 007d6b60  unit: RBX::EquationDisplay  size: 148 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 007d6b60
//
// 007d6b60  0fb65004             movzx edx, byte ptr [eax + 4]
// 007d6b64  83c2fc               add edx, -4
// 007d6b67  83fa06               cmp edx, 6
// 007d6b6a  776b                 ja 0x7d6bd7
// 007d6b6c  ff2495d86b7d00       jmp dword ptr [edx*4 + 0x7d6bd8]
// 007d6b73  50                   push eax
// 007d6b74  51                   push ecx
// 007d6b75  e8b63a0000           call 0x7da630
// 007d6b7a  83c408               add esp, 8
// 007d6b7d  c3                   ret 
// 007d6b7e  50                   push eax
// 007d6b7f  51                   push ecx
// 007d6b80  e84b3b0000           call 0x7da6d0
// 007d6b85  83c408               add esp, 8
// 007d6b88  c3                   ret 
// 007d6b89  50                   push eax
// 007d6b8a  51                   push ecx
// 007d6b8b  e850390000           call 0x7da4e0
// 007d6b90  83c408               add esp, 8
// 007d6b93  c3                   ret 
// 007d6b94  50                   push eax
// 007d6b95  51                   push ecx
// 007d6b96  e8d52c0000           call 0x7d9870
// 007d6b9b  83c408               add esp, 8
// 007d6b9e  c3                   ret 
// 007d6b9f  50                   push eax
// 007d6ba0  51                   push ecx
// 007d6ba1  e84a86faff           call 0x77f1f0
// 007d6ba6  83c408               add esp, 8
// 007d6ba9  c3                   ret 
// 007d6baa  8b5110               mov edx, dword ptr [ecx + 0x10]
// 007d6bad  ff4a04               dec dword ptr [edx + 4]
// 007d6bb0  8b500c               mov edx, dword ptr [eax + 0xc]
// 007d6bb3  6a00                 push 0
// 007d6bb5  83c211               add edx, 0x11
// 007d6bb8  52                   push edx
// 007d6bb9  50                   push eax
// 007d6bba  51                   push ecx
// 007d6bbb  e880420000           call 0x7dae40
// 007d6bc0  83c410               add esp, 0x10
// 007d6bc3  c3                   ret 
// 007d6bc4  8b5010               mov edx, dword ptr [eax + 0x10]
// 007d6bc7  6a00                 push 0
// 007d6bc9  83c218               add edx, 0x18
// 007d6bcc  52                   push edx
// 007d6bcd  50                   push eax
// 007d6bce  51                   push ecx
// 007d6bcf  e86c420000           call 0x7dae40
// 007d6bd4  83c410               add esp, 0x10
// 007d6bd7  c3                   ret 
// 007d6bd8  aa                   stosb byte ptr es:[edi], al
// 007d6bd9  6b7d0094             imul edi, dword ptr [ebp], -0x6c
// 007d6bdd  6b7d007e             imul edi, dword ptr [ebp], 0x7e
// 007d6be1  6b7d00c4             imul edi, dword ptr [ebp], -0x3c
// 007d6be5  6b7d009f             imul edi, dword ptr [ebp], -0x61
// 007d6be9  6b7d0073             imul edi, dword ptr [ebp], 0x73
// 007d6bed  6b7d0089             imul edi, dword ptr [ebp], -0x77
// library lua-5.1/lgc.c (function _freeobj)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lgc.c
