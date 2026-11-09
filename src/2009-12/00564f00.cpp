// from server: 100% by auto
// roc 2009-12 00564f00  unit: CXTPRichRender::XTextHost  size: 200 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00564f00
//
// 00564f00  56                   push esi
// 00564f01  8bf1                 mov esi, ecx
// 00564f03  8b06                 mov eax, dword ptr [esi]
// 00564f05  6a0c                 push 0xc
// 00564f07  85c0                 test eax, eax
// 00564f09  752f                 jne 0x564f3a
// 00564f0b  e850e92800           call 0x7f3860
// 00564f10  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00564f14  894604               mov dword ptr [esi + 4], eax
// 00564f17  8b11                 mov edx, dword ptr [ecx]
// 00564f19  8910                 mov dword ptr [eax], edx
// 00564f1b  8b4604               mov eax, dword ptr [esi + 4]
// 00564f1e  894008               mov dword ptr [eax + 8], eax
// 00564f21  8b4604               mov eax, dword ptr [esi + 4]
// 00564f24  894004               mov dword ptr [eax + 4], eax
// 00564f27  8b4604               mov eax, dword ptr [esi + 4]
// 00564f2a  83c404               add esp, 4
// 00564f2d  c70601000000         mov dword ptr [esi], 1
// 00564f33  894608               mov dword ptr [esi + 8], eax
// 00564f36  5e                   pop esi
// 00564f37  c20400               ret 4
// 00564f3a  83f801               cmp eax, 1
// 00564f3d  7547                 jne 0x564f86
// 00564f3f  e81ce92800           call 0x7f3860
// 00564f44  8b4e04               mov ecx, dword ptr [esi + 4]
// 00564f47  894608               mov dword ptr [esi + 8], eax
// 00564f4a  894108               mov dword ptr [ecx + 8], eax
// 00564f4d  8b5604               mov edx, dword ptr [esi + 4]
// 00564f50  8b4608               mov eax, dword ptr [esi + 8]
// 00564f53  894204               mov dword ptr [edx + 4], eax
// 00564f56  8b5604               mov edx, dword ptr [esi + 4]
// 00564f59  8b4e08               mov ecx, dword ptr [esi + 8]
// 00564f5c  895104               mov dword ptr [ecx + 4], edx
// 00564f5f  8b4e04               mov ecx, dword ptr [esi + 4]
// 00564f62  8b4608               mov eax, dword ptr [esi + 8]
// 00564f65  894808               mov dword ptr [eax + 8], ecx
// 00564f68  8b5608               mov edx, dword ptr [esi + 8]
// 00564f6b  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00564f6f  8b08                 mov ecx, dword ptr [eax]
// 00564f71  890a                 mov dword ptr [edx], ecx
// 00564f73  8b5608               mov edx, dword ptr [esi + 8]
// 00564f76  83c404               add esp, 4
// 00564f79  895604               mov dword ptr [esi + 4], edx
// 00564f7c  c70602000000         mov dword ptr [esi], 2
// 00564f82  5e                   pop esi
// 00564f83  c20400               ret 4
// 00564f86  e8d5e82800           call 0x7f3860
// 00564f8b  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00564f8f  8b11                 mov edx, dword ptr [ecx]
// 00564f91  8910                 mov dword ptr [eax], edx
// 00564f93  8b4e08               mov ecx, dword ptr [esi + 8]
// 00564f96  8b5104               mov edx, dword ptr [ecx + 4]
// 00564f99  894208               mov dword ptr [edx + 8], eax
// 00564f9c  8b4e08               mov ecx, dword ptr [esi + 8]
// 00564f9f  8b5104               mov edx, dword ptr [ecx + 4]
// 00564fa2  895004               mov dword ptr [eax + 4], edx
// 00564fa5  8b4e08               mov ecx, dword ptr [esi + 8]
// 00564fa8  894104               mov dword ptr [ecx + 4], eax
// 00564fab  8b5608               mov edx, dword ptr [esi + 8]
// 00564fae  895008               mov dword ptr [eax + 8], edx
// 00564fb1  8b4e08               mov ecx, dword ptr [esi + 8]
// 00564fb4  83c404               add esp, 4
// 00564fb7  3b4e04               cmp ecx, dword ptr [esi + 4]
// 00564fba  7506                 jne 0x564fc2
// 00564fbc  894604               mov dword ptr [esi + 4], eax
// 00564fbf  894608               mov dword ptr [esi + 8], eax
// 00564fc2  ff06                 inc dword ptr [esi]
// 00564fc4  5e                   pop esi
// 00564fc5  c20400               ret 4
// library raknet-4.081/DS_HuffmanEncodingTree.cpp (function ?Insert@?$CircularLinkedList@PAUHuffmanEncodingTreeNode@@@DataStructures@@QAEXABQAUHuffmanEncodingTreeNode@@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 DS_HuffmanEncodingTree.cpp
