// from server: 100% by auto
// roc 2010-06 0053b900  unit: RBX::G3DTexture  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0053b900
//
// 0053b900  64a100000000         mov eax, dword ptr fs:[0]
// 0053b906  6aff                 push -1
// 0053b908  68e22f9a00           push 0x9a2fe2
// 0053b90d  50                   push eax
// 0053b90e  64892500000000       mov dword ptr fs:[0], esp
// 0053b915  83ec44               sub esp, 0x44
// 0053b918  57                   push edi
// 0053b919  8bf9                 mov edi, ecx
// 0053b91b  817f1ca9aaaa0a       cmp dword ptr [edi + 0x1c], 0xaaaaaa9
// 0053b922  7259                 jb 0x53b97d
// 0053b924  68a800a000           push 0xa000a8
// 0053b929  8d4c2408             lea ecx, [esp + 8]
// 0053b92d  ff1510a49e00         call dword ptr [0x9ea410]
// 0053b933  8d4c2420             lea ecx, [esp + 0x20]
// 0053b937  c744245000000000     mov dword ptr [esp + 0x50], 0
// 0053b93f  ff1518a99e00         call dword ptr [0x9ea918]
// 0053b945  8d442404             lea eax, [esp + 4]
// 0053b949  50                   push eax
// 0053b94a  8d4c2430             lea ecx, [esp + 0x30]
// 0053b94e  c644245401           mov byte ptr [esp + 0x54], 1
// 0053b953  c74424242c00a000     mov dword ptr [esp + 0x24], 0xa0002c
// 0053b95b  ff150ca49e00         call dword ptr [0x9ea40c]
// 0053b961  68601bb000           push 0xb01b60
// 0053b966  8d4c2424             lea ecx, [esp + 0x24]
// 0053b96a  51                   push ecx
// 0053b96b  c644245800           mov byte ptr [esp + 0x58], 0
// 0053b970  c74424283800a000     mov dword ptr [esp + 0x28], 0xa00038
// 0053b978  e835d02600           call 0x7a89b2
// 0053b97d  8b542464             mov edx, dword ptr [esp + 0x64]
// 0053b981  8b4718               mov eax, dword ptr [edi + 0x18]
// 0053b984  53                   push ebx
// 0053b985  55                   push ebp
// 0053b986  56                   push esi
// 0053b987  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 0053b98b  6a00                 push 0
// 0053b98d  52                   push edx
// 0053b98e  50                   push eax
// 0053b98f  56                   push esi
// 0053b990  50                   push eax
// 0053b991  e82afeffff           call 0x53b7c0
// 0053b996  8be8                 mov ebp, eax
// 0053b998  8b4718               mov eax, dword ptr [edi + 0x18]
// 0053b99b  bb01000000           mov ebx, 1
// 0053b9a0  015f1c               add dword ptr [edi + 0x1c], ebx
// 0053b9a3  3bf0                 cmp esi, eax
// 0053b9a5  7510                 jne 0x53b9b7
// 0053b9a7  896804               mov dword ptr [eax + 4], ebp
// 0053b9aa  8b4718               mov eax, dword ptr [edi + 0x18]
// 0053b9ad  8928                 mov dword ptr [eax], ebp
// 0053b9af  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 0053b9b2  896908               mov dword ptr [ecx + 8], ebp
// 0053b9b5  eb22                 jmp 0x53b9d9
// 0053b9b7  807c246800           cmp byte ptr [esp + 0x68], 0
// 0053b9bc  740d                 je 0x53b9cb
// 0053b9be  892e                 mov dword ptr [esi], ebp
// 0053b9c0  8b4718               mov eax, dword ptr [edi + 0x18]
// 0053b9c3  3b30                 cmp esi, dword ptr [eax]
// 0053b9c5  7512                 jne 0x53b9d9
// 0053b9c7  8928                 mov dword ptr [eax], ebp
// 0053b9c9  eb0e                 jmp 0x53b9d9
// 0053b9cb  896e08               mov dword ptr [esi + 8], ebp
// 0053b9ce  8b4718               mov eax, dword ptr [edi + 0x18]
// 0053b9d1  3b7008               cmp esi, dword ptr [eax + 8]
// 0053b9d4  7503                 jne 0x53b9d9
// 0053b9d6  896808               mov dword ptr [eax + 8], ebp
// 0053b9d9  8b5504               mov edx, dword ptr [ebp + 4]
// 0053b9dc  807a2400             cmp byte ptr [edx + 0x24], 0
// 0053b9e0  8d4504               lea eax, [ebp + 4]
// 0053b9e3  8bf5                 mov esi, ebp
// 0053b9e5  0f85ea000000         jne 0x53bad5
// 0053b9eb  eb03                 jmp 0x53b9f0
// 0053b9ed  8d4900               lea ecx, [ecx]
// 0053b9f0  8b08                 mov ecx, dword ptr [eax]
// 0053b9f2  8b5104               mov edx, dword ptr [ecx + 4]
// 0053b9f5  3b0a                 cmp ecx, dword ptr [edx]
// 0053b9f7  7551                 jne 0x53ba4a
// 0053b9f9  8b5208               mov edx, dword ptr [edx + 8]
// 0053b9fc  807a2400             cmp byte ptr [edx + 0x24], 0
// 0053ba00  7519                 jne 0x53ba1b
// 0053ba02  885924               mov byte ptr [ecx + 0x24], bl
// 0053ba05  885a24               mov byte ptr [edx + 0x24], bl
// 0053ba08  8b10                 mov edx, dword ptr [eax]
// 0053ba0a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0053ba0d  c6412400             mov byte ptr [ecx + 0x24], 0
// 0053ba11  8b10                 mov edx, dword ptr [eax]
// 0053ba13  8b7204               mov esi, dword ptr [edx + 4]
// 0053ba16  e9aa000000           jmp 0x53bac5
// 0053ba1b  3b7108               cmp esi, dword ptr [ecx + 8]
// 0053ba1e  750a                 jne 0x53ba2a
// 0053ba20  8bf1                 mov esi, ecx
// 0053ba22  56                   push esi
// 0053ba23  8bcf                 mov ecx, edi
// 0053ba25  e8d6bb2100           call 0x757600
// 0053ba2a  8b4604               mov eax, dword ptr [esi + 4]
// 0053ba2d  885824               mov byte ptr [eax + 0x24], bl
// 0053ba30  8b4e04               mov ecx, dword ptr [esi + 4]
// 0053ba33  8b5104               mov edx, dword ptr [ecx + 4]
// 0053ba36  c6422400             mov byte ptr [edx + 0x24], 0
// 0053ba3a  8b4604               mov eax, dword ptr [esi + 4]
// 0053ba3d  8b4804               mov ecx, dword ptr [eax + 4]
// 0053ba40  51                   push ecx
// 0053ba41  8bcf                 mov ecx, edi
// 0053ba43  e878b0feff           call 0x526ac0
// 0053ba48  eb7b                 jmp 0x53bac5
// 0053ba4a  8b12                 mov edx, dword ptr [edx]
// 0053ba4c  807a2400             cmp byte ptr [edx + 0x24], 0
// 0053ba50  7516                 jne 0x53ba68
// 0053ba52  885924               mov byte ptr [ecx + 0x24], bl
// 0053ba55  885a24               mov byte ptr [edx + 0x24], bl
// 0053ba58  8b10                 mov edx, dword ptr [eax]
// 0053ba5a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0053ba5d  c6412400             mov byte ptr [ecx + 0x24], 0
// 0053ba61  8b10                 mov edx, dword ptr [eax]
// 0053ba63  8b7204               mov esi, dword ptr [edx + 4]
// 0053ba66  eb5d                 jmp 0x53bac5
// 0053ba68  3b31                 cmp esi, dword ptr [ecx]
// 0053ba6a  750a                 jne 0x53ba76
// 0053ba6c  8bf1                 mov esi, ecx
// 0053ba6e  56                   push esi
// 0053ba6f  8bcf                 mov ecx, edi
// 0053ba71  e84ab0feff           call 0x526ac0
// 0053ba76  8b4604               mov eax, dword ptr [esi + 4]
// 0053ba79  885824               mov byte ptr [eax + 0x24], bl
// 0053ba7c  8b4e04               mov ecx, dword ptr [esi + 4]
// 0053ba7f  8b5104               mov edx, dword ptr [ecx + 4]
// 0053ba82  c6422400             mov byte ptr [edx + 0x24], 0
// 0053ba86  8b4604               mov eax, dword ptr [esi + 4]
// 0053ba89  8b4004               mov eax, dword ptr [eax + 4]
// 0053ba8c  8b4808               mov ecx, dword ptr [eax + 8]
// 0053ba8f  8b11                 mov edx, dword ptr [ecx]
// 0053ba91  895008               mov dword ptr [eax + 8], edx
// 0053ba94  8b11                 mov edx, dword ptr [ecx]
// 0053ba96  807a2500             cmp byte ptr [edx + 0x25], 0
// 0053ba9a  7503                 jne 0x53ba9f
// 0053ba9c  894204               mov dword ptr [edx + 4], eax
// 0053ba9f  8b5004               mov edx, dword ptr [eax + 4]
// 0053baa2  895104               mov dword ptr [ecx + 4], edx
// 0053baa5  8b5718               mov edx, dword ptr [edi + 0x18]
// 0053baa8  3b4204               cmp eax, dword ptr [edx + 4]
// 0053baab  7505                 jne 0x53bab2
// 0053baad  894a04               mov dword ptr [edx + 4], ecx
// 0053bab0  eb0e                 jmp 0x53bac0
// 0053bab2  8b5004               mov edx, dword ptr [eax + 4]
// 0053bab5  3b02                 cmp eax, dword ptr [edx]
// 0053bab7  7504                 jne 0x53babd
// 0053bab9  890a                 mov dword ptr [edx], ecx
// 0053babb  eb03                 jmp 0x53bac0
// 0053babd  894a08               mov dword ptr [edx + 8], ecx
// 0053bac0  8901                 mov dword ptr [ecx], eax
// 0053bac2  894804               mov dword ptr [eax + 4], ecx
// 0053bac5  8b4e04               mov ecx, dword ptr [esi + 4]
// 0053bac8  80792400             cmp byte ptr [ecx + 0x24], 0
// 0053bacc  8d4604               lea eax, [esi + 4]
// 0053bacf  0f841bffffff         je 0x53b9f0
// 0053bad5  8b5718               mov edx, dword ptr [edi + 0x18]
// 0053bad8  8b4204               mov eax, dword ptr [edx + 4]
// 0053badb  885824               mov byte ptr [eax + 0x24], bl
// 0053bade  8b442464             mov eax, dword ptr [esp + 0x64]
// 0053bae2  8b0f                 mov ecx, dword ptr [edi]
// 0053bae4  5e                   pop esi
// 0053bae5  896804               mov dword ptr [eax + 4], ebp
// 0053bae8  5d                   pop ebp
// 0053bae9  8908                 mov dword ptr [eax], ecx
// 0053baeb  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 0053baef  5b                   pop ebx
// 0053baf0  5f                   pop edi
// 0053baf1  64890d00000000       mov dword ptr fs:[0], ecx
// 0053baf8  83c450               add esp, 0x50
// 0053bafb  c21000               ret 0x10
// standard library map_int<pod20> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod20>
struct E { int v[5]; };
#include <map>
template class std::map<int, E>;
