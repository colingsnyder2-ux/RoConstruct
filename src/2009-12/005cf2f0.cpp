// from server: 100% by auto
// roc 2009-12 005cf2f0  unit: G3D::VVector3::?$Table  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005cf2f0
//
// 005cf2f0  64a100000000         mov eax, dword ptr fs:[0]
// 005cf2f6  6aff                 push -1
// 005cf2f8  6812699500           push 0x956912
// 005cf2fd  50                   push eax
// 005cf2fe  64892500000000       mov dword ptr fs:[0], esp
// 005cf305  83ec44               sub esp, 0x44
// 005cf308  57                   push edi
// 005cf309  8bf9                 mov edi, ecx
// 005cf30b  817f1c48922409       cmp dword ptr [edi + 0x1c], 0x9249248
// 005cf312  7259                 jb 0x5cf36d
// 005cf314  6800f59900           push 0x99f500
// 005cf319  8d4c2408             lea ecx, [esp + 8]
// 005cf31d  ff15f4b69800         call dword ptr [0x98b6f4]
// 005cf323  8d4c2420             lea ecx, [esp + 0x20]
// 005cf327  c744245000000000     mov dword ptr [esp + 0x50], 0
// 005cf32f  ff1554b79800         call dword ptr [0x98b754]
// 005cf335  8d442404             lea eax, [esp + 4]
// 005cf339  50                   push eax
// 005cf33a  8d4c2430             lea ecx, [esp + 0x30]
// 005cf33e  c644245401           mov byte ptr [esp + 0x54], 1
// 005cf343  c744242484f49900     mov dword ptr [esp + 0x24], 0x99f484
// 005cf34b  ff15f0b69800         call dword ptr [0x98b6f0]
// 005cf351  68e4efa800           push 0xa8efe4
// 005cf356  8d4c2424             lea ecx, [esp + 0x24]
// 005cf35a  51                   push ecx
// 005cf35b  c644245800           mov byte ptr [esp + 0x58], 0
// 005cf360  c744242890f49900     mov dword ptr [esp + 0x28], 0x99f490
// 005cf368  e80b552200           call 0x7f4878
// 005cf36d  8b542464             mov edx, dword ptr [esp + 0x64]
// 005cf371  8b4718               mov eax, dword ptr [edi + 0x18]
// 005cf374  53                   push ebx
// 005cf375  55                   push ebp
// 005cf376  56                   push esi
// 005cf377  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 005cf37b  6a00                 push 0
// 005cf37d  52                   push edx
// 005cf37e  50                   push eax
// 005cf37f  56                   push esi
// 005cf380  50                   push eax
// 005cf381  e82af9ffff           call 0x5cecb0
// 005cf386  8be8                 mov ebp, eax
// 005cf388  8b4718               mov eax, dword ptr [edi + 0x18]
// 005cf38b  bb01000000           mov ebx, 1
// 005cf390  015f1c               add dword ptr [edi + 0x1c], ebx
// 005cf393  3bf0                 cmp esi, eax
// 005cf395  7510                 jne 0x5cf3a7
// 005cf397  896804               mov dword ptr [eax + 4], ebp
// 005cf39a  8b4718               mov eax, dword ptr [edi + 0x18]
// 005cf39d  8928                 mov dword ptr [eax], ebp
// 005cf39f  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 005cf3a2  896908               mov dword ptr [ecx + 8], ebp
// 005cf3a5  eb22                 jmp 0x5cf3c9
// 005cf3a7  807c246800           cmp byte ptr [esp + 0x68], 0
// 005cf3ac  740d                 je 0x5cf3bb
// 005cf3ae  892e                 mov dword ptr [esi], ebp
// 005cf3b0  8b4718               mov eax, dword ptr [edi + 0x18]
// 005cf3b3  3b30                 cmp esi, dword ptr [eax]
// 005cf3b5  7512                 jne 0x5cf3c9
// 005cf3b7  8928                 mov dword ptr [eax], ebp
// 005cf3b9  eb0e                 jmp 0x5cf3c9
// 005cf3bb  896e08               mov dword ptr [esi + 8], ebp
// 005cf3be  8b4718               mov eax, dword ptr [edi + 0x18]
// 005cf3c1  3b7008               cmp esi, dword ptr [eax + 8]
// 005cf3c4  7503                 jne 0x5cf3c9
// 005cf3c6  896808               mov dword ptr [eax + 8], ebp
// 005cf3c9  8b5504               mov edx, dword ptr [ebp + 4]
// 005cf3cc  807a2800             cmp byte ptr [edx + 0x28], 0
// 005cf3d0  8d4504               lea eax, [ebp + 4]
// 005cf3d3  8bf5                 mov esi, ebp
// 005cf3d5  0f85ea000000         jne 0x5cf4c5
// 005cf3db  eb03                 jmp 0x5cf3e0
// 005cf3dd  8d4900               lea ecx, [ecx]
// 005cf3e0  8b08                 mov ecx, dword ptr [eax]
// 005cf3e2  8b5104               mov edx, dword ptr [ecx + 4]
// 005cf3e5  3b0a                 cmp ecx, dword ptr [edx]
// 005cf3e7  7551                 jne 0x5cf43a
// 005cf3e9  8b5208               mov edx, dword ptr [edx + 8]
// 005cf3ec  807a2800             cmp byte ptr [edx + 0x28], 0
// 005cf3f0  7519                 jne 0x5cf40b
// 005cf3f2  885928               mov byte ptr [ecx + 0x28], bl
// 005cf3f5  885a28               mov byte ptr [edx + 0x28], bl
// 005cf3f8  8b10                 mov edx, dword ptr [eax]
// 005cf3fa  8b4a04               mov ecx, dword ptr [edx + 4]
// 005cf3fd  c6412800             mov byte ptr [ecx + 0x28], 0
// 005cf401  8b10                 mov edx, dword ptr [eax]
// 005cf403  8b7204               mov esi, dword ptr [edx + 4]
// 005cf406  e9aa000000           jmp 0x5cf4b5
// 005cf40b  3b7108               cmp esi, dword ptr [ecx + 8]
// 005cf40e  750a                 jne 0x5cf41a
// 005cf410  8bf1                 mov esi, ecx
// 005cf412  56                   push esi
// 005cf413  8bcf                 mov ecx, edi
// 005cf415  e866ddffff           call 0x5cd180
// 005cf41a  8b4604               mov eax, dword ptr [esi + 4]
// 005cf41d  885828               mov byte ptr [eax + 0x28], bl
// 005cf420  8b4e04               mov ecx, dword ptr [esi + 4]
// 005cf423  8b5104               mov edx, dword ptr [ecx + 4]
// 005cf426  c6422800             mov byte ptr [edx + 0x28], 0
// 005cf42a  8b4604               mov eax, dword ptr [esi + 4]
// 005cf42d  8b4804               mov ecx, dword ptr [eax + 4]
// 005cf430  51                   push ecx
// 005cf431  8bcf                 mov ecx, edi
// 005cf433  e8a8d1ffff           call 0x5cc5e0
// 005cf438  eb7b                 jmp 0x5cf4b5
// 005cf43a  8b12                 mov edx, dword ptr [edx]
// 005cf43c  807a2800             cmp byte ptr [edx + 0x28], 0
// 005cf440  7516                 jne 0x5cf458
// 005cf442  885928               mov byte ptr [ecx + 0x28], bl
// 005cf445  885a28               mov byte ptr [edx + 0x28], bl
// 005cf448  8b10                 mov edx, dword ptr [eax]
// 005cf44a  8b4a04               mov ecx, dword ptr [edx + 4]
// 005cf44d  c6412800             mov byte ptr [ecx + 0x28], 0
// 005cf451  8b10                 mov edx, dword ptr [eax]
// 005cf453  8b7204               mov esi, dword ptr [edx + 4]
// 005cf456  eb5d                 jmp 0x5cf4b5
// 005cf458  3b31                 cmp esi, dword ptr [ecx]
// 005cf45a  750a                 jne 0x5cf466
// 005cf45c  8bf1                 mov esi, ecx
// 005cf45e  56                   push esi
// 005cf45f  8bcf                 mov ecx, edi
// 005cf461  e87ad1ffff           call 0x5cc5e0
// 005cf466  8b4604               mov eax, dword ptr [esi + 4]
// 005cf469  885828               mov byte ptr [eax + 0x28], bl
// 005cf46c  8b4e04               mov ecx, dword ptr [esi + 4]
// 005cf46f  8b5104               mov edx, dword ptr [ecx + 4]
// 005cf472  c6422800             mov byte ptr [edx + 0x28], 0
// 005cf476  8b4604               mov eax, dword ptr [esi + 4]
// 005cf479  8b4004               mov eax, dword ptr [eax + 4]
// 005cf47c  8b4808               mov ecx, dword ptr [eax + 8]
// 005cf47f  8b11                 mov edx, dword ptr [ecx]
// 005cf481  895008               mov dword ptr [eax + 8], edx
// 005cf484  8b11                 mov edx, dword ptr [ecx]
// 005cf486  807a2900             cmp byte ptr [edx + 0x29], 0
// 005cf48a  7503                 jne 0x5cf48f
// 005cf48c  894204               mov dword ptr [edx + 4], eax
// 005cf48f  8b5004               mov edx, dword ptr [eax + 4]
// 005cf492  895104               mov dword ptr [ecx + 4], edx
// 005cf495  8b5718               mov edx, dword ptr [edi + 0x18]
// 005cf498  3b4204               cmp eax, dword ptr [edx + 4]
// 005cf49b  7505                 jne 0x5cf4a2
// 005cf49d  894a04               mov dword ptr [edx + 4], ecx
// 005cf4a0  eb0e                 jmp 0x5cf4b0
// 005cf4a2  8b5004               mov edx, dword ptr [eax + 4]
// 005cf4a5  3b02                 cmp eax, dword ptr [edx]
// 005cf4a7  7504                 jne 0x5cf4ad
// 005cf4a9  890a                 mov dword ptr [edx], ecx
// 005cf4ab  eb03                 jmp 0x5cf4b0
// 005cf4ad  894a08               mov dword ptr [edx + 8], ecx
// 005cf4b0  8901                 mov dword ptr [ecx], eax
// 005cf4b2  894804               mov dword ptr [eax + 4], ecx
// 005cf4b5  8b4e04               mov ecx, dword ptr [esi + 4]
// 005cf4b8  80792800             cmp byte ptr [ecx + 0x28], 0
// 005cf4bc  8d4604               lea eax, [esi + 4]
// 005cf4bf  0f841bffffff         je 0x5cf3e0
// 005cf4c5  8b5718               mov edx, dword ptr [edi + 0x18]
// 005cf4c8  8b4204               mov eax, dword ptr [edx + 4]
// 005cf4cb  885828               mov byte ptr [eax + 0x28], bl
// 005cf4ce  8b442464             mov eax, dword ptr [esp + 0x64]
// 005cf4d2  8b0f                 mov ecx, dword ptr [edi]
// 005cf4d4  5e                   pop esi
// 005cf4d5  896804               mov dword ptr [eax + 4], ebp
// 005cf4d8  5d                   pop ebp
// 005cf4d9  8908                 mov dword ptr [eax], ecx
// 005cf4db  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 005cf4df  5b                   pop ebx
// 005cf4e0  5f                   pop edi
// 005cf4e1  64890d00000000       mov dword ptr fs:[0], ecx
// 005cf4e8  83c450               add esp, 0x50
// 005cf4eb  c21000               ret 0x10
// standard library map_int<pod24> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod24>
struct E { int v[6]; };
#include <map>
template class std::map<int, E>;
