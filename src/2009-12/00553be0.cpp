// from server: 100% by auto
// roc 2009-12 00553be0  unit: RBX::Network::ClientReplicator  size: 16 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00553be0
//
// 00553be0  83790c00             cmp dword ptr [ecx + 0xc], 0
// 00553be4  7609                 jbe 0x553bef
// 00553be6  8b01                 mov eax, dword ptr [ecx]
// 00553be8  50                   push eax
// 00553be9  e818ff2900           call 0x7f3b06
// 00553bee  59                   pop ecx
// 00553bef  c3                   ret 
// library raknet-4.081/DS_HuffmanEncodingTree.cpp (function ??1?$Queue@PAUHuffmanEncodingTreeNode@@@DataStructures@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 DS_HuffmanEncodingTree.cpp
