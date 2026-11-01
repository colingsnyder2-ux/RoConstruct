// from server: 100% by auto
// roc 2009-12 006ad520  unit: RBX::Accoutrement  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006ad520
//
// 006ad520  64a100000000         mov eax, dword ptr fs:[0]
// 006ad526  6aff                 push -1
// 006ad528  6812699500           push 0x956912
// 006ad52d  50                   push eax
// 006ad52e  64892500000000       mov dword ptr fs:[0], esp
// 006ad535  83ec44               sub esp, 0x44
// 006ad538  57                   push edi
// 006ad539  8bf9                 mov edi, ecx
// 006ad53b  817f1ccbcccc0c       cmp dword ptr [edi + 0x1c], 0xccccccb
// 006ad542  7259                 jb 0x6ad59d
// 006ad544  6800f59900           push 0x99f500
// 006ad549  8d4c2408             lea ecx, [esp + 8]
// 006ad54d  ff15f4b69800         call dword ptr [0x98b6f4]
// 006ad553  8d4c2420             lea ecx, [esp + 0x20]
// 006ad557  c744245000000000     mov dword ptr [esp + 0x50], 0
// 006ad55f  ff1554b79800         call dword ptr [0x98b754]
// 006ad565  8d442404             lea eax, [esp + 4]
// 006ad569  50                   push eax
// 006ad56a  8d4c2430             lea ecx, [esp + 0x30]
// 006ad56e  c644245401           mov byte ptr [esp + 0x54], 1
// 006ad573  c744242484f49900     mov dword ptr [esp + 0x24], 0x99f484
// 006ad57b  ff15f0b69800         call dword ptr [0x98b6f0]
// 006ad581  68e4efa800           push 0xa8efe4
// 006ad586  8d4c2424             lea ecx, [esp + 0x24]
// 006ad58a  51                   push ecx
// 006ad58b  c644245800           mov byte ptr [esp + 0x58], 0
// 006ad590  c744242890f49900     mov dword ptr [esp + 0x28], 0x99f490
// 006ad598  e8db721400           call 0x7f4878
// 006ad59d  8b542464             mov edx, dword ptr [esp + 0x64]
// 006ad5a1  8b4718               mov eax, dword ptr [edi + 0x18]
// 006ad5a4  53                   push ebx
// 006ad5a5  55                   push ebp
// 006ad5a6  56                   push esi
// 006ad5a7  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 006ad5ab  6a00                 push 0
// 006ad5ad  52                   push edx
// 006ad5ae  50                   push eax
// 006ad5af  56                   push esi
// 006ad5b0  50                   push eax
// 006ad5b1  e8aafbffff           call 0x6ad160
// 006ad5b6  8be8                 mov ebp, eax
// 006ad5b8  8b4718               mov eax, dword ptr [edi + 0x18]
// 006ad5bb  bb01000000           mov ebx, 1
// 006ad5c0  015f1c               add dword ptr [edi + 0x1c], ebx
// 006ad5c3  3bf0                 cmp esi, eax
// 006ad5c5  7510                 jne 0x6ad5d7
// 006ad5c7  896804               mov dword ptr [eax + 4], ebp
// 006ad5ca  8b4718               mov eax, dword ptr [edi + 0x18]
// 006ad5cd  8928                 mov dword ptr [eax], ebp
// 006ad5cf  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 006ad5d2  896908               mov dword ptr [ecx + 8], ebp
// 006ad5d5  eb22                 jmp 0x6ad5f9
// 006ad5d7  807c246800           cmp byte ptr [esp + 0x68], 0
// 006ad5dc  740d                 je 0x6ad5eb
// 006ad5de  892e                 mov dword ptr [esi], ebp
// 006ad5e0  8b4718               mov eax, dword ptr [edi + 0x18]
// 006ad5e3  3b30                 cmp esi, dword ptr [eax]
// 006ad5e5  7512                 jne 0x6ad5f9
// 006ad5e7  8928                 mov dword ptr [eax], ebp
// 006ad5e9  eb0e                 jmp 0x6ad5f9
// 006ad5eb  896e08               mov dword ptr [esi + 8], ebp
// 006ad5ee  8b4718               mov eax, dword ptr [edi + 0x18]
// 006ad5f1  3b7008               cmp esi, dword ptr [eax + 8]
// 006ad5f4  7503                 jne 0x6ad5f9
// 006ad5f6  896808               mov dword ptr [eax + 8], ebp
// 006ad5f9  8b5504               mov edx, dword ptr [ebp + 4]
// 006ad5fc  807a2000             cmp byte ptr [edx + 0x20], 0
// 006ad600  8d4504               lea eax, [ebp + 4]
// 006ad603  8bf5                 mov esi, ebp
// 006ad605  0f85ea000000         jne 0x6ad6f5
// 006ad60b  eb03                 jmp 0x6ad610
// 006ad60d  8d4900               lea ecx, [ecx]
// 006ad610  8b08                 mov ecx, dword ptr [eax]
// 006ad612  8b5104               mov edx, dword ptr [ecx + 4]
// 006ad615  3b0a                 cmp ecx, dword ptr [edx]
// 006ad617  7551                 jne 0x6ad66a
// 006ad619  8b5208               mov edx, dword ptr [edx + 8]
// 006ad61c  807a2000             cmp byte ptr [edx + 0x20], 0
// 006ad620  7519                 jne 0x6ad63b
// 006ad622  885920               mov byte ptr [ecx + 0x20], bl
// 006ad625  885a20               mov byte ptr [edx + 0x20], bl
// 006ad628  8b10                 mov edx, dword ptr [eax]
// 006ad62a  8b4a04               mov ecx, dword ptr [edx + 4]
// 006ad62d  c6412000             mov byte ptr [ecx + 0x20], 0
// 006ad631  8b10                 mov edx, dword ptr [eax]
// 006ad633  8b7204               mov esi, dword ptr [edx + 4]
// 006ad636  e9aa000000           jmp 0x6ad6e5
// 006ad63b  3b7108               cmp esi, dword ptr [ecx + 8]
// 006ad63e  750a                 jne 0x6ad64a
// 006ad640  8bf1                 mov esi, ecx
// 006ad642  56                   push esi
// 006ad643  8bcf                 mov ecx, edi
// 006ad645  e816fdf1ff           call 0x5cd360
// 006ad64a  8b4604               mov eax, dword ptr [esi + 4]
// 006ad64d  885820               mov byte ptr [eax + 0x20], bl
// 006ad650  8b4e04               mov ecx, dword ptr [esi + 4]
// 006ad653  8b5104               mov edx, dword ptr [ecx + 4]
// 006ad656  c6422000             mov byte ptr [edx + 0x20], 0
// 006ad65a  8b4604               mov eax, dword ptr [esi + 4]
// 006ad65d  8b4804               mov ecx, dword ptr [eax + 4]
// 006ad660  51                   push ecx
// 006ad661  8bcf                 mov ecx, edi
// 006ad663  e818eff1ff           call 0x5cc580
// 006ad668  eb7b                 jmp 0x6ad6e5
// 006ad66a  8b12                 mov edx, dword ptr [edx]
// 006ad66c  807a2000             cmp byte ptr [edx + 0x20], 0
// 006ad670  7516                 jne 0x6ad688
// 006ad672  885920               mov byte ptr [ecx + 0x20], bl
// 006ad675  885a20               mov byte ptr [edx + 0x20], bl
// 006ad678  8b10                 mov edx, dword ptr [eax]
// 006ad67a  8b4a04               mov ecx, dword ptr [edx + 4]
// 006ad67d  c6412000             mov byte ptr [ecx + 0x20], 0
// 006ad681  8b10                 mov edx, dword ptr [eax]
// 006ad683  8b7204               mov esi, dword ptr [edx + 4]
// 006ad686  eb5d                 jmp 0x6ad6e5
// 006ad688  3b31                 cmp esi, dword ptr [ecx]
// 006ad68a  750a                 jne 0x6ad696
// 006ad68c  8bf1                 mov esi, ecx
// 006ad68e  56                   push esi
// 006ad68f  8bcf                 mov ecx, edi
// 006ad691  e8eaeef1ff           call 0x5cc580
// 006ad696  8b4604               mov eax, dword ptr [esi + 4]
// 006ad699  885820               mov byte ptr [eax + 0x20], bl
// 006ad69c  8b4e04               mov ecx, dword ptr [esi + 4]
// 006ad69f  8b5104               mov edx, dword ptr [ecx + 4]
// 006ad6a2  c6422000             mov byte ptr [edx + 0x20], 0
// 006ad6a6  8b4604               mov eax, dword ptr [esi + 4]
// 006ad6a9  8b4004               mov eax, dword ptr [eax + 4]
// 006ad6ac  8b4808               mov ecx, dword ptr [eax + 8]
// 006ad6af  8b11                 mov edx, dword ptr [ecx]
// 006ad6b1  895008               mov dword ptr [eax + 8], edx
// 006ad6b4  8b11                 mov edx, dword ptr [ecx]
// 006ad6b6  807a2100             cmp byte ptr [edx + 0x21], 0
// 006ad6ba  7503                 jne 0x6ad6bf
// 006ad6bc  894204               mov dword ptr [edx + 4], eax
// 006ad6bf  8b5004               mov edx, dword ptr [eax + 4]
// 006ad6c2  895104               mov dword ptr [ecx + 4], edx
// 006ad6c5  8b5718               mov edx, dword ptr [edi + 0x18]
// 006ad6c8  3b4204               cmp eax, dword ptr [edx + 4]
// 006ad6cb  7505                 jne 0x6ad6d2
// 006ad6cd  894a04               mov dword ptr [edx + 4], ecx
// 006ad6d0  eb0e                 jmp 0x6ad6e0
// 006ad6d2  8b5004               mov edx, dword ptr [eax + 4]
// 006ad6d5  3b02                 cmp eax, dword ptr [edx]
// 006ad6d7  7504                 jne 0x6ad6dd
// 006ad6d9  890a                 mov dword ptr [edx], ecx
// 006ad6db  eb03                 jmp 0x6ad6e0
// 006ad6dd  894a08               mov dword ptr [edx + 8], ecx
// 006ad6e0  8901                 mov dword ptr [ecx], eax
// 006ad6e2  894804               mov dword ptr [eax + 4], ecx
// 006ad6e5  8b4e04               mov ecx, dword ptr [esi + 4]
// 006ad6e8  80792000             cmp byte ptr [ecx + 0x20], 0
// 006ad6ec  8d4604               lea eax, [esi + 4]
// 006ad6ef  0f841bffffff         je 0x6ad610
// 006ad6f5  8b5718               mov edx, dword ptr [edi + 0x18]
// 006ad6f8  8b4204               mov eax, dword ptr [edx + 4]
// 006ad6fb  885820               mov byte ptr [eax + 0x20], bl
// 006ad6fe  8b442464             mov eax, dword ptr [esp + 0x64]
// 006ad702  8b0f                 mov ecx, dword ptr [edi]
// 006ad704  5e                   pop esi
// 006ad705  896804               mov dword ptr [eax + 4], ebp
// 006ad708  5d                   pop ebp
// 006ad709  8908                 mov dword ptr [eax], ecx
// 006ad70b  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 006ad70f  5b                   pop ebx
// 006ad710  5f                   pop edi
// 006ad711  64890d00000000       mov dword ptr fs:[0], ecx
// 006ad718  83c450               add esp, 0x50
// 006ad71b  c21000               ret 0x10
// standard library map_int<pod16> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod16>
struct E { int v[4]; };
#include <map>
template class std::map<int, E>;
