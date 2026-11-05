// from server: 100% by EspClaude
// from server: 94% by colin
// roc 2008-06 0049bf90  unit: RBX::Network::VPlayers::?$BoundFuncDesc  size: 1198 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0049bf90
//
// 0049bf90  55                   push ebp
// 0049bf91  8d6c24c0             lea ebp, [esp - 0x40]
// 0049bf95  83ec40               sub esp, 0x40
// 0049bf98  6aff                 push -1
// 0049bf9a  68f4717c00           push 0x7c71f4
// 0049bf9f  64a100000000         mov eax, dword ptr fs:[0]
// 0049bfa5  50                   push eax
// 0049bfa6  64892500000000       mov dword ptr fs:[0], esp
// 0049bfad  81ec20010000         sub esp, 0x120
// 0049bfb3  53                   push ebx
// 0049bfb4  56                   push esi
// 0049bfb5  57                   push edi
// 0049bfb6  8965f0               mov dword ptr [ebp - 0x10], esp
// 0049bfb9  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0049bfc0  8d4db8               lea ecx, [ebp - 0x48]
// 0049bfc3  c645fc02             mov byte ptr [ebp - 4], 2
// 0049bfc7  ff1560248000         call dword ptr [0x802460]
// 0049bfcd  8d4dd4               lea ecx, [ebp - 0x2c]
// 0049bfd0  c645fc03             mov byte ptr [ebp - 4], 3
// 0049bfd4  e897c7ffff           call 0x498770
// 0049bfd9  8b7d48               mov edi, dword ptr [ebp + 0x48]
// 0049bfdc  83c720               add edi, 0x20
// 0049bfdf  8bcf                 mov ecx, edi
// 0049bfe1  c645fc04             mov byte ptr [ebp - 4], 4
// 0049bfe5  897d38               mov dword ptr [ebp + 0x38], edi
// 0049bfe8  c6453c00             mov byte ptr [ebp + 0x3c], 0
// 0049bfec  e8ef8c0f00           call 0x594ce0
// 0049bff1  c6453c01             mov byte ptr [ebp + 0x3c], 1
// 0049bff5  8b4548               mov eax, dword ptr [ebp + 0x48]
// 0049bff8  83781c00             cmp dword ptr [eax + 0x1c], 0
// 0049bffc  c645fc05             mov byte ptr [ebp - 4], 5
// 0049c000  7572                 jne 0x49c074
// 0049c002  8bcf                 mov ecx, edi
// 0049c004  c645fc04             mov byte ptr [ebp - 4], 4
// 0049c008  e8f38c0f00           call 0x594d00
// 0049c00d  8d4db0               lea ecx, [ebp - 0x50]
// 0049c010  c645fc02             mov byte ptr [ebp - 4], 2
// 0049c014  e857d3ffff           call 0x499370
// 0049c019  8b754c               mov esi, dword ptr [ebp + 0x4c]
// 0049c01c  c645fc00             mov byte ptr [ebp - 4], 0
// 0049c020  85f6                 test esi, esi
// 0049c022  742a                 je 0x49c04e
// 0049c024  8d4604               lea eax, [esi + 4]
// 0049c027  83c9ff               or ecx, 0xffffffff
// 0049c02a  f00fc108             lock xadd dword ptr [eax], ecx
// 0049c02e  751e                 jne 0x49c04e
// 0049c030  8b16                 mov edx, dword ptr [esi]
// 0049c032  8b4204               mov eax, dword ptr [edx + 4]
// 0049c035  8bce                 mov ecx, esi
// 0049c037  ffd0                 call eax
// 0049c039  8d4e08               lea ecx, [esi + 8]
// 0049c03c  83caff               or edx, 0xffffffff
// 0049c03f  f00fc111             lock xadd dword ptr [ecx], edx
// 0049c043  7509                 jne 0x49c04e
// 0049c045  8b06                 mov eax, dword ptr [esi]
// 0049c047  8b5008               mov edx, dword ptr [eax + 8]
// 0049c04a  8bce                 mov ecx, esi
// 0049c04c  ffd2                 call edx
// 0049c04e  8d4d50               lea ecx, [ebp + 0x50]
// 0049c051  c745fcffffffff       mov dword ptr [ebp - 4], 0xffffffff
// 0049c058  ff1568248000         call dword ptr [0x802468]
// 0049c05e  33c0                 xor eax, eax
// 0049c060  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0049c063  64890d00000000       mov dword ptr fs:[0], ecx
// 0049c06a  5f                   pop edi
// 0049c06b  5e                   pop esi
// 0049c06c  5b                   pop ebx
// 0049c06d  83c540               add ebp, 0x40
// 0049c070  8be5                 mov esp, ebp
// 0049c072  5d                   pop ebp
// 0049c073  c3                   ret 
// 0049c074  8b7018               mov esi, dword ptr [eax + 0x18]
// 0049c077  8bd8                 mov ebx, eax
// 0049c079  8b401c               mov eax, dword ptr [eax + 0x1c]
// 0049c07c  03c6                 add eax, esi
// 0049c07e  3bf0                 cmp esi, eax
// 0049c080  7606                 jbe 0x49c088
// 0049c082  ff1590288000         call dword ptr [0x802890]
// 0049c088  8b0b                 mov ecx, dword ptr [ebx]
// 0049c08a  894d30               mov dword ptr [ebp + 0x30], ecx
// 0049c08d  8d4d30               lea ecx, [ebp + 0x30]
// 0049c090  897534               mov dword ptr [ebp + 0x34], esi
// 0049c093  e8889fffff           call 0x496020
// 0049c098  50                   push eax
// 0049c099  8d4db0               lea ecx, [ebp - 0x50]
// 0049c09c  e88fe7ffff           call 0x49a830
// 0049c0a1  8bcf                 mov ecx, edi
// 0049c0a3  c645fc04             mov byte ptr [ebp - 4], 4
// 0049c0a7  e8548c0f00           call 0x594d00
// 0049c0ac  6a01                 push 1
// 0049c0ae  6a03                 push 3
// 0049c0b0  8d8dd4feffff         lea ecx, [ebp - 0x12c]
// 0049c0b6  ff1528248000         call dword ptr [0x802428]
// 0049c0bc  8d95dcfeffff         lea edx, [ebp - 0x124]
// 0049c0c2  52                   push edx
// 0049c0c3  8d8d6cffffff         lea ecx, [ebp - 0x94]
// 0049c0c9  c645fc06             mov byte ptr [ebp - 4], 6
// 0049c0cd  e81e3f0f00           call 0x58fff0
// 0049c0d2  c7856cffffff1cea8000 mov dword ptr [ebp - 0x94], 0x80ea1c
// 0049c0dc  6aff                 push -1
// 0049c0de  68f00c8100           push 0x810cf0
// 0049c0e3  c645fc07             mov byte ptr [ebp - 4], 7
// 0049c0e7  e8a47e0b00           call 0x553f90
// 0049c0ec  33db                 xor ebx, ebx
// 0049c0ee  83c408               add esp, 8
// 0049c0f1  895d08               mov dword ptr [ebp + 8], ebx
// 0049c0f4  895d0c               mov dword ptr [ebp + 0xc], ebx
// 0049c0f7  895d10               mov dword ptr [ebp + 0x10], ebx
// 0049c0fa  894518               mov dword ptr [ebp + 0x18], eax
// 0049c0fd  895d1c               mov dword ptr [ebp + 0x1c], ebx
// 0049c100  895d28               mov dword ptr [ebp + 0x28], ebx
// 0049c103  895d2c               mov dword ptr [ebp + 0x2c], ebx
// 0049c106  8b75b0               mov esi, dword ptr [ebp - 0x50]
// 0049c109  6aff                 push -1
// 0049c10b  6808278200           push 0x822708
// 0049c110  c645fc08             mov byte ptr [ebp - 4], 8
// 0049c114  e8777e0b00           call 0x553f90
// 0049c119  83c408               add esp, 8
// 0049c11c  6a18                 push 0x18
// 0049c11e  8bf8                 mov edi, eax
// 0049c120  e8fb472000           call 0x6a0920
// 0049c125  83c404               add esp, 4
// 0049c128  3bc3                 cmp eax, ebx
// 0049c12a  7411                 je 0x49c13d
// 0049c12c  8918                 mov dword ptr [eax], ebx
// 0049c12e  897808               mov dword ptr [eax + 8], edi
// 0049c131  c7400c05000000       mov dword ptr [eax + 0xc], 5
// 0049c138  897010               mov dword ptr [eax + 0x10], esi
// 0049c13b  eb02                 jmp 0x49c13f
// 0049c13d  33c0                 xor eax, eax
// 0049c13f  8b4d2c               mov ecx, dword ptr [ebp + 0x2c]
// 0049c142  3bcb                 cmp ecx, ebx
// 0049c144  7505                 jne 0x49c14b
// 0049c146  894528               mov dword ptr [ebp + 0x28], eax
// 0049c149  eb02                 jmp 0x49c14d
// 0049c14b  8901                 mov dword ptr [ecx], eax
// 0049c14d  6a28                 push 0x28
// 0049c14f  89452c               mov dword ptr [ebp + 0x2c], eax
// 0049c152  e8c9472000           call 0x6a0920
// 0049c157  8bf0                 mov esi, eax
// 0049c159  83c404               add esp, 4
// 0049c15c  897534               mov dword ptr [ebp + 0x34], esi
// 0049c15f  c645fc09             mov byte ptr [ebp - 4], 9
// 0049c163  3bf3                 cmp esi, ebx
// 0049c165  7433                 je 0x49c19a
// 0049c167  83ec1c               sub esp, 0x1c
// 0049c16a  8d45b8               lea eax, [ebp - 0x48]
// 0049c16d  8bcc                 mov ecx, esp
// 0049c16f  89653c               mov dword ptr [ebp + 0x3c], esp
// 0049c172  50                   push eax
// 0049c173  ff155c248000         call dword ptr [0x80245c]
// 0049c179  6aff                 push -1
// 0049c17b  68402a8200           push 0x822a40
// 0049c180  c645fc0a             mov byte ptr [ebp - 4], 0xa
// 0049c184  e8077e0b00           call 0x553f90
// 0049c189  83c408               add esp, 8
// 0049c18c  50                   push eax
// 0049c18d  8bce                 mov ecx, esi
// 0049c18f  c645fc09             mov byte ptr [ebp - 4], 9
// 0049c193  e8089fffff           call 0x4960a0
// 0049c198  eb02                 jmp 0x49c19c
// 0049c19a  33c0                 xor eax, eax
// 0049c19c  8b4d10               mov ecx, dword ptr [ebp + 0x10]
// 0049c19f  c645fc08             mov byte ptr [ebp - 4], 8
// 0049c1a3  3bcb                 cmp ecx, ebx
// 0049c1a5  7505                 jne 0x49c1ac
// 0049c1a7  89450c               mov dword ptr [ebp + 0xc], eax
// 0049c1aa  eb02                 jmp 0x49c1ae
// 0049c1ac  8901                 mov dword ptr [ecx], eax
// 0049c1ae  6a28                 push 0x28
// 0049c1b0  894510               mov dword ptr [ebp + 0x10], eax
// 0049c1b3  e868472000           call 0x6a0920
// 0049c1b8  8bf0                 mov esi, eax
// 0049c1ba  83c404               add esp, 4
// 0049c1bd  89753c               mov dword ptr [ebp + 0x3c], esi
// 0049c1c0  c645fc0b             mov byte ptr [ebp - 4], 0xb
// 0049c1c4  3bf3                 cmp esi, ebx
// 0049c1c6  7425                 je 0x49c1ed
// 0049c1c8  6aff                 push -1
// 0049c1ca  68342a8200           push 0x822a34
// 0049c1cf  e8bc7d0b00           call 0x553f90
// 0049c1d4  891e                 mov dword ptr [esi], ebx
// 0049c1d6  895e04               mov dword ptr [esi + 4], ebx
// 0049c1d9  895e08               mov dword ptr [esi + 8], ebx
// 0049c1dc  894610               mov dword ptr [esi + 0x10], eax
// 0049c1df  895e14               mov dword ptr [esi + 0x14], ebx
// 0049c1e2  83c408               add esp, 8
// 0049c1e5  895e20               mov dword ptr [esi + 0x20], ebx
// 0049c1e8  895e24               mov dword ptr [esi + 0x24], ebx
// 0049c1eb  eb02                 jmp 0x49c1ef
// 0049c1ed  33f6                 xor esi, esi
// 0049c1ef  8b4510               mov eax, dword ptr [ebp + 0x10]
// 0049c1f2  c645fc08             mov byte ptr [ebp - 4], 8
// 0049c1f6  3bc3                 cmp eax, ebx
// 0049c1f8  7505                 jne 0x49c1ff
// 0049c1fa  89750c               mov dword ptr [ebp + 0xc], esi
// 0049c1fd  eb02                 jmp 0x49c201
// 0049c1ff  8930                 mov dword ptr [eax], esi
// 0049c201  8b4de8               mov ecx, dword ptr [ebp - 0x18]
// 0049c204  8b55d4               mov edx, dword ptr [ebp - 0x2c]
// 0049c207  56                   push esi
// 0049c208  b820764900           mov eax, 0x497620
// 0049c20d  50                   push eax
// 0049c20e  51                   push ecx
// 0049c20f  52                   push edx
// 0049c210  897510               mov dword ptr [ebp + 0x10], esi
// 0049c213  8b39                 mov edi, dword ptr [ecx]
// 0049c215  57                   push edi
// 0049c216  52                   push edx
// 0049c217  8d4d38               lea ecx, [ebp + 0x38]
// 0049c21a  51                   push ecx
// 0049c21b  e8c0d0ffff           call 0x4992e0
// 0049c220  83c41c               add esp, 0x1c
// 0049c223  8d5508               lea edx, [ebp + 8]
// 0049c226  52                   push edx
// 0049c227  8d8d6cffffff         lea ecx, [ebp - 0x94]
// 0049c22d  e8de250f00           call 0x58e810
// 0049c232  8d8ddcfeffff         lea ecx, [ebp - 0x124]
// 0049c238  ff15bc238000         call dword ptr [0x8023bc]
// 0049c23e  8d4d08               lea ecx, [ebp + 8]
// 0049c241  c645fc07             mov byte ptr [ebp - 4], 7
// 0049c245  e82678f7ff           call 0x413a70
// 0049c24a  8d8d70ffffff         lea ecx, [ebp - 0x90]
// 0049c250  c645fc06             mov byte ptr [ebp - 4], 6
// 0049c254  e87784f7ff           call 0x4146d0
// 0049c259  8d4d94               lea ecx, [ebp - 0x6c]
// 0049c25c  ff1560248000         call dword ptr [0x802460]
// 0049c262  8d4550               lea eax, [ebp + 0x50]
// 0049c265  50                   push eax
// 0049c266  8d8d5cffffff         lea ecx, [ebp - 0xa4]
// 0049c26c  c645fc0c             mov byte ptr [ebp - 4], 0xc
// 0049c270  e83b12f8ff           call 0x41d4b0
// 0049c275  8d4d94               lea ecx, [ebp - 0x6c]
// 0049c278  51                   push ecx
// 0049c279  53                   push ebx
// 0049c27a  8d95d4feffff         lea edx, [ebp - 0x12c]
// 0049c280  52                   push edx
// 0049c281  8bc8                 mov ecx, eax
// 0049c283  c645fc0d             mov byte ptr [ebp - 4], 0xd
// 0049c287  e8b4d70c00           call 0x569a40
// 0049c28c  8d8d5cffffff         lea ecx, [ebp - 0xa4]
// 0049c292  c645fc0c             mov byte ptr [ebp - 4], 0xc
// 0049c296  e885331400           call 0x5df620
// 0049c29b  8d4538               lea eax, [ebp + 0x38]
// 0049c29e  50                   push eax
// 0049c29f  e87cd30c00           call 0x569620
// 0049c2a4  83c404               add esp, 4
// 0049c2a7  837d6810             cmp dword ptr [ebp + 0x68], 0x10
// 0049c2ab  8b4d54               mov ecx, dword ptr [ebp + 0x54]
// 0049c2ae  c645fc0e             mov byte ptr [ebp - 4], 0xe
// 0049c2b2  7303                 jae 0x49c2b7
// 0049c2b4  8d4d54               lea ecx, [ebp + 0x54]
// 0049c2b7  8b00                 mov eax, dword ptr [eax]
// 0049c2b9  51                   push ecx
// 0049c2ba  68182a8200           push 0x822a18
// 0049c2bf  6a01                 push 1
// 0049c2c1  50                   push eax
// 0049c2c2  e8d9d00c00           call 0x5693a0
// 0049c2c7  8b753c               mov esi, dword ptr [ebp + 0x3c]
// 0049c2ca  83c410               add esp, 0x10
// 0049c2cd  c645fc0c             mov byte ptr [ebp - 4], 0xc
// 0049c2d1  3bf3                 cmp esi, ebx
// 0049c2d3  742a                 je 0x49c2ff
// 0049c2d5  8d4e04               lea ecx, [esi + 4]
// 0049c2d8  83caff               or edx, 0xffffffff
// 0049c2db  f00fc111             lock xadd dword ptr [ecx], edx
// 0049c2df  751e                 jne 0x49c2ff
// 0049c2e1  8b06                 mov eax, dword ptr [esi]
// 0049c2e3  8b5004               mov edx, dword ptr [eax + 4]
// 0049c2e6  8bce                 mov ecx, esi
// 0049c2e8  ffd2                 call edx
// 0049c2ea  8d4608               lea eax, [esi + 8]
// 0049c2ed  83c9ff               or ecx, 0xffffffff
// 0049c2f0  f00fc108             lock xadd dword ptr [eax], ecx
// 0049c2f4  7509                 jne 0x49c2ff
// 0049c2f6  8b16                 mov edx, dword ptr [esi]
// 0049c2f8  8b4208               mov eax, dword ptr [edx + 8]
// 0049c2fb  8bce                 mov ecx, esi
// 0049c2fd  ffd0                 call eax
// 0049c2ff  8d4d94               lea ecx, [ebp - 0x6c]
// 0049c302  c645fc06             mov byte ptr [ebp - 4], 6
// 0049c306  ff1568248000         call dword ptr [0x802468]
// 0049c30c  8d8dd4feffff         lea ecx, [ebp - 0x12c]
// 0049c312  c645fc04             mov byte ptr [ebp - 4], 4
// 0049c316  ff152c248000         call dword ptr [0x80242c]
// 0049c31c  8d4db0               lea ecx, [ebp - 0x50]
// 0049c31f  c645fc02             mov byte ptr [ebp - 4], 2
// 0049c323  e848d0ffff           call 0x499370
// 0049c328  c745fc01000000       mov dword ptr [ebp - 4], 1
// 0049c32f  8b4d48               mov ecx, dword ptr [ebp + 0x48]
// 0049c332  83c120               add ecx, 0x20
// 0049c335  894d38               mov dword ptr [ebp + 0x38], ecx
// 0049c338  e8a3890f00           call 0x594ce0
// 0049c33d  c6453c01             mov byte ptr [ebp + 0x3c], 1
// 0049c341  8b4548               mov eax, dword ptr [ebp + 0x48]
// 0049c344  83781c00             cmp dword ptr [eax + 0x1c], 0
// 0049c348  8d581c               lea ebx, [eax + 0x1c]
// 0049c34b  c645fc11             mov byte ptr [ebp - 4], 0x11
// 0049c34f  8bf8                 mov edi, eax
// 0049c351  742b                 je 0x49c37e
// 0049c353  8b4818               mov ecx, dword ptr [eax + 0x18]
// 0049c356  8b5010               mov edx, dword ptr [eax + 0x10]
// 0049c359  8b0c8a               mov ecx, dword ptr [edx + ecx*4]
// 0049c35c  8d7018               lea esi, [eax + 0x18]
// 0049c35f  e80cd0ffff           call 0x499370
// 0049c364  ff06                 inc dword ptr [esi]
// 0049c366  8b06                 mov eax, dword ptr [esi]
// 0049c368  394714               cmp dword ptr [edi + 0x14], eax
// 0049c36b  7706                 ja 0x49c373
// 0049c36d  c70600000000         mov dword ptr [esi], 0
// 0049c373  8303ff               add dword ptr [ebx], -1
// 0049c376  7506                 jne 0x49c37e
// 0049c378  c70600000000         mov dword ptr [esi], 0
// 0049c37e  8b4d38               mov ecx, dword ptr [ebp + 0x38]
// 0049c381  c645fc01             mov byte ptr [ebp - 4], 1
// 0049c385  e876890f00           call 0x594d00
// 0049c38a  8b754c               mov esi, dword ptr [ebp + 0x4c]
// 0049c38d  c645fc00             mov byte ptr [ebp - 4], 0
// 0049c391  85f6                 test esi, esi
// 0049c393  742a                 je 0x49c3bf
// 0049c395  8d4604               lea eax, [esi + 4]
// 0049c398  83c9ff               or ecx, 0xffffffff
// 0049c39b  f00fc108             lock xadd dword ptr [eax], ecx
// 0049c39f  751e                 jne 0x49c3bf
// 0049c3a1  8b16                 mov edx, dword ptr [esi]
// 0049c3a3  8b4204               mov eax, dword ptr [edx + 4]
// 0049c3a6  8bce                 mov ecx, esi
// 0049c3a8  ffd0                 call eax
// 0049c3aa  8d4e08               lea ecx, [esi + 8]
// 0049c3ad  83caff               or edx, 0xffffffff
// 0049c3b0  f00fc111             lock xadd dword ptr [ecx], edx
// 0049c3b4  7509                 jne 0x49c3bf
// 0049c3b6  8b06                 mov eax, dword ptr [esi]
// 0049c3b8  8b5008               mov edx, dword ptr [eax + 8]
// 0049c3bb  8bce                 mov ecx, esi
// 0049c3bd  ffd2                 call edx
// 0049c3bf  8d4d50               lea ecx, [ebp + 0x50]
// 0049c3c2  c745fcffffffff       mov dword ptr [ebp - 4], 0xffffffff
// 0049c3c9  ff1568248000         call dword ptr [0x802468]
// 0049c3cf  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0049c3d2  5f                   pop edi
// 0049c3d3  5e                   pop esi
// 0049c3d4  b801000000           mov eax, 1
// 0049c3d9  64890d00000000       mov dword ptr fs:[0], ecx
// 0049c3e0  5b                   pop ebx
// 0049c3e1  83c540               add ebp, 0x40
// 0049c3e4  8be5                 mov esp, ebp
// 0049c3e6  5d                   pop ebp
// 0049c3e7  c3                   ret 
// 0049c3e8  8d4d38               lea ecx, [ebp + 0x38]
// 0049c3eb  51                   push ecx
// 0049c3ec  e82fd20c00           call 0x569620
// 0049c3f1  83c404               add esp, 4
// 0049c3f4  8b7d54               mov edi, dword ptr [ebp + 0x54]
// 0049c3f7  b910000000           mov ecx, 0x10
// 0049c3fc  884dfc               mov byte ptr [ebp - 4], cl
// 0049c3ff  394d68               cmp dword ptr [ebp + 0x68], ecx
// 0049c402  7303                 jae 0x49c407
// 0049c404  8d7d54               lea edi, [ebp + 0x54]
// 0049c407  8b4d04               mov ecx, dword ptr [ebp + 4]
// 0049c40a  8b11                 mov edx, dword ptr [ecx]
// 0049c40c  8b30                 mov esi, dword ptr [eax]
// 0049c40e  8b4204               mov eax, dword ptr [edx + 4]
// 0049c411  ffd0                 call eax
// 0049c413  50                   push eax
// 0049c414  57                   push edi
// 0049c415  68f0298200           push 0x8229f0
// 0049c41a  6a02                 push 2
// 0049c41c  56                   push esi
// 0049c41d  e87ecf0c00           call 0x5693a0
// 0049c422  83c414               add esp, 0x14
// 0049c425  8d4d38               lea ecx, [ebp + 0x38]
// 0049c428  c645fc0f             mov byte ptr [ebp - 4], 0xf
// 0049c42c  e82f421600           call 0x600660
// 0049c431  c745fc01000000       mov dword ptr [ebp - 4], 1
// 0049c438  b82fc34900           mov eax, 0x49c32f
// 0049c43d  c3                   ret 

