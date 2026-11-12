// from server: 100% by auto
// roc 2009-06 004fd920  unit: RBX::Network::NetworkOwnerJob  size: 200 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004fd920
//
// 004fd920  56                   push esi
// 004fd921  8bf1                 mov esi, ecx
// 004fd923  8b06                 mov eax, dword ptr [esi]
// 004fd925  6a0c                 push 0xc
// 004fd927  85c0                 test eax, eax
// 004fd929  752f                 jne 0x4fd95a
// 004fd92b  e808b12100           call 0x718a38
// 004fd930  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004fd934  894604               mov dword ptr [esi + 4], eax
// 004fd937  8b11                 mov edx, dword ptr [ecx]
// 004fd939  8910                 mov dword ptr [eax], edx
// 004fd93b  8b4604               mov eax, dword ptr [esi + 4]
// 004fd93e  894008               mov dword ptr [eax + 8], eax
// 004fd941  8b4604               mov eax, dword ptr [esi + 4]
// 004fd944  894004               mov dword ptr [eax + 4], eax
// 004fd947  8b4604               mov eax, dword ptr [esi + 4]
// 004fd94a  83c404               add esp, 4
// 004fd94d  c70601000000         mov dword ptr [esi], 1
// 004fd953  894608               mov dword ptr [esi + 8], eax
// 004fd956  5e                   pop esi
// 004fd957  c20400               ret 4
// 004fd95a  83f801               cmp eax, 1
// 004fd95d  7547                 jne 0x4fd9a6
// 004fd95f  e8d4b02100           call 0x718a38
// 004fd964  8b4e04               mov ecx, dword ptr [esi + 4]
// 004fd967  894608               mov dword ptr [esi + 8], eax
// 004fd96a  894108               mov dword ptr [ecx + 8], eax
// 004fd96d  8b5604               mov edx, dword ptr [esi + 4]
// 004fd970  8b4608               mov eax, dword ptr [esi + 8]
// 004fd973  894204               mov dword ptr [edx + 4], eax
// 004fd976  8b5604               mov edx, dword ptr [esi + 4]
// 004fd979  8b4e08               mov ecx, dword ptr [esi + 8]
// 004fd97c  895104               mov dword ptr [ecx + 4], edx
// 004fd97f  8b4e04               mov ecx, dword ptr [esi + 4]
// 004fd982  8b4608               mov eax, dword ptr [esi + 8]
// 004fd985  894808               mov dword ptr [eax + 8], ecx
// 004fd988  8b5608               mov edx, dword ptr [esi + 8]
// 004fd98b  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004fd98f  8b08                 mov ecx, dword ptr [eax]
// 004fd991  890a                 mov dword ptr [edx], ecx
// 004fd993  8b5608               mov edx, dword ptr [esi + 8]
// 004fd996  83c404               add esp, 4
// 004fd999  895604               mov dword ptr [esi + 4], edx
// 004fd99c  c70602000000         mov dword ptr [esi], 2
// 004fd9a2  5e                   pop esi
// 004fd9a3  c20400               ret 4
// 004fd9a6  e88db02100           call 0x718a38
// 004fd9ab  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004fd9af  8b11                 mov edx, dword ptr [ecx]
// 004fd9b1  8910                 mov dword ptr [eax], edx
// 004fd9b3  8b4e08               mov ecx, dword ptr [esi + 8]
// 004fd9b6  8b5104               mov edx, dword ptr [ecx + 4]
// 004fd9b9  894208               mov dword ptr [edx + 8], eax
// 004fd9bc  8b4e08               mov ecx, dword ptr [esi + 8]
// 004fd9bf  8b5104               mov edx, dword ptr [ecx + 4]
// 004fd9c2  895004               mov dword ptr [eax + 4], edx
// 004fd9c5  8b4e08               mov ecx, dword ptr [esi + 8]
// 004fd9c8  894104               mov dword ptr [ecx + 4], eax
// 004fd9cb  8b5608               mov edx, dword ptr [esi + 8]
// 004fd9ce  895008               mov dword ptr [eax + 8], edx
// 004fd9d1  8b4e08               mov ecx, dword ptr [esi + 8]
// 004fd9d4  83c404               add esp, 4
// 004fd9d7  3b4e04               cmp ecx, dword ptr [esi + 4]
// 004fd9da  7506                 jne 0x4fd9e2
// 004fd9dc  894604               mov dword ptr [esi + 4], eax
// 004fd9df  894608               mov dword ptr [esi + 8], eax
// 004fd9e2  ff06                 inc dword ptr [esi]
// 004fd9e4  5e                   pop esi
// 004fd9e5  c20400               ret 4
// library openrbx-raknet/DS_HuffmanEncodingTree.cpp (function ?Insert@?$CircularLinkedList@PAUHuffmanEncodingTreeNode@@@DataStructures@@QAEXABQAUHuffmanEncodingTreeNode@@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet DS_HuffmanEncodingTree.cpp
