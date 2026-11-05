// from server: 100% by auto
// roc 2010-06 0076fe90  unit: RBX::ScoreHud  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0076fe90
//
// 0076fe90  64a100000000         mov eax, dword ptr fs:[0]
// 0076fe96  6aff                 push -1
// 0076fe98  68e22f9a00           push 0x9a2fe2
// 0076fe9d  50                   push eax
// 0076fe9e  64892500000000       mov dword ptr fs:[0], esp
// 0076fea5  83ec44               sub esp, 0x44
// 0076fea8  57                   push edi
// 0076fea9  8bf9                 mov edi, ecx
// 0076feab  817f1c48922409       cmp dword ptr [edi + 0x1c], 0x9249248
// 0076feb2  7259                 jb 0x76ff0d
// 0076feb4  68a800a000           push 0xa000a8
// 0076feb9  8d4c2408             lea ecx, [esp + 8]
// 0076febd  ff1510a49e00         call dword ptr [0x9ea410]
// 0076fec3  8d4c2420             lea ecx, [esp + 0x20]
// 0076fec7  c744245000000000     mov dword ptr [esp + 0x50], 0
// 0076fecf  ff1518a99e00         call dword ptr [0x9ea918]
// 0076fed5  8d442404             lea eax, [esp + 4]
// 0076fed9  50                   push eax
// 0076feda  8d4c2430             lea ecx, [esp + 0x30]
// 0076fede  c644245401           mov byte ptr [esp + 0x54], 1
// 0076fee3  c74424242c00a000     mov dword ptr [esp + 0x24], 0xa0002c
// 0076feeb  ff150ca49e00         call dword ptr [0x9ea40c]
// 0076fef1  68601bb000           push 0xb01b60
// 0076fef6  8d4c2424             lea ecx, [esp + 0x24]
// 0076fefa  51                   push ecx
// 0076fefb  c644245800           mov byte ptr [esp + 0x58], 0
// 0076ff00  c74424283800a000     mov dword ptr [esp + 0x28], 0xa00038
// 0076ff08  e8a58a0300           call 0x7a89b2
// 0076ff0d  8b542464             mov edx, dword ptr [esp + 0x64]
// 0076ff11  8b4718               mov eax, dword ptr [edi + 0x18]
// 0076ff14  53                   push ebx
// 0076ff15  55                   push ebp
// 0076ff16  56                   push esi
// 0076ff17  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 0076ff1b  6a00                 push 0
// 0076ff1d  52                   push edx
// 0076ff1e  50                   push eax
// 0076ff1f  56                   push esi
// 0076ff20  50                   push eax
// 0076ff21  e88afdffff           call 0x76fcb0
// 0076ff26  8be8                 mov ebp, eax
// 0076ff28  8b4718               mov eax, dword ptr [edi + 0x18]
// 0076ff2b  bb01000000           mov ebx, 1
// 0076ff30  015f1c               add dword ptr [edi + 0x1c], ebx
// 0076ff33  3bf0                 cmp esi, eax
// 0076ff35  7510                 jne 0x76ff47
// 0076ff37  896804               mov dword ptr [eax + 4], ebp
// 0076ff3a  8b4718               mov eax, dword ptr [edi + 0x18]
// 0076ff3d  8928                 mov dword ptr [eax], ebp
// 0076ff3f  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 0076ff42  896908               mov dword ptr [ecx + 8], ebp
// 0076ff45  eb22                 jmp 0x76ff69
// 0076ff47  807c246800           cmp byte ptr [esp + 0x68], 0
// 0076ff4c  740d                 je 0x76ff5b
// 0076ff4e  892e                 mov dword ptr [esi], ebp
// 0076ff50  8b4718               mov eax, dword ptr [edi + 0x18]
// 0076ff53  3b30                 cmp esi, dword ptr [eax]
// 0076ff55  7512                 jne 0x76ff69
// 0076ff57  8928                 mov dword ptr [eax], ebp
// 0076ff59  eb0e                 jmp 0x76ff69
// 0076ff5b  896e08               mov dword ptr [esi + 8], ebp
// 0076ff5e  8b4718               mov eax, dword ptr [edi + 0x18]
// 0076ff61  3b7008               cmp esi, dword ptr [eax + 8]
// 0076ff64  7503                 jne 0x76ff69
// 0076ff66  896808               mov dword ptr [eax + 8], ebp
// 0076ff69  8b5504               mov edx, dword ptr [ebp + 4]
// 0076ff6c  807a2800             cmp byte ptr [edx + 0x28], 0
// 0076ff70  8d4504               lea eax, [ebp + 4]
// 0076ff73  8bf5                 mov esi, ebp
// 0076ff75  0f85ea000000         jne 0x770065
// 0076ff7b  eb03                 jmp 0x76ff80
// 0076ff7d  8d4900               lea ecx, [ecx]
// 0076ff80  8b08                 mov ecx, dword ptr [eax]
// 0076ff82  8b5104               mov edx, dword ptr [ecx + 4]
// 0076ff85  3b0a                 cmp ecx, dword ptr [edx]
// 0076ff87  7551                 jne 0x76ffda
// 0076ff89  8b5208               mov edx, dword ptr [edx + 8]
// 0076ff8c  807a2800             cmp byte ptr [edx + 0x28], 0
// 0076ff90  7519                 jne 0x76ffab
// 0076ff92  885928               mov byte ptr [ecx + 0x28], bl
// 0076ff95  885a28               mov byte ptr [edx + 0x28], bl
// 0076ff98  8b10                 mov edx, dword ptr [eax]
// 0076ff9a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0076ff9d  c6412800             mov byte ptr [ecx + 0x28], 0
// 0076ffa1  8b10                 mov edx, dword ptr [eax]
// 0076ffa3  8b7204               mov esi, dword ptr [edx + 4]
// 0076ffa6  e9aa000000           jmp 0x770055
// 0076ffab  3b7108               cmp esi, dword ptr [ecx + 8]
// 0076ffae  750a                 jne 0x76ffba
// 0076ffb0  8bf1                 mov esi, ecx
// 0076ffb2  56                   push esi
// 0076ffb3  8bcf                 mov ecx, edi
// 0076ffb5  e81670dbff           call 0x526fd0
// 0076ffba  8b4604               mov eax, dword ptr [esi + 4]
// 0076ffbd  885828               mov byte ptr [eax + 0x28], bl
// 0076ffc0  8b4e04               mov ecx, dword ptr [esi + 4]
// 0076ffc3  8b5104               mov edx, dword ptr [ecx + 4]
// 0076ffc6  c6422800             mov byte ptr [edx + 0x28], 0
// 0076ffca  8b4604               mov eax, dword ptr [esi + 4]
// 0076ffcd  8b4804               mov ecx, dword ptr [eax + 4]
// 0076ffd0  51                   push ecx
// 0076ffd1  8bcf                 mov ecx, edi
// 0076ffd3  e8986fdbff           call 0x526f70
// 0076ffd8  eb7b                 jmp 0x770055
// 0076ffda  8b12                 mov edx, dword ptr [edx]
// 0076ffdc  807a2800             cmp byte ptr [edx + 0x28], 0
// 0076ffe0  7516                 jne 0x76fff8
// 0076ffe2  885928               mov byte ptr [ecx + 0x28], bl
// 0076ffe5  885a28               mov byte ptr [edx + 0x28], bl
// 0076ffe8  8b10                 mov edx, dword ptr [eax]
// 0076ffea  8b4a04               mov ecx, dword ptr [edx + 4]
// 0076ffed  c6412800             mov byte ptr [ecx + 0x28], 0
// 0076fff1  8b10                 mov edx, dword ptr [eax]
// 0076fff3  8b7204               mov esi, dword ptr [edx + 4]
// 0076fff6  eb5d                 jmp 0x770055
// 0076fff8  3b31                 cmp esi, dword ptr [ecx]
// 0076fffa  750a                 jne 0x770006
// 0076fffc  8bf1                 mov esi, ecx
// 0076fffe  56                   push esi
// 0076ffff  8bcf                 mov ecx, edi
// 00770001  e86a6fdbff           call 0x526f70
// 00770006  8b4604               mov eax, dword ptr [esi + 4]
// 00770009  885828               mov byte ptr [eax + 0x28], bl
// 0077000c  8b4e04               mov ecx, dword ptr [esi + 4]
// 0077000f  8b5104               mov edx, dword ptr [ecx + 4]
// 00770012  c6422800             mov byte ptr [edx + 0x28], 0
// 00770016  8b4604               mov eax, dword ptr [esi + 4]
// 00770019  8b4004               mov eax, dword ptr [eax + 4]
// 0077001c  8b4808               mov ecx, dword ptr [eax + 8]
// 0077001f  8b11                 mov edx, dword ptr [ecx]
// 00770021  895008               mov dword ptr [eax + 8], edx
// 00770024  8b11                 mov edx, dword ptr [ecx]
// 00770026  807a2900             cmp byte ptr [edx + 0x29], 0
// 0077002a  7503                 jne 0x77002f
// 0077002c  894204               mov dword ptr [edx + 4], eax
// 0077002f  8b5004               mov edx, dword ptr [eax + 4]
// 00770032  895104               mov dword ptr [ecx + 4], edx
// 00770035  8b5718               mov edx, dword ptr [edi + 0x18]
// 00770038  3b4204               cmp eax, dword ptr [edx + 4]
// 0077003b  7505                 jne 0x770042
// 0077003d  894a04               mov dword ptr [edx + 4], ecx
// 00770040  eb0e                 jmp 0x770050
// 00770042  8b5004               mov edx, dword ptr [eax + 4]
// 00770045  3b02                 cmp eax, dword ptr [edx]
// 00770047  7504                 jne 0x77004d
// 00770049  890a                 mov dword ptr [edx], ecx
// 0077004b  eb03                 jmp 0x770050
// 0077004d  894a08               mov dword ptr [edx + 8], ecx
// 00770050  8901                 mov dword ptr [ecx], eax
// 00770052  894804               mov dword ptr [eax + 4], ecx
// 00770055  8b4e04               mov ecx, dword ptr [esi + 4]
// 00770058  80792800             cmp byte ptr [ecx + 0x28], 0
// 0077005c  8d4604               lea eax, [esi + 4]
// 0077005f  0f841bffffff         je 0x76ff80
// 00770065  8b5718               mov edx, dword ptr [edi + 0x18]
// 00770068  8b4204               mov eax, dword ptr [edx + 4]
// 0077006b  885828               mov byte ptr [eax + 0x28], bl
// 0077006e  8b442464             mov eax, dword ptr [esp + 0x64]
// 00770072  8b0f                 mov ecx, dword ptr [edi]
// 00770074  5e                   pop esi
// 00770075  896804               mov dword ptr [eax + 4], ebp
// 00770078  5d                   pop ebp
// 00770079  8908                 mov dword ptr [eax], ecx
// 0077007b  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 0077007f  5b                   pop ebx
// 00770080  5f                   pop edi
// 00770081  64890d00000000       mov dword ptr fs:[0], ecx
// 00770088  83c450               add esp, 0x50
// 0077008b  c21000               ret 0x10
// standard library map_int<pod24> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod24>
struct E { int v[6]; };
#include <map>
template class std::map<int, E>;
