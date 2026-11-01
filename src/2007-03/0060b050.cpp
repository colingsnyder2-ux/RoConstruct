// from server: 100% by auto
// roc 2007-03 0060b050  unit: seg_00600000  size: 446 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0060b050
//
// 0060b050  83ec0c               sub esp, 0xc
// 0060b053  56                   push esi
// 0060b054  8bf1                 mov esi, ecx
// 0060b056  837e0800             cmp dword ptr [esi + 8], 0
// 0060b05a  57                   push edi
// 0060b05b  7521                 jne 0x60b07e
// 0060b05d  8b442424             mov eax, dword ptr [esp + 0x24]
// 0060b061  8b4e04               mov ecx, dword ptr [esi + 4]
// 0060b064  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 0060b068  50                   push eax
// 0060b069  51                   push ecx
// 0060b06a  6a01                 push 1
// 0060b06c  57                   push edi
// 0060b06d  8bce                 mov ecx, esi
// 0060b06f  e88cedffff           call 0x609e00
// 0060b074  8bc7                 mov eax, edi
// 0060b076  5f                   pop edi
// 0060b077  5e                   pop esi
// 0060b078  83c40c               add esp, 0xc
// 0060b07b  c21000               ret 0x10
// 0060b07e  8b5604               mov edx, dword ptr [esi + 4]
// 0060b081  8b3a                 mov edi, dword ptr [edx]
// 0060b083  55                   push ebp
// 0060b084  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 0060b088  85ed                 test ebp, ebp
// 0060b08a  7404                 je 0x60b090
// 0060b08c  3bee                 cmp ebp, esi
// 0060b08e  7406                 je 0x60b096
// 0060b090  ff1544e97700         call dword ptr [0x77e944]
// 0060b096  53                   push ebx
// 0060b097  8b5c2428             mov ebx, dword ptr [esp + 0x28]
// 0060b09b  3bdf                 cmp ebx, edi
// 0060b09d  752b                 jne 0x60b0ca
// 0060b09f  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 0060b0a3  8b07                 mov eax, dword ptr [edi]
// 0060b0a5  3b430c               cmp eax, dword ptr [ebx + 0xc]
// 0060b0a8  0f8339010000         jae 0x60b1e7
// 0060b0ae  57                   push edi
// 0060b0af  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 0060b0b3  53                   push ebx
// 0060b0b4  6a01                 push 1
// 0060b0b6  57                   push edi
// 0060b0b7  8bce                 mov ecx, esi
// 0060b0b9  e842edffff           call 0x609e00
// 0060b0be  5b                   pop ebx
// 0060b0bf  5d                   pop ebp
// 0060b0c0  8bc7                 mov eax, edi
// 0060b0c2  5f                   pop edi
// 0060b0c3  5e                   pop esi
// 0060b0c4  83c40c               add esp, 0xc
// 0060b0c7  c21000               ret 0x10
// 0060b0ca  85ed                 test ebp, ebp
// 0060b0cc  8b7e04               mov edi, dword ptr [esi + 4]
// 0060b0cf  7404                 je 0x60b0d5
// 0060b0d1  3bee                 cmp ebp, esi
// 0060b0d3  7406                 je 0x60b0db
// 0060b0d5  ff1544e97700         call dword ptr [0x77e944]
// 0060b0db  3bdf                 cmp ebx, edi
// 0060b0dd  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 0060b0e1  752d                 jne 0x60b110
// 0060b0e3  8b4e04               mov ecx, dword ptr [esi + 4]
// 0060b0e6  8b4108               mov eax, dword ptr [ecx + 8]
// 0060b0e9  8b500c               mov edx, dword ptr [eax + 0xc]
// 0060b0ec  3b17                 cmp edx, dword ptr [edi]
// 0060b0ee  0f83f3000000         jae 0x60b1e7
// 0060b0f4  57                   push edi
// 0060b0f5  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 0060b0f9  50                   push eax
// 0060b0fa  6a00                 push 0
// 0060b0fc  57                   push edi
// 0060b0fd  8bce                 mov ecx, esi
// 0060b0ff  e8fcecffff           call 0x609e00
// 0060b104  5b                   pop ebx
// 0060b105  5d                   pop ebp
// 0060b106  8bc7                 mov eax, edi
// 0060b108  5f                   pop edi
// 0060b109  5e                   pop esi
// 0060b10a  83c40c               add esp, 0xc
// 0060b10d  c21000               ret 0x10
// 0060b110  8b07                 mov eax, dword ptr [edi]
// 0060b112  39430c               cmp dword ptr [ebx + 0xc], eax
// 0060b115  765b                 jbe 0x60b172
// 0060b117  8d4c2424             lea ecx, [esp + 0x24]
// 0060b11b  896c2424             mov dword ptr [esp + 0x24], ebp
// 0060b11f  895c2428             mov dword ptr [esp + 0x28], ebx
// 0060b123  e848a7feff           call 0x5f5870
// 0060b128  8b07                 mov eax, dword ptr [edi]
// 0060b12a  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0060b12e  39410c               cmp dword ptr [ecx + 0xc], eax
// 0060b131  733c                 jae 0x60b16f
// 0060b133  8b4108               mov eax, dword ptr [ecx + 8]
// 0060b136  80781d00             cmp byte ptr [eax + 0x1d], 0
// 0060b13a  57                   push edi
// 0060b13b  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 0060b13f  7417                 je 0x60b158
// 0060b141  51                   push ecx
// 0060b142  6a00                 push 0
// 0060b144  57                   push edi
// 0060b145  8bce                 mov ecx, esi
// 0060b147  e8b4ecffff           call 0x609e00
// 0060b14c  5b                   pop ebx
// 0060b14d  5d                   pop ebp
// 0060b14e  8bc7                 mov eax, edi
// 0060b150  5f                   pop edi
// 0060b151  5e                   pop esi
// 0060b152  83c40c               add esp, 0xc
// 0060b155  c21000               ret 0x10
// 0060b158  53                   push ebx
// 0060b159  6a01                 push 1
// 0060b15b  57                   push edi
// 0060b15c  8bce                 mov ecx, esi
// 0060b15e  e89decffff           call 0x609e00
// 0060b163  5b                   pop ebx
// 0060b164  5d                   pop ebp
// 0060b165  8bc7                 mov eax, edi
// 0060b167  5f                   pop edi
// 0060b168  5e                   pop esi
// 0060b169  83c40c               add esp, 0xc
// 0060b16c  c21000               ret 0x10
// 0060b16f  39430c               cmp dword ptr [ebx + 0xc], eax
// 0060b172  7373                 jae 0x60b1e7
// 0060b174  8b4e04               mov ecx, dword ptr [esi + 4]
// 0060b177  894c2414             mov dword ptr [esp + 0x14], ecx
// 0060b17b  8d4c2424             lea ecx, [esp + 0x24]
// 0060b17f  896c2424             mov dword ptr [esp + 0x24], ebp
// 0060b183  895c2428             mov dword ptr [esp + 0x28], ebx
// 0060b187  89742410             mov dword ptr [esp + 0x10], esi
// 0060b18b  e8d07dedff           call 0x4e2f60
// 0060b190  8d542410             lea edx, [esp + 0x10]
// 0060b194  52                   push edx
// 0060b195  8d4c2428             lea ecx, [esp + 0x28]
// 0060b199  e8c20ae4ff           call 0x44bc60
// 0060b19e  84c0                 test al, al
// 0060b1a0  8b442428             mov eax, dword ptr [esp + 0x28]
// 0060b1a4  7507                 jne 0x60b1ad
// 0060b1a6  8b0f                 mov ecx, dword ptr [edi]
// 0060b1a8  3b480c               cmp ecx, dword ptr [eax + 0xc]
// 0060b1ab  733a                 jae 0x60b1e7
// 0060b1ad  8b5308               mov edx, dword ptr [ebx + 8]
// 0060b1b0  807a1d00             cmp byte ptr [edx + 0x1d], 0
// 0060b1b4  57                   push edi
// 0060b1b5  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 0060b1b9  8bce                 mov ecx, esi
// 0060b1bb  7415                 je 0x60b1d2
// 0060b1bd  53                   push ebx
// 0060b1be  6a00                 push 0
// 0060b1c0  57                   push edi
// 0060b1c1  e83aecffff           call 0x609e00
// 0060b1c6  5b                   pop ebx
// 0060b1c7  5d                   pop ebp
// 0060b1c8  8bc7                 mov eax, edi
// 0060b1ca  5f                   pop edi
// 0060b1cb  5e                   pop esi
// 0060b1cc  83c40c               add esp, 0xc
// 0060b1cf  c21000               ret 0x10
// 0060b1d2  50                   push eax
// 0060b1d3  6a01                 push 1
// 0060b1d5  57                   push edi
// 0060b1d6  e825ecffff           call 0x609e00
// 0060b1db  5b                   pop ebx
// 0060b1dc  5d                   pop ebp
// 0060b1dd  8bc7                 mov eax, edi
// 0060b1df  5f                   pop edi
// 0060b1e0  5e                   pop esi
// 0060b1e1  83c40c               add esp, 0xc
// 0060b1e4  c21000               ret 0x10
// 0060b1e7  57                   push edi
// 0060b1e8  8d442414             lea eax, [esp + 0x14]
// 0060b1ec  50                   push eax
// 0060b1ed  8bce                 mov ecx, esi
// 0060b1ef  e8ecf3ffff           call 0x60a5e0
// 0060b1f4  8b10                 mov edx, dword ptr [eax]
// 0060b1f6  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0060b1fa  5b                   pop ebx
// 0060b1fb  5d                   pop ebp
// 0060b1fc  8911                 mov dword ptr [ecx], edx
// 0060b1fe  8b4004               mov eax, dword ptr [eax + 4]
// 0060b201  5f                   pop edi
// 0060b202  894104               mov dword ptr [ecx + 4], eax
// 0060b205  8bc1                 mov eax, ecx
// 0060b207  5e                   pop esi
// 0060b208  83c40c               add esp, 0xc
// 0060b20b  c21000               ret 0x10
// standard library map_ptr<pod12> (function ?insert@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@QAE?AViterator@12@V312@ABU?$pair@QAUK@@UE@@@2@@Z)

// stl: map_ptr<pod12>
struct E { int v[3]; };
#include <map>
struct K; template class std::map<K*, E>;
