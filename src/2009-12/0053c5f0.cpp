// from server: 100% by auto
// roc 2009-12 0053c5f0  unit: RBX::Network::Replicator::ChangePropertyItem  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0053c5f0
//
// 0053c5f0  64a100000000         mov eax, dword ptr fs:[0]
// 0053c5f6  6aff                 push -1
// 0053c5f8  6812699500           push 0x956912
// 0053c5fd  50                   push eax
// 0053c5fe  64892500000000       mov dword ptr fs:[0], esp
// 0053c605  83ec44               sub esp, 0x44
// 0053c608  57                   push edi
// 0053c609  8bf9                 mov edi, ecx
// 0053c60b  817f1c65666606       cmp dword ptr [edi + 0x1c], 0x6666665
// 0053c612  7259                 jb 0x53c66d
// 0053c614  6800f59900           push 0x99f500
// 0053c619  8d4c2408             lea ecx, [esp + 8]
// 0053c61d  ff15f4b69800         call dword ptr [0x98b6f4]
// 0053c623  8d4c2420             lea ecx, [esp + 0x20]
// 0053c627  c744245000000000     mov dword ptr [esp + 0x50], 0
// 0053c62f  ff1554b79800         call dword ptr [0x98b754]
// 0053c635  8d442404             lea eax, [esp + 4]
// 0053c639  50                   push eax
// 0053c63a  8d4c2430             lea ecx, [esp + 0x30]
// 0053c63e  c644245401           mov byte ptr [esp + 0x54], 1
// 0053c643  c744242484f49900     mov dword ptr [esp + 0x24], 0x99f484
// 0053c64b  ff15f0b69800         call dword ptr [0x98b6f0]
// 0053c651  68e4efa800           push 0xa8efe4
// 0053c656  8d4c2424             lea ecx, [esp + 0x24]
// 0053c65a  51                   push ecx
// 0053c65b  c644245800           mov byte ptr [esp + 0x58], 0
// 0053c660  c744242890f49900     mov dword ptr [esp + 0x28], 0x99f490
// 0053c668  e80b822b00           call 0x7f4878
// 0053c66d  8b542464             mov edx, dword ptr [esp + 0x64]
// 0053c671  8b4718               mov eax, dword ptr [edi + 0x18]
// 0053c674  53                   push ebx
// 0053c675  55                   push ebp
// 0053c676  56                   push esi
// 0053c677  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 0053c67b  6a00                 push 0
// 0053c67d  52                   push edx
// 0053c67e  50                   push eax
// 0053c67f  56                   push esi
// 0053c680  50                   push eax
// 0053c681  e89ae3ffff           call 0x53aa20
// 0053c686  8be8                 mov ebp, eax
// 0053c688  8b4718               mov eax, dword ptr [edi + 0x18]
// 0053c68b  bb01000000           mov ebx, 1
// 0053c690  015f1c               add dword ptr [edi + 0x1c], ebx
// 0053c693  3bf0                 cmp esi, eax
// 0053c695  7510                 jne 0x53c6a7
// 0053c697  896804               mov dword ptr [eax + 4], ebp
// 0053c69a  8b4718               mov eax, dword ptr [edi + 0x18]
// 0053c69d  8928                 mov dword ptr [eax], ebp
// 0053c69f  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 0053c6a2  896908               mov dword ptr [ecx + 8], ebp
// 0053c6a5  eb22                 jmp 0x53c6c9
// 0053c6a7  807c246800           cmp byte ptr [esp + 0x68], 0
// 0053c6ac  740d                 je 0x53c6bb
// 0053c6ae  892e                 mov dword ptr [esi], ebp
// 0053c6b0  8b4718               mov eax, dword ptr [edi + 0x18]
// 0053c6b3  3b30                 cmp esi, dword ptr [eax]
// 0053c6b5  7512                 jne 0x53c6c9
// 0053c6b7  8928                 mov dword ptr [eax], ebp
// 0053c6b9  eb0e                 jmp 0x53c6c9
// 0053c6bb  896e08               mov dword ptr [esi + 8], ebp
// 0053c6be  8b4718               mov eax, dword ptr [edi + 0x18]
// 0053c6c1  3b7008               cmp esi, dword ptr [eax + 8]
// 0053c6c4  7503                 jne 0x53c6c9
// 0053c6c6  896808               mov dword ptr [eax + 8], ebp
// 0053c6c9  8b5504               mov edx, dword ptr [ebp + 4]
// 0053c6cc  807a3400             cmp byte ptr [edx + 0x34], 0
// 0053c6d0  8d4504               lea eax, [ebp + 4]
// 0053c6d3  8bf5                 mov esi, ebp
// 0053c6d5  0f85ea000000         jne 0x53c7c5
// 0053c6db  eb03                 jmp 0x53c6e0
// 0053c6dd  8d4900               lea ecx, [ecx]
// 0053c6e0  8b08                 mov ecx, dword ptr [eax]
// 0053c6e2  8b5104               mov edx, dword ptr [ecx + 4]
// 0053c6e5  3b0a                 cmp ecx, dword ptr [edx]
// 0053c6e7  7551                 jne 0x53c73a
// 0053c6e9  8b5208               mov edx, dword ptr [edx + 8]
// 0053c6ec  807a3400             cmp byte ptr [edx + 0x34], 0
// 0053c6f0  7519                 jne 0x53c70b
// 0053c6f2  885934               mov byte ptr [ecx + 0x34], bl
// 0053c6f5  885a34               mov byte ptr [edx + 0x34], bl
// 0053c6f8  8b10                 mov edx, dword ptr [eax]
// 0053c6fa  8b4a04               mov ecx, dword ptr [edx + 4]
// 0053c6fd  c6413400             mov byte ptr [ecx + 0x34], 0
// 0053c701  8b10                 mov edx, dword ptr [eax]
// 0053c703  8b7204               mov esi, dword ptr [edx + 4]
// 0053c706  e9aa000000           jmp 0x53c7b5
// 0053c70b  3b7108               cmp esi, dword ptr [ecx + 8]
// 0053c70e  750a                 jne 0x53c71a
// 0053c710  8bf1                 mov esi, ecx
// 0053c712  56                   push esi
// 0053c713  8bcf                 mov ecx, edi
// 0053c715  e8060d1800           call 0x6bd420
// 0053c71a  8b4604               mov eax, dword ptr [esi + 4]
// 0053c71d  885834               mov byte ptr [eax + 0x34], bl
// 0053c720  8b4e04               mov ecx, dword ptr [esi + 4]
// 0053c723  8b5104               mov edx, dword ptr [ecx + 4]
// 0053c726  c6423400             mov byte ptr [edx + 0x34], 0
// 0053c72a  8b4604               mov eax, dword ptr [esi + 4]
// 0053c72d  8b4804               mov ecx, dword ptr [eax + 4]
// 0053c730  51                   push ecx
// 0053c731  8bcf                 mov ecx, edi
// 0053c733  e8e8721700           call 0x6b3a20
// 0053c738  eb7b                 jmp 0x53c7b5
// 0053c73a  8b12                 mov edx, dword ptr [edx]
// 0053c73c  807a3400             cmp byte ptr [edx + 0x34], 0
// 0053c740  7516                 jne 0x53c758
// 0053c742  885934               mov byte ptr [ecx + 0x34], bl
// 0053c745  885a34               mov byte ptr [edx + 0x34], bl
// 0053c748  8b10                 mov edx, dword ptr [eax]
// 0053c74a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0053c74d  c6413400             mov byte ptr [ecx + 0x34], 0
// 0053c751  8b10                 mov edx, dword ptr [eax]
// 0053c753  8b7204               mov esi, dword ptr [edx + 4]
// 0053c756  eb5d                 jmp 0x53c7b5
// 0053c758  3b31                 cmp esi, dword ptr [ecx]
// 0053c75a  750a                 jne 0x53c766
// 0053c75c  8bf1                 mov esi, ecx
// 0053c75e  56                   push esi
// 0053c75f  8bcf                 mov ecx, edi
// 0053c761  e8ba721700           call 0x6b3a20
// 0053c766  8b4604               mov eax, dword ptr [esi + 4]
// 0053c769  885834               mov byte ptr [eax + 0x34], bl
// 0053c76c  8b4e04               mov ecx, dword ptr [esi + 4]
// 0053c76f  8b5104               mov edx, dword ptr [ecx + 4]
// 0053c772  c6423400             mov byte ptr [edx + 0x34], 0
// 0053c776  8b4604               mov eax, dword ptr [esi + 4]
// 0053c779  8b4004               mov eax, dword ptr [eax + 4]
// 0053c77c  8b4808               mov ecx, dword ptr [eax + 8]
// 0053c77f  8b11                 mov edx, dword ptr [ecx]
// 0053c781  895008               mov dword ptr [eax + 8], edx
// 0053c784  8b11                 mov edx, dword ptr [ecx]
// 0053c786  807a3500             cmp byte ptr [edx + 0x35], 0
// 0053c78a  7503                 jne 0x53c78f
// 0053c78c  894204               mov dword ptr [edx + 4], eax
// 0053c78f  8b5004               mov edx, dword ptr [eax + 4]
// 0053c792  895104               mov dword ptr [ecx + 4], edx
// 0053c795  8b5718               mov edx, dword ptr [edi + 0x18]
// 0053c798  3b4204               cmp eax, dword ptr [edx + 4]
// 0053c79b  7505                 jne 0x53c7a2
// 0053c79d  894a04               mov dword ptr [edx + 4], ecx
// 0053c7a0  eb0e                 jmp 0x53c7b0
// 0053c7a2  8b5004               mov edx, dword ptr [eax + 4]
// 0053c7a5  3b02                 cmp eax, dword ptr [edx]
// 0053c7a7  7504                 jne 0x53c7ad
// 0053c7a9  890a                 mov dword ptr [edx], ecx
// 0053c7ab  eb03                 jmp 0x53c7b0
// 0053c7ad  894a08               mov dword ptr [edx + 8], ecx
// 0053c7b0  8901                 mov dword ptr [ecx], eax
// 0053c7b2  894804               mov dword ptr [eax + 4], ecx
// 0053c7b5  8b4e04               mov ecx, dword ptr [esi + 4]
// 0053c7b8  80793400             cmp byte ptr [ecx + 0x34], 0
// 0053c7bc  8d4604               lea eax, [esi + 4]
// 0053c7bf  0f841bffffff         je 0x53c6e0
// 0053c7c5  8b5718               mov edx, dword ptr [edi + 0x18]
// 0053c7c8  8b4204               mov eax, dword ptr [edx + 4]
// 0053c7cb  885834               mov byte ptr [eax + 0x34], bl
// 0053c7ce  8b442464             mov eax, dword ptr [esp + 0x64]
// 0053c7d2  8b0f                 mov ecx, dword ptr [edi]
// 0053c7d4  5e                   pop esi
// 0053c7d5  896804               mov dword ptr [eax + 4], ebp
// 0053c7d8  5d                   pop ebp
// 0053c7d9  8908                 mov dword ptr [eax], ecx
// 0053c7db  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 0053c7df  5b                   pop ebx
// 0053c7e0  5f                   pop edi
// 0053c7e1  64890d00000000       mov dword ptr fs:[0], ecx
// 0053c7e8  83c450               add esp, 0x50
// 0053c7eb  c21000               ret 0x10
// standard library map_int<pod36> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod36>
struct E { int v[9]; };
#include <map>
template class std::map<int, E>;
