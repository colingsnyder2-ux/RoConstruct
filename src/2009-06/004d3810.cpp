// from server: 100% by EspClaude
// roc 2009-06 004d3810  unit: RBX::Network::VClient::?$BoundFuncDesc  size: 475 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004d3810
//
// 004d3810  6aff                 push -1
// 004d3812  6880b18500           push 0x85b180
// 004d3817  64a100000000         mov eax, dword ptr fs:[0]
// 004d381d  50                   push eax
// 004d381e  64892500000000       mov dword ptr fs:[0], esp
// 004d3825  83ec2c               sub esp, 0x2c
// 004d3828  56                   push esi
// 004d3829  8bf1                 mov esi, ecx
// 004d382b  8b4e44               mov ecx, dword ptr [esi + 0x44]
// 004d382e  8b4640               mov eax, dword ptr [esi + 0x40]
// 004d3831  57                   push edi
// 004d3832  89442420             mov dword ptr [esp + 0x20], eax
// 004d3836  85c9                 test ecx, ecx
// 004d3838  7409                 je 0x4d3843
// 004d383a  8b11                 mov edx, dword ptr [ecx]
// 004d383c  8b4208               mov eax, dword ptr [edx + 8]
// 004d383f  ffd0                 call eax
// 004d3841  eb02                 jmp 0x4d3845
// 004d3843  33c0                 xor eax, eax
// 004d3845  89442424             mov dword ptr [esp + 0x24], eax
// 004d3849  8b7c2448             mov edi, dword ptr [esp + 0x48]
// 004d384d  8b17                 mov edx, dword ptr [edi]
// 004d384f  8b5204               mov edx, dword ptr [edx + 4]
// 004d3852  8d442420             lea eax, [esp + 0x20]
// 004d3856  50                   push eax
// 004d3857  6a01                 push 1
// 004d3859  8bcf                 mov ecx, edi
// 004d385b  c744244400000000     mov dword ptr [esp + 0x44], 0
// 004d3863  ffd2                 call edx
// 004d3865  8b4e4c               mov ecx, dword ptr [esi + 0x4c]
// 004d3868  8b4648               mov eax, dword ptr [esi + 0x48]
// 004d386b  89442418             mov dword ptr [esp + 0x18], eax
// 004d386f  85c9                 test ecx, ecx
// 004d3871  7409                 je 0x4d387c
// 004d3873  8b11                 mov edx, dword ptr [ecx]
// 004d3875  8b4208               mov eax, dword ptr [edx + 8]
// 004d3878  ffd0                 call eax
// 004d387a  eb02                 jmp 0x4d387e
// 004d387c  33c0                 xor eax, eax
// 004d387e  8944241c             mov dword ptr [esp + 0x1c], eax
// 004d3882  8b17                 mov edx, dword ptr [edi]
// 004d3884  8b5204               mov edx, dword ptr [edx + 4]
// 004d3887  8d442418             lea eax, [esp + 0x18]
// 004d388b  50                   push eax
// 004d388c  6a02                 push 2
// 004d388e  8bcf                 mov ecx, edi
// 004d3890  c644244401           mov byte ptr [esp + 0x44], 1
// 004d3895  ffd2                 call edx
// 004d3897  8b4e54               mov ecx, dword ptr [esi + 0x54]
// 004d389a  8b4650               mov eax, dword ptr [esi + 0x50]
// 004d389d  89442410             mov dword ptr [esp + 0x10], eax
// 004d38a1  85c9                 test ecx, ecx
// 004d38a3  7409                 je 0x4d38ae
// 004d38a5  8b11                 mov edx, dword ptr [ecx]
// 004d38a7  8b4208               mov eax, dword ptr [edx + 8]
// 004d38aa  ffd0                 call eax
// 004d38ac  eb02                 jmp 0x4d38b0
// 004d38ae  33c0                 xor eax, eax
// 004d38b0  89442414             mov dword ptr [esp + 0x14], eax
// 004d38b4  8b17                 mov edx, dword ptr [edi]
// 004d38b6  8b5204               mov edx, dword ptr [edx + 4]
// 004d38b9  8d442410             lea eax, [esp + 0x10]
// 004d38bd  50                   push eax
// 004d38be  6a03                 push 3
// 004d38c0  8bcf                 mov ecx, edi
// 004d38c2  c644244402           mov byte ptr [esp + 0x44], 2
// 004d38c7  ffd2                 call edx
// 004d38c9  8b4e5c               mov ecx, dword ptr [esi + 0x5c]
// 004d38cc  8b4658               mov eax, dword ptr [esi + 0x58]
// 004d38cf  89442408             mov dword ptr [esp + 8], eax
// 004d38d3  85c9                 test ecx, ecx
// 004d38d5  7409                 je 0x4d38e0
// 004d38d7  8b11                 mov edx, dword ptr [ecx]
// 004d38d9  8b4208               mov eax, dword ptr [edx + 8]
// 004d38dc  ffd0                 call eax
// 004d38de  eb02                 jmp 0x4d38e2
// 004d38e0  33c0                 xor eax, eax
// 004d38e2  8944240c             mov dword ptr [esp + 0xc], eax
// 004d38e6  8b17                 mov edx, dword ptr [edi]
// 004d38e8  8b5204               mov edx, dword ptr [edx + 4]
// 004d38eb  8d442408             lea eax, [esp + 8]
// 004d38ef  50                   push eax
// 004d38f0  6a04                 push 4
// 004d38f2  8bcf                 mov ecx, edi
// 004d38f4  c644244403           mov byte ptr [esp + 0x44], 3
// 004d38f9  ffd2                 call edx
// 004d38fb  8b442444             mov eax, dword ptr [esp + 0x44]
// 004d38ff  6a00                 push 0
// 004d3901  68a8169f00           push 0x9f16a8
// 004d3906  68c4bf9d00           push 0x9dbfc4
// 004d390b  6a00                 push 0
// 004d390d  50                   push eax
// 004d390e  e867632400           call 0x719c7a
// 004d3913  8bf8                 mov edi, eax
// 004d3915  83c414               add esp, 0x14
// 004d3918  85ff                 test edi, edi
// 004d391a  751e                 jne 0x4d393a
// 004d391c  6850d38a00           push 0x8ad350
// 004d3921  8d4c242c             lea ecx, [esp + 0x2c]
// 004d3925  ff1570e98900         call dword ptr [0x89e970]
// 004d392b  68b04b9800           push 0x984bb0
// 004d3930  8d4c242c             lea ecx, [esp + 0x2c]
// 004d3934  51                   push ecx
// 004d3935  e810612400           call 0x719a4a
// 004d393a  8d4c2408             lea ecx, [esp + 8]
// 004d393e  e8ad441100           call 0x5e7df0
// 004d3943  8b10                 mov edx, dword ptr [eax]
// 004d3945  52                   push edx
// 004d3946  8d4c2414             lea ecx, [esp + 0x14]
// 004d394a  e8a1441100           call 0x5e7df0
// 004d394f  8b00                 mov eax, dword ptr [eax]
// 004d3951  50                   push eax
// 004d3952  8d4c2420             lea ecx, [esp + 0x20]
// 004d3956  e895441100           call 0x5e7df0
// 004d395b  8b08                 mov ecx, dword ptr [eax]
// 004d395d  51                   push ecx
// 004d395e  8d4c242c             lea ecx, [esp + 0x2c]
// 004d3962  e8d94a1100           call 0x5e8440
// 004d3967  83ec1c               sub esp, 0x1c
// 004d396a  8bcc                 mov ecx, esp
// 004d396c  89642470             mov dword ptr [esp + 0x70], esp
// 004d3970  50                   push eax
// 004d3971  ff15b8e48900         call dword ptr [0x89e4b8]
// 004d3977  8b4e3c               mov ecx, dword ptr [esi + 0x3c]
// 004d397a  8b5638               mov edx, dword ptr [esi + 0x38]
// 004d397d  03cf                 add ecx, edi
// 004d397f  ffd2                 call edx
// 004d3981  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004d3985  c644243c02           mov byte ptr [esp + 0x3c], 2
// 004d398a  85c9                 test ecx, ecx
// 004d398c  7408                 je 0x4d3996
// 004d398e  8b01                 mov eax, dword ptr [ecx]
// 004d3990  8b10                 mov edx, dword ptr [eax]
// 004d3992  6a01                 push 1
// 004d3994  ffd2                 call edx
// 004d3996  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004d399a  c644243c01           mov byte ptr [esp + 0x3c], 1
// 004d399f  85c9                 test ecx, ecx
// 004d39a1  7408                 je 0x4d39ab
// 004d39a3  8b01                 mov eax, dword ptr [ecx]
// 004d39a5  8b10                 mov edx, dword ptr [eax]
// 004d39a7  6a01                 push 1
// 004d39a9  ffd2                 call edx
// 004d39ab  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 004d39af  c644243c00           mov byte ptr [esp + 0x3c], 0
// 004d39b4  85c9                 test ecx, ecx
// 004d39b6  7408                 je 0x4d39c0
// 004d39b8  8b01                 mov eax, dword ptr [ecx]
// 004d39ba  8b10                 mov edx, dword ptr [eax]
// 004d39bc  6a01                 push 1
// 004d39be  ffd2                 call edx
// 004d39c0  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 004d39c4  c744243cffffffff     mov dword ptr [esp + 0x3c], 0xffffffff
// 004d39cc  85c9                 test ecx, ecx
// 004d39ce  7408                 je 0x4d39d8
// 004d39d0  8b01                 mov eax, dword ptr [ecx]
// 004d39d2  8b10                 mov edx, dword ptr [eax]
// 004d39d4  6a01                 push 1
// 004d39d6  ffd2                 call edx
// 004d39d8  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 004d39dc  5f                   pop edi
// 004d39dd  64890d00000000       mov dword ptr fs:[0], ecx
// 004d39e4  5e                   pop esi
// 004d39e5  83c438               add esp, 0x38
// 004d39e8  c20800               ret 8
// copied from an identical function in another client (function ?invoke@BoundFuncDesc@@QAEXPAVDescribedBase@Reflection@RBX@@PAUArguments@@@Z)

