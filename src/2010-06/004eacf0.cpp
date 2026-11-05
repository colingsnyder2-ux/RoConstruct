// from server: 100% by auto
// roc 2010-06 004eacf0  unit: RBX::Network::Replicator::ChangePropertyItem  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004eacf0
//
// 004eacf0  64a100000000         mov eax, dword ptr fs:[0]
// 004eacf6  6aff                 push -1
// 004eacf8  68e22f9a00           push 0x9a2fe2
// 004eacfd  50                   push eax
// 004eacfe  64892500000000       mov dword ptr fs:[0], esp
// 004ead05  83ec44               sub esp, 0x44
// 004ead08  57                   push edi
// 004ead09  8bf9                 mov edi, ecx
// 004ead0b  817f1c54555515       cmp dword ptr [edi + 0x1c], 0x15555554
// 004ead12  7259                 jb 0x4ead6d
// 004ead14  68a800a000           push 0xa000a8
// 004ead19  8d4c2408             lea ecx, [esp + 8]
// 004ead1d  ff1510a49e00         call dword ptr [0x9ea410]
// 004ead23  8d4c2420             lea ecx, [esp + 0x20]
// 004ead27  c744245000000000     mov dword ptr [esp + 0x50], 0
// 004ead2f  ff1518a99e00         call dword ptr [0x9ea918]
// 004ead35  8d442404             lea eax, [esp + 4]
// 004ead39  50                   push eax
// 004ead3a  8d4c2430             lea ecx, [esp + 0x30]
// 004ead3e  c644245401           mov byte ptr [esp + 0x54], 1
// 004ead43  c74424242c00a000     mov dword ptr [esp + 0x24], 0xa0002c
// 004ead4b  ff150ca49e00         call dword ptr [0x9ea40c]
// 004ead51  68601bb000           push 0xb01b60
// 004ead56  8d4c2424             lea ecx, [esp + 0x24]
// 004ead5a  51                   push ecx
// 004ead5b  c644245800           mov byte ptr [esp + 0x58], 0
// 004ead60  c74424283800a000     mov dword ptr [esp + 0x28], 0xa00038
// 004ead68  e845dc2b00           call 0x7a89b2
// 004ead6d  8b542464             mov edx, dword ptr [esp + 0x64]
// 004ead71  8b4718               mov eax, dword ptr [edi + 0x18]
// 004ead74  53                   push ebx
// 004ead75  55                   push ebp
// 004ead76  56                   push esi
// 004ead77  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 004ead7b  6a00                 push 0
// 004ead7d  52                   push edx
// 004ead7e  50                   push eax
// 004ead7f  56                   push esi
// 004ead80  50                   push eax
// 004ead81  e8fa7a1300           call 0x622880
// 004ead86  8be8                 mov ebp, eax
// 004ead88  8b4718               mov eax, dword ptr [edi + 0x18]
// 004ead8b  bb01000000           mov ebx, 1
// 004ead90  015f1c               add dword ptr [edi + 0x1c], ebx
// 004ead93  3bf0                 cmp esi, eax
// 004ead95  7510                 jne 0x4eada7
// 004ead97  896804               mov dword ptr [eax + 4], ebp
// 004ead9a  8b4718               mov eax, dword ptr [edi + 0x18]
// 004ead9d  8928                 mov dword ptr [eax], ebp
// 004ead9f  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 004eada2  896908               mov dword ptr [ecx + 8], ebp
// 004eada5  eb22                 jmp 0x4eadc9
// 004eada7  807c246800           cmp byte ptr [esp + 0x68], 0
// 004eadac  740d                 je 0x4eadbb
// 004eadae  892e                 mov dword ptr [esi], ebp
// 004eadb0  8b4718               mov eax, dword ptr [edi + 0x18]
// 004eadb3  3b30                 cmp esi, dword ptr [eax]
// 004eadb5  7512                 jne 0x4eadc9
// 004eadb7  8928                 mov dword ptr [eax], ebp
// 004eadb9  eb0e                 jmp 0x4eadc9
// 004eadbb  896e08               mov dword ptr [esi + 8], ebp
// 004eadbe  8b4718               mov eax, dword ptr [edi + 0x18]
// 004eadc1  3b7008               cmp esi, dword ptr [eax + 8]
// 004eadc4  7503                 jne 0x4eadc9
// 004eadc6  896808               mov dword ptr [eax + 8], ebp
// 004eadc9  8b5504               mov edx, dword ptr [ebp + 4]
// 004eadcc  807a1800             cmp byte ptr [edx + 0x18], 0
// 004eadd0  8d4504               lea eax, [ebp + 4]
// 004eadd3  8bf5                 mov esi, ebp
// 004eadd5  0f85ea000000         jne 0x4eaec5
// 004eaddb  eb03                 jmp 0x4eade0
// 004eaddd  8d4900               lea ecx, [ecx]
// 004eade0  8b08                 mov ecx, dword ptr [eax]
// 004eade2  8b5104               mov edx, dword ptr [ecx + 4]
// 004eade5  3b0a                 cmp ecx, dword ptr [edx]
// 004eade7  7551                 jne 0x4eae3a
// 004eade9  8b5208               mov edx, dword ptr [edx + 8]
// 004eadec  807a1800             cmp byte ptr [edx + 0x18], 0
// 004eadf0  7519                 jne 0x4eae0b
// 004eadf2  885918               mov byte ptr [ecx + 0x18], bl
// 004eadf5  885a18               mov byte ptr [edx + 0x18], bl
// 004eadf8  8b10                 mov edx, dword ptr [eax]
// 004eadfa  8b4a04               mov ecx, dword ptr [edx + 4]
// 004eadfd  c6411800             mov byte ptr [ecx + 0x18], 0
// 004eae01  8b10                 mov edx, dword ptr [eax]
// 004eae03  8b7204               mov esi, dword ptr [edx + 4]
// 004eae06  e9aa000000           jmp 0x4eaeb5
// 004eae0b  3b7108               cmp esi, dword ptr [ecx + 8]
// 004eae0e  750a                 jne 0x4eae1a
// 004eae10  8bf1                 mov esi, ecx
// 004eae12  56                   push esi
// 004eae13  8bcf                 mov ecx, edi
// 004eae15  e8c6baffff           call 0x4e68e0
// 004eae1a  8b4604               mov eax, dword ptr [esi + 4]
// 004eae1d  885818               mov byte ptr [eax + 0x18], bl
// 004eae20  8b4e04               mov ecx, dword ptr [esi + 4]
// 004eae23  8b5104               mov edx, dword ptr [ecx + 4]
// 004eae26  c6421800             mov byte ptr [edx + 0x18], 0
// 004eae2a  8b4604               mov eax, dword ptr [esi + 4]
// 004eae2d  8b4804               mov ecx, dword ptr [eax + 4]
// 004eae30  51                   push ecx
// 004eae31  8bcf                 mov ecx, edi
// 004eae33  e878771000           call 0x5f25b0
// 004eae38  eb7b                 jmp 0x4eaeb5
// 004eae3a  8b12                 mov edx, dword ptr [edx]
// 004eae3c  807a1800             cmp byte ptr [edx + 0x18], 0
// 004eae40  7516                 jne 0x4eae58
// 004eae42  885918               mov byte ptr [ecx + 0x18], bl
// 004eae45  885a18               mov byte ptr [edx + 0x18], bl
// 004eae48  8b10                 mov edx, dword ptr [eax]
// 004eae4a  8b4a04               mov ecx, dword ptr [edx + 4]
// 004eae4d  c6411800             mov byte ptr [ecx + 0x18], 0
// 004eae51  8b10                 mov edx, dword ptr [eax]
// 004eae53  8b7204               mov esi, dword ptr [edx + 4]
// 004eae56  eb5d                 jmp 0x4eaeb5
// 004eae58  3b31                 cmp esi, dword ptr [ecx]
// 004eae5a  750a                 jne 0x4eae66
// 004eae5c  8bf1                 mov esi, ecx
// 004eae5e  56                   push esi
// 004eae5f  8bcf                 mov ecx, edi
// 004eae61  e84a771000           call 0x5f25b0
// 004eae66  8b4604               mov eax, dword ptr [esi + 4]
// 004eae69  885818               mov byte ptr [eax + 0x18], bl
// 004eae6c  8b4e04               mov ecx, dword ptr [esi + 4]
// 004eae6f  8b5104               mov edx, dword ptr [ecx + 4]
// 004eae72  c6421800             mov byte ptr [edx + 0x18], 0
// 004eae76  8b4604               mov eax, dword ptr [esi + 4]
// 004eae79  8b4004               mov eax, dword ptr [eax + 4]
// 004eae7c  8b4808               mov ecx, dword ptr [eax + 8]
// 004eae7f  8b11                 mov edx, dword ptr [ecx]
// 004eae81  895008               mov dword ptr [eax + 8], edx
// 004eae84  8b11                 mov edx, dword ptr [ecx]
// 004eae86  807a1900             cmp byte ptr [edx + 0x19], 0
// 004eae8a  7503                 jne 0x4eae8f
// 004eae8c  894204               mov dword ptr [edx + 4], eax
// 004eae8f  8b5004               mov edx, dword ptr [eax + 4]
// 004eae92  895104               mov dword ptr [ecx + 4], edx
// 004eae95  8b5718               mov edx, dword ptr [edi + 0x18]
// 004eae98  3b4204               cmp eax, dword ptr [edx + 4]
// 004eae9b  7505                 jne 0x4eaea2
// 004eae9d  894a04               mov dword ptr [edx + 4], ecx
// 004eaea0  eb0e                 jmp 0x4eaeb0
// 004eaea2  8b5004               mov edx, dword ptr [eax + 4]
// 004eaea5  3b02                 cmp eax, dword ptr [edx]
// 004eaea7  7504                 jne 0x4eaead
// 004eaea9  890a                 mov dword ptr [edx], ecx
// 004eaeab  eb03                 jmp 0x4eaeb0
// 004eaead  894a08               mov dword ptr [edx + 8], ecx
// 004eaeb0  8901                 mov dword ptr [ecx], eax
// 004eaeb2  894804               mov dword ptr [eax + 4], ecx
// 004eaeb5  8b4e04               mov ecx, dword ptr [esi + 4]
// 004eaeb8  80791800             cmp byte ptr [ecx + 0x18], 0
// 004eaebc  8d4604               lea eax, [esi + 4]
// 004eaebf  0f841bffffff         je 0x4eade0
// 004eaec5  8b5718               mov edx, dword ptr [edi + 0x18]
// 004eaec8  8b4204               mov eax, dword ptr [edx + 4]
// 004eaecb  885818               mov byte ptr [eax + 0x18], bl
// 004eaece  8b442464             mov eax, dword ptr [esp + 0x64]
// 004eaed2  8b0f                 mov ecx, dword ptr [edi]
// 004eaed4  5e                   pop esi
// 004eaed5  896804               mov dword ptr [eax + 4], ebp
// 004eaed8  5d                   pop ebp
// 004eaed9  8908                 mov dword ptr [eax], ecx
// 004eaedb  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 004eaedf  5b                   pop ebx
// 004eaee0  5f                   pop edi
// 004eaee1  64890d00000000       mov dword ptr fs:[0], ecx
// 004eaee8  83c450               add esp, 0x50
// 004eaeeb  c21000               ret 0x10
// standard library map_int<pod8> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod8>
struct E { int v[2]; };
#include <map>
template class std::map<int, E>;
