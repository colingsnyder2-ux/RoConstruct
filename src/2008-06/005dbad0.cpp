// from server: 100% by EspClaude
// from server: 97% by Espeon
// roc 2008-06 005dbad0  unit: RBX::VPartInstance::?$FilteredSelection  size: 412 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005dbad0
//
// 005dbad0  6aff                 push -1
// 005dbad2  6868917d00           push 0x7d9168
// 005dbad7  64a100000000         mov eax, dword ptr fs:[0]
// 005dbadd  50                   push eax
// 005dbade  64892500000000       mov dword ptr fs:[0], esp
// 005dbae5  83ec0c               sub esp, 0xc
// 005dbae8  53                   push ebx
// 005dbae9  56                   push esi
// 005dbaea  8b742424             mov esi, dword ptr [esp + 0x24]
// 005dbaee  8bd9                 mov ebx, ecx
// 005dbaf0  56                   push esi
// 005dbaf1  895c240c             mov dword ptr [esp + 0xc], ebx
// 005dbaf5  e8c6f1f7ff           call 0x55acc0
// 005dbafa  83bb3401000000       cmp dword ptr [ebx + 0x134], 0
// 005dbb01  0f8552010000         jne 0x5dbc59
// 005dbb07  8b4608               mov eax, dword ptr [esi + 8]
// 005dbb0a  50                   push eax
// 005dbb0b  e8a061e4ff           call 0x421cb0
// 005dbb10  50                   push eax
// 005dbb11  8d4c2414             lea ecx, [esp + 0x14]
// 005dbb15  51                   push ecx
// 005dbb16  e825cf0300           call 0x618a40
// 005dbb1b  83c40c               add esp, 0xc
// 005dbb1e  8b10                 mov edx, dword ptr [eax]
// 005dbb20  83c004               add eax, 4
// 005dbb23  50                   push eax
// 005dbb24  8d8b38010000         lea ecx, [ebx + 0x138]
// 005dbb2a  c744242000000000     mov dword ptr [esp + 0x20], 0
// 005dbb32  899334010000         mov dword ptr [ebx + 0x134], edx
// 005dbb38  e8736ae2ff           call 0x4025b0
// 005dbb3d  8b442410             mov eax, dword ptr [esp + 0x10]
// 005dbb41  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 005dbb49  85c0                 test eax, eax
// 005dbb4b  742c                 je 0x5dbb79
// 005dbb4d  8bf0                 mov esi, eax
// 005dbb4f  83c004               add eax, 4
// 005dbb52  83c9ff               or ecx, 0xffffffff
// 005dbb55  f00fc108             lock xadd dword ptr [eax], ecx
// 005dbb59  751e                 jne 0x5dbb79
// 005dbb5b  8b16                 mov edx, dword ptr [esi]
// 005dbb5d  8b4204               mov eax, dword ptr [edx + 4]
// 005dbb60  8bce                 mov ecx, esi
// 005dbb62  ffd0                 call eax
// 005dbb64  8d4e08               lea ecx, [esi + 8]
// 005dbb67  83caff               or edx, 0xffffffff
// 005dbb6a  f00fc111             lock xadd dword ptr [ecx], edx
// 005dbb6e  7509                 jne 0x5dbb79
// 005dbb70  8b06                 mov eax, dword ptr [esi]
// 005dbb72  8b5008               mov edx, dword ptr [eax + 8]
// 005dbb75  8bce                 mov ecx, esi
// 005dbb77  ffd2                 call edx
// 005dbb79  8b8334010000         mov eax, dword ptr [ebx + 0x134]
// 005dbb7f  85c0                 test eax, eax
// 005dbb81  0f84d2000000         je 0x5dbc59
// 005dbb87  8bb054010000         mov esi, dword ptr [eax + 0x154]
// 005dbb8d  55                   push ebp
// 005dbb8e  57                   push edi
// 005dbb8f  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 005dbb92  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 005dbb95  7606                 jbe 0x5dbb9d
// 005dbb97  ff1590288000         call dword ptr [0x802890]
// 005dbb9d  8b2e                 mov ebp, dword ptr [esi]
// 005dbb9f  90                   nop 
// 005dbba0  8b8334010000         mov eax, dword ptr [ebx + 0x134]
// 005dbba6  8bb054010000         mov esi, dword ptr [eax + 0x154]
// 005dbbac  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 005dbbaf  395e0c               cmp dword ptr [esi + 0xc], ebx
// 005dbbb2  7606                 jbe 0x5dbbba
// 005dbbb4  ff1590288000         call dword ptr [0x802890]
// 005dbbba  8b36                 mov esi, dword ptr [esi]
// 005dbbbc  85ed                 test ebp, ebp
// 005dbbbe  7404                 je 0x5dbbc4
// 005dbbc0  3bee                 cmp ebp, esi
// 005dbbc2  740a                 je 0x5dbbce
// 005dbbc4  8b3590288000         mov esi, dword ptr [0x802890]
// 005dbbca  ffd6                 call esi
// 005dbbcc  eb06                 jmp 0x5dbbd4
// 005dbbce  8b3590288000         mov esi, dword ptr [0x802890]
// 005dbbd4  3bfb                 cmp edi, ebx
// 005dbbd6  7469                 je 0x5dbc41
// 005dbbd8  85ed                 test ebp, ebp
// 005dbbda  755b                 jne 0x5dbc37
// 005dbbdc  ffd6                 call esi
// 005dbbde  33c0                 xor eax, eax
// 005dbbe0  3b7810               cmp edi, dword ptr [eax + 0x10]
// 005dbbe3  7202                 jb 0x5dbbe7
// 005dbbe5  ffd6                 call esi
// 005dbbe7  8b07                 mov eax, dword ptr [edi]
// 005dbbe9  6a00                 push 0
// 005dbbeb  6850dd9200           push 0x92dd50
// 005dbbf0  687c909200           push 0x92907c
// 005dbbf5  6a00                 push 0
// 005dbbf7  50                   push eax
// 005dbbf8  e8c95b0c00           call 0x6a17c6
// 005dbbfd  83c414               add esp, 0x14
// 005dbc00  8944242c             mov dword ptr [esp + 0x2c], eax
// 005dbc04  85c0                 test eax, eax
// 005dbc06  7414                 je 0x5dbc1c
// 005dbc08  8d4c242c             lea ecx, [esp + 0x2c]
// 005dbc0c  51                   push ecx
// 005dbc0d  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 005dbc11  81c13c010000         add ecx, 0x13c
// 005dbc17  e88457e4ff           call 0x4213a0
// 005dbc1c  85ed                 test ebp, ebp
// 005dbc1e  751c                 jne 0x5dbc3c
// 005dbc20  ffd6                 call esi
// 005dbc22  33c0                 xor eax, eax
// 005dbc24  3b7810               cmp edi, dword ptr [eax + 0x10]
// 005dbc27  7202                 jb 0x5dbc2b
// 005dbc29  ffd6                 call esi
// 005dbc2b  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 005dbc2f  83c708               add edi, 8
// 005dbc32  e969ffffff           jmp 0x5dbba0
// 005dbc37  8b4500               mov eax, dword ptr [ebp]
// 005dbc3a  eba4                 jmp 0x5dbbe0
// 005dbc3c  8b4500               mov eax, dword ptr [ebp]
// 005dbc3f  ebe3                 jmp 0x5dbc24
// 005dbc41  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005dbc45  8d8130010000         lea eax, [ecx + 0x130]
// 005dbc4b  8b8934010000         mov ecx, dword ptr [ecx + 0x134]
// 005dbc51  50                   push eax
// 005dbc52  e829b5f8ff           call 0x567180
// 005dbc57  5f                   pop edi
// 005dbc58  5d                   pop ebp
// 005dbc59  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 005dbc5d  5e                   pop esi
// 005dbc5e  5b                   pop ebx
// 005dbc5f  64890d00000000       mov dword ptr fs:[0], ecx
// 005dbc66  83c418               add esp, 0x18
// 005dbc69  c20400               ret 4

