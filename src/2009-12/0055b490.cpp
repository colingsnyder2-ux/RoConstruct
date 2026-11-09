// from server: 100% by auto
// roc 2009-12 0055b490  unit: RBX::Network::ServerReplicator  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0055b490
//
// 0055b490  64a100000000         mov eax, dword ptr fs:[0]
// 0055b496  6aff                 push -1
// 0055b498  6812699500           push 0x956912
// 0055b49d  50                   push eax
// 0055b49e  64892500000000       mov dword ptr fs:[0], esp
// 0055b4a5  83ec44               sub esp, 0x44
// 0055b4a8  57                   push edi
// 0055b4a9  8bf9                 mov edi, ecx
// 0055b4ab  817f1ca9aaaa0a       cmp dword ptr [edi + 0x1c], 0xaaaaaa9
// 0055b4b2  7259                 jb 0x55b50d
// 0055b4b4  6800f59900           push 0x99f500
// 0055b4b9  8d4c2408             lea ecx, [esp + 8]
// 0055b4bd  ff15f4b69800         call dword ptr [0x98b6f4]
// 0055b4c3  8d4c2420             lea ecx, [esp + 0x20]
// 0055b4c7  c744245000000000     mov dword ptr [esp + 0x50], 0
// 0055b4cf  ff1554b79800         call dword ptr [0x98b754]
// 0055b4d5  8d442404             lea eax, [esp + 4]
// 0055b4d9  50                   push eax
// 0055b4da  8d4c2430             lea ecx, [esp + 0x30]
// 0055b4de  c644245401           mov byte ptr [esp + 0x54], 1
// 0055b4e3  c744242484f49900     mov dword ptr [esp + 0x24], 0x99f484
// 0055b4eb  ff15f0b69800         call dword ptr [0x98b6f0]
// 0055b4f1  68e4efa800           push 0xa8efe4
// 0055b4f6  8d4c2424             lea ecx, [esp + 0x24]
// 0055b4fa  51                   push ecx
// 0055b4fb  c644245800           mov byte ptr [esp + 0x58], 0
// 0055b500  c744242890f49900     mov dword ptr [esp + 0x28], 0x99f490
// 0055b508  e86b932900           call 0x7f4878
// 0055b50d  8b542464             mov edx, dword ptr [esp + 0x64]
// 0055b511  8b4718               mov eax, dword ptr [edi + 0x18]
// 0055b514  53                   push ebx
// 0055b515  55                   push ebp
// 0055b516  56                   push esi
// 0055b517  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 0055b51b  6a00                 push 0
// 0055b51d  52                   push edx
// 0055b51e  50                   push eax
// 0055b51f  56                   push esi
// 0055b520  50                   push eax
// 0055b521  e8eafaffff           call 0x55b010
// 0055b526  8be8                 mov ebp, eax
// 0055b528  8b4718               mov eax, dword ptr [edi + 0x18]
// 0055b52b  bb01000000           mov ebx, 1
// 0055b530  015f1c               add dword ptr [edi + 0x1c], ebx
// 0055b533  3bf0                 cmp esi, eax
// 0055b535  7510                 jne 0x55b547
// 0055b537  896804               mov dword ptr [eax + 4], ebp
// 0055b53a  8b4718               mov eax, dword ptr [edi + 0x18]
// 0055b53d  8928                 mov dword ptr [eax], ebp
// 0055b53f  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 0055b542  896908               mov dword ptr [ecx + 8], ebp
// 0055b545  eb22                 jmp 0x55b569
// 0055b547  807c246800           cmp byte ptr [esp + 0x68], 0
// 0055b54c  740d                 je 0x55b55b
// 0055b54e  892e                 mov dword ptr [esi], ebp
// 0055b550  8b4718               mov eax, dword ptr [edi + 0x18]
// 0055b553  3b30                 cmp esi, dword ptr [eax]
// 0055b555  7512                 jne 0x55b569
// 0055b557  8928                 mov dword ptr [eax], ebp
// 0055b559  eb0e                 jmp 0x55b569
// 0055b55b  896e08               mov dword ptr [esi + 8], ebp
// 0055b55e  8b4718               mov eax, dword ptr [edi + 0x18]
// 0055b561  3b7008               cmp esi, dword ptr [eax + 8]
// 0055b564  7503                 jne 0x55b569
// 0055b566  896808               mov dword ptr [eax + 8], ebp
// 0055b569  8b5504               mov edx, dword ptr [ebp + 4]
// 0055b56c  807a2400             cmp byte ptr [edx + 0x24], 0
// 0055b570  8d4504               lea eax, [ebp + 4]
// 0055b573  8bf5                 mov esi, ebp
// 0055b575  0f85ea000000         jne 0x55b665
// 0055b57b  eb03                 jmp 0x55b580
// 0055b57d  8d4900               lea ecx, [ecx]
// 0055b580  8b08                 mov ecx, dword ptr [eax]
// 0055b582  8b5104               mov edx, dword ptr [ecx + 4]
// 0055b585  3b0a                 cmp ecx, dword ptr [edx]
// 0055b587  7551                 jne 0x55b5da
// 0055b589  8b5208               mov edx, dword ptr [edx + 8]
// 0055b58c  807a2400             cmp byte ptr [edx + 0x24], 0
// 0055b590  7519                 jne 0x55b5ab
// 0055b592  885924               mov byte ptr [ecx + 0x24], bl
// 0055b595  885a24               mov byte ptr [edx + 0x24], bl
// 0055b598  8b10                 mov edx, dword ptr [eax]
// 0055b59a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0055b59d  c6412400             mov byte ptr [ecx + 0x24], 0
// 0055b5a1  8b10                 mov edx, dword ptr [eax]
// 0055b5a3  8b7204               mov esi, dword ptr [edx + 4]
// 0055b5a6  e9aa000000           jmp 0x55b655
// 0055b5ab  3b7108               cmp esi, dword ptr [ecx + 8]
// 0055b5ae  750a                 jne 0x55b5ba
// 0055b5b0  8bf1                 mov esi, ecx
// 0055b5b2  56                   push esi
// 0055b5b3  8bcf                 mov ecx, edi
// 0055b5b5  e80606efff           call 0x44bbc0
// 0055b5ba  8b4604               mov eax, dword ptr [esi + 4]
// 0055b5bd  885824               mov byte ptr [eax + 0x24], bl
// 0055b5c0  8b4e04               mov ecx, dword ptr [esi + 4]
// 0055b5c3  8b5104               mov edx, dword ptr [ecx + 4]
// 0055b5c6  c6422400             mov byte ptr [edx + 0x24], 0
// 0055b5ca  8b4604               mov eax, dword ptr [esi + 4]
// 0055b5cd  8b4804               mov ecx, dword ptr [eax + 4]
// 0055b5d0  51                   push ecx
// 0055b5d1  8bcf                 mov ecx, edi
// 0055b5d3  e808f9ffff           call 0x55aee0
// 0055b5d8  eb7b                 jmp 0x55b655
// 0055b5da  8b12                 mov edx, dword ptr [edx]
// 0055b5dc  807a2400             cmp byte ptr [edx + 0x24], 0
// 0055b5e0  7516                 jne 0x55b5f8
// 0055b5e2  885924               mov byte ptr [ecx + 0x24], bl
// 0055b5e5  885a24               mov byte ptr [edx + 0x24], bl
// 0055b5e8  8b10                 mov edx, dword ptr [eax]
// 0055b5ea  8b4a04               mov ecx, dword ptr [edx + 4]
// 0055b5ed  c6412400             mov byte ptr [ecx + 0x24], 0
// 0055b5f1  8b10                 mov edx, dword ptr [eax]
// 0055b5f3  8b7204               mov esi, dword ptr [edx + 4]
// 0055b5f6  eb5d                 jmp 0x55b655
// 0055b5f8  3b31                 cmp esi, dword ptr [ecx]
// 0055b5fa  750a                 jne 0x55b606
// 0055b5fc  8bf1                 mov esi, ecx
// 0055b5fe  56                   push esi
// 0055b5ff  8bcf                 mov ecx, edi
// 0055b601  e8daf8ffff           call 0x55aee0
// 0055b606  8b4604               mov eax, dword ptr [esi + 4]
// 0055b609  885824               mov byte ptr [eax + 0x24], bl
// 0055b60c  8b4e04               mov ecx, dword ptr [esi + 4]
// 0055b60f  8b5104               mov edx, dword ptr [ecx + 4]
// 0055b612  c6422400             mov byte ptr [edx + 0x24], 0
// 0055b616  8b4604               mov eax, dword ptr [esi + 4]
// 0055b619  8b4004               mov eax, dword ptr [eax + 4]
// 0055b61c  8b4808               mov ecx, dword ptr [eax + 8]
// 0055b61f  8b11                 mov edx, dword ptr [ecx]
// 0055b621  895008               mov dword ptr [eax + 8], edx
// 0055b624  8b11                 mov edx, dword ptr [ecx]
// 0055b626  807a2500             cmp byte ptr [edx + 0x25], 0
// 0055b62a  7503                 jne 0x55b62f
// 0055b62c  894204               mov dword ptr [edx + 4], eax
// 0055b62f  8b5004               mov edx, dword ptr [eax + 4]
// 0055b632  895104               mov dword ptr [ecx + 4], edx
// 0055b635  8b5718               mov edx, dword ptr [edi + 0x18]
// 0055b638  3b4204               cmp eax, dword ptr [edx + 4]
// 0055b63b  7505                 jne 0x55b642
// 0055b63d  894a04               mov dword ptr [edx + 4], ecx
// 0055b640  eb0e                 jmp 0x55b650
// 0055b642  8b5004               mov edx, dword ptr [eax + 4]
// 0055b645  3b02                 cmp eax, dword ptr [edx]
// 0055b647  7504                 jne 0x55b64d
// 0055b649  890a                 mov dword ptr [edx], ecx
// 0055b64b  eb03                 jmp 0x55b650
// 0055b64d  894a08               mov dword ptr [edx + 8], ecx
// 0055b650  8901                 mov dword ptr [ecx], eax
// 0055b652  894804               mov dword ptr [eax + 4], ecx
// 0055b655  8b4e04               mov ecx, dword ptr [esi + 4]
// 0055b658  80792400             cmp byte ptr [ecx + 0x24], 0
// 0055b65c  8d4604               lea eax, [esi + 4]
// 0055b65f  0f841bffffff         je 0x55b580
// 0055b665  8b5718               mov edx, dword ptr [edi + 0x18]
// 0055b668  8b4204               mov eax, dword ptr [edx + 4]
// 0055b66b  885824               mov byte ptr [eax + 0x24], bl
// 0055b66e  8b442464             mov eax, dword ptr [esp + 0x64]
// 0055b672  8b0f                 mov ecx, dword ptr [edi]
// 0055b674  5e                   pop esi
// 0055b675  896804               mov dword ptr [eax + 4], ebp
// 0055b678  5d                   pop ebp
// 0055b679  8908                 mov dword ptr [eax], ecx
// 0055b67b  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 0055b67f  5b                   pop ebx
// 0055b680  5f                   pop edi
// 0055b681  64890d00000000       mov dword ptr fs:[0], ecx
// 0055b688  83c450               add esp, 0x50
// 0055b68b  c21000               ret 0x10
// standard library map_int<pod20> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod20>
struct E { int v[5]; };
#include <map>
template class std::map<int, E>;
