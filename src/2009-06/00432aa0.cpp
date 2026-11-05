// from server: 100% by auto
// roc 2009-06 00432aa0  unit: IIHAAH::?$CMap  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00432aa0
//
// 00432aa0  64a100000000         mov eax, dword ptr fs:[0]
// 00432aa6  6aff                 push -1
// 00432aa8  68b2db8500           push 0x85dbb2
// 00432aad  50                   push eax
// 00432aae  64892500000000       mov dword ptr fs:[0], esp
// 00432ab5  83ec44               sub esp, 0x44
// 00432ab8  57                   push edi
// 00432ab9  8bf9                 mov edi, ecx
// 00432abb  817f1c54555515       cmp dword ptr [edi + 0x1c], 0x15555554
// 00432ac2  7259                 jb 0x432b1d
// 00432ac4  68c0c98a00           push 0x8ac9c0
// 00432ac9  8d4c2408             lea ecx, [esp + 8]
// 00432acd  ff15b4e48900         call dword ptr [0x89e4b4]
// 00432ad3  8d4c2420             lea ecx, [esp + 0x20]
// 00432ad7  c744245000000000     mov dword ptr [esp + 0x50], 0
// 00432adf  ff15b8e98900         call dword ptr [0x89e9b8]
// 00432ae5  8d442404             lea eax, [esp + 4]
// 00432ae9  50                   push eax
// 00432aea  8d4c2430             lea ecx, [esp + 0x30]
// 00432aee  c644245401           mov byte ptr [esp + 0x54], 1
// 00432af3  c744242444c98a00     mov dword ptr [esp + 0x24], 0x8ac944
// 00432afb  ff15b8e48900         call dword ptr [0x89e4b8]
// 00432b01  6834929700           push 0x979234
// 00432b06  8d4c2424             lea ecx, [esp + 0x24]
// 00432b0a  51                   push ecx
// 00432b0b  c644245800           mov byte ptr [esp + 0x58], 0
// 00432b10  c744242850c98a00     mov dword ptr [esp + 0x28], 0x8ac950
// 00432b18  e82d6f2e00           call 0x719a4a
// 00432b1d  8b542464             mov edx, dword ptr [esp + 0x64]
// 00432b21  8b4718               mov eax, dword ptr [edi + 0x18]
// 00432b24  53                   push ebx
// 00432b25  55                   push ebp
// 00432b26  56                   push esi
// 00432b27  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 00432b2b  6a00                 push 0
// 00432b2d  52                   push edx
// 00432b2e  50                   push eax
// 00432b2f  56                   push esi
// 00432b30  50                   push eax
// 00432b31  e8eafbffff           call 0x432720
// 00432b36  8be8                 mov ebp, eax
// 00432b38  8b4718               mov eax, dword ptr [edi + 0x18]
// 00432b3b  bb01000000           mov ebx, 1
// 00432b40  015f1c               add dword ptr [edi + 0x1c], ebx
// 00432b43  3bf0                 cmp esi, eax
// 00432b45  7510                 jne 0x432b57
// 00432b47  896804               mov dword ptr [eax + 4], ebp
// 00432b4a  8b4718               mov eax, dword ptr [edi + 0x18]
// 00432b4d  8928                 mov dword ptr [eax], ebp
// 00432b4f  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 00432b52  896908               mov dword ptr [ecx + 8], ebp
// 00432b55  eb22                 jmp 0x432b79
// 00432b57  807c246800           cmp byte ptr [esp + 0x68], 0
// 00432b5c  740d                 je 0x432b6b
// 00432b5e  892e                 mov dword ptr [esi], ebp
// 00432b60  8b4718               mov eax, dword ptr [edi + 0x18]
// 00432b63  3b30                 cmp esi, dword ptr [eax]
// 00432b65  7512                 jne 0x432b79
// 00432b67  8928                 mov dword ptr [eax], ebp
// 00432b69  eb0e                 jmp 0x432b79
// 00432b6b  896e08               mov dword ptr [esi + 8], ebp
// 00432b6e  8b4718               mov eax, dword ptr [edi + 0x18]
// 00432b71  3b7008               cmp esi, dword ptr [eax + 8]
// 00432b74  7503                 jne 0x432b79
// 00432b76  896808               mov dword ptr [eax + 8], ebp
// 00432b79  8b5504               mov edx, dword ptr [ebp + 4]
// 00432b7c  807a1800             cmp byte ptr [edx + 0x18], 0
// 00432b80  8d4504               lea eax, [ebp + 4]
// 00432b83  8bf5                 mov esi, ebp
// 00432b85  0f85ea000000         jne 0x432c75
// 00432b8b  eb03                 jmp 0x432b90
// 00432b8d  8d4900               lea ecx, [ecx]
// 00432b90  8b08                 mov ecx, dword ptr [eax]
// 00432b92  8b5104               mov edx, dword ptr [ecx + 4]
// 00432b95  3b0a                 cmp ecx, dword ptr [edx]
// 00432b97  7551                 jne 0x432bea
// 00432b99  8b5208               mov edx, dword ptr [edx + 8]
// 00432b9c  807a1800             cmp byte ptr [edx + 0x18], 0
// 00432ba0  7519                 jne 0x432bbb
// 00432ba2  885918               mov byte ptr [ecx + 0x18], bl
// 00432ba5  885a18               mov byte ptr [edx + 0x18], bl
// 00432ba8  8b10                 mov edx, dword ptr [eax]
// 00432baa  8b4a04               mov ecx, dword ptr [edx + 4]
// 00432bad  c6411800             mov byte ptr [ecx + 0x18], 0
// 00432bb1  8b10                 mov edx, dword ptr [eax]
// 00432bb3  8b7204               mov esi, dword ptr [edx + 4]
// 00432bb6  e9aa000000           jmp 0x432c65
// 00432bbb  3b7108               cmp esi, dword ptr [ecx + 8]
// 00432bbe  750a                 jne 0x432bca
// 00432bc0  8bf1                 mov esi, ecx
// 00432bc2  56                   push esi
// 00432bc3  8bcf                 mov ecx, edi
// 00432bc5  e8765a1e00           call 0x618640
// 00432bca  8b4604               mov eax, dword ptr [esi + 4]
// 00432bcd  885818               mov byte ptr [eax + 0x18], bl
// 00432bd0  8b4e04               mov ecx, dword ptr [esi + 4]
// 00432bd3  8b5104               mov edx, dword ptr [ecx + 4]
// 00432bd6  c6421800             mov byte ptr [edx + 0x18], 0
// 00432bda  8b4604               mov eax, dword ptr [esi + 4]
// 00432bdd  8b4804               mov ecx, dword ptr [eax + 4]
// 00432be0  51                   push ecx
// 00432be1  8bcf                 mov ecx, edi
// 00432be3  e8d80e2100           call 0x643ac0
// 00432be8  eb7b                 jmp 0x432c65
// 00432bea  8b12                 mov edx, dword ptr [edx]
// 00432bec  807a1800             cmp byte ptr [edx + 0x18], 0
// 00432bf0  7516                 jne 0x432c08
// 00432bf2  885918               mov byte ptr [ecx + 0x18], bl
// 00432bf5  885a18               mov byte ptr [edx + 0x18], bl
// 00432bf8  8b10                 mov edx, dword ptr [eax]
// 00432bfa  8b4a04               mov ecx, dword ptr [edx + 4]
// 00432bfd  c6411800             mov byte ptr [ecx + 0x18], 0
// 00432c01  8b10                 mov edx, dword ptr [eax]
// 00432c03  8b7204               mov esi, dword ptr [edx + 4]
// 00432c06  eb5d                 jmp 0x432c65
// 00432c08  3b31                 cmp esi, dword ptr [ecx]
// 00432c0a  750a                 jne 0x432c16
// 00432c0c  8bf1                 mov esi, ecx
// 00432c0e  56                   push esi
// 00432c0f  8bcf                 mov ecx, edi
// 00432c11  e8aa0e2100           call 0x643ac0
// 00432c16  8b4604               mov eax, dword ptr [esi + 4]
// 00432c19  885818               mov byte ptr [eax + 0x18], bl
// 00432c1c  8b4e04               mov ecx, dword ptr [esi + 4]
// 00432c1f  8b5104               mov edx, dword ptr [ecx + 4]
// 00432c22  c6421800             mov byte ptr [edx + 0x18], 0
// 00432c26  8b4604               mov eax, dword ptr [esi + 4]
// 00432c29  8b4004               mov eax, dword ptr [eax + 4]
// 00432c2c  8b4808               mov ecx, dword ptr [eax + 8]
// 00432c2f  8b11                 mov edx, dword ptr [ecx]
// 00432c31  895008               mov dword ptr [eax + 8], edx
// 00432c34  8b11                 mov edx, dword ptr [ecx]
// 00432c36  807a1900             cmp byte ptr [edx + 0x19], 0
// 00432c3a  7503                 jne 0x432c3f
// 00432c3c  894204               mov dword ptr [edx + 4], eax
// 00432c3f  8b5004               mov edx, dword ptr [eax + 4]
// 00432c42  895104               mov dword ptr [ecx + 4], edx
// 00432c45  8b5718               mov edx, dword ptr [edi + 0x18]
// 00432c48  3b4204               cmp eax, dword ptr [edx + 4]
// 00432c4b  7505                 jne 0x432c52
// 00432c4d  894a04               mov dword ptr [edx + 4], ecx
// 00432c50  eb0e                 jmp 0x432c60
// 00432c52  8b5004               mov edx, dword ptr [eax + 4]
// 00432c55  3b02                 cmp eax, dword ptr [edx]
// 00432c57  7504                 jne 0x432c5d
// 00432c59  890a                 mov dword ptr [edx], ecx
// 00432c5b  eb03                 jmp 0x432c60
// 00432c5d  894a08               mov dword ptr [edx + 8], ecx
// 00432c60  8901                 mov dword ptr [ecx], eax
// 00432c62  894804               mov dword ptr [eax + 4], ecx
// 00432c65  8b4e04               mov ecx, dword ptr [esi + 4]
// 00432c68  80791800             cmp byte ptr [ecx + 0x18], 0
// 00432c6c  8d4604               lea eax, [esi + 4]
// 00432c6f  0f841bffffff         je 0x432b90
// 00432c75  8b5718               mov edx, dword ptr [edi + 0x18]
// 00432c78  8b4204               mov eax, dword ptr [edx + 4]
// 00432c7b  885818               mov byte ptr [eax + 0x18], bl
// 00432c7e  8b442464             mov eax, dword ptr [esp + 0x64]
// 00432c82  8b0f                 mov ecx, dword ptr [edi]
// 00432c84  5e                   pop esi
// 00432c85  896804               mov dword ptr [eax + 4], ebp
// 00432c88  5d                   pop ebp
// 00432c89  8908                 mov dword ptr [eax], ecx
// 00432c8b  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 00432c8f  5b                   pop ebx
// 00432c90  5f                   pop edi
// 00432c91  64890d00000000       mov dword ptr fs:[0], ecx
// 00432c98  83c450               add esp, 0x50
// 00432c9b  c21000               ret 0x10
// standard library map_int<pod8> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod8>
struct E { int v[2]; };
#include <map>
template class std::map<int, E>;