// from server: 78% by colin
// roc 2008-06 005dbad0  unit: RBX::VPartInstance::?$FilteredSelection  size: 412 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005dbad0
//
// 005dbad0  6aff                 push -1
// 005dbad2  6868917d00           push 0x7d9168
// 005dbad7  64a100000000         mov eax, dword ptr fs:[0]
// 005dbadd  50                   push eax
// 005dbade  64892500000000       mov dword ptr fs:[0], esp
// 005dbae5  83ec0c               sub esp, 0xc
// 005dbae8  53                   push ebx
// 005dbae9  56                   push esi
// 005dbaea  8b742424             mov esi, dword ptr [esp + 0x24]
// 005dbaee  8bd9                 mov ebx, ecx
// 005dbaf0  56                   push esi
// 005dbaf1  895c240c             mov dword ptr [esp + 0xc], ebx
// 005dbaf5  e8c6f1f7ff           call 0x55acc0
// 005dbafa  83bb3401000000       cmp dword ptr [ebx + 0x134], 0
// 005dbb01  0f8552010000         jne 0x5dbc59
// 005dbb07  8b4608               mov eax, dword ptr [esi + 8]
// 005dbb0a  50                   push eax
// 005dbb0b  e8a061e4ff           call 0x421cb0
// 005dbb10  50                   push eax
// 005dbb11  8d4c2414             lea ecx, [esp + 0x14]
// 005dbb15  51                   push ecx
// 005dbb16  e825cf0300           call 0x618a40
// 005dbb1b  83c40c               add esp, 0xc
// 005dbb1e  8b10                 mov edx, dword ptr [eax]
// 005dbb20  83c004               add eax, 4
// 005dbb23  50                   push eax
// 005dbb24  8d8b38010000         lea ecx, [ebx + 0x138]
// 005dbb2a  c744242000000000     mov dword ptr [esp + 0x20], 0
// 005dbb32  899334010000         mov dword ptr [ebx + 0x134], edx
// 005dbb38  e8736ae2ff           call 0x4025b0
// 005dbb3d  8b442410             mov eax, dword ptr [esp + 0x10]
// 005dbb41  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 005dbb49  85c0                 test eax, eax
// 005dbb4b  742c                 je 0x5dbb79
// 005dbb4d  8bf0                 mov esi, eax
// 005dbb4f  83c004               add eax, 4
// 005dbb52  83c9ff               or ecx, 0xffffffff
// 005dbb55  f00fc108             lock xadd dword ptr [eax], ecx
// 005dbb59  751e                 jne 0x5dbb79
// 005dbb5b  8b16                 mov edx, dword ptr [esi]
// 005dbb5d  8b4204               mov eax, dword ptr [edx + 4]
// 005dbb60  8bce                 mov ecx, esi
// 005dbb62  ffd0                 call eax
// 005dbb64  8d4e08               lea ecx, [esi + 8]
// 005dbb67  83caff               or edx, 0xffffffff
// 005dbb6a  f00fc111             lock xadd dword ptr [ecx], edx
// 005dbb6e  7509                 jne 0x5dbb79
// 005dbb70  8b06                 mov eax, dword ptr [esi]
// 005dbb72  8b5008               mov edx, dword ptr [eax + 8]
// 005dbb75  8bce                 mov ecx, esi
// 005dbb77  ffd2                 call edx
// 005dbb79  8b8334010000         mov eax, dword ptr [ebx + 0x134]
// 005dbb7f  85c0                 test eax, eax
// 005dbb81  0f84d2000000         je 0x5dbc59
// 005dbb87  8bb054010000         mov esi, dword ptr [eax + 0x154]
// 005dbb8d  55                   push ebp
// 005dbb8e  57                   push edi
// 005dbb8f  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 005dbb92  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 005dbb95  7606                 jbe 0x5dbb9d
// 005dbb97  ff1590288000         call dword ptr [0x802890]
// 005dbb9d  8b2e                 mov ebp, dword ptr [esi]
// 005dbb9f  90                   nop 
// 005dbba0  8b8334010000         mov eax, dword ptr [ebx + 0x134]
// 005dbba6  8bb054010000         mov esi, dword ptr [eax + 0x154]
// 005dbbac  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 005dbbaf  395e0c               cmp dword ptr [esi + 0xc], ebx
// 005dbbb2  7606                 jbe 0x5dbbba
// 005dbbb4  ff1590288000         call dword ptr [0x802890]
// 005dbbba  8b36                 mov esi, dword ptr [esi]
// 005dbbbc  85ed                 test ebp, ebp
// 005dbbbe  7404                 je 0x5dbbc4
// 005dbbc0  3bee                 cmp ebp, esi
// 005dbbc2  740a                 je 0x5dbbce
// 005dbbc4  8b3590288000         mov esi, dword ptr [0x802890]
// 005dbbca  ffd6                 call esi
// 005dbbcc  eb06                 jmp 0x5dbbd4
// 005dbbce  8b3590288000         mov esi, dword ptr [0x802890]
// 005dbbd4  3bfb                 cmp edi, ebx
// 005dbbd6  7469                 je 0x5dbc41
// 005dbbd8  85ed                 test ebp, ebp
// 005dbbda  755b                 jne 0x5dbc37
// 005dbbdc  ffd6                 call esi
// 005dbbde  33c0                 xor eax, eax
// 005dbbe0  3b7810               cmp edi, dword ptr [eax + 0x10]
// 005dbbe3  7202                 jb 0x5dbbe7
// 005dbbe5  ffd6                 call esi
// 005dbbe7  8b07                 mov eax, dword ptr [edi]
// 005dbbe9  6a00                 push 0
// 005dbbeb  6850dd9200           push 0x92dd50
// 005dbbf0  687c909200           push 0x92907c
// 005dbbf5  6a00                 push 0
// 005dbbf7  50                   push eax
// 005dbbf8  e8c95b0c00           call 0x6a17c6
// 005dbbfd  83c414               add esp, 0x14
// 005dbc00  8944242c             mov dword ptr [esp + 0x2c], eax
// 005dbc04  85c0                 test eax, eax
// 005dbc06  7414                 je 0x5dbc1c
// 005dbc08  8d4c242c             lea ecx, [esp + 0x2c]
// 005dbc0c  51                   push ecx
// 005dbc0d  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 005dbc11  81c13c010000         add ecx, 0x13c
// 005dbc17  e88457e4ff           call 0x4213a0
// 005dbc1c  85ed                 test ebp, ebp
// 005dbc1e  751c                 jne 0x5dbc3c
// 005dbc20  ffd6                 call esi
// 005dbc22  33c0                 xor eax, eax
// 005dbc24  3b7810               cmp edi, dword ptr [eax + 0x10]
// 005dbc27  7202                 jb 0x5dbc2b
// 005dbc29  ffd6                 call esi
// 005dbc2b  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 005dbc2f  83c708               add edi, 8
// 005dbc32  e969ffffff           jmp 0x5dbba0
// 005dbc37  8b4500               mov eax, dword ptr [ebp]
// 005dbc3a  eba4                 jmp 0x5dbbe0
// 005dbc3c  8b4500               mov eax, dword ptr [ebp]
// 005dbc3f  ebe3                 jmp 0x5dbc24
// 005dbc41  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005dbc45  8d8130010000         lea eax, [ecx + 0x130]
// 005dbc4b  8b8934010000         mov ecx, dword ptr [ecx + 0x134]
// 005dbc51  50                   push eax
// 005dbc52  e829b5f8ff           call 0x567180
// 005dbc57  5f                   pop edi
// 005dbc58  5d                   pop ebp
// 005dbc59  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 005dbc5d  5e                   pop esi
// 005dbc5e  5b                   pop ebx
// 005dbc5f  64890d00000000       mov dword ptr fs:[0], ecx
// 005dbc66  83c418               add esp, 0x18
// 005dbc69  c20400               ret 4

