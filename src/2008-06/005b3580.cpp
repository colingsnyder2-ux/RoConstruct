// from server: 100% by auto
// roc 2008-06 005b3580  unit: RBX::VHat::?$FactoryProduct  size: 725 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005b3580
//
// 005b3580  64a100000000         mov eax, dword ptr fs:[0]
// 005b3586  6aff                 push -1
// 005b3588  6842e87d00           push 0x7de842
// 005b358d  50                   push eax
// 005b358e  64892500000000       mov dword ptr fs:[0], esp
// 005b3595  8b442418             mov eax, dword ptr [esp + 0x18]
// 005b3599  83ec48               sub esp, 0x48
// 005b359c  80782d00             cmp byte ptr [eax + 0x2d], 0
// 005b35a0  55                   push ebp
// 005b35a1  8be9                 mov ebp, ecx
// 005b35a3  7459                 je 0x5b35fe
// 005b35a5  6870b28000           push 0x80b270
// 005b35aa  8d4c240c             lea ecx, [esp + 0xc]
// 005b35ae  ff1558248000         call dword ptr [0x802458]
// 005b35b4  8d4c2424             lea ecx, [esp + 0x24]
// 005b35b8  c744245400000000     mov dword ptr [esp + 0x54], 0
// 005b35c0  ff1598288000         call dword ptr [0x802898]
// 005b35c6  8d442408             lea eax, [esp + 8]
// 005b35ca  50                   push eax
// 005b35cb  8d4c2434             lea ecx, [esp + 0x34]
// 005b35cf  c644245801           mov byte ptr [esp + 0x58], 1
// 005b35d4  c744242810b18000     mov dword ptr [esp + 0x28], 0x80b110
// 005b35dc  ff155c248000         call dword ptr [0x80245c]
// 005b35e2  683c0c8d00           push 0x8d0c3c
// 005b35e7  8d4c2428             lea ecx, [esp + 0x28]
// 005b35eb  51                   push ecx
// 005b35ec  c644245c00           mov byte ptr [esp + 0x5c], 0
// 005b35f1  c744242c28b18000     mov dword ptr [esp + 0x2c], 0x80b128
// 005b35f9  e88edf0e00           call 0x6a158c
// 005b35fe  53                   push ebx
// 005b35ff  56                   push esi
// 005b3600  8bd8                 mov ebx, eax
// 005b3602  57                   push edi
// 005b3603  8d4c246c             lea ecx, [esp + 0x6c]
// 005b3607  895c2410             mov dword ptr [esp + 0x10], ebx
// 005b360b  e8909b0d00           call 0x68d1a0
// 005b3610  8b0b                 mov ecx, dword ptr [ebx]
// 005b3612  80792d00             cmp byte ptr [ecx + 0x2d], 0
// 005b3616  7405                 je 0x5b361d
// 005b3618  8b7b08               mov edi, dword ptr [ebx + 8]
// 005b361b  eb1b                 jmp 0x5b3638
// 005b361d  8b5308               mov edx, dword ptr [ebx + 8]
// 005b3620  807a2d00             cmp byte ptr [edx + 0x2d], 0
// 005b3624  7404                 je 0x5b362a
// 005b3626  8bf9                 mov edi, ecx
// 005b3628  eb0e                 jmp 0x5b3638
// 005b362a  8b442470             mov eax, dword ptr [esp + 0x70]
// 005b362e  8b7808               mov edi, dword ptr [eax + 8]
// 005b3631  8d5008               lea edx, [eax + 8]
// 005b3634  3bc3                 cmp eax, ebx
// 005b3636  756b                 jne 0x5b36a3
// 005b3638  807f2d00             cmp byte ptr [edi + 0x2d], 0
// 005b363c  8b7304               mov esi, dword ptr [ebx + 4]
// 005b363f  7503                 jne 0x5b3644
// 005b3641  897704               mov dword ptr [edi + 4], esi
// 005b3644  8b4518               mov eax, dword ptr [ebp + 0x18]
// 005b3647  395804               cmp dword ptr [eax + 4], ebx
// 005b364a  7505                 jne 0x5b3651
// 005b364c  897804               mov dword ptr [eax + 4], edi
// 005b364f  eb0b                 jmp 0x5b365c
// 005b3651  391e                 cmp dword ptr [esi], ebx
// 005b3653  7504                 jne 0x5b3659
// 005b3655  893e                 mov dword ptr [esi], edi
// 005b3657  eb03                 jmp 0x5b365c
// 005b3659  897e08               mov dword ptr [esi + 8], edi
// 005b365c  8b5d18               mov ebx, dword ptr [ebp + 0x18]
// 005b365f  8b03                 mov eax, dword ptr [ebx]
// 005b3661  3b442410             cmp eax, dword ptr [esp + 0x10]
// 005b3665  7515                 jne 0x5b367c
// 005b3667  807f2d00             cmp byte ptr [edi + 0x2d], 0
// 005b366b  7404                 je 0x5b3671
// 005b366d  8bc6                 mov eax, esi
// 005b366f  eb09                 jmp 0x5b367a
// 005b3671  57                   push edi
// 005b3672  e8099a0d00           call 0x68d080
// 005b3677  83c404               add esp, 4
// 005b367a  8903                 mov dword ptr [ebx], eax
// 005b367c  8b5d18               mov ebx, dword ptr [ebp + 0x18]
// 005b367f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005b3683  394b08               cmp dword ptr [ebx + 8], ecx
// 005b3686  7577                 jne 0x5b36ff
// 005b3688  807f2d00             cmp byte ptr [edi + 0x2d], 0
// 005b368c  7407                 je 0x5b3695
// 005b368e  8bc6                 mov eax, esi
// 005b3690  894308               mov dword ptr [ebx + 8], eax
// 005b3693  eb6a                 jmp 0x5b36ff
// 005b3695  57                   push edi
// 005b3696  e8c5990d00           call 0x68d060
// 005b369b  83c404               add esp, 4
// 005b369e  894308               mov dword ptr [ebx + 8], eax
// 005b36a1  eb5c                 jmp 0x5b36ff
// 005b36a3  894104               mov dword ptr [ecx + 4], eax
// 005b36a6  8b0b                 mov ecx, dword ptr [ebx]
// 005b36a8  8908                 mov dword ptr [eax], ecx
// 005b36aa  3b4308               cmp eax, dword ptr [ebx + 8]
// 005b36ad  7504                 jne 0x5b36b3
// 005b36af  8bf0                 mov esi, eax
// 005b36b1  eb19                 jmp 0x5b36cc
// 005b36b3  807f2d00             cmp byte ptr [edi + 0x2d], 0
// 005b36b7  8b7004               mov esi, dword ptr [eax + 4]
// 005b36ba  7503                 jne 0x5b36bf
// 005b36bc  897704               mov dword ptr [edi + 4], esi
// 005b36bf  893e                 mov dword ptr [esi], edi
// 005b36c1  8b4b08               mov ecx, dword ptr [ebx + 8]
// 005b36c4  890a                 mov dword ptr [edx], ecx
// 005b36c6  8b5308               mov edx, dword ptr [ebx + 8]
// 005b36c9  894204               mov dword ptr [edx + 4], eax
// 005b36cc  8b4d18               mov ecx, dword ptr [ebp + 0x18]
// 005b36cf  395904               cmp dword ptr [ecx + 4], ebx
// 005b36d2  7505                 jne 0x5b36d9
// 005b36d4  894104               mov dword ptr [ecx + 4], eax
// 005b36d7  eb0e                 jmp 0x5b36e7
// 005b36d9  8b4b04               mov ecx, dword ptr [ebx + 4]
// 005b36dc  3919                 cmp dword ptr [ecx], ebx
// 005b36de  7504                 jne 0x5b36e4
// 005b36e0  8901                 mov dword ptr [ecx], eax
// 005b36e2  eb03                 jmp 0x5b36e7
// 005b36e4  894108               mov dword ptr [ecx + 8], eax
// 005b36e7  8b4b04               mov ecx, dword ptr [ebx + 4]
// 005b36ea  894804               mov dword ptr [eax + 4], ecx
// 005b36ed  8d4b2c               lea ecx, [ebx + 0x2c]
// 005b36f0  83c02c               add eax, 0x2c
// 005b36f3  3bc1                 cmp eax, ecx
// 005b36f5  7408                 je 0x5b36ff
// 005b36f7  8a19                 mov bl, byte ptr [ecx]
// 005b36f9  8a10                 mov dl, byte ptr [eax]
// 005b36fb  8818                 mov byte ptr [eax], bl
// 005b36fd  8811                 mov byte ptr [ecx], dl
// 005b36ff  8b542410             mov edx, dword ptr [esp + 0x10]
// 005b3703  b301                 mov bl, 1
// 005b3705  385a2c               cmp byte ptr [edx + 0x2c], bl
// 005b3708  0f85fd000000         jne 0x5b380b
// 005b370e  8b4518               mov eax, dword ptr [ebp + 0x18]
// 005b3711  3b7804               cmp edi, dword ptr [eax + 4]
// 005b3714  0f84ee000000         je 0x5b3808
// 005b371a  8d9b00000000         lea ebx, [ebx]
// 005b3720  385f2c               cmp byte ptr [edi + 0x2c], bl
// 005b3723  0f85df000000         jne 0x5b3808
// 005b3729  8b06                 mov eax, dword ptr [esi]
// 005b372b  3bf8                 cmp edi, eax
// 005b372d  7565                 jne 0x5b3794
// 005b372f  8b4608               mov eax, dword ptr [esi + 8]
// 005b3732  80782c00             cmp byte ptr [eax + 0x2c], 0
// 005b3736  7512                 jne 0x5b374a
// 005b3738  88582c               mov byte ptr [eax + 0x2c], bl
// 005b373b  56                   push esi
// 005b373c  8bcd                 mov ecx, ebp
// 005b373e  c6462c00             mov byte ptr [esi + 0x2c], 0
// 005b3742  e8b9a70d00           call 0x68df00
// 005b3747  8b4608               mov eax, dword ptr [esi + 8]
// 005b374a  80782d00             cmp byte ptr [eax + 0x2d], 0
// 005b374e  7574                 jne 0x5b37c4
// 005b3750  8b08                 mov ecx, dword ptr [eax]
// 005b3752  38592c               cmp byte ptr [ecx + 0x2c], bl
// 005b3755  7508                 jne 0x5b375f
// 005b3757  8b5008               mov edx, dword ptr [eax + 8]
// 005b375a  385a2c               cmp byte ptr [edx + 0x2c], bl
// 005b375d  7461                 je 0x5b37c0
// 005b375f  8b4808               mov ecx, dword ptr [eax + 8]
// 005b3762  38592c               cmp byte ptr [ecx + 0x2c], bl
// 005b3765  7514                 jne 0x5b377b
// 005b3767  8b10                 mov edx, dword ptr [eax]
// 005b3769  885a2c               mov byte ptr [edx + 0x2c], bl
// 005b376c  50                   push eax
// 005b376d  8bcd                 mov ecx, ebp
// 005b376f  c6402c00             mov byte ptr [eax + 0x2c], 0
// 005b3773  e858980d00           call 0x68cfd0
// 005b3778  8b4608               mov eax, dword ptr [esi + 8]
// 005b377b  8a4e2c               mov cl, byte ptr [esi + 0x2c]
// 005b377e  88482c               mov byte ptr [eax + 0x2c], cl
// 005b3781  885e2c               mov byte ptr [esi + 0x2c], bl
// 005b3784  8b5008               mov edx, dword ptr [eax + 8]
// 005b3787  56                   push esi
// 005b3788  8bcd                 mov ecx, ebp
// 005b378a  885a2c               mov byte ptr [edx + 0x2c], bl
// 005b378d  e86ea70d00           call 0x68df00
// 005b3792  eb74                 jmp 0x5b3808
// 005b3794  80782c00             cmp byte ptr [eax + 0x2c], 0
// 005b3798  7511                 jne 0x5b37ab
// 005b379a  88582c               mov byte ptr [eax + 0x2c], bl
// 005b379d  56                   push esi
// 005b379e  8bcd                 mov ecx, ebp
// 005b37a0  c6462c00             mov byte ptr [esi + 0x2c], 0
// 005b37a4  e827980d00           call 0x68cfd0
// 005b37a9  8b06                 mov eax, dword ptr [esi]
// 005b37ab  80782d00             cmp byte ptr [eax + 0x2d], 0
// 005b37af  7513                 jne 0x5b37c4
// 005b37b1  8b4808               mov ecx, dword ptr [eax + 8]
// 005b37b4  38592c               cmp byte ptr [ecx + 0x2c], bl
// 005b37b7  751e                 jne 0x5b37d7
// 005b37b9  8b10                 mov edx, dword ptr [eax]
// 005b37bb  385a2c               cmp byte ptr [edx + 0x2c], bl
// 005b37be  7517                 jne 0x5b37d7
// 005b37c0  c6402c00             mov byte ptr [eax + 0x2c], 0
// 005b37c4  8b4518               mov eax, dword ptr [ebp + 0x18]
// 005b37c7  8bfe                 mov edi, esi
// 005b37c9  8b7604               mov esi, dword ptr [esi + 4]
// 005b37cc  3b7804               cmp edi, dword ptr [eax + 4]
// 005b37cf  0f854bffffff         jne 0x5b3720
// 005b37d5  eb31                 jmp 0x5b3808
// 005b37d7  8b08                 mov ecx, dword ptr [eax]
// 005b37d9  38592c               cmp byte ptr [ecx + 0x2c], bl
// 005b37dc  7514                 jne 0x5b37f2
// 005b37de  8b5008               mov edx, dword ptr [eax + 8]
// 005b37e1  885a2c               mov byte ptr [edx + 0x2c], bl
// 005b37e4  50                   push eax
// 005b37e5  8bcd                 mov ecx, ebp
// 005b37e7  c6402c00             mov byte ptr [eax + 0x2c], 0
// 005b37eb  e810a70d00           call 0x68df00
// 005b37f0  8b06                 mov eax, dword ptr [esi]
// 005b37f2  8a4e2c               mov cl, byte ptr [esi + 0x2c]
// 005b37f5  88482c               mov byte ptr [eax + 0x2c], cl
// 005b37f8  885e2c               mov byte ptr [esi + 0x2c], bl
// 005b37fb  8b10                 mov edx, dword ptr [eax]
// 005b37fd  56                   push esi
// 005b37fe  8bcd                 mov ecx, ebp
// 005b3800  885a2c               mov byte ptr [edx + 0x2c], bl
// 005b3803  e8c8970d00           call 0x68cfd0
// 005b3808  885f2c               mov byte ptr [edi + 0x2c], bl
// 005b380b  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005b380f  83c110               add ecx, 0x10
// 005b3812  ff1568248000         call dword ptr [0x802468]
// 005b3818  8b442410             mov eax, dword ptr [esp + 0x10]
// 005b381c  50                   push eax
// 005b381d  e858ce0e00           call 0x6a067a
// 005b3822  8b451c               mov eax, dword ptr [ebp + 0x1c]
// 005b3825  83c404               add esp, 4
// 005b3828  5f                   pop edi
// 005b3829  5e                   pop esi
// 005b382a  5b                   pop ebx
// 005b382b  85c0                 test eax, eax
// 005b382d  7604                 jbe 0x5b3833
// 005b382f  48                   dec eax
// 005b3830  89451c               mov dword ptr [ebp + 0x1c], eax
// 005b3833  8b4c2464             mov ecx, dword ptr [esp + 0x64]
// 005b3837  8b44245c             mov eax, dword ptr [esp + 0x5c]
// 005b383b  8b5500               mov edx, dword ptr [ebp]
// 005b383e  894804               mov dword ptr [eax + 4], ecx
// 005b3841  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 005b3845  8910                 mov dword ptr [eax], edx
// 005b3847  5d                   pop ebp
// 005b3848  64890d00000000       mov dword ptr fs:[0], ecx
// 005b384f  83c454               add esp, 0x54
// 005b3852  c20c00               ret 0xc
// standard library map_int<string> (function ?erase@?$_Tree@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@@Z)

// stl: map_int<string>
#include <string>
typedef std::string E;
#include <map>
template class std::map<int, E>;
