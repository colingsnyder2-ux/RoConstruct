// from server: 100% by auto
// roc 2009-12 0053cad0  unit: RBX::Network::Replicator::ChangePropertyItem  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0053cad0
//
// 0053cad0  64a100000000         mov eax, dword ptr fs:[0]
// 0053cad6  6aff                 push -1
// 0053cad8  6812699500           push 0x956912
// 0053cadd  50                   push eax
// 0053cade  64892500000000       mov dword ptr fs:[0], esp
// 0053cae5  83ec44               sub esp, 0x44
// 0053cae8  57                   push edi
// 0053cae9  8bf9                 mov edi, ecx
// 0053caeb  817f1c54555515       cmp dword ptr [edi + 0x1c], 0x15555554
// 0053caf2  7259                 jb 0x53cb4d
// 0053caf4  6800f59900           push 0x99f500
// 0053caf9  8d4c2408             lea ecx, [esp + 8]
// 0053cafd  ff15f4b69800         call dword ptr [0x98b6f4]
// 0053cb03  8d4c2420             lea ecx, [esp + 0x20]
// 0053cb07  c744245000000000     mov dword ptr [esp + 0x50], 0
// 0053cb0f  ff1554b79800         call dword ptr [0x98b754]
// 0053cb15  8d442404             lea eax, [esp + 4]
// 0053cb19  50                   push eax
// 0053cb1a  8d4c2430             lea ecx, [esp + 0x30]
// 0053cb1e  c644245401           mov byte ptr [esp + 0x54], 1
// 0053cb23  c744242484f49900     mov dword ptr [esp + 0x24], 0x99f484
// 0053cb2b  ff15f0b69800         call dword ptr [0x98b6f0]
// 0053cb31  68e4efa800           push 0xa8efe4
// 0053cb36  8d4c2424             lea ecx, [esp + 0x24]
// 0053cb3a  51                   push ecx
// 0053cb3b  c644245800           mov byte ptr [esp + 0x58], 0
// 0053cb40  c744242890f49900     mov dword ptr [esp + 0x28], 0x99f490
// 0053cb48  e82b7d2b00           call 0x7f4878
// 0053cb4d  8b542464             mov edx, dword ptr [esp + 0x64]
// 0053cb51  8b4718               mov eax, dword ptr [edi + 0x18]
// 0053cb54  53                   push ebx
// 0053cb55  55                   push ebp
// 0053cb56  56                   push esi
// 0053cb57  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 0053cb5b  6a00                 push 0
// 0053cb5d  52                   push edx
// 0053cb5e  50                   push eax
// 0053cb5f  56                   push esi
// 0053cb60  50                   push eax
// 0053cb61  e81acbffff           call 0x539680
// 0053cb66  8be8                 mov ebp, eax
// 0053cb68  8b4718               mov eax, dword ptr [edi + 0x18]
// 0053cb6b  bb01000000           mov ebx, 1
// 0053cb70  015f1c               add dword ptr [edi + 0x1c], ebx
// 0053cb73  3bf0                 cmp esi, eax
// 0053cb75  7510                 jne 0x53cb87
// 0053cb77  896804               mov dword ptr [eax + 4], ebp
// 0053cb7a  8b4718               mov eax, dword ptr [edi + 0x18]
// 0053cb7d  8928                 mov dword ptr [eax], ebp
// 0053cb7f  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 0053cb82  896908               mov dword ptr [ecx + 8], ebp
// 0053cb85  eb22                 jmp 0x53cba9
// 0053cb87  807c246800           cmp byte ptr [esp + 0x68], 0
// 0053cb8c  740d                 je 0x53cb9b
// 0053cb8e  892e                 mov dword ptr [esi], ebp
// 0053cb90  8b4718               mov eax, dword ptr [edi + 0x18]
// 0053cb93  3b30                 cmp esi, dword ptr [eax]
// 0053cb95  7512                 jne 0x53cba9
// 0053cb97  8928                 mov dword ptr [eax], ebp
// 0053cb99  eb0e                 jmp 0x53cba9
// 0053cb9b  896e08               mov dword ptr [esi + 8], ebp
// 0053cb9e  8b4718               mov eax, dword ptr [edi + 0x18]
// 0053cba1  3b7008               cmp esi, dword ptr [eax + 8]
// 0053cba4  7503                 jne 0x53cba9
// 0053cba6  896808               mov dword ptr [eax + 8], ebp
// 0053cba9  8b5504               mov edx, dword ptr [ebp + 4]
// 0053cbac  807a1800             cmp byte ptr [edx + 0x18], 0
// 0053cbb0  8d4504               lea eax, [ebp + 4]
// 0053cbb3  8bf5                 mov esi, ebp
// 0053cbb5  0f85ea000000         jne 0x53cca5
// 0053cbbb  eb03                 jmp 0x53cbc0
// 0053cbbd  8d4900               lea ecx, [ecx]
// 0053cbc0  8b08                 mov ecx, dword ptr [eax]
// 0053cbc2  8b5104               mov edx, dword ptr [ecx + 4]
// 0053cbc5  3b0a                 cmp ecx, dword ptr [edx]
// 0053cbc7  7551                 jne 0x53cc1a
// 0053cbc9  8b5208               mov edx, dword ptr [edx + 8]
// 0053cbcc  807a1800             cmp byte ptr [edx + 0x18], 0
// 0053cbd0  7519                 jne 0x53cbeb
// 0053cbd2  885918               mov byte ptr [ecx + 0x18], bl
// 0053cbd5  885a18               mov byte ptr [edx + 0x18], bl
// 0053cbd8  8b10                 mov edx, dword ptr [eax]
// 0053cbda  8b4a04               mov ecx, dword ptr [edx + 4]
// 0053cbdd  c6411800             mov byte ptr [ecx + 0x18], 0
// 0053cbe1  8b10                 mov edx, dword ptr [eax]
// 0053cbe3  8b7204               mov esi, dword ptr [edx + 4]
// 0053cbe6  e9aa000000           jmp 0x53cc95
// 0053cbeb  3b7108               cmp esi, dword ptr [ecx + 8]
// 0053cbee  750a                 jne 0x53cbfa
// 0053cbf0  8bf1                 mov esi, ecx
// 0053cbf2  56                   push esi
// 0053cbf3  8bcf                 mov ecx, edi
// 0053cbf5  e816981200           call 0x666410
// 0053cbfa  8b4604               mov eax, dword ptr [esi + 4]
// 0053cbfd  885818               mov byte ptr [eax + 0x18], bl
// 0053cc00  8b4e04               mov ecx, dword ptr [esi + 4]
// 0053cc03  8b5104               mov edx, dword ptr [ecx + 4]
// 0053cc06  c6421800             mov byte ptr [edx + 0x18], 0
// 0053cc0a  8b4604               mov eax, dword ptr [esi + 4]
// 0053cc0d  8b4804               mov ecx, dword ptr [eax + 4]
// 0053cc10  51                   push ecx
// 0053cc11  8bcf                 mov ecx, edi
// 0053cc13  e82862efff           call 0x432e40
// 0053cc18  eb7b                 jmp 0x53cc95
// 0053cc1a  8b12                 mov edx, dword ptr [edx]
// 0053cc1c  807a1800             cmp byte ptr [edx + 0x18], 0
// 0053cc20  7516                 jne 0x53cc38
// 0053cc22  885918               mov byte ptr [ecx + 0x18], bl
// 0053cc25  885a18               mov byte ptr [edx + 0x18], bl
// 0053cc28  8b10                 mov edx, dword ptr [eax]
// 0053cc2a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0053cc2d  c6411800             mov byte ptr [ecx + 0x18], 0
// 0053cc31  8b10                 mov edx, dword ptr [eax]
// 0053cc33  8b7204               mov esi, dword ptr [edx + 4]
// 0053cc36  eb5d                 jmp 0x53cc95
// 0053cc38  3b31                 cmp esi, dword ptr [ecx]
// 0053cc3a  750a                 jne 0x53cc46
// 0053cc3c  8bf1                 mov esi, ecx
// 0053cc3e  56                   push esi
// 0053cc3f  8bcf                 mov ecx, edi
// 0053cc41  e8fa61efff           call 0x432e40
// 0053cc46  8b4604               mov eax, dword ptr [esi + 4]
// 0053cc49  885818               mov byte ptr [eax + 0x18], bl
// 0053cc4c  8b4e04               mov ecx, dword ptr [esi + 4]
// 0053cc4f  8b5104               mov edx, dword ptr [ecx + 4]
// 0053cc52  c6421800             mov byte ptr [edx + 0x18], 0
// 0053cc56  8b4604               mov eax, dword ptr [esi + 4]
// 0053cc59  8b4004               mov eax, dword ptr [eax + 4]
// 0053cc5c  8b4808               mov ecx, dword ptr [eax + 8]
// 0053cc5f  8b11                 mov edx, dword ptr [ecx]
// 0053cc61  895008               mov dword ptr [eax + 8], edx
// 0053cc64  8b11                 mov edx, dword ptr [ecx]
// 0053cc66  807a1900             cmp byte ptr [edx + 0x19], 0
// 0053cc6a  7503                 jne 0x53cc6f
// 0053cc6c  894204               mov dword ptr [edx + 4], eax
// 0053cc6f  8b5004               mov edx, dword ptr [eax + 4]
// 0053cc72  895104               mov dword ptr [ecx + 4], edx
// 0053cc75  8b5718               mov edx, dword ptr [edi + 0x18]
// 0053cc78  3b4204               cmp eax, dword ptr [edx + 4]
// 0053cc7b  7505                 jne 0x53cc82
// 0053cc7d  894a04               mov dword ptr [edx + 4], ecx
// 0053cc80  eb0e                 jmp 0x53cc90
// 0053cc82  8b5004               mov edx, dword ptr [eax + 4]
// 0053cc85  3b02                 cmp eax, dword ptr [edx]
// 0053cc87  7504                 jne 0x53cc8d
// 0053cc89  890a                 mov dword ptr [edx], ecx
// 0053cc8b  eb03                 jmp 0x53cc90
// 0053cc8d  894a08               mov dword ptr [edx + 8], ecx
// 0053cc90  8901                 mov dword ptr [ecx], eax
// 0053cc92  894804               mov dword ptr [eax + 4], ecx
// 0053cc95  8b4e04               mov ecx, dword ptr [esi + 4]
// 0053cc98  80791800             cmp byte ptr [ecx + 0x18], 0
// 0053cc9c  8d4604               lea eax, [esi + 4]
// 0053cc9f  0f841bffffff         je 0x53cbc0
// 0053cca5  8b5718               mov edx, dword ptr [edi + 0x18]
// 0053cca8  8b4204               mov eax, dword ptr [edx + 4]
// 0053ccab  885818               mov byte ptr [eax + 0x18], bl
// 0053ccae  8b442464             mov eax, dword ptr [esp + 0x64]
// 0053ccb2  8b0f                 mov ecx, dword ptr [edi]
// 0053ccb4  5e                   pop esi
// 0053ccb5  896804               mov dword ptr [eax + 4], ebp
// 0053ccb8  5d                   pop ebp
// 0053ccb9  8908                 mov dword ptr [eax], ecx
// 0053ccbb  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 0053ccbf  5b                   pop ebx
// 0053ccc0  5f                   pop edi
// 0053ccc1  64890d00000000       mov dword ptr fs:[0], ecx
// 0053ccc8  83c450               add esp, 0x50
// 0053cccb  c21000               ret 0x10
// standard library map_int<pod8> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod8>
struct E { int v[2]; };
#include <map>
template class std::map<int, E>;
