// from server: 100% by auto
// roc 2009-12 00553340  unit: RBX::Network::ClientReplicator  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00553340
//
// 00553340  8b5104               mov edx, dword ptr [ecx + 4]
// 00553343  56                   push esi
// 00553344  8b7108               mov esi, dword ptr [ecx + 8]
// 00553347  3bd6                 cmp edx, esi
// 00553349  7706                 ja 0x553351
// 0055334b  8bc6                 mov eax, esi
// 0055334d  2bc2                 sub eax, edx
// 0055334f  5e                   pop esi
// 00553350  c3                   ret 
// 00553351  8b410c               mov eax, dword ptr [ecx + 0xc]
// 00553354  2bc2                 sub eax, edx
// 00553356  03c6                 add eax, esi
// 00553358  5e                   pop esi
// 00553359  c3                   ret 
// library raknet-4.081/DS_HuffmanEncodingTree.cpp (function ?Size@?$Queue@PAUHuffmanEncodingTreeNode@@@DataStructures@@QBEIXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 DS_HuffmanEncodingTree.cpp
