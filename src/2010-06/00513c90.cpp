// from server: 100% by auto
// roc 2010-06 00513c90  unit: RBX::Network::InterpolatingPhysicsReceiver::Job  size: 129 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00513c90
//
// 00513c90  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00513c94  57                   push edi
// 00513c95  8b39                 mov edi, dword ptr [ecx]
// 00513c97  85ff                 test edi, edi
// 00513c99  750e                 jne 0x513ca9
// 00513c9b  8d442408             lea eax, [esp + 8]
// 00513c9f  50                   push eax
// 00513ca0  e87bfdffff           call 0x513a20
// 00513ca5  5f                   pop edi
// 00513ca6  c20800               ret 8
// 00513ca9  56                   push esi
// 00513caa  8b7104               mov esi, dword ptr [ecx + 4]
// 00513cad  85f6                 test esi, esi
// 00513caf  7403                 je 0x513cb4
// 00513cb1  897108               mov dword ptr [ecx + 8], esi
// 00513cb4  8b4108               mov eax, dword ptr [ecx + 8]
// 00513cb7  8b00                 mov eax, dword ptr [eax]
// 00513cb9  8b4004               mov eax, dword ptr [eax + 4]
// 00513cbc  53                   push ebx
// 00513cbd  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 00513cc1  33d2                 xor edx, edx
// 00513cc3  3b4304               cmp eax, dword ptr [ebx + 4]
// 00513cc6  731f                 jae 0x513ce7
// 00513cc8  8b4108               mov eax, dword ptr [ecx + 8]
// 00513ccb  8b4008               mov eax, dword ptr [eax + 8]
// 00513cce  3bc6                 cmp eax, esi
// 00513cd0  7403                 je 0x513cd5
// 00513cd2  894108               mov dword ptr [ecx + 8], eax
// 00513cd5  42                   inc edx
// 00513cd6  3bd7                 cmp edx, edi
// 00513cd8  741d                 je 0x513cf7
// 00513cda  8b4108               mov eax, dword ptr [ecx + 8]
// 00513cdd  8b00                 mov eax, dword ptr [eax]
// 00513cdf  8b4004               mov eax, dword ptr [eax + 4]
// 00513ce2  3b4304               cmp eax, dword ptr [ebx + 4]
// 00513ce5  72e1                 jb 0x513cc8
// 00513ce7  8d542410             lea edx, [esp + 0x10]
// 00513ceb  52                   push edx
// 00513cec  e82ffdffff           call 0x513a20
// 00513cf1  5b                   pop ebx
// 00513cf2  5e                   pop esi
// 00513cf3  5f                   pop edi
// 00513cf4  c20800               ret 8
// 00513cf7  85f6                 test esi, esi
// 00513cf9  7406                 je 0x513d01
// 00513cfb  8b5604               mov edx, dword ptr [esi + 4]
// 00513cfe  895108               mov dword ptr [ecx + 8], edx
// 00513d01  8d442410             lea eax, [esp + 0x10]
// 00513d05  50                   push eax
// 00513d06  e8b5ebfeff           call 0x5028c0
// 00513d0b  5b                   pop ebx
// 00513d0c  5e                   pop esi
// 00513d0d  5f                   pop edi
// 00513d0e  c20800               ret 8
// library openrbx-raknet/DS_HuffmanEncodingTree.cpp (function ?InsertNodeIntoSortedList@HuffmanEncodingTree@@ABEXPAUHuffmanEncodingTreeNode@@PAV?$LinkedList@PAUHuffmanEncodingTreeNode@@@DataStructures@@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet DS_HuffmanEncodingTree.cpp
