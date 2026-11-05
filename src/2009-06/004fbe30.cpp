// from server: 100% by auto
// roc 2009-06 004fbe30  unit: RBX::Network::ServerReplicator  size: 725 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004fbe30
//
// 004fbe30  64a100000000         mov eax, dword ptr fs:[0]
// 004fbe36  6aff                 push -1
// 004fbe38  68b2db8500           push 0x85dbb2
// 004fbe3d  50                   push eax
// 004fbe3e  64892500000000       mov dword ptr fs:[0], esp
// 004fbe45  8b442418             mov eax, dword ptr [esp + 0x18]
// 004fbe49  83ec48               sub esp, 0x48
// 004fbe4c  80783900             cmp byte ptr [eax + 0x39], 0
// 004fbe50  55                   push ebp
// 004fbe51  8be9                 mov ebp, ecx
// 004fbe53  7459                 je 0x4fbeae
// 004fbe55  68a4c98a00           push 0x8ac9a4
// 004fbe5a  8d4c240c             lea ecx, [esp + 0xc]
// 004fbe5e  ff15b4e48900         call dword ptr [0x89e4b4]
// 004fbe64  8d4c2424             lea ecx, [esp + 0x24]
// 004fbe68  c744245400000000     mov dword ptr [esp + 0x54], 0
// 004fbe70  ff15b8e98900         call dword ptr [0x89e9b8]
// 004fbe76  8d442408             lea eax, [esp + 8]
// 004fbe7a  50                   push eax
// 004fbe7b  8d4c2434             lea ecx, [esp + 0x34]
// 004fbe7f  c644245801           mov byte ptr [esp + 0x58], 1
// 004fbe84  c744242844c98a00     mov dword ptr [esp + 0x28], 0x8ac944
// 004fbe8c  ff15b8e48900         call dword ptr [0x89e4b8]
// 004fbe92  68dc919700           push 0x9791dc
// 004fbe97  8d4c2428             lea ecx, [esp + 0x28]
// 004fbe9b  51                   push ecx
// 004fbe9c  c644245c00           mov byte ptr [esp + 0x5c], 0
// 004fbea1  c744242c5cc98a00     mov dword ptr [esp + 0x2c], 0x8ac95c
// 004fbea9  e89cdb2100           call 0x719a4a
// 004fbeae  53                   push ebx
// 004fbeaf  56                   push esi
// 004fbeb0  8bd8                 mov ebx, eax
// 004fbeb2  57                   push edi
// 004fbeb3  8d4c246c             lea ecx, [esp + 0x6c]
// 004fbeb7  895c2410             mov dword ptr [esp + 0x10], ebx
// 004fbebb  e880faffff           call 0x4fb940
// 004fbec0  8b0b                 mov ecx, dword ptr [ebx]
// 004fbec2  80793900             cmp byte ptr [ecx + 0x39], 0
// 004fbec6  7405                 je 0x4fbecd
// 004fbec8  8b7b08               mov edi, dword ptr [ebx + 8]
// 004fbecb  eb1b                 jmp 0x4fbee8
// 004fbecd  8b5308               mov edx, dword ptr [ebx + 8]
// 004fbed0  807a3900             cmp byte ptr [edx + 0x39], 0
// 004fbed4  7404                 je 0x4fbeda
// 004fbed6  8bf9                 mov edi, ecx
// 004fbed8  eb0e                 jmp 0x4fbee8
// 004fbeda  8b442470             mov eax, dword ptr [esp + 0x70]
// 004fbede  8b7808               mov edi, dword ptr [eax + 8]
// 004fbee1  8d5008               lea edx, [eax + 8]
// 004fbee4  3bc3                 cmp eax, ebx
// 004fbee6  756b                 jne 0x4fbf53
// 004fbee8  807f3900             cmp byte ptr [edi + 0x39], 0
// 004fbeec  8b7304               mov esi, dword ptr [ebx + 4]
// 004fbeef  7503                 jne 0x4fbef4
// 004fbef1  897704               mov dword ptr [edi + 4], esi
// 004fbef4  8b4518               mov eax, dword ptr [ebp + 0x18]
// 004fbef7  395804               cmp dword ptr [eax + 4], ebx
// 004fbefa  7505                 jne 0x4fbf01
// 004fbefc  897804               mov dword ptr [eax + 4], edi
// 004fbeff  eb0b                 jmp 0x4fbf0c
// 004fbf01  391e                 cmp dword ptr [esi], ebx
// 004fbf03  7504                 jne 0x4fbf09
// 004fbf05  893e                 mov dword ptr [esi], edi
// 004fbf07  eb03                 jmp 0x4fbf0c
// 004fbf09  897e08               mov dword ptr [esi + 8], edi
// 004fbf0c  8b5d18               mov ebx, dword ptr [ebp + 0x18]
// 004fbf0f  8b03                 mov eax, dword ptr [ebx]
// 004fbf11  3b442410             cmp eax, dword ptr [esp + 0x10]
// 004fbf15  7515                 jne 0x4fbf2c
// 004fbf17  807f3900             cmp byte ptr [edi + 0x39], 0
// 004fbf1b  7404                 je 0x4fbf21
// 004fbf1d  8bc6                 mov eax, esi
// 004fbf1f  eb09                 jmp 0x4fbf2a
// 004fbf21  57                   push edi
// 004fbf22  e8c9f9ffff           call 0x4fb8f0
// 004fbf27  83c404               add esp, 4
// 004fbf2a  8903                 mov dword ptr [ebx], eax
// 004fbf2c  8b5d18               mov ebx, dword ptr [ebp + 0x18]
// 004fbf2f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004fbf33  394b08               cmp dword ptr [ebx + 8], ecx
// 004fbf36  7577                 jne 0x4fbfaf
// 004fbf38  807f3900             cmp byte ptr [edi + 0x39], 0
// 004fbf3c  7407                 je 0x4fbf45
// 004fbf3e  8bc6                 mov eax, esi
// 004fbf40  894308               mov dword ptr [ebx + 8], eax
// 004fbf43  eb6a                 jmp 0x4fbfaf
// 004fbf45  57                   push edi
// 004fbf46  e8c5f9ffff           call 0x4fb910
// 004fbf4b  83c404               add esp, 4
// 004fbf4e  894308               mov dword ptr [ebx + 8], eax
// 004fbf51  eb5c                 jmp 0x4fbfaf
// 004fbf53  894104               mov dword ptr [ecx + 4], eax
// 004fbf56  8b0b                 mov ecx, dword ptr [ebx]
// 004fbf58  8908                 mov dword ptr [eax], ecx
// 004fbf5a  3b4308               cmp eax, dword ptr [ebx + 8]
// 004fbf5d  7504                 jne 0x4fbf63
// 004fbf5f  8bf0                 mov esi, eax
// 004fbf61  eb19                 jmp 0x4fbf7c
// 004fbf63  807f3900             cmp byte ptr [edi + 0x39], 0
// 004fbf67  8b7004               mov esi, dword ptr [eax + 4]
// 004fbf6a  7503                 jne 0x4fbf6f
// 004fbf6c  897704               mov dword ptr [edi + 4], esi
// 004fbf6f  893e                 mov dword ptr [esi], edi
// 004fbf71  8b4b08               mov ecx, dword ptr [ebx + 8]
// 004fbf74  890a                 mov dword ptr [edx], ecx
// 004fbf76  8b5308               mov edx, dword ptr [ebx + 8]
// 004fbf79  894204               mov dword ptr [edx + 4], eax
// 004fbf7c  8b4d18               mov ecx, dword ptr [ebp + 0x18]
// 004fbf7f  395904               cmp dword ptr [ecx + 4], ebx
// 004fbf82  7505                 jne 0x4fbf89
// 004fbf84  894104               mov dword ptr [ecx + 4], eax
// 004fbf87  eb0e                 jmp 0x4fbf97
// 004fbf89  8b4b04               mov ecx, dword ptr [ebx + 4]
// 004fbf8c  3919                 cmp dword ptr [ecx], ebx
// 004fbf8e  7504                 jne 0x4fbf94
// 004fbf90  8901                 mov dword ptr [ecx], eax
// 004fbf92  eb03                 jmp 0x4fbf97
// 004fbf94  894108               mov dword ptr [ecx + 8], eax
// 004fbf97  8b4b04               mov ecx, dword ptr [ebx + 4]
// 004fbf9a  894804               mov dword ptr [eax + 4], ecx
// 004fbf9d  8d4b38               lea ecx, [ebx + 0x38]
// 004fbfa0  83c038               add eax, 0x38
// 004fbfa3  3bc1                 cmp eax, ecx
// 004fbfa5  7408                 je 0x4fbfaf
// 004fbfa7  8a19                 mov bl, byte ptr [ecx]
// 004fbfa9  8a10                 mov dl, byte ptr [eax]
// 004fbfab  8818                 mov byte ptr [eax], bl
// 004fbfad  8811                 mov byte ptr [ecx], dl
// 004fbfaf  8b542410             mov edx, dword ptr [esp + 0x10]
// 004fbfb3  b301                 mov bl, 1
// 004fbfb5  385a38               cmp byte ptr [edx + 0x38], bl
// 004fbfb8  0f85fd000000         jne 0x4fc0bb
// 004fbfbe  8b4518               mov eax, dword ptr [ebp + 0x18]
// 004fbfc1  3b7804               cmp edi, dword ptr [eax + 4]
// 004fbfc4  0f84ee000000         je 0x4fc0b8
// 004fbfca  8d9b00000000         lea ebx, [ebx]
// 004fbfd0  385f38               cmp byte ptr [edi + 0x38], bl
// 004fbfd3  0f85df000000         jne 0x4fc0b8
// 004fbfd9  8b06                 mov eax, dword ptr [esi]
// 004fbfdb  3bf8                 cmp edi, eax
// 004fbfdd  7565                 jne 0x4fc044
// 004fbfdf  8b4608               mov eax, dword ptr [esi + 8]
// 004fbfe2  80783800             cmp byte ptr [eax + 0x38], 0
// 004fbfe6  7512                 jne 0x4fbffa
// 004fbfe8  885838               mov byte ptr [eax + 0x38], bl
// 004fbfeb  56                   push esi
// 004fbfec  8bcd                 mov ecx, ebp
// 004fbfee  c6463800             mov byte ptr [esi + 0x38], 0
// 004fbff2  e809faffff           call 0x4fba00
// 004fbff7  8b4608               mov eax, dword ptr [esi + 8]
// 004fbffa  80783900             cmp byte ptr [eax + 0x39], 0
// 004fbffe  7574                 jne 0x4fc074
// 004fc000  8b08                 mov ecx, dword ptr [eax]
// 004fc002  385938               cmp byte ptr [ecx + 0x38], bl
// 004fc005  7508                 jne 0x4fc00f
// 004fc007  8b5008               mov edx, dword ptr [eax + 8]
// 004fc00a  385a38               cmp byte ptr [edx + 0x38], bl
// 004fc00d  7461                 je 0x4fc070
// 004fc00f  8b4808               mov ecx, dword ptr [eax + 8]
// 004fc012  385938               cmp byte ptr [ecx + 0x38], bl
// 004fc015  7514                 jne 0x4fc02b
// 004fc017  8b10                 mov edx, dword ptr [eax]
// 004fc019  885a38               mov byte ptr [edx + 0x38], bl
// 004fc01c  50                   push eax
// 004fc01d  8bcd                 mov ecx, ebp
// 004fc01f  c6403800             mov byte ptr [eax + 0x38], 0
// 004fc023  e828faffff           call 0x4fba50
// 004fc028  8b4608               mov eax, dword ptr [esi + 8]
// 004fc02b  8a4e38               mov cl, byte ptr [esi + 0x38]
// 004fc02e  884838               mov byte ptr [eax + 0x38], cl
// 004fc031  885e38               mov byte ptr [esi + 0x38], bl
// 004fc034  8b5008               mov edx, dword ptr [eax + 8]
// 004fc037  56                   push esi
// 004fc038  8bcd                 mov ecx, ebp
// 004fc03a  885a38               mov byte ptr [edx + 0x38], bl
// 004fc03d  e8bef9ffff           call 0x4fba00
// 004fc042  eb74                 jmp 0x4fc0b8
// 004fc044  80783800             cmp byte ptr [eax + 0x38], 0
// 004fc048  7511                 jne 0x4fc05b
// 004fc04a  885838               mov byte ptr [eax + 0x38], bl
// 004fc04d  56                   push esi
// 004fc04e  8bcd                 mov ecx, ebp
// 004fc050  c6463800             mov byte ptr [esi + 0x38], 0
// 004fc054  e8f7f9ffff           call 0x4fba50
// 004fc059  8b06                 mov eax, dword ptr [esi]
// 004fc05b  80783900             cmp byte ptr [eax + 0x39], 0
// 004fc05f  7513                 jne 0x4fc074
// 004fc061  8b4808               mov ecx, dword ptr [eax + 8]
// 004fc064  385938               cmp byte ptr [ecx + 0x38], bl
// 004fc067  751e                 jne 0x4fc087
// 004fc069  8b10                 mov edx, dword ptr [eax]
// 004fc06b  385a38               cmp byte ptr [edx + 0x38], bl
// 004fc06e  7517                 jne 0x4fc087
// 004fc070  c6403800             mov byte ptr [eax + 0x38], 0
// 004fc074  8b4518               mov eax, dword ptr [ebp + 0x18]
// 004fc077  8bfe                 mov edi, esi
// 004fc079  8b7604               mov esi, dword ptr [esi + 4]
// 004fc07c  3b7804               cmp edi, dword ptr [eax + 4]
// 004fc07f  0f854bffffff         jne 0x4fbfd0
// 004fc085  eb31                 jmp 0x4fc0b8
// 004fc087  8b08                 mov ecx, dword ptr [eax]
// 004fc089  385938               cmp byte ptr [ecx + 0x38], bl
// 004fc08c  7514                 jne 0x4fc0a2
// 004fc08e  8b5008               mov edx, dword ptr [eax + 8]
// 004fc091  885a38               mov byte ptr [edx + 0x38], bl
// 004fc094  50                   push eax
// 004fc095  8bcd                 mov ecx, ebp
// 004fc097  c6403800             mov byte ptr [eax + 0x38], 0
// 004fc09b  e860f9ffff           call 0x4fba00
// 004fc0a0  8b06                 mov eax, dword ptr [esi]
// 004fc0a2  8a4e38               mov cl, byte ptr [esi + 0x38]
// 004fc0a5  884838               mov byte ptr [eax + 0x38], cl
// 004fc0a8  885e38               mov byte ptr [esi + 0x38], bl
// 004fc0ab  8b10                 mov edx, dword ptr [eax]
// 004fc0ad  56                   push esi
// 004fc0ae  8bcd                 mov ecx, ebp
// 004fc0b0  885a38               mov byte ptr [edx + 0x38], bl
// 004fc0b3  e898f9ffff           call 0x4fba50
// 004fc0b8  885f38               mov byte ptr [edi + 0x38], bl
// 004fc0bb  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004fc0bf  83c10c               add ecx, 0xc
// 004fc0c2  ff15c4e48900         call dword ptr [0x89e4c4]
// 004fc0c8  8b442410             mov eax, dword ptr [esp + 0x10]
// 004fc0cc  50                   push eax
// 004fc0cd  e860c92100           call 0x718a32
// 004fc0d2  8b451c               mov eax, dword ptr [ebp + 0x1c]
// 004fc0d5  83c404               add esp, 4
// 004fc0d8  5f                   pop edi
// 004fc0d9  5e                   pop esi
// 004fc0da  5b                   pop ebx
// 004fc0db  85c0                 test eax, eax
// 004fc0dd  7604                 jbe 0x4fc0e3
// 004fc0df  48                   dec eax
// 004fc0e0  89451c               mov dword ptr [ebp + 0x1c], eax
// 004fc0e3  8b4c2464             mov ecx, dword ptr [esp + 0x64]
// 004fc0e7  8b44245c             mov eax, dword ptr [esp + 0x5c]
// 004fc0eb  8b5500               mov edx, dword ptr [ebp]
// 004fc0ee  894804               mov dword ptr [eax + 4], ecx
// 004fc0f1  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 004fc0f5  8910                 mov dword ptr [eax], edx
// 004fc0f7  5d                   pop ebp
// 004fc0f8  64890d00000000       mov dword ptr fs:[0], ecx
// 004fc0ff  83c454               add esp, 0x54
// 004fc102  c20c00               ret 0xc
// standard library map_str<pod16> (function ?erase@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@@Z)

// stl: map_str<pod16>
struct E { int v[4]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
