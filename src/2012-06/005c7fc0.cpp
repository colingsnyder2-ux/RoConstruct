// roc 2012-06 005c7fc0  unit: RakNet::RakPeer  size: 129 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005c7fc0
//
// 005c7fc0  8b4c2408             mov ecx, dword ptr [esp + 8]
// 005c7fc4  57                   push edi
// 005c7fc5  8b39                 mov edi, dword ptr [ecx]
// 005c7fc7  85ff                 test edi, edi
// 005c7fc9  750e                 jne 0x5c7fd9
// 005c7fcb  8d442408             lea eax, [esp + 8]
// 005c7fcf  50                   push eax
// 005c7fd0  e8bbfcffff           call 0x5c7c90
// 005c7fd5  5f                   pop edi
// 005c7fd6  c20800               ret 8
// 005c7fd9  56                   push esi
// 005c7fda  8b7104               mov esi, dword ptr [ecx + 4]
// 005c7fdd  85f6                 test esi, esi
// 005c7fdf  7403                 je 0x5c7fe4
// 005c7fe1  897108               mov dword ptr [ecx + 8], esi
// 005c7fe4  8b4108               mov eax, dword ptr [ecx + 8]
// 005c7fe7  8b00                 mov eax, dword ptr [eax]
// 005c7fe9  8b4004               mov eax, dword ptr [eax + 4]
// 005c7fec  53                   push ebx
// 005c7fed  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 005c7ff1  33d2                 xor edx, edx
// 005c7ff3  3b4304               cmp eax, dword ptr [ebx + 4]
// 005c7ff6  731f                 jae 0x5c8017
// 005c7ff8  8b4108               mov eax, dword ptr [ecx + 8]
// 005c7ffb  8b4008               mov eax, dword ptr [eax + 8]
// 005c7ffe  3bc6                 cmp eax, esi
// 005c8000  7403                 je 0x5c8005
// 005c8002  894108               mov dword ptr [ecx + 8], eax
// 005c8005  42                   inc edx
// 005c8006  3bd7                 cmp edx, edi
// 005c8008  741d                 je 0x5c8027
// 005c800a  8b4108               mov eax, dword ptr [ecx + 8]
// 005c800d  8b00                 mov eax, dword ptr [eax]
// 005c800f  8b4004               mov eax, dword ptr [eax + 4]
// 005c8012  3b4304               cmp eax, dword ptr [ebx + 4]
// 005c8015  72e1                 jb 0x5c7ff8
// 005c8017  8d542410             lea edx, [esp + 0x10]
// 005c801b  52                   push edx
// 005c801c  e86ffcffff           call 0x5c7c90
// 005c8021  5b                   pop ebx
// 005c8022  5e                   pop esi
// 005c8023  5f                   pop edi
// 005c8024  c20800               ret 8
// 005c8027  85f6                 test esi, esi
// 005c8029  7406                 je 0x5c8031
// 005c802b  8b5604               mov edx, dword ptr [esi + 4]
// 005c802e  895108               mov dword ptr [ecx + 8], edx
// 005c8031  8d442410             lea eax, [esp + 0x10]
// 005c8035  50                   push eax
// 005c8036  e825fdffff           call 0x5c7d60
// 005c803b  5b                   pop ebx
// 005c803c  5e                   pop esi
// 005c803d  5f                   pop edi
// 005c803e  c20800               ret 8
// library openrbx-raknet/DS_HuffmanEncodingTree.cpp (function ?InsertNodeIntoSortedList@HuffmanEncodingTree@@ABEXPAUHuffmanEncodingTreeNode@@PAV?$LinkedList@PAUHuffmanEncodingTreeNode@@@DataStructures@@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet DS_HuffmanEncodingTree.cpp
