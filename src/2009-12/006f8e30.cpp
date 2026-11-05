// from server: 100% by auto
// roc 2009-12 006f8e30  unit: RBX::Network::VPlayer::?$RemoteEventDesc  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006f8e30
//
// 006f8e30  64a100000000         mov eax, dword ptr fs:[0]
// 006f8e36  6aff                 push -1
// 006f8e38  6812699500           push 0x956912
// 006f8e3d  50                   push eax
// 006f8e3e  64892500000000       mov dword ptr fs:[0], esp
// 006f8e45  83ec44               sub esp, 0x44
// 006f8e48  57                   push edi
// 006f8e49  8bf9                 mov edi, ecx
// 006f8e4b  817f1cc6711c07       cmp dword ptr [edi + 0x1c], 0x71c71c6
// 006f8e52  7259                 jb 0x6f8ead
// 006f8e54  6800f59900           push 0x99f500
// 006f8e59  8d4c2408             lea ecx, [esp + 8]
// 006f8e5d  ff15f4b69800         call dword ptr [0x98b6f4]
// 006f8e63  8d4c2420             lea ecx, [esp + 0x20]
// 006f8e67  c744245000000000     mov dword ptr [esp + 0x50], 0
// 006f8e6f  ff1554b79800         call dword ptr [0x98b754]
// 006f8e75  8d442404             lea eax, [esp + 4]
// 006f8e79  50                   push eax
// 006f8e7a  8d4c2430             lea ecx, [esp + 0x30]
// 006f8e7e  c644245401           mov byte ptr [esp + 0x54], 1
// 006f8e83  c744242484f49900     mov dword ptr [esp + 0x24], 0x99f484
// 006f8e8b  ff15f0b69800         call dword ptr [0x98b6f0]
// 006f8e91  68e4efa800           push 0xa8efe4
// 006f8e96  8d4c2424             lea ecx, [esp + 0x24]
// 006f8e9a  51                   push ecx
// 006f8e9b  c644245800           mov byte ptr [esp + 0x58], 0
// 006f8ea0  c744242890f49900     mov dword ptr [esp + 0x28], 0x99f490
// 006f8ea8  e8cbb90f00           call 0x7f4878
// 006f8ead  8b542464             mov edx, dword ptr [esp + 0x64]
// 006f8eb1  8b4718               mov eax, dword ptr [edi + 0x18]
// 006f8eb4  53                   push ebx
// 006f8eb5  55                   push ebp
// 006f8eb6  56                   push esi
// 006f8eb7  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 006f8ebb  6a00                 push 0
// 006f8ebd  52                   push edx
// 006f8ebe  50                   push eax
// 006f8ebf  56                   push esi
// 006f8ec0  50                   push eax
// 006f8ec1  e8aaf6ffff           call 0x6f8570
// 006f8ec6  8be8                 mov ebp, eax
// 006f8ec8  8b4718               mov eax, dword ptr [edi + 0x18]
// 006f8ecb  bb01000000           mov ebx, 1
// 006f8ed0  015f1c               add dword ptr [edi + 0x1c], ebx
// 006f8ed3  3bf0                 cmp esi, eax
// 006f8ed5  7510                 jne 0x6f8ee7
// 006f8ed7  896804               mov dword ptr [eax + 4], ebp
// 006f8eda  8b4718               mov eax, dword ptr [edi + 0x18]
// 006f8edd  8928                 mov dword ptr [eax], ebp
// 006f8edf  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 006f8ee2  896908               mov dword ptr [ecx + 8], ebp
// 006f8ee5  eb22                 jmp 0x6f8f09
// 006f8ee7  807c246800           cmp byte ptr [esp + 0x68], 0
// 006f8eec  740d                 je 0x6f8efb
// 006f8eee  892e                 mov dword ptr [esi], ebp
// 006f8ef0  8b4718               mov eax, dword ptr [edi + 0x18]
// 006f8ef3  3b30                 cmp esi, dword ptr [eax]
// 006f8ef5  7512                 jne 0x6f8f09
// 006f8ef7  8928                 mov dword ptr [eax], ebp
// 006f8ef9  eb0e                 jmp 0x6f8f09
// 006f8efb  896e08               mov dword ptr [esi + 8], ebp
// 006f8efe  8b4718               mov eax, dword ptr [edi + 0x18]
// 006f8f01  3b7008               cmp esi, dword ptr [eax + 8]
// 006f8f04  7503                 jne 0x6f8f09
// 006f8f06  896808               mov dword ptr [eax + 8], ebp
// 006f8f09  8b5504               mov edx, dword ptr [ebp + 4]
// 006f8f0c  807a3000             cmp byte ptr [edx + 0x30], 0
// 006f8f10  8d4504               lea eax, [ebp + 4]
// 006f8f13  8bf5                 mov esi, ebp
// 006f8f15  0f85ea000000         jne 0x6f9005
// 006f8f1b  eb03                 jmp 0x6f8f20
// 006f8f1d  8d4900               lea ecx, [ecx]
// 006f8f20  8b08                 mov ecx, dword ptr [eax]
// 006f8f22  8b5104               mov edx, dword ptr [ecx + 4]
// 006f8f25  3b0a                 cmp ecx, dword ptr [edx]
// 006f8f27  7551                 jne 0x6f8f7a
// 006f8f29  8b5208               mov edx, dword ptr [edx + 8]
// 006f8f2c  807a3000             cmp byte ptr [edx + 0x30], 0
// 006f8f30  7519                 jne 0x6f8f4b
// 006f8f32  885930               mov byte ptr [ecx + 0x30], bl
// 006f8f35  885a30               mov byte ptr [edx + 0x30], bl
// 006f8f38  8b10                 mov edx, dword ptr [eax]
// 006f8f3a  8b4a04               mov ecx, dword ptr [edx + 4]
// 006f8f3d  c6413000             mov byte ptr [ecx + 0x30], 0
// 006f8f41  8b10                 mov edx, dword ptr [eax]
// 006f8f43  8b7204               mov esi, dword ptr [edx + 4]
// 006f8f46  e9aa000000           jmp 0x6f8ff5
// 006f8f4b  3b7108               cmp esi, dword ptr [ecx + 8]
// 006f8f4e  750a                 jne 0x6f8f5a
// 006f8f50  8bf1                 mov esi, ecx
// 006f8f52  56                   push esi
// 006f8f53  8bcf                 mov ecx, edi
// 006f8f55  e8b6a8e1ff           call 0x513810
// 006f8f5a  8b4604               mov eax, dword ptr [esi + 4]
// 006f8f5d  885830               mov byte ptr [eax + 0x30], bl
// 006f8f60  8b4e04               mov ecx, dword ptr [esi + 4]
// 006f8f63  8b5104               mov edx, dword ptr [ecx + 4]
// 006f8f66  c6423000             mov byte ptr [edx + 0x30], 0
// 006f8f6a  8b4604               mov eax, dword ptr [esi + 4]
// 006f8f6d  8b4804               mov ecx, dword ptr [eax + 4]
// 006f8f70  51                   push ecx
// 006f8f71  8bcf                 mov ecx, edi
// 006f8f73  e8289d0000           call 0x702ca0
// 006f8f78  eb7b                 jmp 0x6f8ff5
// 006f8f7a  8b12                 mov edx, dword ptr [edx]
// 006f8f7c  807a3000             cmp byte ptr [edx + 0x30], 0
// 006f8f80  7516                 jne 0x6f8f98
// 006f8f82  885930               mov byte ptr [ecx + 0x30], bl
// 006f8f85  885a30               mov byte ptr [edx + 0x30], bl
// 006f8f88  8b10                 mov edx, dword ptr [eax]
// 006f8f8a  8b4a04               mov ecx, dword ptr [edx + 4]
// 006f8f8d  c6413000             mov byte ptr [ecx + 0x30], 0
// 006f8f91  8b10                 mov edx, dword ptr [eax]
// 006f8f93  8b7204               mov esi, dword ptr [edx + 4]
// 006f8f96  eb5d                 jmp 0x6f8ff5
// 006f8f98  3b31                 cmp esi, dword ptr [ecx]
// 006f8f9a  750a                 jne 0x6f8fa6
// 006f8f9c  8bf1                 mov esi, ecx
// 006f8f9e  56                   push esi
// 006f8f9f  8bcf                 mov ecx, edi
// 006f8fa1  e8fa9c0000           call 0x702ca0
// 006f8fa6  8b4604               mov eax, dword ptr [esi + 4]
// 006f8fa9  885830               mov byte ptr [eax + 0x30], bl
// 006f8fac  8b4e04               mov ecx, dword ptr [esi + 4]
// 006f8faf  8b5104               mov edx, dword ptr [ecx + 4]
// 006f8fb2  c6423000             mov byte ptr [edx + 0x30], 0
// 006f8fb6  8b4604               mov eax, dword ptr [esi + 4]
// 006f8fb9  8b4004               mov eax, dword ptr [eax + 4]
// 006f8fbc  8b4808               mov ecx, dword ptr [eax + 8]
// 006f8fbf  8b11                 mov edx, dword ptr [ecx]
// 006f8fc1  895008               mov dword ptr [eax + 8], edx
// 006f8fc4  8b11                 mov edx, dword ptr [ecx]
// 006f8fc6  807a3100             cmp byte ptr [edx + 0x31], 0
// 006f8fca  7503                 jne 0x6f8fcf
// 006f8fcc  894204               mov dword ptr [edx + 4], eax
// 006f8fcf  8b5004               mov edx, dword ptr [eax + 4]
// 006f8fd2  895104               mov dword ptr [ecx + 4], edx
// 006f8fd5  8b5718               mov edx, dword ptr [edi + 0x18]
// 006f8fd8  3b4204               cmp eax, dword ptr [edx + 4]
// 006f8fdb  7505                 jne 0x6f8fe2
// 006f8fdd  894a04               mov dword ptr [edx + 4], ecx
// 006f8fe0  eb0e                 jmp 0x6f8ff0
// 006f8fe2  8b5004               mov edx, dword ptr [eax + 4]
// 006f8fe5  3b02                 cmp eax, dword ptr [edx]
// 006f8fe7  7504                 jne 0x6f8fed
// 006f8fe9  890a                 mov dword ptr [edx], ecx
// 006f8feb  eb03                 jmp 0x6f8ff0
// 006f8fed  894a08               mov dword ptr [edx + 8], ecx
// 006f8ff0  8901                 mov dword ptr [ecx], eax
// 006f8ff2  894804               mov dword ptr [eax + 4], ecx
// 006f8ff5  8b4e04               mov ecx, dword ptr [esi + 4]
// 006f8ff8  80793000             cmp byte ptr [ecx + 0x30], 0
// 006f8ffc  8d4604               lea eax, [esi + 4]
// 006f8fff  0f841bffffff         je 0x6f8f20
// 006f9005  8b5718               mov edx, dword ptr [edi + 0x18]
// 006f9008  8b4204               mov eax, dword ptr [edx + 4]
// 006f900b  885830               mov byte ptr [eax + 0x30], bl
// 006f900e  8b442464             mov eax, dword ptr [esp + 0x64]
// 006f9012  8b0f                 mov ecx, dword ptr [edi]
// 006f9014  5e                   pop esi
// 006f9015  896804               mov dword ptr [eax + 4], ebp
// 006f9018  5d                   pop ebp
// 006f9019  8908                 mov dword ptr [eax], ecx
// 006f901b  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 006f901f  5b                   pop ebx
// 006f9020  5f                   pop edi
// 006f9021  64890d00000000       mov dword ptr fs:[0], ecx
// 006f9028  83c450               add esp, 0x50
// 006f902b  c21000               ret 0x10
// standard library map_int<pod32> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod32>
struct E { int v[8]; };
#include <map>
template class std::map<int, E>;
