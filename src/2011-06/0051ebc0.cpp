// from server: 100% by auto
// roc 2011-06 0051ebc0  unit: RBX::Network::InterpolatingPhysicsReceiver::Job  size: 200 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0051ebc0
//
// 0051ebc0  56                   push esi
// 0051ebc1  8bf1                 mov esi, ecx
// 0051ebc3  8b06                 mov eax, dword ptr [esi]
// 0051ebc5  6a0c                 push 0xc
// 0051ebc7  85c0                 test eax, eax
// 0051ebc9  752f                 jne 0x51ebfa
// 0051ebcb  e88eb42e00           call 0x80a05e
// 0051ebd0  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0051ebd4  894604               mov dword ptr [esi + 4], eax
// 0051ebd7  8b11                 mov edx, dword ptr [ecx]
// 0051ebd9  8910                 mov dword ptr [eax], edx
// 0051ebdb  8b4604               mov eax, dword ptr [esi + 4]
// 0051ebde  894008               mov dword ptr [eax + 8], eax
// 0051ebe1  8b4604               mov eax, dword ptr [esi + 4]
// 0051ebe4  894004               mov dword ptr [eax + 4], eax
// 0051ebe7  8b4604               mov eax, dword ptr [esi + 4]
// 0051ebea  83c404               add esp, 4
// 0051ebed  c70601000000         mov dword ptr [esi], 1
// 0051ebf3  894608               mov dword ptr [esi + 8], eax
// 0051ebf6  5e                   pop esi
// 0051ebf7  c20400               ret 4
// 0051ebfa  83f801               cmp eax, 1
// 0051ebfd  7547                 jne 0x51ec46
// 0051ebff  e85ab42e00           call 0x80a05e
// 0051ec04  8b4e04               mov ecx, dword ptr [esi + 4]
// 0051ec07  894608               mov dword ptr [esi + 8], eax
// 0051ec0a  894108               mov dword ptr [ecx + 8], eax
// 0051ec0d  8b5604               mov edx, dword ptr [esi + 4]
// 0051ec10  8b4608               mov eax, dword ptr [esi + 8]
// 0051ec13  894204               mov dword ptr [edx + 4], eax
// 0051ec16  8b5604               mov edx, dword ptr [esi + 4]
// 0051ec19  8b4e08               mov ecx, dword ptr [esi + 8]
// 0051ec1c  895104               mov dword ptr [ecx + 4], edx
// 0051ec1f  8b4e04               mov ecx, dword ptr [esi + 4]
// 0051ec22  8b4608               mov eax, dword ptr [esi + 8]
// 0051ec25  894808               mov dword ptr [eax + 8], ecx
// 0051ec28  8b5608               mov edx, dword ptr [esi + 8]
// 0051ec2b  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0051ec2f  8b08                 mov ecx, dword ptr [eax]
// 0051ec31  890a                 mov dword ptr [edx], ecx
// 0051ec33  8b5608               mov edx, dword ptr [esi + 8]
// 0051ec36  83c404               add esp, 4
// 0051ec39  895604               mov dword ptr [esi + 4], edx
// 0051ec3c  c70602000000         mov dword ptr [esi], 2
// 0051ec42  5e                   pop esi
// 0051ec43  c20400               ret 4
// 0051ec46  e813b42e00           call 0x80a05e
// 0051ec4b  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0051ec4f  8b11                 mov edx, dword ptr [ecx]
// 0051ec51  8910                 mov dword ptr [eax], edx
// 0051ec53  8b4e08               mov ecx, dword ptr [esi + 8]
// 0051ec56  8b5104               mov edx, dword ptr [ecx + 4]
// 0051ec59  894208               mov dword ptr [edx + 8], eax
// 0051ec5c  8b4e08               mov ecx, dword ptr [esi + 8]
// 0051ec5f  8b5104               mov edx, dword ptr [ecx + 4]
// 0051ec62  895004               mov dword ptr [eax + 4], edx
// 0051ec65  8b4e08               mov ecx, dword ptr [esi + 8]
// 0051ec68  894104               mov dword ptr [ecx + 4], eax
// 0051ec6b  8b5608               mov edx, dword ptr [esi + 8]
// 0051ec6e  895008               mov dword ptr [eax + 8], edx
// 0051ec71  8b4e08               mov ecx, dword ptr [esi + 8]
// 0051ec74  83c404               add esp, 4
// 0051ec77  3b4e04               cmp ecx, dword ptr [esi + 4]
// 0051ec7a  7506                 jne 0x51ec82
// 0051ec7c  894604               mov dword ptr [esi + 4], eax
// 0051ec7f  894608               mov dword ptr [esi + 8], eax
// 0051ec82  ff06                 inc dword ptr [esi]
// 0051ec84  5e                   pop esi
// 0051ec85  c20400               ret 4
// library openrbx-raknet/DS_HuffmanEncodingTree.cpp (function ?Insert@?$CircularLinkedList@PAUHuffmanEncodingTreeNode@@@DataStructures@@QAEXABQAUHuffmanEncodingTreeNode@@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet DS_HuffmanEncodingTree.cpp
