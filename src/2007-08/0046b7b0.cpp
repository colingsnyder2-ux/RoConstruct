// from server: 100% by Intel
// from server: 98% by EspClaude
// roc 2007-08 0046b7b0  unit: RBX::LDraw2Lua::LDrawCommand  size: 560 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0046b7b0
//
// 0046b7b0  6aff                 push -1
// 0046b7b2  68493f7400           push 0x743f49
// 0046b7b7  64a100000000         mov eax, dword ptr fs:[0]
// 0046b7bd  50                   push eax
// 0046b7be  83ec20               sub esp, 0x20
// 0046b7c1  56                   push esi
// 0046b7c2  57                   push edi
// 0046b7c3  a188518b00           mov eax, dword ptr [0x8b5188]
// 0046b7c8  33c4                 xor eax, esp
// 0046b7ca  50                   push eax
// 0046b7cb  8d44242c             lea eax, [esp + 0x2c]
// 0046b7cf  64a300000000         mov dword ptr fs:[0], eax
// 0046b7d5  8b7c243c             mov edi, dword ptr [esp + 0x3c]
// 0046b7d9  8bf1                 mov esi, ecx
// 0046b7db  8d4c2440             lea ecx, [esp + 0x40]
// 0046b7df  c744243400000000     mov dword ptr [esp + 0x34], 0
// 0046b7e7  ff15a8e67700         call dword ptr [0x77e6a8]
// 0046b7ed  50                   push eax
// 0046b7ee  ff153ce97700         call dword ptr [0x77e93c]
// 0046b7f4  dd4610               fld qword ptr [esi + 0x10]
// 0046b7f7  dc35e0627900         fdiv qword ptr [0x7962e0]
// 0046b7fd  83c404               add esp, 4
// 0046b800  6848cc7800           push 0x78cc48
// 0046b805  83ec08               sub esp, 8
// 0046b808  dd4618               fld qword ptr [esi + 0x18]
// 0046b80b  dd05d8627900         fld qword ptr [0x7962d8]
// 0046b811  dcf9                 fdiv st(1), st(0)
// 0046b813  d9c9                 fxch st(1)
// 0046b815  dee3                 fsubrp st(3)
// 0046b817  dc7e20               fdivr qword ptr [esi + 0x20]
// 0046b81a  dd4628               fld qword ptr [esi + 0x28]
// 0046b81d  dd4630               fld qword ptr [esi + 0x30]
// 0046b820  dd4638               fld qword ptr [esi + 0x38]
// 0046b823  dd4640               fld qword ptr [esi + 0x40]
// 0046b826  dd4648               fld qword ptr [esi + 0x48]
// 0046b829  dd5c2430             fstp qword ptr [esp + 0x30]
// 0046b82d  dd4650               fld qword ptr [esi + 0x50]
// 0046b830  dd5c2420             fstp qword ptr [esp + 0x20]
// 0046b834  dd4658               fld qword ptr [esi + 0x58]
// 0046b837  dd5c2418             fstp qword ptr [esp + 0x18]
// 0046b83b  dd4660               fld qword ptr [esi + 0x60]
// 0046b83e  dd5c2428             fstp qword ptr [esp + 0x28]
// 0046b842  dd4668               fld qword ptr [esi + 0x68]
// 0046b845  dd1c24               fstp qword ptr [esp]
// 0046b848  dd442428             fld qword ptr [esp + 0x28]
// 0046b84c  68d0627900           push 0x7962d0
// 0046b851  83ec08               sub esp, 8
// 0046b854  dd1c24               fstp qword ptr [esp]
// 0046b857  dd442424             fld qword ptr [esp + 0x24]
// 0046b85b  68d0627900           push 0x7962d0
// 0046b860  83ec08               sub esp, 8
// 0046b863  dd1c24               fstp qword ptr [esp]
// 0046b866  dd442438             fld qword ptr [esp + 0x38]
// 0046b86a  68d0627900           push 0x7962d0
// 0046b86f  83ec08               sub esp, 8
// 0046b872  dd1c24               fstp qword ptr [esp]
// 0046b875  dd442454             fld qword ptr [esp + 0x54]
// 0046b879  68d0627900           push 0x7962d0
// 0046b87e  83ec08               sub esp, 8
// 0046b881  dd1c24               fstp qword ptr [esp]
// 0046b884  68d0627900           push 0x7962d0
// 0046b889  83ec08               sub esp, 8
// 0046b88c  dd1c24               fstp qword ptr [esp]
// 0046b88f  68d0627900           push 0x7962d0
// 0046b894  83ec08               sub esp, 8
// 0046b897  dd1c24               fstp qword ptr [esp]
// 0046b89a  68d0627900           push 0x7962d0
// 0046b89f  83ec08               sub esp, 8
// 0046b8a2  dd1c24               fstp qword ptr [esp]
// 0046b8a5  68d0627900           push 0x7962d0
// 0046b8aa  83ec08               sub esp, 8
// 0046b8ad  dd1c24               fstp qword ptr [esp]
// 0046b8b0  68d0627900           push 0x7962d0
// 0046b8b5  83ec08               sub esp, 8
// 0046b8b8  dd1c24               fstp qword ptr [esp]
// 0046b8bb  68d0627900           push 0x7962d0
// 0046b8c0  83ec08               sub esp, 8
// 0046b8c3  d9c9                 fxch st(1)
// 0046b8c5  dd1c24               fstp qword ptr [esp]
// 0046b8c8  68d0627900           push 0x7962d0
// 0046b8cd  83ec08               sub esp, 8
// 0046b8d0  dd1c24               fstp qword ptr [esp]
// 0046b8d3  68b4627900           push 0x7962b4
// 0046b8d8  57                   push edi
// 0046b8d9  e8c2faffff           call 0x46b3a0
// 0046b8de  83c408               add esp, 8
// 0046b8e1  8bc8                 mov ecx, eax
// 0046b8e3  ff159ce57700         call dword ptr [0x77e59c]
// 0046b8e9  50                   push eax
// 0046b8ea  e8b1faffff           call 0x46b3a0
// 0046b8ef  83c408               add esp, 8
// 0046b8f2  8bc8                 mov ecx, eax
// 0046b8f4  ff159ce57700         call dword ptr [0x77e59c]
// 0046b8fa  50                   push eax
// 0046b8fb  e8a0faffff           call 0x46b3a0
// 0046b900  83c408               add esp, 8
// 0046b903  8bc8                 mov ecx, eax
// 0046b905  ff159ce57700         call dword ptr [0x77e59c]
// 0046b90b  50                   push eax
// 0046b90c  e88ffaffff           call 0x46b3a0
// 0046b911  83c408               add esp, 8
// 0046b914  8bc8                 mov ecx, eax
// 0046b916  ff159ce57700         call dword ptr [0x77e59c]
// 0046b91c  50                   push eax
// 0046b91d  e87efaffff           call 0x46b3a0
// 0046b922  83c408               add esp, 8
// 0046b925  8bc8                 mov ecx, eax
// 0046b927  ff159ce57700         call dword ptr [0x77e59c]
// 0046b92d  50                   push eax
// 0046b92e  e86dfaffff           call 0x46b3a0
// 0046b933  83c408               add esp, 8
// 0046b936  8bc8                 mov ecx, eax
// 0046b938  ff159ce57700         call dword ptr [0x77e59c]
// 0046b93e  50                   push eax
// 0046b93f  e85cfaffff           call 0x46b3a0
// 0046b944  83c408               add esp, 8
// 0046b947  8bc8                 mov ecx, eax
// 0046b949  ff159ce57700         call dword ptr [0x77e59c]
// 0046b94f  50                   push eax
// 0046b950  e84bfaffff           call 0x46b3a0
// 0046b955  83c408               add esp, 8
// 0046b958  8bc8                 mov ecx, eax
// 0046b95a  ff159ce57700         call dword ptr [0x77e59c]
// 0046b960  50                   push eax
// 0046b961  e83afaffff           call 0x46b3a0
// 0046b966  83c408               add esp, 8
// 0046b969  8bc8                 mov ecx, eax
// 0046b96b  ff159ce57700         call dword ptr [0x77e59c]
// 0046b971  50                   push eax
// 0046b972  e829faffff           call 0x46b3a0
// 0046b977  83c408               add esp, 8
// 0046b97a  8bc8                 mov ecx, eax
// 0046b97c  ff159ce57700         call dword ptr [0x77e59c]
// 0046b982  50                   push eax
// 0046b983  e818faffff           call 0x46b3a0
// 0046b988  83c408               add esp, 8
// 0046b98b  8bc8                 mov ecx, eax
// 0046b98d  ff159ce57700         call dword ptr [0x77e59c]
// 0046b993  50                   push eax
// 0046b994  e807faffff           call 0x46b3a0
// 0046b999  83c408               add esp, 8
// 0046b99c  8bc8                 mov ecx, eax
// 0046b99e  ff159ce57700         call dword ptr [0x77e59c]
// 0046b9a4  50                   push eax
// 0046b9a5  e8f6f9ffff           call 0x46b3a0
// 0046b9aa  6868637900           push 0x796368
// 0046b9af  57                   push edi
// 0046b9b0  e8ebf9ffff           call 0x46b3a0
// 0046b9b5  83c410               add esp, 0x10
// 0046b9b8  8d4c2440             lea ecx, [esp + 0x40]
// 0046b9bc  c7442434ffffffff     mov dword ptr [esp + 0x34], 0xffffffff
// 0046b9c4  ff15ace67700         call dword ptr [0x77e6ac]
// 0046b9ca  32c0                 xor al, al
// 0046b9cc  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 0046b9d0  64890d00000000       mov dword ptr fs:[0], ecx
// 0046b9d7  59                   pop ecx
// 0046b9d8  5f                   pop edi
// 0046b9d9  5e                   pop esi
// 0046b9da  83c42c               add esp, 0x2c
// 0046b9dd  c22000               ret 0x20

