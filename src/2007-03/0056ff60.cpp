// from server: 100% by auto
// roc 2007-03 0056ff60  unit: seg_00560000  size: 446 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0056ff60
//
// 0056ff60  83ec0c               sub esp, 0xc
// 0056ff63  56                   push esi
// 0056ff64  8bf1                 mov esi, ecx
// 0056ff66  837e0800             cmp dword ptr [esi + 8], 0
// 0056ff6a  57                   push edi
// 0056ff6b  7521                 jne 0x56ff8e
// 0056ff6d  8b442424             mov eax, dword ptr [esp + 0x24]
// 0056ff71  8b4e04               mov ecx, dword ptr [esi + 4]
// 0056ff74  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 0056ff78  50                   push eax
// 0056ff79  51                   push ecx
// 0056ff7a  6a01                 push 1
// 0056ff7c  57                   push edi
// 0056ff7d  8bce                 mov ecx, esi
// 0056ff7f  e89cfcffff           call 0x56fc20
// 0056ff84  8bc7                 mov eax, edi
// 0056ff86  5f                   pop edi
// 0056ff87  5e                   pop esi
// 0056ff88  83c40c               add esp, 0xc
// 0056ff8b  c21000               ret 0x10
// 0056ff8e  8b5604               mov edx, dword ptr [esi + 4]
// 0056ff91  8b3a                 mov edi, dword ptr [edx]
// 0056ff93  55                   push ebp
// 0056ff94  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 0056ff98  85ed                 test ebp, ebp
// 0056ff9a  7404                 je 0x56ffa0
// 0056ff9c  3bee                 cmp ebp, esi
// 0056ff9e  7406                 je 0x56ffa6
// 0056ffa0  ff1544e97700         call dword ptr [0x77e944]
// 0056ffa6  53                   push ebx
// 0056ffa7  8b5c2428             mov ebx, dword ptr [esp + 0x28]
// 0056ffab  3bdf                 cmp ebx, edi
// 0056ffad  752b                 jne 0x56ffda
// 0056ffaf  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 0056ffb3  8b07                 mov eax, dword ptr [edi]
// 0056ffb5  3b430c               cmp eax, dword ptr [ebx + 0xc]
// 0056ffb8  0f8339010000         jae 0x5700f7
// 0056ffbe  57                   push edi
// 0056ffbf  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 0056ffc3  53                   push ebx
// 0056ffc4  6a01                 push 1
// 0056ffc6  57                   push edi
// 0056ffc7  8bce                 mov ecx, esi
// 0056ffc9  e852fcffff           call 0x56fc20
// 0056ffce  5b                   pop ebx
// 0056ffcf  5d                   pop ebp
// 0056ffd0  8bc7                 mov eax, edi
// 0056ffd2  5f                   pop edi
// 0056ffd3  5e                   pop esi
// 0056ffd4  83c40c               add esp, 0xc
// 0056ffd7  c21000               ret 0x10
// 0056ffda  85ed                 test ebp, ebp
// 0056ffdc  8b7e04               mov edi, dword ptr [esi + 4]
// 0056ffdf  7404                 je 0x56ffe5
// 0056ffe1  3bee                 cmp ebp, esi
// 0056ffe3  7406                 je 0x56ffeb
// 0056ffe5  ff1544e97700         call dword ptr [0x77e944]
// 0056ffeb  3bdf                 cmp ebx, edi
// 0056ffed  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 0056fff1  752d                 jne 0x570020
// 0056fff3  8b4e04               mov ecx, dword ptr [esi + 4]
// 0056fff6  8b4108               mov eax, dword ptr [ecx + 8]
// 0056fff9  8b500c               mov edx, dword ptr [eax + 0xc]
// 0056fffc  3b17                 cmp edx, dword ptr [edi]
// 0056fffe  0f83f3000000         jae 0x5700f7
// 00570004  57                   push edi
// 00570005  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00570009  50                   push eax
// 0057000a  6a00                 push 0
// 0057000c  57                   push edi
// 0057000d  8bce                 mov ecx, esi
// 0057000f  e80cfcffff           call 0x56fc20
// 00570014  5b                   pop ebx
// 00570015  5d                   pop ebp
// 00570016  8bc7                 mov eax, edi
// 00570018  5f                   pop edi
// 00570019  5e                   pop esi
// 0057001a  83c40c               add esp, 0xc
// 0057001d  c21000               ret 0x10
// 00570020  8b07                 mov eax, dword ptr [edi]
// 00570022  39430c               cmp dword ptr [ebx + 0xc], eax
// 00570025  765b                 jbe 0x570082
// 00570027  8d4c2424             lea ecx, [esp + 0x24]
// 0057002b  896c2424             mov dword ptr [esp + 0x24], ebp
// 0057002f  895c2428             mov dword ptr [esp + 0x28], ebx
// 00570033  e8d80e0800           call 0x5f0f10
// 00570038  8b07                 mov eax, dword ptr [edi]
// 0057003a  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0057003e  39410c               cmp dword ptr [ecx + 0xc], eax
// 00570041  733c                 jae 0x57007f
// 00570043  8b4108               mov eax, dword ptr [ecx + 8]
// 00570046  80781900             cmp byte ptr [eax + 0x19], 0
// 0057004a  57                   push edi
// 0057004b  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 0057004f  7417                 je 0x570068
// 00570051  51                   push ecx
// 00570052  6a00                 push 0
// 00570054  57                   push edi
// 00570055  8bce                 mov ecx, esi
// 00570057  e8c4fbffff           call 0x56fc20
// 0057005c  5b                   pop ebx
// 0057005d  5d                   pop ebp
// 0057005e  8bc7                 mov eax, edi
// 00570060  5f                   pop edi
// 00570061  5e                   pop esi
// 00570062  83c40c               add esp, 0xc
// 00570065  c21000               ret 0x10
// 00570068  53                   push ebx
// 00570069  6a01                 push 1
// 0057006b  57                   push edi
// 0057006c  8bce                 mov ecx, esi
// 0057006e  e8adfbffff           call 0x56fc20
// 00570073  5b                   pop ebx
// 00570074  5d                   pop ebp
// 00570075  8bc7                 mov eax, edi
// 00570077  5f                   pop edi
// 00570078  5e                   pop esi
// 00570079  83c40c               add esp, 0xc
// 0057007c  c21000               ret 0x10
// 0057007f  39430c               cmp dword ptr [ebx + 0xc], eax
// 00570082  7373                 jae 0x5700f7
// 00570084  8b4e04               mov ecx, dword ptr [esi + 4]
// 00570087  894c2414             mov dword ptr [esp + 0x14], ecx
// 0057008b  8d4c2424             lea ecx, [esp + 0x24]
// 0057008f  896c2424             mov dword ptr [esp + 0x24], ebp
// 00570093  895c2428             mov dword ptr [esp + 0x28], ebx
// 00570097  89742410             mov dword ptr [esp + 0x10], esi
// 0057009b  e860110800           call 0x5f1200
// 005700a0  8d542410             lea edx, [esp + 0x10]
// 005700a4  52                   push edx
// 005700a5  8d4c2428             lea ecx, [esp + 0x28]
// 005700a9  e8b2bbedff           call 0x44bc60
// 005700ae  84c0                 test al, al
// 005700b0  8b442428             mov eax, dword ptr [esp + 0x28]
// 005700b4  7507                 jne 0x5700bd
// 005700b6  8b0f                 mov ecx, dword ptr [edi]
// 005700b8  3b480c               cmp ecx, dword ptr [eax + 0xc]
// 005700bb  733a                 jae 0x5700f7
// 005700bd  8b5308               mov edx, dword ptr [ebx + 8]
// 005700c0  807a1900             cmp byte ptr [edx + 0x19], 0
// 005700c4  57                   push edi
// 005700c5  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 005700c9  8bce                 mov ecx, esi
// 005700cb  7415                 je 0x5700e2
// 005700cd  53                   push ebx
// 005700ce  6a00                 push 0
// 005700d0  57                   push edi
// 005700d1  e84afbffff           call 0x56fc20
// 005700d6  5b                   pop ebx
// 005700d7  5d                   pop ebp
// 005700d8  8bc7                 mov eax, edi
// 005700da  5f                   pop edi
// 005700db  5e                   pop esi
// 005700dc  83c40c               add esp, 0xc
// 005700df  c21000               ret 0x10
// 005700e2  50                   push eax
// 005700e3  6a01                 push 1
// 005700e5  57                   push edi
// 005700e6  e835fbffff           call 0x56fc20
// 005700eb  5b                   pop ebx
// 005700ec  5d                   pop ebp
// 005700ed  8bc7                 mov eax, edi
// 005700ef  5f                   pop edi
// 005700f0  5e                   pop esi
// 005700f1  83c40c               add esp, 0xc
// 005700f4  c21000               ret 0x10
// 005700f7  57                   push edi
// 005700f8  8d442414             lea eax, [esp + 0x14]
// 005700fc  50                   push eax
// 005700fd  8bce                 mov ecx, esi
// 005700ff  e89cfdffff           call 0x56fea0
// 00570104  8b10                 mov edx, dword ptr [eax]
// 00570106  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0057010a  5b                   pop ebx
// 0057010b  5d                   pop ebp
// 0057010c  8911                 mov dword ptr [ecx], edx
// 0057010e  8b4004               mov eax, dword ptr [eax + 4]
// 00570111  5f                   pop edi
// 00570112  894104               mov dword ptr [ecx + 4], eax
// 00570115  8bc1                 mov eax, ecx
// 00570117  5e                   pop esi
// 00570118  83c40c               add esp, 0xc
// 0057011b  c21000               ret 0x10
// standard library map_ptr<pod8> (function ?insert@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@QAE?AViterator@12@V312@ABU?$pair@QAUK@@UE@@@2@@Z)

// stl: map_ptr<pod8>
struct E { int v[2]; };
#include <map>
struct K; template class std::map<K*, E>;