// from server: 74% by king_originala
// roc 2008-06 005dbad0  unit: RBX::VPartInstance::?$FilteredSelection  size: 412 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005dbad0
//
// 005dbad0  6aff                 push -1
// 005dbad2  6868917d00           push 0x7d9168
// 005dbad7  64a100000000         mov eax, dword ptr fs:[0]
// 005dbadd  50                   push eax
// 005dbade  64892500000000       mov dword ptr fs:[0], esp
// 005dbae5  83ec0c               sub esp, 0xc
// 005dbae8  53                   push ebx
// 005dbae9  56                   push esi
// 005dbaea  8b742424             mov esi, dword ptr [esp + 0x24]
// 005dbaee  8bd9                 mov ebx, ecx
// 005dbaf0  56                   push esi
// 005dbaf1  895c240c             mov dword ptr [esp + 0xc], ebx
// 005dbaf5  e8c6f1f7ff           call 0x55acc0
// 005dbafa  83bb3401000000       cmp dword ptr [ebx + 0x134], 0
// 005dbb01  0f8552010000         jne 0x5dbc59
// 005dbb07  8b4608               mov eax, dword ptr [esi + 8]
// 005dbb0a  50                   push eax
// 005dbb0b  e8a061e4ff           call 0x421cb0
// 005dbb10  50                   push eax
// 005dbb11  8d4c2414             lea ecx, [esp + 0x14]
// 005dbb15  51                   push ecx
// 005dbb16  e825cf0300           call 0x618a40
// 005dbb1b  83c40c               add esp, 0xc
// 005dbb1e  8b10                 mov edx, dword ptr [eax]
// 005dbb20  83c004               add eax, 4
// 005dbb23  50                   push eax
// 005dbb24  8d8b38010000         lea ecx, [ebx + 0x138]
// 005dbb2a  c744242000000000     mov dword ptr [esp + 0x20], 0
// 005dbb32  899334010000         mov dword ptr [ebx + 0x134], edx
// 005dbb38  e8736ae2ff           call 0x4025b0
// 005dbb3d  8b442410             mov eax, dword ptr [esp + 0x10]
// 005dbb41  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 005dbb49  85c0                 test eax, eax
// 005dbb4b  742c                 je 0x5dbb79
// 005dbb4d  8bf0                 mov esi, eax
// 005dbb4f  83c004               add eax, 4
// 005dbb52  83c9ff               or ecx, 0xffffffff
// 005dbb55  f00fc108             lock xadd dword ptr [eax], ecx
// 005dbb59  751e                 jne 0x5dbb79
// 005dbb5b  8b16                 mov edx, dword ptr [esi]
// 005dbb5d  8b4204               mov eax, dword ptr [edx + 4]
// 005dbb60  8bce                 mov ecx, esi
// 005dbb62  ffd0                 call eax
// 005dbb64  8d4e08               lea ecx, [esi + 8]
// 005dbb67  83caff               or edx, 0xffffffff
// 005dbb6a  f00fc111             lock xadd dword ptr [ecx], edx
// 005dbb6e  7509                 jne 0x5dbb79
// 005dbb70  8b06                 mov eax, dword ptr [esi]
// 005dbb72  8b5008               mov edx, dword ptr [eax + 8]
// 005dbb75  8bce                 mov ecx, esi
// 005dbb77  ffd2                 call edx
// 005dbb79  8b8334010000         mov eax, dword ptr [ebx + 0x134]
// 005dbb7f  85c0                 test eax, eax
// 005dbb81  0f84d2000000         je 0x5dbc59
// 005dbb87  8bb054010000         mov esi, dword ptr [eax + 0x154]
// 005dbb8d  55                   push ebp
// 005dbb8e  57                   push edi
// 005dbb8f  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 005dbb92  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 005dbb95  7606                 jbe 0x5dbb9d
// 005dbb97  ff1590288000         call dword ptr [0x802890]
// 005dbb9d  8b2e                 mov ebp, dword ptr [esi]
// 005dbb9f  90                   nop 
// 005dbba0  8b8334010000         mov eax, dword ptr [ebx + 0x134]
// 005dbba6  8bb054010000         mov esi, dword ptr [eax + 0x154]
// 005dbbac  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 005dbbaf  395e0c               cmp dword ptr [esi + 0xc], ebx
// 005dbbb2  7606                 jbe 0x5dbbba
// 005dbbb4  ff1590288000         call dword ptr [0x802890]
// 005dbbba  8b36                 mov esi, dword ptr [esi]
// 005dbbbc  85ed                 test ebp, ebp
// 005dbbbe  7404                 je 0x5dbbc4
// 005dbbc0  3bee                 cmp ebp, esi
// 005dbbc2  740a                 je 0x5dbbce
// 005dbbc4  8b3590288000         mov esi, dword ptr [0x802890]
// 005dbbca  ffd6                 call esi
// 005dbbcc  eb06                 jmp 0x5dbbd4
// 005dbbce  8b3590288000         mov esi, dword ptr [0x802890]
// 005dbbd4  3bfb                 cmp edi, ebx
// 005dbbd6  7469                 je 0x5dbc41
// 005dbbd8  85ed                 test ebp, ebp
// 005dbbda  755b                 jne 0x5dbc37
// 005dbbdc  ffd6                 call esi
// 005dbbde  33c0                 xor eax, eax
// 005dbbe0  3b7810               cmp edi, dword ptr [eax + 0x10]
// 005dbbe3  7202                 jb 0x5dbbe7
// 005dbbe5  ffd6                 call esi
// 005dbbe7  8b07                 mov eax, dword ptr [edi]
// 005dbbe9  6a00                 push 0
// 005dbbeb  6850dd9200           push 0x92dd50
// 005dbbf0  687c909200           push 0x92907c
// 005dbbf5  6a00                 push 0
// 005dbbf7  50                   push eax
// 005dbbf8  e8c95b0c00           call 0x6a17c6
// 005dbbfd  83c414               add esp, 0x14
// 005dbc00  8944242c             mov dword ptr [esp + 0x2c], eax
// 005dbc04  85c0                 test eax, eax
// 005dbc06  7414                 je 0x5dbc1c
// 005dbc08  8d4c242c             lea ecx, [esp + 0x2c]
// 005dbc0c  51                   push ecx
// 005dbc0d  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 005dbc11  81c13c010000         add ecx, 0x13c
// 005dbc17  e88457e4ff           call 0x4213a0
// 005dbc1c  85ed                 test ebp, ebp
// 005dbc1e  751c                 jne 0x5dbc3c
// 005dbc20  ffd6                 call esi
// 005dbc22  33c0                 xor eax, eax
// 005dbc24  3b7810               cmp edi, dword ptr [eax + 0x10]
// 005dbc27  7202                 jb 0x5dbc2b
// 005dbc29  ffd6                 call esi
// 005dbc2b  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 005dbc2f  83c708               add edi, 8
// 005dbc32  e969ffffff           jmp 0x5dbba0
// 005dbc37  8b4500               mov eax, dword ptr [ebp]
// 005dbc3a  eba4                 jmp 0x5dbbe0
// 005dbc3c  8b4500               mov eax, dword ptr [ebp]
// 005dbc3f  ebe3                 jmp 0x5dbc24
// 005dbc41  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005dbc45  8d8130010000         lea eax, [ecx + 0x130]
// 005dbc4b  8b8934010000         mov ecx, dword ptr [ecx + 0x134]
// 005dbc51  50                   push eax
// 005dbc52  e829b5f8ff           call 0x567180
// 005dbc57  5f                   pop edi
// 005dbc58  5d                   pop ebp
// 005dbc59  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 005dbc5d  5e                   pop esi
// 005dbc5e  5b                   pop ebx
// 005dbc5f  64890d00000000       mov dword ptr fs:[0], ecx
// 005dbc66  83c418               add esp, 0x18
// 005dbc69  c20400               ret 4

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

