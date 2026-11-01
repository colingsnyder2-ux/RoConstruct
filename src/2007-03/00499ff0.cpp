// from server: 100% by auto
// roc 2007-03 00499ff0  unit: seg_00490000  size: 446 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00499ff0
//
// 00499ff0  83ec0c               sub esp, 0xc
// 00499ff3  56                   push esi
// 00499ff4  8bf1                 mov esi, ecx
// 00499ff6  837e0800             cmp dword ptr [esi + 8], 0
// 00499ffa  57                   push edi
// 00499ffb  7521                 jne 0x49a01e
// 00499ffd  8b442424             mov eax, dword ptr [esp + 0x24]
// 0049a001  8b4e04               mov ecx, dword ptr [esi + 4]
// 0049a004  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 0049a008  50                   push eax
// 0049a009  51                   push ecx
// 0049a00a  6a01                 push 1
// 0049a00c  57                   push edi
// 0049a00d  8bce                 mov ecx, esi
// 0049a00f  e83cfaffff           call 0x499a50
// 0049a014  8bc7                 mov eax, edi
// 0049a016  5f                   pop edi
// 0049a017  5e                   pop esi
// 0049a018  83c40c               add esp, 0xc
// 0049a01b  c21000               ret 0x10
// 0049a01e  8b5604               mov edx, dword ptr [esi + 4]
// 0049a021  8b3a                 mov edi, dword ptr [edx]
// 0049a023  55                   push ebp
// 0049a024  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 0049a028  85ed                 test ebp, ebp
// 0049a02a  7404                 je 0x49a030
// 0049a02c  3bee                 cmp ebp, esi
// 0049a02e  7406                 je 0x49a036
// 0049a030  ff1544e97700         call dword ptr [0x77e944]
// 0049a036  53                   push ebx
// 0049a037  8b5c2428             mov ebx, dword ptr [esp + 0x28]
// 0049a03b  3bdf                 cmp ebx, edi
// 0049a03d  752b                 jne 0x49a06a
// 0049a03f  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 0049a043  8b07                 mov eax, dword ptr [edi]
// 0049a045  3b430c               cmp eax, dword ptr [ebx + 0xc]
// 0049a048  0f8d39010000         jge 0x49a187
// 0049a04e  57                   push edi
// 0049a04f  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 0049a053  53                   push ebx
// 0049a054  6a01                 push 1
// 0049a056  57                   push edi
// 0049a057  8bce                 mov ecx, esi
// 0049a059  e8f2f9ffff           call 0x499a50
// 0049a05e  5b                   pop ebx
// 0049a05f  5d                   pop ebp
// 0049a060  8bc7                 mov eax, edi
// 0049a062  5f                   pop edi
// 0049a063  5e                   pop esi
// 0049a064  83c40c               add esp, 0xc
// 0049a067  c21000               ret 0x10
// 0049a06a  85ed                 test ebp, ebp
// 0049a06c  8b7e04               mov edi, dword ptr [esi + 4]
// 0049a06f  7404                 je 0x49a075
// 0049a071  3bee                 cmp ebp, esi
// 0049a073  7406                 je 0x49a07b
// 0049a075  ff1544e97700         call dword ptr [0x77e944]
// 0049a07b  3bdf                 cmp ebx, edi
// 0049a07d  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 0049a081  752d                 jne 0x49a0b0
// 0049a083  8b4e04               mov ecx, dword ptr [esi + 4]
// 0049a086  8b4108               mov eax, dword ptr [ecx + 8]
// 0049a089  8b500c               mov edx, dword ptr [eax + 0xc]
// 0049a08c  3b17                 cmp edx, dword ptr [edi]
// 0049a08e  0f8df3000000         jge 0x49a187
// 0049a094  57                   push edi
// 0049a095  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 0049a099  50                   push eax
// 0049a09a  6a00                 push 0
// 0049a09c  57                   push edi
// 0049a09d  8bce                 mov ecx, esi
// 0049a09f  e8acf9ffff           call 0x499a50
// 0049a0a4  5b                   pop ebx
// 0049a0a5  5d                   pop ebp
// 0049a0a6  8bc7                 mov eax, edi
// 0049a0a8  5f                   pop edi
// 0049a0a9  5e                   pop esi
// 0049a0aa  83c40c               add esp, 0xc
// 0049a0ad  c21000               ret 0x10
// 0049a0b0  8b07                 mov eax, dword ptr [edi]
// 0049a0b2  39430c               cmp dword ptr [ebx + 0xc], eax
// 0049a0b5  7e5b                 jle 0x49a112
// 0049a0b7  8d4c2424             lea ecx, [esp + 0x24]
// 0049a0bb  896c2424             mov dword ptr [esp + 0x24], ebp
// 0049a0bf  895c2428             mov dword ptr [esp + 0x28], ebx
// 0049a0c3  e8e8ab0200           call 0x4c4cb0
// 0049a0c8  8b07                 mov eax, dword ptr [edi]
// 0049a0ca  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0049a0ce  39410c               cmp dword ptr [ecx + 0xc], eax
// 0049a0d1  7d3c                 jge 0x49a10f
// 0049a0d3  8b4108               mov eax, dword ptr [ecx + 8]
// 0049a0d6  80782100             cmp byte ptr [eax + 0x21], 0
// 0049a0da  57                   push edi
// 0049a0db  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 0049a0df  7417                 je 0x49a0f8
// 0049a0e1  51                   push ecx
// 0049a0e2  6a00                 push 0
// 0049a0e4  57                   push edi
// 0049a0e5  8bce                 mov ecx, esi
// 0049a0e7  e864f9ffff           call 0x499a50
// 0049a0ec  5b                   pop ebx
// 0049a0ed  5d                   pop ebp
// 0049a0ee  8bc7                 mov eax, edi
// 0049a0f0  5f                   pop edi
// 0049a0f1  5e                   pop esi
// 0049a0f2  83c40c               add esp, 0xc
// 0049a0f5  c21000               ret 0x10
// 0049a0f8  53                   push ebx
// 0049a0f9  6a01                 push 1
// 0049a0fb  57                   push edi
// 0049a0fc  8bce                 mov ecx, esi
// 0049a0fe  e84df9ffff           call 0x499a50
// 0049a103  5b                   pop ebx
// 0049a104  5d                   pop ebp
// 0049a105  8bc7                 mov eax, edi
// 0049a107  5f                   pop edi
// 0049a108  5e                   pop esi
// 0049a109  83c40c               add esp, 0xc
// 0049a10c  c21000               ret 0x10
// 0049a10f  39430c               cmp dword ptr [ebx + 0xc], eax
// 0049a112  7d73                 jge 0x49a187
// 0049a114  8b4e04               mov ecx, dword ptr [esi + 4]
// 0049a117  894c2414             mov dword ptr [esp + 0x14], ecx
// 0049a11b  8d4c2424             lea ecx, [esp + 0x24]
// 0049a11f  896c2424             mov dword ptr [esp + 0x24], ebp
// 0049a123  895c2428             mov dword ptr [esp + 0x28], ebx
// 0049a127  89742410             mov dword ptr [esp + 0x10], esi
// 0049a12b  e8f0e0ffff           call 0x498220
// 0049a130  8d542410             lea edx, [esp + 0x10]
// 0049a134  52                   push edx
// 0049a135  8d4c2428             lea ecx, [esp + 0x28]
// 0049a139  e8221bfbff           call 0x44bc60
// 0049a13e  84c0                 test al, al
// 0049a140  8b442428             mov eax, dword ptr [esp + 0x28]
// 0049a144  7507                 jne 0x49a14d
// 0049a146  8b0f                 mov ecx, dword ptr [edi]
// 0049a148  3b480c               cmp ecx, dword ptr [eax + 0xc]
// 0049a14b  7d3a                 jge 0x49a187
// 0049a14d  8b5308               mov edx, dword ptr [ebx + 8]
// 0049a150  807a2100             cmp byte ptr [edx + 0x21], 0
// 0049a154  57                   push edi
// 0049a155  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 0049a159  8bce                 mov ecx, esi
// 0049a15b  7415                 je 0x49a172
// 0049a15d  53                   push ebx
// 0049a15e  6a00                 push 0
// 0049a160  57                   push edi
// 0049a161  e8eaf8ffff           call 0x499a50
// 0049a166  5b                   pop ebx
// 0049a167  5d                   pop ebp
// 0049a168  8bc7                 mov eax, edi
// 0049a16a  5f                   pop edi
// 0049a16b  5e                   pop esi
// 0049a16c  83c40c               add esp, 0xc
// 0049a16f  c21000               ret 0x10
// 0049a172  50                   push eax
// 0049a173  6a01                 push 1
// 0049a175  57                   push edi
// 0049a176  e8d5f8ffff           call 0x499a50
// 0049a17b  5b                   pop ebx
// 0049a17c  5d                   pop ebp
// 0049a17d  8bc7                 mov eax, edi
// 0049a17f  5f                   pop edi
// 0049a180  5e                   pop esi
// 0049a181  83c40c               add esp, 0xc
// 0049a184  c21000               ret 0x10
// 0049a187  57                   push edi
// 0049a188  8d442414             lea eax, [esp + 0x14]
// 0049a18c  50                   push eax
// 0049a18d  8bce                 mov ecx, esi
// 0049a18f  e8acfaffff           call 0x499c40
// 0049a194  8b10                 mov edx, dword ptr [eax]
// 0049a196  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0049a19a  5b                   pop ebx
// 0049a19b  5d                   pop ebp
// 0049a19c  8911                 mov dword ptr [ecx], edx
// 0049a19e  8b4004               mov eax, dword ptr [eax + 4]
// 0049a1a1  5f                   pop edi
// 0049a1a2  894104               mov dword ptr [ecx + 4], eax
// 0049a1a5  8bc1                 mov eax, ecx
// 0049a1a7  5e                   pop esi
// 0049a1a8  83c40c               add esp, 0xc
// 0049a1ab  c21000               ret 0x10
// standard library map_int<pod16> (function ?insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@QAE?AViterator@12@V312@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod16>
struct E { int v[4]; };
#include <map>
template class std::map<int, E>;
