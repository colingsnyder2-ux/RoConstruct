// from server: 100% by auto
// roc 2007-08 0061e500  unit: RBX::ScoreHud  size: 508 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0061e500
//
// 0061e500  64a100000000         mov eax, dword ptr fs:[0]
// 0061e506  6aff                 push -1
// 0061e508  68b2417500           push 0x7541b2
// 0061e50d  50                   push eax
// 0061e50e  64892500000000       mov dword ptr fs:[0], esp
// 0061e515  83ec44               sub esp, 0x44
// 0061e518  57                   push edi
// 0061e519  8bf9                 mov edi, ecx
// 0061e51b  817f08cbcccc0c       cmp dword ptr [edi + 8], 0xccccccb
// 0061e522  7259                 jb 0x61e57d
// 0061e524  68904f7800           push 0x784f90
// 0061e529  8d4c2408             lea ecx, [esp + 8]
// 0061e52d  ff1598e67700         call dword ptr [0x77e698]
// 0061e533  8d4c2420             lea ecx, [esp + 0x20]
// 0061e537  c744245000000000     mov dword ptr [esp + 0x50], 0
// 0061e53f  ff15f8e67700         call dword ptr [0x77e6f8]
// 0061e545  8d442404             lea eax, [esp + 4]
// 0061e549  50                   push eax
// 0061e54a  8d4c2430             lea ecx, [esp + 0x30]
// 0061e54e  c644245401           mov byte ptr [esp + 0x54], 1
// 0061e553  c7442424604e7800     mov dword ptr [esp + 0x24], 0x784e60
// 0061e55b  ff159ce67700         call dword ptr [0x77e69c]
// 0061e561  6878f78300           push 0x83f778
// 0061e566  8d4c2424             lea ecx, [esp + 0x24]
// 0061e56a  51                   push ecx
// 0061e56b  c644245800           mov byte ptr [esp + 0x58], 0
// 0061e570  c74424286c4e7800     mov dword ptr [esp + 0x28], 0x784e6c
// 0061e578  e821260100           call 0x630b9e
// 0061e57d  8b542464             mov edx, dword ptr [esp + 0x64]
// 0061e581  8b4704               mov eax, dword ptr [edi + 4]
// 0061e584  53                   push ebx
// 0061e585  55                   push ebp
// 0061e586  56                   push esi
// 0061e587  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 0061e58b  6a00                 push 0
// 0061e58d  52                   push edx
// 0061e58e  50                   push eax
// 0061e58f  56                   push esi
// 0061e590  50                   push eax
// 0061e591  e84afcffff           call 0x61e1e0
// 0061e596  8be8                 mov ebp, eax
// 0061e598  8b4704               mov eax, dword ptr [edi + 4]
// 0061e59b  bb01000000           mov ebx, 1
// 0061e5a0  015f08               add dword ptr [edi + 8], ebx
// 0061e5a3  3bf0                 cmp esi, eax
// 0061e5a5  7510                 jne 0x61e5b7
// 0061e5a7  896804               mov dword ptr [eax + 4], ebp
// 0061e5aa  8b4704               mov eax, dword ptr [edi + 4]
// 0061e5ad  8928                 mov dword ptr [eax], ebp
// 0061e5af  8b4f04               mov ecx, dword ptr [edi + 4]
// 0061e5b2  896908               mov dword ptr [ecx + 8], ebp
// 0061e5b5  eb22                 jmp 0x61e5d9
// 0061e5b7  807c246800           cmp byte ptr [esp + 0x68], 0
// 0061e5bc  740d                 je 0x61e5cb
// 0061e5be  892e                 mov dword ptr [esi], ebp
// 0061e5c0  8b4704               mov eax, dword ptr [edi + 4]
// 0061e5c3  3b30                 cmp esi, dword ptr [eax]
// 0061e5c5  7512                 jne 0x61e5d9
// 0061e5c7  8928                 mov dword ptr [eax], ebp
// 0061e5c9  eb0e                 jmp 0x61e5d9
// 0061e5cb  896e08               mov dword ptr [esi + 8], ebp
// 0061e5ce  8b4704               mov eax, dword ptr [edi + 4]
// 0061e5d1  3b7008               cmp esi, dword ptr [eax + 8]
// 0061e5d4  7503                 jne 0x61e5d9
// 0061e5d6  896808               mov dword ptr [eax + 8], ebp
// 0061e5d9  8b5504               mov edx, dword ptr [ebp + 4]
// 0061e5dc  807a2000             cmp byte ptr [edx + 0x20], 0
// 0061e5e0  8d4504               lea eax, [ebp + 4]
// 0061e5e3  8bf5                 mov esi, ebp
// 0061e5e5  0f85ea000000         jne 0x61e6d5
// 0061e5eb  eb03                 jmp 0x61e5f0
// 0061e5ed  8d4900               lea ecx, [ecx]
// 0061e5f0  8b08                 mov ecx, dword ptr [eax]
// 0061e5f2  8b5104               mov edx, dword ptr [ecx + 4]
// 0061e5f5  3b0a                 cmp ecx, dword ptr [edx]
// 0061e5f7  7551                 jne 0x61e64a
// 0061e5f9  8b5208               mov edx, dword ptr [edx + 8]
// 0061e5fc  807a2000             cmp byte ptr [edx + 0x20], 0
// 0061e600  7519                 jne 0x61e61b
// 0061e602  885920               mov byte ptr [ecx + 0x20], bl
// 0061e605  885a20               mov byte ptr [edx + 0x20], bl
// 0061e608  8b10                 mov edx, dword ptr [eax]
// 0061e60a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0061e60d  c6412000             mov byte ptr [ecx + 0x20], 0
// 0061e611  8b10                 mov edx, dword ptr [eax]
// 0061e613  8b7204               mov esi, dword ptr [edx + 4]
// 0061e616  e9aa000000           jmp 0x61e6c5
// 0061e61b  3b7108               cmp esi, dword ptr [ecx + 8]
// 0061e61e  750a                 jne 0x61e62a
// 0061e620  8bf1                 mov esi, ecx
// 0061e622  56                   push esi
// 0061e623  8bcf                 mov ecx, edi
// 0061e625  e8e6f0eaff           call 0x4cd710
// 0061e62a  8b4604               mov eax, dword ptr [esi + 4]
// 0061e62d  885820               mov byte ptr [eax + 0x20], bl
// 0061e630  8b4e04               mov ecx, dword ptr [esi + 4]
// 0061e633  8b5104               mov edx, dword ptr [ecx + 4]
// 0061e636  c6422000             mov byte ptr [edx + 0x20], 0
// 0061e63a  8b4604               mov eax, dword ptr [esi + 4]
// 0061e63d  8b4804               mov ecx, dword ptr [eax + 4]
// 0061e640  51                   push ecx
// 0061e641  8bcf                 mov ecx, edi
// 0061e643  e8a81cebff           call 0x4d02f0
// 0061e648  eb7b                 jmp 0x61e6c5
// 0061e64a  8b12                 mov edx, dword ptr [edx]
// 0061e64c  807a2000             cmp byte ptr [edx + 0x20], 0
// 0061e650  7516                 jne 0x61e668
// 0061e652  885920               mov byte ptr [ecx + 0x20], bl
// 0061e655  885a20               mov byte ptr [edx + 0x20], bl
// 0061e658  8b10                 mov edx, dword ptr [eax]
// 0061e65a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0061e65d  c6412000             mov byte ptr [ecx + 0x20], 0
// 0061e661  8b10                 mov edx, dword ptr [eax]
// 0061e663  8b7204               mov esi, dword ptr [edx + 4]
// 0061e666  eb5d                 jmp 0x61e6c5
// 0061e668  3b31                 cmp esi, dword ptr [ecx]
// 0061e66a  750a                 jne 0x61e676
// 0061e66c  8bf1                 mov esi, ecx
// 0061e66e  56                   push esi
// 0061e66f  8bcf                 mov ecx, edi
// 0061e671  e87a1cebff           call 0x4d02f0
// 0061e676  8b4604               mov eax, dword ptr [esi + 4]
// 0061e679  885820               mov byte ptr [eax + 0x20], bl
// 0061e67c  8b4e04               mov ecx, dword ptr [esi + 4]
// 0061e67f  8b5104               mov edx, dword ptr [ecx + 4]
// 0061e682  c6422000             mov byte ptr [edx + 0x20], 0
// 0061e686  8b4604               mov eax, dword ptr [esi + 4]
// 0061e689  8b4004               mov eax, dword ptr [eax + 4]
// 0061e68c  8b4808               mov ecx, dword ptr [eax + 8]
// 0061e68f  8b11                 mov edx, dword ptr [ecx]
// 0061e691  895008               mov dword ptr [eax + 8], edx
// 0061e694  8b11                 mov edx, dword ptr [ecx]
// 0061e696  807a2100             cmp byte ptr [edx + 0x21], 0
// 0061e69a  7503                 jne 0x61e69f
// 0061e69c  894204               mov dword ptr [edx + 4], eax
// 0061e69f  8b5004               mov edx, dword ptr [eax + 4]
// 0061e6a2  895104               mov dword ptr [ecx + 4], edx
// 0061e6a5  8b5704               mov edx, dword ptr [edi + 4]
// 0061e6a8  3b4204               cmp eax, dword ptr [edx + 4]
// 0061e6ab  7505                 jne 0x61e6b2
// 0061e6ad  894a04               mov dword ptr [edx + 4], ecx
// 0061e6b0  eb0e                 jmp 0x61e6c0
// 0061e6b2  8b5004               mov edx, dword ptr [eax + 4]
// 0061e6b5  3b02                 cmp eax, dword ptr [edx]
// 0061e6b7  7504                 jne 0x61e6bd
// 0061e6b9  890a                 mov dword ptr [edx], ecx
// 0061e6bb  eb03                 jmp 0x61e6c0
// 0061e6bd  894a08               mov dword ptr [edx + 8], ecx
// 0061e6c0  8901                 mov dword ptr [ecx], eax
// 0061e6c2  894804               mov dword ptr [eax + 4], ecx
// 0061e6c5  8b4e04               mov ecx, dword ptr [esi + 4]
// 0061e6c8  80792000             cmp byte ptr [ecx + 0x20], 0
// 0061e6cc  8d4604               lea eax, [esi + 4]
// 0061e6cf  0f841bffffff         je 0x61e5f0
// 0061e6d5  8b5704               mov edx, dword ptr [edi + 4]
// 0061e6d8  8b4204               mov eax, dword ptr [edx + 4]
// 0061e6db  8b4c2454             mov ecx, dword ptr [esp + 0x54]
// 0061e6df  885820               mov byte ptr [eax + 0x20], bl
// 0061e6e2  8b442464             mov eax, dword ptr [esp + 0x64]
// 0061e6e6  5e                   pop esi
// 0061e6e7  896804               mov dword ptr [eax + 4], ebp
// 0061e6ea  5d                   pop ebp
// 0061e6eb  8938                 mov dword ptr [eax], edi
// 0061e6ed  5b                   pop ebx
// 0061e6ee  5f                   pop edi
// 0061e6ef  64890d00000000       mov dword ptr fs:[0], ecx
// 0061e6f6  83c450               add esp, 0x50
// 0061e6f9  c21000               ret 0x10
// standard library map_int<pod16> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod16>
struct E { int v[4]; };
#include <map>
template class std::map<int, E>;
