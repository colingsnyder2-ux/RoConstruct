// from server: 100% by auto
// roc 2007-08 004d2a30  unit: G3D::VVector3::?$Table  size: 508 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004d2a30
//
// 004d2a30  64a100000000         mov eax, dword ptr fs:[0]
// 004d2a36  6aff                 push -1
// 004d2a38  68b2417500           push 0x7541b2
// 004d2a3d  50                   push eax
// 004d2a3e  64892500000000       mov dword ptr fs:[0], esp
// 004d2a45  83ec44               sub esp, 0x44
// 004d2a48  57                   push edi
// 004d2a49  8bf9                 mov edi, ecx
// 004d2a4b  817f0848922409       cmp dword ptr [edi + 8], 0x9249248
// 004d2a52  7259                 jb 0x4d2aad
// 004d2a54  68904f7800           push 0x784f90
// 004d2a59  8d4c2408             lea ecx, [esp + 8]
// 004d2a5d  ff1598e67700         call dword ptr [0x77e698]
// 004d2a63  8d4c2420             lea ecx, [esp + 0x20]
// 004d2a67  c744245000000000     mov dword ptr [esp + 0x50], 0
// 004d2a6f  ff15f8e67700         call dword ptr [0x77e6f8]
// 004d2a75  8d442404             lea eax, [esp + 4]
// 004d2a79  50                   push eax
// 004d2a7a  8d4c2430             lea ecx, [esp + 0x30]
// 004d2a7e  c644245401           mov byte ptr [esp + 0x54], 1
// 004d2a83  c7442424604e7800     mov dword ptr [esp + 0x24], 0x784e60
// 004d2a8b  ff159ce67700         call dword ptr [0x77e69c]
// 004d2a91  6878f78300           push 0x83f778
// 004d2a96  8d4c2424             lea ecx, [esp + 0x24]
// 004d2a9a  51                   push ecx
// 004d2a9b  c644245800           mov byte ptr [esp + 0x58], 0
// 004d2aa0  c74424286c4e7800     mov dword ptr [esp + 0x28], 0x784e6c
// 004d2aa8  e8f1e01500           call 0x630b9e
// 004d2aad  8b542464             mov edx, dword ptr [esp + 0x64]
// 004d2ab1  8b4704               mov eax, dword ptr [edi + 4]
// 004d2ab4  53                   push ebx
// 004d2ab5  55                   push ebp
// 004d2ab6  56                   push esi
// 004d2ab7  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 004d2abb  6a00                 push 0
// 004d2abd  52                   push edx
// 004d2abe  50                   push eax
// 004d2abf  56                   push esi
// 004d2ac0  50                   push eax
// 004d2ac1  e86af7ffff           call 0x4d2230
// 004d2ac6  8be8                 mov ebp, eax
// 004d2ac8  8b4704               mov eax, dword ptr [edi + 4]
// 004d2acb  bb01000000           mov ebx, 1
// 004d2ad0  015f08               add dword ptr [edi + 8], ebx
// 004d2ad3  3bf0                 cmp esi, eax
// 004d2ad5  7510                 jne 0x4d2ae7
// 004d2ad7  896804               mov dword ptr [eax + 4], ebp
// 004d2ada  8b4704               mov eax, dword ptr [edi + 4]
// 004d2add  8928                 mov dword ptr [eax], ebp
// 004d2adf  8b4f04               mov ecx, dword ptr [edi + 4]
// 004d2ae2  896908               mov dword ptr [ecx + 8], ebp
// 004d2ae5  eb22                 jmp 0x4d2b09
// 004d2ae7  807c246800           cmp byte ptr [esp + 0x68], 0
// 004d2aec  740d                 je 0x4d2afb
// 004d2aee  892e                 mov dword ptr [esi], ebp
// 004d2af0  8b4704               mov eax, dword ptr [edi + 4]
// 004d2af3  3b30                 cmp esi, dword ptr [eax]
// 004d2af5  7512                 jne 0x4d2b09
// 004d2af7  8928                 mov dword ptr [eax], ebp
// 004d2af9  eb0e                 jmp 0x4d2b09
// 004d2afb  896e08               mov dword ptr [esi + 8], ebp
// 004d2afe  8b4704               mov eax, dword ptr [edi + 4]
// 004d2b01  3b7008               cmp esi, dword ptr [eax + 8]
// 004d2b04  7503                 jne 0x4d2b09
// 004d2b06  896808               mov dword ptr [eax + 8], ebp
// 004d2b09  8b5504               mov edx, dword ptr [ebp + 4]
// 004d2b0c  807a2800             cmp byte ptr [edx + 0x28], 0
// 004d2b10  8d4504               lea eax, [ebp + 4]
// 004d2b13  8bf5                 mov esi, ebp
// 004d2b15  0f85ea000000         jne 0x4d2c05
// 004d2b1b  eb03                 jmp 0x4d2b20
// 004d2b1d  8d4900               lea ecx, [ecx]
// 004d2b20  8b08                 mov ecx, dword ptr [eax]
// 004d2b22  8b5104               mov edx, dword ptr [ecx + 4]
// 004d2b25  3b0a                 cmp ecx, dword ptr [edx]
// 004d2b27  7551                 jne 0x4d2b7a
// 004d2b29  8b5208               mov edx, dword ptr [edx + 8]
// 004d2b2c  807a2800             cmp byte ptr [edx + 0x28], 0
// 004d2b30  7519                 jne 0x4d2b4b
// 004d2b32  885928               mov byte ptr [ecx + 0x28], bl
// 004d2b35  885a28               mov byte ptr [edx + 0x28], bl
// 004d2b38  8b10                 mov edx, dword ptr [eax]
// 004d2b3a  8b4a04               mov ecx, dword ptr [edx + 4]
// 004d2b3d  c6412800             mov byte ptr [ecx + 0x28], 0
// 004d2b41  8b10                 mov edx, dword ptr [eax]
// 004d2b43  8b7204               mov esi, dword ptr [edx + 4]
// 004d2b46  e9aa000000           jmp 0x4d2bf5
// 004d2b4b  3b7108               cmp esi, dword ptr [ecx + 8]
// 004d2b4e  750a                 jne 0x4d2b5a
// 004d2b50  8bf1                 mov esi, ecx
// 004d2b52  56                   push esi
// 004d2b53  8bcf                 mov ecx, edi
// 004d2b55  e836dcffff           call 0x4d0790
// 004d2b5a  8b4604               mov eax, dword ptr [esi + 4]
// 004d2b5d  885828               mov byte ptr [eax + 0x28], bl
// 004d2b60  8b4e04               mov ecx, dword ptr [esi + 4]
// 004d2b63  8b5104               mov edx, dword ptr [ecx + 4]
// 004d2b66  c6422800             mov byte ptr [edx + 0x28], 0
// 004d2b6a  8b4604               mov eax, dword ptr [esi + 4]
// 004d2b6d  8b4804               mov ecx, dword ptr [eax + 4]
// 004d2b70  51                   push ecx
// 004d2b71  8bcf                 mov ecx, edi
// 004d2b73  e818d7ffff           call 0x4d0290
// 004d2b78  eb7b                 jmp 0x4d2bf5
// 004d2b7a  8b12                 mov edx, dword ptr [edx]
// 004d2b7c  807a2800             cmp byte ptr [edx + 0x28], 0
// 004d2b80  7516                 jne 0x4d2b98
// 004d2b82  885928               mov byte ptr [ecx + 0x28], bl
// 004d2b85  885a28               mov byte ptr [edx + 0x28], bl
// 004d2b88  8b10                 mov edx, dword ptr [eax]
// 004d2b8a  8b4a04               mov ecx, dword ptr [edx + 4]
// 004d2b8d  c6412800             mov byte ptr [ecx + 0x28], 0
// 004d2b91  8b10                 mov edx, dword ptr [eax]
// 004d2b93  8b7204               mov esi, dword ptr [edx + 4]
// 004d2b96  eb5d                 jmp 0x4d2bf5
// 004d2b98  3b31                 cmp esi, dword ptr [ecx]
// 004d2b9a  750a                 jne 0x4d2ba6
// 004d2b9c  8bf1                 mov esi, ecx
// 004d2b9e  56                   push esi
// 004d2b9f  8bcf                 mov ecx, edi
// 004d2ba1  e8ead6ffff           call 0x4d0290
// 004d2ba6  8b4604               mov eax, dword ptr [esi + 4]
// 004d2ba9  885828               mov byte ptr [eax + 0x28], bl
// 004d2bac  8b4e04               mov ecx, dword ptr [esi + 4]
// 004d2baf  8b5104               mov edx, dword ptr [ecx + 4]
// 004d2bb2  c6422800             mov byte ptr [edx + 0x28], 0
// 004d2bb6  8b4604               mov eax, dword ptr [esi + 4]
// 004d2bb9  8b4004               mov eax, dword ptr [eax + 4]
// 004d2bbc  8b4808               mov ecx, dword ptr [eax + 8]
// 004d2bbf  8b11                 mov edx, dword ptr [ecx]
// 004d2bc1  895008               mov dword ptr [eax + 8], edx
// 004d2bc4  8b11                 mov edx, dword ptr [ecx]
// 004d2bc6  807a2900             cmp byte ptr [edx + 0x29], 0
// 004d2bca  7503                 jne 0x4d2bcf
// 004d2bcc  894204               mov dword ptr [edx + 4], eax
// 004d2bcf  8b5004               mov edx, dword ptr [eax + 4]
// 004d2bd2  895104               mov dword ptr [ecx + 4], edx
// 004d2bd5  8b5704               mov edx, dword ptr [edi + 4]
// 004d2bd8  3b4204               cmp eax, dword ptr [edx + 4]
// 004d2bdb  7505                 jne 0x4d2be2
// 004d2bdd  894a04               mov dword ptr [edx + 4], ecx
// 004d2be0  eb0e                 jmp 0x4d2bf0
// 004d2be2  8b5004               mov edx, dword ptr [eax + 4]
// 004d2be5  3b02                 cmp eax, dword ptr [edx]
// 004d2be7  7504                 jne 0x4d2bed
// 004d2be9  890a                 mov dword ptr [edx], ecx
// 004d2beb  eb03                 jmp 0x4d2bf0
// 004d2bed  894a08               mov dword ptr [edx + 8], ecx
// 004d2bf0  8901                 mov dword ptr [ecx], eax
// 004d2bf2  894804               mov dword ptr [eax + 4], ecx
// 004d2bf5  8b4e04               mov ecx, dword ptr [esi + 4]
// 004d2bf8  80792800             cmp byte ptr [ecx + 0x28], 0
// 004d2bfc  8d4604               lea eax, [esi + 4]
// 004d2bff  0f841bffffff         je 0x4d2b20
// 004d2c05  8b5704               mov edx, dword ptr [edi + 4]
// 004d2c08  8b4204               mov eax, dword ptr [edx + 4]
// 004d2c0b  8b4c2454             mov ecx, dword ptr [esp + 0x54]
// 004d2c0f  885828               mov byte ptr [eax + 0x28], bl
// 004d2c12  8b442464             mov eax, dword ptr [esp + 0x64]
// 004d2c16  5e                   pop esi
// 004d2c17  896804               mov dword ptr [eax + 4], ebp
// 004d2c1a  5d                   pop ebp
// 004d2c1b  8938                 mov dword ptr [eax], edi
// 004d2c1d  5b                   pop ebx
// 004d2c1e  5f                   pop edi
// 004d2c1f  64890d00000000       mov dword ptr fs:[0], ecx
// 004d2c26  83c450               add esp, 0x50
// 004d2c29  c21000               ret 0x10
// standard library map_int<pod24> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod24>
struct E { int v[6]; };
#include <map>
template class std::map<int, E>;