// from server: 100% by EspClaude
// roc 2008-06 0046ed40  unit: RBX::LDraw2Lua::LDrawCommand  size: 546 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0046ed40
//
// 0046ed40  6aff                 push -1
// 0046ed42  68793f7c00           push 0x7c3f79
// 0046ed47  64a100000000         mov eax, dword ptr fs:[0]
// 0046ed4d  50                   push eax
// 0046ed4e  64892500000000       mov dword ptr fs:[0], esp
// 0046ed55  83ec20               sub esp, 0x20
// 0046ed58  56                   push esi
// 0046ed59  8bf1                 mov esi, ecx
// 0046ed5b  8d4c2438             lea ecx, [esp + 0x38]
// 0046ed5f  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 0046ed67  ff1564248000         call dword ptr [0x802464]
// 0046ed6d  50                   push eax
// 0046ed6e  ff15fc278000         call dword ptr [0x8027fc]
// 0046ed74  dd4610               fld qword ptr [esi + 0x10]
// 0046ed77  dc0d38cb8100         fmul qword ptr [0x81cb38]
// 0046ed7d  83c404               add esp, 4
// 0046ed80  dd4618               fld qword ptr [esi + 0x18]
// 0046ed83  685c2e8100           push 0x812e5c
// 0046ed88  dd0530cb8100         fld qword ptr [0x81cb30]
// 0046ed8e  83ec08               sub esp, 8
// 0046ed91  dcc9                 fmul st(1), st(0)
// 0046ed93  d9c9                 fxch st(1)
// 0046ed95  dee3                 fsubrp st(3)
// 0046ed97  dc4e20               fmul qword ptr [esi + 0x20]
// 0046ed9a  dd4628               fld qword ptr [esi + 0x28]
// 0046ed9d  dd4630               fld qword ptr [esi + 0x30]
// 0046eda0  dd4638               fld qword ptr [esi + 0x38]
// 0046eda3  dd4640               fld qword ptr [esi + 0x40]
// 0046eda6  dd4648               fld qword ptr [esi + 0x48]
// 0046eda9  dd5c2428             fstp qword ptr [esp + 0x28]
// 0046edad  dd4650               fld qword ptr [esi + 0x50]
// 0046edb0  dd5c2420             fstp qword ptr [esp + 0x20]
// 0046edb4  dd4658               fld qword ptr [esi + 0x58]
// 0046edb7  dd5c2418             fstp qword ptr [esp + 0x18]
// 0046edbb  dd4660               fld qword ptr [esi + 0x60]
// 0046edbe  dd5c2410             fstp qword ptr [esp + 0x10]
// 0046edc2  dd4668               fld qword ptr [esi + 0x68]
// 0046edc5  8b742440             mov esi, dword ptr [esp + 0x40]
// 0046edc9  dd1c24               fstp qword ptr [esp]
// 0046edcc  6828cb8100           push 0x81cb28
// 0046edd1  dd442414             fld qword ptr [esp + 0x14]
// 0046edd5  83ec08               sub esp, 8
// 0046edd8  dd1c24               fstp qword ptr [esp]
// 0046eddb  6828cb8100           push 0x81cb28
// 0046ede0  dd442428             fld qword ptr [esp + 0x28]
// 0046ede4  83ec08               sub esp, 8
// 0046ede7  dd1c24               fstp qword ptr [esp]
// 0046edea  6828cb8100           push 0x81cb28
// 0046edef  dd44243c             fld qword ptr [esp + 0x3c]
// 0046edf3  83ec08               sub esp, 8
// 0046edf6  dd1c24               fstp qword ptr [esp]
// 0046edf9  6828cb8100           push 0x81cb28
// 0046edfe  dd442450             fld qword ptr [esp + 0x50]
// 0046ee02  83ec08               sub esp, 8
// 0046ee05  dd1c24               fstp qword ptr [esp]
// 0046ee08  6828cb8100           push 0x81cb28
// 0046ee0d  83ec08               sub esp, 8
// 0046ee10  dd1c24               fstp qword ptr [esp]
// 0046ee13  6828cb8100           push 0x81cb28
// 0046ee18  83ec08               sub esp, 8
// 0046ee1b  dd1c24               fstp qword ptr [esp]
// 0046ee1e  6828cb8100           push 0x81cb28
// 0046ee23  83ec08               sub esp, 8
// 0046ee26  dd1c24               fstp qword ptr [esp]
// 0046ee29  6828cb8100           push 0x81cb28
// 0046ee2e  83ec08               sub esp, 8
// 0046ee31  dd1c24               fstp qword ptr [esp]
// 0046ee34  6828cb8100           push 0x81cb28
// 0046ee39  83ec08               sub esp, 8
// 0046ee3c  dd1c24               fstp qword ptr [esp]
// 0046ee3f  6828cb8100           push 0x81cb28
// 0046ee44  83ec08               sub esp, 8
// 0046ee47  d9c9                 fxch st(1)
// 0046ee49  dd1c24               fstp qword ptr [esp]
// 0046ee4c  6828cb8100           push 0x81cb28
// 0046ee51  83ec08               sub esp, 8
// 0046ee54  dd1c24               fstp qword ptr [esp]
// 0046ee57  680ccb8100           push 0x81cb0c
// 0046ee5c  56                   push esi
// 0046ee5d  e8eeb5fdff           call 0x44a450
// 0046ee62  83c408               add esp, 8
// 0046ee65  8bc8                 mov ecx, eax
// 0046ee67  ff1578248000         call dword ptr [0x802478]
// 0046ee6d  50                   push eax
// 0046ee6e  e8ddb5fdff           call 0x44a450
// 0046ee73  83c408               add esp, 8
// 0046ee76  8bc8                 mov ecx, eax
// 0046ee78  ff1578248000         call dword ptr [0x802478]
// 0046ee7e  50                   push eax
// 0046ee7f  e8ccb5fdff           call 0x44a450
// 0046ee84  83c408               add esp, 8
// 0046ee87  8bc8                 mov ecx, eax
// 0046ee89  ff1578248000         call dword ptr [0x802478]
// 0046ee8f  50                   push eax
// 0046ee90  e8bbb5fdff           call 0x44a450
// 0046ee95  83c408               add esp, 8
// 0046ee98  8bc8                 mov ecx, eax
// 0046ee9a  ff1578248000         call dword ptr [0x802478]
// 0046eea0  50                   push eax
// 0046eea1  e8aab5fdff           call 0x44a450
// 0046eea6  83c408               add esp, 8
// 0046eea9  8bc8                 mov ecx, eax
// 0046eeab  ff1578248000         call dword ptr [0x802478]
// 0046eeb1  50                   push eax
// 0046eeb2  e899b5fdff           call 0x44a450
// 0046eeb7  83c408               add esp, 8
// 0046eeba  8bc8                 mov ecx, eax
// 0046eebc  ff1578248000         call dword ptr [0x802478]
// 0046eec2  50                   push eax
// 0046eec3  e888b5fdff           call 0x44a450
// 0046eec8  83c408               add esp, 8
// 0046eecb  8bc8                 mov ecx, eax
// 0046eecd  ff1578248000         call dword ptr [0x802478]
// 0046eed3  50                   push eax
// 0046eed4  e877b5fdff           call 0x44a450
// 0046eed9  83c408               add esp, 8
// 0046eedc  8bc8                 mov ecx, eax
// 0046eede  ff1578248000         call dword ptr [0x802478]
// 0046eee4  50                   push eax
// 0046eee5  e866b5fdff           call 0x44a450
// 0046eeea  83c408               add esp, 8
// 0046eeed  8bc8                 mov ecx, eax
// 0046eeef  ff1578248000         call dword ptr [0x802478]
// 0046eef5  50                   push eax
// 0046eef6  e855b5fdff           call 0x44a450
// 0046eefb  83c408               add esp, 8
// 0046eefe  8bc8                 mov ecx, eax
// 0046ef00  ff1578248000         call dword ptr [0x802478]
// 0046ef06  50                   push eax
// 0046ef07  e844b5fdff           call 0x44a450
// 0046ef0c  83c408               add esp, 8
// 0046ef0f  8bc8                 mov ecx, eax
// 0046ef11  ff1578248000         call dword ptr [0x802478]
// 0046ef17  50                   push eax
// 0046ef18  e833b5fdff           call 0x44a450
// 0046ef1d  83c408               add esp, 8
// 0046ef20  8bc8                 mov ecx, eax
// 0046ef22  ff1578248000         call dword ptr [0x802478]
// 0046ef28  50                   push eax
// 0046ef29  e822b5fdff           call 0x44a450
// 0046ef2e  68cccb8100           push 0x81cbcc
// 0046ef33  56                   push esi
// 0046ef34  e817b5fdff           call 0x44a450
// 0046ef39  83c410               add esp, 0x10
// 0046ef3c  8d4c2438             lea ecx, [esp + 0x38]
// 0046ef40  c744242cffffffff     mov dword ptr [esp + 0x2c], 0xffffffff
// 0046ef48  ff1568248000         call dword ptr [0x802468]
// 0046ef4e  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0046ef52  32c0                 xor al, al
// 0046ef54  5e                   pop esi
// 0046ef55  64890d00000000       mov dword ptr fs:[0], ecx
// 0046ef5c  83c42c               add esp, 0x2c
// 0046ef5f  c22000               ret 0x20

