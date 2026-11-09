// from server: 100% by auto
// roc 2010-06 0061b610  unit: RBX::Accoutrement  size: 725 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0061b610
//
// 0061b610  64a100000000         mov eax, dword ptr fs:[0]
// 0061b616  6aff                 push -1
// 0061b618  68e22f9a00           push 0x9a2fe2
// 0061b61d  50                   push eax
// 0061b61e  64892500000000       mov dword ptr fs:[0], esp
// 0061b625  8b442418             mov eax, dword ptr [esp + 0x18]
// 0061b629  83ec48               sub esp, 0x48
// 0061b62c  80782d00             cmp byte ptr [eax + 0x2d], 0
// 0061b630  55                   push ebp
// 0061b631  8be9                 mov ebp, ecx
// 0061b633  7459                 je 0x61b68e
// 0061b635  688c00a000           push 0xa0008c
// 0061b63a  8d4c240c             lea ecx, [esp + 0xc]
// 0061b63e  ff1510a49e00         call dword ptr [0x9ea410]
// 0061b644  8d4c2424             lea ecx, [esp + 0x24]
// 0061b648  c744245400000000     mov dword ptr [esp + 0x54], 0
// 0061b650  ff1518a99e00         call dword ptr [0x9ea918]
// 0061b656  8d442408             lea eax, [esp + 8]
// 0061b65a  50                   push eax
// 0061b65b  8d4c2434             lea ecx, [esp + 0x34]
// 0061b65f  c644245801           mov byte ptr [esp + 0x58], 1
// 0061b664  c74424282c00a000     mov dword ptr [esp + 0x28], 0xa0002c
// 0061b66c  ff150ca49e00         call dword ptr [0x9ea40c]
// 0061b672  68081bb000           push 0xb01b08
// 0061b677  8d4c2428             lea ecx, [esp + 0x28]
// 0061b67b  51                   push ecx
// 0061b67c  c644245c00           mov byte ptr [esp + 0x5c], 0
// 0061b681  c744242c4400a000     mov dword ptr [esp + 0x2c], 0xa00044
// 0061b689  e824d31800           call 0x7a89b2
// 0061b68e  53                   push ebx
// 0061b68f  56                   push esi
// 0061b690  8bd8                 mov ebx, eax
// 0061b692  57                   push edi
// 0061b693  8d4c246c             lea ecx, [esp + 0x6c]
// 0061b697  895c2410             mov dword ptr [esp + 0x10], ebx
// 0061b69b  e8a0ab2a00           call 0x8c6240
// 0061b6a0  8b0b                 mov ecx, dword ptr [ebx]
// 0061b6a2  80792d00             cmp byte ptr [ecx + 0x2d], 0
// 0061b6a6  7405                 je 0x61b6ad
// 0061b6a8  8b7b08               mov edi, dword ptr [ebx + 8]
// 0061b6ab  eb1b                 jmp 0x61b6c8
// 0061b6ad  8b5308               mov edx, dword ptr [ebx + 8]
// 0061b6b0  807a2d00             cmp byte ptr [edx + 0x2d], 0
// 0061b6b4  7404                 je 0x61b6ba
// 0061b6b6  8bf9                 mov edi, ecx
// 0061b6b8  eb0e                 jmp 0x61b6c8
// 0061b6ba  8b442470             mov eax, dword ptr [esp + 0x70]
// 0061b6be  8b7808               mov edi, dword ptr [eax + 8]
// 0061b6c1  8d5008               lea edx, [eax + 8]
// 0061b6c4  3bc3                 cmp eax, ebx
// 0061b6c6  756b                 jne 0x61b733
// 0061b6c8  807f2d00             cmp byte ptr [edi + 0x2d], 0
// 0061b6cc  8b7304               mov esi, dword ptr [ebx + 4]
// 0061b6cf  7503                 jne 0x61b6d4
// 0061b6d1  897704               mov dword ptr [edi + 4], esi
// 0061b6d4  8b4518               mov eax, dword ptr [ebp + 0x18]
// 0061b6d7  395804               cmp dword ptr [eax + 4], ebx
// 0061b6da  7505                 jne 0x61b6e1
// 0061b6dc  897804               mov dword ptr [eax + 4], edi
// 0061b6df  eb0b                 jmp 0x61b6ec
// 0061b6e1  391e                 cmp dword ptr [esi], ebx
// 0061b6e3  7504                 jne 0x61b6e9
// 0061b6e5  893e                 mov dword ptr [esi], edi
// 0061b6e7  eb03                 jmp 0x61b6ec
// 0061b6e9  897e08               mov dword ptr [esi + 8], edi
// 0061b6ec  8b5d18               mov ebx, dword ptr [ebp + 0x18]
// 0061b6ef  8b03                 mov eax, dword ptr [ebx]
// 0061b6f1  3b442410             cmp eax, dword ptr [esp + 0x10]
// 0061b6f5  7515                 jne 0x61b70c
// 0061b6f7  807f2d00             cmp byte ptr [edi + 0x2d], 0
// 0061b6fb  7404                 je 0x61b701
// 0061b6fd  8bc6                 mov eax, esi
// 0061b6ff  eb09                 jmp 0x61b70a
// 0061b701  57                   push edi
// 0061b702  e8e955e6ff           call 0x480cf0
// 0061b707  83c404               add esp, 4
// 0061b70a  8903                 mov dword ptr [ebx], eax
// 0061b70c  8b5d18               mov ebx, dword ptr [ebp + 0x18]
// 0061b70f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0061b713  394b08               cmp dword ptr [ebx + 8], ecx
// 0061b716  7577                 jne 0x61b78f
// 0061b718  807f2d00             cmp byte ptr [edi + 0x2d], 0
// 0061b71c  7407                 je 0x61b725
// 0061b71e  8bc6                 mov eax, esi
// 0061b720  894308               mov dword ptr [ebx + 8], eax
// 0061b723  eb6a                 jmp 0x61b78f
// 0061b725  57                   push edi
// 0061b726  e885e01100           call 0x7397b0
// 0061b72b  83c404               add esp, 4
// 0061b72e  894308               mov dword ptr [ebx + 8], eax
// 0061b731  eb5c                 jmp 0x61b78f
// 0061b733  894104               mov dword ptr [ecx + 4], eax
// 0061b736  8b0b                 mov ecx, dword ptr [ebx]
// 0061b738  8908                 mov dword ptr [eax], ecx
// 0061b73a  3b4308               cmp eax, dword ptr [ebx + 8]
// 0061b73d  7504                 jne 0x61b743
// 0061b73f  8bf0                 mov esi, eax
// 0061b741  eb19                 jmp 0x61b75c
// 0061b743  807f2d00             cmp byte ptr [edi + 0x2d], 0
// 0061b747  8b7004               mov esi, dword ptr [eax + 4]
// 0061b74a  7503                 jne 0x61b74f
// 0061b74c  897704               mov dword ptr [edi + 4], esi
// 0061b74f  893e                 mov dword ptr [esi], edi
// 0061b751  8b4b08               mov ecx, dword ptr [ebx + 8]
// 0061b754  890a                 mov dword ptr [edx], ecx
// 0061b756  8b5308               mov edx, dword ptr [ebx + 8]
// 0061b759  894204               mov dword ptr [edx + 4], eax
// 0061b75c  8b4d18               mov ecx, dword ptr [ebp + 0x18]
// 0061b75f  395904               cmp dword ptr [ecx + 4], ebx
// 0061b762  7505                 jne 0x61b769
// 0061b764  894104               mov dword ptr [ecx + 4], eax
// 0061b767  eb0e                 jmp 0x61b777
// 0061b769  8b4b04               mov ecx, dword ptr [ebx + 4]
// 0061b76c  3919                 cmp dword ptr [ecx], ebx
// 0061b76e  7504                 jne 0x61b774
// 0061b770  8901                 mov dword ptr [ecx], eax
// 0061b772  eb03                 jmp 0x61b777
// 0061b774  894108               mov dword ptr [ecx + 8], eax
// 0061b777  8b4b04               mov ecx, dword ptr [ebx + 4]
// 0061b77a  894804               mov dword ptr [eax + 4], ecx
// 0061b77d  8d4b2c               lea ecx, [ebx + 0x2c]
// 0061b780  83c02c               add eax, 0x2c
// 0061b783  3bc1                 cmp eax, ecx
// 0061b785  7408                 je 0x61b78f
// 0061b787  8a19                 mov bl, byte ptr [ecx]
// 0061b789  8a10                 mov dl, byte ptr [eax]
// 0061b78b  8818                 mov byte ptr [eax], bl
// 0061b78d  8811                 mov byte ptr [ecx], dl
// 0061b78f  8b542410             mov edx, dword ptr [esp + 0x10]
// 0061b793  b301                 mov bl, 1
// 0061b795  385a2c               cmp byte ptr [edx + 0x2c], bl
// 0061b798  0f85fd000000         jne 0x61b89b
// 0061b79e  8b4518               mov eax, dword ptr [ebp + 0x18]
// 0061b7a1  3b7804               cmp edi, dword ptr [eax + 4]
// 0061b7a4  0f84ee000000         je 0x61b898
// 0061b7aa  8d9b00000000         lea ebx, [ebx]
// 0061b7b0  385f2c               cmp byte ptr [edi + 0x2c], bl
// 0061b7b3  0f85df000000         jne 0x61b898
// 0061b7b9  8b06                 mov eax, dword ptr [esi]
// 0061b7bb  3bf8                 cmp edi, eax
// 0061b7bd  7565                 jne 0x61b824
// 0061b7bf  8b4608               mov eax, dword ptr [esi + 8]
// 0061b7c2  80782c00             cmp byte ptr [eax + 0x2c], 0
// 0061b7c6  7512                 jne 0x61b7da
// 0061b7c8  88582c               mov byte ptr [eax + 0x2c], bl
// 0061b7cb  56                   push esi
// 0061b7cc  8bcd                 mov ecx, ebp
// 0061b7ce  c6462c00             mov byte ptr [esi + 0x2c], 0
// 0061b7d2  e8f9df1100           call 0x7397d0
// 0061b7d7  8b4608               mov eax, dword ptr [esi + 8]
// 0061b7da  80782d00             cmp byte ptr [eax + 0x2d], 0
// 0061b7de  7574                 jne 0x61b854
// 0061b7e0  8b08                 mov ecx, dword ptr [eax]
// 0061b7e2  38592c               cmp byte ptr [ecx + 0x2c], bl
// 0061b7e5  7508                 jne 0x61b7ef
// 0061b7e7  8b5008               mov edx, dword ptr [eax + 8]
// 0061b7ea  385a2c               cmp byte ptr [edx + 0x2c], bl
// 0061b7ed  7461                 je 0x61b850
// 0061b7ef  8b4808               mov ecx, dword ptr [eax + 8]
// 0061b7f2  38592c               cmp byte ptr [ecx + 0x2c], bl
// 0061b7f5  7514                 jne 0x61b80b
// 0061b7f7  8b10                 mov edx, dword ptr [eax]
// 0061b7f9  885a2c               mov byte ptr [edx + 0x2c], bl
// 0061b7fc  50                   push eax
// 0061b7fd  8bcd                 mov ecx, ebp
// 0061b7ff  c6402c00             mov byte ptr [eax + 0x2c], 0
// 0061b803  e8b8523400           call 0x960ac0
// 0061b808  8b4608               mov eax, dword ptr [esi + 8]
// 0061b80b  8a4e2c               mov cl, byte ptr [esi + 0x2c]
// 0061b80e  88482c               mov byte ptr [eax + 0x2c], cl
// 0061b811  885e2c               mov byte ptr [esi + 0x2c], bl
// 0061b814  8b5008               mov edx, dword ptr [eax + 8]
// 0061b817  56                   push esi
// 0061b818  8bcd                 mov ecx, ebp
// 0061b81a  885a2c               mov byte ptr [edx + 0x2c], bl
// 0061b81d  e8aedf1100           call 0x7397d0
// 0061b822  eb74                 jmp 0x61b898
// 0061b824  80782c00             cmp byte ptr [eax + 0x2c], 0
// 0061b828  7511                 jne 0x61b83b
// 0061b82a  88582c               mov byte ptr [eax + 0x2c], bl
// 0061b82d  56                   push esi
// 0061b82e  8bcd                 mov ecx, ebp
// 0061b830  c6462c00             mov byte ptr [esi + 0x2c], 0
// 0061b834  e887523400           call 0x960ac0
// 0061b839  8b06                 mov eax, dword ptr [esi]
// 0061b83b  80782d00             cmp byte ptr [eax + 0x2d], 0
// 0061b83f  7513                 jne 0x61b854
// 0061b841  8b4808               mov ecx, dword ptr [eax + 8]
// 0061b844  38592c               cmp byte ptr [ecx + 0x2c], bl
// 0061b847  751e                 jne 0x61b867
// 0061b849  8b10                 mov edx, dword ptr [eax]
// 0061b84b  385a2c               cmp byte ptr [edx + 0x2c], bl
// 0061b84e  7517                 jne 0x61b867
// 0061b850  c6402c00             mov byte ptr [eax + 0x2c], 0
// 0061b854  8b4518               mov eax, dword ptr [ebp + 0x18]
// 0061b857  8bfe                 mov edi, esi
// 0061b859  8b7604               mov esi, dword ptr [esi + 4]
// 0061b85c  3b7804               cmp edi, dword ptr [eax + 4]
// 0061b85f  0f854bffffff         jne 0x61b7b0
// 0061b865  eb31                 jmp 0x61b898
// 0061b867  8b08                 mov ecx, dword ptr [eax]
// 0061b869  38592c               cmp byte ptr [ecx + 0x2c], bl
// 0061b86c  7514                 jne 0x61b882
// 0061b86e  8b5008               mov edx, dword ptr [eax + 8]
// 0061b871  885a2c               mov byte ptr [edx + 0x2c], bl
// 0061b874  50                   push eax
// 0061b875  8bcd                 mov ecx, ebp
// 0061b877  c6402c00             mov byte ptr [eax + 0x2c], 0
// 0061b87b  e850df1100           call 0x7397d0
// 0061b880  8b06                 mov eax, dword ptr [esi]
// 0061b882  8a4e2c               mov cl, byte ptr [esi + 0x2c]
// 0061b885  88482c               mov byte ptr [eax + 0x2c], cl
// 0061b888  885e2c               mov byte ptr [esi + 0x2c], bl
// 0061b88b  8b10                 mov edx, dword ptr [eax]
// 0061b88d  56                   push esi
// 0061b88e  8bcd                 mov ecx, ebp
// 0061b890  885a2c               mov byte ptr [edx + 0x2c], bl
// 0061b893  e828523400           call 0x960ac0
// 0061b898  885f2c               mov byte ptr [edi + 0x2c], bl
// 0061b89b  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0061b89f  83c110               add ecx, 0x10
// 0061b8a2  ff1500a49e00         call dword ptr [0x9ea400]
// 0061b8a8  8b442410             mov eax, dword ptr [esp + 0x10]
// 0061b8ac  50                   push eax
// 0061b8ad  e8e8c01800           call 0x7a799a
// 0061b8b2  8b451c               mov eax, dword ptr [ebp + 0x1c]
// 0061b8b5  83c404               add esp, 4
// 0061b8b8  5f                   pop edi
// 0061b8b9  5e                   pop esi
// 0061b8ba  5b                   pop ebx
// 0061b8bb  85c0                 test eax, eax
// 0061b8bd  7604                 jbe 0x61b8c3
// 0061b8bf  48                   dec eax
// 0061b8c0  89451c               mov dword ptr [ebp + 0x1c], eax
// 0061b8c3  8b4c2464             mov ecx, dword ptr [esp + 0x64]
// 0061b8c7  8b44245c             mov eax, dword ptr [esp + 0x5c]
// 0061b8cb  8b5500               mov edx, dword ptr [ebp]
// 0061b8ce  894804               mov dword ptr [eax + 4], ecx
// 0061b8d1  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 0061b8d5  8910                 mov dword ptr [eax], edx
// 0061b8d7  5d                   pop ebp
// 0061b8d8  64890d00000000       mov dword ptr fs:[0], ecx
// 0061b8df  83c454               add esp, 0x54
// 0061b8e2  c20c00               ret 0xc
// standard library map_int<string> (function ?erase@?$_Tree@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@@Z)

// stl: map_int<string>
#include <string>
typedef std::string E;
#include <map>
template class std::map<int, E>;
