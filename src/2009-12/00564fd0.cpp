// from server: 100% by auto
// roc 2009-12 00564fd0  unit: CXTPRichRender::XTextHost  size: 186 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00564fd0
//
// 00564fd0  56                   push esi
// 00564fd1  8bf1                 mov esi, ecx
// 00564fd3  8b06                 mov eax, dword ptr [esi]
// 00564fd5  6a0c                 push 0xc
// 00564fd7  85c0                 test eax, eax
// 00564fd9  752f                 jne 0x56500a
// 00564fdb  e880e82800           call 0x7f3860
// 00564fe0  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00564fe4  894604               mov dword ptr [esi + 4], eax
// 00564fe7  8b11                 mov edx, dword ptr [ecx]
// 00564fe9  8910                 mov dword ptr [eax], edx
// 00564feb  8b4604               mov eax, dword ptr [esi + 4]
// 00564fee  894008               mov dword ptr [eax + 8], eax
// 00564ff1  8b4604               mov eax, dword ptr [esi + 4]
// 00564ff4  894004               mov dword ptr [eax + 4], eax
// 00564ff7  8b4604               mov eax, dword ptr [esi + 4]
// 00564ffa  83c404               add esp, 4
// 00564ffd  c70601000000         mov dword ptr [esi], 1
// 00565003  894608               mov dword ptr [esi + 8], eax
// 00565006  5e                   pop esi
// 00565007  c20400               ret 4
// 0056500a  83f801               cmp eax, 1
// 0056500d  7547                 jne 0x565056
// 0056500f  e84ce82800           call 0x7f3860
// 00565014  8b4e04               mov ecx, dword ptr [esi + 4]
// 00565017  894608               mov dword ptr [esi + 8], eax
// 0056501a  894108               mov dword ptr [ecx + 8], eax
// 0056501d  8b4608               mov eax, dword ptr [esi + 8]
// 00565020  8b5604               mov edx, dword ptr [esi + 4]
// 00565023  894204               mov dword ptr [edx + 4], eax
// 00565026  8b4e08               mov ecx, dword ptr [esi + 8]
// 00565029  8b5604               mov edx, dword ptr [esi + 4]
// 0056502c  895104               mov dword ptr [ecx + 4], edx
// 0056502f  8b4608               mov eax, dword ptr [esi + 8]
// 00565032  8b4e04               mov ecx, dword ptr [esi + 4]
// 00565035  894808               mov dword ptr [eax + 8], ecx
// 00565038  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0056503c  8b08                 mov ecx, dword ptr [eax]
// 0056503e  8b5608               mov edx, dword ptr [esi + 8]
// 00565041  890a                 mov dword ptr [edx], ecx
// 00565043  8b4604               mov eax, dword ptr [esi + 4]
// 00565046  83c404               add esp, 4
// 00565049  c70602000000         mov dword ptr [esi], 2
// 0056504f  894608               mov dword ptr [esi + 8], eax
// 00565052  5e                   pop esi
// 00565053  c20400               ret 4
// 00565056  e805e82800           call 0x7f3860
// 0056505b  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0056505f  8b0a                 mov ecx, dword ptr [edx]
// 00565061  8908                 mov dword ptr [eax], ecx
// 00565063  8b5608               mov edx, dword ptr [esi + 8]
// 00565066  895004               mov dword ptr [eax + 4], edx
// 00565069  8b4e08               mov ecx, dword ptr [esi + 8]
// 0056506c  8b5108               mov edx, dword ptr [ecx + 8]
// 0056506f  895008               mov dword ptr [eax + 8], edx
// 00565072  8b4e08               mov ecx, dword ptr [esi + 8]
// 00565075  8b5108               mov edx, dword ptr [ecx + 8]
// 00565078  894204               mov dword ptr [edx + 4], eax
// 0056507b  8b4e08               mov ecx, dword ptr [esi + 8]
// 0056507e  83c404               add esp, 4
// 00565081  894108               mov dword ptr [ecx + 8], eax
// 00565084  ff06                 inc dword ptr [esi]
// 00565086  5e                   pop esi
// 00565087  c20400               ret 4
// library raknet-4.081/DS_HuffmanEncodingTree.cpp (function ?Add@?$CircularLinkedList@PAUHuffmanEncodingTreeNode@@@DataStructures@@QAEAAPAUHuffmanEncodingTreeNode@@ABQAU3@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 DS_HuffmanEncodingTree.cpp
