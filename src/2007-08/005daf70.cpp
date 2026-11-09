// from server: 100% by auto
// roc 2007-08 005daf70  unit: RBX::VVelocityMotor::?$FactoryProduct  size: 446 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005daf70
//
// 005daf70  83ec0c               sub esp, 0xc
// 005daf73  56                   push esi
// 005daf74  8bf1                 mov esi, ecx
// 005daf76  837e0800             cmp dword ptr [esi + 8], 0
// 005daf7a  57                   push edi
// 005daf7b  7521                 jne 0x5daf9e
// 005daf7d  8b442424             mov eax, dword ptr [esp + 0x24]
// 005daf81  8b4e04               mov ecx, dword ptr [esi + 4]
// 005daf84  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 005daf88  50                   push eax
// 005daf89  51                   push ecx
// 005daf8a  6a01                 push 1
// 005daf8c  57                   push edi
// 005daf8d  8bce                 mov ecx, esi
// 005daf8f  e89c8afaff           call 0x583a30
// 005daf94  8bc7                 mov eax, edi
// 005daf96  5f                   pop edi
// 005daf97  5e                   pop esi
// 005daf98  83c40c               add esp, 0xc
// 005daf9b  c21000               ret 0x10
// 005daf9e  8b5604               mov edx, dword ptr [esi + 4]
// 005dafa1  8b3a                 mov edi, dword ptr [edx]
// 005dafa3  55                   push ebp
// 005dafa4  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 005dafa8  85ed                 test ebp, ebp
// 005dafaa  7404                 je 0x5dafb0
// 005dafac  3bee                 cmp ebp, esi
// 005dafae  7406                 je 0x5dafb6
// 005dafb0  ff15d8e67700         call dword ptr [0x77e6d8]
// 005dafb6  53                   push ebx
// 005dafb7  8b5c2428             mov ebx, dword ptr [esp + 0x28]
// 005dafbb  3bdf                 cmp ebx, edi
// 005dafbd  752b                 jne 0x5dafea
// 005dafbf  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 005dafc3  8b07                 mov eax, dword ptr [edi]
// 005dafc5  3b430c               cmp eax, dword ptr [ebx + 0xc]
// 005dafc8  0f8339010000         jae 0x5db107
// 005dafce  57                   push edi
// 005dafcf  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 005dafd3  53                   push ebx
// 005dafd4  6a01                 push 1
// 005dafd6  57                   push edi
// 005dafd7  8bce                 mov ecx, esi
// 005dafd9  e8528afaff           call 0x583a30
// 005dafde  5b                   pop ebx
// 005dafdf  5d                   pop ebp
// 005dafe0  8bc7                 mov eax, edi
// 005dafe2  5f                   pop edi
// 005dafe3  5e                   pop esi
// 005dafe4  83c40c               add esp, 0xc
// 005dafe7  c21000               ret 0x10
// 005dafea  85ed                 test ebp, ebp
// 005dafec  8b7e04               mov edi, dword ptr [esi + 4]
// 005dafef  7404                 je 0x5daff5
// 005daff1  3bee                 cmp ebp, esi
// 005daff3  7406                 je 0x5daffb
// 005daff5  ff15d8e67700         call dword ptr [0x77e6d8]
// 005daffb  3bdf                 cmp ebx, edi
// 005daffd  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 005db001  752d                 jne 0x5db030
// 005db003  8b4e04               mov ecx, dword ptr [esi + 4]
// 005db006  8b4108               mov eax, dword ptr [ecx + 8]
// 005db009  8b500c               mov edx, dword ptr [eax + 0xc]
// 005db00c  3b17                 cmp edx, dword ptr [edi]
// 005db00e  0f83f3000000         jae 0x5db107
// 005db014  57                   push edi
// 005db015  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 005db019  50                   push eax
// 005db01a  6a00                 push 0
// 005db01c  57                   push edi
// 005db01d  8bce                 mov ecx, esi
// 005db01f  e80c8afaff           call 0x583a30
// 005db024  5b                   pop ebx
// 005db025  5d                   pop ebp
// 005db026  8bc7                 mov eax, edi
// 005db028  5f                   pop edi
// 005db029  5e                   pop esi
// 005db02a  83c40c               add esp, 0xc
// 005db02d  c21000               ret 0x10
// 005db030  8b07                 mov eax, dword ptr [edi]
// 005db032  39430c               cmp dword ptr [ebx + 0xc], eax
// 005db035  765b                 jbe 0x5db092
// 005db037  8d4c2424             lea ecx, [esp + 0x24]
// 005db03b  896c2424             mov dword ptr [esp + 0x24], ebp
// 005db03f  895c2428             mov dword ptr [esp + 0x28], ebx
// 005db043  e8e841f1ff           call 0x4ef230
// 005db048  8b07                 mov eax, dword ptr [edi]
// 005db04a  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 005db04e  39410c               cmp dword ptr [ecx + 0xc], eax
// 005db051  733c                 jae 0x5db08f
// 005db053  8b4108               mov eax, dword ptr [ecx + 8]
// 005db056  80781500             cmp byte ptr [eax + 0x15], 0
// 005db05a  57                   push edi
// 005db05b  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 005db05f  7417                 je 0x5db078
// 005db061  51                   push ecx
// 005db062  6a00                 push 0
// 005db064  57                   push edi
// 005db065  8bce                 mov ecx, esi
// 005db067  e8c489faff           call 0x583a30
// 005db06c  5b                   pop ebx
// 005db06d  5d                   pop ebp
// 005db06e  8bc7                 mov eax, edi
// 005db070  5f                   pop edi
// 005db071  5e                   pop esi
// 005db072  83c40c               add esp, 0xc
// 005db075  c21000               ret 0x10
// 005db078  53                   push ebx
// 005db079  6a01                 push 1
// 005db07b  57                   push edi
// 005db07c  8bce                 mov ecx, esi
// 005db07e  e8ad89faff           call 0x583a30
// 005db083  5b                   pop ebx
// 005db084  5d                   pop ebp
// 005db085  8bc7                 mov eax, edi
// 005db087  5f                   pop edi
// 005db088  5e                   pop esi
// 005db089  83c40c               add esp, 0xc
// 005db08c  c21000               ret 0x10
// 005db08f  39430c               cmp dword ptr [ebx + 0xc], eax
// 005db092  7373                 jae 0x5db107
// 005db094  8b4e04               mov ecx, dword ptr [esi + 4]
// 005db097  894c2414             mov dword ptr [esp + 0x14], ecx
// 005db09b  8d4c2424             lea ecx, [esp + 0x24]
// 005db09f  896c2424             mov dword ptr [esp + 0x24], ebp
// 005db0a3  895c2428             mov dword ptr [esp + 0x28], ebx
// 005db0a7  89742410             mov dword ptr [esp + 0x10], esi
// 005db0ab  e800dee5ff           call 0x438eb0
// 005db0b0  8d542410             lea edx, [esp + 0x10]
// 005db0b4  52                   push edx
// 005db0b5  8d4c2428             lea ecx, [esp + 0x28]
// 005db0b9  e8f2b9e8ff           call 0x466ab0
// 005db0be  84c0                 test al, al
// 005db0c0  8b442428             mov eax, dword ptr [esp + 0x28]
// 005db0c4  7507                 jne 0x5db0cd
// 005db0c6  8b0f                 mov ecx, dword ptr [edi]
// 005db0c8  3b480c               cmp ecx, dword ptr [eax + 0xc]
// 005db0cb  733a                 jae 0x5db107
// 005db0cd  8b5308               mov edx, dword ptr [ebx + 8]
// 005db0d0  807a1500             cmp byte ptr [edx + 0x15], 0
// 005db0d4  57                   push edi
// 005db0d5  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 005db0d9  8bce                 mov ecx, esi
// 005db0db  7415                 je 0x5db0f2
// 005db0dd  53                   push ebx
// 005db0de  6a00                 push 0
// 005db0e0  57                   push edi
// 005db0e1  e84a89faff           call 0x583a30
// 005db0e6  5b                   pop ebx
// 005db0e7  5d                   pop ebp
// 005db0e8  8bc7                 mov eax, edi
// 005db0ea  5f                   pop edi
// 005db0eb  5e                   pop esi
// 005db0ec  83c40c               add esp, 0xc
// 005db0ef  c21000               ret 0x10
// 005db0f2  50                   push eax
// 005db0f3  6a01                 push 1
// 005db0f5  57                   push edi
// 005db0f6  e83589faff           call 0x583a30
// 005db0fb  5b                   pop ebx
// 005db0fc  5d                   pop ebp
// 005db0fd  8bc7                 mov eax, edi
// 005db0ff  5f                   pop edi
// 005db100  5e                   pop esi
// 005db101  83c40c               add esp, 0xc
// 005db104  c21000               ret 0x10
// 005db107  57                   push edi
// 005db108  8d442414             lea eax, [esp + 0x14]
// 005db10c  50                   push eax
// 005db10d  8bce                 mov ecx, esi
// 005db10f  e80c2bf5ff           call 0x52dc20
// 005db114  8b10                 mov edx, dword ptr [eax]
// 005db116  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 005db11a  5b                   pop ebx
// 005db11b  5d                   pop ebp
// 005db11c  8911                 mov dword ptr [ecx], edx
// 005db11e  8b4004               mov eax, dword ptr [eax + 4]
// 005db121  5f                   pop edi
// 005db122  894104               mov dword ptr [ecx + 4], eax
// 005db125  8bc1                 mov eax, ecx
// 005db127  5e                   pop esi
// 005db128  83c40c               add esp, 0xc
// 005db12b  c21000               ret 0x10
// standard library map_ptr<ptr> (function ?insert@?$_Tree@V?$_Tmap_traits@PAUK@@PAUT@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@PAUT@@@std@@@4@$0A@@std@@@std@@QAE?AViterator@12@V312@ABU?$pair@QAUK@@PAUT@@@2@@Z)

// stl: map_ptr<ptr>
struct T; typedef T* E;
#include <map>
struct K; template class std::map<K*, E>;