// from server: 67% by colin
// roc 2008-06 0046ed40  unit: RBX::LDraw2Lua::LDrawCommand  size: 546 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0046ed40
//
// 0046ed40  6aff                 push -1
// 0046ed42  68793f7c00           push 0x7c3f79
// 0046ed47  64a100000000         mov eax, dword ptr fs:[0]
// 0046ed4d  50                   push eax
// 0046ed4e  64892500000000       mov dword ptr fs:[0], esp
// 0046ed55  83ec20               sub esp, 0x20
// 0046ed58  56                   push esi
// 0046ed59  8bf1                 mov esi, ecx
// 0046ed5b  8d4c2438             lea ecx, [esp + 0x38]
// 0046ed5f  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 0046ed67  ff1564248000         call dword ptr [0x802464]
// 0046ed6d  50                   push eax
// 0046ed6e  ff15fc278000         call dword ptr [0x8027fc]
// 0046ed74  dd4610               fld qword ptr [esi + 0x10]
// 0046ed77  dc0d38cb8100         fmul qword ptr [0x81cb38]
// 0046ed7d  83c404               add esp, 4
// 0046ed80  dd4618               fld qword ptr [esi + 0x18]
// 0046ed83  685c2e8100           push 0x812e5c
// 0046ed88  dd0530cb8100         fld qword ptr [0x81cb30]
// 0046ed8e  83ec08               sub esp, 8
// 0046ed91  dcc9                 fmul st(1), st(0)
// 0046ed93  d9c9                 fxch st(1)
// 0046ed95  dee3                 fsubrp st(3)
// 0046ed97  dc4e20               fmul qword ptr [esi + 0x20]
// 0046ed9a  dd4628               fld qword ptr [esi + 0x28]
// 0046ed9d  dd4630               fld qword ptr [esi + 0x30]
// 0046eda0  dd4638               fld qword ptr [esi + 0x38]
// 0046eda3  dd4640               fld qword ptr [esi + 0x40]
// 0046eda6  dd4648               fld qword ptr [esi + 0x48]
// 0046eda9  dd5c2428             fstp qword ptr [esp + 0x28]
// 0046edad  dd4650               fld qword ptr [esi + 0x50]
// 0046edb0  dd5c2420             fstp qword ptr [esp + 0x20]
// 0046edb4  dd4658               fld qword ptr [esi + 0x58]
// 0046edb7  dd5c2418             fstp qword ptr [esp + 0x18]
// 0046edbb  dd4660               fld qword ptr [esi + 0x60]
// 0046edbe  dd5c2410             fstp qword ptr [esp + 0x10]
// 0046edc2  dd4668               fld qword ptr [esi + 0x68]
// 0046edc5  8b742440             mov esi, dword ptr [esp + 0x40]
// 0046edc9  dd1c24               fstp qword ptr [esp]
// 0046edcc  6828cb8100           push 0x81cb28
// 0046edd1  dd442414             fld qword ptr [esp + 0x14]
// 0046edd5  83ec08               sub esp, 8
// 0046edd8  dd1c24               fstp qword ptr [esp]
// 0046eddb  6828cb8100           push 0x81cb28
// 0046ede0  dd442428             fld qword ptr [esp + 0x28]
// 0046ede4  83ec08               sub esp, 8
// 0046ede7  dd1c24               fstp qword ptr [esp]
// 0046edea  6828cb8100           push 0x81cb28
// 0046edef  dd44243c             fld qword ptr [esp + 0x3c]
// 0046edf3  83ec08               sub esp, 8
// 0046edf6  dd1c24               fstp qword ptr [esp]
// 0046edf9  6828cb8100           push 0x81cb28
// 0046edfe  dd442450             fld qword ptr [esp + 0x50]
// 0046ee02  83ec08               sub esp, 8
// 0046ee05  dd1c24               fstp qword ptr [esp]
// 0046ee08  6828cb8100           push 0x81cb28
// 0046ee0d  83ec08               sub esp, 8
// 0046ee10  dd1c24               fstp qword ptr [esp]
// 0046ee13  6828cb8100           push 0x81cb28
// 0046ee18  83ec08               sub esp, 8
// 0046ee1b  dd1c24               fstp qword ptr [esp]
// 0046ee1e  6828cb8100           push 0x81cb28
// 0046ee23  83ec08               sub esp, 8
// 0046ee26  dd1c24               fstp qword ptr [esp]
// 0046ee29  6828cb8100           push 0x81cb28
// 0046ee2e  83ec08               sub esp, 8
// 0046ee31  dd1c24               fstp qword ptr [esp]
// 0046ee34  6828cb8100           push 0x81cb28
// 0046ee39  83ec08               sub esp, 8
// 0046ee3c  dd1c24               fstp qword ptr [esp]
// 0046ee3f  6828cb8100           push 0x81cb28
// 0046ee44  83ec08               sub esp, 8
// 0046ee47  d9c9                 fxch st(1)
// 0046ee49  dd1c24               fstp qword ptr [esp]
// 0046ee4c  6828cb8100           push 0x81cb28
// 0046ee51  83ec08               sub esp, 8
// 0046ee54  dd1c24               fstp qword ptr [esp]
// 0046ee57  680ccb8100           push 0x81cb0c
// 0046ee5c  56                   push esi
// 0046ee5d  e8eeb5fdff           call 0x44a450
// 0046ee62  83c408               add esp, 8
// 0046ee65  8bc8                 mov ecx, eax
// 0046ee67  ff1578248000         call dword ptr [0x802478]
// 0046ee6d  50                   push eax
// 0046ee6e  e8ddb5fdff           call 0x44a450
// 0046ee73  83c408               add esp, 8
// 0046ee76  8bc8                 mov ecx, eax
// 0046ee78  ff1578248000         call dword ptr [0x802478]
// 0046ee7e  50                   push eax
// 0046ee7f  e8ccb5fdff           call 0x44a450
// 0046ee84  83c408               add esp, 8
// 0046ee87  8bc8                 mov ecx, eax
// 0046ee89  ff1578248000         call dword ptr [0x802478]
// 0046ee8f  50                   push eax
// 0046ee90  e8bbb5fdff           call 0x44a450
// 0046ee95  83c408               add esp, 8
// 0046ee98  8bc8                 mov ecx, eax
// 0046ee9a  ff1578248000         call dword ptr [0x802478]
// 0046eea0  50                   push eax
// 0046eea1  e8aab5fdff           call 0x44a450
// 0046eea6  83c408               add esp, 8
// 0046eea9  8bc8                 mov ecx, eax
// 0046eeab  ff1578248000         call dword ptr [0x802478]
// 0046eeb1  50                   push eax
// 0046eeb2  e899b5fdff           call 0x44a450
// 0046eeb7  83c408               add esp, 8
// 0046eeba  8bc8                 mov ecx, eax
// 0046eebc  ff1578248000         call dword ptr [0x802478]
// 0046eec2  50                   push eax
// 0046eec3  e888b5fdff           call 0x44a450
// 0046eec8  83c408               add esp, 8
// 0046eecb  8bc8                 mov ecx, eax
// 0046eecd  ff1578248000         call dword ptr [0x802478]
// 0046eed3  50                   push eax
// 0046eed4  e877b5fdff           call 0x44a450
// 0046eed9  83c408               add esp, 8
// 0046eedc  8bc8                 mov ecx, eax
// 0046eede  ff1578248000         call dword ptr [0x802478]
// 0046eee4  50                   push eax
// 0046eee5  e866b5fdff           call 0x44a450
// 0046eeea  83c408               add esp, 8
// 0046eeed  8bc8                 mov ecx, eax
// 0046eeef  ff1578248000         call dword ptr [0x802478]
// 0046eef5  50                   push eax
// 0046eef6  e855b5fdff           call 0x44a450
// 0046eefb  83c408               add esp, 8
// 0046eefe  8bc8                 mov ecx, eax
// 0046ef00  ff1578248000         call dword ptr [0x802478]
// 0046ef06  50                   push eax
// 0046ef07  e844b5fdff           call 0x44a450
// 0046ef0c  83c408               add esp, 8
// 0046ef0f  8bc8                 mov ecx, eax
// 0046ef11  ff1578248000         call dword ptr [0x802478]
// 0046ef17  50                   push eax
// 0046ef18  e833b5fdff           call 0x44a450
// 0046ef1d  83c408               add esp, 8
// 0046ef20  8bc8                 mov ecx, eax
// 0046ef22  ff1578248000         call dword ptr [0x802478]
// 0046ef28  50                   push eax
// 0046ef29  e822b5fdff           call 0x44a450
// 0046ef2e  68cccb8100           push 0x81cbcc
// 0046ef33  56                   push esi
// 0046ef34  e817b5fdff           call 0x44a450
// 0046ef39  83c410               add esp, 0x10
// 0046ef3c  8d4c2438             lea ecx, [esp + 0x38]
// 0046ef40  c744242cffffffff     mov dword ptr [esp + 0x2c], 0xffffffff
// 0046ef48  ff1568248000         call dword ptr [0x802468]
// 0046ef4e  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0046ef52  32c0                 xor al, al
// 0046ef54  5e                   pop esi
// 0046ef55  64890d00000000       mov dword ptr fs:[0], ecx
// 0046ef5c  83c42c               add esp, 0x2c
// 0046ef5f  c22000               ret 0x20