// from server: 68% by colin
// roc 2008-06 004a04b0  unit: RBX::Network::VClient::?$BoundFuncDesc  size: 475 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004a04b0
//
// 004a04b0  6aff                 push -1
// 004a04b2  6820797c00           push 0x7c7920
// 004a04b7  64a100000000         mov eax, dword ptr fs:[0]
// 004a04bd  50                   push eax
// 004a04be  64892500000000       mov dword ptr fs:[0], esp
// 004a04c5  83ec2c               sub esp, 0x2c
// 004a04c8  56                   push esi
// 004a04c9  8bf1                 mov esi, ecx
// 004a04cb  8b4e44               mov ecx, dword ptr [esi + 0x44]
// 004a04ce  8b4640               mov eax, dword ptr [esi + 0x40]
// 004a04d1  57                   push edi
// 004a04d2  89442420             mov dword ptr [esp + 0x20], eax
// 004a04d6  85c9                 test ecx, ecx
// 004a04d8  7409                 je 0x4a04e3
// 004a04da  8b11                 mov edx, dword ptr [ecx]
// 004a04dc  8b4208               mov eax, dword ptr [edx + 8]
// 004a04df  ffd0                 call eax
// 004a04e1  eb02                 jmp 0x4a04e5
// 004a04e3  33c0                 xor eax, eax
// 004a04e5  89442424             mov dword ptr [esp + 0x24], eax
// 004a04e9  8b7c2448             mov edi, dword ptr [esp + 0x48]
// 004a04ed  8b17                 mov edx, dword ptr [edi]
// 004a04ef  8b5204               mov edx, dword ptr [edx + 4]
// 004a04f2  8d442420             lea eax, [esp + 0x20]
// 004a04f6  50                   push eax
// 004a04f7  6a01                 push 1
// 004a04f9  8bcf                 mov ecx, edi
// 004a04fb  c744244400000000     mov dword ptr [esp + 0x44], 0
// 004a0503  ffd2                 call edx
// 004a0505  8b4e4c               mov ecx, dword ptr [esi + 0x4c]
// 004a0508  8b4648               mov eax, dword ptr [esi + 0x48]
// 004a050b  89442418             mov dword ptr [esp + 0x18], eax
// 004a050f  85c9                 test ecx, ecx
// 004a0511  7409                 je 0x4a051c
// 004a0513  8b11                 mov edx, dword ptr [ecx]
// 004a0515  8b4208               mov eax, dword ptr [edx + 8]
// 004a0518  ffd0                 call eax
// 004a051a  eb02                 jmp 0x4a051e
// 004a051c  33c0                 xor eax, eax
// 004a051e  8944241c             mov dword ptr [esp + 0x1c], eax
// 004a0522  8b17                 mov edx, dword ptr [edi]
// 004a0524  8b5204               mov edx, dword ptr [edx + 4]
// 004a0527  8d442418             lea eax, [esp + 0x18]
// 004a052b  50                   push eax
// 004a052c  6a02                 push 2
// 004a052e  8bcf                 mov ecx, edi
// 004a0530  c644244401           mov byte ptr [esp + 0x44], 1
// 004a0535  ffd2                 call edx
// 004a0537  8b4e54               mov ecx, dword ptr [esi + 0x54]
// 004a053a  8b4650               mov eax, dword ptr [esi + 0x50]
// 004a053d  89442410             mov dword ptr [esp + 0x10], eax
// 004a0541  85c9                 test ecx, ecx
// 004a0543  7409                 je 0x4a054e
// 004a0545  8b11                 mov edx, dword ptr [ecx]
// 004a0547  8b4208               mov eax, dword ptr [edx + 8]
// 004a054a  ffd0                 call eax
// 004a054c  eb02                 jmp 0x4a0550
// 004a054e  33c0                 xor eax, eax
// 004a0550  89442414             mov dword ptr [esp + 0x14], eax
// 004a0554  8b17                 mov edx, dword ptr [edi]
// 004a0556  8b5204               mov edx, dword ptr [edx + 4]
// 004a0559  8d442410             lea eax, [esp + 0x10]
// 004a055d  50                   push eax
// 004a055e  6a03                 push 3
// 004a0560  8bcf                 mov ecx, edi
// 004a0562  c644244402           mov byte ptr [esp + 0x44], 2
// 004a0567  ffd2                 call edx
// 004a0569  8b4e5c               mov ecx, dword ptr [esi + 0x5c]
// 004a056c  8b4658               mov eax, dword ptr [esi + 0x58]
// 004a056f  89442408             mov dword ptr [esp + 8], eax
// 004a0573  85c9                 test ecx, ecx
// 004a0575  7409                 je 0x4a0580
// 004a0577  8b11                 mov edx, dword ptr [ecx]
// 004a0579  8b4208               mov eax, dword ptr [edx + 8]
// 004a057c  ffd0                 call eax
// 004a057e  eb02                 jmp 0x4a0582
// 004a0580  33c0                 xor eax, eax
// 004a0582  8944240c             mov dword ptr [esp + 0xc], eax
// 004a0586  8b17                 mov edx, dword ptr [edi]
// 004a0588  8b5204               mov edx, dword ptr [edx + 4]
// 004a058b  8d442408             lea eax, [esp + 8]
// 004a058f  50                   push eax
// 004a0590  6a04                 push 4
// 004a0592  8bcf                 mov ecx, edi
// 004a0594  c644244403           mov byte ptr [esp + 0x44], 3
// 004a0599  ffd2                 call edx
// 004a059b  8b442444             mov eax, dword ptr [esp + 0x44]
// 004a059f  6a00                 push 0
// 004a05a1  68dc8d9300           push 0x938ddc
// 004a05a6  68fc919200           push 0x9291fc
// 004a05ab  6a00                 push 0
// 004a05ad  50                   push eax
// 004a05ae  e813122000           call 0x6a17c6
// 004a05b3  8bf8                 mov edi, eax
// 004a05b5  83c414               add esp, 0x14
// 004a05b8  85ff                 test edi, edi
// 004a05ba  751e                 jne 0x4a05da
// 004a05bc  6834ba8000           push 0x80ba34
// 004a05c1  8d4c242c             lea ecx, [esp + 0x2c]
// 004a05c5  ff1564288000         call dword ptr [0x802864]
// 004a05cb  682c368d00           push 0x8d362c
// 004a05d0  8d4c242c             lea ecx, [esp + 0x2c]
// 004a05d4  51                   push ecx
// 004a05d5  e8b20f2000           call 0x6a158c
// 004a05da  8d4c2408             lea ecx, [esp + 8]
// 004a05de  e87de40c00           call 0x56ea60
// 004a05e3  8b10                 mov edx, dword ptr [eax]
// 004a05e5  52                   push edx
// 004a05e6  8d4c2414             lea ecx, [esp + 0x14]
// 004a05ea  e871e40c00           call 0x56ea60
// 004a05ef  8b00                 mov eax, dword ptr [eax]
// 004a05f1  50                   push eax
// 004a05f2  8d4c2420             lea ecx, [esp + 0x20]
// 004a05f6  e865e40c00           call 0x56ea60
// 004a05fb  8b08                 mov ecx, dword ptr [eax]
// 004a05fd  51                   push ecx
// 004a05fe  8d4c242c             lea ecx, [esp + 0x2c]
// 004a0602  e8a9ea0c00           call 0x56f0b0
// 004a0607  83ec1c               sub esp, 0x1c
// 004a060a  8bcc                 mov ecx, esp
// 004a060c  89642470             mov dword ptr [esp + 0x70], esp
// 004a0610  50                   push eax
// 004a0611  ff155c248000         call dword ptr [0x80245c]
// 004a0617  8b4e3c               mov ecx, dword ptr [esi + 0x3c]
// 004a061a  8b5638               mov edx, dword ptr [esi + 0x38]
// 004a061d  03cf                 add ecx, edi
// 004a061f  ffd2                 call edx
// 004a0621  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004a0625  c644243c02           mov byte ptr [esp + 0x3c], 2
// 004a062a  85c9                 test ecx, ecx
// 004a062c  7408                 je 0x4a0636
// 004a062e  8b01                 mov eax, dword ptr [ecx]
// 004a0630  8b10                 mov edx, dword ptr [eax]
// 004a0632  6a01                 push 1
// 004a0634  ffd2                 call edx
// 004a0636  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004a063a  c644243c01           mov byte ptr [esp + 0x3c], 1
// 004a063f  85c9                 test ecx, ecx
// 004a0641  7408                 je 0x4a064b
// 004a0643  8b01                 mov eax, dword ptr [ecx]
// 004a0645  8b10                 mov edx, dword ptr [eax]
// 004a0647  6a01                 push 1
// 004a0649  ffd2                 call edx
// 004a064b  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 004a064f  c644243c00           mov byte ptr [esp + 0x3c], 0
// 004a0654  85c9                 test ecx, ecx
// 004a0656  7408                 je 0x4a0660
// 004a0658  8b01                 mov eax, dword ptr [ecx]
// 004a065a  8b10                 mov edx, dword ptr [eax]
// 004a065c  6a01                 push 1
// 004a065e  ffd2                 call edx
// 004a0660  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 004a0664  c744243cffffffff     mov dword ptr [esp + 0x3c], 0xffffffff
// 004a066c  85c9                 test ecx, ecx
// 004a066e  7408                 je 0x4a0678
// 004a0670  8b01                 mov eax, dword ptr [ecx]
// 004a0672  8b10                 mov edx, dword ptr [eax]
// 004a0674  6a01                 push 1
// 004a0676  ffd2                 call edx
// 004a0678  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 004a067c  5f                   pop edi
// 004a067d  64890d00000000       mov dword ptr fs:[0], ecx
// 004a0684  5e                   pop esi
// 004a0685  83c438               add esp, 0x38
// 004a0688  c20800               ret 8

