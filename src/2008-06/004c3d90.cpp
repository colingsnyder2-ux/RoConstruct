// from server: 100% by auto
// roc 2008-06 004c3d90  unit: ProfiledRakPeer  size: 758 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004c3d90
//
// 004c3d90  51                   push ecx
// 004c3d91  837c240800           cmp dword ptr [esp + 8], 0
// 004c3d96  53                   push ebx
// 004c3d97  55                   push ebp
// 004c3d98  56                   push esi
// 004c3d99  8bf1                 mov esi, ecx
// 004c3d9b  0fb74608             movzx eax, word ptr [esi + 8]
// 004c3d9f  57                   push edi
// 004c3da0  89442410             mov dword ptr [esp + 0x10], eax
// 004c3da4  0f867d000000         jbe 0x4c3e27
// 004c3daa  0fb7e8               movzx ebp, ax
// 004c3dad  85ed                 test ebp, ebp
// 004c3daf  7632                 jbe 0x4c3de3
// 004c3db1  33ff                 xor edi, edi
// 004c3db3  8bdd                 mov ebx, ebp
// 004c3db5  8b862c020000         mov eax, dword ptr [esi + 0x22c]
// 004c3dbb  03c7                 add eax, edi
// 004c3dbd  803800               cmp byte ptr [eax], 0
// 004c3dc0  7416                 je 0x4c3dd8
// 004c3dc2  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 004c3dc6  8b5008               mov edx, dword ptr [eax + 8]
// 004c3dc9  8b4004               mov eax, dword ptr [eax + 4]
// 004c3dcc  51                   push ecx
// 004c3dcd  6a00                 push 0
// 004c3dcf  52                   push edx
// 004c3dd0  50                   push eax
// 004c3dd1  8bce                 mov ecx, esi
// 004c3dd3  e878e4ffff           call 0x4c2250
// 004c3dd8  81c750080000         add edi, 0x850
// 004c3dde  83eb01               sub ebx, 1
// 004c3de1  75d2                 jne 0x4c3db5
// 004c3de3  e8285b0000           call 0x4c9910
// 004c3de8  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 004c3dec  8bf8                 mov edi, eax
// 004c3dee  85db                 test ebx, ebx
// 004c3df0  7635                 jbe 0x4c3e27
// 004c3df2  33c0                 xor eax, eax
// 004c3df4  85ed                 test ebp, ebp
// 004c3df6  762f                 jbe 0x4c3e27
// 004c3df8  8b8e2c020000         mov ecx, dword ptr [esi + 0x22c]
// 004c3dfe  8bff                 mov edi, edi
// 004c3e00  803900               cmp byte ptr [ecx], 0
// 004c3e03  750d                 jne 0x4c3e12
// 004c3e05  40                   inc eax
// 004c3e06  81c150080000         add ecx, 0x850
// 004c3e0c  3bc5                 cmp eax, ebp
// 004c3e0e  72f0                 jb 0x4c3e00
// 004c3e10  eb15                 jmp 0x4c3e27
// 004c3e12  6a0f                 push 0xf
// 004c3e14  e857030100           call 0x4d4170
// 004c3e19  83c404               add esp, 4
// 004c3e1c  e8ef5a0000           call 0x4c9910
// 004c3e21  2bc7                 sub eax, edi
// 004c3e23  3bc3                 cmp eax, ebx
// 004c3e25  72cb                 jb 0x4c3df2
// 004c3e27  33ff                 xor edi, edi
// 004c3e29  39beac020000         cmp dword ptr [esi + 0x2ac], edi
// 004c3e2f  761a                 jbe 0x4c3e4b
// 004c3e31  8b8ea8020000         mov ecx, dword ptr [esi + 0x2a8]
// 004c3e37  8b0cb9               mov ecx, dword ptr [ecx + edi*4]
// 004c3e3a  8b11                 mov edx, dword ptr [ecx]
// 004c3e3c  8b4218               mov eax, dword ptr [edx + 0x18]
// 004c3e3f  56                   push esi
// 004c3e40  ffd0                 call eax
// 004c3e42  47                   inc edi
// 004c3e43  3bbeac020000         cmp edi, dword ptr [esi + 0x2ac]
// 004c3e49  72e6                 jb 0x4c3e31
// 004c3e4b  8a4e05               mov cl, byte ptr [esi + 5]
// 004c3e4e  84c9                 test cl, cl
// 004c3e50  7415                 je 0x4c3e67
// 004c3e52  c6460401             mov byte ptr [esi + 4], 1
// 004c3e56  6a0f                 push 0xf
// 004c3e58  e813030100           call 0x4d4170
// 004c3e5d  8a5605               mov dl, byte ptr [esi + 5]
// 004c3e60  83c404               add esp, 4
// 004c3e63  84d2                 test dl, dl
// 004c3e65  75eb                 jne 0x4c3e52
// 004c3e67  0fb76c2410           movzx ebp, word ptr [esp + 0x10]
// 004c3e6c  85ed                 test ebp, ebp
// 004c3e6e  7636                 jbe 0x4c3ea6
// 004c3e70  33ff                 xor edi, edi
// 004c3e72  eb0c                 jmp 0x4c3e80
// 004c3e74  8da42400000000       lea esp, [esp]
// 004c3e7b  eb03                 jmp 0x4c3e80
// 004c3e7d  8d4900               lea ecx, [ecx]
// 004c3e80  8b862c020000         mov eax, dword ptr [esi + 0x22c]
// 004c3e86  c6040700             mov byte ptr [edi + eax], 0
// 004c3e8a  8b8e2c020000         mov ecx, dword ptr [esi + 0x22c]
// 004c3e90  6a00                 push 0
// 004c3e92  8d4c3918             lea ecx, [ecx + edi + 0x18]
// 004c3e96  e8d5fd0000           call 0x4d3c70
// 004c3e9b  81c750080000         add edi, 0x850
// 004c3ea1  83ed01               sub ebp, 1
// 004c3ea4  75da                 jne 0x4c3e80
// 004c3ea6  8b8638020000         mov eax, dword ptr [esi + 0x238]
// 004c3eac  85c0                 test eax, eax
// 004c3eae  742e                 je 0x4c3ede
// 004c3eb0  3d00020000           cmp eax, 0x200
// 004c3eb5  761d                 jbe 0x4c3ed4
// 004c3eb7  8b9630020000         mov edx, dword ptr [esi + 0x230]
// 004c3ebd  52                   push edx
// 004c3ebe  e8b7c71d00           call 0x6a067a
// 004c3ec3  83c404               add esp, 4
// 004c3ec6  33c0                 xor eax, eax
// 004c3ec8  898638020000         mov dword ptr [esi + 0x238], eax
// 004c3ece  898630020000         mov dword ptr [esi + 0x230], eax
// 004c3ed4  c7863402000000000000 mov dword ptr [esi + 0x234], 0
// 004c3ede  33c0                 xor eax, eax
// 004c3ee0  8dbed8080000         lea edi, [esi + 0x8d8]
// 004c3ee6  66894608             mov word ptr [esi + 8], ax
// 004c3eea  8b07                 mov eax, dword ptr [edi]
// 004c3eec  3b470c               cmp eax, dword ptr [edi + 0xc]
// 004c3eef  744a                 je 0x4c3f3b
// 004c3ef1  8a4804               mov cl, byte ptr [eax + 4]
// 004c3ef4  84c9                 test cl, cl
// 004c3ef6  7443                 je 0x4c3f3b
// 004c3ef8  8b07                 mov eax, dword ptr [edi]
// 004c3efa  8b5008               mov edx, dword ptr [eax + 8]
// 004c3efd  8917                 mov dword ptr [edi], edx
// 004c3eff  85c0                 test eax, eax
// 004c3f01  7438                 je 0x4c3f3b
// 004c3f03  8b16                 mov edx, dword ptr [esi]
// 004c3f05  8b00                 mov eax, dword ptr [eax]
// 004c3f07  8b5240               mov edx, dword ptr [edx + 0x40]
// 004c3f0a  50                   push eax
// 004c3f0b  8bce                 mov ecx, esi
// 004c3f0d  ffd2                 call edx
// 004c3f0f  ff4710               inc dword ptr [edi + 0x10]
// 004c3f12  8b4708               mov eax, dword ptr [edi + 8]
// 004c3f15  c6400400             mov byte ptr [eax + 4], 0
// 004c3f19  8b4f08               mov ecx, dword ptr [edi + 8]
// 004c3f1c  8b5108               mov edx, dword ptr [ecx + 8]
// 004c3f1f  895708               mov dword ptr [edi + 8], edx
// 004c3f22  8b07                 mov eax, dword ptr [edi]
// 004c3f24  3b470c               cmp eax, dword ptr [edi + 0xc]
// 004c3f27  7412                 je 0x4c3f3b
// 004c3f29  8a4004               mov al, byte ptr [eax + 4]
// 004c3f2c  84c0                 test al, al
// 004c3f2e  740b                 je 0x4c3f3b
// 004c3f30  8b07                 mov eax, dword ptr [edi]
// 004c3f32  8b4808               mov ecx, dword ptr [eax + 8]
// 004c3f35  890f                 mov dword ptr [edi], ecx
// 004c3f37  85c0                 test eax, eax
// 004c3f39  75c8                 jne 0x4c3f03
// 004c3f3b  8bcf                 mov ecx, edi
// 004c3f3d  e87e86ffff           call 0x4bc5c0
// 004c3f42  33db                 xor ebx, ebx
// 004c3f44  33ff                 xor edi, edi
// 004c3f46  eb08                 jmp 0x4c3f50
// 004c3f48  8da42400000000       lea esp, [esp]
// 004c3f4f  90                   nop 
// 004c3f50  8b96f4080000         mov edx, dword ptr [esi + 0x8f4]
// 004c3f56  8b8ef8080000         mov ecx, dword ptr [esi + 0x8f8]
// 004c3f5c  3bd1                 cmp edx, ecx
// 004c3f5e  7706                 ja 0x4c3f66
// 004c3f60  2bca                 sub ecx, edx
// 004c3f62  8bc1                 mov eax, ecx
// 004c3f64  eb0a                 jmp 0x4c3f70
// 004c3f66  8b86fc080000         mov eax, dword ptr [esi + 0x8fc]
// 004c3f6c  2bc2                 sub eax, edx
// 004c3f6e  03c1                 add eax, ecx
// 004c3f70  3bf8                 cmp edi, eax
// 004c3f72  7343                 jae 0x4c3fb7
// 004c3f74  8b8efc080000         mov ecx, dword ptr [esi + 0x8fc]
// 004c3f7a  8bc2                 mov eax, edx
// 004c3f7c  8d1438               lea edx, [eax + edi]
// 004c3f7f  3bd1                 cmp edx, ecx
// 004c3f81  721c                 jb 0x4c3f9f
// 004c3f83  8b96f0080000         mov edx, dword ptr [esi + 0x8f0]
// 004c3f89  2bc1                 sub eax, ecx
// 004c3f8b  03c7                 add eax, edi
// 004c3f8d  8d0482               lea eax, [edx + eax*4]
// 004c3f90  8b16                 mov edx, dword ptr [esi]
// 004c3f92  8b00                 mov eax, dword ptr [eax]
// 004c3f94  8b5240               mov edx, dword ptr [edx + 0x40]
// 004c3f97  50                   push eax
// 004c3f98  8bce                 mov ecx, esi
// 004c3f9a  ffd2                 call edx
// 004c3f9c  47                   inc edi
// 004c3f9d  ebb1                 jmp 0x4c3f50
// 004c3f9f  8b86f0080000         mov eax, dword ptr [esi + 0x8f0]
// 004c3fa5  8d0490               lea eax, [eax + edx*4]
// 004c3fa8  8b16                 mov edx, dword ptr [esi]
// 004c3faa  8b00                 mov eax, dword ptr [eax]
// 004c3fac  8b5240               mov edx, dword ptr [edx + 0x40]
// 004c3faf  50                   push eax
// 004c3fb0  8bce                 mov ecx, esi
// 004c3fb2  ffd2                 call edx
// 004c3fb4  47                   inc edi
// 004c3fb5  eb99                 jmp 0x4c3f50
// 004c3fb7  8b86fc080000         mov eax, dword ptr [esi + 0x8fc]
// 004c3fbd  3bc3                 cmp eax, ebx
// 004c3fbf  7426                 je 0x4c3fe7
// 004c3fc1  83f820               cmp eax, 0x20
// 004c3fc4  7615                 jbe 0x4c3fdb
// 004c3fc6  8b86f0080000         mov eax, dword ptr [esi + 0x8f0]
// 004c3fcc  50                   push eax
// 004c3fcd  e8a8c61d00           call 0x6a067a
// 004c3fd2  83c404               add esp, 4
// 004c3fd5  899efc080000         mov dword ptr [esi + 0x8fc], ebx
// 004c3fdb  899ef4080000         mov dword ptr [esi + 0x8f4], ebx
// 004c3fe1  899ef8080000         mov dword ptr [esi + 0x8f8], ebx
// 004c3fe7  33ff                 xor edi, edi
// 004c3fe9  c6862907000000       mov byte ptr [esi + 0x729], 0
// 004c3ff0  399e18070000         cmp dword ptr [esi + 0x718], ebx
// 004c3ff6  761d                 jbe 0x4c4015
// 004c3ff8  8b2dc02e8000         mov ebp, dword ptr [0x802ec0]
// 004c3ffe  8bff                 mov edi, edi
// 004c4000  8b8e14070000         mov ecx, dword ptr [esi + 0x714]
// 004c4006  8b14b9               mov edx, dword ptr [ecx + edi*4]
// 004c4009  52                   push edx
// 004c400a  ffd5                 call ebp
// 004c400c  47                   inc edi
// 004c400d  3bbe18070000         cmp edi, dword ptr [esi + 0x718]
// 004c4013  72eb                 jb 0x4c4000
// 004c4015  8b8614070000         mov eax, dword ptr [esi + 0x714]
// 004c401b  3bc3                 cmp eax, ebx
// 004c401d  7409                 je 0x4c4028
// 004c401f  50                   push eax
// 004c4020  e855c61d00           call 0x6a067a
// 004c4025  83c404               add esp, 4
// 004c4028  8bce                 mov ecx, esi
// 004c402a  899e14070000         mov dword ptr [esi + 0x714], ebx
// 004c4030  899e18070000         mov dword ptr [esi + 0x718], ebx
// 004c4036  e8e596ffff           call 0x4bd720
// 004c403b  8bce                 mov ecx, esi
// 004c403d  899e5c020000         mov dword ptr [esi + 0x25c], ebx
// 004c4043  899e58020000         mov dword ptr [esi + 0x258], ebx
// 004c4049  e82297ffff           call 0x4bd770
// 004c404e  8b862c020000         mov eax, dword ptr [esi + 0x22c]
// 004c4054  899e2c020000         mov dword ptr [esi + 0x22c], ebx
// 004c405a  3bc3                 cmp eax, ebx
// 004c405c  7420                 je 0x4c407e
// 004c405e  8b48fc               mov ecx, dword ptr [eax - 4]
// 004c4061  8d70fc               lea esi, [eax - 4]
// 004c4064  6820b64b00           push 0x4bb620
// 004c4069  51                   push ecx
// 004c406a  6850080000           push 0x850
// 004c406f  50                   push eax
// 004c4070  e8e6d51d00           call 0x6a165b
// 004c4075  56                   push esi
// 004c4076  e8ffc51d00           call 0x6a067a
// 004c407b  83c404               add esp, 4
// 004c407e  5f                   pop edi
// 004c407f  5e                   pop esi
// 004c4080  5d                   pop ebp
// 004c4081  5b                   pop ebx
// 004c4082  59                   pop ecx
// 004c4083  c20800               ret 8
// library openrbx-raknet/RakPeer.cpp (function ?Shutdown@RakPeer@@UAEXIE@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
