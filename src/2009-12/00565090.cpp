// from server: 100% by auto
// roc 2009-12 00565090  unit: CXTPRichRender::XTextHost  size: 74 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00565090
//
// 00565090  57                   push edi
// 00565091  8bf9                 mov edi, ecx
// 00565093  8b07                 mov eax, dword ptr [edi]
// 00565095  85c0                 test eax, eax
// 00565097  743f                 je 0x5650d8
// 00565099  83f801               cmp eax, 1
// 0056509c  750e                 jne 0x5650ac
// 0056509e  8b4704               mov eax, dword ptr [edi + 4]
// 005650a1  50                   push eax
// 005650a2  e8b3e72800           call 0x7f385a
// 005650a7  83c404               add esp, 4
// 005650aa  eb18                 jmp 0x5650c4
// 005650ac  56                   push esi
// 005650ad  8b7704               mov esi, dword ptr [edi + 4]
// 005650b0  8bc6                 mov eax, esi
// 005650b2  8b7608               mov esi, dword ptr [esi + 8]
// 005650b5  50                   push eax
// 005650b6  e89fe72800           call 0x7f385a
// 005650bb  83c404               add esp, 4
// 005650be  3b7704               cmp esi, dword ptr [edi + 4]
// 005650c1  75ed                 jne 0x5650b0
// 005650c3  5e                   pop esi
// 005650c4  c70700000000         mov dword ptr [edi], 0
// 005650ca  c7470400000000       mov dword ptr [edi + 4], 0
// 005650d1  c7470800000000       mov dword ptr [edi + 8], 0
// 005650d8  5f                   pop edi
// 005650d9  c3                   ret 
// library raknet-4.081/DS_HuffmanEncodingTree.cpp (function ?Clear@?$CircularLinkedList@PAUHuffmanEncodingTreeNode@@@DataStructures@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 DS_HuffmanEncodingTree.cpp
