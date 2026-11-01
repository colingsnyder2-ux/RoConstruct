// from server: 100% by colin
// from server: 99% by EspClaude
// from server: 63% by colin
// roc 2008-06 004c9e30  unit: RBX::VInstance::?$NonFactoryProduct  size: 472 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004c9e30
//
// 004c9e30  51                   push ecx
// 004c9e31  55                   push ebp
// 004c9e32  8be9                 mov ebp, ecx
// 004c9e34  8b4544               mov eax, dword ptr [ebp + 0x44]
// 004c9e37  3b442414             cmp eax, dword ptr [esp + 0x14]
// 004c9e3b  7c07                 jl 0x4c9e44
// 004c9e3d  32c0                 xor al, al
// 004c9e3f  5d                   pop ebp
// 004c9e40  59                   pop ecx
// 004c9e41  c20c00               ret 0xc
// 004c9e44  8b4500               mov eax, dword ptr [ebp]
// 004c9e47  56                   push esi
// 004c9e48  8d8828020000         lea ecx, [eax + 0x228]
// 004c9e4e  e81dd71100           call 0x5e7570
// 004c9e53  8bf0                 mov esi, eax
// 004c9e55  85f6                 test esi, esi
// 004c9e57  7464                 je 0x4c9ebd
// 004c9e59  807e5400             cmp byte ptr [esi + 0x54], 0
// 004c9e5d  7412                 je 0x4c9e71
// 004c9e5f  8b4e64               mov ecx, dword ptr [esi + 0x64]
// 004c9e62  034e58               add ecx, dword ptr [esi + 0x58]
// 004c9e65  8b5660               mov edx, dword ptr [esi + 0x60]
// 004c9e68  ffd2                 call edx
// 004c9e6a  d95e50               fstp dword ptr [esi + 0x50]
// 004c9e6d  c6465400             mov byte ptr [esi + 0x54], 0
// 004c9e71  d94650               fld dword ptr [esi + 0x50]
// 004c9e74  dcc0                 fadd st(0), st(0)
// 004c9e76  d94540               fld dword ptr [ebp + 0x40]
// 004c9e79  d8d1                 fcom st(1)
// 004c9e7b  dfe0                 fnstsw ax
// 004c9e7d  f6c401               test ah, 1
// 004c9e80  7504                 jne 0x4c9e86
// 004c9e82  ddd9                 fstp st(1)
// 004c9e84  eb17                 jmp 0x4c9e9d
// 004c9e86  ddd8                 fstp st(0)
// 004c9e88  d90544cc9300         fld dword ptr [0x93cc44]
// 004c9e8e  d8d1                 fcom st(1)
// 004c9e90  dfe0                 fnstsw ax
// 004c9e92  f6c441               test ah, 0x41
// 004c9e95  7a04                 jp 0x4c9e9b
// 004c9e97  ddd9                 fstp st(1)
// 004c9e99  eb02                 jmp 0x4c9e9d
// 004c9e9b  ddd8                 fstp st(0)
// 004c9e9d  d95d40               fstp dword ptr [ebp + 0x40]
// 004c9ea0  807e5400             cmp byte ptr [esi + 0x54], 0
// 004c9ea4  7412                 je 0x4c9eb8
// 004c9ea6  8b4e64               mov ecx, dword ptr [esi + 0x64]
// 004c9ea9  034e58               add ecx, dword ptr [esi + 0x58]
// 004c9eac  8b4660               mov eax, dword ptr [esi + 0x60]
// 004c9eaf  ffd0                 call eax
// 004c9eb1  d95e50               fstp dword ptr [esi + 0x50]
// 004c9eb4  c6465400             mov byte ptr [esi + 0x54], 0
// 004c9eb8  d94650               fld dword ptr [esi + 0x50]
// 004c9ebb  eb02                 jmp 0x4c9ebf
// 004c9ebd  d9ee                 fldz 
// 004c9ebf  8b4d00               mov ecx, dword ptr [ebp]
// 004c9ec2  d95c2408             fstp dword ptr [esp + 8]
// 004c9ec6  8b742410             mov esi, dword ptr [esp + 0x10]
// 004c9eca  e8e1ed0c00           call 0x598cb0
// 004c9ecf  d94024               fld dword ptr [eax + 0x24]
// 004c9ed2  d86624               fsub dword ptr [esi + 0x24]
// 004c9ed5  83c024               add eax, 0x24
// 004c9ed8  d94004               fld dword ptr [eax + 4]
// 004c9edb  d86628               fsub dword ptr [esi + 0x28]
// 004c9ede  d94008               fld dword ptr [eax + 8]
// 004c9ee1  d8662c               fsub dword ptr [esi + 0x2c]
// 004c9ee4  d9c9                 fxch st(1)
// 004c9ee6  d9e1                 fabs 
// 004c9ee8  d9ca                 fxch st(2)
// 004c9eea  d9e1                 fabs 
// 004c9eec  dec2                 faddp st(2)
// 004c9eee  d9e1                 fabs 
// 004c9ef0  dec1                 faddp st(1)
// 004c9ef2  d8642408             fsub dword ptr [esp + 8]
// 004c9ef6  d95548               fst dword ptr [ebp + 0x48]
// 004c9ef9  d90538cc9300         fld dword ptr [0x93cc38]
// 004c9eff  d8d1                 fcom st(1)
// 004c9f01  dfe0                 fnstsw ax
// 004c9f03  f6c401               test ah, 1
// 004c9f06  7504                 jne 0x4c9f0c
// 004c9f08  ddd9                 fstp st(1)
// 004c9f0a  eb17                 jmp 0x4c9f23
// 004c9f0c  ddd8                 fstp st(0)
// 004c9f0e  d9053ccc9300         fld dword ptr [0x93cc3c]
// 004c9f14  d8d1                 fcom st(1)
// 004c9f16  dfe0                 fnstsw ax
// 004c9f18  f6c441               test ah, 0x41
// 004c9f1b  7a04                 jp 0x4c9f21
// 004c9f1d  ddd9                 fstp st(1)
// 004c9f1f  eb02                 jmp 0x4c9f23
// 004c9f21  ddd8                 fstp st(0)
// 004c9f23  837d44ff             cmp dword ptr [ebp + 0x44], -1
// 004c9f27  d95548               fst dword ptr [ebp + 0x48]
// 004c9f2a  7545                 jne 0x4c9f71
// 004c9f2c  d94540               fld dword ptr [ebp + 0x40]
// 004c9f2f  8b4d00               mov ecx, dword ptr [ebp]
// 004c9f32  d9c0                 fld st(0)
// 004c9f34  57                   push edi
// 004c9f35  def2                 fdivrp st(2)
// 004c9f37  dec9                 fmulp st(1)
// 004c9f39  dd5d08               fstp qword ptr [ebp + 8]
// 004c9f3c  e86fed0c00           call 0x598cb0
// 004c9f41  8d5510               lea edx, [ebp + 0x10]
// 004c9f44  8bf0                 mov esi, eax
// 004c9f46  b909000000           mov ecx, 9
// 004c9f4b  8bfa                 mov edi, edx
// 004c9f4d  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 004c9f4f  d94024               fld dword ptr [eax + 0x24]
// 004c9f52  d95a24               fstp dword ptr [edx + 0x24]
// 004c9f55  d94028               fld dword ptr [eax + 0x28]
// 004c9f58  d95a28               fstp dword ptr [edx + 0x28]
// 004c9f5b  d9402c               fld dword ptr [eax + 0x2c]
// 004c9f5e  d95a2c               fstp dword ptr [edx + 0x2c]
// 004c9f61  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004c9f65  5f                   pop edi
// 004c9f66  894544               mov dword ptr [ebp + 0x44], eax
// 004c9f69  5e                   pop esi
// 004c9f6a  b001                 mov al, 1
// 004c9f6c  5d                   pop ebp
// 004c9f6d  59                   pop ecx
// 004c9f6e  c20c00               ret 0xc
// 004c9f71  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004c9f75  ddd8                 fstp st(0)
// 004c9f77  8b7500               mov esi, dword ptr [ebp]
// 004c9f7a  51                   push ecx
// 004c9f7b  8bce                 mov ecx, esi
// 004c9f7d  e85e8bf5ff           call 0x422ae0
// 004c9f82  84c0                 test al, al
// 004c9f84  7418                 je 0x4c9f9e
// 004c9f86  8b442418             mov eax, dword ptr [esp + 0x18]
// 004c9f8a  dd0548688200         fld qword ptr [0x826848]
// 004c9f90  894544               mov dword ptr [ebp + 0x44], eax
// 004c9f93  dd5d08               fstp qword ptr [ebp + 8]
// 004c9f96  5e                   pop esi
// 004c9f97  b001                 mov al, 1
// 004c9f99  5d                   pop ebp
// 004c9f9a  59                   pop ecx
// 004c9f9b  c20c00               ret 0xc
// 004c9f9e  8bce                 mov ecx, esi
// 004c9fa0  e80bed0c00           call 0x598cb0
// 004c9fa5  d94024               fld dword ptr [eax + 0x24]
// 004c9fa8  d86534               fsub dword ptr [ebp + 0x34]
// 004c9fab  8b4d00               mov ecx, dword ptr [ebp]
// 004c9fae  d94028               fld dword ptr [eax + 0x28]
// 004c9fb1  83c024               add eax, 0x24
// 004c9fb4  d86538               fsub dword ptr [ebp + 0x38]
// 004c9fb7  8d5510               lea edx, [ebp + 0x10]
// 004c9fba  d94008               fld dword ptr [eax + 8]
// 004c9fbd  52                   push edx
// 004c9fbe  d8653c               fsub dword ptr [ebp + 0x3c]
// 004c9fc1  d9c9                 fxch st(1)
// 004c9fc3  d9e1                 fabs 
// 004c9fc5  d9ca                 fxch st(2)
// 004c9fc7  d9e1                 fabs 
// 004c9fc9  dec2                 faddp st(2)
// 004c9fcb  d9e1                 fabs 
// 004c9fcd  dec1                 faddp st(1)
// 004c9fcf  d95c2414             fstp dword ptr [esp + 0x14]
// 004c9fd3  e8d8ec0c00           call 0x598cb0
// 004c9fd8  8bc8                 mov ecx, eax
// 004c9fda  e8f1920400           call 0x5132d0
// 004c9fdf  84c0                 test al, al
// 004c9fe1  7404                 je 0x4c9fe7
// 004c9fe3  d9e8                 fld1 
// 004c9fe5  eb02                 jmp 0x4c9fe9
// 004c9fe7  d9ee                 fldz 
// 004c9fe9  d8442410             fadd dword ptr [esp + 0x10]
// 004c9fed  8b442418             mov eax, dword ptr [esp + 0x18]
// 004c9ff1  894544               mov dword ptr [ebp + 0x44], eax
// 004c9ff4  5e                   pop esi
// 004c9ff5  d87548               fdiv dword ptr [ebp + 0x48]
// 004c9ff8  b001                 mov al, 1
// 004c9ffa  d84d40               fmul dword ptr [ebp + 0x40]
// 004c9ffd  d84d40               fmul dword ptr [ebp + 0x40]
// 004ca000  dd5d08               fstp qword ptr [ebp + 8]
// 004ca003  5d                   pop ebp
// 004ca004  59                   pop ecx
// 004ca005  c20c00               ret 0xc

