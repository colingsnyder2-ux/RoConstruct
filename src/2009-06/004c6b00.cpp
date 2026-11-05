// from server: 100% by auto
// roc 2009-06 004c6b00  unit: RBX::VInstance::?$NonFactoryProduct  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004c6b00
//
// 004c6b00  64a100000000         mov eax, dword ptr fs:[0]
// 004c6b06  6aff                 push -1
// 004c6b08  68b2db8500           push 0x85dbb2
// 004c6b0d  50                   push eax
// 004c6b0e  64892500000000       mov dword ptr fs:[0], esp
// 004c6b15  83ec44               sub esp, 0x44
// 004c6b18  57                   push edi
// 004c6b19  8bf9                 mov edi, ecx
// 004c6b1b  817f1c54555515       cmp dword ptr [edi + 0x1c], 0x15555554
// 004c6b22  7259                 jb 0x4c6b7d
// 004c6b24  68c0c98a00           push 0x8ac9c0
// 004c6b29  8d4c2408             lea ecx, [esp + 8]
// 004c6b2d  ff15b4e48900         call dword ptr [0x89e4b4]
// 004c6b33  8d4c2420             lea ecx, [esp + 0x20]
// 004c6b37  c744245000000000     mov dword ptr [esp + 0x50], 0
// 004c6b3f  ff15b8e98900         call dword ptr [0x89e9b8]
// 004c6b45  8d442404             lea eax, [esp + 4]
// 004c6b49  50                   push eax
// 004c6b4a  8d4c2430             lea ecx, [esp + 0x30]
// 004c6b4e  c644245401           mov byte ptr [esp + 0x54], 1
// 004c6b53  c744242444c98a00     mov dword ptr [esp + 0x24], 0x8ac944
// 004c6b5b  ff15b8e48900         call dword ptr [0x89e4b8]
// 004c6b61  6834929700           push 0x979234
// 004c6b66  8d4c2424             lea ecx, [esp + 0x24]
// 004c6b6a  51                   push ecx
// 004c6b6b  c644245800           mov byte ptr [esp + 0x58], 0
// 004c6b70  c744242850c98a00     mov dword ptr [esp + 0x28], 0x8ac950
// 004c6b78  e8cd2e2500           call 0x719a4a
// 004c6b7d  8b542464             mov edx, dword ptr [esp + 0x64]
// 004c6b81  8b4718               mov eax, dword ptr [edi + 0x18]
// 004c6b84  53                   push ebx
// 004c6b85  55                   push ebp
// 004c6b86  56                   push esi
// 004c6b87  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 004c6b8b  6a00                 push 0
// 004c6b8d  52                   push edx
// 004c6b8e  50                   push eax
// 004c6b8f  56                   push esi
// 004c6b90  50                   push eax
// 004c6b91  e84ae4ffff           call 0x4c4fe0
// 004c6b96  8be8                 mov ebp, eax
// 004c6b98  8b4718               mov eax, dword ptr [edi + 0x18]
// 004c6b9b  bb01000000           mov ebx, 1
// 004c6ba0  015f1c               add dword ptr [edi + 0x1c], ebx
// 004c6ba3  3bf0                 cmp esi, eax
// 004c6ba5  7510                 jne 0x4c6bb7
// 004c6ba7  896804               mov dword ptr [eax + 4], ebp
// 004c6baa  8b4718               mov eax, dword ptr [edi + 0x18]
// 004c6bad  8928                 mov dword ptr [eax], ebp
// 004c6baf  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 004c6bb2  896908               mov dword ptr [ecx + 8], ebp
// 004c6bb5  eb22                 jmp 0x4c6bd9
// 004c6bb7  807c246800           cmp byte ptr [esp + 0x68], 0
// 004c6bbc  740d                 je 0x4c6bcb
// 004c6bbe  892e                 mov dword ptr [esi], ebp
// 004c6bc0  8b4718               mov eax, dword ptr [edi + 0x18]
// 004c6bc3  3b30                 cmp esi, dword ptr [eax]
// 004c6bc5  7512                 jne 0x4c6bd9
// 004c6bc7  8928                 mov dword ptr [eax], ebp
// 004c6bc9  eb0e                 jmp 0x4c6bd9
// 004c6bcb  896e08               mov dword ptr [esi + 8], ebp
// 004c6bce  8b4718               mov eax, dword ptr [edi + 0x18]
// 004c6bd1  3b7008               cmp esi, dword ptr [eax + 8]
// 004c6bd4  7503                 jne 0x4c6bd9
// 004c6bd6  896808               mov dword ptr [eax + 8], ebp
// 004c6bd9  8b5504               mov edx, dword ptr [ebp + 4]
// 004c6bdc  807a1800             cmp byte ptr [edx + 0x18], 0
// 004c6be0  8d4504               lea eax, [ebp + 4]
// 004c6be3  8bf5                 mov esi, ebp
// 004c6be5  0f85ea000000         jne 0x4c6cd5
// 004c6beb  eb03                 jmp 0x4c6bf0
// 004c6bed  8d4900               lea ecx, [ecx]
// 004c6bf0  8b08                 mov ecx, dword ptr [eax]
// 004c6bf2  8b5104               mov edx, dword ptr [ecx + 4]
// 004c6bf5  3b0a                 cmp ecx, dword ptr [edx]
// 004c6bf7  7551                 jne 0x4c6c4a
// 004c6bf9  8b5208               mov edx, dword ptr [edx + 8]
// 004c6bfc  807a1800             cmp byte ptr [edx + 0x18], 0
// 004c6c00  7519                 jne 0x4c6c1b
// 004c6c02  885918               mov byte ptr [ecx + 0x18], bl
// 004c6c05  885a18               mov byte ptr [edx + 0x18], bl
// 004c6c08  8b10                 mov edx, dword ptr [eax]
// 004c6c0a  8b4a04               mov ecx, dword ptr [edx + 4]
// 004c6c0d  c6411800             mov byte ptr [ecx + 0x18], 0
// 004c6c11  8b10                 mov edx, dword ptr [eax]
// 004c6c13  8b7204               mov esi, dword ptr [edx + 4]
// 004c6c16  e9aa000000           jmp 0x4c6cc5
// 004c6c1b  3b7108               cmp esi, dword ptr [ecx + 8]
// 004c6c1e  750a                 jne 0x4c6c2a
// 004c6c20  8bf1                 mov esi, ecx
// 004c6c22  56                   push esi
// 004c6c23  8bcf                 mov ecx, edi
// 004c6c25  e8161a1500           call 0x618640
// 004c6c2a  8b4604               mov eax, dword ptr [esi + 4]
// 004c6c2d  885818               mov byte ptr [eax + 0x18], bl
// 004c6c30  8b4e04               mov ecx, dword ptr [esi + 4]
// 004c6c33  8b5104               mov edx, dword ptr [ecx + 4]
// 004c6c36  c6421800             mov byte ptr [edx + 0x18], 0
// 004c6c3a  8b4604               mov eax, dword ptr [esi + 4]
// 004c6c3d  8b4804               mov ecx, dword ptr [eax + 4]
// 004c6c40  51                   push ecx
// 004c6c41  8bcf                 mov ecx, edi
// 004c6c43  e878ce1700           call 0x643ac0
// 004c6c48  eb7b                 jmp 0x4c6cc5
// 004c6c4a  8b12                 mov edx, dword ptr [edx]
// 004c6c4c  807a1800             cmp byte ptr [edx + 0x18], 0
// 004c6c50  7516                 jne 0x4c6c68
// 004c6c52  885918               mov byte ptr [ecx + 0x18], bl
// 004c6c55  885a18               mov byte ptr [edx + 0x18], bl
// 004c6c58  8b10                 mov edx, dword ptr [eax]
// 004c6c5a  8b4a04               mov ecx, dword ptr [edx + 4]
// 004c6c5d  c6411800             mov byte ptr [ecx + 0x18], 0
// 004c6c61  8b10                 mov edx, dword ptr [eax]
// 004c6c63  8b7204               mov esi, dword ptr [edx + 4]
// 004c6c66  eb5d                 jmp 0x4c6cc5
// 004c6c68  3b31                 cmp esi, dword ptr [ecx]
// 004c6c6a  750a                 jne 0x4c6c76
// 004c6c6c  8bf1                 mov esi, ecx
// 004c6c6e  56                   push esi
// 004c6c6f  8bcf                 mov ecx, edi
// 004c6c71  e84ace1700           call 0x643ac0
// 004c6c76  8b4604               mov eax, dword ptr [esi + 4]
// 004c6c79  885818               mov byte ptr [eax + 0x18], bl
// 004c6c7c  8b4e04               mov ecx, dword ptr [esi + 4]
// 004c6c7f  8b5104               mov edx, dword ptr [ecx + 4]
// 004c6c82  c6421800             mov byte ptr [edx + 0x18], 0
// 004c6c86  8b4604               mov eax, dword ptr [esi + 4]
// 004c6c89  8b4004               mov eax, dword ptr [eax + 4]
// 004c6c8c  8b4808               mov ecx, dword ptr [eax + 8]
// 004c6c8f  8b11                 mov edx, dword ptr [ecx]
// 004c6c91  895008               mov dword ptr [eax + 8], edx
// 004c6c94  8b11                 mov edx, dword ptr [ecx]
// 004c6c96  807a1900             cmp byte ptr [edx + 0x19], 0
// 004c6c9a  7503                 jne 0x4c6c9f
// 004c6c9c  894204               mov dword ptr [edx + 4], eax
// 004c6c9f  8b5004               mov edx, dword ptr [eax + 4]
// 004c6ca2  895104               mov dword ptr [ecx + 4], edx
// 004c6ca5  8b5718               mov edx, dword ptr [edi + 0x18]
// 004c6ca8  3b4204               cmp eax, dword ptr [edx + 4]
// 004c6cab  7505                 jne 0x4c6cb2
// 004c6cad  894a04               mov dword ptr [edx + 4], ecx
// 004c6cb0  eb0e                 jmp 0x4c6cc0
// 004c6cb2  8b5004               mov edx, dword ptr [eax + 4]
// 004c6cb5  3b02                 cmp eax, dword ptr [edx]
// 004c6cb7  7504                 jne 0x4c6cbd
// 004c6cb9  890a                 mov dword ptr [edx], ecx
// 004c6cbb  eb03                 jmp 0x4c6cc0
// 004c6cbd  894a08               mov dword ptr [edx + 8], ecx
// 004c6cc0  8901                 mov dword ptr [ecx], eax
// 004c6cc2  894804               mov dword ptr [eax + 4], ecx
// 004c6cc5  8b4e04               mov ecx, dword ptr [esi + 4]
// 004c6cc8  80791800             cmp byte ptr [ecx + 0x18], 0
// 004c6ccc  8d4604               lea eax, [esi + 4]
// 004c6ccf  0f841bffffff         je 0x4c6bf0
// 004c6cd5  8b5718               mov edx, dword ptr [edi + 0x18]
// 004c6cd8  8b4204               mov eax, dword ptr [edx + 4]
// 004c6cdb  885818               mov byte ptr [eax + 0x18], bl
// 004c6cde  8b442464             mov eax, dword ptr [esp + 0x64]
// 004c6ce2  8b0f                 mov ecx, dword ptr [edi]
// 004c6ce4  5e                   pop esi
// 004c6ce5  896804               mov dword ptr [eax + 4], ebp
// 004c6ce8  5d                   pop ebp
// 004c6ce9  8908                 mov dword ptr [eax], ecx
// 004c6ceb  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 004c6cef  5b                   pop ebx
// 004c6cf0  5f                   pop edi
// 004c6cf1  64890d00000000       mov dword ptr fs:[0], ecx
// 004c6cf8  83c450               add esp, 0x50
// 004c6cfb  c21000               ret 0x10
// standard library map_int<pod8> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod8>
struct E { int v[2]; };
#include <map>
template class std::map<int, E>;
