// from server: 100% by auto
// roc 2009-12 0053c7f0  unit: RBX::Network::Replicator::ChangePropertyItem  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0053c7f0
//
// 0053c7f0  64a100000000         mov eax, dword ptr fs:[0]
// 0053c7f6  6aff                 push -1
// 0053c7f8  6812699500           push 0x956912
// 0053c7fd  50                   push eax
// 0053c7fe  64892500000000       mov dword ptr fs:[0], esp
// 0053c805  83ec44               sub esp, 0x44
// 0053c808  57                   push edi
// 0053c809  8bf9                 mov edi, ecx
// 0053c80b  817f1c54555515       cmp dword ptr [edi + 0x1c], 0x15555554
// 0053c812  7259                 jb 0x53c86d
// 0053c814  6800f59900           push 0x99f500
// 0053c819  8d4c2408             lea ecx, [esp + 8]
// 0053c81d  ff15f4b69800         call dword ptr [0x98b6f4]
// 0053c823  8d4c2420             lea ecx, [esp + 0x20]
// 0053c827  c744245000000000     mov dword ptr [esp + 0x50], 0
// 0053c82f  ff1554b79800         call dword ptr [0x98b754]
// 0053c835  8d442404             lea eax, [esp + 4]
// 0053c839  50                   push eax
// 0053c83a  8d4c2430             lea ecx, [esp + 0x30]
// 0053c83e  c644245401           mov byte ptr [esp + 0x54], 1
// 0053c843  c744242484f49900     mov dword ptr [esp + 0x24], 0x99f484
// 0053c84b  ff15f0b69800         call dword ptr [0x98b6f0]
// 0053c851  68e4efa800           push 0xa8efe4
// 0053c856  8d4c2424             lea ecx, [esp + 0x24]
// 0053c85a  51                   push ecx
// 0053c85b  c644245800           mov byte ptr [esp + 0x58], 0
// 0053c860  c744242890f49900     mov dword ptr [esp + 0x28], 0x99f490
// 0053c868  e80b802b00           call 0x7f4878
// 0053c86d  8b542464             mov edx, dword ptr [esp + 0x64]
// 0053c871  8b4718               mov eax, dword ptr [edi + 0x18]
// 0053c874  53                   push ebx
// 0053c875  55                   push ebp
// 0053c876  56                   push esi
// 0053c877  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 0053c87b  6a00                 push 0
// 0053c87d  52                   push edx
// 0053c87e  50                   push eax
// 0053c87f  56                   push esi
// 0053c880  50                   push eax
// 0053c881  e8eae1ffff           call 0x53aa70
// 0053c886  8be8                 mov ebp, eax
// 0053c888  8b4718               mov eax, dword ptr [edi + 0x18]
// 0053c88b  bb01000000           mov ebx, 1
// 0053c890  015f1c               add dword ptr [edi + 0x1c], ebx
// 0053c893  3bf0                 cmp esi, eax
// 0053c895  7510                 jne 0x53c8a7
// 0053c897  896804               mov dword ptr [eax + 4], ebp
// 0053c89a  8b4718               mov eax, dword ptr [edi + 0x18]
// 0053c89d  8928                 mov dword ptr [eax], ebp
// 0053c89f  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 0053c8a2  896908               mov dword ptr [ecx + 8], ebp
// 0053c8a5  eb22                 jmp 0x53c8c9
// 0053c8a7  807c246800           cmp byte ptr [esp + 0x68], 0
// 0053c8ac  740d                 je 0x53c8bb
// 0053c8ae  892e                 mov dword ptr [esi], ebp
// 0053c8b0  8b4718               mov eax, dword ptr [edi + 0x18]
// 0053c8b3  3b30                 cmp esi, dword ptr [eax]
// 0053c8b5  7512                 jne 0x53c8c9
// 0053c8b7  8928                 mov dword ptr [eax], ebp
// 0053c8b9  eb0e                 jmp 0x53c8c9
// 0053c8bb  896e08               mov dword ptr [esi + 8], ebp
// 0053c8be  8b4718               mov eax, dword ptr [edi + 0x18]
// 0053c8c1  3b7008               cmp esi, dword ptr [eax + 8]
// 0053c8c4  7503                 jne 0x53c8c9
// 0053c8c6  896808               mov dword ptr [eax + 8], ebp
// 0053c8c9  8b5504               mov edx, dword ptr [ebp + 4]
// 0053c8cc  807a1800             cmp byte ptr [edx + 0x18], 0
// 0053c8d0  8d4504               lea eax, [ebp + 4]
// 0053c8d3  8bf5                 mov esi, ebp
// 0053c8d5  0f85ea000000         jne 0x53c9c5
// 0053c8db  eb03                 jmp 0x53c8e0
// 0053c8dd  8d4900               lea ecx, [ecx]
// 0053c8e0  8b08                 mov ecx, dword ptr [eax]
// 0053c8e2  8b5104               mov edx, dword ptr [ecx + 4]
// 0053c8e5  3b0a                 cmp ecx, dword ptr [edx]
// 0053c8e7  7551                 jne 0x53c93a
// 0053c8e9  8b5208               mov edx, dword ptr [edx + 8]
// 0053c8ec  807a1800             cmp byte ptr [edx + 0x18], 0
// 0053c8f0  7519                 jne 0x53c90b
// 0053c8f2  885918               mov byte ptr [ecx + 0x18], bl
// 0053c8f5  885a18               mov byte ptr [edx + 0x18], bl
// 0053c8f8  8b10                 mov edx, dword ptr [eax]
// 0053c8fa  8b4a04               mov ecx, dword ptr [edx + 4]
// 0053c8fd  c6411800             mov byte ptr [ecx + 0x18], 0
// 0053c901  8b10                 mov edx, dword ptr [eax]
// 0053c903  8b7204               mov esi, dword ptr [edx + 4]
// 0053c906  e9aa000000           jmp 0x53c9b5
// 0053c90b  3b7108               cmp esi, dword ptr [ecx + 8]
// 0053c90e  750a                 jne 0x53c91a
// 0053c910  8bf1                 mov esi, ecx
// 0053c912  56                   push esi
// 0053c913  8bcf                 mov ecx, edi
// 0053c915  e8f69a1200           call 0x666410
// 0053c91a  8b4604               mov eax, dword ptr [esi + 4]
// 0053c91d  885818               mov byte ptr [eax + 0x18], bl
// 0053c920  8b4e04               mov ecx, dword ptr [esi + 4]
// 0053c923  8b5104               mov edx, dword ptr [ecx + 4]
// 0053c926  c6421800             mov byte ptr [edx + 0x18], 0
// 0053c92a  8b4604               mov eax, dword ptr [esi + 4]
// 0053c92d  8b4804               mov ecx, dword ptr [eax + 4]
// 0053c930  51                   push ecx
// 0053c931  8bcf                 mov ecx, edi
// 0053c933  e80865efff           call 0x432e40
// 0053c938  eb7b                 jmp 0x53c9b5
// 0053c93a  8b12                 mov edx, dword ptr [edx]
// 0053c93c  807a1800             cmp byte ptr [edx + 0x18], 0
// 0053c940  7516                 jne 0x53c958
// 0053c942  885918               mov byte ptr [ecx + 0x18], bl
// 0053c945  885a18               mov byte ptr [edx + 0x18], bl
// 0053c948  8b10                 mov edx, dword ptr [eax]
// 0053c94a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0053c94d  c6411800             mov byte ptr [ecx + 0x18], 0
// 0053c951  8b10                 mov edx, dword ptr [eax]
// 0053c953  8b7204               mov esi, dword ptr [edx + 4]
// 0053c956  eb5d                 jmp 0x53c9b5
// 0053c958  3b31                 cmp esi, dword ptr [ecx]
// 0053c95a  750a                 jne 0x53c966
// 0053c95c  8bf1                 mov esi, ecx
// 0053c95e  56                   push esi
// 0053c95f  8bcf                 mov ecx, edi
// 0053c961  e8da64efff           call 0x432e40
// 0053c966  8b4604               mov eax, dword ptr [esi + 4]
// 0053c969  885818               mov byte ptr [eax + 0x18], bl
// 0053c96c  8b4e04               mov ecx, dword ptr [esi + 4]
// 0053c96f  8b5104               mov edx, dword ptr [ecx + 4]
// 0053c972  c6421800             mov byte ptr [edx + 0x18], 0
// 0053c976  8b4604               mov eax, dword ptr [esi + 4]
// 0053c979  8b4004               mov eax, dword ptr [eax + 4]
// 0053c97c  8b4808               mov ecx, dword ptr [eax + 8]
// 0053c97f  8b11                 mov edx, dword ptr [ecx]
// 0053c981  895008               mov dword ptr [eax + 8], edx
// 0053c984  8b11                 mov edx, dword ptr [ecx]
// 0053c986  807a1900             cmp byte ptr [edx + 0x19], 0
// 0053c98a  7503                 jne 0x53c98f
// 0053c98c  894204               mov dword ptr [edx + 4], eax
// 0053c98f  8b5004               mov edx, dword ptr [eax + 4]
// 0053c992  895104               mov dword ptr [ecx + 4], edx
// 0053c995  8b5718               mov edx, dword ptr [edi + 0x18]
// 0053c998  3b4204               cmp eax, dword ptr [edx + 4]
// 0053c99b  7505                 jne 0x53c9a2
// 0053c99d  894a04               mov dword ptr [edx + 4], ecx
// 0053c9a0  eb0e                 jmp 0x53c9b0
// 0053c9a2  8b5004               mov edx, dword ptr [eax + 4]
// 0053c9a5  3b02                 cmp eax, dword ptr [edx]
// 0053c9a7  7504                 jne 0x53c9ad
// 0053c9a9  890a                 mov dword ptr [edx], ecx
// 0053c9ab  eb03                 jmp 0x53c9b0
// 0053c9ad  894a08               mov dword ptr [edx + 8], ecx
// 0053c9b0  8901                 mov dword ptr [ecx], eax
// 0053c9b2  894804               mov dword ptr [eax + 4], ecx
// 0053c9b5  8b4e04               mov ecx, dword ptr [esi + 4]
// 0053c9b8  80791800             cmp byte ptr [ecx + 0x18], 0
// 0053c9bc  8d4604               lea eax, [esi + 4]
// 0053c9bf  0f841bffffff         je 0x53c8e0
// 0053c9c5  8b5718               mov edx, dword ptr [edi + 0x18]
// 0053c9c8  8b4204               mov eax, dword ptr [edx + 4]
// 0053c9cb  885818               mov byte ptr [eax + 0x18], bl
// 0053c9ce  8b442464             mov eax, dword ptr [esp + 0x64]
// 0053c9d2  8b0f                 mov ecx, dword ptr [edi]
// 0053c9d4  5e                   pop esi
// 0053c9d5  896804               mov dword ptr [eax + 4], ebp
// 0053c9d8  5d                   pop ebp
// 0053c9d9  8908                 mov dword ptr [eax], ecx
// 0053c9db  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 0053c9df  5b                   pop ebx
// 0053c9e0  5f                   pop edi
// 0053c9e1  64890d00000000       mov dword ptr fs:[0], ecx
// 0053c9e8  83c450               add esp, 0x50
// 0053c9eb  c21000               ret 0x10
// standard library map_int<pod8> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod8>
struct E { int v[2]; };
#include <map>
template class std::map<int, E>;
