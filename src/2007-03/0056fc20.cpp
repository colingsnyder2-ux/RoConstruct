// from server: 100% by auto
// roc 2007-03 0056fc20  unit: seg_00560000  size: 508 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0056fc20
//
// 0056fc20  64a100000000         mov eax, dword ptr fs:[0]
// 0056fc26  6aff                 push -1
// 0056fc28  68926f7500           push 0x756f92
// 0056fc2d  50                   push eax
// 0056fc2e  64892500000000       mov dword ptr fs:[0], esp
// 0056fc35  83ec44               sub esp, 0x44
// 0056fc38  57                   push edi
// 0056fc39  8bf9                 mov edi, ecx
// 0056fc3b  817f0854555515       cmp dword ptr [edi + 8], 0x15555554
// 0056fc42  7259                 jb 0x56fc9d
// 0056fc44  68903f7800           push 0x783f90
// 0056fc49  8d4c2408             lea ecx, [esp + 8]
// 0056fc4d  ff1578e77700         call dword ptr [0x77e778]
// 0056fc53  8d4c2420             lea ecx, [esp + 0x20]
// 0056fc57  c744245000000000     mov dword ptr [esp + 0x50], 0
// 0056fc5f  ff1560e97700         call dword ptr [0x77e960]
// 0056fc65  8d442404             lea eax, [esp + 4]
// 0056fc69  50                   push eax
// 0056fc6a  8d4c2430             lea ecx, [esp + 0x30]
// 0056fc6e  c644245401           mov byte ptr [esp + 0x54], 1
// 0056fc73  c7442424383e7800     mov dword ptr [esp + 0x24], 0x783e38
// 0056fc7b  ff157ce77700         call dword ptr [0x77e77c]
// 0056fc81  6870f78300           push 0x83f770
// 0056fc86  8d4c2424             lea ecx, [esp + 0x24]
// 0056fc8a  51                   push ecx
// 0056fc8b  c644245800           mov byte ptr [esp + 0x58], 0
// 0056fc90  c7442428443e7800     mov dword ptr [esp + 0x28], 0x783e44
// 0056fc98  e891f30a00           call 0x61f02e
// 0056fc9d  8b542464             mov edx, dword ptr [esp + 0x64]
// 0056fca1  8b4704               mov eax, dword ptr [edi + 4]
// 0056fca4  53                   push ebx
// 0056fca5  55                   push ebp
// 0056fca6  56                   push esi
// 0056fca7  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 0056fcab  6a00                 push 0
// 0056fcad  52                   push edx
// 0056fcae  50                   push eax
// 0056fcaf  56                   push esi
// 0056fcb0  50                   push eax
// 0056fcb1  e80ae8f2ff           call 0x49e4c0
// 0056fcb6  8be8                 mov ebp, eax
// 0056fcb8  8b4704               mov eax, dword ptr [edi + 4]
// 0056fcbb  bb01000000           mov ebx, 1
// 0056fcc0  015f08               add dword ptr [edi + 8], ebx
// 0056fcc3  3bf0                 cmp esi, eax
// 0056fcc5  7510                 jne 0x56fcd7
// 0056fcc7  896804               mov dword ptr [eax + 4], ebp
// 0056fcca  8b4704               mov eax, dword ptr [edi + 4]
// 0056fccd  8928                 mov dword ptr [eax], ebp
// 0056fccf  8b4f04               mov ecx, dword ptr [edi + 4]
// 0056fcd2  896908               mov dword ptr [ecx + 8], ebp
// 0056fcd5  eb22                 jmp 0x56fcf9
// 0056fcd7  807c246800           cmp byte ptr [esp + 0x68], 0
// 0056fcdc  740d                 je 0x56fceb
// 0056fcde  892e                 mov dword ptr [esi], ebp
// 0056fce0  8b4704               mov eax, dword ptr [edi + 4]
// 0056fce3  3b30                 cmp esi, dword ptr [eax]
// 0056fce5  7512                 jne 0x56fcf9
// 0056fce7  8928                 mov dword ptr [eax], ebp
// 0056fce9  eb0e                 jmp 0x56fcf9
// 0056fceb  896e08               mov dword ptr [esi + 8], ebp
// 0056fcee  8b4704               mov eax, dword ptr [edi + 4]
// 0056fcf1  3b7008               cmp esi, dword ptr [eax + 8]
// 0056fcf4  7503                 jne 0x56fcf9
// 0056fcf6  896808               mov dword ptr [eax + 8], ebp
// 0056fcf9  8b5504               mov edx, dword ptr [ebp + 4]
// 0056fcfc  807a1800             cmp byte ptr [edx + 0x18], 0
// 0056fd00  8d4504               lea eax, [ebp + 4]
// 0056fd03  8bf5                 mov esi, ebp
// 0056fd05  0f85ea000000         jne 0x56fdf5
// 0056fd0b  eb03                 jmp 0x56fd10
// 0056fd0d  8d4900               lea ecx, [ecx]
// 0056fd10  8b08                 mov ecx, dword ptr [eax]
// 0056fd12  8b5104               mov edx, dword ptr [ecx + 4]
// 0056fd15  3b0a                 cmp ecx, dword ptr [edx]
// 0056fd17  7551                 jne 0x56fd6a
// 0056fd19  8b5208               mov edx, dword ptr [edx + 8]
// 0056fd1c  807a1800             cmp byte ptr [edx + 0x18], 0
// 0056fd20  7519                 jne 0x56fd3b
// 0056fd22  885918               mov byte ptr [ecx + 0x18], bl
// 0056fd25  885a18               mov byte ptr [edx + 0x18], bl
// 0056fd28  8b10                 mov edx, dword ptr [eax]
// 0056fd2a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0056fd2d  c6411800             mov byte ptr [ecx + 0x18], 0
// 0056fd31  8b10                 mov edx, dword ptr [eax]
// 0056fd33  8b7204               mov esi, dword ptr [edx + 4]
// 0056fd36  e9aa000000           jmp 0x56fde5
// 0056fd3b  3b7108               cmp esi, dword ptr [ecx + 8]
// 0056fd3e  750a                 jne 0x56fd4a
// 0056fd40  8bf1                 mov esi, ecx
// 0056fd42  56                   push esi
// 0056fd43  8bcf                 mov ecx, edi
// 0056fd45  e866140800           call 0x5f11b0
// 0056fd4a  8b4604               mov eax, dword ptr [esi + 4]
// 0056fd4d  885818               mov byte ptr [eax + 0x18], bl
// 0056fd50  8b4e04               mov ecx, dword ptr [esi + 4]
// 0056fd53  8b5104               mov edx, dword ptr [ecx + 4]
// 0056fd56  c6421800             mov byte ptr [edx + 0x18], 0
// 0056fd5a  8b4604               mov eax, dword ptr [esi + 4]
// 0056fd5d  8b4804               mov ecx, dword ptr [eax + 4]
// 0056fd60  51                   push ecx
// 0056fd61  8bcf                 mov ecx, edi
// 0056fd63  e8f8c0f2ff           call 0x49be60
// 0056fd68  eb7b                 jmp 0x56fde5
// 0056fd6a  8b12                 mov edx, dword ptr [edx]
// 0056fd6c  807a1800             cmp byte ptr [edx + 0x18], 0
// 0056fd70  7516                 jne 0x56fd88
// 0056fd72  885918               mov byte ptr [ecx + 0x18], bl
// 0056fd75  885a18               mov byte ptr [edx + 0x18], bl
// 0056fd78  8b10                 mov edx, dword ptr [eax]
// 0056fd7a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0056fd7d  c6411800             mov byte ptr [ecx + 0x18], 0
// 0056fd81  8b10                 mov edx, dword ptr [eax]
// 0056fd83  8b7204               mov esi, dword ptr [edx + 4]
// 0056fd86  eb5d                 jmp 0x56fde5
// 0056fd88  3b31                 cmp esi, dword ptr [ecx]
// 0056fd8a  750a                 jne 0x56fd96
// 0056fd8c  8bf1                 mov esi, ecx
// 0056fd8e  56                   push esi
// 0056fd8f  8bcf                 mov ecx, edi
// 0056fd91  e8cac0f2ff           call 0x49be60
// 0056fd96  8b4604               mov eax, dword ptr [esi + 4]
// 0056fd99  885818               mov byte ptr [eax + 0x18], bl
// 0056fd9c  8b4e04               mov ecx, dword ptr [esi + 4]
// 0056fd9f  8b5104               mov edx, dword ptr [ecx + 4]
// 0056fda2  c6421800             mov byte ptr [edx + 0x18], 0
// 0056fda6  8b4604               mov eax, dword ptr [esi + 4]
// 0056fda9  8b4004               mov eax, dword ptr [eax + 4]
// 0056fdac  8b4808               mov ecx, dword ptr [eax + 8]
// 0056fdaf  8b11                 mov edx, dword ptr [ecx]
// 0056fdb1  895008               mov dword ptr [eax + 8], edx
// 0056fdb4  8b11                 mov edx, dword ptr [ecx]
// 0056fdb6  807a1900             cmp byte ptr [edx + 0x19], 0
// 0056fdba  7503                 jne 0x56fdbf
// 0056fdbc  894204               mov dword ptr [edx + 4], eax
// 0056fdbf  8b5004               mov edx, dword ptr [eax + 4]
// 0056fdc2  895104               mov dword ptr [ecx + 4], edx
// 0056fdc5  8b5704               mov edx, dword ptr [edi + 4]
// 0056fdc8  3b4204               cmp eax, dword ptr [edx + 4]
// 0056fdcb  7505                 jne 0x56fdd2
// 0056fdcd  894a04               mov dword ptr [edx + 4], ecx
// 0056fdd0  eb0e                 jmp 0x56fde0
// 0056fdd2  8b5004               mov edx, dword ptr [eax + 4]
// 0056fdd5  3b02                 cmp eax, dword ptr [edx]
// 0056fdd7  7504                 jne 0x56fddd
// 0056fdd9  890a                 mov dword ptr [edx], ecx
// 0056fddb  eb03                 jmp 0x56fde0
// 0056fddd  894a08               mov dword ptr [edx + 8], ecx
// 0056fde0  8901                 mov dword ptr [ecx], eax
// 0056fde2  894804               mov dword ptr [eax + 4], ecx
// 0056fde5  8b4e04               mov ecx, dword ptr [esi + 4]
// 0056fde8  80791800             cmp byte ptr [ecx + 0x18], 0
// 0056fdec  8d4604               lea eax, [esi + 4]
// 0056fdef  0f841bffffff         je 0x56fd10
// 0056fdf5  8b5704               mov edx, dword ptr [edi + 4]
// 0056fdf8  8b4204               mov eax, dword ptr [edx + 4]
// 0056fdfb  8b4c2454             mov ecx, dword ptr [esp + 0x54]
// 0056fdff  885818               mov byte ptr [eax + 0x18], bl
// 0056fe02  8b442464             mov eax, dword ptr [esp + 0x64]
// 0056fe06  5e                   pop esi
// 0056fe07  896804               mov dword ptr [eax + 4], ebp
// 0056fe0a  5d                   pop ebp
// 0056fe0b  8938                 mov dword ptr [eax], edi
// 0056fe0d  5b                   pop ebx
// 0056fe0e  5f                   pop edi
// 0056fe0f  64890d00000000       mov dword ptr fs:[0], ecx
// 0056fe16  83c450               add esp, 0x50
// 0056fe19  c21000               ret 0x10
// standard library map_int<pod8> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod8>
struct E { int v[2]; };
#include <map>
template class std::map<int, E>;
