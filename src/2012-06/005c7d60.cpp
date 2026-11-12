// roc 2012-06 005c7d60  unit: RakNet::RakPeer  size: 186 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005c7d60
//
// 005c7d60  56                   push esi
// 005c7d61  8bf1                 mov esi, ecx
// 005c7d63  8b06                 mov eax, dword ptr [esi]
// 005c7d65  6a0c                 push 0xc
// 005c7d67  85c0                 test eax, eax
// 005c7d69  752f                 jne 0x5c7d9a
// 005c7d6b  e8aaa33b00           call 0x98211a
// 005c7d70  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005c7d74  894604               mov dword ptr [esi + 4], eax
// 005c7d77  8b11                 mov edx, dword ptr [ecx]
// 005c7d79  8910                 mov dword ptr [eax], edx
// 005c7d7b  8b4604               mov eax, dword ptr [esi + 4]
// 005c7d7e  894008               mov dword ptr [eax + 8], eax
// 005c7d81  8b4604               mov eax, dword ptr [esi + 4]
// 005c7d84  894004               mov dword ptr [eax + 4], eax
// 005c7d87  8b4604               mov eax, dword ptr [esi + 4]
// 005c7d8a  83c404               add esp, 4
// 005c7d8d  c70601000000         mov dword ptr [esi], 1
// 005c7d93  894608               mov dword ptr [esi + 8], eax
// 005c7d96  5e                   pop esi
// 005c7d97  c20400               ret 4
// 005c7d9a  83f801               cmp eax, 1
// 005c7d9d  7547                 jne 0x5c7de6
// 005c7d9f  e876a33b00           call 0x98211a
// 005c7da4  8b4e04               mov ecx, dword ptr [esi + 4]
// 005c7da7  894608               mov dword ptr [esi + 8], eax
// 005c7daa  894108               mov dword ptr [ecx + 8], eax
// 005c7dad  8b4608               mov eax, dword ptr [esi + 8]
// 005c7db0  8b5604               mov edx, dword ptr [esi + 4]
// 005c7db3  894204               mov dword ptr [edx + 4], eax
// 005c7db6  8b4e08               mov ecx, dword ptr [esi + 8]
// 005c7db9  8b5604               mov edx, dword ptr [esi + 4]
// 005c7dbc  895104               mov dword ptr [ecx + 4], edx
// 005c7dbf  8b4608               mov eax, dword ptr [esi + 8]
// 005c7dc2  8b4e04               mov ecx, dword ptr [esi + 4]
// 005c7dc5  894808               mov dword ptr [eax + 8], ecx
// 005c7dc8  8b44240c             mov eax, dword ptr [esp + 0xc]
// 005c7dcc  8b08                 mov ecx, dword ptr [eax]
// 005c7dce  8b5608               mov edx, dword ptr [esi + 8]
// 005c7dd1  890a                 mov dword ptr [edx], ecx
// 005c7dd3  8b4604               mov eax, dword ptr [esi + 4]
// 005c7dd6  83c404               add esp, 4
// 005c7dd9  c70602000000         mov dword ptr [esi], 2
// 005c7ddf  894608               mov dword ptr [esi + 8], eax
// 005c7de2  5e                   pop esi
// 005c7de3  c20400               ret 4
// 005c7de6  e82fa33b00           call 0x98211a
// 005c7deb  8b54240c             mov edx, dword ptr [esp + 0xc]
// 005c7def  8b0a                 mov ecx, dword ptr [edx]
// 005c7df1  8908                 mov dword ptr [eax], ecx
// 005c7df3  8b5608               mov edx, dword ptr [esi + 8]
// 005c7df6  895004               mov dword ptr [eax + 4], edx
// 005c7df9  8b4e08               mov ecx, dword ptr [esi + 8]
// 005c7dfc  8b5108               mov edx, dword ptr [ecx + 8]
// 005c7dff  895008               mov dword ptr [eax + 8], edx
// 005c7e02  8b4e08               mov ecx, dword ptr [esi + 8]
// 005c7e05  8b5108               mov edx, dword ptr [ecx + 8]
// 005c7e08  894204               mov dword ptr [edx + 4], eax
// 005c7e0b  8b4e08               mov ecx, dword ptr [esi + 8]
// 005c7e0e  83c404               add esp, 4
// 005c7e11  894108               mov dword ptr [ecx + 8], eax
// 005c7e14  ff06                 inc dword ptr [esi]
// 005c7e16  5e                   pop esi
// 005c7e17  c20400               ret 4
// library openrbx-raknet/DS_HuffmanEncodingTree.cpp (function ?Add@?$CircularLinkedList@PAUHuffmanEncodingTreeNode@@@DataStructures@@QAEAAPAUHuffmanEncodingTreeNode@@ABQAU3@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet DS_HuffmanEncodingTree.cpp
