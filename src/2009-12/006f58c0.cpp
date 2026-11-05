// from server: 100% by auto
// roc 2009-12 006f58c0  unit: G3D::VRay::?$TypedPropertyDescriptor  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006f58c0
//
// 006f58c0  64a100000000         mov eax, dword ptr fs:[0]
// 006f58c6  6aff                 push -1
// 006f58c8  6812699500           push 0x956912
// 006f58cd  50                   push eax
// 006f58ce  64892500000000       mov dword ptr fs:[0], esp
// 006f58d5  83ec44               sub esp, 0x44
// 006f58d8  57                   push edi
// 006f58d9  8bf9                 mov edi, ecx
// 006f58db  817f1cfeffff1f       cmp dword ptr [edi + 0x1c], 0x1ffffffe
// 006f58e2  7259                 jb 0x6f593d
// 006f58e4  6800f59900           push 0x99f500
// 006f58e9  8d4c2408             lea ecx, [esp + 8]
// 006f58ed  ff15f4b69800         call dword ptr [0x98b6f4]
// 006f58f3  8d4c2420             lea ecx, [esp + 0x20]
// 006f58f7  c744245000000000     mov dword ptr [esp + 0x50], 0
// 006f58ff  ff1554b79800         call dword ptr [0x98b754]
// 006f5905  8d442404             lea eax, [esp + 4]
// 006f5909  50                   push eax
// 006f590a  8d4c2430             lea ecx, [esp + 0x30]
// 006f590e  c644245401           mov byte ptr [esp + 0x54], 1
// 006f5913  c744242484f49900     mov dword ptr [esp + 0x24], 0x99f484
// 006f591b  ff15f0b69800         call dword ptr [0x98b6f0]
// 006f5921  68e4efa800           push 0xa8efe4
// 006f5926  8d4c2424             lea ecx, [esp + 0x24]
// 006f592a  51                   push ecx
// 006f592b  c644245800           mov byte ptr [esp + 0x58], 0
// 006f5930  c744242890f49900     mov dword ptr [esp + 0x28], 0x99f490
// 006f5938  e83bef0f00           call 0x7f4878
// 006f593d  8b542464             mov edx, dword ptr [esp + 0x64]
// 006f5941  8b4718               mov eax, dword ptr [edi + 0x18]
// 006f5944  53                   push ebx
// 006f5945  55                   push ebp
// 006f5946  56                   push esi
// 006f5947  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 006f594b  6a00                 push 0
// 006f594d  52                   push edx
// 006f594e  50                   push eax
// 006f594f  56                   push esi
// 006f5950  50                   push eax
// 006f5951  e84af4ffff           call 0x6f4da0
// 006f5956  8be8                 mov ebp, eax
// 006f5958  8b4718               mov eax, dword ptr [edi + 0x18]
// 006f595b  bb01000000           mov ebx, 1
// 006f5960  015f1c               add dword ptr [edi + 0x1c], ebx
// 006f5963  3bf0                 cmp esi, eax
// 006f5965  7510                 jne 0x6f5977
// 006f5967  896804               mov dword ptr [eax + 4], ebp
// 006f596a  8b4718               mov eax, dword ptr [edi + 0x18]
// 006f596d  8928                 mov dword ptr [eax], ebp
// 006f596f  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 006f5972  896908               mov dword ptr [ecx + 8], ebp
// 006f5975  eb22                 jmp 0x6f5999
// 006f5977  807c246800           cmp byte ptr [esp + 0x68], 0
// 006f597c  740d                 je 0x6f598b
// 006f597e  892e                 mov dword ptr [esi], ebp
// 006f5980  8b4718               mov eax, dword ptr [edi + 0x18]
// 006f5983  3b30                 cmp esi, dword ptr [eax]
// 006f5985  7512                 jne 0x6f5999
// 006f5987  8928                 mov dword ptr [eax], ebp
// 006f5989  eb0e                 jmp 0x6f5999
// 006f598b  896e08               mov dword ptr [esi + 8], ebp
// 006f598e  8b4718               mov eax, dword ptr [edi + 0x18]
// 006f5991  3b7008               cmp esi, dword ptr [eax + 8]
// 006f5994  7503                 jne 0x6f5999
// 006f5996  896808               mov dword ptr [eax + 8], ebp
// 006f5999  8b5504               mov edx, dword ptr [ebp + 4]
// 006f599c  807a1400             cmp byte ptr [edx + 0x14], 0
// 006f59a0  8d4504               lea eax, [ebp + 4]
// 006f59a3  8bf5                 mov esi, ebp
// 006f59a5  0f85ea000000         jne 0x6f5a95
// 006f59ab  eb03                 jmp 0x6f59b0
// 006f59ad  8d4900               lea ecx, [ecx]
// 006f59b0  8b08                 mov ecx, dword ptr [eax]
// 006f59b2  8b5104               mov edx, dword ptr [ecx + 4]
// 006f59b5  3b0a                 cmp ecx, dword ptr [edx]
// 006f59b7  7551                 jne 0x6f5a0a
// 006f59b9  8b5208               mov edx, dword ptr [edx + 8]
// 006f59bc  807a1400             cmp byte ptr [edx + 0x14], 0
// 006f59c0  7519                 jne 0x6f59db
// 006f59c2  885914               mov byte ptr [ecx + 0x14], bl
// 006f59c5  885a14               mov byte ptr [edx + 0x14], bl
// 006f59c8  8b10                 mov edx, dword ptr [eax]
// 006f59ca  8b4a04               mov ecx, dword ptr [edx + 4]
// 006f59cd  c6411400             mov byte ptr [ecx + 0x14], 0
// 006f59d1  8b10                 mov edx, dword ptr [eax]
// 006f59d3  8b7204               mov esi, dword ptr [edx + 4]
// 006f59d6  e9aa000000           jmp 0x6f5a85
// 006f59db  3b7108               cmp esi, dword ptr [ecx + 8]
// 006f59de  750a                 jne 0x6f59ea
// 006f59e0  8bf1                 mov esi, ecx
// 006f59e2  56                   push esi
// 006f59e3  8bcf                 mov ecx, edi
// 006f59e5  e8e6070f00           call 0x7e61d0
// 006f59ea  8b4604               mov eax, dword ptr [esi + 4]
// 006f59ed  885814               mov byte ptr [eax + 0x14], bl
// 006f59f0  8b4e04               mov ecx, dword ptr [esi + 4]
// 006f59f3  8b5104               mov edx, dword ptr [ecx + 4]
// 006f59f6  c6421400             mov byte ptr [edx + 0x14], 0
// 006f59fa  8b4604               mov eax, dword ptr [esi + 4]
// 006f59fd  8b4804               mov ecx, dword ptr [eax + 4]
// 006f5a00  51                   push ecx
// 006f5a01  8bcf                 mov ecx, edi
// 006f5a03  e868f3d5ff           call 0x454d70
// 006f5a08  eb7b                 jmp 0x6f5a85
// 006f5a0a  8b12                 mov edx, dword ptr [edx]
// 006f5a0c  807a1400             cmp byte ptr [edx + 0x14], 0
// 006f5a10  7516                 jne 0x6f5a28
// 006f5a12  885914               mov byte ptr [ecx + 0x14], bl
// 006f5a15  885a14               mov byte ptr [edx + 0x14], bl
// 006f5a18  8b10                 mov edx, dword ptr [eax]
// 006f5a1a  8b4a04               mov ecx, dword ptr [edx + 4]
// 006f5a1d  c6411400             mov byte ptr [ecx + 0x14], 0
// 006f5a21  8b10                 mov edx, dword ptr [eax]
// 006f5a23  8b7204               mov esi, dword ptr [edx + 4]
// 006f5a26  eb5d                 jmp 0x6f5a85
// 006f5a28  3b31                 cmp esi, dword ptr [ecx]
// 006f5a2a  750a                 jne 0x6f5a36
// 006f5a2c  8bf1                 mov esi, ecx
// 006f5a2e  56                   push esi
// 006f5a2f  8bcf                 mov ecx, edi
// 006f5a31  e83af3d5ff           call 0x454d70
// 006f5a36  8b4604               mov eax, dword ptr [esi + 4]
// 006f5a39  885814               mov byte ptr [eax + 0x14], bl
// 006f5a3c  8b4e04               mov ecx, dword ptr [esi + 4]
// 006f5a3f  8b5104               mov edx, dword ptr [ecx + 4]
// 006f5a42  c6421400             mov byte ptr [edx + 0x14], 0
// 006f5a46  8b4604               mov eax, dword ptr [esi + 4]
// 006f5a49  8b4004               mov eax, dword ptr [eax + 4]
// 006f5a4c  8b4808               mov ecx, dword ptr [eax + 8]
// 006f5a4f  8b11                 mov edx, dword ptr [ecx]
// 006f5a51  895008               mov dword ptr [eax + 8], edx
// 006f5a54  8b11                 mov edx, dword ptr [ecx]
// 006f5a56  807a1500             cmp byte ptr [edx + 0x15], 0
// 006f5a5a  7503                 jne 0x6f5a5f
// 006f5a5c  894204               mov dword ptr [edx + 4], eax
// 006f5a5f  8b5004               mov edx, dword ptr [eax + 4]
// 006f5a62  895104               mov dword ptr [ecx + 4], edx
// 006f5a65  8b5718               mov edx, dword ptr [edi + 0x18]
// 006f5a68  3b4204               cmp eax, dword ptr [edx + 4]
// 006f5a6b  7505                 jne 0x6f5a72
// 006f5a6d  894a04               mov dword ptr [edx + 4], ecx
// 006f5a70  eb0e                 jmp 0x6f5a80
// 006f5a72  8b5004               mov edx, dword ptr [eax + 4]
// 006f5a75  3b02                 cmp eax, dword ptr [edx]
// 006f5a77  7504                 jne 0x6f5a7d
// 006f5a79  890a                 mov dword ptr [edx], ecx
// 006f5a7b  eb03                 jmp 0x6f5a80
// 006f5a7d  894a08               mov dword ptr [edx + 8], ecx
// 006f5a80  8901                 mov dword ptr [ecx], eax
// 006f5a82  894804               mov dword ptr [eax + 4], ecx
// 006f5a85  8b4e04               mov ecx, dword ptr [esi + 4]
// 006f5a88  80791400             cmp byte ptr [ecx + 0x14], 0
// 006f5a8c  8d4604               lea eax, [esi + 4]
// 006f5a8f  0f841bffffff         je 0x6f59b0
// 006f5a95  8b5718               mov edx, dword ptr [edi + 0x18]
// 006f5a98  8b4204               mov eax, dword ptr [edx + 4]
// 006f5a9b  885814               mov byte ptr [eax + 0x14], bl
// 006f5a9e  8b442464             mov eax, dword ptr [esp + 0x64]
// 006f5aa2  8b0f                 mov ecx, dword ptr [edi]
// 006f5aa4  5e                   pop esi
// 006f5aa5  896804               mov dword ptr [eax + 4], ebp
// 006f5aa8  5d                   pop ebp
// 006f5aa9  8908                 mov dword ptr [eax], ecx
// 006f5aab  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 006f5aaf  5b                   pop ebx
// 006f5ab0  5f                   pop edi
// 006f5ab1  64890d00000000       mov dword ptr fs:[0], ecx
// 006f5ab8  83c450               add esp, 0x50
// 006f5abb  c21000               ret 0x10
// standard library map_int<ptr> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HPAUT@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHPAUT@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HPAUT@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHPAUT@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHPAUT@@@2@@Z)

// stl: map_int<ptr>
struct T; typedef T* E;
#include <map>
template class std::map<int, E>;
