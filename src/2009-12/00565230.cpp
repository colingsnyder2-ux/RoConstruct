// from server: 100% by auto
// roc 2009-12 00565230  unit: CXTPRichRender::XTextHost  size: 129 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00565230
//
// 00565230  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00565234  57                   push edi
// 00565235  8b39                 mov edi, dword ptr [ecx]
// 00565237  85ff                 test edi, edi
// 00565239  750e                 jne 0x565249
// 0056523b  8d442408             lea eax, [esp + 8]
// 0056523f  50                   push eax
// 00565240  e8bbfcffff           call 0x564f00
// 00565245  5f                   pop edi
// 00565246  c20800               ret 8
// 00565249  56                   push esi
// 0056524a  8b7104               mov esi, dword ptr [ecx + 4]
// 0056524d  85f6                 test esi, esi
// 0056524f  7403                 je 0x565254
// 00565251  897108               mov dword ptr [ecx + 8], esi
// 00565254  8b4108               mov eax, dword ptr [ecx + 8]
// 00565257  8b00                 mov eax, dword ptr [eax]
// 00565259  8b4004               mov eax, dword ptr [eax + 4]
// 0056525c  53                   push ebx
// 0056525d  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 00565261  33d2                 xor edx, edx
// 00565263  3b4304               cmp eax, dword ptr [ebx + 4]
// 00565266  731f                 jae 0x565287
// 00565268  8b4108               mov eax, dword ptr [ecx + 8]
// 0056526b  8b4008               mov eax, dword ptr [eax + 8]
// 0056526e  3bc6                 cmp eax, esi
// 00565270  7403                 je 0x565275
// 00565272  894108               mov dword ptr [ecx + 8], eax
// 00565275  42                   inc edx
// 00565276  3bd7                 cmp edx, edi
// 00565278  741d                 je 0x565297
// 0056527a  8b4108               mov eax, dword ptr [ecx + 8]
// 0056527d  8b00                 mov eax, dword ptr [eax]
// 0056527f  8b4004               mov eax, dword ptr [eax + 4]
// 00565282  3b4304               cmp eax, dword ptr [ebx + 4]
// 00565285  72e1                 jb 0x565268
// 00565287  8d542410             lea edx, [esp + 0x10]
// 0056528b  52                   push edx
// 0056528c  e86ffcffff           call 0x564f00
// 00565291  5b                   pop ebx
// 00565292  5e                   pop esi
// 00565293  5f                   pop edi
// 00565294  c20800               ret 8
// 00565297  85f6                 test esi, esi
// 00565299  7406                 je 0x5652a1
// 0056529b  8b5604               mov edx, dword ptr [esi + 4]
// 0056529e  895108               mov dword ptr [ecx + 8], edx
// 005652a1  8d442410             lea eax, [esp + 0x10]
// 005652a5  50                   push eax
// 005652a6  e825fdffff           call 0x564fd0
// 005652ab  5b                   pop ebx
// 005652ac  5e                   pop esi
// 005652ad  5f                   pop edi
// 005652ae  c20800               ret 8
// library raknet-4.081/DS_HuffmanEncodingTree.cpp (function ?InsertNodeIntoSortedList@HuffmanEncodingTree@RakNet@@ABEXPAUHuffmanEncodingTreeNode@@PAV?$LinkedList@PAUHuffmanEncodingTreeNode@@@DataStructures@@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 DS_HuffmanEncodingTree.cpp
