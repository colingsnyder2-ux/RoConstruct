// from server: 100% by auto
// roc 2011-06 0052f320  unit: RBX::Network::ProfiledRakPeer  size: 186 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0052f320
//
// 0052f320  56                   push esi
// 0052f321  8bf1                 mov esi, ecx
// 0052f323  8b06                 mov eax, dword ptr [esi]
// 0052f325  6a0c                 push 0xc
// 0052f327  85c0                 test eax, eax
// 0052f329  752f                 jne 0x52f35a
// 0052f32b  e82ead2d00           call 0x80a05e
// 0052f330  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0052f334  894604               mov dword ptr [esi + 4], eax
// 0052f337  8b11                 mov edx, dword ptr [ecx]
// 0052f339  8910                 mov dword ptr [eax], edx
// 0052f33b  8b4604               mov eax, dword ptr [esi + 4]
// 0052f33e  894008               mov dword ptr [eax + 8], eax
// 0052f341  8b4604               mov eax, dword ptr [esi + 4]
// 0052f344  894004               mov dword ptr [eax + 4], eax
// 0052f347  8b4604               mov eax, dword ptr [esi + 4]
// 0052f34a  83c404               add esp, 4
// 0052f34d  c70601000000         mov dword ptr [esi], 1
// 0052f353  894608               mov dword ptr [esi + 8], eax
// 0052f356  5e                   pop esi
// 0052f357  c20400               ret 4
// 0052f35a  83f801               cmp eax, 1
// 0052f35d  7547                 jne 0x52f3a6
// 0052f35f  e8faac2d00           call 0x80a05e
// 0052f364  8b4e04               mov ecx, dword ptr [esi + 4]
// 0052f367  894608               mov dword ptr [esi + 8], eax
// 0052f36a  894108               mov dword ptr [ecx + 8], eax
// 0052f36d  8b4608               mov eax, dword ptr [esi + 8]
// 0052f370  8b5604               mov edx, dword ptr [esi + 4]
// 0052f373  894204               mov dword ptr [edx + 4], eax
// 0052f376  8b4e08               mov ecx, dword ptr [esi + 8]
// 0052f379  8b5604               mov edx, dword ptr [esi + 4]
// 0052f37c  895104               mov dword ptr [ecx + 4], edx
// 0052f37f  8b4608               mov eax, dword ptr [esi + 8]
// 0052f382  8b4e04               mov ecx, dword ptr [esi + 4]
// 0052f385  894808               mov dword ptr [eax + 8], ecx
// 0052f388  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0052f38c  8b08                 mov ecx, dword ptr [eax]
// 0052f38e  8b5608               mov edx, dword ptr [esi + 8]
// 0052f391  890a                 mov dword ptr [edx], ecx
// 0052f393  8b4604               mov eax, dword ptr [esi + 4]
// 0052f396  83c404               add esp, 4
// 0052f399  c70602000000         mov dword ptr [esi], 2
// 0052f39f  894608               mov dword ptr [esi + 8], eax
// 0052f3a2  5e                   pop esi
// 0052f3a3  c20400               ret 4
// 0052f3a6  e8b3ac2d00           call 0x80a05e
// 0052f3ab  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0052f3af  8b0a                 mov ecx, dword ptr [edx]
// 0052f3b1  8908                 mov dword ptr [eax], ecx
// 0052f3b3  8b5608               mov edx, dword ptr [esi + 8]
// 0052f3b6  895004               mov dword ptr [eax + 4], edx
// 0052f3b9  8b4e08               mov ecx, dword ptr [esi + 8]
// 0052f3bc  8b5108               mov edx, dword ptr [ecx + 8]
// 0052f3bf  895008               mov dword ptr [eax + 8], edx
// 0052f3c2  8b4e08               mov ecx, dword ptr [esi + 8]
// 0052f3c5  8b5108               mov edx, dword ptr [ecx + 8]
// 0052f3c8  894204               mov dword ptr [edx + 4], eax
// 0052f3cb  8b4e08               mov ecx, dword ptr [esi + 8]
// 0052f3ce  83c404               add esp, 4
// 0052f3d1  894108               mov dword ptr [ecx + 8], eax
// 0052f3d4  ff06                 inc dword ptr [esi]
// 0052f3d6  5e                   pop esi
// 0052f3d7  c20400               ret 4
// library openrbx-raknet/DS_HuffmanEncodingTree.cpp (function ?Add@?$CircularLinkedList@PAUHuffmanEncodingTreeNode@@@DataStructures@@QAEAAPAUHuffmanEncodingTreeNode@@ABQAU3@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet DS_HuffmanEncodingTree.cpp
