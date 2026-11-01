// from server: 100% by auto
// roc 2009-12 006f5db0  unit: G3D::VRay::?$TypedPropertyDescriptor  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006f5db0
//
// 006f5db0  64a100000000         mov eax, dword ptr fs:[0]
// 006f5db6  6aff                 push -1
// 006f5db8  6812699500           push 0x956912
// 006f5dbd  50                   push eax
// 006f5dbe  64892500000000       mov dword ptr fs:[0], esp
// 006f5dc5  83ec44               sub esp, 0x44
// 006f5dc8  57                   push edi
// 006f5dc9  8bf9                 mov edi, ecx
// 006f5dcb  817f1c54555515       cmp dword ptr [edi + 0x1c], 0x15555554
// 006f5dd2  7259                 jb 0x6f5e2d
// 006f5dd4  6800f59900           push 0x99f500
// 006f5dd9  8d4c2408             lea ecx, [esp + 8]
// 006f5ddd  ff15f4b69800         call dword ptr [0x98b6f4]
// 006f5de3  8d4c2420             lea ecx, [esp + 0x20]
// 006f5de7  c744245000000000     mov dword ptr [esp + 0x50], 0
// 006f5def  ff1554b79800         call dword ptr [0x98b754]
// 006f5df5  8d442404             lea eax, [esp + 4]
// 006f5df9  50                   push eax
// 006f5dfa  8d4c2430             lea ecx, [esp + 0x30]
// 006f5dfe  c644245401           mov byte ptr [esp + 0x54], 1
// 006f5e03  c744242484f49900     mov dword ptr [esp + 0x24], 0x99f484
// 006f5e0b  ff15f0b69800         call dword ptr [0x98b6f0]
// 006f5e11  68e4efa800           push 0xa8efe4
// 006f5e16  8d4c2424             lea ecx, [esp + 0x24]
// 006f5e1a  51                   push ecx
// 006f5e1b  c644245800           mov byte ptr [esp + 0x58], 0
// 006f5e20  c744242890f49900     mov dword ptr [esp + 0x28], 0x99f490
// 006f5e28  e84bea0f00           call 0x7f4878
// 006f5e2d  8b542464             mov edx, dword ptr [esp + 0x64]
// 006f5e31  8b4718               mov eax, dword ptr [edi + 0x18]
// 006f5e34  53                   push ebx
// 006f5e35  55                   push ebp
// 006f5e36  56                   push esi
// 006f5e37  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 006f5e3b  6a00                 push 0
// 006f5e3d  52                   push edx
// 006f5e3e  50                   push eax
// 006f5e3f  56                   push esi
// 006f5e40  50                   push eax
// 006f5e41  e8aadfd3ff           call 0x433df0
// 006f5e46  8be8                 mov ebp, eax
// 006f5e48  8b4718               mov eax, dword ptr [edi + 0x18]
// 006f5e4b  bb01000000           mov ebx, 1
// 006f5e50  015f1c               add dword ptr [edi + 0x1c], ebx
// 006f5e53  3bf0                 cmp esi, eax
// 006f5e55  7510                 jne 0x6f5e67
// 006f5e57  896804               mov dword ptr [eax + 4], ebp
// 006f5e5a  8b4718               mov eax, dword ptr [edi + 0x18]
// 006f5e5d  8928                 mov dword ptr [eax], ebp
// 006f5e5f  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 006f5e62  896908               mov dword ptr [ecx + 8], ebp
// 006f5e65  eb22                 jmp 0x6f5e89
// 006f5e67  807c246800           cmp byte ptr [esp + 0x68], 0
// 006f5e6c  740d                 je 0x6f5e7b
// 006f5e6e  892e                 mov dword ptr [esi], ebp
// 006f5e70  8b4718               mov eax, dword ptr [edi + 0x18]
// 006f5e73  3b30                 cmp esi, dword ptr [eax]
// 006f5e75  7512                 jne 0x6f5e89
// 006f5e77  8928                 mov dword ptr [eax], ebp
// 006f5e79  eb0e                 jmp 0x6f5e89
// 006f5e7b  896e08               mov dword ptr [esi + 8], ebp
// 006f5e7e  8b4718               mov eax, dword ptr [edi + 0x18]
// 006f5e81  3b7008               cmp esi, dword ptr [eax + 8]
// 006f5e84  7503                 jne 0x6f5e89
// 006f5e86  896808               mov dword ptr [eax + 8], ebp
// 006f5e89  8b5504               mov edx, dword ptr [ebp + 4]
// 006f5e8c  807a1800             cmp byte ptr [edx + 0x18], 0
// 006f5e90  8d4504               lea eax, [ebp + 4]
// 006f5e93  8bf5                 mov esi, ebp
// 006f5e95  0f85ea000000         jne 0x6f5f85
// 006f5e9b  eb03                 jmp 0x6f5ea0
// 006f5e9d  8d4900               lea ecx, [ecx]
// 006f5ea0  8b08                 mov ecx, dword ptr [eax]
// 006f5ea2  8b5104               mov edx, dword ptr [ecx + 4]
// 006f5ea5  3b0a                 cmp ecx, dword ptr [edx]
// 006f5ea7  7551                 jne 0x6f5efa
// 006f5ea9  8b5208               mov edx, dword ptr [edx + 8]
// 006f5eac  807a1800             cmp byte ptr [edx + 0x18], 0
// 006f5eb0  7519                 jne 0x6f5ecb
// 006f5eb2  885918               mov byte ptr [ecx + 0x18], bl
// 006f5eb5  885a18               mov byte ptr [edx + 0x18], bl
// 006f5eb8  8b10                 mov edx, dword ptr [eax]
// 006f5eba  8b4a04               mov ecx, dword ptr [edx + 4]
// 006f5ebd  c6411800             mov byte ptr [ecx + 0x18], 0
// 006f5ec1  8b10                 mov edx, dword ptr [eax]
// 006f5ec3  8b7204               mov esi, dword ptr [edx + 4]
// 006f5ec6  e9aa000000           jmp 0x6f5f75
// 006f5ecb  3b7108               cmp esi, dword ptr [ecx + 8]
// 006f5ece  750a                 jne 0x6f5eda
// 006f5ed0  8bf1                 mov esi, ecx
// 006f5ed2  56                   push esi
// 006f5ed3  8bcf                 mov ecx, edi
// 006f5ed5  e83605f7ff           call 0x666410
// 006f5eda  8b4604               mov eax, dword ptr [esi + 4]
// 006f5edd  885818               mov byte ptr [eax + 0x18], bl
// 006f5ee0  8b4e04               mov ecx, dword ptr [esi + 4]
// 006f5ee3  8b5104               mov edx, dword ptr [ecx + 4]
// 006f5ee6  c6421800             mov byte ptr [edx + 0x18], 0
// 006f5eea  8b4604               mov eax, dword ptr [esi + 4]
// 006f5eed  8b4804               mov ecx, dword ptr [eax + 4]
// 006f5ef0  51                   push ecx
// 006f5ef1  8bcf                 mov ecx, edi
// 006f5ef3  e848cfd3ff           call 0x432e40
// 006f5ef8  eb7b                 jmp 0x6f5f75
// 006f5efa  8b12                 mov edx, dword ptr [edx]
// 006f5efc  807a1800             cmp byte ptr [edx + 0x18], 0
// 006f5f00  7516                 jne 0x6f5f18
// 006f5f02  885918               mov byte ptr [ecx + 0x18], bl
// 006f5f05  885a18               mov byte ptr [edx + 0x18], bl
// 006f5f08  8b10                 mov edx, dword ptr [eax]
// 006f5f0a  8b4a04               mov ecx, dword ptr [edx + 4]
// 006f5f0d  c6411800             mov byte ptr [ecx + 0x18], 0
// 006f5f11  8b10                 mov edx, dword ptr [eax]
// 006f5f13  8b7204               mov esi, dword ptr [edx + 4]
// 006f5f16  eb5d                 jmp 0x6f5f75
// 006f5f18  3b31                 cmp esi, dword ptr [ecx]
// 006f5f1a  750a                 jne 0x6f5f26
// 006f5f1c  8bf1                 mov esi, ecx
// 006f5f1e  56                   push esi
// 006f5f1f  8bcf                 mov ecx, edi
// 006f5f21  e81acfd3ff           call 0x432e40
// 006f5f26  8b4604               mov eax, dword ptr [esi + 4]
// 006f5f29  885818               mov byte ptr [eax + 0x18], bl
// 006f5f2c  8b4e04               mov ecx, dword ptr [esi + 4]
// 006f5f2f  8b5104               mov edx, dword ptr [ecx + 4]
// 006f5f32  c6421800             mov byte ptr [edx + 0x18], 0
// 006f5f36  8b4604               mov eax, dword ptr [esi + 4]
// 006f5f39  8b4004               mov eax, dword ptr [eax + 4]
// 006f5f3c  8b4808               mov ecx, dword ptr [eax + 8]
// 006f5f3f  8b11                 mov edx, dword ptr [ecx]
// 006f5f41  895008               mov dword ptr [eax + 8], edx
// 006f5f44  8b11                 mov edx, dword ptr [ecx]
// 006f5f46  807a1900             cmp byte ptr [edx + 0x19], 0
// 006f5f4a  7503                 jne 0x6f5f4f
// 006f5f4c  894204               mov dword ptr [edx + 4], eax
// 006f5f4f  8b5004               mov edx, dword ptr [eax + 4]
// 006f5f52  895104               mov dword ptr [ecx + 4], edx
// 006f5f55  8b5718               mov edx, dword ptr [edi + 0x18]
// 006f5f58  3b4204               cmp eax, dword ptr [edx + 4]
// 006f5f5b  7505                 jne 0x6f5f62
// 006f5f5d  894a04               mov dword ptr [edx + 4], ecx
// 006f5f60  eb0e                 jmp 0x6f5f70
// 006f5f62  8b5004               mov edx, dword ptr [eax + 4]
// 006f5f65  3b02                 cmp eax, dword ptr [edx]
// 006f5f67  7504                 jne 0x6f5f6d
// 006f5f69  890a                 mov dword ptr [edx], ecx
// 006f5f6b  eb03                 jmp 0x6f5f70
// 006f5f6d  894a08               mov dword ptr [edx + 8], ecx
// 006f5f70  8901                 mov dword ptr [ecx], eax
// 006f5f72  894804               mov dword ptr [eax + 4], ecx
// 006f5f75  8b4e04               mov ecx, dword ptr [esi + 4]
// 006f5f78  80791800             cmp byte ptr [ecx + 0x18], 0
// 006f5f7c  8d4604               lea eax, [esi + 4]
// 006f5f7f  0f841bffffff         je 0x6f5ea0
// 006f5f85  8b5718               mov edx, dword ptr [edi + 0x18]
// 006f5f88  8b4204               mov eax, dword ptr [edx + 4]
// 006f5f8b  885818               mov byte ptr [eax + 0x18], bl
// 006f5f8e  8b442464             mov eax, dword ptr [esp + 0x64]
// 006f5f92  8b0f                 mov ecx, dword ptr [edi]
// 006f5f94  5e                   pop esi
// 006f5f95  896804               mov dword ptr [eax + 4], ebp
// 006f5f98  5d                   pop ebp
// 006f5f99  8908                 mov dword ptr [eax], ecx
// 006f5f9b  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 006f5f9f  5b                   pop ebx
// 006f5fa0  5f                   pop edi
// 006f5fa1  64890d00000000       mov dword ptr fs:[0], ecx
// 006f5fa8  83c450               add esp, 0x50
// 006f5fab  c21000               ret 0x10
// standard library map_int<pod8> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod8>
struct E { int v[2]; };
#include <map>
template class std::map<int, E>;