extern "C" __declspec(dllimport) void __cdecl _invalid_parameter_noinfo();

namespace RBX
{
    class Instance
    {
    public:
        virtual ~Instance();
        char padding[0x100];
        Instance* next;
    };

    class ServiceProvider : public Instance
    {
    public:
        ServiceProvider* finish();
    };

    class PartInstance : public Instance
    {
    };
}

RBX::ServiceProvider* __cdecl func_00421cb0(RBX::Instance*);

typedef void (__cdecl* InvalidHandler)();

struct Control
{
    virtual void unused() = 0;
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    volatile long strong;
    volatile long weak;
};

struct Entry
{
    RBX::Instance* pointer;
    Control* control;
};

struct Container;

struct Proxy
{
    Container* container;
};

struct Iterator
{
    Proxy* owner;
    Entry* current;

    RBX::Instance* dereference(InvalidHandler) const;
    void increment(InvalidHandler);
};

struct Container
{
    Proxy* proxy;
    unsigned int unused[2];
    Entry* first;
    Entry* last;

    Iterator begin();
    Iterator end();
};

inline Iterator Container::begin()
{
    Entry* position = first;
    if (position > last)
        _invalid_parameter_noinfo();
    Iterator result;
    result.owner = proxy;
    result.current = position;
    return result;
}