// from server: 90% by king_originala
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// Complete1112-byte cdecl worker: shared data8 and URL string28 by value.
// Native Players.h, openrbx XML double-valued union, Http.h and Boost1.34 contracts.
// All sizes/offsets below are compile-asserted against measured target transport.
// The empty test addresses the queue through (&d->queue)[1-lock.m_locked] (index folds to 0 only after
// CSE), so front()'s checked-iterator ctor reloads _Mysize as in the target (no barrier needed).
// This is a codegen analog; class descriptions are supported by native source and target.
#include <intrin.h>
#include <string>
#include <list>
#include <queue>
#include <map>
#include <sstream>
#include <exception>
#include <stddef.h>
namespace boost {namespace detail {
struct sp_counted_base {
 virtual ~sp_counted_base(){}virtual void dispose()=0;virtual void destroy(){delete this;}
 long use_count_,weak_count_;
 void add_ref_copy(){_InterlockedIncrement(&use_count_);}
 void weak_release(){if(_InterlockedDecrement(&weak_count_)==0)destroy();}
 void release(){if(_InterlockedDecrement(&use_count_)==0){dispose();weak_release();}}
};
struct shared_count {sp_counted_base*pi_;shared_count():pi_(0){}shared_count(const shared_count&r):pi_(r.pi_){if(pi_)pi_->add_ref_copy();}~shared_count(){if(pi_)pi_->release();}};
}
template<class T>struct shared_ptr {T*px;detail::shared_count pn;shared_ptr():px(0),pn(){}shared_ptr(const shared_ptr&r):px(r.px),pn(r.pn){}T*get()const{return px;}T*operator->()const{return px;}};
class thread_exception:public std::exception {int m_sys_err;protected:thread_exception();thread_exception(int);public:~thread_exception()throw();int native_error()const;};
class lock_error:public thread_exception {public:lock_error();lock_error(int);~lock_error()throw();virtual const char*what()const throw();};
struct mutex {
 void*m_mutex;bool m_critical_section;
 void do_lock();void do_unlock();
 struct scoped_lock {
 mutex&m_mutex;bool m_locked;
 explicit scoped_lock(mutex&m,bool initially_locked=true):m_mutex(m),m_locked(false){if(initially_locked)lock();}
 ~scoped_lock(){if(m_locked)unlock();}
 void lock(){if(m_locked)throw lock_error();m_mutex.do_lock();m_locked=true;}
 void unlock(){if(!m_locked)throw lock_error();m_mutex.do_unlock();m_locked=false;}
 };
};
}
namespace RBX {
struct Name {static const Name&declare(const char*,int=-1);};
struct Instance;
struct InstanceHandle {boost::shared_ptr<Instance>target;bool operator<(const InstanceHandle&)const;};
template<class T>struct Sibling {T*next;Sibling():next(0){}void setNextSibling(T*n){next=n;}};
template<class T>struct Parent {
 T*first;T*last;Parent():first(0),last(0){}
 void pushBackChild(T*child){if(!last)first=child;else last->setNextSibling(child);last=child;}
};
struct Http {const std::string url;std::string additionalHeaders;Http(const std::string&);~Http();void post(std::istream&,bool,std::string&);};
struct StandardOut {static boost::shared_ptr<StandardOut>singleton();};
void __cdecl printMessage(StandardOut*,int,const char*,...);
}
struct XmlElement;
struct XmlAttribute;
struct XmlNameValuePair {
 enum ValueType{NONE,NAME,STRING,CONTENTID,BOOL,INT,UINT,FLOAT,HANDLE,DOUBLE};
 const RBX::Name&tag;mutable ValueType valueType;
 union {std::string*stringValue;const RBX::Name*nameValue;void*handleValue;bool boolValue;int intValue;unsigned uintValue;float floatValue;double doubleValue;};
 XmlNameValuePair(const RBX::Name&t):tag(t),valueType(NONE){}
 XmlNameValuePair(const RBX::Name&t,int v):tag(t),valueType(INT),intValue(v){}
 XmlNameValuePair(const RBX::Name&,const std::string&);
 ~XmlNameValuePair(){clearValue();}
 void clearValue()const;
};
struct XmlAttribute:RBX::Sibling<XmlAttribute>,XmlNameValuePair {XmlAttribute(const RBX::Name&t,int v):XmlNameValuePair(t,v){}};
struct XmlElement:RBX::Sibling<XmlElement>,RBX::Parent<XmlElement>,XmlNameValuePair {
 RBX::Parent<XmlAttribute>attributes;
 explicit XmlElement(const RBX::Name&t):XmlNameValuePair(t){}
 XmlElement(const RBX::Name&,std::string);
 ~XmlElement();
 void addAttribute(const RBX::Name&t,int v){attributes.pushBackChild(new XmlAttribute(t,v));}
 XmlElement*addChild(XmlElement*e){pushBackChild(e);return e;}
};
struct XmlWriter {
 std::map<RBX::InstanceHandle,int>handles;std::ostream&stream;
 explicit XmlWriter(std::ostream&);
 virtual void serialize(const XmlElement*)=0;
};
struct TextXmlWriter:XmlWriter {
 TextXmlWriter(std::ostream&s):XmlWriter(s){}
 virtual void serialize(const XmlElement*);
 virtual void serializeNode(const XmlElement*,int);
};
namespace RBX {namespace Network {
struct AbuseReport {
 struct Message {int userID;std::string text;};
 int submitterID,allegedAbuserID;std::string comment;std::list<Message>messages;
 ~AbuseReport();AbuseReport&operator=(const AbuseReport&);
};
void __cdecl appendMessage(const AbuseReport::Message&,XmlElement*);
struct MessageAppender {void(__cdecl*function)(const AbuseReport::Message&,XmlElement*);XmlElement*container;MessageAppender(void(__cdecl*f)(const AbuseReport::Message&,XmlElement*),XmlElement*p):function(f),container(p){} };
MessageAppender __cdecl forEachMessages(std::list<AbuseReport::Message>::iterator,std::list<AbuseReport::Message>::iterator,MessageAppender);
struct AbuseReporter {
 struct data {std::queue<AbuseReport>queue;boost::mutex requestSync;};
 static int processRequests(boost::shared_ptr<data>,std::string);
};
int AbuseReporter::processRequests(boost::shared_ptr<data>d,std::string url){
 try {
  AbuseReport report;
  {
   boost::mutex::scoped_lock lock(d->requestSync);
   if((&d->queue)[1-lock.m_locked].empty())return 0;
   report=d->queue.front();
  }
  std::stringstream stream;
  {
   TextXmlWriter writer(stream);
   XmlElement root(RBX::Name::declare("report"));
   root.addAttribute(RBX::Name::declare("userID"),report.submitterID);
   root.addChild(new XmlElement(RBX::Name::declare("comment"),report.comment));
   XmlElement*messages=root.addChild(new XmlElement(RBX::Name::declare("messages")));
   MessageAppender appender(appendMessage,messages);
   forEachMessages(report.messages.begin(),report.messages.end(),appender);
   writer.serialize(&root);
   stream.flush();
  }
  std::string response;
  RBX::Http(url).post(stream,false,response);
  RBX::printMessage(RBX::StandardOut::singleton().get(),1,"Posted abuse report to %s",url.c_str());
 }catch(const std::exception&e){
  RBX::printMessage(RBX::StandardOut::singleton().get(),2,"Unable to post abuse report to %s. %s",url.c_str(),e.what());
 }
 {
  boost::mutex::scoped_lock lock(d->requestSync);
  d->queue.pop();
 }
 return 1;
}
}}
typedef char report_size[sizeof(RBX::Network::AbuseReport)==64?1:-1];
typedef char queue_size[sizeof(std::queue<RBX::Network::AbuseReport>)==32?1:-1];
typedef char attribute_size[sizeof(XmlAttribute)==24?1:-1];
typedef char element_size[sizeof(XmlElement)==40?1:-1];
typedef char writer_size[sizeof(TextXmlWriter)==40?1:-1];
typedef char http_size[sizeof(RBX::Http)==56?1:-1];
typedef char data_mutex_offset[offsetof(RBX::Network::AbuseReporter::data,requestSync)==32?1:-1];
