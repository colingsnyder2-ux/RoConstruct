// from server: 100% by auto
// roc 2008-06 004be8b0  unit: ProfiledRakPeer  size: 711 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004be8b0
//
// 004be8b0  55                   push ebp
// 004be8b1  8bec                 mov ebp, esp
// 004be8b3  83ec18               sub esp, 0x18
// 004be8b6  8b450c               mov eax, dword ptr [ebp + 0xc]
// 004be8b9  8b08                 mov ecx, dword ptr [eax]
// 004be8bb  53                   push ebx
// 004be8bc  8b580c               mov ebx, dword ptr [eax + 0xc]
// 004be8bf  56                   push esi
// 004be8c0  8b7008               mov esi, dword ptr [eax + 8]
// 004be8c3  57                   push edi
// 004be8c4  8b7804               mov edi, dword ptr [eax + 4]
// 004be8c7  8b4508               mov eax, dword ptr [ebp + 8]
// 004be8ca  8b10                 mov edx, dword ptr [eax]
// 004be8cc  894de8               mov dword ptr [ebp - 0x18], ecx
// 004be8cf  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 004be8d2  8911                 mov dword ptr [ecx], edx
// 004be8d4  8b5004               mov edx, dword ptr [eax + 4]
// 004be8d7  895104               mov dword ptr [ecx + 4], edx
// 004be8da  8b5008               mov edx, dword ptr [eax + 8]
// 004be8dd  895108               mov dword ptr [ecx + 8], edx
// 004be8e0  8b400c               mov eax, dword ptr [eax + 0xc]
// 004be8e3  8b5510               mov edx, dword ptr [ebp + 0x10]
// 004be8e6  89410c               mov dword ptr [ecx + 0xc], eax
// 004be8e9  33c0                 xor eax, eax
// 004be8eb  8902                 mov dword ptr [edx], eax
// 004be8ed  894204               mov dword ptr [edx + 4], eax
// 004be8f0  894208               mov dword ptr [edx + 8], eax
// 004be8f3  897dec               mov dword ptr [ebp - 0x14], edi
// 004be8f6  8975f0               mov dword ptr [ebp - 0x10], esi
// 004be8f9  895df4               mov dword ptr [ebp - 0xc], ebx
// 004be8fc  89420c               mov dword ptr [edx + 0xc], eax
// 004be8ff  c7450c01000000       mov dword ptr [ebp + 0xc], 1
// 004be906  85db                 test ebx, ebx
// 004be908  0f8819010000         js 0x4bea27
// 004be90e  8d55e8               lea edx, [ebp - 0x18]
// 004be911  52                   push edx
// 004be912  51                   push ecx
// 004be913  e818ddffff           call 0x4bc630
// 004be918  83c408               add esp, 8
// 004be91b  84c0                 test al, al
// 004be91d  0f8401010000         je 0x4bea24
// 004be923  b803000000           mov eax, 3
// 004be928  eb06                 jmp 0x4be930
// 004be92a  8d9b00000000         lea ebx, [ebx]
// 004be930  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 004be933  833c8100             cmp dword ptr [ecx + eax*4], 0
// 004be937  7505                 jne 0x4be93e
// 004be939  83e801               sub eax, 1
// 004be93c  79f2                 jns 0x4be930
// 004be93e  8bc8                 mov ecx, eax
// 004be940  85c0                 test eax, eax
// 004be942  7c31                 jl 0x4be975
// 004be944  837c8de800           cmp dword ptr [ebp + ecx*4 - 0x18], 0
// 004be949  7505                 jne 0x4be950
// 004be94b  83e901               sub ecx, 1
// 004be94e  79f4                 jns 0x4be944
// 004be950  3bc1                 cmp eax, ecx
// 004be952  7421                 je 0x4be975
// 004be954  2bc1                 sub eax, ecx
// 004be956  c1e005               shl eax, 5
// 004be959  8bf0                 mov esi, eax
// 004be95b  8d55e8               lea edx, [ebp - 0x18]
// 004be95e  56                   push esi
// 004be95f  52                   push edx
// 004be960  e88be2ffff           call 0x4bcbf0
// 004be965  8b5df4               mov ebx, dword ptr [ebp - 0xc]
// 004be968  8b7dec               mov edi, dword ptr [ebp - 0x14]
// 004be96b  83c408               add esp, 8
// 004be96e  46                   inc esi
// 004be96f  89750c               mov dword ptr [ebp + 0xc], esi
// 004be972  8b75f0               mov esi, dword ptr [ebp - 0x10]
// 004be975  85db                 test ebx, ebx
// 004be977  7857                 js 0x4be9d0
// 004be979  8da42400000000       lea esp, [esp]
// 004be980  b803000000           mov eax, 3
// 004be985  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 004be988  8b0c81               mov ecx, dword ptr [ecx + eax*4]
// 004be98b  8b5485e8             mov edx, dword ptr [ebp + eax*4 - 0x18]
// 004be98f  3bca                 cmp ecx, edx
// 004be991  7709                 ja 0x4be99c
// 004be993  723b                 jb 0x4be9d0
// 004be995  83e801               sub eax, 1
// 004be998  79eb                 jns 0x4be985
// 004be99a  eb34                 jmp 0x4be9d0
// 004be99c  8b4de8               mov ecx, dword ptr [ebp - 0x18]
// 004be99f  ff450c               inc dword ptr [ebp + 0xc]
// 004be9a2  8bc1                 mov eax, ecx
// 004be9a4  03c9                 add ecx, ecx
// 004be9a6  894de8               mov dword ptr [ebp - 0x18], ecx
// 004be9a9  c1e81f               shr eax, 0x1f
// 004be9ac  8bcf                 mov ecx, edi
// 004be9ae  03ff                 add edi, edi
// 004be9b0  0bf8                 or edi, eax
// 004be9b2  8bc6                 mov eax, esi
// 004be9b4  c1e81f               shr eax, 0x1f
// 004be9b7  03db                 add ebx, ebx
// 004be9b9  c1e91f               shr ecx, 0x1f
// 004be9bc  03f6                 add esi, esi
// 004be9be  0bd8                 or ebx, eax
// 004be9c0  0bf1                 or esi, ecx
// 004be9c2  897dec               mov dword ptr [ebp - 0x14], edi
// 004be9c5  8975f0               mov dword ptr [ebp - 0x10], esi
// 004be9c8  895df4               mov dword ptr [ebp - 0xc], ebx
// 004be9cb  85db                 test ebx, ebx
// 004be9cd  79b1                 jns 0x4be980
// 004be9cf  90                   nop 
// 004be9d0  b803000000           mov eax, 3
// 004be9d5  8b5514               mov edx, dword ptr [ebp + 0x14]
// 004be9d8  8b0c82               mov ecx, dword ptr [edx + eax*4]
// 004be9db  8b5485e8             mov edx, dword ptr [ebp + eax*4 - 0x18]
// 004be9df  3bd1                 cmp edx, ecx
// 004be9e1  7710                 ja 0x4be9f3
// 004be9e3  0f8291000000         jb 0x4bea7a
// 004be9e9  83e801               sub eax, 1
// 004be9ec  79e7                 jns 0x4be9d5
// 004be9ee  e987000000           jmp 0x4bea7a
// 004be9f3  8bc3                 mov eax, ebx
// 004be9f5  c1e01f               shl eax, 0x1f
// 004be9f8  8bce                 mov ecx, esi
// 004be9fa  d1ee                 shr esi, 1
// 004be9fc  0bf0                 or esi, eax
// 004be9fe  c1e11f               shl ecx, 0x1f
// 004bea01  8bc7                 mov eax, edi
// 004bea03  d1ef                 shr edi, 1
// 004bea05  0bf9                 or edi, ecx
// 004bea07  8b4de8               mov ecx, dword ptr [ebp - 0x18]
// 004bea0a  c1e01f               shl eax, 0x1f
// 004bea0d  d1e9                 shr ecx, 1
// 004bea0f  d1eb                 shr ebx, 1
// 004bea11  0bc8                 or ecx, eax
// 004bea13  ff4d0c               dec dword ptr [ebp + 0xc]
// 004bea16  895df4               mov dword ptr [ebp - 0xc], ebx
// 004bea19  8975f0               mov dword ptr [ebp - 0x10], esi
// 004bea1c  897dec               mov dword ptr [ebp - 0x14], edi
// 004bea1f  894de8               mov dword ptr [ebp - 0x18], ecx
// 004bea22  ebac                 jmp 0x4be9d0
// 004bea24  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 004bea27  b803000000           mov eax, 3
// 004bea2c  eb05                 jmp 0x4bea33
// 004bea2e  8bff                 mov edi, edi
// 004bea30  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 004bea33  8b0c81               mov ecx, dword ptr [ecx + eax*4]
// 004bea36  8b5485e8             mov edx, dword ptr [ebp + eax*4 - 0x18]
// 004bea3a  3bd1                 cmp edx, ecx
// 004bea3c  7709                 ja 0x4bea47
// 004bea3e  723a                 jb 0x4bea7a
// 004bea40  83e801               sub eax, 1
// 004bea43  79eb                 jns 0x4bea30
// 004bea45  eb33                 jmp 0x4bea7a
// 004bea47  8b55e8               mov edx, dword ptr [ebp - 0x18]
// 004bea4a  8bc3                 mov eax, ebx
// 004bea4c  c1e01f               shl eax, 0x1f
// 004bea4f  8bce                 mov ecx, esi
// 004bea51  d1ee                 shr esi, 1
// 004bea53  0bf0                 or esi, eax
// 004bea55  8bc7                 mov eax, edi
// 004bea57  c1e11f               shl ecx, 0x1f
// 004bea5a  d1ef                 shr edi, 1
// 004bea5c  d1eb                 shr ebx, 1
// 004bea5e  0bf9                 or edi, ecx
// 004bea60  c1e01f               shl eax, 0x1f
// 004bea63  d1ea                 shr edx, 1
// 004bea65  0bd0                 or edx, eax
// 004bea67  895df4               mov dword ptr [ebp - 0xc], ebx
// 004bea6a  8975f0               mov dword ptr [ebp - 0x10], esi
// 004bea6d  897dec               mov dword ptr [ebp - 0x14], edi
// 004bea70  8955e8               mov dword ptr [ebp - 0x18], edx
// 004bea73  c7450c00000000       mov dword ptr [ebp + 0xc], 0
// 004bea7a  837d0c00             cmp dword ptr [ebp + 0xc], 0
// 004bea7e  c7450800000000       mov dword ptr [ebp + 8], 0
// 004bea85  0f84d5000000         je 0x4beb60
// 004bea8b  eb03                 jmp 0x4bea90
// 004bea8d  8d4900               lea ecx, [ecx]
// 004bea90  b801000000           mov eax, 1
// 004bea95  29450c               sub dword ptr [ebp + 0xc], eax
// 004bea98  014508               add dword ptr [ebp + 8], eax
// 004bea9b  b803000000           mov eax, 3
// 004beaa0  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 004beaa3  8b0c81               mov ecx, dword ptr [ecx + eax*4]
// 004beaa6  8b5485e8             mov edx, dword ptr [ebp + eax*4 - 0x18]
// 004beaaa  3bd1                 cmp edx, ecx
// 004beaac  777c                 ja 0x4beb2a
// 004beaae  7205                 jb 0x4beab5
// 004beab0  83e801               sub eax, 1
// 004beab3  79eb                 jns 0x4beaa0
// 004beab5  8d55e8               lea edx, [ebp - 0x18]
// 004beab8  8955f8               mov dword ptr [ebp - 8], edx
// 004beabb  c745fc00000000       mov dword ptr [ebp - 4], 0
// 004beac2  8b75f8               mov esi, dword ptr [ebp - 8]
// 004beac5  8b7d14               mov edi, dword ptr [ebp + 0x14]
// 004beac8  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 004beacb  8b06                 mov eax, dword ptr [esi]
// 004beacd  33d2                 xor edx, edx
// 004beacf  2907                 sub dword ptr [edi], eax
// 004bead1  8b4604               mov eax, dword ptr [esi + 4]
// 004bead4  194704               sbb dword ptr [edi + 4], eax
// 004bead7  8b4608               mov eax, dword ptr [esi + 8]
// 004beada  194708               sbb dword ptr [edi + 8], eax
// 004beadd  8b460c               mov eax, dword ptr [esi + 0xc]
// 004beae0  19470c               sbb dword ptr [edi + 0xc], eax
// 004beae3  e322                 jecxz 0x4beb07
// 004beae5  42                   inc edx
// 004beae6  42                   inc edx
// 004beae7  8b04d6               mov eax, dword ptr [esi + edx*8]
// 004beaea  1904d7               sbb dword ptr [edi + edx*8], eax
// 004beaed  8b44d604             mov eax, dword ptr [esi + edx*8 + 4]
// 004beaf1  1944d704             sbb dword ptr [edi + edx*8 + 4], eax
// 004beaf5  8b44d608             mov eax, dword ptr [esi + edx*8 + 8]
// 004beaf9  1944d708             sbb dword ptr [edi + edx*8 + 8], eax
// 004beafd  8b44d60c             mov eax, dword ptr [esi + edx*8 + 0xc]
// 004beb01  1944d70c             sbb dword ptr [edi + edx*8 + 0xc], eax
// 004beb05  e2de                 loop 0x4beae5
// 004beb07  8b4508               mov eax, dword ptr [ebp + 8]
// 004beb0a  8b7510               mov esi, dword ptr [ebp + 0x10]
// 004beb0d  50                   push eax
// 004beb0e  56                   push esi
// 004beb0f  e8dce0ffff           call 0x4bcbf0
// 004beb14  8b5df4               mov ebx, dword ptr [ebp - 0xc]
// 004beb17  8b7dec               mov edi, dword ptr [ebp - 0x14]
// 004beb1a  83c408               add esp, 8
// 004beb1d  830e01               or dword ptr [esi], 1
// 004beb20  8b75f0               mov esi, dword ptr [ebp - 0x10]
// 004beb23  c7450800000000       mov dword ptr [ebp + 8], 0
// 004beb2a  8bc3                 mov eax, ebx
// 004beb2c  c1e01f               shl eax, 0x1f
// 004beb2f  8bce                 mov ecx, esi
// 004beb31  d1ee                 shr esi, 1
// 004beb33  0bf0                 or esi, eax
// 004beb35  c1e11f               shl ecx, 0x1f
// 004beb38  8bc7                 mov eax, edi
// 004beb3a  d1ef                 shr edi, 1
// 004beb3c  0bf9                 or edi, ecx
// 004beb3e  8b4de8               mov ecx, dword ptr [ebp - 0x18]
// 004beb41  c1e01f               shl eax, 0x1f
// 004beb44  d1e9                 shr ecx, 1
// 004beb46  d1eb                 shr ebx, 1
// 004beb48  0bc8                 or ecx, eax
// 004beb4a  837d0c00             cmp dword ptr [ebp + 0xc], 0
// 004beb4e  895df4               mov dword ptr [ebp - 0xc], ebx
// 004beb51  8975f0               mov dword ptr [ebp - 0x10], esi
// 004beb54  897dec               mov dword ptr [ebp - 0x14], edi
// 004beb57  894de8               mov dword ptr [ebp - 0x18], ecx
// 004beb5a  0f8530ffffff         jne 0x4bea90
// 004beb60  8b5508               mov edx, dword ptr [ebp + 8]
// 004beb63  8b4510               mov eax, dword ptr [ebp + 0x10]
// 004beb66  52                   push edx
// 004beb67  50                   push eax
// 004beb68  e883e0ffff           call 0x4bcbf0
// 004beb6d  83c408               add esp, 8
// 004beb70  5f                   pop edi
// 004beb71  5e                   pop esi
// 004beb72  5b                   pop ebx
// 004beb73  8be5                 mov esp, ebp
// 004beb75  5d                   pop ebp
// 004beb76  c3                   ret 
// library openrbx-raknet/RakPeer.cpp (function ??$udivide@$$BY03I@big@@YAXAAY03I000@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
