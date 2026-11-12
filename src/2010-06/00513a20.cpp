// from server: 100% by auto
// roc 2010-06 00513a20  unit: RBX::Network::InterpolatingPhysicsReceiver::Job  size: 200 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00513a20
//
// 00513a20  56                   push esi
// 00513a21  8bf1                 mov esi, ecx
// 00513a23  8b06                 mov eax, dword ptr [esi]
// 00513a25  6a0c                 push 0xc
// 00513a27  85c0                 test eax, eax
// 00513a29  752f                 jne 0x513a5a
// 00513a2b  e8703f2900           call 0x7a79a0
// 00513a30  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00513a34  894604               mov dword ptr [esi + 4], eax
// 00513a37  8b11                 mov edx, dword ptr [ecx]
// 00513a39  8910                 mov dword ptr [eax], edx
// 00513a3b  8b4604               mov eax, dword ptr [esi + 4]
// 00513a3e  894008               mov dword ptr [eax + 8], eax
// 00513a41  8b4604               mov eax, dword ptr [esi + 4]
// 00513a44  894004               mov dword ptr [eax + 4], eax
// 00513a47  8b4604               mov eax, dword ptr [esi + 4]
// 00513a4a  83c404               add esp, 4
// 00513a4d  c70601000000         mov dword ptr [esi], 1
// 00513a53  894608               mov dword ptr [esi + 8], eax
// 00513a56  5e                   pop esi
// 00513a57  c20400               ret 4
// 00513a5a  83f801               cmp eax, 1
// 00513a5d  7547                 jne 0x513aa6
// 00513a5f  e83c3f2900           call 0x7a79a0
// 00513a64  8b4e04               mov ecx, dword ptr [esi + 4]
// 00513a67  894608               mov dword ptr [esi + 8], eax
// 00513a6a  894108               mov dword ptr [ecx + 8], eax
// 00513a6d  8b5604               mov edx, dword ptr [esi + 4]
// 00513a70  8b4608               mov eax, dword ptr [esi + 8]
// 00513a73  894204               mov dword ptr [edx + 4], eax
// 00513a76  8b5604               mov edx, dword ptr [esi + 4]
// 00513a79  8b4e08               mov ecx, dword ptr [esi + 8]
// 00513a7c  895104               mov dword ptr [ecx + 4], edx
// 00513a7f  8b4e04               mov ecx, dword ptr [esi + 4]
// 00513a82  8b4608               mov eax, dword ptr [esi + 8]
// 00513a85  894808               mov dword ptr [eax + 8], ecx
// 00513a88  8b5608               mov edx, dword ptr [esi + 8]
// 00513a8b  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00513a8f  8b08                 mov ecx, dword ptr [eax]
// 00513a91  890a                 mov dword ptr [edx], ecx
// 00513a93  8b5608               mov edx, dword ptr [esi + 8]
// 00513a96  83c404               add esp, 4
// 00513a99  895604               mov dword ptr [esi + 4], edx
// 00513a9c  c70602000000         mov dword ptr [esi], 2
// 00513aa2  5e                   pop esi
// 00513aa3  c20400               ret 4
// 00513aa6  e8f53e2900           call 0x7a79a0
// 00513aab  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00513aaf  8b11                 mov edx, dword ptr [ecx]
// 00513ab1  8910                 mov dword ptr [eax], edx
// 00513ab3  8b4e08               mov ecx, dword ptr [esi + 8]
// 00513ab6  8b5104               mov edx, dword ptr [ecx + 4]
// 00513ab9  894208               mov dword ptr [edx + 8], eax
// 00513abc  8b4e08               mov ecx, dword ptr [esi + 8]
// 00513abf  8b5104               mov edx, dword ptr [ecx + 4]
// 00513ac2  895004               mov dword ptr [eax + 4], edx
// 00513ac5  8b4e08               mov ecx, dword ptr [esi + 8]
// 00513ac8  894104               mov dword ptr [ecx + 4], eax
// 00513acb  8b5608               mov edx, dword ptr [esi + 8]
// 00513ace  895008               mov dword ptr [eax + 8], edx
// 00513ad1  8b4e08               mov ecx, dword ptr [esi + 8]
// 00513ad4  83c404               add esp, 4
// 00513ad7  3b4e04               cmp ecx, dword ptr [esi + 4]
// 00513ada  7506                 jne 0x513ae2
// 00513adc  894604               mov dword ptr [esi + 4], eax
// 00513adf  894608               mov dword ptr [esi + 8], eax
// 00513ae2  ff06                 inc dword ptr [esi]
// 00513ae4  5e                   pop esi
// 00513ae5  c20400               ret 4
// library openrbx-raknet/DS_HuffmanEncodingTree.cpp (function ?Insert@?$CircularLinkedList@PAUHuffmanEncodingTreeNode@@@DataStructures@@QAEXABQAUHuffmanEncodingTreeNode@@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet DS_HuffmanEncodingTree.cpp
