// from server: 100% by auto
// roc 2009-12 00762e60  unit: RBX::VInstance::?$NonFactoryProduct  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00762e60
//
// 00762e60  64a100000000         mov eax, dword ptr fs:[0]
// 00762e66  6aff                 push -1
// 00762e68  6812699500           push 0x956912
// 00762e6d  50                   push eax
// 00762e6e  64892500000000       mov dword ptr fs:[0], esp
// 00762e75  83ec44               sub esp, 0x44
// 00762e78  57                   push edi
// 00762e79  8bf9                 mov edi, ecx
// 00762e7b  817f1cc6711c07       cmp dword ptr [edi + 0x1c], 0x71c71c6
// 00762e82  7259                 jb 0x762edd
// 00762e84  6800f59900           push 0x99f500
// 00762e89  8d4c2408             lea ecx, [esp + 8]
// 00762e8d  ff15f4b69800         call dword ptr [0x98b6f4]
// 00762e93  8d4c2420             lea ecx, [esp + 0x20]
// 00762e97  c744245000000000     mov dword ptr [esp + 0x50], 0
// 00762e9f  ff1554b79800         call dword ptr [0x98b754]
// 00762ea5  8d442404             lea eax, [esp + 4]
// 00762ea9  50                   push eax
// 00762eaa  8d4c2430             lea ecx, [esp + 0x30]
// 00762eae  c644245401           mov byte ptr [esp + 0x54], 1
// 00762eb3  c744242484f49900     mov dword ptr [esp + 0x24], 0x99f484
// 00762ebb  ff15f0b69800         call dword ptr [0x98b6f0]
// 00762ec1  68e4efa800           push 0xa8efe4
// 00762ec6  8d4c2424             lea ecx, [esp + 0x24]
// 00762eca  51                   push ecx
// 00762ecb  c644245800           mov byte ptr [esp + 0x58], 0
// 00762ed0  c744242890f49900     mov dword ptr [esp + 0x28], 0x99f490
// 00762ed8  e89b190900           call 0x7f4878
// 00762edd  8b542464             mov edx, dword ptr [esp + 0x64]
// 00762ee1  8b4718               mov eax, dword ptr [edi + 0x18]
// 00762ee4  53                   push ebx
// 00762ee5  55                   push ebp
// 00762ee6  56                   push esi
// 00762ee7  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 00762eeb  6a00                 push 0
// 00762eed  52                   push edx
// 00762eee  50                   push eax
// 00762eef  56                   push esi
// 00762ef0  50                   push eax
// 00762ef1  e84afaffff           call 0x762940
// 00762ef6  8be8                 mov ebp, eax
// 00762ef8  8b4718               mov eax, dword ptr [edi + 0x18]
// 00762efb  bb01000000           mov ebx, 1
// 00762f00  015f1c               add dword ptr [edi + 0x1c], ebx
// 00762f03  3bf0                 cmp esi, eax
// 00762f05  7510                 jne 0x762f17
// 00762f07  896804               mov dword ptr [eax + 4], ebp
// 00762f0a  8b4718               mov eax, dword ptr [edi + 0x18]
// 00762f0d  8928                 mov dword ptr [eax], ebp
// 00762f0f  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 00762f12  896908               mov dword ptr [ecx + 8], ebp
// 00762f15  eb22                 jmp 0x762f39
// 00762f17  807c246800           cmp byte ptr [esp + 0x68], 0
// 00762f1c  740d                 je 0x762f2b
// 00762f1e  892e                 mov dword ptr [esi], ebp
// 00762f20  8b4718               mov eax, dword ptr [edi + 0x18]
// 00762f23  3b30                 cmp esi, dword ptr [eax]
// 00762f25  7512                 jne 0x762f39
// 00762f27  8928                 mov dword ptr [eax], ebp
// 00762f29  eb0e                 jmp 0x762f39
// 00762f2b  896e08               mov dword ptr [esi + 8], ebp
// 00762f2e  8b4718               mov eax, dword ptr [edi + 0x18]
// 00762f31  3b7008               cmp esi, dword ptr [eax + 8]
// 00762f34  7503                 jne 0x762f39
// 00762f36  896808               mov dword ptr [eax + 8], ebp
// 00762f39  8b5504               mov edx, dword ptr [ebp + 4]
// 00762f3c  807a3000             cmp byte ptr [edx + 0x30], 0
// 00762f40  8d4504               lea eax, [ebp + 4]
// 00762f43  8bf5                 mov esi, ebp
// 00762f45  0f85ea000000         jne 0x763035
// 00762f4b  eb03                 jmp 0x762f50
// 00762f4d  8d4900               lea ecx, [ecx]
// 00762f50  8b08                 mov ecx, dword ptr [eax]
// 00762f52  8b5104               mov edx, dword ptr [ecx + 4]
// 00762f55  3b0a                 cmp ecx, dword ptr [edx]
// 00762f57  7551                 jne 0x762faa
// 00762f59  8b5208               mov edx, dword ptr [edx + 8]
// 00762f5c  807a3000             cmp byte ptr [edx + 0x30], 0
// 00762f60  7519                 jne 0x762f7b
// 00762f62  885930               mov byte ptr [ecx + 0x30], bl
// 00762f65  885a30               mov byte ptr [edx + 0x30], bl
// 00762f68  8b10                 mov edx, dword ptr [eax]
// 00762f6a  8b4a04               mov ecx, dword ptr [edx + 4]
// 00762f6d  c6413000             mov byte ptr [ecx + 0x30], 0
// 00762f71  8b10                 mov edx, dword ptr [eax]
// 00762f73  8b7204               mov esi, dword ptr [edx + 4]
// 00762f76  e9aa000000           jmp 0x763025
// 00762f7b  3b7108               cmp esi, dword ptr [ecx + 8]
// 00762f7e  750a                 jne 0x762f8a
// 00762f80  8bf1                 mov esi, ecx
// 00762f82  56                   push esi
// 00762f83  8bcf                 mov ecx, edi
// 00762f85  e88608dbff           call 0x513810
// 00762f8a  8b4604               mov eax, dword ptr [esi + 4]
// 00762f8d  885830               mov byte ptr [eax + 0x30], bl
// 00762f90  8b4e04               mov ecx, dword ptr [esi + 4]
// 00762f93  8b5104               mov edx, dword ptr [ecx + 4]
// 00762f96  c6423000             mov byte ptr [edx + 0x30], 0
// 00762f9a  8b4604               mov eax, dword ptr [esi + 4]
// 00762f9d  8b4804               mov ecx, dword ptr [eax + 4]
// 00762fa0  51                   push ecx
// 00762fa1  8bcf                 mov ecx, edi
// 00762fa3  e8f8fcf9ff           call 0x702ca0
// 00762fa8  eb7b                 jmp 0x763025
// 00762faa  8b12                 mov edx, dword ptr [edx]
// 00762fac  807a3000             cmp byte ptr [edx + 0x30], 0
// 00762fb0  7516                 jne 0x762fc8
// 00762fb2  885930               mov byte ptr [ecx + 0x30], bl
// 00762fb5  885a30               mov byte ptr [edx + 0x30], bl
// 00762fb8  8b10                 mov edx, dword ptr [eax]
// 00762fba  8b4a04               mov ecx, dword ptr [edx + 4]
// 00762fbd  c6413000             mov byte ptr [ecx + 0x30], 0
// 00762fc1  8b10                 mov edx, dword ptr [eax]
// 00762fc3  8b7204               mov esi, dword ptr [edx + 4]
// 00762fc6  eb5d                 jmp 0x763025
// 00762fc8  3b31                 cmp esi, dword ptr [ecx]
// 00762fca  750a                 jne 0x762fd6
// 00762fcc  8bf1                 mov esi, ecx
// 00762fce  56                   push esi
// 00762fcf  8bcf                 mov ecx, edi
// 00762fd1  e8cafcf9ff           call 0x702ca0
// 00762fd6  8b4604               mov eax, dword ptr [esi + 4]
// 00762fd9  885830               mov byte ptr [eax + 0x30], bl
// 00762fdc  8b4e04               mov ecx, dword ptr [esi + 4]
// 00762fdf  8b5104               mov edx, dword ptr [ecx + 4]
// 00762fe2  c6423000             mov byte ptr [edx + 0x30], 0
// 00762fe6  8b4604               mov eax, dword ptr [esi + 4]
// 00762fe9  8b4004               mov eax, dword ptr [eax + 4]
// 00762fec  8b4808               mov ecx, dword ptr [eax + 8]
// 00762fef  8b11                 mov edx, dword ptr [ecx]
// 00762ff1  895008               mov dword ptr [eax + 8], edx
// 00762ff4  8b11                 mov edx, dword ptr [ecx]
// 00762ff6  807a3100             cmp byte ptr [edx + 0x31], 0
// 00762ffa  7503                 jne 0x762fff
// 00762ffc  894204               mov dword ptr [edx + 4], eax
// 00762fff  8b5004               mov edx, dword ptr [eax + 4]
// 00763002  895104               mov dword ptr [ecx + 4], edx
// 00763005  8b5718               mov edx, dword ptr [edi + 0x18]
// 00763008  3b4204               cmp eax, dword ptr [edx + 4]
// 0076300b  7505                 jne 0x763012
// 0076300d  894a04               mov dword ptr [edx + 4], ecx
// 00763010  eb0e                 jmp 0x763020
// 00763012  8b5004               mov edx, dword ptr [eax + 4]
// 00763015  3b02                 cmp eax, dword ptr [edx]
// 00763017  7504                 jne 0x76301d
// 00763019  890a                 mov dword ptr [edx], ecx
// 0076301b  eb03                 jmp 0x763020
// 0076301d  894a08               mov dword ptr [edx + 8], ecx
// 00763020  8901                 mov dword ptr [ecx], eax
// 00763022  894804               mov dword ptr [eax + 4], ecx
// 00763025  8b4e04               mov ecx, dword ptr [esi + 4]
// 00763028  80793000             cmp byte ptr [ecx + 0x30], 0
// 0076302c  8d4604               lea eax, [esi + 4]
// 0076302f  0f841bffffff         je 0x762f50
// 00763035  8b5718               mov edx, dword ptr [edi + 0x18]
// 00763038  8b4204               mov eax, dword ptr [edx + 4]
// 0076303b  885830               mov byte ptr [eax + 0x30], bl
// 0076303e  8b442464             mov eax, dword ptr [esp + 0x64]
// 00763042  8b0f                 mov ecx, dword ptr [edi]
// 00763044  5e                   pop esi
// 00763045  896804               mov dword ptr [eax + 4], ebp
// 00763048  5d                   pop ebp
// 00763049  8908                 mov dword ptr [eax], ecx
// 0076304b  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 0076304f  5b                   pop ebx
// 00763050  5f                   pop edi
// 00763051  64890d00000000       mov dword ptr fs:[0], ecx
// 00763058  83c450               add esp, 0x50
// 0076305b  c21000               ret 0x10
// standard library map_int<pod32> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod32>
struct E { int v[8]; };
#include <map>
template class std::map<int, E>;
