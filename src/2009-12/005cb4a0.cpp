// from server: 100% by auto
// roc 2009-12 005cb4a0  unit: RBX::RbxG3D::TextureProxy  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005cb4a0
//
// 005cb4a0  64a100000000         mov eax, dword ptr fs:[0]
// 005cb4a6  6aff                 push -1
// 005cb4a8  6812699500           push 0x956912
// 005cb4ad  50                   push eax
// 005cb4ae  64892500000000       mov dword ptr fs:[0], esp
// 005cb4b5  83ec44               sub esp, 0x44
// 005cb4b8  57                   push edi
// 005cb4b9  8bf9                 mov edi, ecx
// 005cb4bb  817f1ca9aaaa0a       cmp dword ptr [edi + 0x1c], 0xaaaaaa9
// 005cb4c2  7259                 jb 0x5cb51d
// 005cb4c4  6800f59900           push 0x99f500
// 005cb4c9  8d4c2408             lea ecx, [esp + 8]
// 005cb4cd  ff15f4b69800         call dword ptr [0x98b6f4]
// 005cb4d3  8d4c2420             lea ecx, [esp + 0x20]
// 005cb4d7  c744245000000000     mov dword ptr [esp + 0x50], 0
// 005cb4df  ff1554b79800         call dword ptr [0x98b754]
// 005cb4e5  8d442404             lea eax, [esp + 4]
// 005cb4e9  50                   push eax
// 005cb4ea  8d4c2430             lea ecx, [esp + 0x30]
// 005cb4ee  c644245401           mov byte ptr [esp + 0x54], 1
// 005cb4f3  c744242484f49900     mov dword ptr [esp + 0x24], 0x99f484
// 005cb4fb  ff15f0b69800         call dword ptr [0x98b6f0]
// 005cb501  68e4efa800           push 0xa8efe4
// 005cb506  8d4c2424             lea ecx, [esp + 0x24]
// 005cb50a  51                   push ecx
// 005cb50b  c644245800           mov byte ptr [esp + 0x58], 0
// 005cb510  c744242890f49900     mov dword ptr [esp + 0x28], 0x99f490
// 005cb518  e85b932200           call 0x7f4878
// 005cb51d  8b542464             mov edx, dword ptr [esp + 0x64]
// 005cb521  8b4718               mov eax, dword ptr [edi + 0x18]
// 005cb524  53                   push ebx
// 005cb525  55                   push ebp
// 005cb526  56                   push esi
// 005cb527  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 005cb52b  6a00                 push 0
// 005cb52d  52                   push edx
// 005cb52e  50                   push eax
// 005cb52f  56                   push esi
// 005cb530  50                   push eax
// 005cb531  e82afeffff           call 0x5cb360
// 005cb536  8be8                 mov ebp, eax
// 005cb538  8b4718               mov eax, dword ptr [edi + 0x18]
// 005cb53b  bb01000000           mov ebx, 1
// 005cb540  015f1c               add dword ptr [edi + 0x1c], ebx
// 005cb543  3bf0                 cmp esi, eax
// 005cb545  7510                 jne 0x5cb557
// 005cb547  896804               mov dword ptr [eax + 4], ebp
// 005cb54a  8b4718               mov eax, dword ptr [edi + 0x18]
// 005cb54d  8928                 mov dword ptr [eax], ebp
// 005cb54f  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 005cb552  896908               mov dword ptr [ecx + 8], ebp
// 005cb555  eb22                 jmp 0x5cb579
// 005cb557  807c246800           cmp byte ptr [esp + 0x68], 0
// 005cb55c  740d                 je 0x5cb56b
// 005cb55e  892e                 mov dword ptr [esi], ebp
// 005cb560  8b4718               mov eax, dword ptr [edi + 0x18]
// 005cb563  3b30                 cmp esi, dword ptr [eax]
// 005cb565  7512                 jne 0x5cb579
// 005cb567  8928                 mov dword ptr [eax], ebp
// 005cb569  eb0e                 jmp 0x5cb579
// 005cb56b  896e08               mov dword ptr [esi + 8], ebp
// 005cb56e  8b4718               mov eax, dword ptr [edi + 0x18]
// 005cb571  3b7008               cmp esi, dword ptr [eax + 8]
// 005cb574  7503                 jne 0x5cb579
// 005cb576  896808               mov dword ptr [eax + 8], ebp
// 005cb579  8b5504               mov edx, dword ptr [ebp + 4]
// 005cb57c  807a2400             cmp byte ptr [edx + 0x24], 0
// 005cb580  8d4504               lea eax, [ebp + 4]
// 005cb583  8bf5                 mov esi, ebp
// 005cb585  0f85ea000000         jne 0x5cb675
// 005cb58b  eb03                 jmp 0x5cb590
// 005cb58d  8d4900               lea ecx, [ecx]
// 005cb590  8b08                 mov ecx, dword ptr [eax]
// 005cb592  8b5104               mov edx, dword ptr [ecx + 4]
// 005cb595  3b0a                 cmp ecx, dword ptr [edx]
// 005cb597  7551                 jne 0x5cb5ea
// 005cb599  8b5208               mov edx, dword ptr [edx + 8]
// 005cb59c  807a2400             cmp byte ptr [edx + 0x24], 0
// 005cb5a0  7519                 jne 0x5cb5bb
// 005cb5a2  885924               mov byte ptr [ecx + 0x24], bl
// 005cb5a5  885a24               mov byte ptr [edx + 0x24], bl
// 005cb5a8  8b10                 mov edx, dword ptr [eax]
// 005cb5aa  8b4a04               mov ecx, dword ptr [edx + 4]
// 005cb5ad  c6412400             mov byte ptr [ecx + 0x24], 0
// 005cb5b1  8b10                 mov edx, dword ptr [eax]
// 005cb5b3  8b7204               mov esi, dword ptr [edx + 4]
// 005cb5b6  e9aa000000           jmp 0x5cb665
// 005cb5bb  3b7108               cmp esi, dword ptr [ecx + 8]
// 005cb5be  750a                 jne 0x5cb5ca
// 005cb5c0  8bf1                 mov esi, ecx
// 005cb5c2  56                   push esi
// 005cb5c3  8bcf                 mov ecx, edi
// 005cb5c5  e8f605e8ff           call 0x44bbc0
// 005cb5ca  8b4604               mov eax, dword ptr [esi + 4]
// 005cb5cd  885824               mov byte ptr [eax + 0x24], bl
// 005cb5d0  8b4e04               mov ecx, dword ptr [esi + 4]
// 005cb5d3  8b5104               mov edx, dword ptr [ecx + 4]
// 005cb5d6  c6422400             mov byte ptr [edx + 0x24], 0
// 005cb5da  8b4604               mov eax, dword ptr [esi + 4]
// 005cb5dd  8b4804               mov ecx, dword ptr [eax + 4]
// 005cb5e0  51                   push ecx
// 005cb5e1  8bcf                 mov ecx, edi
// 005cb5e3  e8f8f8f8ff           call 0x55aee0
// 005cb5e8  eb7b                 jmp 0x5cb665
// 005cb5ea  8b12                 mov edx, dword ptr [edx]
// 005cb5ec  807a2400             cmp byte ptr [edx + 0x24], 0
// 005cb5f0  7516                 jne 0x5cb608
// 005cb5f2  885924               mov byte ptr [ecx + 0x24], bl
// 005cb5f5  885a24               mov byte ptr [edx + 0x24], bl
// 005cb5f8  8b10                 mov edx, dword ptr [eax]
// 005cb5fa  8b4a04               mov ecx, dword ptr [edx + 4]
// 005cb5fd  c6412400             mov byte ptr [ecx + 0x24], 0
// 005cb601  8b10                 mov edx, dword ptr [eax]
// 005cb603  8b7204               mov esi, dword ptr [edx + 4]
// 005cb606  eb5d                 jmp 0x5cb665
// 005cb608  3b31                 cmp esi, dword ptr [ecx]
// 005cb60a  750a                 jne 0x5cb616
// 005cb60c  8bf1                 mov esi, ecx
// 005cb60e  56                   push esi
// 005cb60f  8bcf                 mov ecx, edi
// 005cb611  e8caf8f8ff           call 0x55aee0
// 005cb616  8b4604               mov eax, dword ptr [esi + 4]
// 005cb619  885824               mov byte ptr [eax + 0x24], bl
// 005cb61c  8b4e04               mov ecx, dword ptr [esi + 4]
// 005cb61f  8b5104               mov edx, dword ptr [ecx + 4]
// 005cb622  c6422400             mov byte ptr [edx + 0x24], 0
// 005cb626  8b4604               mov eax, dword ptr [esi + 4]
// 005cb629  8b4004               mov eax, dword ptr [eax + 4]
// 005cb62c  8b4808               mov ecx, dword ptr [eax + 8]
// 005cb62f  8b11                 mov edx, dword ptr [ecx]
// 005cb631  895008               mov dword ptr [eax + 8], edx
// 005cb634  8b11                 mov edx, dword ptr [ecx]
// 005cb636  807a2500             cmp byte ptr [edx + 0x25], 0
// 005cb63a  7503                 jne 0x5cb63f
// 005cb63c  894204               mov dword ptr [edx + 4], eax
// 005cb63f  8b5004               mov edx, dword ptr [eax + 4]
// 005cb642  895104               mov dword ptr [ecx + 4], edx
// 005cb645  8b5718               mov edx, dword ptr [edi + 0x18]
// 005cb648  3b4204               cmp eax, dword ptr [edx + 4]
// 005cb64b  7505                 jne 0x5cb652
// 005cb64d  894a04               mov dword ptr [edx + 4], ecx
// 005cb650  eb0e                 jmp 0x5cb660
// 005cb652  8b5004               mov edx, dword ptr [eax + 4]
// 005cb655  3b02                 cmp eax, dword ptr [edx]
// 005cb657  7504                 jne 0x5cb65d
// 005cb659  890a                 mov dword ptr [edx], ecx
// 005cb65b  eb03                 jmp 0x5cb660
// 005cb65d  894a08               mov dword ptr [edx + 8], ecx
// 005cb660  8901                 mov dword ptr [ecx], eax
// 005cb662  894804               mov dword ptr [eax + 4], ecx
// 005cb665  8b4e04               mov ecx, dword ptr [esi + 4]
// 005cb668  80792400             cmp byte ptr [ecx + 0x24], 0
// 005cb66c  8d4604               lea eax, [esi + 4]
// 005cb66f  0f841bffffff         je 0x5cb590
// 005cb675  8b5718               mov edx, dword ptr [edi + 0x18]
// 005cb678  8b4204               mov eax, dword ptr [edx + 4]
// 005cb67b  885824               mov byte ptr [eax + 0x24], bl
// 005cb67e  8b442464             mov eax, dword ptr [esp + 0x64]
// 005cb682  8b0f                 mov ecx, dword ptr [edi]
// 005cb684  5e                   pop esi
// 005cb685  896804               mov dword ptr [eax + 4], ebp
// 005cb688  5d                   pop ebp
// 005cb689  8908                 mov dword ptr [eax], ecx
// 005cb68b  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 005cb68f  5b                   pop ebx
// 005cb690  5f                   pop edi
// 005cb691  64890d00000000       mov dword ptr fs:[0], ecx
// 005cb698  83c450               add esp, 0x50
// 005cb69b  c21000               ret 0x10
// standard library map_int<pod20> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod20>
struct E { int v[5]; };
#include <map>
template class std::map<int, E>;