// from server: 66% by colin
// roc 2008-06 0046ed40  unit: RBX::LDraw2Lua::LDrawCommand  size: 546 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0046ed40
//
// 0046ed40  6aff                 push -1
// 0046ed42  68793f7c00           push 0x7c3f79
// 0046ed47  64a100000000         mov eax, dword ptr fs:[0]
// 0046ed4d  50                   push eax
// 0046ed4e  64892500000000       mov dword ptr fs:[0], esp
// 0046ed55  83ec20               sub esp, 0x20
// 0046ed58  56                   push esi
// 0046ed59  8bf1                 mov esi, ecx
// 0046ed5b  8d4c2438             lea ecx, [esp + 0x38]
// 0046ed5f  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 0046ed67  ff1564248000         call dword ptr [0x802464]
// 0046ed6d  50                   push eax
// 0046ed6e  ff15fc278000         call dword ptr [0x8027fc]
// 0046ed74  dd4610               fld qword ptr [esi + 0x10]
// 0046ed77  dc0d38cb8100         fmul qword ptr [0x81cb38]
// 0046ed7d  83c404               add esp, 4
// 0046ed80  dd4618               fld qword ptr [esi + 0x18]
// 0046ed83  685c2e8100           push 0x812e5c
// 0046ed88  dd0530cb8100         fld qword ptr [0x81cb30]
// 0046ed8e  83ec08               sub esp, 8
// 0046ed91  dcc9                 fmul st(1), st(0)
// 0046ed93  d9c9                 fxch st(1)
// 0046ed95  dee3                 fsubrp st(3)
// 0046ed97  dc4e20               fmul qword ptr [esi + 0x20]
// 0046ed9a  dd4628               fld qword ptr [esi + 0x28]
// 0046ed9d  dd4630               fld qword ptr [esi + 0x30]
// 0046eda0  dd4638               fld qword ptr [esi + 0x38]
// 0046eda3  dd4640               fld qword ptr [esi + 0x40]
// 0046eda6  dd4648               fld qword ptr [esi + 0x48]
// 0046eda9  dd5c2428             fstp qword ptr [esp + 0x28]
// 0046edad  dd4650               fld qword ptr [esi + 0x50]
// 0046edb0  dd5c2420             fstp qword ptr [esp + 0x20]
// 0046edb4  dd4658               fld qword ptr [esi + 0x58]
// 0046edb7  dd5c2418             fstp qword ptr [esp + 0x18]
// 0046edbb  dd4660               fld qword ptr [esi + 0x60]
// 0046edbe  dd5c2410             fstp qword ptr [esp + 0x10]
// 0046edc2  dd4668               fld qword ptr [esi + 0x68]
// 0046edc5  8b742440             mov esi, dword ptr [esp + 0x40]
// 0046edc9  dd1c24               fstp qword ptr [esp]
// 0046edcc  6828cb8100           push 0x81cb28
// 0046edd1  dd442414             fld qword ptr [esp + 0x14]
// 0046edd5  83ec08               sub esp, 8
// 0046edd8  dd1c24               fstp qword ptr [esp]
// 0046eddb  6828cb8100           push 0x81cb28
// 0046ede0  dd442428             fld qword ptr [esp + 0x28]
// 0046ede4  83ec08               sub esp, 8
// 0046ede7  dd1c24               fstp qword ptr [esp]
// 0046edea  6828cb8100           push 0x81cb28
// 0046edef  dd44243c             fld qword ptr [esp + 0x3c]
// 0046edf3  83ec08               sub esp, 8
// 0046edf6  dd1c24               fstp qword ptr [esp]
// 0046edf9  6828cb8100           push 0x81cb28
// 0046edfe  dd442450             fld qword ptr [esp + 0x50]
// 0046ee02  83ec08               sub esp, 8
// 0046ee05  dd1c24               fstp qword ptr [esp]
// 0046ee08  6828cb8100           push 0x81cb28
// 0046ee0d  83ec08               sub esp, 8
// 0046ee10  dd1c24               fstp qword ptr [esp]
// 0046ee13  6828cb8100           push 0x81cb28
// 0046ee18  83ec08               sub esp, 8
// 0046ee1b  dd1c24               fstp qword ptr [esp]
// 0046ee1e  6828cb8100           push 0x81cb28
// 0046ee23  83ec08               sub esp, 8
// 0046ee26  dd1c24               fstp qword ptr [esp]
// 0046ee29  6828cb8100           push 0x81cb28
// 0046ee2e  83ec08               sub esp, 8
// 0046ee31  dd1c24               fstp qword ptr [esp]
// 0046ee34  6828cb8100           push 0x81cb28
// 0046ee39  83ec08               sub esp, 8
// 0046ee3c  dd1c24               fstp qword ptr [esp]
// 0046ee3f  6828cb8100           push 0x81cb28
// 0046ee44  83ec08               sub esp, 8
// 0046ee47  d9c9                 fxch st(1)
// 0046ee49  dd1c24               fstp qword ptr [esp]
// 0046ee4c  6828cb8100           push 0x81cb28
// 0046ee51  83ec08               sub esp, 8
// 0046ee54  dd1c24               fstp qword ptr [esp]
// 0046ee57  680ccb8100           push 0x81cb0c
// 0046ee5c  56                   push esi
// 0046ee5d  e8eeb5fdff           call 0x44a450
// 0046ee62  83c408               add esp, 8
// 0046ee65  8bc8                 mov ecx, eax
// 0046ee67  ff1578248000         call dword ptr [0x802478]
// 0046ee6d  50                   push eax
// 0046ee6e  e8ddb5fdff           call 0x44a450
// 0046ee73  83c408               add esp, 8
// 0046ee76  8bc8                 mov ecx, eax
// 0046ee78  ff1578248000         call dword ptr [0x802478]
// 0046ee7e  50                   push eax
// 0046ee7f  e8ccb5fdff           call 0x44a450
// 0046ee84  83c408               add esp, 8
// 0046ee87  8bc8                 mov ecx, eax
// 0046ee89  ff1578248000         call dword ptr [0x802478]
// 0046ee8f  50                   push eax
// 0046ee90  e8bbb5fdff           call 0x44a450
// 0046ee95  83c408               add esp, 8
// 0046ee98  8bc8                 mov ecx, eax
// 0046ee9a  ff1578248000         call dword ptr [0x802478]
// 0046eea0  50                   push eax
// 0046eea1  e8aab5fdff           call 0x44a450
// 0046eea6  83c408               add esp, 8
// 0046eea9  8bc8                 mov ecx, eax
// 0046eeab  ff1578248000         call dword ptr [0x802478]
// 0046eeb1  50                   push eax
// 0046eeb2  e899b5fdff           call 0x44a450
// 0046eeb7  83c408               add esp, 8
// 0046eeba  8bc8                 mov ecx, eax
// 0046eebc  ff1578248000         call dword ptr [0x802478]
// 0046eec2  50                   push eax
// 0046eec3  e888b5fdff           call 0x44a450
// 0046eec8  83c408               add esp, 8
// 0046eecb  8bc8                 mov ecx, eax
// 0046eecd  ff1578248000         call dword ptr [0x802478]
// 0046eed3  50                   push eax
// 0046eed4  e877b5fdff           call 0x44a450
// 0046eed9  83c408               add esp, 8
// 0046eedc  8bc8                 mov ecx, eax
// 0046eede  ff1578248000         call dword ptr [0x802478]
// 0046eee4  50                   push eax
// 0046eee5  e866b5fdff           call 0x44a450
// 0046eeea  83c408               add esp, 8
// 0046eeed  8bc8                 mov ecx, eax
// 0046eeef  ff1578248000         call dword ptr [0x802478]
// 0046eef5  50                   push eax
// 0046eef6  e855b5fdff           call 0x44a450
// 0046eefb  83c408               add esp, 8
// 0046eefe  8bc8                 mov ecx, eax
// 0046ef00  ff1578248000         call dword ptr [0x802478]
// 0046ef06  50                   push eax
// 0046ef07  e844b5fdff           call 0x44a450
// 0046ef0c  83c408               add esp, 8
// 0046ef0f  8bc8                 mov ecx, eax
// 0046ef11  ff1578248000         call dword ptr [0x802478]
// 0046ef17  50                   push eax
// 0046ef18  e833b5fdff           call 0x44a450
// 0046ef1d  83c408               add esp, 8
// 0046ef20  8bc8                 mov ecx, eax
// 0046ef22  ff1578248000         call dword ptr [0x802478]
// 0046ef28  50                   push eax
// 0046ef29  e822b5fdff           call 0x44a450
// 0046ef2e  68cccb8100           push 0x81cbcc
// 0046ef33  56                   push esi
// 0046ef34  e817b5fdff           call 0x44a450
// 0046ef39  83c410               add esp, 0x10
// 0046ef3c  8d4c2438             lea ecx, [esp + 0x38]
// 0046ef40  c744242cffffffff     mov dword ptr [esp + 0x2c], 0xffffffff
// 0046ef48  ff1568248000         call dword ptr [0x802468]
// 0046ef4e  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0046ef52  32c0                 xor al, al
// 0046ef54  5e                   pop esi
// 0046ef55  64890d00000000       mov dword ptr fs:[0], ecx
// 0046ef5c  83c42c               add esp, 0x2c
// 0046ef5f  c22000               ret 0x20
#include <intrin.h>

