// from server: 100% by auto
// roc 2009-06 006f4d20  unit: RBX::HUMAN::GettingUp  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006f4d20
//
// 006f4d20  64a100000000         mov eax, dword ptr fs:[0]
// 006f4d26  6aff                 push -1
// 006f4d28  68b2db8500           push 0x85dbb2
// 006f4d2d  50                   push eax
// 006f4d2e  64892500000000       mov dword ptr fs:[0], esp
// 006f4d35  83ec44               sub esp, 0x44
// 006f4d38  57                   push edi
// 006f4d39  8bf9                 mov edi, ecx
// 006f4d3b  817f1cfeffff1f       cmp dword ptr [edi + 0x1c], 0x1ffffffe
// 006f4d42  7259                 jb 0x6f4d9d
// 006f4d44  68c0c98a00           push 0x8ac9c0
// 006f4d49  8d4c2408             lea ecx, [esp + 8]
// 006f4d4d  ff15b4e48900         call dword ptr [0x89e4b4]
// 006f4d53  8d4c2420             lea ecx, [esp + 0x20]
// 006f4d57  c744245000000000     mov dword ptr [esp + 0x50], 0
// 006f4d5f  ff15b8e98900         call dword ptr [0x89e9b8]
// 006f4d65  8d442404             lea eax, [esp + 4]
// 006f4d69  50                   push eax
// 006f4d6a  8d4c2430             lea ecx, [esp + 0x30]
// 006f4d6e  c644245401           mov byte ptr [esp + 0x54], 1
// 006f4d73  c744242444c98a00     mov dword ptr [esp + 0x24], 0x8ac944
// 006f4d7b  ff15b8e48900         call dword ptr [0x89e4b8]
// 006f4d81  6834929700           push 0x979234
// 006f4d86  8d4c2424             lea ecx, [esp + 0x24]
// 006f4d8a  51                   push ecx
// 006f4d8b  c644245800           mov byte ptr [esp + 0x58], 0
// 006f4d90  c744242850c98a00     mov dword ptr [esp + 0x28], 0x8ac950
// 006f4d98  e8ad4c0200           call 0x719a4a
// 006f4d9d  8b542464             mov edx, dword ptr [esp + 0x64]
// 006f4da1  8b4718               mov eax, dword ptr [edi + 0x18]
// 006f4da4  53                   push ebx
// 006f4da5  55                   push ebp
// 006f4da6  56                   push esi
// 006f4da7  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 006f4dab  6a00                 push 0
// 006f4dad  52                   push edx
// 006f4dae  50                   push eax
// 006f4daf  56                   push esi
// 006f4db0  50                   push eax
// 006f4db1  e83a40faff           call 0x698df0
// 006f4db6  8be8                 mov ebp, eax
// 006f4db8  8b4718               mov eax, dword ptr [edi + 0x18]
// 006f4dbb  bb01000000           mov ebx, 1
// 006f4dc0  015f1c               add dword ptr [edi + 0x1c], ebx
// 006f4dc3  3bf0                 cmp esi, eax
// 006f4dc5  7510                 jne 0x6f4dd7
// 006f4dc7  896804               mov dword ptr [eax + 4], ebp
// 006f4dca  8b4718               mov eax, dword ptr [edi + 0x18]
// 006f4dcd  8928                 mov dword ptr [eax], ebp
// 006f4dcf  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 006f4dd2  896908               mov dword ptr [ecx + 8], ebp
// 006f4dd5  eb22                 jmp 0x6f4df9
// 006f4dd7  807c246800           cmp byte ptr [esp + 0x68], 0
// 006f4ddc  740d                 je 0x6f4deb
// 006f4dde  892e                 mov dword ptr [esi], ebp
// 006f4de0  8b4718               mov eax, dword ptr [edi + 0x18]
// 006f4de3  3b30                 cmp esi, dword ptr [eax]
// 006f4de5  7512                 jne 0x6f4df9
// 006f4de7  8928                 mov dword ptr [eax], ebp
// 006f4de9  eb0e                 jmp 0x6f4df9
// 006f4deb  896e08               mov dword ptr [esi + 8], ebp
// 006f4dee  8b4718               mov eax, dword ptr [edi + 0x18]
// 006f4df1  3b7008               cmp esi, dword ptr [eax + 8]
// 006f4df4  7503                 jne 0x6f4df9
// 006f4df6  896808               mov dword ptr [eax + 8], ebp
// 006f4df9  8b5504               mov edx, dword ptr [ebp + 4]
// 006f4dfc  807a1400             cmp byte ptr [edx + 0x14], 0
// 006f4e00  8d4504               lea eax, [ebp + 4]
// 006f4e03  8bf5                 mov esi, ebp
// 006f4e05  0f85ea000000         jne 0x6f4ef5
// 006f4e0b  eb03                 jmp 0x6f4e10
// 006f4e0d  8d4900               lea ecx, [ecx]
// 006f4e10  8b08                 mov ecx, dword ptr [eax]
// 006f4e12  8b5104               mov edx, dword ptr [ecx + 4]
// 006f4e15  3b0a                 cmp ecx, dword ptr [edx]
// 006f4e17  7551                 jne 0x6f4e6a
// 006f4e19  8b5208               mov edx, dword ptr [edx + 8]
// 006f4e1c  807a1400             cmp byte ptr [edx + 0x14], 0
// 006f4e20  7519                 jne 0x6f4e3b
// 006f4e22  885914               mov byte ptr [ecx + 0x14], bl
// 006f4e25  885a14               mov byte ptr [edx + 0x14], bl
// 006f4e28  8b10                 mov edx, dword ptr [eax]
// 006f4e2a  8b4a04               mov ecx, dword ptr [edx + 4]
// 006f4e2d  c6411400             mov byte ptr [ecx + 0x14], 0
// 006f4e31  8b10                 mov edx, dword ptr [eax]
// 006f4e33  8b7204               mov esi, dword ptr [edx + 4]
// 006f4e36  e9aa000000           jmp 0x6f4ee5
// 006f4e3b  3b7108               cmp esi, dword ptr [ecx + 8]
// 006f4e3e  750a                 jne 0x6f4e4a
// 006f4e40  8bf1                 mov esi, ecx
// 006f4e42  56                   push esi
// 006f4e43  8bcf                 mov ecx, edi
// 006f4e45  e8467a0000           call 0x6fc890
// 006f4e4a  8b4604               mov eax, dword ptr [esi + 4]
// 006f4e4d  885814               mov byte ptr [eax + 0x14], bl
// 006f4e50  8b4e04               mov ecx, dword ptr [esi + 4]
// 006f4e53  8b5104               mov edx, dword ptr [ecx + 4]
// 006f4e56  c6421400             mov byte ptr [edx + 0x14], 0
// 006f4e5a  8b4604               mov eax, dword ptr [esi + 4]
// 006f4e5d  8b4804               mov ecx, dword ptr [eax + 4]
// 006f4e60  51                   push ecx
// 006f4e61  8bcf                 mov ecx, edi
// 006f4e63  e8a842efff           call 0x5e9110
// 006f4e68  eb7b                 jmp 0x6f4ee5
// 006f4e6a  8b12                 mov edx, dword ptr [edx]
// 006f4e6c  807a1400             cmp byte ptr [edx + 0x14], 0
// 006f4e70  7516                 jne 0x6f4e88
// 006f4e72  885914               mov byte ptr [ecx + 0x14], bl
// 006f4e75  885a14               mov byte ptr [edx + 0x14], bl
// 006f4e78  8b10                 mov edx, dword ptr [eax]
// 006f4e7a  8b4a04               mov ecx, dword ptr [edx + 4]
// 006f4e7d  c6411400             mov byte ptr [ecx + 0x14], 0
// 006f4e81  8b10                 mov edx, dword ptr [eax]
// 006f4e83  8b7204               mov esi, dword ptr [edx + 4]
// 006f4e86  eb5d                 jmp 0x6f4ee5
// 006f4e88  3b31                 cmp esi, dword ptr [ecx]
// 006f4e8a  750a                 jne 0x6f4e96
// 006f4e8c  8bf1                 mov esi, ecx
// 006f4e8e  56                   push esi
// 006f4e8f  8bcf                 mov ecx, edi
// 006f4e91  e87a42efff           call 0x5e9110
// 006f4e96  8b4604               mov eax, dword ptr [esi + 4]
// 006f4e99  885814               mov byte ptr [eax + 0x14], bl
// 006f4e9c  8b4e04               mov ecx, dword ptr [esi + 4]
// 006f4e9f  8b5104               mov edx, dword ptr [ecx + 4]
// 006f4ea2  c6421400             mov byte ptr [edx + 0x14], 0
// 006f4ea6  8b4604               mov eax, dword ptr [esi + 4]
// 006f4ea9  8b4004               mov eax, dword ptr [eax + 4]
// 006f4eac  8b4808               mov ecx, dword ptr [eax + 8]
// 006f4eaf  8b11                 mov edx, dword ptr [ecx]
// 006f4eb1  895008               mov dword ptr [eax + 8], edx
// 006f4eb4  8b11                 mov edx, dword ptr [ecx]
// 006f4eb6  807a1500             cmp byte ptr [edx + 0x15], 0
// 006f4eba  7503                 jne 0x6f4ebf
// 006f4ebc  894204               mov dword ptr [edx + 4], eax
// 006f4ebf  8b5004               mov edx, dword ptr [eax + 4]
// 006f4ec2  895104               mov dword ptr [ecx + 4], edx
// 006f4ec5  8b5718               mov edx, dword ptr [edi + 0x18]
// 006f4ec8  3b4204               cmp eax, dword ptr [edx + 4]
// 006f4ecb  7505                 jne 0x6f4ed2
// 006f4ecd  894a04               mov dword ptr [edx + 4], ecx
// 006f4ed0  eb0e                 jmp 0x6f4ee0
// 006f4ed2  8b5004               mov edx, dword ptr [eax + 4]
// 006f4ed5  3b02                 cmp eax, dword ptr [edx]
// 006f4ed7  7504                 jne 0x6f4edd
// 006f4ed9  890a                 mov dword ptr [edx], ecx
// 006f4edb  eb03                 jmp 0x6f4ee0
// 006f4edd  894a08               mov dword ptr [edx + 8], ecx
// 006f4ee0  8901                 mov dword ptr [ecx], eax
// 006f4ee2  894804               mov dword ptr [eax + 4], ecx
// 006f4ee5  8b4e04               mov ecx, dword ptr [esi + 4]
// 006f4ee8  80791400             cmp byte ptr [ecx + 0x14], 0
// 006f4eec  8d4604               lea eax, [esi + 4]
// 006f4eef  0f841bffffff         je 0x6f4e10
// 006f4ef5  8b5718               mov edx, dword ptr [edi + 0x18]
// 006f4ef8  8b4204               mov eax, dword ptr [edx + 4]
// 006f4efb  885814               mov byte ptr [eax + 0x14], bl
// 006f4efe  8b442464             mov eax, dword ptr [esp + 0x64]
// 006f4f02  8b0f                 mov ecx, dword ptr [edi]
// 006f4f04  5e                   pop esi
// 006f4f05  896804               mov dword ptr [eax + 4], ebp
// 006f4f08  5d                   pop ebp
// 006f4f09  8908                 mov dword ptr [eax], ecx
// 006f4f0b  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 006f4f0f  5b                   pop ebx
// 006f4f10  5f                   pop edi
// 006f4f11  64890d00000000       mov dword ptr fs:[0], ecx
// 006f4f18  83c450               add esp, 0x50
// 006f4f1b  c21000               ret 0x10
// standard library map_int<ptr> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HPAUT@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHPAUT@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HPAUT@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHPAUT@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHPAUT@@@2@@Z)

// stl: map_int<ptr>
struct T; typedef T* E;
#include <map>
template class std::map<int, E>;