// from server: 61% by king_originala
// roc 2008-06 004c9e30  unit: RBX::VInstance::?$NonFactoryProduct  size: 472 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004c9e30
//
// 004c9e30  51                   push ecx
// 004c9e31  55                   push ebp
// 004c9e32  8be9                 mov ebp, ecx
// 004c9e34  8b4544               mov eax, dword ptr [ebp + 0x44]
// 004c9e37  3b442414             cmp eax, dword ptr [esp + 0x14]
// 004c9e3b  7c07                 jl 0x4c9e44
// 004c9e3d  32c0                 xor al, al
// 004c9e3f  5d                   pop ebp
// 004c9e40  59                   pop ecx
// 004c9e41  c20c00               ret 0xc
// 004c9e44  8b4500               mov eax, dword ptr [ebp]
// 004c9e47  56                   push esi
// 004c9e48  8d8828020000         lea ecx, [eax + 0x228]
// 004c9e4e  e81dd71100           call 0x5e7570
// 004c9e53  8bf0                 mov esi, eax
// 004c9e55  85f6                 test esi, esi
// 004c9e57  7464                 je 0x4c9ebd
// 004c9e59  807e5400             cmp byte ptr [esi + 0x54], 0
// 004c9e5d  7412                 je 0x4c9e71
// 004c9e5f  8b4e64               mov ecx, dword ptr [esi + 0x64]
// 004c9e62  034e58               add ecx, dword ptr [esi + 0x58]
// 004c9e65  8b5660               mov edx, dword ptr [esi + 0x60]
// 004c9e68  ffd2                 call edx
// 004c9e6a  d95e50               fstp dword ptr [esi + 0x50]
// 004c9e6d  c6465400             mov byte ptr [esi + 0x54], 0
// 004c9e71  d94650               fld dword ptr [esi + 0x50]
// 004c9e74  dcc0                 fadd st(0), st(0)
// 004c9e76  d94540               fld dword ptr [ebp + 0x40]
// 004c9e79  d8d1                 fcom st(1)
// 004c9e7b  dfe0                 fnstsw ax
// 004c9e7d  f6c401               test ah, 1
// 004c9e80  7504                 jne 0x4c9e86
// 004c9e82  ddd9                 fstp st(1)
// 004c9e84  eb17                 jmp 0x4c9e9d
// 004c9e86  ddd8                 fstp st(0)
// 004c9e88  d90544cc9300         fld dword ptr [0x93cc44]
// 004c9e8e  d8d1                 fcom st(1)
// 004c9e90  dfe0                 fnstsw ax
// 004c9e92  f6c441               test ah, 0x41
// 004c9e95  7a04                 jp 0x4c9e9b
// 004c9e97  ddd9                 fstp st(1)
// 004c9e99  eb02                 jmp 0x4c9e9d
// 004c9e9b  ddd8                 fstp st(0)
// 004c9e9d  d95d40               fstp dword ptr [ebp + 0x40]
// 004c9ea0  807e5400             cmp byte ptr [esi + 0x54], 0
// 004c9ea4  7412                 je 0x4c9eb8
// 004c9ea6  8b4e64               mov ecx, dword ptr [esi + 0x64]
// 004c9ea9  034e58               add ecx, dword ptr [esi + 0x58]
// 004c9eac  8b4660               mov eax, dword ptr [esi + 0x60]
// 004c9eaf  ffd0                 call eax
// 004c9eb1  d95e50               fstp dword ptr [esi + 0x50]
// 004c9eb4  c6465400             mov byte ptr [esi + 0x54], 0
// 004c9eb8  d94650               fld dword ptr [esi + 0x50]
// 004c9ebb  eb02                 jmp 0x4c9ebf
// 004c9ebd  d9ee                 fldz 
// 004c9ebf  8b4d00               mov ecx, dword ptr [ebp]
// 004c9ec2  d95c2408             fstp dword ptr [esp + 8]
// 004c9ec6  8b742410             mov esi, dword ptr [esp + 0x10]
// 004c9eca  e8e1ed0c00           call 0x598cb0
// 004c9ecf  d94024               fld dword ptr [eax + 0x24]
// 004c9ed2  d86624               fsub dword ptr [esi + 0x24]
// 004c9ed5  83c024               add eax, 0x24
// 004c9ed8  d94004               fld dword ptr [eax + 4]
// 004c9edb  d86628               fsub dword ptr [esi + 0x28]
// 004c9ede  d94008               fld dword ptr [eax + 8]
// 004c9ee1  d8662c               fsub dword ptr [esi + 0x2c]
// 004c9ee4  d9c9                 fxch st(1)
// 004c9ee6  d9e1                 fabs 
// 004c9ee8  d9ca                 fxch st(2)
// 004c9eea  d9e1                 fabs 
// 004c9eec  dec2                 faddp st(2)
// 004c9eee  d9e1                 fabs 
// 004c9ef0  dec1                 faddp st(1)
// 004c9ef2  d8642408             fsub dword ptr [esp + 8]
// 004c9ef6  d95548               fst dword ptr [ebp + 0x48]
// 004c9ef9  d90538cc9300         fld dword ptr [0x93cc38]
// 004c9eff  d8d1                 fcom st(1)
// 004c9f01  dfe0                 fnstsw ax
// 004c9f03  f6c401               test ah, 1
// 004c9f06  7504                 jne 0x4c9f0c
// 004c9f08  ddd9                 fstp st(1)
// 004c9f0a  eb17                 jmp 0x4c9f23
// 004c9f0c  ddd8                 fstp st(0)
// 004c9f0e  d9053ccc9300         fld dword ptr [0x93cc3c]
// 004c9f14  d8d1                 fcom st(1)
// 004c9f16  dfe0                 fnstsw ax
// 004c9f18  f6c441               test ah, 0x41
// 004c9f1b  7a04                 jp 0x4c9f21
// 004c9f1d  ddd9                 fstp st(1)
// 004c9f1f  eb02                 jmp 0x4c9f23
// 004c9f21  ddd8                 fstp st(0)
// 004c9f23  837d44ff             cmp dword ptr [ebp + 0x44], -1
// 004c9f27  d95548               fst dword ptr [ebp + 0x48]
// 004c9f2a  7545                 jne 0x4c9f71
// 004c9f2c  d94540               fld dword ptr [ebp + 0x40]
// 004c9f2f  8b4d00               mov ecx, dword ptr [ebp]
// 004c9f32  d9c0                 fld st(0)
// 004c9f34  57                   push edi
// 004c9f35  def2                 fdivrp st(2)
// 004c9f37  dec9                 fmulp st(1)
// 004c9f39  dd5d08               fstp qword ptr [ebp + 8]
// 004c9f3c  e86fed0c00           call 0x598cb0
// 004c9f41  8d5510               lea edx, [ebp + 0x10]
// 004c9f44  8bf0                 mov esi, eax
// 004c9f46  b909000000           mov ecx, 9
// 004c9f4b  8bfa                 mov edi, edx
// 004c9f4d  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 004c9f4f  d94024               fld dword ptr [eax + 0x24]
// 004c9f52  d95a24               fstp dword ptr [edx + 0x24]
// 004c9f55  d94028               fld dword ptr [eax + 0x28]
// 004c9f58  d95a28               fstp dword ptr [edx + 0x28]
// 004c9f5b  d9402c               fld dword ptr [eax + 0x2c]
// 004c9f5e  d95a2c               fstp dword ptr [edx + 0x2c]
// 004c9f61  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004c9f65  5f                   pop edi
// 004c9f66  894544               mov dword ptr [ebp + 0x44], eax
// 004c9f69  5e                   pop esi
// 004c9f6a  b001                 mov al, 1
// 004c9f6c  5d                   pop ebp
// 004c9f6d  59                   pop ecx
// 004c9f6e  c20c00               ret 0xc
// 004c9f71  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004c9f75  ddd8                 fstp st(0)
// 004c9f77  8b7500               mov esi, dword ptr [ebp]
// 004c9f7a  51                   push ecx
// 004c9f7b  8bce                 mov ecx, esi
// 004c9f7d  e85e8bf5ff           call 0x422ae0
// 004c9f82  84c0                 test al, al
// 004c9f84  7418                 je 0x4c9f9e
// 004c9f86  8b442418             mov eax, dword ptr [esp + 0x18]
// 004c9f8a  dd0548688200         fld qword ptr [0x826848]
// 004c9f90  894544               mov dword ptr [ebp + 0x44], eax
// 004c9f93  dd5d08               fstp qword ptr [ebp + 8]
// 004c9f96  5e                   pop esi
// 004c9f97  b001                 mov al, 1
// 004c9f99  5d                   pop ebp
// 004c9f9a  59                   pop ecx
// 004c9f9b  c20c00               ret 0xc
// 004c9f9e  8bce                 mov ecx, esi
// 004c9fa0  e80bed0c00           call 0x598cb0
// 004c9fa5  d94024               fld dword ptr [eax + 0x24]
// 004c9fa8  d86534               fsub dword ptr [ebp + 0x34]
// 004c9fab  8b4d00               mov ecx, dword ptr [ebp]
// 004c9fae  d94028               fld dword ptr [eax + 0x28]
// 004c9fb1  83c024               add eax, 0x24
// 004c9fb4  d86538               fsub dword ptr [ebp + 0x38]
// 004c9fb7  8d5510               lea edx, [ebp + 0x10]
// 004c9fba  d94008               fld dword ptr [eax + 8]
// 004c9fbd  52                   push edx
// 004c9fbe  d8653c               fsub dword ptr [ebp + 0x3c]
// 004c9fc1  d9c9                 fxch st(1)
// 004c9fc3  d9e1                 fabs 
// 004c9fc5  d9ca                 fxch st(2)
// 004c9fc7  d9e1                 fabs 
// 004c9fc9  dec2                 faddp st(2)
// 004c9fcb  d9e1                 fabs 
// 004c9fcd  dec1                 faddp st(1)
// 004c9fcf  d95c2414             fstp dword ptr [esp + 0x14]
// 004c9fd3  e8d8ec0c00           call 0x598cb0
// 004c9fd8  8bc8                 mov ecx, eax
// 004c9fda  e8f1920400           call 0x5132d0
// 004c9fdf  84c0                 test al, al
// 004c9fe1  7404                 je 0x4c9fe7
// 004c9fe3  d9e8                 fld1 
// 004c9fe5  eb02                 jmp 0x4c9fe9
// 004c9fe7  d9ee                 fldz 
// 004c9fe9  d8442410             fadd dword ptr [esp + 0x10]
// 004c9fed  8b442418             mov eax, dword ptr [esp + 0x18]
// 004c9ff1  894544               mov dword ptr [ebp + 0x44], eax
// 004c9ff4  5e                   pop esi
// 004c9ff5  d87548               fdiv dword ptr [ebp + 0x48]
// 004c9ff8  b001                 mov al, 1
// 004c9ffa  d84d40               fmul dword ptr [ebp + 0x40]
// 004c9ffd  d84d40               fmul dword ptr [ebp + 0x40]
// 004ca000  dd5d08               fstp qword ptr [ebp + 8]
// 004ca003  5d                   pop ebp
// 004ca004  59                   pop ecx
// 004ca005  c20c00               ret 0xc

