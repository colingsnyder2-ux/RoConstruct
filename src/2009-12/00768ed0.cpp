// from server: 100% by auto
// roc 2009-12 00768ed0  unit: RBX::VInstance::?$NonFactoryProduct  size: 725 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00768ed0
//
// 00768ed0  64a100000000         mov eax, dword ptr fs:[0]
// 00768ed6  6aff                 push -1
// 00768ed8  6812699500           push 0x956912
// 00768edd  50                   push eax
// 00768ede  64892500000000       mov dword ptr fs:[0], esp
// 00768ee5  8b442418             mov eax, dword ptr [esp + 0x18]
// 00768ee9  83ec48               sub esp, 0x48
// 00768eec  80783100             cmp byte ptr [eax + 0x31], 0
// 00768ef0  55                   push ebp
// 00768ef1  8be9                 mov ebp, ecx
// 00768ef3  7459                 je 0x768f4e
// 00768ef5  68e4f49900           push 0x99f4e4
// 00768efa  8d4c240c             lea ecx, [esp + 0xc]
// 00768efe  ff15f4b69800         call dword ptr [0x98b6f4]
// 00768f04  8d4c2424             lea ecx, [esp + 0x24]
// 00768f08  c744245400000000     mov dword ptr [esp + 0x54], 0
// 00768f10  ff1554b79800         call dword ptr [0x98b754]
// 00768f16  8d442408             lea eax, [esp + 8]
// 00768f1a  50                   push eax
// 00768f1b  8d4c2434             lea ecx, [esp + 0x34]
// 00768f1f  c644245801           mov byte ptr [esp + 0x58], 1
// 00768f24  c744242884f49900     mov dword ptr [esp + 0x28], 0x99f484
// 00768f2c  ff15f0b69800         call dword ptr [0x98b6f0]
// 00768f32  688cefa800           push 0xa8ef8c
// 00768f37  8d4c2428             lea ecx, [esp + 0x28]
// 00768f3b  51                   push ecx
// 00768f3c  c644245c00           mov byte ptr [esp + 0x5c], 0
// 00768f41  c744242c9cf49900     mov dword ptr [esp + 0x2c], 0x99f49c
// 00768f49  e82ab90800           call 0x7f4878
// 00768f4e  53                   push ebx
// 00768f4f  56                   push esi
// 00768f50  8bd8                 mov ebx, eax
// 00768f52  57                   push edi
// 00768f53  8d4c246c             lea ecx, [esp + 0x6c]
// 00768f57  895c2410             mov dword ptr [esp + 0x10], ebx
// 00768f5b  e890a9daff           call 0x5138f0
// 00768f60  8b0b                 mov ecx, dword ptr [ebx]
// 00768f62  80793100             cmp byte ptr [ecx + 0x31], 0
// 00768f66  7405                 je 0x768f6d
// 00768f68  8b7b08               mov edi, dword ptr [ebx + 8]
// 00768f6b  eb1b                 jmp 0x768f88
// 00768f6d  8b5308               mov edx, dword ptr [ebx + 8]
// 00768f70  807a3100             cmp byte ptr [edx + 0x31], 0
// 00768f74  7404                 je 0x768f7a
// 00768f76  8bf9                 mov edi, ecx
// 00768f78  eb0e                 jmp 0x768f88
// 00768f7a  8b442470             mov eax, dword ptr [esp + 0x70]
// 00768f7e  8b7808               mov edi, dword ptr [eax + 8]
// 00768f81  8d5008               lea edx, [eax + 8]
// 00768f84  3bc3                 cmp eax, ebx
// 00768f86  756b                 jne 0x768ff3
// 00768f88  807f3100             cmp byte ptr [edi + 0x31], 0
// 00768f8c  8b7304               mov esi, dword ptr [ebx + 4]
// 00768f8f  7503                 jne 0x768f94
// 00768f91  897704               mov dword ptr [edi + 4], esi
// 00768f94  8b4518               mov eax, dword ptr [ebp + 0x18]
// 00768f97  395804               cmp dword ptr [eax + 4], ebx
// 00768f9a  7505                 jne 0x768fa1
// 00768f9c  897804               mov dword ptr [eax + 4], edi
// 00768f9f  eb0b                 jmp 0x768fac
// 00768fa1  391e                 cmp dword ptr [esi], ebx
// 00768fa3  7504                 jne 0x768fa9
// 00768fa5  893e                 mov dword ptr [esi], edi
// 00768fa7  eb03                 jmp 0x768fac
// 00768fa9  897e08               mov dword ptr [esi + 8], edi
// 00768fac  8b5d18               mov ebx, dword ptr [ebp + 0x18]
// 00768faf  8b03                 mov eax, dword ptr [ebx]
// 00768fb1  3b442410             cmp eax, dword ptr [esp + 0x10]
// 00768fb5  7515                 jne 0x768fcc
// 00768fb7  807f3100             cmp byte ptr [edi + 0x31], 0
// 00768fbb  7404                 je 0x768fc1
// 00768fbd  8bc6                 mov eax, esi
// 00768fbf  eb09                 jmp 0x768fca
// 00768fc1  57                   push edi
// 00768fc2  e8c97effff           call 0x760e90
// 00768fc7  83c404               add esp, 4
// 00768fca  8903                 mov dword ptr [ebx], eax
// 00768fcc  8b5d18               mov ebx, dword ptr [ebp + 0x18]
// 00768fcf  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00768fd3  394b08               cmp dword ptr [ebx + 8], ecx
// 00768fd6  7577                 jne 0x76904f
// 00768fd8  807f3100             cmp byte ptr [edi + 0x31], 0
// 00768fdc  7407                 je 0x768fe5
// 00768fde  8bc6                 mov eax, esi
// 00768fe0  894308               mov dword ptr [ebx + 8], eax
// 00768fe3  eb6a                 jmp 0x76904f
// 00768fe5  57                   push edi
// 00768fe6  e8251ef2ff           call 0x68ae10
// 00768feb  83c404               add esp, 4
// 00768fee  894308               mov dword ptr [ebx + 8], eax
// 00768ff1  eb5c                 jmp 0x76904f
// 00768ff3  894104               mov dword ptr [ecx + 4], eax
// 00768ff6  8b0b                 mov ecx, dword ptr [ebx]
// 00768ff8  8908                 mov dword ptr [eax], ecx
// 00768ffa  3b4308               cmp eax, dword ptr [ebx + 8]
// 00768ffd  7504                 jne 0x769003
// 00768fff  8bf0                 mov esi, eax
// 00769001  eb19                 jmp 0x76901c
// 00769003  807f3100             cmp byte ptr [edi + 0x31], 0
// 00769007  8b7004               mov esi, dword ptr [eax + 4]
// 0076900a  7503                 jne 0x76900f
// 0076900c  897704               mov dword ptr [edi + 4], esi
// 0076900f  893e                 mov dword ptr [esi], edi
// 00769011  8b4b08               mov ecx, dword ptr [ebx + 8]
// 00769014  890a                 mov dword ptr [edx], ecx
// 00769016  8b5308               mov edx, dword ptr [ebx + 8]
// 00769019  894204               mov dword ptr [edx + 4], eax
// 0076901c  8b4d18               mov ecx, dword ptr [ebp + 0x18]
// 0076901f  395904               cmp dword ptr [ecx + 4], ebx
// 00769022  7505                 jne 0x769029
// 00769024  894104               mov dword ptr [ecx + 4], eax
// 00769027  eb0e                 jmp 0x769037
// 00769029  8b4b04               mov ecx, dword ptr [ebx + 4]
// 0076902c  3919                 cmp dword ptr [ecx], ebx
// 0076902e  7504                 jne 0x769034
// 00769030  8901                 mov dword ptr [ecx], eax
// 00769032  eb03                 jmp 0x769037
// 00769034  894108               mov dword ptr [ecx + 8], eax
// 00769037  8b4b04               mov ecx, dword ptr [ebx + 4]
// 0076903a  894804               mov dword ptr [eax + 4], ecx
// 0076903d  8d4b30               lea ecx, [ebx + 0x30]
// 00769040  83c030               add eax, 0x30
// 00769043  3bc1                 cmp eax, ecx
// 00769045  7408                 je 0x76904f
// 00769047  8a19                 mov bl, byte ptr [ecx]
// 00769049  8a10                 mov dl, byte ptr [eax]
// 0076904b  8818                 mov byte ptr [eax], bl
// 0076904d  8811                 mov byte ptr [ecx], dl
// 0076904f  8b542410             mov edx, dword ptr [esp + 0x10]
// 00769053  b301                 mov bl, 1
// 00769055  385a30               cmp byte ptr [edx + 0x30], bl
// 00769058  0f85fd000000         jne 0x76915b
// 0076905e  8b4518               mov eax, dword ptr [ebp + 0x18]
// 00769061  3b7804               cmp edi, dword ptr [eax + 4]
// 00769064  0f84ee000000         je 0x769158
// 0076906a  8d9b00000000         lea ebx, [ebx]
// 00769070  385f30               cmp byte ptr [edi + 0x30], bl
// 00769073  0f85df000000         jne 0x769158
// 00769079  8b06                 mov eax, dword ptr [esi]
// 0076907b  3bf8                 cmp edi, eax
// 0076907d  7565                 jne 0x7690e4
// 0076907f  8b4608               mov eax, dword ptr [esi + 8]
// 00769082  80783000             cmp byte ptr [eax + 0x30], 0
// 00769086  7512                 jne 0x76909a
// 00769088  885830               mov byte ptr [eax + 0x30], bl
// 0076908b  56                   push esi
// 0076908c  8bcd                 mov ecx, ebp
// 0076908e  c6463000             mov byte ptr [esi + 0x30], 0
// 00769092  e879a7daff           call 0x513810
// 00769097  8b4608               mov eax, dword ptr [esi + 8]
// 0076909a  80783100             cmp byte ptr [eax + 0x31], 0
// 0076909e  7574                 jne 0x769114
// 007690a0  8b08                 mov ecx, dword ptr [eax]
// 007690a2  385930               cmp byte ptr [ecx + 0x30], bl
// 007690a5  7508                 jne 0x7690af
// 007690a7  8b5008               mov edx, dword ptr [eax + 8]
// 007690aa  385a30               cmp byte ptr [edx + 0x30], bl
// 007690ad  7461                 je 0x769110
// 007690af  8b4808               mov ecx, dword ptr [eax + 8]
// 007690b2  385930               cmp byte ptr [ecx + 0x30], bl
// 007690b5  7514                 jne 0x7690cb
// 007690b7  8b10                 mov edx, dword ptr [eax]
// 007690b9  885a30               mov byte ptr [edx + 0x30], bl
// 007690bc  50                   push eax
// 007690bd  8bcd                 mov ecx, ebp
// 007690bf  c6403000             mov byte ptr [eax + 0x30], 0
// 007690c3  e8d89bf9ff           call 0x702ca0
// 007690c8  8b4608               mov eax, dword ptr [esi + 8]
// 007690cb  8a4e30               mov cl, byte ptr [esi + 0x30]
// 007690ce  884830               mov byte ptr [eax + 0x30], cl
// 007690d1  885e30               mov byte ptr [esi + 0x30], bl
// 007690d4  8b5008               mov edx, dword ptr [eax + 8]
// 007690d7  56                   push esi
// 007690d8  8bcd                 mov ecx, ebp
// 007690da  885a30               mov byte ptr [edx + 0x30], bl
// 007690dd  e82ea7daff           call 0x513810
// 007690e2  eb74                 jmp 0x769158
// 007690e4  80783000             cmp byte ptr [eax + 0x30], 0
// 007690e8  7511                 jne 0x7690fb
// 007690ea  885830               mov byte ptr [eax + 0x30], bl
// 007690ed  56                   push esi
// 007690ee  8bcd                 mov ecx, ebp
// 007690f0  c6463000             mov byte ptr [esi + 0x30], 0
// 007690f4  e8a79bf9ff           call 0x702ca0
// 007690f9  8b06                 mov eax, dword ptr [esi]
// 007690fb  80783100             cmp byte ptr [eax + 0x31], 0
// 007690ff  7513                 jne 0x769114
// 00769101  8b4808               mov ecx, dword ptr [eax + 8]
// 00769104  385930               cmp byte ptr [ecx + 0x30], bl
// 00769107  751e                 jne 0x769127
// 00769109  8b10                 mov edx, dword ptr [eax]
// 0076910b  385a30               cmp byte ptr [edx + 0x30], bl
// 0076910e  7517                 jne 0x769127
// 00769110  c6403000             mov byte ptr [eax + 0x30], 0
// 00769114  8b4518               mov eax, dword ptr [ebp + 0x18]
// 00769117  8bfe                 mov edi, esi
// 00769119  8b7604               mov esi, dword ptr [esi + 4]
// 0076911c  3b7804               cmp edi, dword ptr [eax + 4]
// 0076911f  0f854bffffff         jne 0x769070
// 00769125  eb31                 jmp 0x769158
// 00769127  8b08                 mov ecx, dword ptr [eax]
// 00769129  385930               cmp byte ptr [ecx + 0x30], bl
// 0076912c  7514                 jne 0x769142
// 0076912e  8b5008               mov edx, dword ptr [eax + 8]
// 00769131  885a30               mov byte ptr [edx + 0x30], bl
// 00769134  50                   push eax
// 00769135  8bcd                 mov ecx, ebp
// 00769137  c6403000             mov byte ptr [eax + 0x30], 0
// 0076913b  e8d0a6daff           call 0x513810
// 00769140  8b06                 mov eax, dword ptr [esi]
// 00769142  8a4e30               mov cl, byte ptr [esi + 0x30]
// 00769145  884830               mov byte ptr [eax + 0x30], cl
// 00769148  885e30               mov byte ptr [esi + 0x30], bl
// 0076914b  8b10                 mov edx, dword ptr [eax]
// 0076914d  56                   push esi
// 0076914e  8bcd                 mov ecx, ebp
// 00769150  885a30               mov byte ptr [edx + 0x30], bl
// 00769153  e8489bf9ff           call 0x702ca0
// 00769158  885f30               mov byte ptr [edi + 0x30], bl
// 0076915b  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0076915f  83c10c               add ecx, 0xc
// 00769162  ff15e4b69800         call dword ptr [0x98b6e4]
// 00769168  8b442410             mov eax, dword ptr [esp + 0x10]
// 0076916c  50                   push eax
// 0076916d  e8e8a60800           call 0x7f385a
// 00769172  8b451c               mov eax, dword ptr [ebp + 0x1c]
// 00769175  83c404               add esp, 4
// 00769178  5f                   pop edi
// 00769179  5e                   pop esi
// 0076917a  5b                   pop ebx
// 0076917b  85c0                 test eax, eax
// 0076917d  7604                 jbe 0x769183
// 0076917f  48                   dec eax
// 00769180  89451c               mov dword ptr [ebp + 0x1c], eax
// 00769183  8b4c2464             mov ecx, dword ptr [esp + 0x64]
// 00769187  8b44245c             mov eax, dword ptr [esp + 0x5c]
// 0076918b  8b5500               mov edx, dword ptr [ebp]
// 0076918e  894804               mov dword ptr [eax + 4], ecx
// 00769191  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 00769195  8910                 mov dword ptr [eax], edx
// 00769197  5d                   pop ebp
// 00769198  64890d00000000       mov dword ptr fs:[0], ecx
// 0076919f  83c454               add esp, 0x54
// 007691a2  c20c00               ret 0xc
// standard library map_str<pod8> (function ?erase@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@@Z)

// stl: map_str<pod8>
struct E { int v[2]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
