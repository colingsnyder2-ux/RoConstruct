// from server: 100% by auto
// roc 2011-06 0052f640  unit: RBX::Network::ProfiledRakPeer  size: 95 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0052f640
//
// 0052f640  56                   push esi
// 0052f641  8bf1                 mov esi, ecx
// 0052f643  8b06                 mov eax, dword ptr [esi]
// 0052f645  57                   push edi
// 0052f646  33ff                 xor edi, edi
// 0052f648  3bc7                 cmp eax, edi
// 0052f64a  7450                 je 0x52f69c
// 0052f64c  83f801               cmp eax, 1
// 0052f64f  7517                 jne 0x52f668
// 0052f651  8b4604               mov eax, dword ptr [esi + 4]
// 0052f654  50                   push eax
// 0052f655  e8fea92d00           call 0x80a058
// 0052f65a  83c404               add esp, 4
// 0052f65d  897e04               mov dword ptr [esi + 4], edi
// 0052f660  893e                 mov dword ptr [esi], edi
// 0052f662  897e08               mov dword ptr [esi + 8], edi
// 0052f665  5f                   pop edi
// 0052f666  5e                   pop esi
// 0052f667  c3                   ret 
// 0052f668  8b4608               mov eax, dword ptr [esi + 8]
// 0052f66b  8b4804               mov ecx, dword ptr [eax + 4]
// 0052f66e  8b5008               mov edx, dword ptr [eax + 8]
// 0052f671  895108               mov dword ptr [ecx + 8], edx
// 0052f674  8b4608               mov eax, dword ptr [esi + 8]
// 0052f677  8b4808               mov ecx, dword ptr [eax + 8]
// 0052f67a  8b5004               mov edx, dword ptr [eax + 4]
// 0052f67d  895104               mov dword ptr [ecx + 4], edx
// 0052f680  8b4608               mov eax, dword ptr [esi + 8]
// 0052f683  8b7808               mov edi, dword ptr [eax + 8]
// 0052f686  3b4604               cmp eax, dword ptr [esi + 4]
// 0052f689  7503                 jne 0x52f68e
// 0052f68b  897e04               mov dword ptr [esi + 4], edi
// 0052f68e  50                   push eax
// 0052f68f  e8c4a92d00           call 0x80a058
// 0052f694  83c404               add esp, 4
// 0052f697  ff0e                 dec dword ptr [esi]
// 0052f699  897e08               mov dword ptr [esi + 8], edi
// 0052f69c  5f                   pop edi
// 0052f69d  5e                   pop esi
// 0052f69e  c3                   ret 
// library openrbx-raknet/DS_HuffmanEncodingTree.cpp (function ?Del@?$CircularLinkedList@PAUHuffmanEncodingTreeNode@@@DataStructures@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet DS_HuffmanEncodingTree.cpp
