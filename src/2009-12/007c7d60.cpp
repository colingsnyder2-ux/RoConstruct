// from server: 100% by auto
// roc 2009-12 007c7d60  unit: RBX::ScoreHud  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007c7d60
//
// 007c7d60  64a100000000         mov eax, dword ptr fs:[0]
// 007c7d66  6aff                 push -1
// 007c7d68  6812699500           push 0x956912
// 007c7d6d  50                   push eax
// 007c7d6e  64892500000000       mov dword ptr fs:[0], esp
// 007c7d75  83ec44               sub esp, 0x44
// 007c7d78  57                   push edi
// 007c7d79  8bf9                 mov edi, ecx
// 007c7d7b  817f1cc6711c07       cmp dword ptr [edi + 0x1c], 0x71c71c6
// 007c7d82  7259                 jb 0x7c7ddd
// 007c7d84  6800f59900           push 0x99f500
// 007c7d89  8d4c2408             lea ecx, [esp + 8]
// 007c7d8d  ff15f4b69800         call dword ptr [0x98b6f4]
// 007c7d93  8d4c2420             lea ecx, [esp + 0x20]
// 007c7d97  c744245000000000     mov dword ptr [esp + 0x50], 0
// 007c7d9f  ff1554b79800         call dword ptr [0x98b754]
// 007c7da5  8d442404             lea eax, [esp + 4]
// 007c7da9  50                   push eax
// 007c7daa  8d4c2430             lea ecx, [esp + 0x30]
// 007c7dae  c644245401           mov byte ptr [esp + 0x54], 1
// 007c7db3  c744242484f49900     mov dword ptr [esp + 0x24], 0x99f484
// 007c7dbb  ff15f0b69800         call dword ptr [0x98b6f0]
// 007c7dc1  68e4efa800           push 0xa8efe4
// 007c7dc6  8d4c2424             lea ecx, [esp + 0x24]
// 007c7dca  51                   push ecx
// 007c7dcb  c644245800           mov byte ptr [esp + 0x58], 0
// 007c7dd0  c744242890f49900     mov dword ptr [esp + 0x28], 0x99f490
// 007c7dd8  e89bca0200           call 0x7f4878
// 007c7ddd  8b542464             mov edx, dword ptr [esp + 0x64]
// 007c7de1  8b4718               mov eax, dword ptr [edi + 0x18]
// 007c7de4  53                   push ebx
// 007c7de5  55                   push ebp
// 007c7de6  56                   push esi
// 007c7de7  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 007c7deb  6a00                 push 0
// 007c7ded  52                   push edx
// 007c7dee  50                   push eax
// 007c7def  56                   push esi
// 007c7df0  50                   push eax
// 007c7df1  e8faf9ffff           call 0x7c77f0
// 007c7df6  8be8                 mov ebp, eax
// 007c7df8  8b4718               mov eax, dword ptr [edi + 0x18]
// 007c7dfb  bb01000000           mov ebx, 1
// 007c7e00  015f1c               add dword ptr [edi + 0x1c], ebx
// 007c7e03  3bf0                 cmp esi, eax
// 007c7e05  7510                 jne 0x7c7e17
// 007c7e07  896804               mov dword ptr [eax + 4], ebp
// 007c7e0a  8b4718               mov eax, dword ptr [edi + 0x18]
// 007c7e0d  8928                 mov dword ptr [eax], ebp
// 007c7e0f  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 007c7e12  896908               mov dword ptr [ecx + 8], ebp
// 007c7e15  eb22                 jmp 0x7c7e39
// 007c7e17  807c246800           cmp byte ptr [esp + 0x68], 0
// 007c7e1c  740d                 je 0x7c7e2b
// 007c7e1e  892e                 mov dword ptr [esi], ebp
// 007c7e20  8b4718               mov eax, dword ptr [edi + 0x18]
// 007c7e23  3b30                 cmp esi, dword ptr [eax]
// 007c7e25  7512                 jne 0x7c7e39
// 007c7e27  8928                 mov dword ptr [eax], ebp
// 007c7e29  eb0e                 jmp 0x7c7e39
// 007c7e2b  896e08               mov dword ptr [esi + 8], ebp
// 007c7e2e  8b4718               mov eax, dword ptr [edi + 0x18]
// 007c7e31  3b7008               cmp esi, dword ptr [eax + 8]
// 007c7e34  7503                 jne 0x7c7e39
// 007c7e36  896808               mov dword ptr [eax + 8], ebp
// 007c7e39  8b5504               mov edx, dword ptr [ebp + 4]
// 007c7e3c  807a3000             cmp byte ptr [edx + 0x30], 0
// 007c7e40  8d4504               lea eax, [ebp + 4]
// 007c7e43  8bf5                 mov esi, ebp
// 007c7e45  0f85ea000000         jne 0x7c7f35
// 007c7e4b  eb03                 jmp 0x7c7e50
// 007c7e4d  8d4900               lea ecx, [ecx]
// 007c7e50  8b08                 mov ecx, dword ptr [eax]
// 007c7e52  8b5104               mov edx, dword ptr [ecx + 4]
// 007c7e55  3b0a                 cmp ecx, dword ptr [edx]
// 007c7e57  7551                 jne 0x7c7eaa
// 007c7e59  8b5208               mov edx, dword ptr [edx + 8]
// 007c7e5c  807a3000             cmp byte ptr [edx + 0x30], 0
// 007c7e60  7519                 jne 0x7c7e7b
// 007c7e62  885930               mov byte ptr [ecx + 0x30], bl
// 007c7e65  885a30               mov byte ptr [edx + 0x30], bl
// 007c7e68  8b10                 mov edx, dword ptr [eax]
// 007c7e6a  8b4a04               mov ecx, dword ptr [edx + 4]
// 007c7e6d  c6413000             mov byte ptr [ecx + 0x30], 0
// 007c7e71  8b10                 mov edx, dword ptr [eax]
// 007c7e73  8b7204               mov esi, dword ptr [edx + 4]
// 007c7e76  e9aa000000           jmp 0x7c7f25
// 007c7e7b  3b7108               cmp esi, dword ptr [ecx + 8]
// 007c7e7e  750a                 jne 0x7c7e8a
// 007c7e80  8bf1                 mov esi, ecx
// 007c7e82  56                   push esi
// 007c7e83  8bcf                 mov ecx, edi
// 007c7e85  e886b9d4ff           call 0x513810
// 007c7e8a  8b4604               mov eax, dword ptr [esi + 4]
// 007c7e8d  885830               mov byte ptr [eax + 0x30], bl
// 007c7e90  8b4e04               mov ecx, dword ptr [esi + 4]
// 007c7e93  8b5104               mov edx, dword ptr [ecx + 4]
// 007c7e96  c6423000             mov byte ptr [edx + 0x30], 0
// 007c7e9a  8b4604               mov eax, dword ptr [esi + 4]
// 007c7e9d  8b4804               mov ecx, dword ptr [eax + 4]
// 007c7ea0  51                   push ecx
// 007c7ea1  8bcf                 mov ecx, edi
// 007c7ea3  e8f8adf3ff           call 0x702ca0
// 007c7ea8  eb7b                 jmp 0x7c7f25
// 007c7eaa  8b12                 mov edx, dword ptr [edx]
// 007c7eac  807a3000             cmp byte ptr [edx + 0x30], 0
// 007c7eb0  7516                 jne 0x7c7ec8
// 007c7eb2  885930               mov byte ptr [ecx + 0x30], bl
// 007c7eb5  885a30               mov byte ptr [edx + 0x30], bl
// 007c7eb8  8b10                 mov edx, dword ptr [eax]
// 007c7eba  8b4a04               mov ecx, dword ptr [edx + 4]
// 007c7ebd  c6413000             mov byte ptr [ecx + 0x30], 0
// 007c7ec1  8b10                 mov edx, dword ptr [eax]
// 007c7ec3  8b7204               mov esi, dword ptr [edx + 4]
// 007c7ec6  eb5d                 jmp 0x7c7f25
// 007c7ec8  3b31                 cmp esi, dword ptr [ecx]
// 007c7eca  750a                 jne 0x7c7ed6
// 007c7ecc  8bf1                 mov esi, ecx
// 007c7ece  56                   push esi
// 007c7ecf  8bcf                 mov ecx, edi
// 007c7ed1  e8caadf3ff           call 0x702ca0
// 007c7ed6  8b4604               mov eax, dword ptr [esi + 4]
// 007c7ed9  885830               mov byte ptr [eax + 0x30], bl
// 007c7edc  8b4e04               mov ecx, dword ptr [esi + 4]
// 007c7edf  8b5104               mov edx, dword ptr [ecx + 4]
// 007c7ee2  c6423000             mov byte ptr [edx + 0x30], 0
// 007c7ee6  8b4604               mov eax, dword ptr [esi + 4]
// 007c7ee9  8b4004               mov eax, dword ptr [eax + 4]
// 007c7eec  8b4808               mov ecx, dword ptr [eax + 8]
// 007c7eef  8b11                 mov edx, dword ptr [ecx]
// 007c7ef1  895008               mov dword ptr [eax + 8], edx
// 007c7ef4  8b11                 mov edx, dword ptr [ecx]
// 007c7ef6  807a3100             cmp byte ptr [edx + 0x31], 0
// 007c7efa  7503                 jne 0x7c7eff
// 007c7efc  894204               mov dword ptr [edx + 4], eax
// 007c7eff  8b5004               mov edx, dword ptr [eax + 4]
// 007c7f02  895104               mov dword ptr [ecx + 4], edx
// 007c7f05  8b5718               mov edx, dword ptr [edi + 0x18]
// 007c7f08  3b4204               cmp eax, dword ptr [edx + 4]
// 007c7f0b  7505                 jne 0x7c7f12
// 007c7f0d  894a04               mov dword ptr [edx + 4], ecx
// 007c7f10  eb0e                 jmp 0x7c7f20
// 007c7f12  8b5004               mov edx, dword ptr [eax + 4]
// 007c7f15  3b02                 cmp eax, dword ptr [edx]
// 007c7f17  7504                 jne 0x7c7f1d
// 007c7f19  890a                 mov dword ptr [edx], ecx
// 007c7f1b  eb03                 jmp 0x7c7f20
// 007c7f1d  894a08               mov dword ptr [edx + 8], ecx
// 007c7f20  8901                 mov dword ptr [ecx], eax
// 007c7f22  894804               mov dword ptr [eax + 4], ecx
// 007c7f25  8b4e04               mov ecx, dword ptr [esi + 4]
// 007c7f28  80793000             cmp byte ptr [ecx + 0x30], 0
// 007c7f2c  8d4604               lea eax, [esi + 4]
// 007c7f2f  0f841bffffff         je 0x7c7e50
// 007c7f35  8b5718               mov edx, dword ptr [edi + 0x18]
// 007c7f38  8b4204               mov eax, dword ptr [edx + 4]
// 007c7f3b  885830               mov byte ptr [eax + 0x30], bl
// 007c7f3e  8b442464             mov eax, dword ptr [esp + 0x64]
// 007c7f42  8b0f                 mov ecx, dword ptr [edi]
// 007c7f44  5e                   pop esi
// 007c7f45  896804               mov dword ptr [eax + 4], ebp
// 007c7f48  5d                   pop ebp
// 007c7f49  8908                 mov dword ptr [eax], ecx
// 007c7f4b  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 007c7f4f  5b                   pop ebx
// 007c7f50  5f                   pop edi
// 007c7f51  64890d00000000       mov dword ptr fs:[0], ecx
// 007c7f58  83c450               add esp, 0x50
// 007c7f5b  c21000               ret 0x10
// standard library map_int<pod32> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod32>
struct E { int v[8]; };
#include <map>
template class std::map<int, E>;
