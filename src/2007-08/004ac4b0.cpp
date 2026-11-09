// from server: 100% by auto
// roc 2007-08 004ac4b0  unit: RBX::Network::Replicator::DeleteInstanceItem  size: 446 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004ac4b0
//
// 004ac4b0  83ec0c               sub esp, 0xc
// 004ac4b3  56                   push esi
// 004ac4b4  8bf1                 mov esi, ecx
// 004ac4b6  837e0800             cmp dword ptr [esi + 8], 0
// 004ac4ba  57                   push edi
// 004ac4bb  7521                 jne 0x4ac4de
// 004ac4bd  8b442424             mov eax, dword ptr [esp + 0x24]
// 004ac4c1  8b4e04               mov ecx, dword ptr [esi + 4]
// 004ac4c4  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 004ac4c8  50                   push eax
// 004ac4c9  51                   push ecx
// 004ac4ca  6a01                 push 1
// 004ac4cc  57                   push edi
// 004ac4cd  8bce                 mov ecx, esi
// 004ac4cf  e8dcd3ffff           call 0x4a98b0
// 004ac4d4  8bc7                 mov eax, edi
// 004ac4d6  5f                   pop edi
// 004ac4d7  5e                   pop esi
// 004ac4d8  83c40c               add esp, 0xc
// 004ac4db  c21000               ret 0x10
// 004ac4de  8b5604               mov edx, dword ptr [esi + 4]
// 004ac4e1  8b3a                 mov edi, dword ptr [edx]
// 004ac4e3  55                   push ebp
// 004ac4e4  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 004ac4e8  85ed                 test ebp, ebp
// 004ac4ea  7404                 je 0x4ac4f0
// 004ac4ec  3bee                 cmp ebp, esi
// 004ac4ee  7406                 je 0x4ac4f6
// 004ac4f0  ff15d8e67700         call dword ptr [0x77e6d8]
// 004ac4f6  53                   push ebx
// 004ac4f7  8b5c2428             mov ebx, dword ptr [esp + 0x28]
// 004ac4fb  3bdf                 cmp ebx, edi
// 004ac4fd  752b                 jne 0x4ac52a
// 004ac4ff  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 004ac503  8b07                 mov eax, dword ptr [edi]
// 004ac505  3b430c               cmp eax, dword ptr [ebx + 0xc]
// 004ac508  0f8339010000         jae 0x4ac647
// 004ac50e  57                   push edi
// 004ac50f  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 004ac513  53                   push ebx
// 004ac514  6a01                 push 1
// 004ac516  57                   push edi
// 004ac517  8bce                 mov ecx, esi
// 004ac519  e892d3ffff           call 0x4a98b0
// 004ac51e  5b                   pop ebx
// 004ac51f  5d                   pop ebp
// 004ac520  8bc7                 mov eax, edi
// 004ac522  5f                   pop edi
// 004ac523  5e                   pop esi
// 004ac524  83c40c               add esp, 0xc
// 004ac527  c21000               ret 0x10
// 004ac52a  85ed                 test ebp, ebp
// 004ac52c  8b7e04               mov edi, dword ptr [esi + 4]
// 004ac52f  7404                 je 0x4ac535
// 004ac531  3bee                 cmp ebp, esi
// 004ac533  7406                 je 0x4ac53b
// 004ac535  ff15d8e67700         call dword ptr [0x77e6d8]
// 004ac53b  3bdf                 cmp ebx, edi
// 004ac53d  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 004ac541  752d                 jne 0x4ac570
// 004ac543  8b4e04               mov ecx, dword ptr [esi + 4]
// 004ac546  8b4108               mov eax, dword ptr [ecx + 8]
// 004ac549  8b500c               mov edx, dword ptr [eax + 0xc]
// 004ac54c  3b17                 cmp edx, dword ptr [edi]
// 004ac54e  0f83f3000000         jae 0x4ac647
// 004ac554  57                   push edi
// 004ac555  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 004ac559  50                   push eax
// 004ac55a  6a00                 push 0
// 004ac55c  57                   push edi
// 004ac55d  8bce                 mov ecx, esi
// 004ac55f  e84cd3ffff           call 0x4a98b0
// 004ac564  5b                   pop ebx
// 004ac565  5d                   pop ebp
// 004ac566  8bc7                 mov eax, edi
// 004ac568  5f                   pop edi
// 004ac569  5e                   pop esi
// 004ac56a  83c40c               add esp, 0xc
// 004ac56d  c21000               ret 0x10
// 004ac570  8b07                 mov eax, dword ptr [edi]
// 004ac572  39430c               cmp dword ptr [ebx + 0xc], eax
// 004ac575  765b                 jbe 0x4ac5d2
// 004ac577  8d4c2424             lea ecx, [esp + 0x24]
// 004ac57b  896c2424             mov dword ptr [esp + 0x24], ebp
// 004ac57f  895c2428             mov dword ptr [esp + 0x28], ebx
// 004ac583  e8a8b60d00           call 0x587c30
// 004ac588  8b07                 mov eax, dword ptr [edi]
// 004ac58a  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 004ac58e  39410c               cmp dword ptr [ecx + 0xc], eax
// 004ac591  733c                 jae 0x4ac5cf
// 004ac593  8b4108               mov eax, dword ptr [ecx + 8]
// 004ac596  80781900             cmp byte ptr [eax + 0x19], 0
// 004ac59a  57                   push edi
// 004ac59b  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 004ac59f  7417                 je 0x4ac5b8
// 004ac5a1  51                   push ecx
// 004ac5a2  6a00                 push 0
// 004ac5a4  57                   push edi
// 004ac5a5  8bce                 mov ecx, esi
// 004ac5a7  e804d3ffff           call 0x4a98b0
// 004ac5ac  5b                   pop ebx
// 004ac5ad  5d                   pop ebp
// 004ac5ae  8bc7                 mov eax, edi
// 004ac5b0  5f                   pop edi
// 004ac5b1  5e                   pop esi
// 004ac5b2  83c40c               add esp, 0xc
// 004ac5b5  c21000               ret 0x10
// 004ac5b8  53                   push ebx
// 004ac5b9  6a01                 push 1
// 004ac5bb  57                   push edi
// 004ac5bc  8bce                 mov ecx, esi
// 004ac5be  e8edd2ffff           call 0x4a98b0
// 004ac5c3  5b                   pop ebx
// 004ac5c4  5d                   pop ebp
// 004ac5c5  8bc7                 mov eax, edi
// 004ac5c7  5f                   pop edi
// 004ac5c8  5e                   pop esi
// 004ac5c9  83c40c               add esp, 0xc
// 004ac5cc  c21000               ret 0x10
// 004ac5cf  39430c               cmp dword ptr [ebx + 0xc], eax
// 004ac5d2  7373                 jae 0x4ac647
// 004ac5d4  8b4e04               mov ecx, dword ptr [esi + 4]
// 004ac5d7  894c2414             mov dword ptr [esp + 0x14], ecx
// 004ac5db  8d4c2424             lea ecx, [esp + 0x24]
// 004ac5df  896c2424             mov dword ptr [esp + 0x24], ebp
// 004ac5e3  895c2428             mov dword ptr [esp + 0x28], ebx
// 004ac5e7  89742410             mov dword ptr [esp + 0x10], esi
// 004ac5eb  e8d0b60d00           call 0x587cc0
// 004ac5f0  8d542410             lea edx, [esp + 0x10]
// 004ac5f4  52                   push edx
// 004ac5f5  8d4c2428             lea ecx, [esp + 0x28]
// 004ac5f9  e8b2a4fbff           call 0x466ab0
// 004ac5fe  84c0                 test al, al
// 004ac600  8b442428             mov eax, dword ptr [esp + 0x28]
// 004ac604  7507                 jne 0x4ac60d
// 004ac606  8b0f                 mov ecx, dword ptr [edi]
// 004ac608  3b480c               cmp ecx, dword ptr [eax + 0xc]
// 004ac60b  733a                 jae 0x4ac647
// 004ac60d  8b5308               mov edx, dword ptr [ebx + 8]
// 004ac610  807a1900             cmp byte ptr [edx + 0x19], 0
// 004ac614  57                   push edi
// 004ac615  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 004ac619  8bce                 mov ecx, esi
// 004ac61b  7415                 je 0x4ac632
// 004ac61d  53                   push ebx
// 004ac61e  6a00                 push 0
// 004ac620  57                   push edi
// 004ac621  e88ad2ffff           call 0x4a98b0
// 004ac626  5b                   pop ebx
// 004ac627  5d                   pop ebp
// 004ac628  8bc7                 mov eax, edi
// 004ac62a  5f                   pop edi
// 004ac62b  5e                   pop esi
// 004ac62c  83c40c               add esp, 0xc
// 004ac62f  c21000               ret 0x10
// 004ac632  50                   push eax
// 004ac633  6a01                 push 1
// 004ac635  57                   push edi
// 004ac636  e875d2ffff           call 0x4a98b0
// 004ac63b  5b                   pop ebx
// 004ac63c  5d                   pop ebp
// 004ac63d  8bc7                 mov eax, edi
// 004ac63f  5f                   pop edi
// 004ac640  5e                   pop esi
// 004ac641  83c40c               add esp, 0xc
// 004ac644  c21000               ret 0x10
// 004ac647  57                   push edi
// 004ac648  8d442414             lea eax, [esp + 0x14]
// 004ac64c  50                   push eax
// 004ac64d  8bce                 mov ecx, esi
// 004ac64f  e8cce9ffff           call 0x4ab020
// 004ac654  8b10                 mov edx, dword ptr [eax]
// 004ac656  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 004ac65a  5b                   pop ebx
// 004ac65b  5d                   pop ebp
// 004ac65c  8911                 mov dword ptr [ecx], edx
// 004ac65e  8b4004               mov eax, dword ptr [eax + 4]
// 004ac661  5f                   pop edi
// 004ac662  894104               mov dword ptr [ecx + 4], eax
// 004ac665  8bc1                 mov eax, ecx
// 004ac667  5e                   pop esi
// 004ac668  83c40c               add esp, 0xc
// 004ac66b  c21000               ret 0x10
// standard library map_ptr<pod8> (function ?insert@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@QAE?AViterator@12@V312@ABU?$pair@QAUK@@UE@@@2@@Z)

// stl: map_ptr<pod8>
struct E { int v[2]; };
#include <map>
struct K; template class std::map<K*, E>;