#pragma float_control(precise, off)

extern "C" double __cdecl fabs(double);
#pragma intrinsic(fabs)

inline float clamp(float val, float low, float hi)
{
    if (val <= low)
        return low;
    else if (val >= hi)
        return hi;
    else
        return val;
}

extern float maxScale;
extern float minDistance;
extern float maxDistance;

struct Matrix3 {
    float elt[3][3];
};

struct Vector3 {
    float x, y, z;
    Vector3() {}
    Vector3(float x_, float y_, float z_) : x(x_), y(y_), z(z_) {}
    Vector3& operator=(const Vector3& o) { x = o.x; y = o.y; z = o.z; return *this; }
    Vector3 abs() const { return Vector3((float)fabs(x), (float)fabs(y), (float)fabs(z)); }
    float sum() const { return x + y + z; }
    Vector3 operator-(const Vector3& o) const { return Vector3(x - o.x, y - o.y, z - o.z); }
};

struct CoordinateFrame {
    Matrix3 rotation;
    Vector3 translation;
    bool fuzzyEq(const CoordinateFrame& other) const;
};

struct Sphere {
    char padding[0x50];
    float radius;
    bool dirty;
    char* object;
    unsigned unused;
    float (__thiscall *getter)(void*);
    int adjustment;
    float getRadius()
    {
        if (dirty) {
            radius = getter(object + adjustment);
            dirty = false;
        }
        return radius;
    }
};