inline Iterator Container::end()
{
    Entry* position = last;
    if (first > position)
        _invalid_parameter_noinfo();
    Iterator result;
    result.owner = proxy;
    result.current = position;
    return result;
}

inline RBX::Instance* Iterator::dereference(InvalidHandler invalid) const
{
    if (!owner)
        invalid();
    Container* container = owner ? owner->container : 0;
    if (current >= container->last)
        invalid();
    return current->pointer;
}

inline void Iterator::increment(InvalidHandler invalid)
{
    if (!owner)
        invalid();
    Container* container = owner ? owner->container : 0;
    if (current >= container->last)
        invalid();
    ++current;
}

struct Selection
{
    char padding[0x154];
    Container* entries;
    void invoke(void*);
};

struct ControlSlot
{
    Control* control;
    void assign(const ControlSlot&);
};

struct SharedSelection
{
    Selection* pointer;
    ControlSlot ownership;

    SharedSelection& operator=(const SharedSelection&);
    ~SharedSelection();
};

inline SharedSelection& SharedSelection::operator=(const SharedSelection& other)
{
    pointer = other.pointer;
    ownership.assign(other.ownership);
    return *this;
}

inline SharedSelection::~SharedSelection()
{
    if (ownership.control)
    {
        Control* saved = ownership.control;
        if (_InterlockedDecrement(&saved->strong) == 0)
        {
            saved->dispose();
            if (_InterlockedDecrement(&saved->weak) == 0)
                saved->destroy();
        }
    }
}

