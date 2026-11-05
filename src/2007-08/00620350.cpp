// from server: 100% by auto
// roc 2007-08 00620350  unit: RBX::ScoreHud  size: 518 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00620350
//
// 00620350  83ec0c               sub esp, 0xc
// 00620353  56                   push esi
// 00620354  8bf1                 mov esi, ecx
// 00620356  837e0800             cmp dword ptr [esi + 8], 0
// 0062035a  57                   push edi
// 0062035b  7521                 jne 0x62037e
// 0062035d  8b442424             mov eax, dword ptr [esp + 0x24]
// 00620361  8b4e04               mov ecx, dword ptr [esi + 4]
// 00620364  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 00620368  50                   push eax
// 00620369  51                   push ecx
// 0062036a  6a01                 push 1
// 0062036c  57                   push edi
// 0062036d  8bce                 mov ecx, esi
// 0062036f  e89cedffff           call 0x61f110
// 00620374  8bc7                 mov eax, edi
// 00620376  5f                   pop edi
// 00620377  5e                   pop esi
// 00620378  83c40c               add esp, 0xc
// 0062037b  c21000               ret 0x10
// 0062037e  8b5604               mov edx, dword ptr [esi + 4]
// 00620381  8b3a                 mov edi, dword ptr [edx]
// 00620383  55                   push ebp
// 00620384  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 00620388  85ed                 test ebp, ebp
// 0062038a  7404                 je 0x620390
// 0062038c  3bee                 cmp ebp, esi
// 0062038e  7406                 je 0x620396
// 00620390  ff15d8e67700         call dword ptr [0x77e6d8]
// 00620396  53                   push ebx
// 00620397  8b5c2428             mov ebx, dword ptr [esp + 0x28]
// 0062039b  3bdf                 cmp ebx, edi
// 0062039d  7536                 jne 0x6203d5
// 0062039f  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 006203a3  8d430c               lea eax, [ebx + 0xc]
// 006203a6  50                   push eax
// 006203a7  57                   push edi
// 006203a8  ff1520e67700         call dword ptr [0x77e620]
// 006203ae  83c408               add esp, 8
// 006203b1  84c0                 test al, al
// 006203b3  0f8476010000         je 0x62052f
// 006203b9  57                   push edi
// 006203ba  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 006203be  53                   push ebx
// 006203bf  6a01                 push 1
// 006203c1  57                   push edi
// 006203c2  8bce                 mov ecx, esi
// 006203c4  e847edffff           call 0x61f110
// 006203c9  5b                   pop ebx
// 006203ca  5d                   pop ebp
// 006203cb  8bc7                 mov eax, edi
// 006203cd  5f                   pop edi
// 006203ce  5e                   pop esi
// 006203cf  83c40c               add esp, 0xc
// 006203d2  c21000               ret 0x10
// 006203d5  85ed                 test ebp, ebp
// 006203d7  8b7e04               mov edi, dword ptr [esi + 4]
// 006203da  7404                 je 0x6203e0
// 006203dc  3bee                 cmp ebp, esi
// 006203de  7406                 je 0x6203e6
// 006203e0  ff15d8e67700         call dword ptr [0x77e6d8]
// 006203e6  3bdf                 cmp ebx, edi
// 006203e8  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 006203ec  753e                 jne 0x62042c
// 006203ee  8b4e04               mov ecx, dword ptr [esi + 4]
// 006203f1  8b4108               mov eax, dword ptr [ecx + 8]
// 006203f4  83c00c               add eax, 0xc
// 006203f7  57                   push edi
// 006203f8  50                   push eax
// 006203f9  ff1520e67700         call dword ptr [0x77e620]
// 006203ff  83c408               add esp, 8
// 00620402  84c0                 test al, al
// 00620404  0f8425010000         je 0x62052f
// 0062040a  8b5604               mov edx, dword ptr [esi + 4]
// 0062040d  8b4208               mov eax, dword ptr [edx + 8]
// 00620410  57                   push edi
// 00620411  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00620415  50                   push eax
// 00620416  6a00                 push 0
// 00620418  57                   push edi
// 00620419  8bce                 mov ecx, esi
// 0062041b  e8f0ecffff           call 0x61f110
// 00620420  5b                   pop ebx
// 00620421  5d                   pop ebp
// 00620422  8bc7                 mov eax, edi
// 00620424  5f                   pop edi
// 00620425  5e                   pop esi
// 00620426  83c40c               add esp, 0xc
// 00620429  c21000               ret 0x10
// 0062042c  8d430c               lea eax, [ebx + 0xc]
// 0062042f  50                   push eax
// 00620430  57                   push edi
// 00620431  ff1520e67700         call dword ptr [0x77e620]
// 00620437  83c408               add esp, 8
// 0062043a  84c0                 test al, al
// 0062043c  7463                 je 0x6204a1
// 0062043e  8d4c2424             lea ecx, [esp + 0x24]
// 00620442  896c2424             mov dword ptr [esp + 0x24], ebp
// 00620446  895c2428             mov dword ptr [esp + 0x28], ebx
// 0062044a  e801d6ffff           call 0x61da50
// 0062044f  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00620453  83c10c               add ecx, 0xc
// 00620456  57                   push edi
// 00620457  51                   push ecx
// 00620458  8bce                 mov ecx, esi
// 0062045a  e8a149e2ff           call 0x444e00
// 0062045f  84c0                 test al, al
// 00620461  743e                 je 0x6204a1
// 00620463  8b442428             mov eax, dword ptr [esp + 0x28]
// 00620467  8b5008               mov edx, dword ptr [eax + 8]
// 0062046a  807a3500             cmp byte ptr [edx + 0x35], 0
// 0062046e  57                   push edi
// 0062046f  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00620473  8bce                 mov ecx, esi
// 00620475  7415                 je 0x62048c
// 00620477  50                   push eax
// 00620478  6a00                 push 0
// 0062047a  57                   push edi
// 0062047b  e890ecffff           call 0x61f110
// 00620480  5b                   pop ebx
// 00620481  5d                   pop ebp
// 00620482  8bc7                 mov eax, edi
// 00620484  5f                   pop edi
// 00620485  5e                   pop esi
// 00620486  83c40c               add esp, 0xc
// 00620489  c21000               ret 0x10
// 0062048c  53                   push ebx
// 0062048d  6a01                 push 1
// 0062048f  57                   push edi
// 00620490  e87becffff           call 0x61f110
// 00620495  5b                   pop ebx
// 00620496  5d                   pop ebp
// 00620497  8bc7                 mov eax, edi
// 00620499  5f                   pop edi
// 0062049a  5e                   pop esi
// 0062049b  83c40c               add esp, 0xc
// 0062049e  c21000               ret 0x10
// 006204a1  8d430c               lea eax, [ebx + 0xc]
// 006204a4  57                   push edi
// 006204a5  50                   push eax
// 006204a6  ff1520e67700         call dword ptr [0x77e620]
// 006204ac  83c408               add esp, 8
// 006204af  84c0                 test al, al
// 006204b1  747c                 je 0x62052f
// 006204b3  8b4604               mov eax, dword ptr [esi + 4]
// 006204b6  8d4c2424             lea ecx, [esp + 0x24]
// 006204ba  896c2424             mov dword ptr [esp + 0x24], ebp
// 006204be  895c2428             mov dword ptr [esp + 0x28], ebx
// 006204c2  89442414             mov dword ptr [esp + 0x14], eax
// 006204c6  89742410             mov dword ptr [esp + 0x10], esi
// 006204ca  e81176f6ff           call 0x587ae0
// 006204cf  8d4c2410             lea ecx, [esp + 0x10]
// 006204d3  51                   push ecx
// 006204d4  8d4c2428             lea ecx, [esp + 0x28]
// 006204d8  e8d365e4ff           call 0x466ab0
// 006204dd  84c0                 test al, al
// 006204df  8b6c2428             mov ebp, dword ptr [esp + 0x28]
// 006204e3  7510                 jne 0x6204f5
// 006204e5  8d550c               lea edx, [ebp + 0xc]
// 006204e8  52                   push edx
// 006204e9  57                   push edi
// 006204ea  8bce                 mov ecx, esi
// 006204ec  e80f49e2ff           call 0x444e00
// 006204f1  84c0                 test al, al
// 006204f3  743a                 je 0x62052f
// 006204f5  8b4308               mov eax, dword ptr [ebx + 8]
// 006204f8  80783500             cmp byte ptr [eax + 0x35], 0
// 006204fc  57                   push edi
// 006204fd  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00620501  8bce                 mov ecx, esi
// 00620503  7415                 je 0x62051a
// 00620505  53                   push ebx
// 00620506  6a00                 push 0
// 00620508  57                   push edi
// 00620509  e802ecffff           call 0x61f110
// 0062050e  5b                   pop ebx
// 0062050f  5d                   pop ebp
// 00620510  8bc7                 mov eax, edi
// 00620512  5f                   pop edi
// 00620513  5e                   pop esi
// 00620514  83c40c               add esp, 0xc
// 00620517  c21000               ret 0x10
// 0062051a  55                   push ebp
// 0062051b  6a01                 push 1
// 0062051d  57                   push edi
// 0062051e  e8edebffff           call 0x61f110
// 00620523  5b                   pop ebx
// 00620524  5d                   pop ebp
// 00620525  8bc7                 mov eax, edi
// 00620527  5f                   pop edi
// 00620528  5e                   pop esi
// 00620529  83c40c               add esp, 0xc
// 0062052c  c21000               ret 0x10
// 0062052f  57                   push edi
// 00620530  8d4c2414             lea ecx, [esp + 0x14]
// 00620534  51                   push ecx
// 00620535  8bce                 mov ecx, esi
// 00620537  e8b4f4ffff           call 0x61f9f0
// 0062053c  8b10                 mov edx, dword ptr [eax]
// 0062053e  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00620542  5b                   pop ebx
// 00620543  5d                   pop ebp
// 00620544  8911                 mov dword ptr [ecx], edx
// 00620546  8b4004               mov eax, dword ptr [eax + 4]
// 00620549  5f                   pop edi
// 0062054a  894104               mov dword ptr [ecx + 4], eax
// 0062054d  8bc1                 mov eax, ecx
// 0062054f  5e                   pop esi
// 00620550  83c40c               add esp, 0xc
// 00620553  c21000               ret 0x10
// standard library map_str<pod12> (function ?insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@QAE?AViterator@12@V312@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@@Z)

// stl: map_str<pod12>
struct E { int v[3]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
