// from server: 100% by auto
// roc 2009-06 004f5ff0  unit: RBX::Network::ClientReplicator  size: 186 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004f5ff0
//
// 004f5ff0  56                   push esi
// 004f5ff1  8bf1                 mov esi, ecx
// 004f5ff3  8b06                 mov eax, dword ptr [esi]
// 004f5ff5  6a0c                 push 0xc
// 004f5ff7  85c0                 test eax, eax
// 004f5ff9  752f                 jne 0x4f602a
// 004f5ffb  e8382a2200           call 0x718a38
// 004f6000  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004f6004  894604               mov dword ptr [esi + 4], eax
// 004f6007  8b11                 mov edx, dword ptr [ecx]
// 004f6009  8910                 mov dword ptr [eax], edx
// 004f600b  8b4604               mov eax, dword ptr [esi + 4]
// 004f600e  894008               mov dword ptr [eax + 8], eax
// 004f6011  8b4604               mov eax, dword ptr [esi + 4]
// 004f6014  894004               mov dword ptr [eax + 4], eax
// 004f6017  8b4604               mov eax, dword ptr [esi + 4]
// 004f601a  83c404               add esp, 4
// 004f601d  c70601000000         mov dword ptr [esi], 1
// 004f6023  894608               mov dword ptr [esi + 8], eax
// 004f6026  5e                   pop esi
// 004f6027  c20400               ret 4
// 004f602a  83f801               cmp eax, 1
// 004f602d  7547                 jne 0x4f6076
// 004f602f  e8042a2200           call 0x718a38
// 004f6034  8b4e04               mov ecx, dword ptr [esi + 4]
// 004f6037  894608               mov dword ptr [esi + 8], eax
// 004f603a  894108               mov dword ptr [ecx + 8], eax
// 004f603d  8b4608               mov eax, dword ptr [esi + 8]
// 004f6040  8b5604               mov edx, dword ptr [esi + 4]
// 004f6043  894204               mov dword ptr [edx + 4], eax
// 004f6046  8b4e08               mov ecx, dword ptr [esi + 8]
// 004f6049  8b5604               mov edx, dword ptr [esi + 4]
// 004f604c  895104               mov dword ptr [ecx + 4], edx
// 004f604f  8b4608               mov eax, dword ptr [esi + 8]
// 004f6052  8b4e04               mov ecx, dword ptr [esi + 4]
// 004f6055  894808               mov dword ptr [eax + 8], ecx
// 004f6058  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004f605c  8b08                 mov ecx, dword ptr [eax]
// 004f605e  8b5608               mov edx, dword ptr [esi + 8]
// 004f6061  890a                 mov dword ptr [edx], ecx
// 004f6063  8b4604               mov eax, dword ptr [esi + 4]
// 004f6066  83c404               add esp, 4
// 004f6069  c70602000000         mov dword ptr [esi], 2
// 004f606f  894608               mov dword ptr [esi + 8], eax
// 004f6072  5e                   pop esi
// 004f6073  c20400               ret 4
// 004f6076  e8bd292200           call 0x718a38
// 004f607b  8b54240c             mov edx, dword ptr [esp + 0xc]
// 004f607f  8b0a                 mov ecx, dword ptr [edx]
// 004f6081  8908                 mov dword ptr [eax], ecx
// 004f6083  8b5608               mov edx, dword ptr [esi + 8]
// 004f6086  895004               mov dword ptr [eax + 4], edx
// 004f6089  8b4e08               mov ecx, dword ptr [esi + 8]
// 004f608c  8b5108               mov edx, dword ptr [ecx + 8]
// 004f608f  895008               mov dword ptr [eax + 8], edx
// 004f6092  8b4e08               mov ecx, dword ptr [esi + 8]
// 004f6095  8b5108               mov edx, dword ptr [ecx + 8]
// 004f6098  894204               mov dword ptr [edx + 4], eax
// 004f609b  8b4e08               mov ecx, dword ptr [esi + 8]
// 004f609e  83c404               add esp, 4
// 004f60a1  894108               mov dword ptr [ecx + 8], eax
// 004f60a4  ff06                 inc dword ptr [esi]
// 004f60a6  5e                   pop esi
// 004f60a7  c20400               ret 4
// library openrbx-raknet/DS_HuffmanEncodingTree.cpp (function ?Add@?$CircularLinkedList@PAUHuffmanEncodingTreeNode@@@DataStructures@@QAEAAPAUHuffmanEncodingTreeNode@@ABQAU3@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet DS_HuffmanEncodingTree.cpp