SharedSelection __cdecl sub_618a40(RBX::ServiceProvider*);

struct Output
{
    void append(RBX::PartInstance* const*);
};

struct Argument
{
    unsigned int unused[2];
    RBX::Instance* instance;
};

struct PadBase { char padding[0x130]; };
struct CallbackBase { unsigned int callback; };
struct S : PadBase, CallbackBase
{
    SharedSelection selection;
    Output output;

    void initialize(Argument*);
    void f(Argument*);
};

void S::f(Argument* argument)
{
    initialize(argument);
    if (!selection.pointer)
    {
        selection = sub_618a40(func_00421cb0(argument->instance));
        if (selection.pointer)
        {
            Iterator iterator = selection.pointer->entries->begin();
            for (;;)
            {
                Iterator finish = selection.pointer->entries->end();
                if (!iterator.owner || iterator.owner != finish.owner)
                    _invalid_parameter_noinfo();

                InvalidHandler invalid = _invalid_parameter_noinfo;
                if (iterator.current == finish.current)
                    break;

                RBX::PartInstance* part =
                    dynamic_cast<RBX::PartInstance*>(iterator.dereference(invalid));
                if (part)
                    output.append(&part);
                iterator.increment(invalid);
            }
            selection.pointer->invoke(static_cast<CallbackBase*>(this));
        }
    }
}
