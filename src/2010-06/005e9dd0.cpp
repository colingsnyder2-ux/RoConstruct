// from server: 100% by auto
// roc 2010-06 005e9dd0  unit: RBX::VChangeHistoryService::?$FactoryProduct  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005e9dd0
//
// 005e9dd0  64a100000000         mov eax, dword ptr fs:[0]
// 005e9dd6  6aff                 push -1
// 005e9dd8  68e22f9a00           push 0x9a2fe2
// 005e9ddd  50                   push eax
// 005e9dde  64892500000000       mov dword ptr fs:[0], esp
// 005e9de5  83ec44               sub esp, 0x44
// 005e9de8  57                   push edi
// 005e9de9  8bf9                 mov edi, ecx
// 005e9deb  817f1c54555515       cmp dword ptr [edi + 0x1c], 0x15555554
// 005e9df2  7259                 jb 0x5e9e4d
// 005e9df4  68a800a000           push 0xa000a8
// 005e9df9  8d4c2408             lea ecx, [esp + 8]
// 005e9dfd  ff1510a49e00         call dword ptr [0x9ea410]
// 005e9e03  8d4c2420             lea ecx, [esp + 0x20]
// 005e9e07  c744245000000000     mov dword ptr [esp + 0x50], 0
// 005e9e0f  ff1518a99e00         call dword ptr [0x9ea918]
// 005e9e15  8d442404             lea eax, [esp + 4]
// 005e9e19  50                   push eax
// 005e9e1a  8d4c2430             lea ecx, [esp + 0x30]
// 005e9e1e  c644245401           mov byte ptr [esp + 0x54], 1
// 005e9e23  c74424242c00a000     mov dword ptr [esp + 0x24], 0xa0002c
// 005e9e2b  ff150ca49e00         call dword ptr [0x9ea40c]
// 005e9e31  68601bb000           push 0xb01b60
// 005e9e36  8d4c2424             lea ecx, [esp + 0x24]
// 005e9e3a  51                   push ecx
// 005e9e3b  c644245800           mov byte ptr [esp + 0x58], 0
// 005e9e40  c74424283800a000     mov dword ptr [esp + 0x28], 0xa00038
// 005e9e48  e865eb1b00           call 0x7a89b2
// 005e9e4d  8b542464             mov edx, dword ptr [esp + 0x64]
// 005e9e51  8b4718               mov eax, dword ptr [edi + 0x18]
// 005e9e54  53                   push ebx
// 005e9e55  55                   push ebp
// 005e9e56  56                   push esi
// 005e9e57  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 005e9e5b  6a00                 push 0
// 005e9e5d  52                   push edx
// 005e9e5e  50                   push eax
// 005e9e5f  56                   push esi
// 005e9e60  50                   push eax
// 005e9e61  e84afeffff           call 0x5e9cb0
// 005e9e66  8be8                 mov ebp, eax
// 005e9e68  8b4718               mov eax, dword ptr [edi + 0x18]
// 005e9e6b  bb01000000           mov ebx, 1
// 005e9e70  015f1c               add dword ptr [edi + 0x1c], ebx
// 005e9e73  3bf0                 cmp esi, eax
// 005e9e75  7510                 jne 0x5e9e87
// 005e9e77  896804               mov dword ptr [eax + 4], ebp
// 005e9e7a  8b4718               mov eax, dword ptr [edi + 0x18]
// 005e9e7d  8928                 mov dword ptr [eax], ebp
// 005e9e7f  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 005e9e82  896908               mov dword ptr [ecx + 8], ebp
// 005e9e85  eb22                 jmp 0x5e9ea9
// 005e9e87  807c246800           cmp byte ptr [esp + 0x68], 0
// 005e9e8c  740d                 je 0x5e9e9b
// 005e9e8e  892e                 mov dword ptr [esi], ebp
// 005e9e90  8b4718               mov eax, dword ptr [edi + 0x18]
// 005e9e93  3b30                 cmp esi, dword ptr [eax]
// 005e9e95  7512                 jne 0x5e9ea9
// 005e9e97  8928                 mov dword ptr [eax], ebp
// 005e9e99  eb0e                 jmp 0x5e9ea9
// 005e9e9b  896e08               mov dword ptr [esi + 8], ebp
// 005e9e9e  8b4718               mov eax, dword ptr [edi + 0x18]
// 005e9ea1  3b7008               cmp esi, dword ptr [eax + 8]
// 005e9ea4  7503                 jne 0x5e9ea9
// 005e9ea6  896808               mov dword ptr [eax + 8], ebp
// 005e9ea9  8b5504               mov edx, dword ptr [ebp + 4]
// 005e9eac  807a1800             cmp byte ptr [edx + 0x18], 0
// 005e9eb0  8d4504               lea eax, [ebp + 4]
// 005e9eb3  8bf5                 mov esi, ebp
// 005e9eb5  0f85ea000000         jne 0x5e9fa5
// 005e9ebb  eb03                 jmp 0x5e9ec0
// 005e9ebd  8d4900               lea ecx, [ecx]
// 005e9ec0  8b08                 mov ecx, dword ptr [eax]
// 005e9ec2  8b5104               mov edx, dword ptr [ecx + 4]
// 005e9ec5  3b0a                 cmp ecx, dword ptr [edx]
// 005e9ec7  7551                 jne 0x5e9f1a
// 005e9ec9  8b5208               mov edx, dword ptr [edx + 8]
// 005e9ecc  807a1800             cmp byte ptr [edx + 0x18], 0
// 005e9ed0  7519                 jne 0x5e9eeb
// 005e9ed2  885918               mov byte ptr [ecx + 0x18], bl
// 005e9ed5  885a18               mov byte ptr [edx + 0x18], bl
// 005e9ed8  8b10                 mov edx, dword ptr [eax]
// 005e9eda  8b4a04               mov ecx, dword ptr [edx + 4]
// 005e9edd  c6411800             mov byte ptr [ecx + 0x18], 0
// 005e9ee1  8b10                 mov edx, dword ptr [eax]
// 005e9ee3  8b7204               mov esi, dword ptr [edx + 4]
// 005e9ee6  e9aa000000           jmp 0x5e9f95
// 005e9eeb  3b7108               cmp esi, dword ptr [ecx + 8]
// 005e9eee  750a                 jne 0x5e9efa
// 005e9ef0  8bf1                 mov esi, ecx
// 005e9ef2  56                   push esi
// 005e9ef3  8bcf                 mov ecx, edi
// 005e9ef5  e8e6c9efff           call 0x4e68e0
// 005e9efa  8b4604               mov eax, dword ptr [esi + 4]
// 005e9efd  885818               mov byte ptr [eax + 0x18], bl
// 005e9f00  8b4e04               mov ecx, dword ptr [esi + 4]
// 005e9f03  8b5104               mov edx, dword ptr [ecx + 4]
// 005e9f06  c6421800             mov byte ptr [edx + 0x18], 0
// 005e9f0a  8b4604               mov eax, dword ptr [esi + 4]
// 005e9f0d  8b4804               mov ecx, dword ptr [eax + 4]
// 005e9f10  51                   push ecx
// 005e9f11  8bcf                 mov ecx, edi
// 005e9f13  e898860000           call 0x5f25b0
// 005e9f18  eb7b                 jmp 0x5e9f95
// 005e9f1a  8b12                 mov edx, dword ptr [edx]
// 005e9f1c  807a1800             cmp byte ptr [edx + 0x18], 0
// 005e9f20  7516                 jne 0x5e9f38
// 005e9f22  885918               mov byte ptr [ecx + 0x18], bl
// 005e9f25  885a18               mov byte ptr [edx + 0x18], bl
// 005e9f28  8b10                 mov edx, dword ptr [eax]
// 005e9f2a  8b4a04               mov ecx, dword ptr [edx + 4]
// 005e9f2d  c6411800             mov byte ptr [ecx + 0x18], 0
// 005e9f31  8b10                 mov edx, dword ptr [eax]
// 005e9f33  8b7204               mov esi, dword ptr [edx + 4]
// 005e9f36  eb5d                 jmp 0x5e9f95
// 005e9f38  3b31                 cmp esi, dword ptr [ecx]
// 005e9f3a  750a                 jne 0x5e9f46
// 005e9f3c  8bf1                 mov esi, ecx
// 005e9f3e  56                   push esi
// 005e9f3f  8bcf                 mov ecx, edi
// 005e9f41  e86a860000           call 0x5f25b0
// 005e9f46  8b4604               mov eax, dword ptr [esi + 4]
// 005e9f49  885818               mov byte ptr [eax + 0x18], bl
// 005e9f4c  8b4e04               mov ecx, dword ptr [esi + 4]
// 005e9f4f  8b5104               mov edx, dword ptr [ecx + 4]
// 005e9f52  c6421800             mov byte ptr [edx + 0x18], 0
// 005e9f56  8b4604               mov eax, dword ptr [esi + 4]
// 005e9f59  8b4004               mov eax, dword ptr [eax + 4]
// 005e9f5c  8b4808               mov ecx, dword ptr [eax + 8]
// 005e9f5f  8b11                 mov edx, dword ptr [ecx]
// 005e9f61  895008               mov dword ptr [eax + 8], edx
// 005e9f64  8b11                 mov edx, dword ptr [ecx]
// 005e9f66  807a1900             cmp byte ptr [edx + 0x19], 0
// 005e9f6a  7503                 jne 0x5e9f6f
// 005e9f6c  894204               mov dword ptr [edx + 4], eax
// 005e9f6f  8b5004               mov edx, dword ptr [eax + 4]
// 005e9f72  895104               mov dword ptr [ecx + 4], edx
// 005e9f75  8b5718               mov edx, dword ptr [edi + 0x18]
// 005e9f78  3b4204               cmp eax, dword ptr [edx + 4]
// 005e9f7b  7505                 jne 0x5e9f82
// 005e9f7d  894a04               mov dword ptr [edx + 4], ecx
// 005e9f80  eb0e                 jmp 0x5e9f90
// 005e9f82  8b5004               mov edx, dword ptr [eax + 4]
// 005e9f85  3b02                 cmp eax, dword ptr [edx]
// 005e9f87  7504                 jne 0x5e9f8d
// 005e9f89  890a                 mov dword ptr [edx], ecx
// 005e9f8b  eb03                 jmp 0x5e9f90
// 005e9f8d  894a08               mov dword ptr [edx + 8], ecx
// 005e9f90  8901                 mov dword ptr [ecx], eax
// 005e9f92  894804               mov dword ptr [eax + 4], ecx
// 005e9f95  8b4e04               mov ecx, dword ptr [esi + 4]
// 005e9f98  80791800             cmp byte ptr [ecx + 0x18], 0
// 005e9f9c  8d4604               lea eax, [esi + 4]
// 005e9f9f  0f841bffffff         je 0x5e9ec0
// 005e9fa5  8b5718               mov edx, dword ptr [edi + 0x18]
// 005e9fa8  8b4204               mov eax, dword ptr [edx + 4]
// 005e9fab  885818               mov byte ptr [eax + 0x18], bl
// 005e9fae  8b442464             mov eax, dword ptr [esp + 0x64]
// 005e9fb2  8b0f                 mov ecx, dword ptr [edi]
// 005e9fb4  5e                   pop esi
// 005e9fb5  896804               mov dword ptr [eax + 4], ebp
// 005e9fb8  5d                   pop ebp
// 005e9fb9  8908                 mov dword ptr [eax], ecx
// 005e9fbb  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 005e9fbf  5b                   pop ebx
// 005e9fc0  5f                   pop edi
// 005e9fc1  64890d00000000       mov dword ptr fs:[0], ecx
// 005e9fc8  83c450               add esp, 0x50
// 005e9fcb  c21000               ret 0x10
// standard library map_int<pod8> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod8>
struct E { int v[2]; };
#include <map>
template class std::map<int, E>;
