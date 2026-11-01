// from server: 100% by auto
// roc 2009-12 006bea10  unit: RBX::VInstance::?$NonFactoryProduct  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006bea10
//
// 006bea10  64a100000000         mov eax, dword ptr fs:[0]
// 006bea16  6aff                 push -1
// 006bea18  6812699500           push 0x956912
// 006bea1d  50                   push eax
// 006bea1e  64892500000000       mov dword ptr fs:[0], esp
// 006bea25  83ec44               sub esp, 0x44
// 006bea28  57                   push edi
// 006bea29  8bf9                 mov edi, ecx
// 006bea2b  817f1c65666606       cmp dword ptr [edi + 0x1c], 0x6666665
// 006bea32  7259                 jb 0x6bea8d
// 006bea34  6800f59900           push 0x99f500
// 006bea39  8d4c2408             lea ecx, [esp + 8]
// 006bea3d  ff15f4b69800         call dword ptr [0x98b6f4]
// 006bea43  8d4c2420             lea ecx, [esp + 0x20]
// 006bea47  c744245000000000     mov dword ptr [esp + 0x50], 0
// 006bea4f  ff1554b79800         call dword ptr [0x98b754]
// 006bea55  8d442404             lea eax, [esp + 4]
// 006bea59  50                   push eax
// 006bea5a  8d4c2430             lea ecx, [esp + 0x30]
// 006bea5e  c644245401           mov byte ptr [esp + 0x54], 1
// 006bea63  c744242484f49900     mov dword ptr [esp + 0x24], 0x99f484
// 006bea6b  ff15f0b69800         call dword ptr [0x98b6f0]
// 006bea71  68e4efa800           push 0xa8efe4
// 006bea76  8d4c2424             lea ecx, [esp + 0x24]
// 006bea7a  51                   push ecx
// 006bea7b  c644245800           mov byte ptr [esp + 0x58], 0
// 006bea80  c744242890f49900     mov dword ptr [esp + 0x28], 0x99f490
// 006bea88  e8eb5d1300           call 0x7f4878
// 006bea8d  8b542464             mov edx, dword ptr [esp + 0x64]
// 006bea91  8b4718               mov eax, dword ptr [edi + 0x18]
// 006bea94  53                   push ebx
// 006bea95  55                   push ebp
// 006bea96  56                   push esi
// 006bea97  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 006bea9b  6a00                 push 0
// 006bea9d  52                   push edx
// 006bea9e  50                   push eax
// 006bea9f  56                   push esi
// 006beaa0  50                   push eax
// 006beaa1  e83af2ffff           call 0x6bdce0
// 006beaa6  8be8                 mov ebp, eax
// 006beaa8  8b4718               mov eax, dword ptr [edi + 0x18]
// 006beaab  bb01000000           mov ebx, 1
// 006beab0  015f1c               add dword ptr [edi + 0x1c], ebx
// 006beab3  3bf0                 cmp esi, eax
// 006beab5  7510                 jne 0x6beac7
// 006beab7  896804               mov dword ptr [eax + 4], ebp
// 006beaba  8b4718               mov eax, dword ptr [edi + 0x18]
// 006beabd  8928                 mov dword ptr [eax], ebp
// 006beabf  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 006beac2  896908               mov dword ptr [ecx + 8], ebp
// 006beac5  eb22                 jmp 0x6beae9
// 006beac7  807c246800           cmp byte ptr [esp + 0x68], 0
// 006beacc  740d                 je 0x6beadb
// 006beace  892e                 mov dword ptr [esi], ebp
// 006bead0  8b4718               mov eax, dword ptr [edi + 0x18]
// 006bead3  3b30                 cmp esi, dword ptr [eax]
// 006bead5  7512                 jne 0x6beae9
// 006bead7  8928                 mov dword ptr [eax], ebp
// 006bead9  eb0e                 jmp 0x6beae9
// 006beadb  896e08               mov dword ptr [esi + 8], ebp
// 006beade  8b4718               mov eax, dword ptr [edi + 0x18]
// 006beae1  3b7008               cmp esi, dword ptr [eax + 8]
// 006beae4  7503                 jne 0x6beae9
// 006beae6  896808               mov dword ptr [eax + 8], ebp
// 006beae9  8b5504               mov edx, dword ptr [ebp + 4]
// 006beaec  807a3400             cmp byte ptr [edx + 0x34], 0
// 006beaf0  8d4504               lea eax, [ebp + 4]
// 006beaf3  8bf5                 mov esi, ebp
// 006beaf5  0f85ea000000         jne 0x6bebe5
// 006beafb  eb03                 jmp 0x6beb00
// 006beafd  8d4900               lea ecx, [ecx]
// 006beb00  8b08                 mov ecx, dword ptr [eax]
// 006beb02  8b5104               mov edx, dword ptr [ecx + 4]
// 006beb05  3b0a                 cmp ecx, dword ptr [edx]
// 006beb07  7551                 jne 0x6beb5a
// 006beb09  8b5208               mov edx, dword ptr [edx + 8]
// 006beb0c  807a3400             cmp byte ptr [edx + 0x34], 0
// 006beb10  7519                 jne 0x6beb2b
// 006beb12  885934               mov byte ptr [ecx + 0x34], bl
// 006beb15  885a34               mov byte ptr [edx + 0x34], bl
// 006beb18  8b10                 mov edx, dword ptr [eax]
// 006beb1a  8b4a04               mov ecx, dword ptr [edx + 4]
// 006beb1d  c6413400             mov byte ptr [ecx + 0x34], 0
// 006beb21  8b10                 mov edx, dword ptr [eax]
// 006beb23  8b7204               mov esi, dword ptr [edx + 4]
// 006beb26  e9aa000000           jmp 0x6bebd5
// 006beb2b  3b7108               cmp esi, dword ptr [ecx + 8]
// 006beb2e  750a                 jne 0x6beb3a
// 006beb30  8bf1                 mov esi, ecx
// 006beb32  56                   push esi
// 006beb33  8bcf                 mov ecx, edi
// 006beb35  e8e6e8ffff           call 0x6bd420
// 006beb3a  8b4604               mov eax, dword ptr [esi + 4]
// 006beb3d  885834               mov byte ptr [eax + 0x34], bl
// 006beb40  8b4e04               mov ecx, dword ptr [esi + 4]
// 006beb43  8b5104               mov edx, dword ptr [ecx + 4]
// 006beb46  c6423400             mov byte ptr [edx + 0x34], 0
// 006beb4a  8b4604               mov eax, dword ptr [esi + 4]
// 006beb4d  8b4804               mov ecx, dword ptr [eax + 4]
// 006beb50  51                   push ecx
// 006beb51  8bcf                 mov ecx, edi
// 006beb53  e8c84effff           call 0x6b3a20
// 006beb58  eb7b                 jmp 0x6bebd5
// 006beb5a  8b12                 mov edx, dword ptr [edx]
// 006beb5c  807a3400             cmp byte ptr [edx + 0x34], 0
// 006beb60  7516                 jne 0x6beb78
// 006beb62  885934               mov byte ptr [ecx + 0x34], bl
// 006beb65  885a34               mov byte ptr [edx + 0x34], bl
// 006beb68  8b10                 mov edx, dword ptr [eax]
// 006beb6a  8b4a04               mov ecx, dword ptr [edx + 4]
// 006beb6d  c6413400             mov byte ptr [ecx + 0x34], 0
// 006beb71  8b10                 mov edx, dword ptr [eax]
// 006beb73  8b7204               mov esi, dword ptr [edx + 4]
// 006beb76  eb5d                 jmp 0x6bebd5
// 006beb78  3b31                 cmp esi, dword ptr [ecx]
// 006beb7a  750a                 jne 0x6beb86
// 006beb7c  8bf1                 mov esi, ecx
// 006beb7e  56                   push esi
// 006beb7f  8bcf                 mov ecx, edi
// 006beb81  e89a4effff           call 0x6b3a20
// 006beb86  8b4604               mov eax, dword ptr [esi + 4]
// 006beb89  885834               mov byte ptr [eax + 0x34], bl
// 006beb8c  8b4e04               mov ecx, dword ptr [esi + 4]
// 006beb8f  8b5104               mov edx, dword ptr [ecx + 4]
// 006beb92  c6423400             mov byte ptr [edx + 0x34], 0
// 006beb96  8b4604               mov eax, dword ptr [esi + 4]
// 006beb99  8b4004               mov eax, dword ptr [eax + 4]
// 006beb9c  8b4808               mov ecx, dword ptr [eax + 8]
// 006beb9f  8b11                 mov edx, dword ptr [ecx]
// 006beba1  895008               mov dword ptr [eax + 8], edx
// 006beba4  8b11                 mov edx, dword ptr [ecx]
// 006beba6  807a3500             cmp byte ptr [edx + 0x35], 0
// 006bebaa  7503                 jne 0x6bebaf
// 006bebac  894204               mov dword ptr [edx + 4], eax
// 006bebaf  8b5004               mov edx, dword ptr [eax + 4]
// 006bebb2  895104               mov dword ptr [ecx + 4], edx
// 006bebb5  8b5718               mov edx, dword ptr [edi + 0x18]
// 006bebb8  3b4204               cmp eax, dword ptr [edx + 4]
// 006bebbb  7505                 jne 0x6bebc2
// 006bebbd  894a04               mov dword ptr [edx + 4], ecx
// 006bebc0  eb0e                 jmp 0x6bebd0
// 006bebc2  8b5004               mov edx, dword ptr [eax + 4]
// 006bebc5  3b02                 cmp eax, dword ptr [edx]
// 006bebc7  7504                 jne 0x6bebcd
// 006bebc9  890a                 mov dword ptr [edx], ecx
// 006bebcb  eb03                 jmp 0x6bebd0
// 006bebcd  894a08               mov dword ptr [edx + 8], ecx
// 006bebd0  8901                 mov dword ptr [ecx], eax
// 006bebd2  894804               mov dword ptr [eax + 4], ecx
// 006bebd5  8b4e04               mov ecx, dword ptr [esi + 4]
// 006bebd8  80793400             cmp byte ptr [ecx + 0x34], 0
// 006bebdc  8d4604               lea eax, [esi + 4]
// 006bebdf  0f841bffffff         je 0x6beb00
// 006bebe5  8b5718               mov edx, dword ptr [edi + 0x18]
// 006bebe8  8b4204               mov eax, dword ptr [edx + 4]
// 006bebeb  885834               mov byte ptr [eax + 0x34], bl
// 006bebee  8b442464             mov eax, dword ptr [esp + 0x64]
// 006bebf2  8b0f                 mov ecx, dword ptr [edi]
// 006bebf4  5e                   pop esi
// 006bebf5  896804               mov dword ptr [eax + 4], ebp
// 006bebf8  5d                   pop ebp
// 006bebf9  8908                 mov dword ptr [eax], ecx
// 006bebfb  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 006bebff  5b                   pop ebx
// 006bec00  5f                   pop edi
// 006bec01  64890d00000000       mov dword ptr fs:[0], ecx
// 006bec08  83c450               add esp, 0x50
// 006bec0b  c21000               ret 0x10
// standard library map_int<pod36> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod36>
struct E { int v[9]; };
#include <map>
template class std::map<int, E>;