// roc-lang: cpp
// roc-cl: 50727

#include <cstdlib>
#include <ostream>

struct Text
{
    char storage[28];
    __declspec(dllimport) const char* c_str() const;
    __declspec(dllimport) ~Text();
};

struct LDrawCommand
{
    int command;
    int color;
    int line;
    int reserved;
    double x;
    double y;
    double z;
    double r00;
    double r01;
    double r02;
    double r10;
    double r11;
    double r12;
    double r20;
    double r21;
    double r22;

    bool writeCFrame(std::ostream& stream, Text offset);
};

extern const double ldrawPos;
extern const double ldrawNeg;

bool LDrawCommand::writeCFrame(std::ostream& stream, Text offset)
{
    double value = atof(offset.c_str());
    double px = x / ldrawPos;
    double py = y / ldrawNeg - value;
    double pz = z / ldrawNeg;
    double mr00 = r00;
    double mr01 = r01;
    double mr02 = r02;
    double mr10 = r10;
    double mr11 = r11;
    double mr12 = r12;
    double mr20 = r20;
    double mr21 = r21;
    double mr22 = r22;
    stream << "part.CFrame = CFrame.new("
        << px << "," << py << "," << pz << ","
        << mr00 << "," << mr01 << "," << mr02 << "," << mr10 << "," << mr11 << ","
        << mr12 << "," << mr20 << "," << mr21 << "," << mr22 << ")";
    stream << "\n";
    return false;
}
