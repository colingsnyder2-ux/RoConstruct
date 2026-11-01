// from server: 100% by auto
// roc 2007-03 004695c0  unit: seg_00460000  size: 446 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 004695c0
//
// 004695c0  83ec0c               sub esp, 0xc
// 004695c3  56                   push esi
// 004695c4  8bf1                 mov esi, ecx
// 004695c6  837e0800             cmp dword ptr [esi + 8], 0
// 004695ca  57                   push edi
// 004695cb  7521                 jne 0x4695ee
// 004695cd  8b442424             mov eax, dword ptr [esp + 0x24]
// 004695d1  8b4e04               mov ecx, dword ptr [esi + 4]
// 004695d4  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 004695d8  50                   push eax
// 004695d9  51                   push ecx
// 004695da  6a01                 push 1
// 004695dc  57                   push edi
// 004695dd  8bce                 mov ecx, esi
// 004695df  e88cd9faff           call 0x416f70
// 004695e4  8bc7                 mov eax, edi
// 004695e6  5f                   pop edi
// 004695e7  5e                   pop esi
// 004695e8  83c40c               add esp, 0xc
// 004695eb  c21000               ret 0x10
// 004695ee  8b5604               mov edx, dword ptr [esi + 4]
// 004695f1  8b3a                 mov edi, dword ptr [edx]
// 004695f3  55                   push ebp
// 004695f4  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 004695f8  85ed                 test ebp, ebp
// 004695fa  7404                 je 0x469600
// 004695fc  3bee                 cmp ebp, esi
// 004695fe  7406                 je 0x469606
// 00469600  ff1544e97700         call dword ptr [0x77e944]
// 00469606  53                   push ebx
// 00469607  8b5c2428             mov ebx, dword ptr [esp + 0x28]
// 0046960b  3bdf                 cmp ebx, edi
// 0046960d  752b                 jne 0x46963a
// 0046960f  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 00469613  8b07                 mov eax, dword ptr [edi]
// 00469615  3b430c               cmp eax, dword ptr [ebx + 0xc]
// 00469618  0f8d39010000         jge 0x469757
// 0046961e  57                   push edi
// 0046961f  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00469623  53                   push ebx
// 00469624  6a01                 push 1
// 00469626  57                   push edi
// 00469627  8bce                 mov ecx, esi
// 00469629  e842d9faff           call 0x416f70
// 0046962e  5b                   pop ebx
// 0046962f  5d                   pop ebp
// 00469630  8bc7                 mov eax, edi
// 00469632  5f                   pop edi
// 00469633  5e                   pop esi
// 00469634  83c40c               add esp, 0xc
// 00469637  c21000               ret 0x10
// 0046963a  85ed                 test ebp, ebp
// 0046963c  8b7e04               mov edi, dword ptr [esi + 4]
// 0046963f  7404                 je 0x469645
// 00469641  3bee                 cmp ebp, esi
// 00469643  7406                 je 0x46964b
// 00469645  ff1544e97700         call dword ptr [0x77e944]
// 0046964b  3bdf                 cmp ebx, edi
// 0046964d  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 00469651  752d                 jne 0x469680
// 00469653  8b4e04               mov ecx, dword ptr [esi + 4]
// 00469656  8b4108               mov eax, dword ptr [ecx + 8]
// 00469659  8b500c               mov edx, dword ptr [eax + 0xc]
// 0046965c  3b17                 cmp edx, dword ptr [edi]
// 0046965e  0f8df3000000         jge 0x469757
// 00469664  57                   push edi
// 00469665  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00469669  50                   push eax
// 0046966a  6a00                 push 0
// 0046966c  57                   push edi
// 0046966d  8bce                 mov ecx, esi
// 0046966f  e8fcd8faff           call 0x416f70
// 00469674  5b                   pop ebx
// 00469675  5d                   pop ebp
// 00469676  8bc7                 mov eax, edi
// 00469678  5f                   pop edi
// 00469679  5e                   pop esi
// 0046967a  83c40c               add esp, 0xc
// 0046967d  c21000               ret 0x10
// 00469680  8b07                 mov eax, dword ptr [edi]
// 00469682  39430c               cmp dword ptr [ebx + 0xc], eax
// 00469685  7e5b                 jle 0x4696e2
// 00469687  8d4c2424             lea ecx, [esp + 0x24]
// 0046968b  896c2424             mov dword ptr [esp + 0x24], ebp
// 0046968f  895c2428             mov dword ptr [esp + 0x28], ebx
// 00469693  e8e8640c00           call 0x52fb80
// 00469698  8b07                 mov eax, dword ptr [edi]
// 0046969a  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0046969e  39410c               cmp dword ptr [ecx + 0xc], eax
// 004696a1  7d3c                 jge 0x4696df
// 004696a3  8b4108               mov eax, dword ptr [ecx + 8]
// 004696a6  80781500             cmp byte ptr [eax + 0x15], 0
// 004696aa  57                   push edi
// 004696ab  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 004696af  7417                 je 0x4696c8
// 004696b1  51                   push ecx
// 004696b2  6a00                 push 0
// 004696b4  57                   push edi
// 004696b5  8bce                 mov ecx, esi
// 004696b7  e8b4d8faff           call 0x416f70
// 004696bc  5b                   pop ebx
// 004696bd  5d                   pop ebp
// 004696be  8bc7                 mov eax, edi
// 004696c0  5f                   pop edi
// 004696c1  5e                   pop esi
// 004696c2  83c40c               add esp, 0xc
// 004696c5  c21000               ret 0x10
// 004696c8  53                   push ebx
// 004696c9  6a01                 push 1
// 004696cb  57                   push edi
// 004696cc  8bce                 mov ecx, esi
// 004696ce  e89dd8faff           call 0x416f70
// 004696d3  5b                   pop ebx
// 004696d4  5d                   pop ebp
// 004696d5  8bc7                 mov eax, edi
// 004696d7  5f                   pop edi
// 004696d8  5e                   pop esi
// 004696d9  83c40c               add esp, 0xc
// 004696dc  c21000               ret 0x10
// 004696df  39430c               cmp dword ptr [ebx + 0xc], eax
// 004696e2  7d73                 jge 0x469757
// 004696e4  8b4e04               mov ecx, dword ptr [esi + 4]
// 004696e7  894c2414             mov dword ptr [esp + 0x14], ecx
// 004696eb  8d4c2424             lea ecx, [esp + 0x24]
// 004696ef  896c2424             mov dword ptr [esp + 0x24], ebp
// 004696f3  895c2428             mov dword ptr [esp + 0x28], ebx
// 004696f7  89742410             mov dword ptr [esp + 0x10], esi
// 004696fb  e8d0c61400           call 0x5b5dd0
// 00469700  8d542410             lea edx, [esp + 0x10]
// 00469704  52                   push edx
// 00469705  8d4c2428             lea ecx, [esp + 0x28]
// 00469709  e85225feff           call 0x44bc60
// 0046970e  84c0                 test al, al
// 00469710  8b442428             mov eax, dword ptr [esp + 0x28]
// 00469714  7507                 jne 0x46971d
// 00469716  8b0f                 mov ecx, dword ptr [edi]
// 00469718  3b480c               cmp ecx, dword ptr [eax + 0xc]
// 0046971b  7d3a                 jge 0x469757
// 0046971d  8b5308               mov edx, dword ptr [ebx + 8]
// 00469720  807a1500             cmp byte ptr [edx + 0x15], 0
// 00469724  57                   push edi
// 00469725  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00469729  8bce                 mov ecx, esi
// 0046972b  7415                 je 0x469742
// 0046972d  53                   push ebx
// 0046972e  6a00                 push 0
// 00469730  57                   push edi
// 00469731  e83ad8faff           call 0x416f70
// 00469736  5b                   pop ebx
// 00469737  5d                   pop ebp
// 00469738  8bc7                 mov eax, edi
// 0046973a  5f                   pop edi
// 0046973b  5e                   pop esi
// 0046973c  83c40c               add esp, 0xc
// 0046973f  c21000               ret 0x10
// 00469742  50                   push eax
// 00469743  6a01                 push 1
// 00469745  57                   push edi
// 00469746  e825d8faff           call 0x416f70
// 0046974b  5b                   pop ebx
// 0046974c  5d                   pop ebp
// 0046974d  8bc7                 mov eax, edi
// 0046974f  5f                   pop edi
// 00469750  5e                   pop esi
// 00469751  83c40c               add esp, 0xc
// 00469754  c21000               ret 0x10
// 00469757  57                   push edi
// 00469758  8d442414             lea eax, [esp + 0x14]
// 0046975c  50                   push eax
// 0046975d  8bce                 mov ecx, esi
// 0046975f  e89cfdffff           call 0x469500
// 00469764  8b10                 mov edx, dword ptr [eax]
// 00469766  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0046976a  5b                   pop ebx
// 0046976b  5d                   pop ebp
// 0046976c  8911                 mov dword ptr [ecx], edx
// 0046976e  8b4004               mov eax, dword ptr [eax + 4]
// 00469771  5f                   pop edi
// 00469772  894104               mov dword ptr [ecx + 4], eax
// 00469775  8bc1                 mov eax, ecx
// 00469777  5e                   pop esi
// 00469778  83c40c               add esp, 0xc
// 0046977b  c21000               ret 0x10
// standard library map_int<ptr> (function ?insert@?$_Tree@V?$_Tmap_traits@HPAUT@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHPAUT@@@std@@@3@$0A@@std@@@std@@QAE?AViterator@12@V312@ABU?$pair@$$CBHPAUT@@@2@@Z)

// stl: map_int<ptr>
struct T; typedef T* E;
#include <map>
template class std::map<int, E>;