// from server: 61% by king_originala
// roc 2008-06 004a04b0  unit: RBX::Network::VClient::?$BoundFuncDesc  size: 475 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004a04b0
//
// 004a04b0  6aff                 push -1
// 004a04b2  6820797c00           push 0x7c7920
// 004a04b7  64a100000000         mov eax, dword ptr fs:[0]
// 004a04bd  50                   push eax
// 004a04be  64892500000000       mov dword ptr fs:[0], esp
// 004a04c5  83ec2c               sub esp, 0x2c
// 004a04c8  56                   push esi
// 004a04c9  8bf1                 mov esi, ecx
// 004a04cb  8b4e44               mov ecx, dword ptr [esi + 0x44]
// 004a04ce  8b4640               mov eax, dword ptr [esi + 0x40]
// 004a04d1  57                   push edi
// 004a04d2  89442420             mov dword ptr [esp + 0x20], eax
// 004a04d6  85c9                 test ecx, ecx
// 004a04d8  7409                 je 0x4a04e3
// 004a04da  8b11                 mov edx, dword ptr [ecx]
// 004a04dc  8b4208               mov eax, dword ptr [edx + 8]
// 004a04df  ffd0                 call eax
// 004a04e1  eb02                 jmp 0x4a04e5
// 004a04e3  33c0                 xor eax, eax
// 004a04e5  89442424             mov dword ptr [esp + 0x24], eax
// 004a04e9  8b7c2448             mov edi, dword ptr [esp + 0x48]
// 004a04ed  8b17                 mov edx, dword ptr [edi]
// 004a04ef  8b5204               mov edx, dword ptr [edx + 4]
// 004a04f2  8d442420             lea eax, [esp + 0x20]
// 004a04f6  50                   push eax
// 004a04f7  6a01                 push 1
// 004a04f9  8bcf                 mov ecx, edi
// 004a04fb  c744244400000000     mov dword ptr [esp + 0x44], 0
// 004a0503  ffd2                 call edx
// 004a0505  8b4e4c               mov ecx, dword ptr [esi + 0x4c]
// 004a0508  8b4648               mov eax, dword ptr [esi + 0x48]
// 004a050b  89442418             mov dword ptr [esp + 0x18], eax
// 004a050f  85c9                 test ecx, ecx
// 004a0511  7409                 je 0x4a051c
// 004a0513  8b11                 mov edx, dword ptr [ecx]
// 004a0515  8b4208               mov eax, dword ptr [edx + 8]
// 004a0518  ffd0                 call eax
// 004a051a  eb02                 jmp 0x4a051e
// 004a051c  33c0                 xor eax, eax
// 004a051e  8944241c             mov dword ptr [esp + 0x1c], eax
// 004a0522  8b17                 mov edx, dword ptr [edi]
// 004a0524  8b5204               mov edx, dword ptr [edx + 4]
// 004a0527  8d442418             lea eax, [esp + 0x18]
// 004a052b  50                   push eax
// 004a052c  6a02                 push 2
// 004a052e  8bcf                 mov ecx, edi
// 004a0530  c644244401           mov byte ptr [esp + 0x44], 1
// 004a0535  ffd2                 call edx
// 004a0537  8b4e54               mov ecx, dword ptr [esi + 0x54]
// 004a053a  8b4650               mov eax, dword ptr [esi + 0x50]
// 004a053d  89442410             mov dword ptr [esp + 0x10], eax
// 004a0541  85c9                 test ecx, ecx
// 004a0543  7409                 je 0x4a054e
// 004a0545  8b11                 mov edx, dword ptr [ecx]
// 004a0547  8b4208               mov eax, dword ptr [edx + 8]
// 004a054a  ffd0                 call eax
// 004a054c  eb02                 jmp 0x4a0550
// 004a054e  33c0                 xor eax, eax
// 004a0550  89442414             mov dword ptr [esp + 0x14], eax
// 004a0554  8b17                 mov edx, dword ptr [edi]
// 004a0556  8b5204               mov edx, dword ptr [edx + 4]
// 004a0559  8d442410             lea eax, [esp + 0x10]
// 004a055d  50                   push eax
// 004a055e  6a03                 push 3
// 004a0560  8bcf                 mov ecx, edi
// 004a0562  c644244402           mov byte ptr [esp + 0x44], 2
// 004a0567  ffd2                 call edx
// 004a0569  8b4e5c               mov ecx, dword ptr [esi + 0x5c]
// 004a056c  8b4658               mov eax, dword ptr [esi + 0x58]
// 004a056f  89442408             mov dword ptr [esp + 8], eax
// 004a0573  85c9                 test ecx, ecx
// 004a0575  7409                 je 0x4a0580
// 004a0577  8b11                 mov edx, dword ptr [ecx]
// 004a0579  8b4208               mov eax, dword ptr [edx + 8]
// 004a057c  ffd0                 call eax
// 004a057e  eb02                 jmp 0x4a0582
// 004a0580  33c0                 xor eax, eax
// 004a0582  8944240c             mov dword ptr [esp + 0xc], eax
// 004a0586  8b17                 mov edx, dword ptr [edi]
// 004a0588  8b5204               mov edx, dword ptr [edx + 4]
// 004a058b  8d442408             lea eax, [esp + 8]
// 004a058f  50                   push eax
// 004a0590  6a04                 push 4
// 004a0592  8bcf                 mov ecx, edi
// 004a0594  c644244403           mov byte ptr [esp + 0x44], 3
// 004a0599  ffd2                 call edx
// 004a059b  8b442444             mov eax, dword ptr [esp + 0x44]
// 004a059f  6a00                 push 0
// 004a05a1  68dc8d9300           push 0x938ddc
// 004a05a6  68fc919200           push 0x9291fc
// 004a05ab  6a00                 push 0
// 004a05ad  50                   push eax
// 004a05ae  e813122000           call 0x6a17c6
// 004a05b3  8bf8                 mov edi, eax
// 004a05b5  83c414               add esp, 0x14
// 004a05b8  85ff                 test edi, edi
// 004a05ba  751e                 jne 0x4a05da
// 004a05bc  6834ba8000           push 0x80ba34
// 004a05c1  8d4c242c             lea ecx, [esp + 0x2c]
// 004a05c5  ff1564288000         call dword ptr [0x802864]
// 004a05cb  682c368d00           push 0x8d362c
// 004a05d0  8d4c242c             lea ecx, [esp + 0x2c]
// 004a05d4  51                   push ecx
// 004a05d5  e8b20f2000           call 0x6a158c
// 004a05da  8d4c2408             lea ecx, [esp + 8]
// 004a05de  e87de40c00           call 0x56ea60
// 004a05e3  8b10                 mov edx, dword ptr [eax]
// 004a05e5  52                   push edx
// 004a05e6  8d4c2414             lea ecx, [esp + 0x14]
// 004a05ea  e871e40c00           call 0x56ea60
// 004a05ef  8b00                 mov eax, dword ptr [eax]
// 004a05f1  50                   push eax
// 004a05f2  8d4c2420             lea ecx, [esp + 0x20]
// 004a05f6  e865e40c00           call 0x56ea60
// 004a05fb  8b08                 mov ecx, dword ptr [eax]
// 004a05fd  51                   push ecx
// 004a05fe  8d4c242c             lea ecx, [esp + 0x2c]
// 004a0602  e8a9ea0c00           call 0x56f0b0
// 004a0607  83ec1c               sub esp, 0x1c
// 004a060a  8bcc                 mov ecx, esp
// 004a060c  89642470             mov dword ptr [esp + 0x70], esp
// 004a0610  50                   push eax
// 004a0611  ff155c248000         call dword ptr [0x80245c]
// 004a0617  8b4e3c               mov ecx, dword ptr [esi + 0x3c]
// 004a061a  8b5638               mov edx, dword ptr [esi + 0x38]
// 004a061d  03cf                 add ecx, edi
// 004a061f  ffd2                 call edx
// 004a0621  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004a0625  c644243c02           mov byte ptr [esp + 0x3c], 2
// 004a062a  85c9                 test ecx, ecx
// 004a062c  7408                 je 0x4a0636
// 004a062e  8b01                 mov eax, dword ptr [ecx]
// 004a0630  8b10                 mov edx, dword ptr [eax]
// 004a0632  6a01                 push 1
// 004a0634  ffd2                 call edx
// 004a0636  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004a063a  c644243c01           mov byte ptr [esp + 0x3c], 1
// 004a063f  85c9                 test ecx, ecx
// 004a0641  7408                 je 0x4a064b
// 004a0643  8b01                 mov eax, dword ptr [ecx]
// 004a0645  8b10                 mov edx, dword ptr [eax]
// 004a0647  6a01                 push 1
// 004a0649  ffd2                 call edx
// 004a064b  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 004a064f  c644243c00           mov byte ptr [esp + 0x3c], 0
// 004a0654  85c9                 test ecx, ecx
// 004a0656  7408                 je 0x4a0660
// 004a0658  8b01                 mov eax, dword ptr [ecx]
// 004a065a  8b10                 mov edx, dword ptr [eax]
// 004a065c  6a01                 push 1
// 004a065e  ffd2                 call edx
// 004a0660  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 004a0664  c744243cffffffff     mov dword ptr [esp + 0x3c], 0xffffffff
// 004a066c  85c9                 test ecx, ecx
// 004a066e  7408                 je 0x4a0678
// 004a0670  8b01                 mov eax, dword ptr [ecx]
// 004a0672  8b10                 mov edx, dword ptr [eax]
// 004a0674  6a01                 push 1
// 004a0676  ffd2                 call edx
// 004a0678  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 004a067c  5f                   pop edi
// 004a067d  64890d00000000       mov dword ptr fs:[0], ecx
// 004a0684  5e                   pop esi
// 004a0685  83c438               add esp, 0x38
// 004a0688  c20800               ret 8

