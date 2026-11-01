// from server: 100% by auto
// roc 2009-12 006ad720  unit: RBX::Accoutrement  size: 725 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006ad720
//
// 006ad720  64a100000000         mov eax, dword ptr fs:[0]
// 006ad726  6aff                 push -1
// 006ad728  6812699500           push 0x956912
// 006ad72d  50                   push eax
// 006ad72e  64892500000000       mov dword ptr fs:[0], esp
// 006ad735  8b442418             mov eax, dword ptr [esp + 0x18]
// 006ad739  83ec48               sub esp, 0x48
// 006ad73c  80782d00             cmp byte ptr [eax + 0x2d], 0
// 006ad740  55                   push ebp
// 006ad741  8be9                 mov ebp, ecx
// 006ad743  7459                 je 0x6ad79e
// 006ad745  68e4f49900           push 0x99f4e4
// 006ad74a  8d4c240c             lea ecx, [esp + 0xc]
// 006ad74e  ff15f4b69800         call dword ptr [0x98b6f4]
// 006ad754  8d4c2424             lea ecx, [esp + 0x24]
// 006ad758  c744245400000000     mov dword ptr [esp + 0x54], 0
// 006ad760  ff1554b79800         call dword ptr [0x98b754]
// 006ad766  8d442408             lea eax, [esp + 8]
// 006ad76a  50                   push eax
// 006ad76b  8d4c2434             lea ecx, [esp + 0x34]
// 006ad76f  c644245801           mov byte ptr [esp + 0x58], 1
// 006ad774  c744242884f49900     mov dword ptr [esp + 0x28], 0x99f484
// 006ad77c  ff15f0b69800         call dword ptr [0x98b6f0]
// 006ad782  688cefa800           push 0xa8ef8c
// 006ad787  8d4c2428             lea ecx, [esp + 0x28]
// 006ad78b  51                   push ecx
// 006ad78c  c644245c00           mov byte ptr [esp + 0x5c], 0
// 006ad791  c744242c9cf49900     mov dword ptr [esp + 0x2c], 0x99f49c
// 006ad799  e8da701400           call 0x7f4878
// 006ad79e  53                   push ebx
// 006ad79f  56                   push esi
// 006ad7a0  8bd8                 mov ebx, eax
// 006ad7a2  57                   push edi
// 006ad7a3  8d4c246c             lea ecx, [esp + 0x6c]
// 006ad7a7  895c2410             mov dword ptr [esp + 0x10], ebx
// 006ad7ab  e860d1dcff           call 0x47a910
// 006ad7b0  8b0b                 mov ecx, dword ptr [ebx]
// 006ad7b2  80792d00             cmp byte ptr [ecx + 0x2d], 0
// 006ad7b6  7405                 je 0x6ad7bd
// 006ad7b8  8b7b08               mov edi, dword ptr [ebx + 8]
// 006ad7bb  eb1b                 jmp 0x6ad7d8
// 006ad7bd  8b5308               mov edx, dword ptr [ebx + 8]
// 006ad7c0  807a2d00             cmp byte ptr [edx + 0x2d], 0
// 006ad7c4  7404                 je 0x6ad7ca
// 006ad7c6  8bf9                 mov edi, ecx
// 006ad7c8  eb0e                 jmp 0x6ad7d8
// 006ad7ca  8b442470             mov eax, dword ptr [esp + 0x70]
// 006ad7ce  8b7808               mov edi, dword ptr [eax + 8]
// 006ad7d1  8d5008               lea edx, [eax + 8]
// 006ad7d4  3bc3                 cmp eax, ebx
// 006ad7d6  756b                 jne 0x6ad843
// 006ad7d8  807f2d00             cmp byte ptr [edi + 0x2d], 0
// 006ad7dc  8b7304               mov esi, dword ptr [ebx + 4]
// 006ad7df  7503                 jne 0x6ad7e4
// 006ad7e1  897704               mov dword ptr [edi + 4], esi
// 006ad7e4  8b4518               mov eax, dword ptr [ebp + 0x18]
// 006ad7e7  395804               cmp dword ptr [eax + 4], ebx
// 006ad7ea  7505                 jne 0x6ad7f1
// 006ad7ec  897804               mov dword ptr [eax + 4], edi
// 006ad7ef  eb0b                 jmp 0x6ad7fc
// 006ad7f1  391e                 cmp dword ptr [esi], ebx
// 006ad7f3  7504                 jne 0x6ad7f9
// 006ad7f5  893e                 mov dword ptr [esi], edi
// 006ad7f7  eb03                 jmp 0x6ad7fc
// 006ad7f9  897e08               mov dword ptr [esi + 8], edi
// 006ad7fc  8b5d18               mov ebx, dword ptr [ebp + 0x18]
// 006ad7ff  8b03                 mov eax, dword ptr [ebx]
// 006ad801  3b442410             cmp eax, dword ptr [esp + 0x10]
// 006ad805  7515                 jne 0x6ad81c
// 006ad807  807f2d00             cmp byte ptr [edi + 0x2d], 0
// 006ad80b  7404                 je 0x6ad811
// 006ad80d  8bc6                 mov eax, esi
// 006ad80f  eb09                 jmp 0x6ad81a
// 006ad811  57                   push edi
// 006ad812  e88945f8ff           call 0x631da0
// 006ad817  83c404               add esp, 4
// 006ad81a  8903                 mov dword ptr [ebx], eax
// 006ad81c  8b5d18               mov ebx, dword ptr [ebp + 0x18]
// 006ad81f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006ad823  394b08               cmp dword ptr [ebx + 8], ecx
// 006ad826  7577                 jne 0x6ad89f
// 006ad828  807f2d00             cmp byte ptr [edi + 0x2d], 0
// 006ad82c  7407                 je 0x6ad835
// 006ad82e  8bc6                 mov eax, esi
// 006ad830  894308               mov dword ptr [ebx + 8], eax
// 006ad833  eb6a                 jmp 0x6ad89f
// 006ad835  57                   push edi
// 006ad836  e86592dcff           call 0x476aa0
// 006ad83b  83c404               add esp, 4
// 006ad83e  894308               mov dword ptr [ebx + 8], eax
// 006ad841  eb5c                 jmp 0x6ad89f
// 006ad843  894104               mov dword ptr [ecx + 4], eax
// 006ad846  8b0b                 mov ecx, dword ptr [ebx]
// 006ad848  8908                 mov dword ptr [eax], ecx
// 006ad84a  3b4308               cmp eax, dword ptr [ebx + 8]
// 006ad84d  7504                 jne 0x6ad853
// 006ad84f  8bf0                 mov esi, eax
// 006ad851  eb19                 jmp 0x6ad86c
// 006ad853  807f2d00             cmp byte ptr [edi + 0x2d], 0
// 006ad857  8b7004               mov esi, dword ptr [eax + 4]
// 006ad85a  7503                 jne 0x6ad85f
// 006ad85c  897704               mov dword ptr [edi + 4], esi
// 006ad85f  893e                 mov dword ptr [esi], edi
// 006ad861  8b4b08               mov ecx, dword ptr [ebx + 8]
// 006ad864  890a                 mov dword ptr [edx], ecx
// 006ad866  8b5308               mov edx, dword ptr [ebx + 8]
// 006ad869  894204               mov dword ptr [edx + 4], eax
// 006ad86c  8b4d18               mov ecx, dword ptr [ebp + 0x18]
// 006ad86f  395904               cmp dword ptr [ecx + 4], ebx
// 006ad872  7505                 jne 0x6ad879
// 006ad874  894104               mov dword ptr [ecx + 4], eax
// 006ad877  eb0e                 jmp 0x6ad887
// 006ad879  8b4b04               mov ecx, dword ptr [ebx + 4]
// 006ad87c  3919                 cmp dword ptr [ecx], ebx
// 006ad87e  7504                 jne 0x6ad884
// 006ad880  8901                 mov dword ptr [ecx], eax
// 006ad882  eb03                 jmp 0x6ad887
// 006ad884  894108               mov dword ptr [ecx + 8], eax
// 006ad887  8b4b04               mov ecx, dword ptr [ebx + 4]
// 006ad88a  894804               mov dword ptr [eax + 4], ecx
// 006ad88d  8d4b2c               lea ecx, [ebx + 0x2c]
// 006ad890  83c02c               add eax, 0x2c
// 006ad893  3bc1                 cmp eax, ecx
// 006ad895  7408                 je 0x6ad89f
// 006ad897  8a19                 mov bl, byte ptr [ecx]
// 006ad899  8a10                 mov dl, byte ptr [eax]
// 006ad89b  8818                 mov byte ptr [eax], bl
// 006ad89d  8811                 mov byte ptr [ecx], dl
// 006ad89f  8b542410             mov edx, dword ptr [esp + 0x10]
// 006ad8a3  b301                 mov bl, 1
// 006ad8a5  385a2c               cmp byte ptr [edx + 0x2c], bl
// 006ad8a8  0f85fd000000         jne 0x6ad9ab
// 006ad8ae  8b4518               mov eax, dword ptr [ebp + 0x18]
// 006ad8b1  3b7804               cmp edi, dword ptr [eax + 4]
// 006ad8b4  0f84ee000000         je 0x6ad9a8
// 006ad8ba  8d9b00000000         lea ebx, [ebx]
// 006ad8c0  385f2c               cmp byte ptr [edi + 0x2c], bl
// 006ad8c3  0f85df000000         jne 0x6ad9a8
// 006ad8c9  8b06                 mov eax, dword ptr [esi]
// 006ad8cb  3bf8                 cmp edi, eax
// 006ad8cd  7565                 jne 0x6ad934
// 006ad8cf  8b4608               mov eax, dword ptr [esi + 8]
// 006ad8d2  80782c00             cmp byte ptr [eax + 0x2c], 0
// 006ad8d6  7512                 jne 0x6ad8ea
// 006ad8d8  88582c               mov byte ptr [eax + 0x2c], bl
// 006ad8db  56                   push esi
// 006ad8dc  8bcd                 mov ecx, ebp
// 006ad8de  c6462c00             mov byte ptr [esi + 0x2c], 0
// 006ad8e2  e899d0dcff           call 0x47a980
// 006ad8e7  8b4608               mov eax, dword ptr [esi + 8]
// 006ad8ea  80782d00             cmp byte ptr [eax + 0x2d], 0
// 006ad8ee  7574                 jne 0x6ad964
// 006ad8f0  8b08                 mov ecx, dword ptr [eax]
// 006ad8f2  38592c               cmp byte ptr [ecx + 0x2c], bl
// 006ad8f5  7508                 jne 0x6ad8ff
// 006ad8f7  8b5008               mov edx, dword ptr [eax + 8]
// 006ad8fa  385a2c               cmp byte ptr [edx + 0x2c], bl
// 006ad8fd  7461                 je 0x6ad960
// 006ad8ff  8b4808               mov ecx, dword ptr [eax + 8]
// 006ad902  38592c               cmp byte ptr [ecx + 0x2c], bl
// 006ad905  7514                 jne 0x6ad91b
// 006ad907  8b10                 mov edx, dword ptr [eax]
// 006ad909  885a2c               mov byte ptr [edx + 0x2c], bl
// 006ad90c  50                   push eax
// 006ad90d  8bcd                 mov ecx, ebp
// 006ad90f  c6402c00             mov byte ptr [eax + 0x2c], 0
// 006ad913  e878f7ffff           call 0x6ad090
// 006ad918  8b4608               mov eax, dword ptr [esi + 8]
// 006ad91b  8a4e2c               mov cl, byte ptr [esi + 0x2c]
// 006ad91e  88482c               mov byte ptr [eax + 0x2c], cl
// 006ad921  885e2c               mov byte ptr [esi + 0x2c], bl
// 006ad924  8b5008               mov edx, dword ptr [eax + 8]
// 006ad927  56                   push esi
// 006ad928  8bcd                 mov ecx, ebp
// 006ad92a  885a2c               mov byte ptr [edx + 0x2c], bl
// 006ad92d  e84ed0dcff           call 0x47a980
// 006ad932  eb74                 jmp 0x6ad9a8
// 006ad934  80782c00             cmp byte ptr [eax + 0x2c], 0
// 006ad938  7511                 jne 0x6ad94b
// 006ad93a  88582c               mov byte ptr [eax + 0x2c], bl
// 006ad93d  56                   push esi
// 006ad93e  8bcd                 mov ecx, ebp
// 006ad940  c6462c00             mov byte ptr [esi + 0x2c], 0
// 006ad944  e847f7ffff           call 0x6ad090
// 006ad949  8b06                 mov eax, dword ptr [esi]
// 006ad94b  80782d00             cmp byte ptr [eax + 0x2d], 0
// 006ad94f  7513                 jne 0x6ad964
// 006ad951  8b4808               mov ecx, dword ptr [eax + 8]
// 006ad954  38592c               cmp byte ptr [ecx + 0x2c], bl
// 006ad957  751e                 jne 0x6ad977
// 006ad959  8b10                 mov edx, dword ptr [eax]
// 006ad95b  385a2c               cmp byte ptr [edx + 0x2c], bl
// 006ad95e  7517                 jne 0x6ad977
// 006ad960  c6402c00             mov byte ptr [eax + 0x2c], 0
// 006ad964  8b4518               mov eax, dword ptr [ebp + 0x18]
// 006ad967  8bfe                 mov edi, esi
// 006ad969  8b7604               mov esi, dword ptr [esi + 4]
// 006ad96c  3b7804               cmp edi, dword ptr [eax + 4]
// 006ad96f  0f854bffffff         jne 0x6ad8c0
// 006ad975  eb31                 jmp 0x6ad9a8
// 006ad977  8b08                 mov ecx, dword ptr [eax]
// 006ad979  38592c               cmp byte ptr [ecx + 0x2c], bl
// 006ad97c  7514                 jne 0x6ad992
// 006ad97e  8b5008               mov edx, dword ptr [eax + 8]
// 006ad981  885a2c               mov byte ptr [edx + 0x2c], bl
// 006ad984  50                   push eax
// 006ad985  8bcd                 mov ecx, ebp
// 006ad987  c6402c00             mov byte ptr [eax + 0x2c], 0
// 006ad98b  e8f0cfdcff           call 0x47a980
// 006ad990  8b06                 mov eax, dword ptr [esi]
// 006ad992  8a4e2c               mov cl, byte ptr [esi + 0x2c]
// 006ad995  88482c               mov byte ptr [eax + 0x2c], cl
// 006ad998  885e2c               mov byte ptr [esi + 0x2c], bl
// 006ad99b  8b10                 mov edx, dword ptr [eax]
// 006ad99d  56                   push esi
// 006ad99e  8bcd                 mov ecx, ebp
// 006ad9a0  885a2c               mov byte ptr [edx + 0x2c], bl
// 006ad9a3  e8e8f6ffff           call 0x6ad090
// 006ad9a8  885f2c               mov byte ptr [edi + 0x2c], bl
// 006ad9ab  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006ad9af  83c110               add ecx, 0x10
// 006ad9b2  ff15e4b69800         call dword ptr [0x98b6e4]
// 006ad9b8  8b442410             mov eax, dword ptr [esp + 0x10]
// 006ad9bc  50                   push eax
// 006ad9bd  e8985e1400           call 0x7f385a
// 006ad9c2  8b451c               mov eax, dword ptr [ebp + 0x1c]
// 006ad9c5  83c404               add esp, 4
// 006ad9c8  5f                   pop edi
// 006ad9c9  5e                   pop esi
// 006ad9ca  5b                   pop ebx
// 006ad9cb  85c0                 test eax, eax
// 006ad9cd  7604                 jbe 0x6ad9d3
// 006ad9cf  48                   dec eax
// 006ad9d0  89451c               mov dword ptr [ebp + 0x1c], eax
// 006ad9d3  8b4c2464             mov ecx, dword ptr [esp + 0x64]
// 006ad9d7  8b44245c             mov eax, dword ptr [esp + 0x5c]
// 006ad9db  8b5500               mov edx, dword ptr [ebp]
// 006ad9de  894804               mov dword ptr [eax + 4], ecx
// 006ad9e1  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 006ad9e5  8910                 mov dword ptr [eax], edx
// 006ad9e7  5d                   pop ebp
// 006ad9e8  64890d00000000       mov dword ptr fs:[0], ecx
// 006ad9ef  83c454               add esp, 0x54
// 006ad9f2  c20c00               ret 0xc
// standard library map_int<string> (function ?erase@?$_Tree@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@@Z)

// stl: map_int<string>
#include <string>
typedef std::string E;
#include <map>
template class std::map<int, E>;
