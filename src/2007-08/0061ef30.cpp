// from server: 100% by auto
// roc 2007-08 0061ef30  unit: RBX::ScoreHud  size: 446 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0061ef30
//
// 0061ef30  83ec0c               sub esp, 0xc
// 0061ef33  56                   push esi
// 0061ef34  8bf1                 mov esi, ecx
// 0061ef36  837e0800             cmp dword ptr [esi + 8], 0
// 0061ef3a  57                   push edi
// 0061ef3b  7521                 jne 0x61ef5e
// 0061ef3d  8b442424             mov eax, dword ptr [esp + 0x24]
// 0061ef41  8b4e04               mov ecx, dword ptr [esi + 4]
// 0061ef44  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 0061ef48  50                   push eax
// 0061ef49  51                   push ecx
// 0061ef4a  6a01                 push 1
// 0061ef4c  57                   push edi
// 0061ef4d  8bce                 mov ecx, esi
// 0061ef4f  e8acf5ffff           call 0x61e500
// 0061ef54  8bc7                 mov eax, edi
// 0061ef56  5f                   pop edi
// 0061ef57  5e                   pop esi
// 0061ef58  83c40c               add esp, 0xc
// 0061ef5b  c21000               ret 0x10
// 0061ef5e  8b5604               mov edx, dword ptr [esi + 4]
// 0061ef61  8b3a                 mov edi, dword ptr [edx]
// 0061ef63  55                   push ebp
// 0061ef64  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 0061ef68  85ed                 test ebp, ebp
// 0061ef6a  7404                 je 0x61ef70
// 0061ef6c  3bee                 cmp ebp, esi
// 0061ef6e  7406                 je 0x61ef76
// 0061ef70  ff15d8e67700         call dword ptr [0x77e6d8]
// 0061ef76  53                   push ebx
// 0061ef77  8b5c2428             mov ebx, dword ptr [esp + 0x28]
// 0061ef7b  3bdf                 cmp ebx, edi
// 0061ef7d  752b                 jne 0x61efaa
// 0061ef7f  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 0061ef83  8b07                 mov eax, dword ptr [edi]
// 0061ef85  3b430c               cmp eax, dword ptr [ebx + 0xc]
// 0061ef88  0f8339010000         jae 0x61f0c7
// 0061ef8e  57                   push edi
// 0061ef8f  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 0061ef93  53                   push ebx
// 0061ef94  6a01                 push 1
// 0061ef96  57                   push edi
// 0061ef97  8bce                 mov ecx, esi
// 0061ef99  e862f5ffff           call 0x61e500
// 0061ef9e  5b                   pop ebx
// 0061ef9f  5d                   pop ebp
// 0061efa0  8bc7                 mov eax, edi
// 0061efa2  5f                   pop edi
// 0061efa3  5e                   pop esi
// 0061efa4  83c40c               add esp, 0xc
// 0061efa7  c21000               ret 0x10
// 0061efaa  85ed                 test ebp, ebp
// 0061efac  8b7e04               mov edi, dword ptr [esi + 4]
// 0061efaf  7404                 je 0x61efb5
// 0061efb1  3bee                 cmp ebp, esi
// 0061efb3  7406                 je 0x61efbb
// 0061efb5  ff15d8e67700         call dword ptr [0x77e6d8]
// 0061efbb  3bdf                 cmp ebx, edi
// 0061efbd  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 0061efc1  752d                 jne 0x61eff0
// 0061efc3  8b4e04               mov ecx, dword ptr [esi + 4]
// 0061efc6  8b4108               mov eax, dword ptr [ecx + 8]
// 0061efc9  8b500c               mov edx, dword ptr [eax + 0xc]
// 0061efcc  3b17                 cmp edx, dword ptr [edi]
// 0061efce  0f83f3000000         jae 0x61f0c7
// 0061efd4  57                   push edi
// 0061efd5  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 0061efd9  50                   push eax
// 0061efda  6a00                 push 0
// 0061efdc  57                   push edi
// 0061efdd  8bce                 mov ecx, esi
// 0061efdf  e81cf5ffff           call 0x61e500
// 0061efe4  5b                   pop ebx
// 0061efe5  5d                   pop ebp
// 0061efe6  8bc7                 mov eax, edi
// 0061efe8  5f                   pop edi
// 0061efe9  5e                   pop esi
// 0061efea  83c40c               add esp, 0xc
// 0061efed  c21000               ret 0x10
// 0061eff0  8b07                 mov eax, dword ptr [edi]
// 0061eff2  39430c               cmp dword ptr [ebx + 0xc], eax
// 0061eff5  765b                 jbe 0x61f052
// 0061eff7  8d4c2424             lea ecx, [esp + 0x24]
// 0061effb  896c2424             mov dword ptr [esp + 0x24], ebp
// 0061efff  895c2428             mov dword ptr [esp + 0x28], ebx
// 0061f003  e8a813e8ff           call 0x4a03b0
// 0061f008  8b07                 mov eax, dword ptr [edi]
// 0061f00a  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0061f00e  39410c               cmp dword ptr [ecx + 0xc], eax
// 0061f011  733c                 jae 0x61f04f
// 0061f013  8b4108               mov eax, dword ptr [ecx + 8]
// 0061f016  80782100             cmp byte ptr [eax + 0x21], 0
// 0061f01a  57                   push edi
// 0061f01b  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 0061f01f  7417                 je 0x61f038
// 0061f021  51                   push ecx
// 0061f022  6a00                 push 0
// 0061f024  57                   push edi
// 0061f025  8bce                 mov ecx, esi
// 0061f027  e8d4f4ffff           call 0x61e500
// 0061f02c  5b                   pop ebx
// 0061f02d  5d                   pop ebp
// 0061f02e  8bc7                 mov eax, edi
// 0061f030  5f                   pop edi
// 0061f031  5e                   pop esi
// 0061f032  83c40c               add esp, 0xc
// 0061f035  c21000               ret 0x10
// 0061f038  53                   push ebx
// 0061f039  6a01                 push 1
// 0061f03b  57                   push edi
// 0061f03c  8bce                 mov ecx, esi
// 0061f03e  e8bdf4ffff           call 0x61e500
// 0061f043  5b                   pop ebx
// 0061f044  5d                   pop ebp
// 0061f045  8bc7                 mov eax, edi
// 0061f047  5f                   pop edi
// 0061f048  5e                   pop esi
// 0061f049  83c40c               add esp, 0xc
// 0061f04c  c21000               ret 0x10
// 0061f04f  39430c               cmp dword ptr [ebx + 0xc], eax
// 0061f052  7373                 jae 0x61f0c7
// 0061f054  8b4e04               mov ecx, dword ptr [esi + 4]
// 0061f057  894c2414             mov dword ptr [esp + 0x14], ecx
// 0061f05b  8d4c2424             lea ecx, [esp + 0x24]
// 0061f05f  896c2424             mov dword ptr [esp + 0x24], ebp
// 0061f063  895c2428             mov dword ptr [esp + 0x28], ebx
// 0061f067  89742410             mov dword ptr [esp + 0x10], esi
// 0061f06b  e80018ebff           call 0x4d0870
// 0061f070  8d542410             lea edx, [esp + 0x10]
// 0061f074  52                   push edx
// 0061f075  8d4c2428             lea ecx, [esp + 0x28]
// 0061f079  e8327ae4ff           call 0x466ab0
// 0061f07e  84c0                 test al, al
// 0061f080  8b442428             mov eax, dword ptr [esp + 0x28]
// 0061f084  7507                 jne 0x61f08d
// 0061f086  8b0f                 mov ecx, dword ptr [edi]
// 0061f088  3b480c               cmp ecx, dword ptr [eax + 0xc]
// 0061f08b  733a                 jae 0x61f0c7
// 0061f08d  8b5308               mov edx, dword ptr [ebx + 8]
// 0061f090  807a2100             cmp byte ptr [edx + 0x21], 0
// 0061f094  57                   push edi
// 0061f095  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 0061f099  8bce                 mov ecx, esi
// 0061f09b  7415                 je 0x61f0b2
// 0061f09d  53                   push ebx
// 0061f09e  6a00                 push 0
// 0061f0a0  57                   push edi
// 0061f0a1  e85af4ffff           call 0x61e500
// 0061f0a6  5b                   pop ebx
// 0061f0a7  5d                   pop ebp
// 0061f0a8  8bc7                 mov eax, edi
// 0061f0aa  5f                   pop edi
// 0061f0ab  5e                   pop esi
// 0061f0ac  83c40c               add esp, 0xc
// 0061f0af  c21000               ret 0x10
// 0061f0b2  50                   push eax
// 0061f0b3  6a01                 push 1
// 0061f0b5  57                   push edi
// 0061f0b6  e845f4ffff           call 0x61e500
// 0061f0bb  5b                   pop ebx
// 0061f0bc  5d                   pop ebp
// 0061f0bd  8bc7                 mov eax, edi
// 0061f0bf  5f                   pop edi
// 0061f0c0  5e                   pop esi
// 0061f0c1  83c40c               add esp, 0xc
// 0061f0c4  c21000               ret 0x10
// 0061f0c7  57                   push edi
// 0061f0c8  8d442414             lea eax, [esp + 0x14]
// 0061f0cc  50                   push eax
// 0061f0cd  8bce                 mov ecx, esi
// 0061f0cf  e81cf7ffff           call 0x61e7f0
// 0061f0d4  8b10                 mov edx, dword ptr [eax]
// 0061f0d6  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0061f0da  5b                   pop ebx
// 0061f0db  5d                   pop ebp
// 0061f0dc  8911                 mov dword ptr [ecx], edx
// 0061f0de  8b4004               mov eax, dword ptr [eax + 4]
// 0061f0e1  5f                   pop edi
// 0061f0e2  894104               mov dword ptr [ecx + 4], eax
// 0061f0e5  8bc1                 mov eax, ecx
// 0061f0e7  5e                   pop esi
// 0061f0e8  83c40c               add esp, 0xc
// 0061f0eb  c21000               ret 0x10
// standard library map_ptr<pod16> (function ?insert@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@QAE?AViterator@12@V312@ABU?$pair@QAUK@@UE@@@2@@Z)

// stl: map_ptr<pod16>
struct E { int v[4]; };
#include <map>
struct K; template class std::map<K*, E>;
