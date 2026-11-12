// roc 2012-06 005c7c90  unit: RakNet::RakPeer  size: 200 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005c7c90
//
// 005c7c90  56                   push esi
// 005c7c91  8bf1                 mov esi, ecx
// 005c7c93  8b06                 mov eax, dword ptr [esi]
// 005c7c95  6a0c                 push 0xc
// 005c7c97  85c0                 test eax, eax
// 005c7c99  752f                 jne 0x5c7cca
// 005c7c9b  e87aa43b00           call 0x98211a
// 005c7ca0  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005c7ca4  894604               mov dword ptr [esi + 4], eax
// 005c7ca7  8b11                 mov edx, dword ptr [ecx]
// 005c7ca9  8910                 mov dword ptr [eax], edx
// 005c7cab  8b4604               mov eax, dword ptr [esi + 4]
// 005c7cae  894008               mov dword ptr [eax + 8], eax
// 005c7cb1  8b4604               mov eax, dword ptr [esi + 4]
// 005c7cb4  894004               mov dword ptr [eax + 4], eax
// 005c7cb7  8b4604               mov eax, dword ptr [esi + 4]
// 005c7cba  83c404               add esp, 4
// 005c7cbd  c70601000000         mov dword ptr [esi], 1
// 005c7cc3  894608               mov dword ptr [esi + 8], eax
// 005c7cc6  5e                   pop esi
// 005c7cc7  c20400               ret 4
// 005c7cca  83f801               cmp eax, 1
// 005c7ccd  7547                 jne 0x5c7d16
// 005c7ccf  e846a43b00           call 0x98211a
// 005c7cd4  8b4e04               mov ecx, dword ptr [esi + 4]
// 005c7cd7  894608               mov dword ptr [esi + 8], eax
// 005c7cda  894108               mov dword ptr [ecx + 8], eax
// 005c7cdd  8b5604               mov edx, dword ptr [esi + 4]
// 005c7ce0  8b4608               mov eax, dword ptr [esi + 8]
// 005c7ce3  894204               mov dword ptr [edx + 4], eax
// 005c7ce6  8b5604               mov edx, dword ptr [esi + 4]
// 005c7ce9  8b4e08               mov ecx, dword ptr [esi + 8]
// 005c7cec  895104               mov dword ptr [ecx + 4], edx
// 005c7cef  8b4e04               mov ecx, dword ptr [esi + 4]
// 005c7cf2  8b4608               mov eax, dword ptr [esi + 8]
// 005c7cf5  894808               mov dword ptr [eax + 8], ecx
// 005c7cf8  8b5608               mov edx, dword ptr [esi + 8]
// 005c7cfb  8b44240c             mov eax, dword ptr [esp + 0xc]
// 005c7cff  8b08                 mov ecx, dword ptr [eax]
// 005c7d01  890a                 mov dword ptr [edx], ecx
// 005c7d03  8b5608               mov edx, dword ptr [esi + 8]
// 005c7d06  83c404               add esp, 4
// 005c7d09  895604               mov dword ptr [esi + 4], edx
// 005c7d0c  c70602000000         mov dword ptr [esi], 2
// 005c7d12  5e                   pop esi
// 005c7d13  c20400               ret 4
// 005c7d16  e8ffa33b00           call 0x98211a
// 005c7d1b  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005c7d1f  8b11                 mov edx, dword ptr [ecx]
// 005c7d21  8910                 mov dword ptr [eax], edx
// 005c7d23  8b4e08               mov ecx, dword ptr [esi + 8]
// 005c7d26  8b5104               mov edx, dword ptr [ecx + 4]
// 005c7d29  894208               mov dword ptr [edx + 8], eax
// 005c7d2c  8b4e08               mov ecx, dword ptr [esi + 8]
// 005c7d2f  8b5104               mov edx, dword ptr [ecx + 4]
// 005c7d32  895004               mov dword ptr [eax + 4], edx
// 005c7d35  8b4e08               mov ecx, dword ptr [esi + 8]
// 005c7d38  894104               mov dword ptr [ecx + 4], eax
// 005c7d3b  8b5608               mov edx, dword ptr [esi + 8]
// 005c7d3e  895008               mov dword ptr [eax + 8], edx
// 005c7d41  8b4e08               mov ecx, dword ptr [esi + 8]
// 005c7d44  83c404               add esp, 4
// 005c7d47  3b4e04               cmp ecx, dword ptr [esi + 4]
// 005c7d4a  7506                 jne 0x5c7d52
// 005c7d4c  894604               mov dword ptr [esi + 4], eax
// 005c7d4f  894608               mov dword ptr [esi + 8], eax
// 005c7d52  ff06                 inc dword ptr [esi]
// 005c7d54  5e                   pop esi
// 005c7d55  c20400               ret 4
// library openrbx-raknet/DS_HuffmanEncodingTree.cpp (function ?Insert@?$CircularLinkedList@PAUHuffmanEncodingTreeNode@@@DataStructures@@QAEXABQAUHuffmanEncodingTreeNode@@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet DS_HuffmanEncodingTree.cpp
