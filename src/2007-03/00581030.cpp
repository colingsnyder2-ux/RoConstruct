// from server: 100% by auto
// roc 2007-03 00581030  unit: seg_00580000  size: 446 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00581030
//
// 00581030  83ec0c               sub esp, 0xc
// 00581033  56                   push esi
// 00581034  8bf1                 mov esi, ecx
// 00581036  837e0800             cmp dword ptr [esi + 8], 0
// 0058103a  57                   push edi
// 0058103b  7521                 jne 0x58105e
// 0058103d  8b442424             mov eax, dword ptr [esp + 0x24]
// 00581041  8b4e04               mov ecx, dword ptr [esi + 4]
// 00581044  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 00581048  50                   push eax
// 00581049  51                   push ecx
// 0058104a  6a01                 push 1
// 0058104c  57                   push edi
// 0058104d  8bce                 mov ecx, esi
// 0058104f  e87ce30600           call 0x5ef3d0
// 00581054  8bc7                 mov eax, edi
// 00581056  5f                   pop edi
// 00581057  5e                   pop esi
// 00581058  83c40c               add esp, 0xc
// 0058105b  c21000               ret 0x10
// 0058105e  8b5604               mov edx, dword ptr [esi + 4]
// 00581061  8b3a                 mov edi, dword ptr [edx]
// 00581063  55                   push ebp
// 00581064  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 00581068  85ed                 test ebp, ebp
// 0058106a  7404                 je 0x581070
// 0058106c  3bee                 cmp ebp, esi
// 0058106e  7406                 je 0x581076
// 00581070  ff1544e97700         call dword ptr [0x77e944]
// 00581076  53                   push ebx
// 00581077  8b5c2428             mov ebx, dword ptr [esp + 0x28]
// 0058107b  3bdf                 cmp ebx, edi
// 0058107d  752b                 jne 0x5810aa
// 0058107f  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 00581083  8b07                 mov eax, dword ptr [edi]
// 00581085  3b430c               cmp eax, dword ptr [ebx + 0xc]
// 00581088  0f8d39010000         jge 0x5811c7
// 0058108e  57                   push edi
// 0058108f  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00581093  53                   push ebx
// 00581094  6a01                 push 1
// 00581096  57                   push edi
// 00581097  8bce                 mov ecx, esi
// 00581099  e832e30600           call 0x5ef3d0
// 0058109e  5b                   pop ebx
// 0058109f  5d                   pop ebp
// 005810a0  8bc7                 mov eax, edi
// 005810a2  5f                   pop edi
// 005810a3  5e                   pop esi
// 005810a4  83c40c               add esp, 0xc
// 005810a7  c21000               ret 0x10
// 005810aa  85ed                 test ebp, ebp
// 005810ac  8b7e04               mov edi, dword ptr [esi + 4]
// 005810af  7404                 je 0x5810b5
// 005810b1  3bee                 cmp ebp, esi
// 005810b3  7406                 je 0x5810bb
// 005810b5  ff1544e97700         call dword ptr [0x77e944]
// 005810bb  3bdf                 cmp ebx, edi
// 005810bd  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 005810c1  752d                 jne 0x5810f0
// 005810c3  8b4e04               mov ecx, dword ptr [esi + 4]
// 005810c6  8b4108               mov eax, dword ptr [ecx + 8]
// 005810c9  8b500c               mov edx, dword ptr [eax + 0xc]
// 005810cc  3b17                 cmp edx, dword ptr [edi]
// 005810ce  0f8df3000000         jge 0x5811c7
// 005810d4  57                   push edi
// 005810d5  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 005810d9  50                   push eax
// 005810da  6a00                 push 0
// 005810dc  57                   push edi
// 005810dd  8bce                 mov ecx, esi
// 005810df  e8ece20600           call 0x5ef3d0
// 005810e4  5b                   pop ebx
// 005810e5  5d                   pop ebp
// 005810e6  8bc7                 mov eax, edi
// 005810e8  5f                   pop edi
// 005810e9  5e                   pop esi
// 005810ea  83c40c               add esp, 0xc
// 005810ed  c21000               ret 0x10
// 005810f0  8b07                 mov eax, dword ptr [edi]
// 005810f2  39430c               cmp dword ptr [ebx + 0xc], eax
// 005810f5  7e5b                 jle 0x581152
// 005810f7  8d4c2424             lea ecx, [esp + 0x24]
// 005810fb  896c2424             mov dword ptr [esp + 0x24], ebp
// 005810ff  895c2428             mov dword ptr [esp + 0x28], ebx
// 00581103  e878eafaff           call 0x52fb80
// 00581108  8b07                 mov eax, dword ptr [edi]
// 0058110a  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0058110e  39410c               cmp dword ptr [ecx + 0xc], eax
// 00581111  7d3c                 jge 0x58114f
// 00581113  8b4108               mov eax, dword ptr [ecx + 8]
// 00581116  80781500             cmp byte ptr [eax + 0x15], 0
// 0058111a  57                   push edi
// 0058111b  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 0058111f  7417                 je 0x581138
// 00581121  51                   push ecx
// 00581122  6a00                 push 0
// 00581124  57                   push edi
// 00581125  8bce                 mov ecx, esi
// 00581127  e8a4e20600           call 0x5ef3d0
// 0058112c  5b                   pop ebx
// 0058112d  5d                   pop ebp
// 0058112e  8bc7                 mov eax, edi
// 00581130  5f                   pop edi
// 00581131  5e                   pop esi
// 00581132  83c40c               add esp, 0xc
// 00581135  c21000               ret 0x10
// 00581138  53                   push ebx
// 00581139  6a01                 push 1
// 0058113b  57                   push edi
// 0058113c  8bce                 mov ecx, esi
// 0058113e  e88de20600           call 0x5ef3d0
// 00581143  5b                   pop ebx
// 00581144  5d                   pop ebp
// 00581145  8bc7                 mov eax, edi
// 00581147  5f                   pop edi
// 00581148  5e                   pop esi
// 00581149  83c40c               add esp, 0xc
// 0058114c  c21000               ret 0x10
// 0058114f  39430c               cmp dword ptr [ebx + 0xc], eax
// 00581152  7d73                 jge 0x5811c7
// 00581154  8b4e04               mov ecx, dword ptr [esi + 4]
// 00581157  894c2414             mov dword ptr [esp + 0x14], ecx
// 0058115b  8d4c2424             lea ecx, [esp + 0x24]
// 0058115f  896c2424             mov dword ptr [esp + 0x24], ebp
// 00581163  895c2428             mov dword ptr [esp + 0x28], ebx
// 00581167  89742410             mov dword ptr [esp + 0x10], esi
// 0058116b  e8604c0300           call 0x5b5dd0
// 00581170  8d542410             lea edx, [esp + 0x10]
// 00581174  52                   push edx
// 00581175  8d4c2428             lea ecx, [esp + 0x28]
// 00581179  e8e2aaecff           call 0x44bc60
// 0058117e  84c0                 test al, al
// 00581180  8b442428             mov eax, dword ptr [esp + 0x28]
// 00581184  7507                 jne 0x58118d
// 00581186  8b0f                 mov ecx, dword ptr [edi]
// 00581188  3b480c               cmp ecx, dword ptr [eax + 0xc]
// 0058118b  7d3a                 jge 0x5811c7
// 0058118d  8b5308               mov edx, dword ptr [ebx + 8]
// 00581190  807a1500             cmp byte ptr [edx + 0x15], 0
// 00581194  57                   push edi
// 00581195  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00581199  8bce                 mov ecx, esi
// 0058119b  7415                 je 0x5811b2
// 0058119d  53                   push ebx
// 0058119e  6a00                 push 0
// 005811a0  57                   push edi
// 005811a1  e82ae20600           call 0x5ef3d0
// 005811a6  5b                   pop ebx
// 005811a7  5d                   pop ebp
// 005811a8  8bc7                 mov eax, edi
// 005811aa  5f                   pop edi
// 005811ab  5e                   pop esi
// 005811ac  83c40c               add esp, 0xc
// 005811af  c21000               ret 0x10
// 005811b2  50                   push eax
// 005811b3  6a01                 push 1
// 005811b5  57                   push edi
// 005811b6  e815e20600           call 0x5ef3d0
// 005811bb  5b                   pop ebx
// 005811bc  5d                   pop ebp
// 005811bd  8bc7                 mov eax, edi
// 005811bf  5f                   pop edi
// 005811c0  5e                   pop esi
// 005811c1  83c40c               add esp, 0xc
// 005811c4  c21000               ret 0x10
// 005811c7  57                   push edi
// 005811c8  8d442414             lea eax, [esp + 0x14]
// 005811cc  50                   push eax
// 005811cd  8bce                 mov ecx, esi
// 005811cf  e87cf8ffff           call 0x580a50
// 005811d4  8b10                 mov edx, dword ptr [eax]
// 005811d6  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 005811da  5b                   pop ebx
// 005811db  5d                   pop ebp
// 005811dc  8911                 mov dword ptr [ecx], edx
// 005811de  8b4004               mov eax, dword ptr [eax + 4]
// 005811e1  5f                   pop edi
// 005811e2  894104               mov dword ptr [ecx + 4], eax
// 005811e5  8bc1                 mov eax, ecx
// 005811e7  5e                   pop esi
// 005811e8  83c40c               add esp, 0xc
// 005811eb  c21000               ret 0x10
// standard library map_int<ptr> (function ?insert@?$_Tree@V?$_Tmap_traits@HPAUT@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHPAUT@@@std@@@3@$0A@@std@@@std@@QAE?AViterator@12@V312@ABU?$pair@$$CBHPAUT@@@2@@Z)

// stl: map_int<ptr>
struct T; typedef T* E;
#include <map>
template class std::map<int, E>;
