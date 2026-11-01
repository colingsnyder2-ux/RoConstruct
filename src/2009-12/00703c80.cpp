// from server: 100% by auto
// roc 2009-12 00703c80  unit: RBX::Reflection::VValue::$$CBV?$vector::V?$shared_ptr::?$holder  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00703c80
//
// 00703c80  64a100000000         mov eax, dword ptr fs:[0]
// 00703c86  6aff                 push -1
// 00703c88  6812699500           push 0x956912
// 00703c8d  50                   push eax
// 00703c8e  64892500000000       mov dword ptr fs:[0], esp
// 00703c95  83ec44               sub esp, 0x44
// 00703c98  57                   push edi
// 00703c99  8bf9                 mov edi, ecx
// 00703c9b  817f1cc6711c07       cmp dword ptr [edi + 0x1c], 0x71c71c6
// 00703ca2  7259                 jb 0x703cfd
// 00703ca4  6800f59900           push 0x99f500
// 00703ca9  8d4c2408             lea ecx, [esp + 8]
// 00703cad  ff15f4b69800         call dword ptr [0x98b6f4]
// 00703cb3  8d4c2420             lea ecx, [esp + 0x20]
// 00703cb7  c744245000000000     mov dword ptr [esp + 0x50], 0
// 00703cbf  ff1554b79800         call dword ptr [0x98b754]
// 00703cc5  8d442404             lea eax, [esp + 4]
// 00703cc9  50                   push eax
// 00703cca  8d4c2430             lea ecx, [esp + 0x30]
// 00703cce  c644245401           mov byte ptr [esp + 0x54], 1
// 00703cd3  c744242484f49900     mov dword ptr [esp + 0x24], 0x99f484
// 00703cdb  ff15f0b69800         call dword ptr [0x98b6f0]
// 00703ce1  68e4efa800           push 0xa8efe4
// 00703ce6  8d4c2424             lea ecx, [esp + 0x24]
// 00703cea  51                   push ecx
// 00703ceb  c644245800           mov byte ptr [esp + 0x58], 0
// 00703cf0  c744242890f49900     mov dword ptr [esp + 0x28], 0x99f490
// 00703cf8  e87b0b0f00           call 0x7f4878
// 00703cfd  8b542464             mov edx, dword ptr [esp + 0x64]
// 00703d01  8b4718               mov eax, dword ptr [edi + 0x18]
// 00703d04  53                   push ebx
// 00703d05  55                   push ebp
// 00703d06  56                   push esi
// 00703d07  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 00703d0b  6a00                 push 0
// 00703d0d  52                   push edx
// 00703d0e  50                   push eax
// 00703d0f  56                   push esi
// 00703d10  50                   push eax
// 00703d11  e89af7ffff           call 0x7034b0
// 00703d16  8be8                 mov ebp, eax
// 00703d18  8b4718               mov eax, dword ptr [edi + 0x18]
// 00703d1b  bb01000000           mov ebx, 1
// 00703d20  015f1c               add dword ptr [edi + 0x1c], ebx
// 00703d23  3bf0                 cmp esi, eax
// 00703d25  7510                 jne 0x703d37
// 00703d27  896804               mov dword ptr [eax + 4], ebp
// 00703d2a  8b4718               mov eax, dword ptr [edi + 0x18]
// 00703d2d  8928                 mov dword ptr [eax], ebp
// 00703d2f  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 00703d32  896908               mov dword ptr [ecx + 8], ebp
// 00703d35  eb22                 jmp 0x703d59
// 00703d37  807c246800           cmp byte ptr [esp + 0x68], 0
// 00703d3c  740d                 je 0x703d4b
// 00703d3e  892e                 mov dword ptr [esi], ebp
// 00703d40  8b4718               mov eax, dword ptr [edi + 0x18]
// 00703d43  3b30                 cmp esi, dword ptr [eax]
// 00703d45  7512                 jne 0x703d59
// 00703d47  8928                 mov dword ptr [eax], ebp
// 00703d49  eb0e                 jmp 0x703d59
// 00703d4b  896e08               mov dword ptr [esi + 8], ebp
// 00703d4e  8b4718               mov eax, dword ptr [edi + 0x18]
// 00703d51  3b7008               cmp esi, dword ptr [eax + 8]
// 00703d54  7503                 jne 0x703d59
// 00703d56  896808               mov dword ptr [eax + 8], ebp
// 00703d59  8b5504               mov edx, dword ptr [ebp + 4]
// 00703d5c  807a3000             cmp byte ptr [edx + 0x30], 0
// 00703d60  8d4504               lea eax, [ebp + 4]
// 00703d63  8bf5                 mov esi, ebp
// 00703d65  0f85ea000000         jne 0x703e55
// 00703d6b  eb03                 jmp 0x703d70
// 00703d6d  8d4900               lea ecx, [ecx]
// 00703d70  8b08                 mov ecx, dword ptr [eax]
// 00703d72  8b5104               mov edx, dword ptr [ecx + 4]
// 00703d75  3b0a                 cmp ecx, dword ptr [edx]
// 00703d77  7551                 jne 0x703dca
// 00703d79  8b5208               mov edx, dword ptr [edx + 8]
// 00703d7c  807a3000             cmp byte ptr [edx + 0x30], 0
// 00703d80  7519                 jne 0x703d9b
// 00703d82  885930               mov byte ptr [ecx + 0x30], bl
// 00703d85  885a30               mov byte ptr [edx + 0x30], bl
// 00703d88  8b10                 mov edx, dword ptr [eax]
// 00703d8a  8b4a04               mov ecx, dword ptr [edx + 4]
// 00703d8d  c6413000             mov byte ptr [ecx + 0x30], 0
// 00703d91  8b10                 mov edx, dword ptr [eax]
// 00703d93  8b7204               mov esi, dword ptr [edx + 4]
// 00703d96  e9aa000000           jmp 0x703e45
// 00703d9b  3b7108               cmp esi, dword ptr [ecx + 8]
// 00703d9e  750a                 jne 0x703daa
// 00703da0  8bf1                 mov esi, ecx
// 00703da2  56                   push esi
// 00703da3  8bcf                 mov ecx, edi
// 00703da5  e866fae0ff           call 0x513810
// 00703daa  8b4604               mov eax, dword ptr [esi + 4]
// 00703dad  885830               mov byte ptr [eax + 0x30], bl
// 00703db0  8b4e04               mov ecx, dword ptr [esi + 4]
// 00703db3  8b5104               mov edx, dword ptr [ecx + 4]
// 00703db6  c6423000             mov byte ptr [edx + 0x30], 0
// 00703dba  8b4604               mov eax, dword ptr [esi + 4]
// 00703dbd  8b4804               mov ecx, dword ptr [eax + 4]
// 00703dc0  51                   push ecx
// 00703dc1  8bcf                 mov ecx, edi
// 00703dc3  e8d8eeffff           call 0x702ca0
// 00703dc8  eb7b                 jmp 0x703e45
// 00703dca  8b12                 mov edx, dword ptr [edx]
// 00703dcc  807a3000             cmp byte ptr [edx + 0x30], 0
// 00703dd0  7516                 jne 0x703de8
// 00703dd2  885930               mov byte ptr [ecx + 0x30], bl
// 00703dd5  885a30               mov byte ptr [edx + 0x30], bl
// 00703dd8  8b10                 mov edx, dword ptr [eax]
// 00703dda  8b4a04               mov ecx, dword ptr [edx + 4]
// 00703ddd  c6413000             mov byte ptr [ecx + 0x30], 0
// 00703de1  8b10                 mov edx, dword ptr [eax]
// 00703de3  8b7204               mov esi, dword ptr [edx + 4]
// 00703de6  eb5d                 jmp 0x703e45
// 00703de8  3b31                 cmp esi, dword ptr [ecx]
// 00703dea  750a                 jne 0x703df6
// 00703dec  8bf1                 mov esi, ecx
// 00703dee  56                   push esi
// 00703def  8bcf                 mov ecx, edi
// 00703df1  e8aaeeffff           call 0x702ca0
// 00703df6  8b4604               mov eax, dword ptr [esi + 4]
// 00703df9  885830               mov byte ptr [eax + 0x30], bl
// 00703dfc  8b4e04               mov ecx, dword ptr [esi + 4]
// 00703dff  8b5104               mov edx, dword ptr [ecx + 4]
// 00703e02  c6423000             mov byte ptr [edx + 0x30], 0
// 00703e06  8b4604               mov eax, dword ptr [esi + 4]
// 00703e09  8b4004               mov eax, dword ptr [eax + 4]
// 00703e0c  8b4808               mov ecx, dword ptr [eax + 8]
// 00703e0f  8b11                 mov edx, dword ptr [ecx]
// 00703e11  895008               mov dword ptr [eax + 8], edx
// 00703e14  8b11                 mov edx, dword ptr [ecx]
// 00703e16  807a3100             cmp byte ptr [edx + 0x31], 0
// 00703e1a  7503                 jne 0x703e1f
// 00703e1c  894204               mov dword ptr [edx + 4], eax
// 00703e1f  8b5004               mov edx, dword ptr [eax + 4]
// 00703e22  895104               mov dword ptr [ecx + 4], edx
// 00703e25  8b5718               mov edx, dword ptr [edi + 0x18]
// 00703e28  3b4204               cmp eax, dword ptr [edx + 4]
// 00703e2b  7505                 jne 0x703e32
// 00703e2d  894a04               mov dword ptr [edx + 4], ecx
// 00703e30  eb0e                 jmp 0x703e40
// 00703e32  8b5004               mov edx, dword ptr [eax + 4]
// 00703e35  3b02                 cmp eax, dword ptr [edx]
// 00703e37  7504                 jne 0x703e3d
// 00703e39  890a                 mov dword ptr [edx], ecx
// 00703e3b  eb03                 jmp 0x703e40
// 00703e3d  894a08               mov dword ptr [edx + 8], ecx
// 00703e40  8901                 mov dword ptr [ecx], eax
// 00703e42  894804               mov dword ptr [eax + 4], ecx
// 00703e45  8b4e04               mov ecx, dword ptr [esi + 4]
// 00703e48  80793000             cmp byte ptr [ecx + 0x30], 0
// 00703e4c  8d4604               lea eax, [esi + 4]
// 00703e4f  0f841bffffff         je 0x703d70
// 00703e55  8b5718               mov edx, dword ptr [edi + 0x18]
// 00703e58  8b4204               mov eax, dword ptr [edx + 4]
// 00703e5b  885830               mov byte ptr [eax + 0x30], bl
// 00703e5e  8b442464             mov eax, dword ptr [esp + 0x64]
// 00703e62  8b0f                 mov ecx, dword ptr [edi]
// 00703e64  5e                   pop esi
// 00703e65  896804               mov dword ptr [eax + 4], ebp
// 00703e68  5d                   pop ebp
// 00703e69  8908                 mov dword ptr [eax], ecx
// 00703e6b  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 00703e6f  5b                   pop ebx
// 00703e70  5f                   pop edi
// 00703e71  64890d00000000       mov dword ptr fs:[0], ecx
// 00703e78  83c450               add esp, 0x50
// 00703e7b  c21000               ret 0x10
// standard library map_int<pod32> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod32>
struct E { int v[8]; };
#include <map>
template class std::map<int, E>;
