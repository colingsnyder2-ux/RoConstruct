// from server: 100% by auto
// roc 2008-06 004cde00  unit: RBX::Network::PhysicsSender  size: 200 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004cde00
//
// 004cde00  56                   push esi
// 004cde01  8bf1                 mov esi, ecx
// 004cde03  8b06                 mov eax, dword ptr [esi]
// 004cde05  6a0c                 push 0xc
// 004cde07  85c0                 test eax, eax
// 004cde09  752f                 jne 0x4cde3a
// 004cde0b  e8102b1d00           call 0x6a0920
// 004cde10  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004cde14  894604               mov dword ptr [esi + 4], eax
// 004cde17  8b11                 mov edx, dword ptr [ecx]
// 004cde19  8910                 mov dword ptr [eax], edx
// 004cde1b  8b4604               mov eax, dword ptr [esi + 4]
// 004cde1e  894008               mov dword ptr [eax + 8], eax
// 004cde21  8b4604               mov eax, dword ptr [esi + 4]
// 004cde24  894004               mov dword ptr [eax + 4], eax
// 004cde27  8b4604               mov eax, dword ptr [esi + 4]
// 004cde2a  83c404               add esp, 4
// 004cde2d  c70601000000         mov dword ptr [esi], 1
// 004cde33  894608               mov dword ptr [esi + 8], eax
// 004cde36  5e                   pop esi
// 004cde37  c20400               ret 4
// 004cde3a  83f801               cmp eax, 1
// 004cde3d  7547                 jne 0x4cde86
// 004cde3f  e8dc2a1d00           call 0x6a0920
// 004cde44  8b4e04               mov ecx, dword ptr [esi + 4]
// 004cde47  894608               mov dword ptr [esi + 8], eax
// 004cde4a  894108               mov dword ptr [ecx + 8], eax
// 004cde4d  8b5604               mov edx, dword ptr [esi + 4]
// 004cde50  8b4608               mov eax, dword ptr [esi + 8]
// 004cde53  894204               mov dword ptr [edx + 4], eax
// 004cde56  8b5604               mov edx, dword ptr [esi + 4]
// 004cde59  8b4e08               mov ecx, dword ptr [esi + 8]
// 004cde5c  895104               mov dword ptr [ecx + 4], edx
// 004cde5f  8b4e04               mov ecx, dword ptr [esi + 4]
// 004cde62  8b4608               mov eax, dword ptr [esi + 8]
// 004cde65  894808               mov dword ptr [eax + 8], ecx
// 004cde68  8b5608               mov edx, dword ptr [esi + 8]
// 004cde6b  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004cde6f  8b08                 mov ecx, dword ptr [eax]
// 004cde71  890a                 mov dword ptr [edx], ecx
// 004cde73  8b5608               mov edx, dword ptr [esi + 8]
// 004cde76  83c404               add esp, 4
// 004cde79  895604               mov dword ptr [esi + 4], edx
// 004cde7c  c70602000000         mov dword ptr [esi], 2
// 004cde82  5e                   pop esi
// 004cde83  c20400               ret 4
// 004cde86  e8952a1d00           call 0x6a0920
// 004cde8b  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004cde8f  8b11                 mov edx, dword ptr [ecx]
// 004cde91  8910                 mov dword ptr [eax], edx
// 004cde93  8b4e08               mov ecx, dword ptr [esi + 8]
// 004cde96  8b5104               mov edx, dword ptr [ecx + 4]
// 004cde99  894208               mov dword ptr [edx + 8], eax
// 004cde9c  8b4e08               mov ecx, dword ptr [esi + 8]
// 004cde9f  8b5104               mov edx, dword ptr [ecx + 4]
// 004cdea2  895004               mov dword ptr [eax + 4], edx
// 004cdea5  8b4e08               mov ecx, dword ptr [esi + 8]
// 004cdea8  894104               mov dword ptr [ecx + 4], eax
// 004cdeab  8b5608               mov edx, dword ptr [esi + 8]
// 004cdeae  895008               mov dword ptr [eax + 8], edx
// 004cdeb1  8b4e08               mov ecx, dword ptr [esi + 8]
// 004cdeb4  83c404               add esp, 4
// 004cdeb7  3b4e04               cmp ecx, dword ptr [esi + 4]
// 004cdeba  7506                 jne 0x4cdec2
// 004cdebc  894604               mov dword ptr [esi + 4], eax
// 004cdebf  894608               mov dword ptr [esi + 8], eax
// 004cdec2  ff06                 inc dword ptr [esi]
// 004cdec4  5e                   pop esi
// 004cdec5  c20400               ret 4
// library openrbx-raknet/DS_HuffmanEncodingTree.cpp (function ?Insert@?$CircularLinkedList@PAUHuffmanEncodingTreeNode@@@DataStructures@@QAEXABQAUHuffmanEncodingTreeNode@@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet DS_HuffmanEncodingTree.cpp
