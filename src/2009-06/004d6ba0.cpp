// from server: 100% by auto
// roc 2009-06 004d6ba0  unit: RBX::Network::VServer::?$FactoryProduct  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004d6ba0
//
// 004d6ba0  64a100000000         mov eax, dword ptr fs:[0]
// 004d6ba6  6aff                 push -1
// 004d6ba8  68b2db8500           push 0x85dbb2
// 004d6bad  50                   push eax
// 004d6bae  64892500000000       mov dword ptr fs:[0], esp
// 004d6bb5  83ec44               sub esp, 0x44
// 004d6bb8  57                   push edi
// 004d6bb9  8bf9                 mov edi, ecx
// 004d6bbb  817f1c48922409       cmp dword ptr [edi + 0x1c], 0x9249248
// 004d6bc2  7259                 jb 0x4d6c1d
// 004d6bc4  68c0c98a00           push 0x8ac9c0
// 004d6bc9  8d4c2408             lea ecx, [esp + 8]
// 004d6bcd  ff15b4e48900         call dword ptr [0x89e4b4]
// 004d6bd3  8d4c2420             lea ecx, [esp + 0x20]
// 004d6bd7  c744245000000000     mov dword ptr [esp + 0x50], 0
// 004d6bdf  ff15b8e98900         call dword ptr [0x89e9b8]
// 004d6be5  8d442404             lea eax, [esp + 4]
// 004d6be9  50                   push eax
// 004d6bea  8d4c2430             lea ecx, [esp + 0x30]
// 004d6bee  c644245401           mov byte ptr [esp + 0x54], 1
// 004d6bf3  c744242444c98a00     mov dword ptr [esp + 0x24], 0x8ac944
// 004d6bfb  ff15b8e48900         call dword ptr [0x89e4b8]
// 004d6c01  6834929700           push 0x979234
// 004d6c06  8d4c2424             lea ecx, [esp + 0x24]
// 004d6c0a  51                   push ecx
// 004d6c0b  c644245800           mov byte ptr [esp + 0x58], 0
// 004d6c10  c744242850c98a00     mov dword ptr [esp + 0x28], 0x8ac950
// 004d6c18  e82d2e2400           call 0x719a4a
// 004d6c1d  8b542464             mov edx, dword ptr [esp + 0x64]
// 004d6c21  8b4718               mov eax, dword ptr [edi + 0x18]
// 004d6c24  53                   push ebx
// 004d6c25  55                   push ebp
// 004d6c26  56                   push esi
// 004d6c27  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 004d6c2b  6a00                 push 0
// 004d6c2d  52                   push edx
// 004d6c2e  50                   push eax
// 004d6c2f  56                   push esi
// 004d6c30  50                   push eax
// 004d6c31  e81af8f9ff           call 0x476450
// 004d6c36  8be8                 mov ebp, eax
// 004d6c38  8b4718               mov eax, dword ptr [edi + 0x18]
// 004d6c3b  bb01000000           mov ebx, 1
// 004d6c40  015f1c               add dword ptr [edi + 0x1c], ebx
// 004d6c43  3bf0                 cmp esi, eax
// 004d6c45  7510                 jne 0x4d6c57
// 004d6c47  896804               mov dword ptr [eax + 4], ebp
// 004d6c4a  8b4718               mov eax, dword ptr [edi + 0x18]
// 004d6c4d  8928                 mov dword ptr [eax], ebp
// 004d6c4f  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 004d6c52  896908               mov dword ptr [ecx + 8], ebp
// 004d6c55  eb22                 jmp 0x4d6c79
// 004d6c57  807c246800           cmp byte ptr [esp + 0x68], 0
// 004d6c5c  740d                 je 0x4d6c6b
// 004d6c5e  892e                 mov dword ptr [esi], ebp
// 004d6c60  8b4718               mov eax, dword ptr [edi + 0x18]
// 004d6c63  3b30                 cmp esi, dword ptr [eax]
// 004d6c65  7512                 jne 0x4d6c79
// 004d6c67  8928                 mov dword ptr [eax], ebp
// 004d6c69  eb0e                 jmp 0x4d6c79
// 004d6c6b  896e08               mov dword ptr [esi + 8], ebp
// 004d6c6e  8b4718               mov eax, dword ptr [edi + 0x18]
// 004d6c71  3b7008               cmp esi, dword ptr [eax + 8]
// 004d6c74  7503                 jne 0x4d6c79
// 004d6c76  896808               mov dword ptr [eax + 8], ebp
// 004d6c79  8b5504               mov edx, dword ptr [ebp + 4]
// 004d6c7c  807a2800             cmp byte ptr [edx + 0x28], 0
// 004d6c80  8d4504               lea eax, [ebp + 4]
// 004d6c83  8bf5                 mov esi, ebp
// 004d6c85  0f85ea000000         jne 0x4d6d75
// 004d6c8b  eb03                 jmp 0x4d6c90
// 004d6c8d  8d4900               lea ecx, [ecx]
// 004d6c90  8b08                 mov ecx, dword ptr [eax]
// 004d6c92  8b5104               mov edx, dword ptr [ecx + 4]
// 004d6c95  3b0a                 cmp ecx, dword ptr [edx]
// 004d6c97  7551                 jne 0x4d6cea
// 004d6c99  8b5208               mov edx, dword ptr [edx + 8]
// 004d6c9c  807a2800             cmp byte ptr [edx + 0x28], 0
// 004d6ca0  7519                 jne 0x4d6cbb
// 004d6ca2  885928               mov byte ptr [ecx + 0x28], bl
// 004d6ca5  885a28               mov byte ptr [edx + 0x28], bl
// 004d6ca8  8b10                 mov edx, dword ptr [eax]
// 004d6caa  8b4a04               mov ecx, dword ptr [edx + 4]
// 004d6cad  c6412800             mov byte ptr [ecx + 0x28], 0
// 004d6cb1  8b10                 mov edx, dword ptr [eax]
// 004d6cb3  8b7204               mov esi, dword ptr [edx + 4]
// 004d6cb6  e9aa000000           jmp 0x4d6d65
// 004d6cbb  3b7108               cmp esi, dword ptr [ecx + 8]
// 004d6cbe  750a                 jne 0x4d6cca
// 004d6cc0  8bf1                 mov esi, ecx
// 004d6cc2  56                   push esi
// 004d6cc3  8bcf                 mov ecx, edi
// 004d6cc5  e806b52000           call 0x6e21d0
// 004d6cca  8b4604               mov eax, dword ptr [esi + 4]
// 004d6ccd  885828               mov byte ptr [eax + 0x28], bl
// 004d6cd0  8b4e04               mov ecx, dword ptr [esi + 4]
// 004d6cd3  8b5104               mov edx, dword ptr [ecx + 4]
// 004d6cd6  c6422800             mov byte ptr [edx + 0x28], 0
// 004d6cda  8b4604               mov eax, dword ptr [esi + 4]
// 004d6cdd  8b4804               mov ecx, dword ptr [eax + 4]
// 004d6ce0  51                   push ecx
// 004d6ce1  8bcf                 mov ecx, edi
// 004d6ce3  e808fd0300           call 0x5169f0
// 004d6ce8  eb7b                 jmp 0x4d6d65
// 004d6cea  8b12                 mov edx, dword ptr [edx]
// 004d6cec  807a2800             cmp byte ptr [edx + 0x28], 0
// 004d6cf0  7516                 jne 0x4d6d08
// 004d6cf2  885928               mov byte ptr [ecx + 0x28], bl
// 004d6cf5  885a28               mov byte ptr [edx + 0x28], bl
// 004d6cf8  8b10                 mov edx, dword ptr [eax]
// 004d6cfa  8b4a04               mov ecx, dword ptr [edx + 4]
// 004d6cfd  c6412800             mov byte ptr [ecx + 0x28], 0
// 004d6d01  8b10                 mov edx, dword ptr [eax]
// 004d6d03  8b7204               mov esi, dword ptr [edx + 4]
// 004d6d06  eb5d                 jmp 0x4d6d65
// 004d6d08  3b31                 cmp esi, dword ptr [ecx]
// 004d6d0a  750a                 jne 0x4d6d16
// 004d6d0c  8bf1                 mov esi, ecx
// 004d6d0e  56                   push esi
// 004d6d0f  8bcf                 mov ecx, edi
// 004d6d11  e8dafc0300           call 0x5169f0
// 004d6d16  8b4604               mov eax, dword ptr [esi + 4]
// 004d6d19  885828               mov byte ptr [eax + 0x28], bl
// 004d6d1c  8b4e04               mov ecx, dword ptr [esi + 4]
// 004d6d1f  8b5104               mov edx, dword ptr [ecx + 4]
// 004d6d22  c6422800             mov byte ptr [edx + 0x28], 0
// 004d6d26  8b4604               mov eax, dword ptr [esi + 4]
// 004d6d29  8b4004               mov eax, dword ptr [eax + 4]
// 004d6d2c  8b4808               mov ecx, dword ptr [eax + 8]
// 004d6d2f  8b11                 mov edx, dword ptr [ecx]
// 004d6d31  895008               mov dword ptr [eax + 8], edx
// 004d6d34  8b11                 mov edx, dword ptr [ecx]
// 004d6d36  807a2900             cmp byte ptr [edx + 0x29], 0
// 004d6d3a  7503                 jne 0x4d6d3f
// 004d6d3c  894204               mov dword ptr [edx + 4], eax
// 004d6d3f  8b5004               mov edx, dword ptr [eax + 4]
// 004d6d42  895104               mov dword ptr [ecx + 4], edx
// 004d6d45  8b5718               mov edx, dword ptr [edi + 0x18]
// 004d6d48  3b4204               cmp eax, dword ptr [edx + 4]
// 004d6d4b  7505                 jne 0x4d6d52
// 004d6d4d  894a04               mov dword ptr [edx + 4], ecx
// 004d6d50  eb0e                 jmp 0x4d6d60
// 004d6d52  8b5004               mov edx, dword ptr [eax + 4]
// 004d6d55  3b02                 cmp eax, dword ptr [edx]
// 004d6d57  7504                 jne 0x4d6d5d
// 004d6d59  890a                 mov dword ptr [edx], ecx
// 004d6d5b  eb03                 jmp 0x4d6d60
// 004d6d5d  894a08               mov dword ptr [edx + 8], ecx
// 004d6d60  8901                 mov dword ptr [ecx], eax
// 004d6d62  894804               mov dword ptr [eax + 4], ecx
// 004d6d65  8b4e04               mov ecx, dword ptr [esi + 4]
// 004d6d68  80792800             cmp byte ptr [ecx + 0x28], 0
// 004d6d6c  8d4604               lea eax, [esi + 4]
// 004d6d6f  0f841bffffff         je 0x4d6c90
// 004d6d75  8b5718               mov edx, dword ptr [edi + 0x18]
// 004d6d78  8b4204               mov eax, dword ptr [edx + 4]
// 004d6d7b  885828               mov byte ptr [eax + 0x28], bl
// 004d6d7e  8b442464             mov eax, dword ptr [esp + 0x64]
// 004d6d82  8b0f                 mov ecx, dword ptr [edi]
// 004d6d84  5e                   pop esi
// 004d6d85  896804               mov dword ptr [eax + 4], ebp
// 004d6d88  5d                   pop ebp
// 004d6d89  8908                 mov dword ptr [eax], ecx
// 004d6d8b  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 004d6d8f  5b                   pop ebx
// 004d6d90  5f                   pop edi
// 004d6d91  64890d00000000       mov dword ptr fs:[0], ecx
// 004d6d98  83c450               add esp, 0x50
// 004d6d9b  c21000               ret 0x10
// standard library map_int<pod24> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod24>
struct E { int v[6]; };
#include <map>
template class std::map<int, E>;
