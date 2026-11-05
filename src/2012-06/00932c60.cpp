// roc 2012-06 00932c60  unit: RBX::BallCellContact  size: 148 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00932c60
//
// 00932c60  0fb65004             movzx edx, byte ptr [eax + 4]
// 00932c64  83c2fc               add edx, -4
// 00932c67  83fa06               cmp edx, 6
// 00932c6a  776b                 ja 0x932cd7
// 00932c6c  ff2495d82c9300       jmp dword ptr [edx*4 + 0x932cd8]
// 00932c73  50                   push eax
// 00932c74  51                   push ecx
// 00932c75  e8d63a0000           call 0x936750
// 00932c7a  83c408               add esp, 8
// 00932c7d  c3                   ret 
// 00932c7e  50                   push eax
// 00932c7f  51                   push ecx
// 00932c80  e86b3b0000           call 0x9367f0
// 00932c85  83c408               add esp, 8
// 00932c88  c3                   ret 
// 00932c89  50                   push eax
// 00932c8a  51                   push ecx
// 00932c8b  e870390000           call 0x936600
// 00932c90  83c408               add esp, 8
// 00932c93  c3                   ret 
// 00932c94  50                   push eax
// 00932c95  51                   push ecx
// 00932c96  e8e52c0000           call 0x935980
// 00932c9b  83c408               add esp, 8
// 00932c9e  c3                   ret 
// 00932c9f  50                   push eax
// 00932ca0  51                   push ecx
// 00932ca1  e8ea14f2ff           call 0x854190
// 00932ca6  83c408               add esp, 8
// 00932ca9  c3                   ret 
// 00932caa  8b5110               mov edx, dword ptr [ecx + 0x10]
// 00932cad  ff4a04               dec dword ptr [edx + 4]
// 00932cb0  8b500c               mov edx, dword ptr [eax + 0xc]
// 00932cb3  6a00                 push 0
// 00932cb5  83c211               add edx, 0x11
// 00932cb8  52                   push edx
// 00932cb9  50                   push eax
// 00932cba  51                   push ecx
// 00932cbb  e8a0420000           call 0x936f60
// 00932cc0  83c410               add esp, 0x10
// 00932cc3  c3                   ret 
// 00932cc4  8b5010               mov edx, dword ptr [eax + 0x10]
// 00932cc7  6a00                 push 0
// 00932cc9  83c218               add edx, 0x18
// 00932ccc  52                   push edx
// 00932ccd  50                   push eax
// 00932cce  51                   push ecx
// 00932ccf  e88c420000           call 0x936f60
// 00932cd4  83c410               add esp, 0x10
// 00932cd7  c3                   ret 
// 00932cd8  aa                   stosb byte ptr es:[edi], al
// 00932cd9  2c93                 sub al, 0x93
// 00932cdb  00942c93007e2c       add byte ptr [esp + ebp + 0x2c7e0093], dl
// 00932ce2  93                   xchg ebx, eax
// 00932ce3  00c4                 add ah, al
// 00932ce5  2c93                 sub al, 0x93
// 00932ce7  009f2c930073         add byte ptr [edi + 0x7300932c], bl
// 00932ced  2c93                 sub al, 0x93
// library lua-5.1/lgc.c (function _freeobj)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lgc.c
