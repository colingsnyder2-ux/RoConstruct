// from server: 100% by auto
// roc 2009-12 005cf4f0  unit: G3D::VVector3::?$Table  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005cf4f0
//
// 005cf4f0  64a100000000         mov eax, dword ptr fs:[0]
// 005cf4f6  6aff                 push -1
// 005cf4f8  6812699500           push 0x956912
// 005cf4fd  50                   push eax
// 005cf4fe  64892500000000       mov dword ptr fs:[0], esp
// 005cf505  83ec44               sub esp, 0x44
// 005cf508  57                   push edi
// 005cf509  8bf9                 mov edi, ecx
// 005cf50b  817f1ccbcccc0c       cmp dword ptr [edi + 0x1c], 0xccccccb
// 005cf512  7259                 jb 0x5cf56d
// 005cf514  6800f59900           push 0x99f500
// 005cf519  8d4c2408             lea ecx, [esp + 8]
// 005cf51d  ff15f4b69800         call dword ptr [0x98b6f4]
// 005cf523  8d4c2420             lea ecx, [esp + 0x20]
// 005cf527  c744245000000000     mov dword ptr [esp + 0x50], 0
// 005cf52f  ff1554b79800         call dword ptr [0x98b754]
// 005cf535  8d442404             lea eax, [esp + 4]
// 005cf539  50                   push eax
// 005cf53a  8d4c2430             lea ecx, [esp + 0x30]
// 005cf53e  c644245401           mov byte ptr [esp + 0x54], 1
// 005cf543  c744242484f49900     mov dword ptr [esp + 0x24], 0x99f484
// 005cf54b  ff15f0b69800         call dword ptr [0x98b6f0]
// 005cf551  68e4efa800           push 0xa8efe4
// 005cf556  8d4c2424             lea ecx, [esp + 0x24]
// 005cf55a  51                   push ecx
// 005cf55b  c644245800           mov byte ptr [esp + 0x58], 0
// 005cf560  c744242890f49900     mov dword ptr [esp + 0x28], 0x99f490
// 005cf568  e80b532200           call 0x7f4878
// 005cf56d  8b542464             mov edx, dword ptr [esp + 0x64]
// 005cf571  8b4718               mov eax, dword ptr [edi + 0x18]
// 005cf574  53                   push ebx
// 005cf575  55                   push ebp
// 005cf576  56                   push esi
// 005cf577  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 005cf57b  6a00                 push 0
// 005cf57d  52                   push edx
// 005cf57e  50                   push eax
// 005cf57f  56                   push esi
// 005cf580  50                   push eax
// 005cf581  e8baf7ffff           call 0x5ced40
// 005cf586  8be8                 mov ebp, eax
// 005cf588  8b4718               mov eax, dword ptr [edi + 0x18]
// 005cf58b  bb01000000           mov ebx, 1
// 005cf590  015f1c               add dword ptr [edi + 0x1c], ebx
// 005cf593  3bf0                 cmp esi, eax
// 005cf595  7510                 jne 0x5cf5a7
// 005cf597  896804               mov dword ptr [eax + 4], ebp
// 005cf59a  8b4718               mov eax, dword ptr [edi + 0x18]
// 005cf59d  8928                 mov dword ptr [eax], ebp
// 005cf59f  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 005cf5a2  896908               mov dword ptr [ecx + 8], ebp
// 005cf5a5  eb22                 jmp 0x5cf5c9
// 005cf5a7  807c246800           cmp byte ptr [esp + 0x68], 0
// 005cf5ac  740d                 je 0x5cf5bb
// 005cf5ae  892e                 mov dword ptr [esi], ebp
// 005cf5b0  8b4718               mov eax, dword ptr [edi + 0x18]
// 005cf5b3  3b30                 cmp esi, dword ptr [eax]
// 005cf5b5  7512                 jne 0x5cf5c9
// 005cf5b7  8928                 mov dword ptr [eax], ebp
// 005cf5b9  eb0e                 jmp 0x5cf5c9
// 005cf5bb  896e08               mov dword ptr [esi + 8], ebp
// 005cf5be  8b4718               mov eax, dword ptr [edi + 0x18]
// 005cf5c1  3b7008               cmp esi, dword ptr [eax + 8]
// 005cf5c4  7503                 jne 0x5cf5c9
// 005cf5c6  896808               mov dword ptr [eax + 8], ebp
// 005cf5c9  8b5504               mov edx, dword ptr [ebp + 4]
// 005cf5cc  807a2000             cmp byte ptr [edx + 0x20], 0
// 005cf5d0  8d4504               lea eax, [ebp + 4]
// 005cf5d3  8bf5                 mov esi, ebp
// 005cf5d5  0f85ea000000         jne 0x5cf6c5
// 005cf5db  eb03                 jmp 0x5cf5e0
// 005cf5dd  8d4900               lea ecx, [ecx]
// 005cf5e0  8b08                 mov ecx, dword ptr [eax]
// 005cf5e2  8b5104               mov edx, dword ptr [ecx + 4]
// 005cf5e5  3b0a                 cmp ecx, dword ptr [edx]
// 005cf5e7  7551                 jne 0x5cf63a
// 005cf5e9  8b5208               mov edx, dword ptr [edx + 8]
// 005cf5ec  807a2000             cmp byte ptr [edx + 0x20], 0
// 005cf5f0  7519                 jne 0x5cf60b
// 005cf5f2  885920               mov byte ptr [ecx + 0x20], bl
// 005cf5f5  885a20               mov byte ptr [edx + 0x20], bl
// 005cf5f8  8b10                 mov edx, dword ptr [eax]
// 005cf5fa  8b4a04               mov ecx, dword ptr [edx + 4]
// 005cf5fd  c6412000             mov byte ptr [ecx + 0x20], 0
// 005cf601  8b10                 mov edx, dword ptr [eax]
// 005cf603  8b7204               mov esi, dword ptr [edx + 4]
// 005cf606  e9aa000000           jmp 0x5cf6b5
// 005cf60b  3b7108               cmp esi, dword ptr [ecx + 8]
// 005cf60e  750a                 jne 0x5cf61a
// 005cf610  8bf1                 mov esi, ecx
// 005cf612  56                   push esi
// 005cf613  8bcf                 mov ecx, edi
// 005cf615  e846ddffff           call 0x5cd360
// 005cf61a  8b4604               mov eax, dword ptr [esi + 4]
// 005cf61d  885820               mov byte ptr [eax + 0x20], bl
// 005cf620  8b4e04               mov ecx, dword ptr [esi + 4]
// 005cf623  8b5104               mov edx, dword ptr [ecx + 4]
// 005cf626  c6422000             mov byte ptr [edx + 0x20], 0
// 005cf62a  8b4604               mov eax, dword ptr [esi + 4]
// 005cf62d  8b4804               mov ecx, dword ptr [eax + 4]
// 005cf630  51                   push ecx
// 005cf631  8bcf                 mov ecx, edi
// 005cf633  e848cfffff           call 0x5cc580
// 005cf638  eb7b                 jmp 0x5cf6b5
// 005cf63a  8b12                 mov edx, dword ptr [edx]
// 005cf63c  807a2000             cmp byte ptr [edx + 0x20], 0
// 005cf640  7516                 jne 0x5cf658
// 005cf642  885920               mov byte ptr [ecx + 0x20], bl
// 005cf645  885a20               mov byte ptr [edx + 0x20], bl
// 005cf648  8b10                 mov edx, dword ptr [eax]
// 005cf64a  8b4a04               mov ecx, dword ptr [edx + 4]
// 005cf64d  c6412000             mov byte ptr [ecx + 0x20], 0
// 005cf651  8b10                 mov edx, dword ptr [eax]
// 005cf653  8b7204               mov esi, dword ptr [edx + 4]
// 005cf656  eb5d                 jmp 0x5cf6b5
// 005cf658  3b31                 cmp esi, dword ptr [ecx]
// 005cf65a  750a                 jne 0x5cf666
// 005cf65c  8bf1                 mov esi, ecx
// 005cf65e  56                   push esi
// 005cf65f  8bcf                 mov ecx, edi
// 005cf661  e81acfffff           call 0x5cc580
// 005cf666  8b4604               mov eax, dword ptr [esi + 4]
// 005cf669  885820               mov byte ptr [eax + 0x20], bl
// 005cf66c  8b4e04               mov ecx, dword ptr [esi + 4]
// 005cf66f  8b5104               mov edx, dword ptr [ecx + 4]
// 005cf672  c6422000             mov byte ptr [edx + 0x20], 0
// 005cf676  8b4604               mov eax, dword ptr [esi + 4]
// 005cf679  8b4004               mov eax, dword ptr [eax + 4]
// 005cf67c  8b4808               mov ecx, dword ptr [eax + 8]
// 005cf67f  8b11                 mov edx, dword ptr [ecx]
// 005cf681  895008               mov dword ptr [eax + 8], edx
// 005cf684  8b11                 mov edx, dword ptr [ecx]
// 005cf686  807a2100             cmp byte ptr [edx + 0x21], 0
// 005cf68a  7503                 jne 0x5cf68f
// 005cf68c  894204               mov dword ptr [edx + 4], eax
// 005cf68f  8b5004               mov edx, dword ptr [eax + 4]
// 005cf692  895104               mov dword ptr [ecx + 4], edx
// 005cf695  8b5718               mov edx, dword ptr [edi + 0x18]
// 005cf698  3b4204               cmp eax, dword ptr [edx + 4]
// 005cf69b  7505                 jne 0x5cf6a2
// 005cf69d  894a04               mov dword ptr [edx + 4], ecx
// 005cf6a0  eb0e                 jmp 0x5cf6b0
// 005cf6a2  8b5004               mov edx, dword ptr [eax + 4]
// 005cf6a5  3b02                 cmp eax, dword ptr [edx]
// 005cf6a7  7504                 jne 0x5cf6ad
// 005cf6a9  890a                 mov dword ptr [edx], ecx
// 005cf6ab  eb03                 jmp 0x5cf6b0
// 005cf6ad  894a08               mov dword ptr [edx + 8], ecx
// 005cf6b0  8901                 mov dword ptr [ecx], eax
// 005cf6b2  894804               mov dword ptr [eax + 4], ecx
// 005cf6b5  8b4e04               mov ecx, dword ptr [esi + 4]
// 005cf6b8  80792000             cmp byte ptr [ecx + 0x20], 0
// 005cf6bc  8d4604               lea eax, [esi + 4]
// 005cf6bf  0f841bffffff         je 0x5cf5e0
// 005cf6c5  8b5718               mov edx, dword ptr [edi + 0x18]
// 005cf6c8  8b4204               mov eax, dword ptr [edx + 4]
// 005cf6cb  885820               mov byte ptr [eax + 0x20], bl
// 005cf6ce  8b442464             mov eax, dword ptr [esp + 0x64]
// 005cf6d2  8b0f                 mov ecx, dword ptr [edi]
// 005cf6d4  5e                   pop esi
// 005cf6d5  896804               mov dword ptr [eax + 4], ebp
// 005cf6d8  5d                   pop ebp
// 005cf6d9  8908                 mov dword ptr [eax], ecx
// 005cf6db  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 005cf6df  5b                   pop ebx
// 005cf6e0  5f                   pop edi
// 005cf6e1  64890d00000000       mov dword ptr fs:[0], ecx
// 005cf6e8  83c450               add esp, 0x50
// 005cf6eb  c21000               ret 0x10
// standard library map_int<pod16> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod16>
struct E { int v[4]; };
#include <map>
template class std::map<int, E>;
