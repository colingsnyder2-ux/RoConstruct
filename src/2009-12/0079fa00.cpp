// from server: 100% by auto
// roc 2009-12 0079fa00  unit: seg_00790000  size: 725 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079fa00
//
// 0079fa00  64a100000000         mov eax, dword ptr fs:[0]
// 0079fa06  6aff                 push -1
// 0079fa08  6812699500           push 0x956912
// 0079fa0d  50                   push eax
// 0079fa0e  64892500000000       mov dword ptr fs:[0], esp
// 0079fa15  8b442418             mov eax, dword ptr [esp + 0x18]
// 0079fa19  83ec48               sub esp, 0x48
// 0079fa1c  80782d00             cmp byte ptr [eax + 0x2d], 0
// 0079fa20  55                   push ebp
// 0079fa21  8be9                 mov ebp, ecx
// 0079fa23  7459                 je 0x79fa7e
// 0079fa25  68e4f49900           push 0x99f4e4
// 0079fa2a  8d4c240c             lea ecx, [esp + 0xc]
// 0079fa2e  ff15f4b69800         call dword ptr [0x98b6f4]
// 0079fa34  8d4c2424             lea ecx, [esp + 0x24]
// 0079fa38  c744245400000000     mov dword ptr [esp + 0x54], 0
// 0079fa40  ff1554b79800         call dword ptr [0x98b754]
// 0079fa46  8d442408             lea eax, [esp + 8]
// 0079fa4a  50                   push eax
// 0079fa4b  8d4c2434             lea ecx, [esp + 0x34]
// 0079fa4f  c644245801           mov byte ptr [esp + 0x58], 1
// 0079fa54  c744242884f49900     mov dword ptr [esp + 0x28], 0x99f484
// 0079fa5c  ff15f0b69800         call dword ptr [0x98b6f0]
// 0079fa62  688cefa800           push 0xa8ef8c
// 0079fa67  8d4c2428             lea ecx, [esp + 0x28]
// 0079fa6b  51                   push ecx
// 0079fa6c  c644245c00           mov byte ptr [esp + 0x5c], 0
// 0079fa71  c744242c9cf49900     mov dword ptr [esp + 0x2c], 0x99f49c
// 0079fa79  e8fa4d0500           call 0x7f4878
// 0079fa7e  53                   push ebx
// 0079fa7f  56                   push esi
// 0079fa80  8bd8                 mov ebx, eax
// 0079fa82  57                   push edi
// 0079fa83  8d4c246c             lea ecx, [esp + 0x6c]
// 0079fa87  895c2410             mov dword ptr [esp + 0x10], ebx
// 0079fa8b  e880aecdff           call 0x47a910
// 0079fa90  8b0b                 mov ecx, dword ptr [ebx]
// 0079fa92  80792d00             cmp byte ptr [ecx + 0x2d], 0
// 0079fa96  7405                 je 0x79fa9d
// 0079fa98  8b7b08               mov edi, dword ptr [ebx + 8]
// 0079fa9b  eb1b                 jmp 0x79fab8
// 0079fa9d  8b5308               mov edx, dword ptr [ebx + 8]
// 0079faa0  807a2d00             cmp byte ptr [edx + 0x2d], 0
// 0079faa4  7404                 je 0x79faaa
// 0079faa6  8bf9                 mov edi, ecx
// 0079faa8  eb0e                 jmp 0x79fab8
// 0079faaa  8b442470             mov eax, dword ptr [esp + 0x70]
// 0079faae  8b7808               mov edi, dword ptr [eax + 8]
// 0079fab1  8d5008               lea edx, [eax + 8]
// 0079fab4  3bc3                 cmp eax, ebx
// 0079fab6  756b                 jne 0x79fb23
// 0079fab8  807f2d00             cmp byte ptr [edi + 0x2d], 0
// 0079fabc  8b7304               mov esi, dword ptr [ebx + 4]
// 0079fabf  7503                 jne 0x79fac4
// 0079fac1  897704               mov dword ptr [edi + 4], esi
// 0079fac4  8b4518               mov eax, dword ptr [ebp + 0x18]
// 0079fac7  395804               cmp dword ptr [eax + 4], ebx
// 0079faca  7505                 jne 0x79fad1
// 0079facc  897804               mov dword ptr [eax + 4], edi
// 0079facf  eb0b                 jmp 0x79fadc
// 0079fad1  391e                 cmp dword ptr [esi], ebx
// 0079fad3  7504                 jne 0x79fad9
// 0079fad5  893e                 mov dword ptr [esi], edi
// 0079fad7  eb03                 jmp 0x79fadc
// 0079fad9  897e08               mov dword ptr [esi + 8], edi
// 0079fadc  8b5d18               mov ebx, dword ptr [ebp + 0x18]
// 0079fadf  8b03                 mov eax, dword ptr [ebx]
// 0079fae1  3b442410             cmp eax, dword ptr [esp + 0x10]
// 0079fae5  7515                 jne 0x79fafc
// 0079fae7  807f2d00             cmp byte ptr [edi + 0x2d], 0
// 0079faeb  7404                 je 0x79faf1
// 0079faed  8bc6                 mov eax, esi
// 0079faef  eb09                 jmp 0x79fafa
// 0079faf1  57                   push edi
// 0079faf2  e8a922e9ff           call 0x631da0
// 0079faf7  83c404               add esp, 4
// 0079fafa  8903                 mov dword ptr [ebx], eax
// 0079fafc  8b5d18               mov ebx, dword ptr [ebp + 0x18]
// 0079faff  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0079fb03  394b08               cmp dword ptr [ebx + 8], ecx
// 0079fb06  7577                 jne 0x79fb7f
// 0079fb08  807f2d00             cmp byte ptr [edi + 0x2d], 0
// 0079fb0c  7407                 je 0x79fb15
// 0079fb0e  8bc6                 mov eax, esi
// 0079fb10  894308               mov dword ptr [ebx + 8], eax
// 0079fb13  eb6a                 jmp 0x79fb7f
// 0079fb15  57                   push edi
// 0079fb16  e8856fcdff           call 0x476aa0
// 0079fb1b  83c404               add esp, 4
// 0079fb1e  894308               mov dword ptr [ebx + 8], eax
// 0079fb21  eb5c                 jmp 0x79fb7f
// 0079fb23  894104               mov dword ptr [ecx + 4], eax
// 0079fb26  8b0b                 mov ecx, dword ptr [ebx]
// 0079fb28  8908                 mov dword ptr [eax], ecx
// 0079fb2a  3b4308               cmp eax, dword ptr [ebx + 8]
// 0079fb2d  7504                 jne 0x79fb33
// 0079fb2f  8bf0                 mov esi, eax
// 0079fb31  eb19                 jmp 0x79fb4c
// 0079fb33  807f2d00             cmp byte ptr [edi + 0x2d], 0
// 0079fb37  8b7004               mov esi, dword ptr [eax + 4]
// 0079fb3a  7503                 jne 0x79fb3f
// 0079fb3c  897704               mov dword ptr [edi + 4], esi
// 0079fb3f  893e                 mov dword ptr [esi], edi
// 0079fb41  8b4b08               mov ecx, dword ptr [ebx + 8]
// 0079fb44  890a                 mov dword ptr [edx], ecx
// 0079fb46  8b5308               mov edx, dword ptr [ebx + 8]
// 0079fb49  894204               mov dword ptr [edx + 4], eax
// 0079fb4c  8b4d18               mov ecx, dword ptr [ebp + 0x18]
// 0079fb4f  395904               cmp dword ptr [ecx + 4], ebx
// 0079fb52  7505                 jne 0x79fb59
// 0079fb54  894104               mov dword ptr [ecx + 4], eax
// 0079fb57  eb0e                 jmp 0x79fb67
// 0079fb59  8b4b04               mov ecx, dword ptr [ebx + 4]
// 0079fb5c  3919                 cmp dword ptr [ecx], ebx
// 0079fb5e  7504                 jne 0x79fb64
// 0079fb60  8901                 mov dword ptr [ecx], eax
// 0079fb62  eb03                 jmp 0x79fb67
// 0079fb64  894108               mov dword ptr [ecx + 8], eax
// 0079fb67  8b4b04               mov ecx, dword ptr [ebx + 4]
// 0079fb6a  894804               mov dword ptr [eax + 4], ecx
// 0079fb6d  8d4b2c               lea ecx, [ebx + 0x2c]
// 0079fb70  83c02c               add eax, 0x2c
// 0079fb73  3bc1                 cmp eax, ecx
// 0079fb75  7408                 je 0x79fb7f
// 0079fb77  8a19                 mov bl, byte ptr [ecx]
// 0079fb79  8a10                 mov dl, byte ptr [eax]
// 0079fb7b  8818                 mov byte ptr [eax], bl
// 0079fb7d  8811                 mov byte ptr [ecx], dl
// 0079fb7f  8b542410             mov edx, dword ptr [esp + 0x10]
// 0079fb83  b301                 mov bl, 1
// 0079fb85  385a2c               cmp byte ptr [edx + 0x2c], bl
// 0079fb88  0f85fd000000         jne 0x79fc8b
// 0079fb8e  8b4518               mov eax, dword ptr [ebp + 0x18]
// 0079fb91  3b7804               cmp edi, dword ptr [eax + 4]
// 0079fb94  0f84ee000000         je 0x79fc88
// 0079fb9a  8d9b00000000         lea ebx, [ebx]
// 0079fba0  385f2c               cmp byte ptr [edi + 0x2c], bl
// 0079fba3  0f85df000000         jne 0x79fc88
// 0079fba9  8b06                 mov eax, dword ptr [esi]
// 0079fbab  3bf8                 cmp edi, eax
// 0079fbad  7565                 jne 0x79fc14
// 0079fbaf  8b4608               mov eax, dword ptr [esi + 8]
// 0079fbb2  80782c00             cmp byte ptr [eax + 0x2c], 0
// 0079fbb6  7512                 jne 0x79fbca
// 0079fbb8  88582c               mov byte ptr [eax + 0x2c], bl
// 0079fbbb  56                   push esi
// 0079fbbc  8bcd                 mov ecx, ebp
// 0079fbbe  c6462c00             mov byte ptr [esi + 0x2c], 0
// 0079fbc2  e8b9adcdff           call 0x47a980
// 0079fbc7  8b4608               mov eax, dword ptr [esi + 8]
// 0079fbca  80782d00             cmp byte ptr [eax + 0x2d], 0
// 0079fbce  7574                 jne 0x79fc44
// 0079fbd0  8b08                 mov ecx, dword ptr [eax]
// 0079fbd2  38592c               cmp byte ptr [ecx + 0x2c], bl
// 0079fbd5  7508                 jne 0x79fbdf
// 0079fbd7  8b5008               mov edx, dword ptr [eax + 8]
// 0079fbda  385a2c               cmp byte ptr [edx + 0x2c], bl
// 0079fbdd  7461                 je 0x79fc40
// 0079fbdf  8b4808               mov ecx, dword ptr [eax + 8]
// 0079fbe2  38592c               cmp byte ptr [ecx + 0x2c], bl
// 0079fbe5  7514                 jne 0x79fbfb
// 0079fbe7  8b10                 mov edx, dword ptr [eax]
// 0079fbe9  885a2c               mov byte ptr [edx + 0x2c], bl
// 0079fbec  50                   push eax
// 0079fbed  8bcd                 mov ecx, ebp
// 0079fbef  c6402c00             mov byte ptr [eax + 0x2c], 0
// 0079fbf3  e898d4f0ff           call 0x6ad090
// 0079fbf8  8b4608               mov eax, dword ptr [esi + 8]
// 0079fbfb  8a4e2c               mov cl, byte ptr [esi + 0x2c]
// 0079fbfe  88482c               mov byte ptr [eax + 0x2c], cl
// 0079fc01  885e2c               mov byte ptr [esi + 0x2c], bl
// 0079fc04  8b5008               mov edx, dword ptr [eax + 8]
// 0079fc07  56                   push esi
// 0079fc08  8bcd                 mov ecx, ebp
// 0079fc0a  885a2c               mov byte ptr [edx + 0x2c], bl
// 0079fc0d  e86eadcdff           call 0x47a980
// 0079fc12  eb74                 jmp 0x79fc88
// 0079fc14  80782c00             cmp byte ptr [eax + 0x2c], 0
// 0079fc18  7511                 jne 0x79fc2b
// 0079fc1a  88582c               mov byte ptr [eax + 0x2c], bl
// 0079fc1d  56                   push esi
// 0079fc1e  8bcd                 mov ecx, ebp
// 0079fc20  c6462c00             mov byte ptr [esi + 0x2c], 0
// 0079fc24  e867d4f0ff           call 0x6ad090
// 0079fc29  8b06                 mov eax, dword ptr [esi]
// 0079fc2b  80782d00             cmp byte ptr [eax + 0x2d], 0
// 0079fc2f  7513                 jne 0x79fc44
// 0079fc31  8b4808               mov ecx, dword ptr [eax + 8]
// 0079fc34  38592c               cmp byte ptr [ecx + 0x2c], bl
// 0079fc37  751e                 jne 0x79fc57
// 0079fc39  8b10                 mov edx, dword ptr [eax]
// 0079fc3b  385a2c               cmp byte ptr [edx + 0x2c], bl
// 0079fc3e  7517                 jne 0x79fc57
// 0079fc40  c6402c00             mov byte ptr [eax + 0x2c], 0
// 0079fc44  8b4518               mov eax, dword ptr [ebp + 0x18]
// 0079fc47  8bfe                 mov edi, esi
// 0079fc49  8b7604               mov esi, dword ptr [esi + 4]
// 0079fc4c  3b7804               cmp edi, dword ptr [eax + 4]
// 0079fc4f  0f854bffffff         jne 0x79fba0
// 0079fc55  eb31                 jmp 0x79fc88
// 0079fc57  8b08                 mov ecx, dword ptr [eax]
// 0079fc59  38592c               cmp byte ptr [ecx + 0x2c], bl
// 0079fc5c  7514                 jne 0x79fc72
// 0079fc5e  8b5008               mov edx, dword ptr [eax + 8]
// 0079fc61  885a2c               mov byte ptr [edx + 0x2c], bl
// 0079fc64  50                   push eax
// 0079fc65  8bcd                 mov ecx, ebp
// 0079fc67  c6402c00             mov byte ptr [eax + 0x2c], 0
// 0079fc6b  e810adcdff           call 0x47a980
// 0079fc70  8b06                 mov eax, dword ptr [esi]
// 0079fc72  8a4e2c               mov cl, byte ptr [esi + 0x2c]
// 0079fc75  88482c               mov byte ptr [eax + 0x2c], cl
// 0079fc78  885e2c               mov byte ptr [esi + 0x2c], bl
// 0079fc7b  8b10                 mov edx, dword ptr [eax]
// 0079fc7d  56                   push esi
// 0079fc7e  8bcd                 mov ecx, ebp
// 0079fc80  885a2c               mov byte ptr [edx + 0x2c], bl
// 0079fc83  e808d4f0ff           call 0x6ad090
// 0079fc88  885f2c               mov byte ptr [edi + 0x2c], bl
// 0079fc8b  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0079fc8f  83c10c               add ecx, 0xc
// 0079fc92  ff15e4b69800         call dword ptr [0x98b6e4]
// 0079fc98  8b442410             mov eax, dword ptr [esp + 0x10]
// 0079fc9c  50                   push eax
// 0079fc9d  e8b83b0500           call 0x7f385a
// 0079fca2  8b451c               mov eax, dword ptr [ebp + 0x1c]
// 0079fca5  83c404               add esp, 4
// 0079fca8  5f                   pop edi
// 0079fca9  5e                   pop esi
// 0079fcaa  5b                   pop ebx
// 0079fcab  85c0                 test eax, eax
// 0079fcad  7604                 jbe 0x79fcb3
// 0079fcaf  48                   dec eax
// 0079fcb0  89451c               mov dword ptr [ebp + 0x1c], eax
// 0079fcb3  8b4c2464             mov ecx, dword ptr [esp + 0x64]
// 0079fcb7  8b44245c             mov eax, dword ptr [esp + 0x5c]
// 0079fcbb  8b5500               mov edx, dword ptr [ebp]
// 0079fcbe  894804               mov dword ptr [eax + 4], ecx
// 0079fcc1  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 0079fcc5  8910                 mov dword ptr [eax], edx
// 0079fcc7  5d                   pop ebp
// 0079fcc8  64890d00000000       mov dword ptr fs:[0], ecx
// 0079fccf  83c454               add esp, 0x54
// 0079fcd2  c20c00               ret 0xc
// standard library map_str<ptr> (function ?erase@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@@2@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@@Z)

// stl: map_str<ptr>
struct T; typedef T* E;
#include <map>
#include <string>
template class std::map<std::string, E>;
