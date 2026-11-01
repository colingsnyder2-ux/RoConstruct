// from server: 100% by auto
// roc 2007-03 004d0e50  unit: seg_004d0000  size: 508 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 004d0e50
//
// 004d0e50  64a100000000         mov eax, dword ptr fs:[0]
// 004d0e56  6aff                 push -1
// 004d0e58  68926f7500           push 0x756f92
// 004d0e5d  50                   push eax
// 004d0e5e  64892500000000       mov dword ptr fs:[0], esp
// 004d0e65  83ec44               sub esp, 0x44
// 004d0e68  57                   push edi
// 004d0e69  8bf9                 mov edi, ecx
// 004d0e6b  817f0865666606       cmp dword ptr [edi + 8], 0x6666665
// 004d0e72  7259                 jb 0x4d0ecd
// 004d0e74  68903f7800           push 0x783f90
// 004d0e79  8d4c2408             lea ecx, [esp + 8]
// 004d0e7d  ff1578e77700         call dword ptr [0x77e778]
// 004d0e83  8d4c2420             lea ecx, [esp + 0x20]
// 004d0e87  c744245000000000     mov dword ptr [esp + 0x50], 0
// 004d0e8f  ff1560e97700         call dword ptr [0x77e960]
// 004d0e95  8d442404             lea eax, [esp + 4]
// 004d0e99  50                   push eax
// 004d0e9a  8d4c2430             lea ecx, [esp + 0x30]
// 004d0e9e  c644245401           mov byte ptr [esp + 0x54], 1
// 004d0ea3  c7442424383e7800     mov dword ptr [esp + 0x24], 0x783e38
// 004d0eab  ff157ce77700         call dword ptr [0x77e77c]
// 004d0eb1  6870f78300           push 0x83f770
// 004d0eb6  8d4c2424             lea ecx, [esp + 0x24]
// 004d0eba  51                   push ecx
// 004d0ebb  c644245800           mov byte ptr [esp + 0x58], 0
// 004d0ec0  c7442428443e7800     mov dword ptr [esp + 0x28], 0x783e44
// 004d0ec8  e861e11400           call 0x61f02e
// 004d0ecd  8b542464             mov edx, dword ptr [esp + 0x64]
// 004d0ed1  8b4704               mov eax, dword ptr [edi + 4]
// 004d0ed4  53                   push ebx
// 004d0ed5  55                   push ebp
// 004d0ed6  56                   push esi
// 004d0ed7  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 004d0edb  6a00                 push 0
// 004d0edd  52                   push edx
// 004d0ede  50                   push eax
// 004d0edf  56                   push esi
// 004d0ee0  50                   push eax
// 004d0ee1  e8dafeffff           call 0x4d0dc0
// 004d0ee6  8be8                 mov ebp, eax
// 004d0ee8  8b4704               mov eax, dword ptr [edi + 4]
// 004d0eeb  bb01000000           mov ebx, 1
// 004d0ef0  015f08               add dword ptr [edi + 8], ebx
// 004d0ef3  3bf0                 cmp esi, eax
// 004d0ef5  7510                 jne 0x4d0f07
// 004d0ef7  896804               mov dword ptr [eax + 4], ebp
// 004d0efa  8b4704               mov eax, dword ptr [edi + 4]
// 004d0efd  8928                 mov dword ptr [eax], ebp
// 004d0eff  8b4f04               mov ecx, dword ptr [edi + 4]
// 004d0f02  896908               mov dword ptr [ecx + 8], ebp
// 004d0f05  eb22                 jmp 0x4d0f29
// 004d0f07  807c246800           cmp byte ptr [esp + 0x68], 0
// 004d0f0c  740d                 je 0x4d0f1b
// 004d0f0e  892e                 mov dword ptr [esi], ebp
// 004d0f10  8b4704               mov eax, dword ptr [edi + 4]
// 004d0f13  3b30                 cmp esi, dword ptr [eax]
// 004d0f15  7512                 jne 0x4d0f29
// 004d0f17  8928                 mov dword ptr [eax], ebp
// 004d0f19  eb0e                 jmp 0x4d0f29
// 004d0f1b  896e08               mov dword ptr [esi + 8], ebp
// 004d0f1e  8b4704               mov eax, dword ptr [edi + 4]
// 004d0f21  3b7008               cmp esi, dword ptr [eax + 8]
// 004d0f24  7503                 jne 0x4d0f29
// 004d0f26  896808               mov dword ptr [eax + 8], ebp
// 004d0f29  8b5504               mov edx, dword ptr [ebp + 4]
// 004d0f2c  807a3400             cmp byte ptr [edx + 0x34], 0
// 004d0f30  8d4504               lea eax, [ebp + 4]
// 004d0f33  8bf5                 mov esi, ebp
// 004d0f35  0f85ea000000         jne 0x4d1025
// 004d0f3b  eb03                 jmp 0x4d0f40
// 004d0f3d  8d4900               lea ecx, [ecx]
// 004d0f40  8b08                 mov ecx, dword ptr [eax]
// 004d0f42  8b5104               mov edx, dword ptr [ecx + 4]
// 004d0f45  3b0a                 cmp ecx, dword ptr [edx]
// 004d0f47  7551                 jne 0x4d0f9a
// 004d0f49  8b5208               mov edx, dword ptr [edx + 8]
// 004d0f4c  807a3400             cmp byte ptr [edx + 0x34], 0
// 004d0f50  7519                 jne 0x4d0f6b
// 004d0f52  885934               mov byte ptr [ecx + 0x34], bl
// 004d0f55  885a34               mov byte ptr [edx + 0x34], bl
// 004d0f58  8b10                 mov edx, dword ptr [eax]
// 004d0f5a  8b4a04               mov ecx, dword ptr [edx + 4]
// 004d0f5d  c6413400             mov byte ptr [ecx + 0x34], 0
// 004d0f61  8b10                 mov edx, dword ptr [eax]
// 004d0f63  8b7204               mov esi, dword ptr [edx + 4]
// 004d0f66  e9aa000000           jmp 0x4d1015
// 004d0f6b  3b7108               cmp esi, dword ptr [ecx + 8]
// 004d0f6e  750a                 jne 0x4d0f7a
// 004d0f70  8bf1                 mov esi, ecx
// 004d0f72  56                   push esi
// 004d0f73  8bcf                 mov ecx, edi
// 004d0f75  e886711300           call 0x608100
// 004d0f7a  8b4604               mov eax, dword ptr [esi + 4]
// 004d0f7d  885834               mov byte ptr [eax + 0x34], bl
// 004d0f80  8b4e04               mov ecx, dword ptr [esi + 4]
// 004d0f83  8b5104               mov edx, dword ptr [ecx + 4]
// 004d0f86  c6423400             mov byte ptr [edx + 0x34], 0
// 004d0f8a  8b4604               mov eax, dword ptr [esi + 4]
// 004d0f8d  8b4804               mov ecx, dword ptr [eax + 4]
// 004d0f90  51                   push ecx
// 004d0f91  8bcf                 mov ecx, edi
// 004d0f93  e8c8c6ffff           call 0x4cd660
// 004d0f98  eb7b                 jmp 0x4d1015
// 004d0f9a  8b12                 mov edx, dword ptr [edx]
// 004d0f9c  807a3400             cmp byte ptr [edx + 0x34], 0
// 004d0fa0  7516                 jne 0x4d0fb8
// 004d0fa2  885934               mov byte ptr [ecx + 0x34], bl
// 004d0fa5  885a34               mov byte ptr [edx + 0x34], bl
// 004d0fa8  8b10                 mov edx, dword ptr [eax]
// 004d0faa  8b4a04               mov ecx, dword ptr [edx + 4]
// 004d0fad  c6413400             mov byte ptr [ecx + 0x34], 0
// 004d0fb1  8b10                 mov edx, dword ptr [eax]
// 004d0fb3  8b7204               mov esi, dword ptr [edx + 4]
// 004d0fb6  eb5d                 jmp 0x4d1015
// 004d0fb8  3b31                 cmp esi, dword ptr [ecx]
// 004d0fba  750a                 jne 0x4d0fc6
// 004d0fbc  8bf1                 mov esi, ecx
// 004d0fbe  56                   push esi
// 004d0fbf  8bcf                 mov ecx, edi
// 004d0fc1  e89ac6ffff           call 0x4cd660
// 004d0fc6  8b4604               mov eax, dword ptr [esi + 4]
// 004d0fc9  885834               mov byte ptr [eax + 0x34], bl
// 004d0fcc  8b4e04               mov ecx, dword ptr [esi + 4]
// 004d0fcf  8b5104               mov edx, dword ptr [ecx + 4]
// 004d0fd2  c6423400             mov byte ptr [edx + 0x34], 0
// 004d0fd6  8b4604               mov eax, dword ptr [esi + 4]
// 004d0fd9  8b4004               mov eax, dword ptr [eax + 4]
// 004d0fdc  8b4808               mov ecx, dword ptr [eax + 8]
// 004d0fdf  8b11                 mov edx, dword ptr [ecx]
// 004d0fe1  895008               mov dword ptr [eax + 8], edx
// 004d0fe4  8b11                 mov edx, dword ptr [ecx]
// 004d0fe6  807a3500             cmp byte ptr [edx + 0x35], 0
// 004d0fea  7503                 jne 0x4d0fef
// 004d0fec  894204               mov dword ptr [edx + 4], eax
// 004d0fef  8b5004               mov edx, dword ptr [eax + 4]
// 004d0ff2  895104               mov dword ptr [ecx + 4], edx
// 004d0ff5  8b5704               mov edx, dword ptr [edi + 4]
// 004d0ff8  3b4204               cmp eax, dword ptr [edx + 4]
// 004d0ffb  7505                 jne 0x4d1002
// 004d0ffd  894a04               mov dword ptr [edx + 4], ecx
// 004d1000  eb0e                 jmp 0x4d1010
// 004d1002  8b5004               mov edx, dword ptr [eax + 4]
// 004d1005  3b02                 cmp eax, dword ptr [edx]
// 004d1007  7504                 jne 0x4d100d
// 004d1009  890a                 mov dword ptr [edx], ecx
// 004d100b  eb03                 jmp 0x4d1010
// 004d100d  894a08               mov dword ptr [edx + 8], ecx
// 004d1010  8901                 mov dword ptr [ecx], eax
// 004d1012  894804               mov dword ptr [eax + 4], ecx
// 004d1015  8b4e04               mov ecx, dword ptr [esi + 4]
// 004d1018  80793400             cmp byte ptr [ecx + 0x34], 0
// 004d101c  8d4604               lea eax, [esi + 4]
// 004d101f  0f841bffffff         je 0x4d0f40
// 004d1025  8b5704               mov edx, dword ptr [edi + 4]
// 004d1028  8b4204               mov eax, dword ptr [edx + 4]
// 004d102b  8b4c2454             mov ecx, dword ptr [esp + 0x54]
// 004d102f  885834               mov byte ptr [eax + 0x34], bl
// 004d1032  8b442464             mov eax, dword ptr [esp + 0x64]
// 004d1036  5e                   pop esi
// 004d1037  896804               mov dword ptr [eax + 4], ebp
// 004d103a  5d                   pop ebp
// 004d103b  8938                 mov dword ptr [eax], edi
// 004d103d  5b                   pop ebx
// 004d103e  5f                   pop edi
// 004d103f  64890d00000000       mov dword ptr fs:[0], ecx
// 004d1046  83c450               add esp, 0x50
// 004d1049  c21000               ret 0x10
// standard library map_int<pod36> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod36>
struct E { int v[9]; };
#include <map>
template class std::map<int, E>;
