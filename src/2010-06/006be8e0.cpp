// from server: 100% by auto
// roc 2010-06 006be8e0  unit: RBX::VCollectionService::?$FactoryProduct  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 006be8e0
//
// 006be8e0  64a100000000         mov eax, dword ptr fs:[0]
// 006be8e6  6aff                 push -1
// 006be8e8  68e22f9a00           push 0x9a2fe2
// 006be8ed  50                   push eax
// 006be8ee  64892500000000       mov dword ptr fs:[0], esp
// 006be8f5  83ec44               sub esp, 0x44
// 006be8f8  57                   push edi
// 006be8f9  8bf9                 mov edi, ecx
// 006be8fb  817f1cc6711c07       cmp dword ptr [edi + 0x1c], 0x71c71c6
// 006be902  7259                 jb 0x6be95d
// 006be904  68a800a000           push 0xa000a8
// 006be909  8d4c2408             lea ecx, [esp + 8]
// 006be90d  ff1510a49e00         call dword ptr [0x9ea410]
// 006be913  8d4c2420             lea ecx, [esp + 0x20]
// 006be917  c744245000000000     mov dword ptr [esp + 0x50], 0
// 006be91f  ff1518a99e00         call dword ptr [0x9ea918]
// 006be925  8d442404             lea eax, [esp + 4]
// 006be929  50                   push eax
// 006be92a  8d4c2430             lea ecx, [esp + 0x30]
// 006be92e  c644245401           mov byte ptr [esp + 0x54], 1
// 006be933  c74424242c00a000     mov dword ptr [esp + 0x24], 0xa0002c
// 006be93b  ff150ca49e00         call dword ptr [0x9ea40c]
// 006be941  68601bb000           push 0xb01b60
// 006be946  8d4c2424             lea ecx, [esp + 0x24]
// 006be94a  51                   push ecx
// 006be94b  c644245800           mov byte ptr [esp + 0x58], 0
// 006be950  c74424283800a000     mov dword ptr [esp + 0x28], 0xa00038
// 006be958  e855a00e00           call 0x7a89b2
// 006be95d  8b542464             mov edx, dword ptr [esp + 0x64]
// 006be961  8b4718               mov eax, dword ptr [edi + 0x18]
// 006be964  53                   push ebx
// 006be965  55                   push ebp
// 006be966  56                   push esi
// 006be967  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 006be96b  6a00                 push 0
// 006be96d  52                   push edx
// 006be96e  50                   push eax
// 006be96f  56                   push esi
// 006be970  50                   push eax
// 006be971  e8ea44f3ff           call 0x5f2e60
// 006be976  8be8                 mov ebp, eax
// 006be978  8b4718               mov eax, dword ptr [edi + 0x18]
// 006be97b  bb01000000           mov ebx, 1
// 006be980  015f1c               add dword ptr [edi + 0x1c], ebx
// 006be983  3bf0                 cmp esi, eax
// 006be985  7510                 jne 0x6be997
// 006be987  896804               mov dword ptr [eax + 4], ebp
// 006be98a  8b4718               mov eax, dword ptr [edi + 0x18]
// 006be98d  8928                 mov dword ptr [eax], ebp
// 006be98f  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 006be992  896908               mov dword ptr [ecx + 8], ebp
// 006be995  eb22                 jmp 0x6be9b9
// 006be997  807c246800           cmp byte ptr [esp + 0x68], 0
// 006be99c  740d                 je 0x6be9ab
// 006be99e  892e                 mov dword ptr [esi], ebp
// 006be9a0  8b4718               mov eax, dword ptr [edi + 0x18]
// 006be9a3  3b30                 cmp esi, dword ptr [eax]
// 006be9a5  7512                 jne 0x6be9b9
// 006be9a7  8928                 mov dword ptr [eax], ebp
// 006be9a9  eb0e                 jmp 0x6be9b9
// 006be9ab  896e08               mov dword ptr [esi + 8], ebp
// 006be9ae  8b4718               mov eax, dword ptr [edi + 0x18]
// 006be9b1  3b7008               cmp esi, dword ptr [eax + 8]
// 006be9b4  7503                 jne 0x6be9b9
// 006be9b6  896808               mov dword ptr [eax + 8], ebp
// 006be9b9  8b5504               mov edx, dword ptr [ebp + 4]
// 006be9bc  807a3000             cmp byte ptr [edx + 0x30], 0
// 006be9c0  8d4504               lea eax, [ebp + 4]
// 006be9c3  8bf5                 mov esi, ebp
// 006be9c5  0f85ea000000         jne 0x6beab5
// 006be9cb  eb03                 jmp 0x6be9d0
// 006be9cd  8d4900               lea ecx, [ecx]
// 006be9d0  8b08                 mov ecx, dword ptr [eax]
// 006be9d2  8b5104               mov edx, dword ptr [ecx + 4]
// 006be9d5  3b0a                 cmp ecx, dword ptr [edx]
// 006be9d7  7551                 jne 0x6bea2a
// 006be9d9  8b5208               mov edx, dword ptr [edx + 8]
// 006be9dc  807a3000             cmp byte ptr [edx + 0x30], 0
// 006be9e0  7519                 jne 0x6be9fb
// 006be9e2  885930               mov byte ptr [ecx + 0x30], bl
// 006be9e5  885a30               mov byte ptr [edx + 0x30], bl
// 006be9e8  8b10                 mov edx, dword ptr [eax]
// 006be9ea  8b4a04               mov ecx, dword ptr [edx + 4]
// 006be9ed  c6413000             mov byte ptr [ecx + 0x30], 0
// 006be9f1  8b10                 mov edx, dword ptr [eax]
// 006be9f3  8b7204               mov esi, dword ptr [edx + 4]
// 006be9f6  e9aa000000           jmp 0x6beaa5
// 006be9fb  3b7108               cmp esi, dword ptr [ecx + 8]
// 006be9fe  750a                 jne 0x6bea0a
// 006bea00  8bf1                 mov esi, ecx
// 006bea02  56                   push esi
// 006bea03  8bcf                 mov ecx, edi
// 006bea05  e8160bfaff           call 0x65f520
// 006bea0a  8b4604               mov eax, dword ptr [esi + 4]
// 006bea0d  885830               mov byte ptr [eax + 0x30], bl
// 006bea10  8b4e04               mov ecx, dword ptr [esi + 4]
// 006bea13  8b5104               mov edx, dword ptr [ecx + 4]
// 006bea16  c6423000             mov byte ptr [edx + 0x30], 0
// 006bea1a  8b4604               mov eax, dword ptr [esi + 4]
// 006bea1d  8b4804               mov ecx, dword ptr [eax + 4]
// 006bea20  51                   push ecx
// 006bea21  8bcf                 mov ecx, edi
// 006bea23  e82814e0ff           call 0x4bfe50
// 006bea28  eb7b                 jmp 0x6beaa5
// 006bea2a  8b12                 mov edx, dword ptr [edx]
// 006bea2c  807a3000             cmp byte ptr [edx + 0x30], 0
// 006bea30  7516                 jne 0x6bea48
// 006bea32  885930               mov byte ptr [ecx + 0x30], bl
// 006bea35  885a30               mov byte ptr [edx + 0x30], bl
// 006bea38  8b10                 mov edx, dword ptr [eax]
// 006bea3a  8b4a04               mov ecx, dword ptr [edx + 4]
// 006bea3d  c6413000             mov byte ptr [ecx + 0x30], 0
// 006bea41  8b10                 mov edx, dword ptr [eax]
// 006bea43  8b7204               mov esi, dword ptr [edx + 4]
// 006bea46  eb5d                 jmp 0x6beaa5
// 006bea48  3b31                 cmp esi, dword ptr [ecx]
// 006bea4a  750a                 jne 0x6bea56
// 006bea4c  8bf1                 mov esi, ecx
// 006bea4e  56                   push esi
// 006bea4f  8bcf                 mov ecx, edi
// 006bea51  e8fa13e0ff           call 0x4bfe50
// 006bea56  8b4604               mov eax, dword ptr [esi + 4]
// 006bea59  885830               mov byte ptr [eax + 0x30], bl
// 006bea5c  8b4e04               mov ecx, dword ptr [esi + 4]
// 006bea5f  8b5104               mov edx, dword ptr [ecx + 4]
// 006bea62  c6423000             mov byte ptr [edx + 0x30], 0
// 006bea66  8b4604               mov eax, dword ptr [esi + 4]
// 006bea69  8b4004               mov eax, dword ptr [eax + 4]
// 006bea6c  8b4808               mov ecx, dword ptr [eax + 8]
// 006bea6f  8b11                 mov edx, dword ptr [ecx]
// 006bea71  895008               mov dword ptr [eax + 8], edx
// 006bea74  8b11                 mov edx, dword ptr [ecx]
// 006bea76  807a3100             cmp byte ptr [edx + 0x31], 0
// 006bea7a  7503                 jne 0x6bea7f
// 006bea7c  894204               mov dword ptr [edx + 4], eax
// 006bea7f  8b5004               mov edx, dword ptr [eax + 4]
// 006bea82  895104               mov dword ptr [ecx + 4], edx
// 006bea85  8b5718               mov edx, dword ptr [edi + 0x18]
// 006bea88  3b4204               cmp eax, dword ptr [edx + 4]
// 006bea8b  7505                 jne 0x6bea92
// 006bea8d  894a04               mov dword ptr [edx + 4], ecx
// 006bea90  eb0e                 jmp 0x6beaa0
// 006bea92  8b5004               mov edx, dword ptr [eax + 4]
// 006bea95  3b02                 cmp eax, dword ptr [edx]
// 006bea97  7504                 jne 0x6bea9d
// 006bea99  890a                 mov dword ptr [edx], ecx
// 006bea9b  eb03                 jmp 0x6beaa0
// 006bea9d  894a08               mov dword ptr [edx + 8], ecx
// 006beaa0  8901                 mov dword ptr [ecx], eax
// 006beaa2  894804               mov dword ptr [eax + 4], ecx
// 006beaa5  8b4e04               mov ecx, dword ptr [esi + 4]
// 006beaa8  80793000             cmp byte ptr [ecx + 0x30], 0
// 006beaac  8d4604               lea eax, [esi + 4]
// 006beaaf  0f841bffffff         je 0x6be9d0
// 006beab5  8b5718               mov edx, dword ptr [edi + 0x18]
// 006beab8  8b4204               mov eax, dword ptr [edx + 4]
// 006beabb  885830               mov byte ptr [eax + 0x30], bl
// 006beabe  8b442464             mov eax, dword ptr [esp + 0x64]
// 006beac2  8b0f                 mov ecx, dword ptr [edi]
// 006beac4  5e                   pop esi
// 006beac5  896804               mov dword ptr [eax + 4], ebp
// 006beac8  5d                   pop ebp
// 006beac9  8908                 mov dword ptr [eax], ecx
// 006beacb  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 006beacf  5b                   pop ebx
// 006bead0  5f                   pop edi
// 006bead1  64890d00000000       mov dword ptr fs:[0], ecx
// 006bead8  83c450               add esp, 0x50
// 006beadb  c21000               ret 0x10
// standard library map_int<pod32> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod32>
struct E { int v[8]; };
#include <map>
template class std::map<int, E>;
