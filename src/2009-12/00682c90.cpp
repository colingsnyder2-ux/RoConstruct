// from server: 100% by auto
// roc 2009-12 00682c90  unit: RBX::VChangeHistoryService::?$FactoryProduct  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00682c90
//
// 00682c90  64a100000000         mov eax, dword ptr fs:[0]
// 00682c96  6aff                 push -1
// 00682c98  6812699500           push 0x956912
// 00682c9d  50                   push eax
// 00682c9e  64892500000000       mov dword ptr fs:[0], esp
// 00682ca5  83ec44               sub esp, 0x44
// 00682ca8  57                   push edi
// 00682ca9  8bf9                 mov edi, ecx
// 00682cab  817f1c54555515       cmp dword ptr [edi + 0x1c], 0x15555554
// 00682cb2  7259                 jb 0x682d0d
// 00682cb4  6800f59900           push 0x99f500
// 00682cb9  8d4c2408             lea ecx, [esp + 8]
// 00682cbd  ff15f4b69800         call dword ptr [0x98b6f4]
// 00682cc3  8d4c2420             lea ecx, [esp + 0x20]
// 00682cc7  c744245000000000     mov dword ptr [esp + 0x50], 0
// 00682ccf  ff1554b79800         call dword ptr [0x98b754]
// 00682cd5  8d442404             lea eax, [esp + 4]
// 00682cd9  50                   push eax
// 00682cda  8d4c2430             lea ecx, [esp + 0x30]
// 00682cde  c644245401           mov byte ptr [esp + 0x54], 1
// 00682ce3  c744242484f49900     mov dword ptr [esp + 0x24], 0x99f484
// 00682ceb  ff15f0b69800         call dword ptr [0x98b6f0]
// 00682cf1  68e4efa800           push 0xa8efe4
// 00682cf6  8d4c2424             lea ecx, [esp + 0x24]
// 00682cfa  51                   push ecx
// 00682cfb  c644245800           mov byte ptr [esp + 0x58], 0
// 00682d00  c744242890f49900     mov dword ptr [esp + 0x28], 0x99f490
// 00682d08  e86b1b1700           call 0x7f4878
// 00682d0d  8b542464             mov edx, dword ptr [esp + 0x64]
// 00682d11  8b4718               mov eax, dword ptr [edi + 0x18]
// 00682d14  53                   push ebx
// 00682d15  55                   push ebp
// 00682d16  56                   push esi
// 00682d17  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 00682d1b  6a00                 push 0
// 00682d1d  52                   push edx
// 00682d1e  50                   push eax
// 00682d1f  56                   push esi
// 00682d20  50                   push eax
// 00682d21  e84afeffff           call 0x682b70
// 00682d26  8be8                 mov ebp, eax
// 00682d28  8b4718               mov eax, dword ptr [edi + 0x18]
// 00682d2b  bb01000000           mov ebx, 1
// 00682d30  015f1c               add dword ptr [edi + 0x1c], ebx
// 00682d33  3bf0                 cmp esi, eax
// 00682d35  7510                 jne 0x682d47
// 00682d37  896804               mov dword ptr [eax + 4], ebp
// 00682d3a  8b4718               mov eax, dword ptr [edi + 0x18]
// 00682d3d  8928                 mov dword ptr [eax], ebp
// 00682d3f  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 00682d42  896908               mov dword ptr [ecx + 8], ebp
// 00682d45  eb22                 jmp 0x682d69
// 00682d47  807c246800           cmp byte ptr [esp + 0x68], 0
// 00682d4c  740d                 je 0x682d5b
// 00682d4e  892e                 mov dword ptr [esi], ebp
// 00682d50  8b4718               mov eax, dword ptr [edi + 0x18]
// 00682d53  3b30                 cmp esi, dword ptr [eax]
// 00682d55  7512                 jne 0x682d69
// 00682d57  8928                 mov dword ptr [eax], ebp
// 00682d59  eb0e                 jmp 0x682d69
// 00682d5b  896e08               mov dword ptr [esi + 8], ebp
// 00682d5e  8b4718               mov eax, dword ptr [edi + 0x18]
// 00682d61  3b7008               cmp esi, dword ptr [eax + 8]
// 00682d64  7503                 jne 0x682d69
// 00682d66  896808               mov dword ptr [eax + 8], ebp
// 00682d69  8b5504               mov edx, dword ptr [ebp + 4]
// 00682d6c  807a1800             cmp byte ptr [edx + 0x18], 0
// 00682d70  8d4504               lea eax, [ebp + 4]
// 00682d73  8bf5                 mov esi, ebp
// 00682d75  0f85ea000000         jne 0x682e65
// 00682d7b  eb03                 jmp 0x682d80
// 00682d7d  8d4900               lea ecx, [ecx]
// 00682d80  8b08                 mov ecx, dword ptr [eax]
// 00682d82  8b5104               mov edx, dword ptr [ecx + 4]
// 00682d85  3b0a                 cmp ecx, dword ptr [edx]
// 00682d87  7551                 jne 0x682dda
// 00682d89  8b5208               mov edx, dword ptr [edx + 8]
// 00682d8c  807a1800             cmp byte ptr [edx + 0x18], 0
// 00682d90  7519                 jne 0x682dab
// 00682d92  885918               mov byte ptr [ecx + 0x18], bl
// 00682d95  885a18               mov byte ptr [edx + 0x18], bl
// 00682d98  8b10                 mov edx, dword ptr [eax]
// 00682d9a  8b4a04               mov ecx, dword ptr [edx + 4]
// 00682d9d  c6411800             mov byte ptr [ecx + 0x18], 0
// 00682da1  8b10                 mov edx, dword ptr [eax]
// 00682da3  8b7204               mov esi, dword ptr [edx + 4]
// 00682da6  e9aa000000           jmp 0x682e55
// 00682dab  3b7108               cmp esi, dword ptr [ecx + 8]
// 00682dae  750a                 jne 0x682dba
// 00682db0  8bf1                 mov esi, ecx
// 00682db2  56                   push esi
// 00682db3  8bcf                 mov ecx, edi
// 00682db5  e85636feff           call 0x666410
// 00682dba  8b4604               mov eax, dword ptr [esi + 4]
// 00682dbd  885818               mov byte ptr [eax + 0x18], bl
// 00682dc0  8b4e04               mov ecx, dword ptr [esi + 4]
// 00682dc3  8b5104               mov edx, dword ptr [ecx + 4]
// 00682dc6  c6421800             mov byte ptr [edx + 0x18], 0
// 00682dca  8b4604               mov eax, dword ptr [esi + 4]
// 00682dcd  8b4804               mov ecx, dword ptr [eax + 4]
// 00682dd0  51                   push ecx
// 00682dd1  8bcf                 mov ecx, edi
// 00682dd3  e86800dbff           call 0x432e40
// 00682dd8  eb7b                 jmp 0x682e55
// 00682dda  8b12                 mov edx, dword ptr [edx]
// 00682ddc  807a1800             cmp byte ptr [edx + 0x18], 0
// 00682de0  7516                 jne 0x682df8
// 00682de2  885918               mov byte ptr [ecx + 0x18], bl
// 00682de5  885a18               mov byte ptr [edx + 0x18], bl
// 00682de8  8b10                 mov edx, dword ptr [eax]
// 00682dea  8b4a04               mov ecx, dword ptr [edx + 4]
// 00682ded  c6411800             mov byte ptr [ecx + 0x18], 0
// 00682df1  8b10                 mov edx, dword ptr [eax]
// 00682df3  8b7204               mov esi, dword ptr [edx + 4]
// 00682df6  eb5d                 jmp 0x682e55
// 00682df8  3b31                 cmp esi, dword ptr [ecx]
// 00682dfa  750a                 jne 0x682e06
// 00682dfc  8bf1                 mov esi, ecx
// 00682dfe  56                   push esi
// 00682dff  8bcf                 mov ecx, edi
// 00682e01  e83a00dbff           call 0x432e40
// 00682e06  8b4604               mov eax, dword ptr [esi + 4]
// 00682e09  885818               mov byte ptr [eax + 0x18], bl
// 00682e0c  8b4e04               mov ecx, dword ptr [esi + 4]
// 00682e0f  8b5104               mov edx, dword ptr [ecx + 4]
// 00682e12  c6421800             mov byte ptr [edx + 0x18], 0
// 00682e16  8b4604               mov eax, dword ptr [esi + 4]
// 00682e19  8b4004               mov eax, dword ptr [eax + 4]
// 00682e1c  8b4808               mov ecx, dword ptr [eax + 8]
// 00682e1f  8b11                 mov edx, dword ptr [ecx]
// 00682e21  895008               mov dword ptr [eax + 8], edx
// 00682e24  8b11                 mov edx, dword ptr [ecx]
// 00682e26  807a1900             cmp byte ptr [edx + 0x19], 0
// 00682e2a  7503                 jne 0x682e2f
// 00682e2c  894204               mov dword ptr [edx + 4], eax
// 00682e2f  8b5004               mov edx, dword ptr [eax + 4]
// 00682e32  895104               mov dword ptr [ecx + 4], edx
// 00682e35  8b5718               mov edx, dword ptr [edi + 0x18]
// 00682e38  3b4204               cmp eax, dword ptr [edx + 4]
// 00682e3b  7505                 jne 0x682e42
// 00682e3d  894a04               mov dword ptr [edx + 4], ecx
// 00682e40  eb0e                 jmp 0x682e50
// 00682e42  8b5004               mov edx, dword ptr [eax + 4]
// 00682e45  3b02                 cmp eax, dword ptr [edx]
// 00682e47  7504                 jne 0x682e4d
// 00682e49  890a                 mov dword ptr [edx], ecx
// 00682e4b  eb03                 jmp 0x682e50
// 00682e4d  894a08               mov dword ptr [edx + 8], ecx
// 00682e50  8901                 mov dword ptr [ecx], eax
// 00682e52  894804               mov dword ptr [eax + 4], ecx
// 00682e55  8b4e04               mov ecx, dword ptr [esi + 4]
// 00682e58  80791800             cmp byte ptr [ecx + 0x18], 0
// 00682e5c  8d4604               lea eax, [esi + 4]
// 00682e5f  0f841bffffff         je 0x682d80
// 00682e65  8b5718               mov edx, dword ptr [edi + 0x18]
// 00682e68  8b4204               mov eax, dword ptr [edx + 4]
// 00682e6b  885818               mov byte ptr [eax + 0x18], bl
// 00682e6e  8b442464             mov eax, dword ptr [esp + 0x64]
// 00682e72  8b0f                 mov ecx, dword ptr [edi]
// 00682e74  5e                   pop esi
// 00682e75  896804               mov dword ptr [eax + 4], ebp
// 00682e78  5d                   pop ebp
// 00682e79  8908                 mov dword ptr [eax], ecx
// 00682e7b  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 00682e7f  5b                   pop ebx
// 00682e80  5f                   pop edi
// 00682e81  64890d00000000       mov dword ptr fs:[0], ecx
// 00682e88  83c450               add esp, 0x50
// 00682e8b  c21000               ret 0x10
// standard library map_int<pod8> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod8>
struct E { int v[2]; };
#include <map>
template class std::map<int, E>;
