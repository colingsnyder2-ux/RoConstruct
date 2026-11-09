// from server: 100% by auto
// roc 2009-06 006e2bf0  unit: RBX::ScoreHud  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006e2bf0
//
// 006e2bf0  64a100000000         mov eax, dword ptr fs:[0]
// 006e2bf6  6aff                 push -1
// 006e2bf8  68b2db8500           push 0x85dbb2
// 006e2bfd  50                   push eax
// 006e2bfe  64892500000000       mov dword ptr fs:[0], esp
// 006e2c05  83ec44               sub esp, 0x44
// 006e2c08  57                   push edi
// 006e2c09  8bf9                 mov edi, ecx
// 006e2c0b  817f1c48922409       cmp dword ptr [edi + 0x1c], 0x9249248
// 006e2c12  7259                 jb 0x6e2c6d
// 006e2c14  68c0c98a00           push 0x8ac9c0
// 006e2c19  8d4c2408             lea ecx, [esp + 8]
// 006e2c1d  ff15b4e48900         call dword ptr [0x89e4b4]
// 006e2c23  8d4c2420             lea ecx, [esp + 0x20]
// 006e2c27  c744245000000000     mov dword ptr [esp + 0x50], 0
// 006e2c2f  ff15b8e98900         call dword ptr [0x89e9b8]
// 006e2c35  8d442404             lea eax, [esp + 4]
// 006e2c39  50                   push eax
// 006e2c3a  8d4c2430             lea ecx, [esp + 0x30]
// 006e2c3e  c644245401           mov byte ptr [esp + 0x54], 1
// 006e2c43  c744242444c98a00     mov dword ptr [esp + 0x24], 0x8ac944
// 006e2c4b  ff15b8e48900         call dword ptr [0x89e4b8]
// 006e2c51  6834929700           push 0x979234
// 006e2c56  8d4c2424             lea ecx, [esp + 0x24]
// 006e2c5a  51                   push ecx
// 006e2c5b  c644245800           mov byte ptr [esp + 0x58], 0
// 006e2c60  c744242850c98a00     mov dword ptr [esp + 0x28], 0x8ac950
// 006e2c68  e8dd6d0300           call 0x719a4a
// 006e2c6d  8b542464             mov edx, dword ptr [esp + 0x64]
// 006e2c71  8b4718               mov eax, dword ptr [edi + 0x18]
// 006e2c74  53                   push ebx
// 006e2c75  55                   push ebp
// 006e2c76  56                   push esi
// 006e2c77  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 006e2c7b  6a00                 push 0
// 006e2c7d  52                   push edx
// 006e2c7e  50                   push eax
// 006e2c7f  56                   push esi
// 006e2c80  50                   push eax
// 006e2c81  e88afdffff           call 0x6e2a10
// 006e2c86  8be8                 mov ebp, eax
// 006e2c88  8b4718               mov eax, dword ptr [edi + 0x18]
// 006e2c8b  bb01000000           mov ebx, 1
// 006e2c90  015f1c               add dword ptr [edi + 0x1c], ebx
// 006e2c93  3bf0                 cmp esi, eax
// 006e2c95  7510                 jne 0x6e2ca7
// 006e2c97  896804               mov dword ptr [eax + 4], ebp
// 006e2c9a  8b4718               mov eax, dword ptr [edi + 0x18]
// 006e2c9d  8928                 mov dword ptr [eax], ebp
// 006e2c9f  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 006e2ca2  896908               mov dword ptr [ecx + 8], ebp
// 006e2ca5  eb22                 jmp 0x6e2cc9
// 006e2ca7  807c246800           cmp byte ptr [esp + 0x68], 0
// 006e2cac  740d                 je 0x6e2cbb
// 006e2cae  892e                 mov dword ptr [esi], ebp
// 006e2cb0  8b4718               mov eax, dword ptr [edi + 0x18]
// 006e2cb3  3b30                 cmp esi, dword ptr [eax]
// 006e2cb5  7512                 jne 0x6e2cc9
// 006e2cb7  8928                 mov dword ptr [eax], ebp
// 006e2cb9  eb0e                 jmp 0x6e2cc9
// 006e2cbb  896e08               mov dword ptr [esi + 8], ebp
// 006e2cbe  8b4718               mov eax, dword ptr [edi + 0x18]
// 006e2cc1  3b7008               cmp esi, dword ptr [eax + 8]
// 006e2cc4  7503                 jne 0x6e2cc9
// 006e2cc6  896808               mov dword ptr [eax + 8], ebp
// 006e2cc9  8b5504               mov edx, dword ptr [ebp + 4]
// 006e2ccc  807a2800             cmp byte ptr [edx + 0x28], 0
// 006e2cd0  8d4504               lea eax, [ebp + 4]
// 006e2cd3  8bf5                 mov esi, ebp
// 006e2cd5  0f85ea000000         jne 0x6e2dc5
// 006e2cdb  eb03                 jmp 0x6e2ce0
// 006e2cdd  8d4900               lea ecx, [ecx]
// 006e2ce0  8b08                 mov ecx, dword ptr [eax]
// 006e2ce2  8b5104               mov edx, dword ptr [ecx + 4]
// 006e2ce5  3b0a                 cmp ecx, dword ptr [edx]
// 006e2ce7  7551                 jne 0x6e2d3a
// 006e2ce9  8b5208               mov edx, dword ptr [edx + 8]
// 006e2cec  807a2800             cmp byte ptr [edx + 0x28], 0
// 006e2cf0  7519                 jne 0x6e2d0b
// 006e2cf2  885928               mov byte ptr [ecx + 0x28], bl
// 006e2cf5  885a28               mov byte ptr [edx + 0x28], bl
// 006e2cf8  8b10                 mov edx, dword ptr [eax]
// 006e2cfa  8b4a04               mov ecx, dword ptr [edx + 4]
// 006e2cfd  c6412800             mov byte ptr [ecx + 0x28], 0
// 006e2d01  8b10                 mov edx, dword ptr [eax]
// 006e2d03  8b7204               mov esi, dword ptr [edx + 4]
// 006e2d06  e9aa000000           jmp 0x6e2db5
// 006e2d0b  3b7108               cmp esi, dword ptr [ecx + 8]
// 006e2d0e  750a                 jne 0x6e2d1a
// 006e2d10  8bf1                 mov esi, ecx
// 006e2d12  56                   push esi
// 006e2d13  8bcf                 mov ecx, edi
// 006e2d15  e8b6f4ffff           call 0x6e21d0
// 006e2d1a  8b4604               mov eax, dword ptr [esi + 4]
// 006e2d1d  885828               mov byte ptr [eax + 0x28], bl
// 006e2d20  8b4e04               mov ecx, dword ptr [esi + 4]
// 006e2d23  8b5104               mov edx, dword ptr [ecx + 4]
// 006e2d26  c6422800             mov byte ptr [edx + 0x28], 0
// 006e2d2a  8b4604               mov eax, dword ptr [esi + 4]
// 006e2d2d  8b4804               mov ecx, dword ptr [eax + 4]
// 006e2d30  51                   push ecx
// 006e2d31  8bcf                 mov ecx, edi
// 006e2d33  e8b83ce3ff           call 0x5169f0
// 006e2d38  eb7b                 jmp 0x6e2db5
// 006e2d3a  8b12                 mov edx, dword ptr [edx]
// 006e2d3c  807a2800             cmp byte ptr [edx + 0x28], 0
// 006e2d40  7516                 jne 0x6e2d58
// 006e2d42  885928               mov byte ptr [ecx + 0x28], bl
// 006e2d45  885a28               mov byte ptr [edx + 0x28], bl
// 006e2d48  8b10                 mov edx, dword ptr [eax]
// 006e2d4a  8b4a04               mov ecx, dword ptr [edx + 4]
// 006e2d4d  c6412800             mov byte ptr [ecx + 0x28], 0
// 006e2d51  8b10                 mov edx, dword ptr [eax]
// 006e2d53  8b7204               mov esi, dword ptr [edx + 4]
// 006e2d56  eb5d                 jmp 0x6e2db5
// 006e2d58  3b31                 cmp esi, dword ptr [ecx]
// 006e2d5a  750a                 jne 0x6e2d66
// 006e2d5c  8bf1                 mov esi, ecx
// 006e2d5e  56                   push esi
// 006e2d5f  8bcf                 mov ecx, edi
// 006e2d61  e88a3ce3ff           call 0x5169f0
// 006e2d66  8b4604               mov eax, dword ptr [esi + 4]
// 006e2d69  885828               mov byte ptr [eax + 0x28], bl
// 006e2d6c  8b4e04               mov ecx, dword ptr [esi + 4]
// 006e2d6f  8b5104               mov edx, dword ptr [ecx + 4]
// 006e2d72  c6422800             mov byte ptr [edx + 0x28], 0
// 006e2d76  8b4604               mov eax, dword ptr [esi + 4]
// 006e2d79  8b4004               mov eax, dword ptr [eax + 4]
// 006e2d7c  8b4808               mov ecx, dword ptr [eax + 8]
// 006e2d7f  8b11                 mov edx, dword ptr [ecx]
// 006e2d81  895008               mov dword ptr [eax + 8], edx
// 006e2d84  8b11                 mov edx, dword ptr [ecx]
// 006e2d86  807a2900             cmp byte ptr [edx + 0x29], 0
// 006e2d8a  7503                 jne 0x6e2d8f
// 006e2d8c  894204               mov dword ptr [edx + 4], eax
// 006e2d8f  8b5004               mov edx, dword ptr [eax + 4]
// 006e2d92  895104               mov dword ptr [ecx + 4], edx
// 006e2d95  8b5718               mov edx, dword ptr [edi + 0x18]
// 006e2d98  3b4204               cmp eax, dword ptr [edx + 4]
// 006e2d9b  7505                 jne 0x6e2da2
// 006e2d9d  894a04               mov dword ptr [edx + 4], ecx
// 006e2da0  eb0e                 jmp 0x6e2db0
// 006e2da2  8b5004               mov edx, dword ptr [eax + 4]
// 006e2da5  3b02                 cmp eax, dword ptr [edx]
// 006e2da7  7504                 jne 0x6e2dad
// 006e2da9  890a                 mov dword ptr [edx], ecx
// 006e2dab  eb03                 jmp 0x6e2db0
// 006e2dad  894a08               mov dword ptr [edx + 8], ecx
// 006e2db0  8901                 mov dword ptr [ecx], eax
// 006e2db2  894804               mov dword ptr [eax + 4], ecx
// 006e2db5  8b4e04               mov ecx, dword ptr [esi + 4]
// 006e2db8  80792800             cmp byte ptr [ecx + 0x28], 0
// 006e2dbc  8d4604               lea eax, [esi + 4]
// 006e2dbf  0f841bffffff         je 0x6e2ce0
// 006e2dc5  8b5718               mov edx, dword ptr [edi + 0x18]
// 006e2dc8  8b4204               mov eax, dword ptr [edx + 4]
// 006e2dcb  885828               mov byte ptr [eax + 0x28], bl
// 006e2dce  8b442464             mov eax, dword ptr [esp + 0x64]
// 006e2dd2  8b0f                 mov ecx, dword ptr [edi]
// 006e2dd4  5e                   pop esi
// 006e2dd5  896804               mov dword ptr [eax + 4], ebp
// 006e2dd8  5d                   pop ebp
// 006e2dd9  8908                 mov dword ptr [eax], ecx
// 006e2ddb  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 006e2ddf  5b                   pop ebx
// 006e2de0  5f                   pop edi
// 006e2de1  64890d00000000       mov dword ptr fs:[0], ecx
// 006e2de8  83c450               add esp, 0x50
// 006e2deb  c21000               ret 0x10
// standard library map_int<pod24> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod24>
struct E { int v[6]; };
#include <map>
template class std::map<int, E>;
