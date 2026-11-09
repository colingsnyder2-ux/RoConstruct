// from server: 100% by auto
// roc 2007-08 00620560  unit: RBX::ScoreHud  size: 446 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00620560
//
// 00620560  83ec0c               sub esp, 0xc
// 00620563  56                   push esi
// 00620564  8bf1                 mov esi, ecx
// 00620566  837e0800             cmp dword ptr [esi + 8], 0
// 0062056a  57                   push edi
// 0062056b  7521                 jne 0x62058e
// 0062056d  8b442424             mov eax, dword ptr [esp + 0x24]
// 00620571  8b4e04               mov ecx, dword ptr [esi + 4]
// 00620574  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 00620578  50                   push eax
// 00620579  51                   push ecx
// 0062057a  6a01                 push 1
// 0062057c  57                   push edi
// 0062057d  8bce                 mov ecx, esi
// 0062057f  e88cedffff           call 0x61f310
// 00620584  8bc7                 mov eax, edi
// 00620586  5f                   pop edi
// 00620587  5e                   pop esi
// 00620588  83c40c               add esp, 0xc
// 0062058b  c21000               ret 0x10
// 0062058e  8b5604               mov edx, dword ptr [esi + 4]
// 00620591  8b3a                 mov edi, dword ptr [edx]
// 00620593  55                   push ebp
// 00620594  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 00620598  85ed                 test ebp, ebp
// 0062059a  7404                 je 0x6205a0
// 0062059c  3bee                 cmp ebp, esi
// 0062059e  7406                 je 0x6205a6
// 006205a0  ff15d8e67700         call dword ptr [0x77e6d8]
// 006205a6  53                   push ebx
// 006205a7  8b5c2428             mov ebx, dword ptr [esp + 0x28]
// 006205ab  3bdf                 cmp ebx, edi
// 006205ad  752b                 jne 0x6205da
// 006205af  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 006205b3  8b07                 mov eax, dword ptr [edi]
// 006205b5  3b430c               cmp eax, dword ptr [ebx + 0xc]
// 006205b8  0f8339010000         jae 0x6206f7
// 006205be  57                   push edi
// 006205bf  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 006205c3  53                   push ebx
// 006205c4  6a01                 push 1
// 006205c6  57                   push edi
// 006205c7  8bce                 mov ecx, esi
// 006205c9  e842edffff           call 0x61f310
// 006205ce  5b                   pop ebx
// 006205cf  5d                   pop ebp
// 006205d0  8bc7                 mov eax, edi
// 006205d2  5f                   pop edi
// 006205d3  5e                   pop esi
// 006205d4  83c40c               add esp, 0xc
// 006205d7  c21000               ret 0x10
// 006205da  85ed                 test ebp, ebp
// 006205dc  8b7e04               mov edi, dword ptr [esi + 4]
// 006205df  7404                 je 0x6205e5
// 006205e1  3bee                 cmp ebp, esi
// 006205e3  7406                 je 0x6205eb
// 006205e5  ff15d8e67700         call dword ptr [0x77e6d8]
// 006205eb  3bdf                 cmp ebx, edi
// 006205ed  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 006205f1  752d                 jne 0x620620
// 006205f3  8b4e04               mov ecx, dword ptr [esi + 4]
// 006205f6  8b4108               mov eax, dword ptr [ecx + 8]
// 006205f9  8b500c               mov edx, dword ptr [eax + 0xc]
// 006205fc  3b17                 cmp edx, dword ptr [edi]
// 006205fe  0f83f3000000         jae 0x6206f7
// 00620604  57                   push edi
// 00620605  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00620609  50                   push eax
// 0062060a  6a00                 push 0
// 0062060c  57                   push edi
// 0062060d  8bce                 mov ecx, esi
// 0062060f  e8fcecffff           call 0x61f310
// 00620614  5b                   pop ebx
// 00620615  5d                   pop ebp
// 00620616  8bc7                 mov eax, edi
// 00620618  5f                   pop edi
// 00620619  5e                   pop esi
// 0062061a  83c40c               add esp, 0xc
// 0062061d  c21000               ret 0x10
// 00620620  8b07                 mov eax, dword ptr [edi]
// 00620622  39430c               cmp dword ptr [ebx + 0xc], eax
// 00620625  765b                 jbe 0x620682
// 00620627  8d4c2424             lea ecx, [esp + 0x24]
// 0062062b  896c2424             mov dword ptr [esp + 0x24], ebp
// 0062062f  895c2428             mov dword ptr [esp + 0x28], ebx
// 00620633  e808c4feff           call 0x60ca40
// 00620638  8b07                 mov eax, dword ptr [edi]
// 0062063a  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0062063e  39410c               cmp dword ptr [ecx + 0xc], eax
// 00620641  733c                 jae 0x62067f
// 00620643  8b4108               mov eax, dword ptr [ecx + 8]
// 00620646  80781d00             cmp byte ptr [eax + 0x1d], 0
// 0062064a  57                   push edi
// 0062064b  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 0062064f  7417                 je 0x620668
// 00620651  51                   push ecx
// 00620652  6a00                 push 0
// 00620654  57                   push edi
// 00620655  8bce                 mov ecx, esi
// 00620657  e8b4ecffff           call 0x61f310
// 0062065c  5b                   pop ebx
// 0062065d  5d                   pop ebp
// 0062065e  8bc7                 mov eax, edi
// 00620660  5f                   pop edi
// 00620661  5e                   pop esi
// 00620662  83c40c               add esp, 0xc
// 00620665  c21000               ret 0x10
// 00620668  53                   push ebx
// 00620669  6a01                 push 1
// 0062066b  57                   push edi
// 0062066c  8bce                 mov ecx, esi
// 0062066e  e89decffff           call 0x61f310
// 00620673  5b                   pop ebx
// 00620674  5d                   pop ebp
// 00620675  8bc7                 mov eax, edi
// 00620677  5f                   pop edi
// 00620678  5e                   pop esi
// 00620679  83c40c               add esp, 0xc
// 0062067c  c21000               ret 0x10
// 0062067f  39430c               cmp dword ptr [ebx + 0xc], eax
// 00620682  7373                 jae 0x6206f7
// 00620684  8b4e04               mov ecx, dword ptr [esi + 4]
// 00620687  894c2414             mov dword ptr [esp + 0x14], ecx
// 0062068b  8d4c2424             lea ecx, [esp + 0x24]
// 0062068f  896c2424             mov dword ptr [esp + 0x24], ebp
// 00620693  895c2428             mov dword ptr [esp + 0x28], ebx
// 00620697  89742410             mov dword ptr [esp + 0x10], esi
// 0062069b  e8e0c6feff           call 0x60cd80
// 006206a0  8d542410             lea edx, [esp + 0x10]
// 006206a4  52                   push edx
// 006206a5  8d4c2428             lea ecx, [esp + 0x28]
// 006206a9  e80264e4ff           call 0x466ab0
// 006206ae  84c0                 test al, al
// 006206b0  8b442428             mov eax, dword ptr [esp + 0x28]
// 006206b4  7507                 jne 0x6206bd
// 006206b6  8b0f                 mov ecx, dword ptr [edi]
// 006206b8  3b480c               cmp ecx, dword ptr [eax + 0xc]
// 006206bb  733a                 jae 0x6206f7
// 006206bd  8b5308               mov edx, dword ptr [ebx + 8]
// 006206c0  807a1d00             cmp byte ptr [edx + 0x1d], 0
// 006206c4  57                   push edi
// 006206c5  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 006206c9  8bce                 mov ecx, esi
// 006206cb  7415                 je 0x6206e2
// 006206cd  53                   push ebx
// 006206ce  6a00                 push 0
// 006206d0  57                   push edi
// 006206d1  e83aecffff           call 0x61f310
// 006206d6  5b                   pop ebx
// 006206d7  5d                   pop ebp
// 006206d8  8bc7                 mov eax, edi
// 006206da  5f                   pop edi
// 006206db  5e                   pop esi
// 006206dc  83c40c               add esp, 0xc
// 006206df  c21000               ret 0x10
// 006206e2  50                   push eax
// 006206e3  6a01                 push 1
// 006206e5  57                   push edi
// 006206e6  e825ecffff           call 0x61f310
// 006206eb  5b                   pop ebx
// 006206ec  5d                   pop ebp
// 006206ed  8bc7                 mov eax, edi
// 006206ef  5f                   pop edi
// 006206f0  5e                   pop esi
// 006206f1  83c40c               add esp, 0xc
// 006206f4  c21000               ret 0x10
// 006206f7  57                   push edi
// 006206f8  8d442414             lea eax, [esp + 0x14]
// 006206fc  50                   push eax
// 006206fd  8bce                 mov ecx, esi
// 006206ff  e8ecf3ffff           call 0x61faf0
// 00620704  8b10                 mov edx, dword ptr [eax]
// 00620706  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0062070a  5b                   pop ebx
// 0062070b  5d                   pop ebp
// 0062070c  8911                 mov dword ptr [ecx], edx
// 0062070e  8b4004               mov eax, dword ptr [eax + 4]
// 00620711  5f                   pop edi
// 00620712  894104               mov dword ptr [ecx + 4], eax
// 00620715  8bc1                 mov eax, ecx
// 00620717  5e                   pop esi
// 00620718  83c40c               add esp, 0xc
// 0062071b  c21000               ret 0x10
// standard library map_ptr<pod12> (function ?insert@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@QAE?AViterator@12@V312@ABU?$pair@QAUK@@UE@@@2@@Z)

// stl: map_ptr<pod12>
struct E { int v[3]; };
#include <map>
struct K; template class std::map<K*, E>;
