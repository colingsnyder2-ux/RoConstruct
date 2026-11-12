// from server: 100% by auto
// roc 2008-06 004ce1e0  unit: RBX::Network::PhysicsSender  size: 129 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004ce1e0
//
// 004ce1e0  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004ce1e4  57                   push edi
// 004ce1e5  8b39                 mov edi, dword ptr [ecx]
// 004ce1e7  85ff                 test edi, edi
// 004ce1e9  750e                 jne 0x4ce1f9
// 004ce1eb  8d442408             lea eax, [esp + 8]
// 004ce1ef  50                   push eax
// 004ce1f0  e80bfcffff           call 0x4cde00
// 004ce1f5  5f                   pop edi
// 004ce1f6  c20800               ret 8
// 004ce1f9  56                   push esi
// 004ce1fa  8b7104               mov esi, dword ptr [ecx + 4]
// 004ce1fd  85f6                 test esi, esi
// 004ce1ff  7403                 je 0x4ce204
// 004ce201  897108               mov dword ptr [ecx + 8], esi
// 004ce204  8b4108               mov eax, dword ptr [ecx + 8]
// 004ce207  8b00                 mov eax, dword ptr [eax]
// 004ce209  8b4004               mov eax, dword ptr [eax + 4]
// 004ce20c  53                   push ebx
// 004ce20d  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 004ce211  33d2                 xor edx, edx
// 004ce213  3b4304               cmp eax, dword ptr [ebx + 4]
// 004ce216  731f                 jae 0x4ce237
// 004ce218  8b4108               mov eax, dword ptr [ecx + 8]
// 004ce21b  8b4008               mov eax, dword ptr [eax + 8]
// 004ce21e  3bc6                 cmp eax, esi
// 004ce220  7403                 je 0x4ce225
// 004ce222  894108               mov dword ptr [ecx + 8], eax
// 004ce225  42                   inc edx
// 004ce226  3bd7                 cmp edx, edi
// 004ce228  741d                 je 0x4ce247
// 004ce22a  8b4108               mov eax, dword ptr [ecx + 8]
// 004ce22d  8b00                 mov eax, dword ptr [eax]
// 004ce22f  8b4004               mov eax, dword ptr [eax + 4]
// 004ce232  3b4304               cmp eax, dword ptr [ebx + 4]
// 004ce235  72e1                 jb 0x4ce218
// 004ce237  8d542410             lea edx, [esp + 0x10]
// 004ce23b  52                   push edx
// 004ce23c  e8bffbffff           call 0x4cde00
// 004ce241  5b                   pop ebx
// 004ce242  5e                   pop esi
// 004ce243  5f                   pop edi
// 004ce244  c20800               ret 8
// 004ce247  85f6                 test esi, esi
// 004ce249  7406                 je 0x4ce251
// 004ce24b  8b5604               mov edx, dword ptr [esi + 4]
// 004ce24e  895108               mov dword ptr [ecx + 8], edx
// 004ce251  8d442410             lea eax, [esp + 0x10]
// 004ce255  50                   push eax
// 004ce256  e875fcffff           call 0x4cded0
// 004ce25b  5b                   pop ebx
// 004ce25c  5e                   pop esi
// 004ce25d  5f                   pop edi
// 004ce25e  c20800               ret 8
// library openrbx-raknet/DS_HuffmanEncodingTree.cpp (function ?InsertNodeIntoSortedList@HuffmanEncodingTree@@ABEXPAUHuffmanEncodingTreeNode@@PAV?$LinkedList@PAUHuffmanEncodingTreeNode@@@DataStructures@@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet DS_HuffmanEncodingTree.cpp
