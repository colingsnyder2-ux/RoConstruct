// from server: 100% by auto
// roc 2009-12 007c6df0  unit: RBX::ScoreHud  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007c6df0
//
// 007c6df0  64a100000000         mov eax, dword ptr fs:[0]
// 007c6df6  6aff                 push -1
// 007c6df8  6812699500           push 0x956912
// 007c6dfd  50                   push eax
// 007c6dfe  64892500000000       mov dword ptr fs:[0], esp
// 007c6e05  83ec44               sub esp, 0x44
// 007c6e08  57                   push edi
// 007c6e09  8bf9                 mov edi, ecx
// 007c6e0b  817f1c48922409       cmp dword ptr [edi + 0x1c], 0x9249248
// 007c6e12  7259                 jb 0x7c6e6d
// 007c6e14  6800f59900           push 0x99f500
// 007c6e19  8d4c2408             lea ecx, [esp + 8]
// 007c6e1d  ff15f4b69800         call dword ptr [0x98b6f4]
// 007c6e23  8d4c2420             lea ecx, [esp + 0x20]
// 007c6e27  c744245000000000     mov dword ptr [esp + 0x50], 0
// 007c6e2f  ff1554b79800         call dword ptr [0x98b754]
// 007c6e35  8d442404             lea eax, [esp + 4]
// 007c6e39  50                   push eax
// 007c6e3a  8d4c2430             lea ecx, [esp + 0x30]
// 007c6e3e  c644245401           mov byte ptr [esp + 0x54], 1
// 007c6e43  c744242484f49900     mov dword ptr [esp + 0x24], 0x99f484
// 007c6e4b  ff15f0b69800         call dword ptr [0x98b6f0]
// 007c6e51  68e4efa800           push 0xa8efe4
// 007c6e56  8d4c2424             lea ecx, [esp + 0x24]
// 007c6e5a  51                   push ecx
// 007c6e5b  c644245800           mov byte ptr [esp + 0x58], 0
// 007c6e60  c744242890f49900     mov dword ptr [esp + 0x28], 0x99f490
// 007c6e68  e80bda0200           call 0x7f4878
// 007c6e6d  8b542464             mov edx, dword ptr [esp + 0x64]
// 007c6e71  8b4718               mov eax, dword ptr [edi + 0x18]
// 007c6e74  53                   push ebx
// 007c6e75  55                   push ebp
// 007c6e76  56                   push esi
// 007c6e77  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 007c6e7b  6a00                 push 0
// 007c6e7d  52                   push edx
// 007c6e7e  50                   push eax
// 007c6e7f  56                   push esi
// 007c6e80  50                   push eax
// 007c6e81  e88afdffff           call 0x7c6c10
// 007c6e86  8be8                 mov ebp, eax
// 007c6e88  8b4718               mov eax, dword ptr [edi + 0x18]
// 007c6e8b  bb01000000           mov ebx, 1
// 007c6e90  015f1c               add dword ptr [edi + 0x1c], ebx
// 007c6e93  3bf0                 cmp esi, eax
// 007c6e95  7510                 jne 0x7c6ea7
// 007c6e97  896804               mov dword ptr [eax + 4], ebp
// 007c6e9a  8b4718               mov eax, dword ptr [edi + 0x18]
// 007c6e9d  8928                 mov dword ptr [eax], ebp
// 007c6e9f  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 007c6ea2  896908               mov dword ptr [ecx + 8], ebp
// 007c6ea5  eb22                 jmp 0x7c6ec9
// 007c6ea7  807c246800           cmp byte ptr [esp + 0x68], 0
// 007c6eac  740d                 je 0x7c6ebb
// 007c6eae  892e                 mov dword ptr [esi], ebp
// 007c6eb0  8b4718               mov eax, dword ptr [edi + 0x18]
// 007c6eb3  3b30                 cmp esi, dword ptr [eax]
// 007c6eb5  7512                 jne 0x7c6ec9
// 007c6eb7  8928                 mov dword ptr [eax], ebp
// 007c6eb9  eb0e                 jmp 0x7c6ec9
// 007c6ebb  896e08               mov dword ptr [esi + 8], ebp
// 007c6ebe  8b4718               mov eax, dword ptr [edi + 0x18]
// 007c6ec1  3b7008               cmp esi, dword ptr [eax + 8]
// 007c6ec4  7503                 jne 0x7c6ec9
// 007c6ec6  896808               mov dword ptr [eax + 8], ebp
// 007c6ec9  8b5504               mov edx, dword ptr [ebp + 4]
// 007c6ecc  807a2800             cmp byte ptr [edx + 0x28], 0
// 007c6ed0  8d4504               lea eax, [ebp + 4]
// 007c6ed3  8bf5                 mov esi, ebp
// 007c6ed5  0f85ea000000         jne 0x7c6fc5
// 007c6edb  eb03                 jmp 0x7c6ee0
// 007c6edd  8d4900               lea ecx, [ecx]
// 007c6ee0  8b08                 mov ecx, dword ptr [eax]
// 007c6ee2  8b5104               mov edx, dword ptr [ecx + 4]
// 007c6ee5  3b0a                 cmp ecx, dword ptr [edx]
// 007c6ee7  7551                 jne 0x7c6f3a
// 007c6ee9  8b5208               mov edx, dword ptr [edx + 8]
// 007c6eec  807a2800             cmp byte ptr [edx + 0x28], 0
// 007c6ef0  7519                 jne 0x7c6f0b
// 007c6ef2  885928               mov byte ptr [ecx + 0x28], bl
// 007c6ef5  885a28               mov byte ptr [edx + 0x28], bl
// 007c6ef8  8b10                 mov edx, dword ptr [eax]
// 007c6efa  8b4a04               mov ecx, dword ptr [edx + 4]
// 007c6efd  c6412800             mov byte ptr [ecx + 0x28], 0
// 007c6f01  8b10                 mov edx, dword ptr [eax]
// 007c6f03  8b7204               mov esi, dword ptr [edx + 4]
// 007c6f06  e9aa000000           jmp 0x7c6fb5
// 007c6f0b  3b7108               cmp esi, dword ptr [ecx + 8]
// 007c6f0e  750a                 jne 0x7c6f1a
// 007c6f10  8bf1                 mov esi, ecx
// 007c6f12  56                   push esi
// 007c6f13  8bcf                 mov ecx, edi
// 007c6f15  e86662e0ff           call 0x5cd180
// 007c6f1a  8b4604               mov eax, dword ptr [esi + 4]
// 007c6f1d  885828               mov byte ptr [eax + 0x28], bl
// 007c6f20  8b4e04               mov ecx, dword ptr [esi + 4]
// 007c6f23  8b5104               mov edx, dword ptr [ecx + 4]
// 007c6f26  c6422800             mov byte ptr [edx + 0x28], 0
// 007c6f2a  8b4604               mov eax, dword ptr [esi + 4]
// 007c6f2d  8b4804               mov ecx, dword ptr [eax + 4]
// 007c6f30  51                   push ecx
// 007c6f31  8bcf                 mov ecx, edi
// 007c6f33  e8a856e0ff           call 0x5cc5e0
// 007c6f38  eb7b                 jmp 0x7c6fb5
// 007c6f3a  8b12                 mov edx, dword ptr [edx]
// 007c6f3c  807a2800             cmp byte ptr [edx + 0x28], 0
// 007c6f40  7516                 jne 0x7c6f58
// 007c6f42  885928               mov byte ptr [ecx + 0x28], bl
// 007c6f45  885a28               mov byte ptr [edx + 0x28], bl
// 007c6f48  8b10                 mov edx, dword ptr [eax]
// 007c6f4a  8b4a04               mov ecx, dword ptr [edx + 4]
// 007c6f4d  c6412800             mov byte ptr [ecx + 0x28], 0
// 007c6f51  8b10                 mov edx, dword ptr [eax]
// 007c6f53  8b7204               mov esi, dword ptr [edx + 4]
// 007c6f56  eb5d                 jmp 0x7c6fb5
// 007c6f58  3b31                 cmp esi, dword ptr [ecx]
// 007c6f5a  750a                 jne 0x7c6f66
// 007c6f5c  8bf1                 mov esi, ecx
// 007c6f5e  56                   push esi
// 007c6f5f  8bcf                 mov ecx, edi
// 007c6f61  e87a56e0ff           call 0x5cc5e0
// 007c6f66  8b4604               mov eax, dword ptr [esi + 4]
// 007c6f69  885828               mov byte ptr [eax + 0x28], bl
// 007c6f6c  8b4e04               mov ecx, dword ptr [esi + 4]
// 007c6f6f  8b5104               mov edx, dword ptr [ecx + 4]
// 007c6f72  c6422800             mov byte ptr [edx + 0x28], 0
// 007c6f76  8b4604               mov eax, dword ptr [esi + 4]
// 007c6f79  8b4004               mov eax, dword ptr [eax + 4]
// 007c6f7c  8b4808               mov ecx, dword ptr [eax + 8]
// 007c6f7f  8b11                 mov edx, dword ptr [ecx]
// 007c6f81  895008               mov dword ptr [eax + 8], edx
// 007c6f84  8b11                 mov edx, dword ptr [ecx]
// 007c6f86  807a2900             cmp byte ptr [edx + 0x29], 0
// 007c6f8a  7503                 jne 0x7c6f8f
// 007c6f8c  894204               mov dword ptr [edx + 4], eax
// 007c6f8f  8b5004               mov edx, dword ptr [eax + 4]
// 007c6f92  895104               mov dword ptr [ecx + 4], edx
// 007c6f95  8b5718               mov edx, dword ptr [edi + 0x18]
// 007c6f98  3b4204               cmp eax, dword ptr [edx + 4]
// 007c6f9b  7505                 jne 0x7c6fa2
// 007c6f9d  894a04               mov dword ptr [edx + 4], ecx
// 007c6fa0  eb0e                 jmp 0x7c6fb0
// 007c6fa2  8b5004               mov edx, dword ptr [eax + 4]
// 007c6fa5  3b02                 cmp eax, dword ptr [edx]
// 007c6fa7  7504                 jne 0x7c6fad
// 007c6fa9  890a                 mov dword ptr [edx], ecx
// 007c6fab  eb03                 jmp 0x7c6fb0
// 007c6fad  894a08               mov dword ptr [edx + 8], ecx
// 007c6fb0  8901                 mov dword ptr [ecx], eax
// 007c6fb2  894804               mov dword ptr [eax + 4], ecx
// 007c6fb5  8b4e04               mov ecx, dword ptr [esi + 4]
// 007c6fb8  80792800             cmp byte ptr [ecx + 0x28], 0
// 007c6fbc  8d4604               lea eax, [esi + 4]
// 007c6fbf  0f841bffffff         je 0x7c6ee0
// 007c6fc5  8b5718               mov edx, dword ptr [edi + 0x18]
// 007c6fc8  8b4204               mov eax, dword ptr [edx + 4]
// 007c6fcb  885828               mov byte ptr [eax + 0x28], bl
// 007c6fce  8b442464             mov eax, dword ptr [esp + 0x64]
// 007c6fd2  8b0f                 mov ecx, dword ptr [edi]
// 007c6fd4  5e                   pop esi
// 007c6fd5  896804               mov dword ptr [eax + 4], ebp
// 007c6fd8  5d                   pop ebp
// 007c6fd9  8908                 mov dword ptr [eax], ecx
// 007c6fdb  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 007c6fdf  5b                   pop ebx
// 007c6fe0  5f                   pop edi
// 007c6fe1  64890d00000000       mov dword ptr fs:[0], ecx
// 007c6fe8  83c450               add esp, 0x50
// 007c6feb  c21000               ret 0x10
// standard library map_int<pod24> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod24>
struct E { int v[6]; };
#include <map>
template class std::map<int, E>;
