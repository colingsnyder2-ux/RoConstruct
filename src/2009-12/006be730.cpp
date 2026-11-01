// from server: 100% by auto
// roc 2009-12 006be730  unit: RBX::VInstance::?$NonFactoryProduct  size: 725 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006be730
//
// 006be730  64a100000000         mov eax, dword ptr fs:[0]
// 006be736  6aff                 push -1
// 006be738  6812699500           push 0x956912
// 006be73d  50                   push eax
// 006be73e  64892500000000       mov dword ptr fs:[0], esp
// 006be745  8b442418             mov eax, dword ptr [esp + 0x18]
// 006be749  83ec48               sub esp, 0x48
// 006be74c  80783500             cmp byte ptr [eax + 0x35], 0
// 006be750  55                   push ebp
// 006be751  8be9                 mov ebp, ecx
// 006be753  7459                 je 0x6be7ae
// 006be755  68e4f49900           push 0x99f4e4
// 006be75a  8d4c240c             lea ecx, [esp + 0xc]
// 006be75e  ff15f4b69800         call dword ptr [0x98b6f4]
// 006be764  8d4c2424             lea ecx, [esp + 0x24]
// 006be768  c744245400000000     mov dword ptr [esp + 0x54], 0
// 006be770  ff1554b79800         call dword ptr [0x98b754]
// 006be776  8d442408             lea eax, [esp + 8]
// 006be77a  50                   push eax
// 006be77b  8d4c2434             lea ecx, [esp + 0x34]
// 006be77f  c644245801           mov byte ptr [esp + 0x58], 1
// 006be784  c744242884f49900     mov dword ptr [esp + 0x28], 0x99f484
// 006be78c  ff15f0b69800         call dword ptr [0x98b6f0]
// 006be792  688cefa800           push 0xa8ef8c
// 006be797  8d4c2428             lea ecx, [esp + 0x28]
// 006be79b  51                   push ecx
// 006be79c  c644245c00           mov byte ptr [esp + 0x5c], 0
// 006be7a1  c744242c9cf49900     mov dword ptr [esp + 0x2c], 0x99f49c
// 006be7a9  e8ca601300           call 0x7f4878
// 006be7ae  53                   push ebx
// 006be7af  56                   push esi
// 006be7b0  8bd8                 mov ebx, eax
// 006be7b2  57                   push edi
// 006be7b3  8d4c246c             lea ecx, [esp + 0x6c]
// 006be7b7  895c2410             mov dword ptr [esp + 0x10], ebx
// 006be7bb  e8e052ffff           call 0x6b3aa0
// 006be7c0  8b0b                 mov ecx, dword ptr [ebx]
// 006be7c2  80793500             cmp byte ptr [ecx + 0x35], 0
// 006be7c6  7405                 je 0x6be7cd
// 006be7c8  8b7b08               mov edi, dword ptr [ebx + 8]
// 006be7cb  eb1b                 jmp 0x6be7e8
// 006be7cd  8b5308               mov edx, dword ptr [ebx + 8]
// 006be7d0  807a3500             cmp byte ptr [edx + 0x35], 0
// 006be7d4  7404                 je 0x6be7da
// 006be7d6  8bf9                 mov edi, ecx
// 006be7d8  eb0e                 jmp 0x6be7e8
// 006be7da  8b442470             mov eax, dword ptr [esp + 0x70]
// 006be7de  8b7808               mov edi, dword ptr [eax + 8]
// 006be7e1  8d5008               lea edx, [eax + 8]
// 006be7e4  3bc3                 cmp eax, ebx
// 006be7e6  756b                 jne 0x6be853
// 006be7e8  807f3500             cmp byte ptr [edi + 0x35], 0
// 006be7ec  8b7304               mov esi, dword ptr [ebx + 4]
// 006be7ef  7503                 jne 0x6be7f4
// 006be7f1  897704               mov dword ptr [edi + 4], esi
// 006be7f4  8b4518               mov eax, dword ptr [ebp + 0x18]
// 006be7f7  395804               cmp dword ptr [eax + 4], ebx
// 006be7fa  7505                 jne 0x6be801
// 006be7fc  897804               mov dword ptr [eax + 4], edi
// 006be7ff  eb0b                 jmp 0x6be80c
// 006be801  391e                 cmp dword ptr [esi], ebx
// 006be803  7504                 jne 0x6be809
// 006be805  893e                 mov dword ptr [esi], edi
// 006be807  eb03                 jmp 0x6be80c
// 006be809  897e08               mov dword ptr [esi + 8], edi
// 006be80c  8b5d18               mov ebx, dword ptr [ebp + 0x18]
// 006be80f  8b03                 mov eax, dword ptr [ebx]
// 006be811  3b442410             cmp eax, dword ptr [esp + 0x10]
// 006be815  7515                 jne 0x6be82c
// 006be817  807f3500             cmp byte ptr [edi + 0x35], 0
// 006be81b  7404                 je 0x6be821
// 006be81d  8bc6                 mov eax, esi
// 006be81f  eb09                 jmp 0x6be82a
// 006be821  57                   push edi
// 006be822  e8a98ee7ff           call 0x5376d0
// 006be827  83c404               add esp, 4
// 006be82a  8903                 mov dword ptr [ebx], eax
// 006be82c  8b5d18               mov ebx, dword ptr [ebp + 0x18]
// 006be82f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006be833  394b08               cmp dword ptr [ebx + 8], ecx
// 006be836  7577                 jne 0x6be8af
// 006be838  807f3500             cmp byte ptr [edi + 0x35], 0
// 006be83c  7407                 je 0x6be845
// 006be83e  8bc6                 mov eax, esi
// 006be840  894308               mov dword ptr [ebx + 8], eax
// 006be843  eb6a                 jmp 0x6be8af
// 006be845  57                   push edi
// 006be846  e885e8ffff           call 0x6bd0d0
// 006be84b  83c404               add esp, 4
// 006be84e  894308               mov dword ptr [ebx + 8], eax
// 006be851  eb5c                 jmp 0x6be8af
// 006be853  894104               mov dword ptr [ecx + 4], eax
// 006be856  8b0b                 mov ecx, dword ptr [ebx]
// 006be858  8908                 mov dword ptr [eax], ecx
// 006be85a  3b4308               cmp eax, dword ptr [ebx + 8]
// 006be85d  7504                 jne 0x6be863
// 006be85f  8bf0                 mov esi, eax
// 006be861  eb19                 jmp 0x6be87c
// 006be863  807f3500             cmp byte ptr [edi + 0x35], 0
// 006be867  8b7004               mov esi, dword ptr [eax + 4]
// 006be86a  7503                 jne 0x6be86f
// 006be86c  897704               mov dword ptr [edi + 4], esi
// 006be86f  893e                 mov dword ptr [esi], edi
// 006be871  8b4b08               mov ecx, dword ptr [ebx + 8]
// 006be874  890a                 mov dword ptr [edx], ecx
// 006be876  8b5308               mov edx, dword ptr [ebx + 8]
// 006be879  894204               mov dword ptr [edx + 4], eax
// 006be87c  8b4d18               mov ecx, dword ptr [ebp + 0x18]
// 006be87f  395904               cmp dword ptr [ecx + 4], ebx
// 006be882  7505                 jne 0x6be889
// 006be884  894104               mov dword ptr [ecx + 4], eax
// 006be887  eb0e                 jmp 0x6be897
// 006be889  8b4b04               mov ecx, dword ptr [ebx + 4]
// 006be88c  3919                 cmp dword ptr [ecx], ebx
// 006be88e  7504                 jne 0x6be894
// 006be890  8901                 mov dword ptr [ecx], eax
// 006be892  eb03                 jmp 0x6be897
// 006be894  894108               mov dword ptr [ecx + 8], eax
// 006be897  8b4b04               mov ecx, dword ptr [ebx + 4]
// 006be89a  894804               mov dword ptr [eax + 4], ecx
// 006be89d  8d4b34               lea ecx, [ebx + 0x34]
// 006be8a0  83c034               add eax, 0x34
// 006be8a3  3bc1                 cmp eax, ecx
// 006be8a5  7408                 je 0x6be8af
// 006be8a7  8a19                 mov bl, byte ptr [ecx]
// 006be8a9  8a10                 mov dl, byte ptr [eax]
// 006be8ab  8818                 mov byte ptr [eax], bl
// 006be8ad  8811                 mov byte ptr [ecx], dl
// 006be8af  8b542410             mov edx, dword ptr [esp + 0x10]
// 006be8b3  b301                 mov bl, 1
// 006be8b5  385a34               cmp byte ptr [edx + 0x34], bl
// 006be8b8  0f85fd000000         jne 0x6be9bb
// 006be8be  8b4518               mov eax, dword ptr [ebp + 0x18]
// 006be8c1  3b7804               cmp edi, dword ptr [eax + 4]
// 006be8c4  0f84ee000000         je 0x6be9b8
// 006be8ca  8d9b00000000         lea ebx, [ebx]
// 006be8d0  385f34               cmp byte ptr [edi + 0x34], bl
// 006be8d3  0f85df000000         jne 0x6be9b8
// 006be8d9  8b06                 mov eax, dword ptr [esi]
// 006be8db  3bf8                 cmp edi, eax
// 006be8dd  7565                 jne 0x6be944
// 006be8df  8b4608               mov eax, dword ptr [esi + 8]
// 006be8e2  80783400             cmp byte ptr [eax + 0x34], 0
// 006be8e6  7512                 jne 0x6be8fa
// 006be8e8  885834               mov byte ptr [eax + 0x34], bl
// 006be8eb  56                   push esi
// 006be8ec  8bcd                 mov ecx, ebp
// 006be8ee  c6463400             mov byte ptr [esi + 0x34], 0
// 006be8f2  e829ebffff           call 0x6bd420
// 006be8f7  8b4608               mov eax, dword ptr [esi + 8]
// 006be8fa  80783500             cmp byte ptr [eax + 0x35], 0
// 006be8fe  7574                 jne 0x6be974
// 006be900  8b08                 mov ecx, dword ptr [eax]
// 006be902  385934               cmp byte ptr [ecx + 0x34], bl
// 006be905  7508                 jne 0x6be90f
// 006be907  8b5008               mov edx, dword ptr [eax + 8]
// 006be90a  385a34               cmp byte ptr [edx + 0x34], bl
// 006be90d  7461                 je 0x6be970
// 006be90f  8b4808               mov ecx, dword ptr [eax + 8]
// 006be912  385934               cmp byte ptr [ecx + 0x34], bl
// 006be915  7514                 jne 0x6be92b
// 006be917  8b10                 mov edx, dword ptr [eax]
// 006be919  885a34               mov byte ptr [edx + 0x34], bl
// 006be91c  50                   push eax
// 006be91d  8bcd                 mov ecx, ebp
// 006be91f  c6403400             mov byte ptr [eax + 0x34], 0
// 006be923  e8f850ffff           call 0x6b3a20
// 006be928  8b4608               mov eax, dword ptr [esi + 8]
// 006be92b  8a4e34               mov cl, byte ptr [esi + 0x34]
// 006be92e  884834               mov byte ptr [eax + 0x34], cl
// 006be931  885e34               mov byte ptr [esi + 0x34], bl
// 006be934  8b5008               mov edx, dword ptr [eax + 8]
// 006be937  56                   push esi
// 006be938  8bcd                 mov ecx, ebp
// 006be93a  885a34               mov byte ptr [edx + 0x34], bl
// 006be93d  e8deeaffff           call 0x6bd420
// 006be942  eb74                 jmp 0x6be9b8
// 006be944  80783400             cmp byte ptr [eax + 0x34], 0
// 006be948  7511                 jne 0x6be95b
// 006be94a  885834               mov byte ptr [eax + 0x34], bl
// 006be94d  56                   push esi
// 006be94e  8bcd                 mov ecx, ebp
// 006be950  c6463400             mov byte ptr [esi + 0x34], 0
// 006be954  e8c750ffff           call 0x6b3a20
// 006be959  8b06                 mov eax, dword ptr [esi]
// 006be95b  80783500             cmp byte ptr [eax + 0x35], 0
// 006be95f  7513                 jne 0x6be974
// 006be961  8b4808               mov ecx, dword ptr [eax + 8]
// 006be964  385934               cmp byte ptr [ecx + 0x34], bl
// 006be967  751e                 jne 0x6be987
// 006be969  8b10                 mov edx, dword ptr [eax]
// 006be96b  385a34               cmp byte ptr [edx + 0x34], bl
// 006be96e  7517                 jne 0x6be987
// 006be970  c6403400             mov byte ptr [eax + 0x34], 0
// 006be974  8b4518               mov eax, dword ptr [ebp + 0x18]
// 006be977  8bfe                 mov edi, esi
// 006be979  8b7604               mov esi, dword ptr [esi + 4]
// 006be97c  3b7804               cmp edi, dword ptr [eax + 4]
// 006be97f  0f854bffffff         jne 0x6be8d0
// 006be985  eb31                 jmp 0x6be9b8
// 006be987  8b08                 mov ecx, dword ptr [eax]
// 006be989  385934               cmp byte ptr [ecx + 0x34], bl
// 006be98c  7514                 jne 0x6be9a2
// 006be98e  8b5008               mov edx, dword ptr [eax + 8]
// 006be991  885a34               mov byte ptr [edx + 0x34], bl
// 006be994  50                   push eax
// 006be995  8bcd                 mov ecx, ebp
// 006be997  c6403400             mov byte ptr [eax + 0x34], 0
// 006be99b  e880eaffff           call 0x6bd420
// 006be9a0  8b06                 mov eax, dword ptr [esi]
// 006be9a2  8a4e34               mov cl, byte ptr [esi + 0x34]
// 006be9a5  884834               mov byte ptr [eax + 0x34], cl
// 006be9a8  885e34               mov byte ptr [esi + 0x34], bl
// 006be9ab  8b10                 mov edx, dword ptr [eax]
// 006be9ad  56                   push esi
// 006be9ae  8bcd                 mov ecx, ebp
// 006be9b0  885a34               mov byte ptr [edx + 0x34], bl
// 006be9b3  e86850ffff           call 0x6b3a20
// 006be9b8  885f34               mov byte ptr [edi + 0x34], bl
// 006be9bb  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006be9bf  83c10c               add ecx, 0xc
// 006be9c2  ff15e4b69800         call dword ptr [0x98b6e4]
// 006be9c8  8b442410             mov eax, dword ptr [esp + 0x10]
// 006be9cc  50                   push eax
// 006be9cd  e8884e1300           call 0x7f385a
// 006be9d2  8b451c               mov eax, dword ptr [ebp + 0x1c]
// 006be9d5  83c404               add esp, 4
// 006be9d8  5f                   pop edi
// 006be9d9  5e                   pop esi
// 006be9da  5b                   pop ebx
// 006be9db  85c0                 test eax, eax
// 006be9dd  7604                 jbe 0x6be9e3
// 006be9df  48                   dec eax
// 006be9e0  89451c               mov dword ptr [ebp + 0x1c], eax
// 006be9e3  8b4c2464             mov ecx, dword ptr [esp + 0x64]
// 006be9e7  8b44245c             mov eax, dword ptr [esp + 0x5c]
// 006be9eb  8b5500               mov edx, dword ptr [ebp]
// 006be9ee  894804               mov dword ptr [eax + 4], ecx
// 006be9f1  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 006be9f5  8910                 mov dword ptr [eax], edx
// 006be9f7  5d                   pop ebp
// 006be9f8  64890d00000000       mov dword ptr fs:[0], ecx
// 006be9ff  83c454               add esp, 0x54
// 006bea02  c20c00               ret 0xc
// standard library map_str<pod12> (function ?erase@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@@Z)

// stl: map_str<pod12>
struct E { int v[3]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