#include <string>
#include <typeinfo>
typedef std::string String;
struct Cloneable {
    virtual ~Cloneable();
    virtual void reserved();
    virtual Cloneable* clone();
};

struct Any {
    Cloneable* content;
    Any(const Any& other) : content(other.content ? other.content->clone() : 0) {}
    ~Any() { delete content; }
};

struct Argument {
    void* value;
    Any any;

    int* integer();
    String* string();
};

struct Arguments {
    virtual void reserved();
    virtual void read(int index, Argument* argument);
};

namespace RBX { namespace Reflection {
class DescribedBase {
public:
    virtual ~DescribedBase();
};
} }
using RBX::Reflection::DescribedBase;

struct OtherBase {
    virtual ~OtherBase();
};

namespace RBX { namespace Network {
class Client : public DescribedBase, public OtherBase {
};
} }
using RBX::Network::Client;

typedef void (Client::*ClientFunction)(String, int, int, int);

template <class Target, class Source>
inline Target polymorphic_cast(Source* x)
{
    Target tmp = dynamic_cast<Target>(x);
    if (tmp == 0) throw std::bad_cast();
    return tmp;
}

struct BoundFuncDesc {
    char padding[56];
    ClientFunction function;
    Argument first;
    Argument second;
    Argument third;
    Argument fourth;

    void invoke(DescribedBase* object, Arguments* arguments);
};

void BoundFuncDesc::invoke(DescribedBase* object, Arguments* arguments) {
    Argument a(first);
    arguments->read(1, &a);

    Argument b(second);
    arguments->read(2, &b);

    Argument c(third);
    arguments->read(3, &c);

    Argument d(fourth);
    arguments->read(4, &d);

    Client* client = polymorphic_cast<Client*>(object);
    (client->*function)(*a.string(), *b.integer(), *c.integer(), *d.integer());
}