struct Ball {
    Sphere* getSphere();
};

struct Part {
    char padding[0x228];
    Ball ball;
    const CoordinateFrame& getCoordinateFrame() const;
    bool contains(Part* other);
};

inline float fabsf_(float f) { return (float)fabs(f); }

inline float manhattan(const Vector3& v)
{
    return fabsf_(v.x) + fabsf_(v.y) + fabsf_(v.z);
}

struct Sender {
    Part* part;
    double priority;
    CoordinateFrame previous;
    float scale;
    int sequence;
    float distance;

    bool update(const CoordinateFrame& reference, Part* other, int newSequence);
};

bool Sender::update(const CoordinateFrame& reference, Part* other, int newSequence)
{
    if (sequence >= newSequence)
        return false;

    float radius;
    Part* current = part; Sphere* sphere = current->ball.getSphere();
    if (sphere) {
        scale = clamp(sphere->getRadius() * 2.0f, scale, maxScale);
        radius = sphere->getRadius();
    } else {
        radius = 0.0f;
    }

    distance = manhattan(part->getCoordinateFrame().translation - reference.translation) - radius;
    distance = clamp(distance, minDistance, maxDistance);

    if (sequence == -1) {
        float s = scale;
        priority = s / distance * s;
        previous = part->getCoordinateFrame();
    } else {
        Part* p = part;
        if (p->contains(other)) {
            priority = 1.7976931348623157e+308;
        } else {
            float moved = manhattan(p->getCoordinateFrame().translation - previous.translation);
            float change = (part->getCoordinateFrame().fuzzyEq(previous) ? 1.0f : 0.0f) + moved;
            priority = change / distance * scale * scale;
        }
    }
    sequence = newSequence;
    return true;
}
