// from server: 100% by auto
// roc 2010-06 005028c0  unit: RBX::Network::ClientReplicator  size: 186 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005028c0
//
// 005028c0  56                   push esi
// 005028c1  8bf1                 mov esi, ecx
// 005028c3  8b06                 mov eax, dword ptr [esi]
// 005028c5  6a0c                 push 0xc
// 005028c7  85c0                 test eax, eax
// 005028c9  752f                 jne 0x5028fa
// 005028cb  e8d0502a00           call 0x7a79a0
// 005028d0  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005028d4  894604               mov dword ptr [esi + 4], eax
// 005028d7  8b11                 mov edx, dword ptr [ecx]
// 005028d9  8910                 mov dword ptr [eax], edx
// 005028db  8b4604               mov eax, dword ptr [esi + 4]
// 005028de  894008               mov dword ptr [eax + 8], eax
// 005028e1  8b4604               mov eax, dword ptr [esi + 4]
// 005028e4  894004               mov dword ptr [eax + 4], eax
// 005028e7  8b4604               mov eax, dword ptr [esi + 4]
// 005028ea  83c404               add esp, 4
// 005028ed  c70601000000         mov dword ptr [esi], 1
// 005028f3  894608               mov dword ptr [esi + 8], eax
// 005028f6  5e                   pop esi
// 005028f7  c20400               ret 4
// 005028fa  83f801               cmp eax, 1
// 005028fd  7547                 jne 0x502946
// 005028ff  e89c502a00           call 0x7a79a0
// 00502904  8b4e04               mov ecx, dword ptr [esi + 4]
// 00502907  894608               mov dword ptr [esi + 8], eax
// 0050290a  894108               mov dword ptr [ecx + 8], eax
// 0050290d  8b4608               mov eax, dword ptr [esi + 8]
// 00502910  8b5604               mov edx, dword ptr [esi + 4]
// 00502913  894204               mov dword ptr [edx + 4], eax
// 00502916  8b4e08               mov ecx, dword ptr [esi + 8]
// 00502919  8b5604               mov edx, dword ptr [esi + 4]
// 0050291c  895104               mov dword ptr [ecx + 4], edx
// 0050291f  8b4608               mov eax, dword ptr [esi + 8]
// 00502922  8b4e04               mov ecx, dword ptr [esi + 4]
// 00502925  894808               mov dword ptr [eax + 8], ecx
// 00502928  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0050292c  8b08                 mov ecx, dword ptr [eax]
// 0050292e  8b5608               mov edx, dword ptr [esi + 8]
// 00502931  890a                 mov dword ptr [edx], ecx
// 00502933  8b4604               mov eax, dword ptr [esi + 4]
// 00502936  83c404               add esp, 4
// 00502939  c70602000000         mov dword ptr [esi], 2
// 0050293f  894608               mov dword ptr [esi + 8], eax
// 00502942  5e                   pop esi
// 00502943  c20400               ret 4
// 00502946  e855502a00           call 0x7a79a0
// 0050294b  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0050294f  8b0a                 mov ecx, dword ptr [edx]
// 00502951  8908                 mov dword ptr [eax], ecx
// 00502953  8b5608               mov edx, dword ptr [esi + 8]
// 00502956  895004               mov dword ptr [eax + 4], edx
// 00502959  8b4e08               mov ecx, dword ptr [esi + 8]
// 0050295c  8b5108               mov edx, dword ptr [ecx + 8]
// 0050295f  895008               mov dword ptr [eax + 8], edx
// 00502962  8b4e08               mov ecx, dword ptr [esi + 8]
// 00502965  8b5108               mov edx, dword ptr [ecx + 8]
// 00502968  894204               mov dword ptr [edx + 4], eax
// 0050296b  8b4e08               mov ecx, dword ptr [esi + 8]
// 0050296e  83c404               add esp, 4
// 00502971  894108               mov dword ptr [ecx + 8], eax
// 00502974  ff06                 inc dword ptr [esi]
// 00502976  5e                   pop esi
// 00502977  c20400               ret 4
// library openrbx-raknet/DS_HuffmanEncodingTree.cpp (function ?Add@?$CircularLinkedList@PAUHuffmanEncodingTreeNode@@@DataStructures@@QAEAAPAUHuffmanEncodingTreeNode@@ABQAU3@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet DS_HuffmanEncodingTree.cpp
