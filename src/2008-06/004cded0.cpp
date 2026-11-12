// from server: 100% by auto
// roc 2008-06 004cded0  unit: RBX::Network::PhysicsSender  size: 186 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004cded0
//
// 004cded0  56                   push esi
// 004cded1  8bf1                 mov esi, ecx
// 004cded3  8b06                 mov eax, dword ptr [esi]
// 004cded5  6a0c                 push 0xc
// 004cded7  85c0                 test eax, eax
// 004cded9  752f                 jne 0x4cdf0a
// 004cdedb  e8402a1d00           call 0x6a0920
// 004cdee0  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004cdee4  894604               mov dword ptr [esi + 4], eax
// 004cdee7  8b11                 mov edx, dword ptr [ecx]
// 004cdee9  8910                 mov dword ptr [eax], edx
// 004cdeeb  8b4604               mov eax, dword ptr [esi + 4]
// 004cdeee  894008               mov dword ptr [eax + 8], eax
// 004cdef1  8b4604               mov eax, dword ptr [esi + 4]
// 004cdef4  894004               mov dword ptr [eax + 4], eax
// 004cdef7  8b4604               mov eax, dword ptr [esi + 4]
// 004cdefa  83c404               add esp, 4
// 004cdefd  c70601000000         mov dword ptr [esi], 1
// 004cdf03  894608               mov dword ptr [esi + 8], eax
// 004cdf06  5e                   pop esi
// 004cdf07  c20400               ret 4
// 004cdf0a  83f801               cmp eax, 1
// 004cdf0d  7547                 jne 0x4cdf56
// 004cdf0f  e80c2a1d00           call 0x6a0920
// 004cdf14  8b4e04               mov ecx, dword ptr [esi + 4]
// 004cdf17  894608               mov dword ptr [esi + 8], eax
// 004cdf1a  894108               mov dword ptr [ecx + 8], eax
// 004cdf1d  8b4608               mov eax, dword ptr [esi + 8]
// 004cdf20  8b5604               mov edx, dword ptr [esi + 4]
// 004cdf23  894204               mov dword ptr [edx + 4], eax
// 004cdf26  8b4e08               mov ecx, dword ptr [esi + 8]
// 004cdf29  8b5604               mov edx, dword ptr [esi + 4]
// 004cdf2c  895104               mov dword ptr [ecx + 4], edx
// 004cdf2f  8b4608               mov eax, dword ptr [esi + 8]
// 004cdf32  8b4e04               mov ecx, dword ptr [esi + 4]
// 004cdf35  894808               mov dword ptr [eax + 8], ecx
// 004cdf38  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004cdf3c  8b08                 mov ecx, dword ptr [eax]
// 004cdf3e  8b5608               mov edx, dword ptr [esi + 8]
// 004cdf41  890a                 mov dword ptr [edx], ecx
// 004cdf43  8b4604               mov eax, dword ptr [esi + 4]
// 004cdf46  83c404               add esp, 4
// 004cdf49  c70602000000         mov dword ptr [esi], 2
// 004cdf4f  894608               mov dword ptr [esi + 8], eax
// 004cdf52  5e                   pop esi
// 004cdf53  c20400               ret 4
// 004cdf56  e8c5291d00           call 0x6a0920
// 004cdf5b  8b54240c             mov edx, dword ptr [esp + 0xc]
// 004cdf5f  8b0a                 mov ecx, dword ptr [edx]
// 004cdf61  8908                 mov dword ptr [eax], ecx
// 004cdf63  8b5608               mov edx, dword ptr [esi + 8]
// 004cdf66  895004               mov dword ptr [eax + 4], edx
// 004cdf69  8b4e08               mov ecx, dword ptr [esi + 8]
// 004cdf6c  8b5108               mov edx, dword ptr [ecx + 8]
// 004cdf6f  895008               mov dword ptr [eax + 8], edx
// 004cdf72  8b4e08               mov ecx, dword ptr [esi + 8]
// 004cdf75  8b5108               mov edx, dword ptr [ecx + 8]
// 004cdf78  894204               mov dword ptr [edx + 4], eax
// 004cdf7b  8b4e08               mov ecx, dword ptr [esi + 8]
// 004cdf7e  83c404               add esp, 4
// 004cdf81  894108               mov dword ptr [ecx + 8], eax
// 004cdf84  ff06                 inc dword ptr [esi]
// 004cdf86  5e                   pop esi
// 004cdf87  c20400               ret 4
// library openrbx-raknet/DS_HuffmanEncodingTree.cpp (function ?Add@?$CircularLinkedList@PAUHuffmanEncodingTreeNode@@@DataStructures@@QAEAAPAUHuffmanEncodingTreeNode@@ABQAU3@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet DS_HuffmanEncodingTree.cpp
