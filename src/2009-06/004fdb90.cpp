// from server: 100% by auto
// roc 2009-06 004fdb90  unit: RBX::Network::NetworkOwnerJob  size: 129 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004fdb90
//
// 004fdb90  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004fdb94  57                   push edi
// 004fdb95  8b39                 mov edi, dword ptr [ecx]
// 004fdb97  85ff                 test edi, edi
// 004fdb99  750e                 jne 0x4fdba9
// 004fdb9b  8d442408             lea eax, [esp + 8]
// 004fdb9f  50                   push eax
// 004fdba0  e87bfdffff           call 0x4fd920
// 004fdba5  5f                   pop edi
// 004fdba6  c20800               ret 8
// 004fdba9  56                   push esi
// 004fdbaa  8b7104               mov esi, dword ptr [ecx + 4]
// 004fdbad  85f6                 test esi, esi
// 004fdbaf  7403                 je 0x4fdbb4
// 004fdbb1  897108               mov dword ptr [ecx + 8], esi
// 004fdbb4  8b4108               mov eax, dword ptr [ecx + 8]
// 004fdbb7  8b00                 mov eax, dword ptr [eax]
// 004fdbb9  8b4004               mov eax, dword ptr [eax + 4]
// 004fdbbc  53                   push ebx
// 004fdbbd  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 004fdbc1  33d2                 xor edx, edx
// 004fdbc3  3b4304               cmp eax, dword ptr [ebx + 4]
// 004fdbc6  731f                 jae 0x4fdbe7
// 004fdbc8  8b4108               mov eax, dword ptr [ecx + 8]
// 004fdbcb  8b4008               mov eax, dword ptr [eax + 8]
// 004fdbce  3bc6                 cmp eax, esi
// 004fdbd0  7403                 je 0x4fdbd5
// 004fdbd2  894108               mov dword ptr [ecx + 8], eax
// 004fdbd5  42                   inc edx
// 004fdbd6  3bd7                 cmp edx, edi
// 004fdbd8  741d                 je 0x4fdbf7
// 004fdbda  8b4108               mov eax, dword ptr [ecx + 8]
// 004fdbdd  8b00                 mov eax, dword ptr [eax]
// 004fdbdf  8b4004               mov eax, dword ptr [eax + 4]
// 004fdbe2  3b4304               cmp eax, dword ptr [ebx + 4]
// 004fdbe5  72e1                 jb 0x4fdbc8
// 004fdbe7  8d542410             lea edx, [esp + 0x10]
// 004fdbeb  52                   push edx
// 004fdbec  e82ffdffff           call 0x4fd920
// 004fdbf1  5b                   pop ebx
// 004fdbf2  5e                   pop esi
// 004fdbf3  5f                   pop edi
// 004fdbf4  c20800               ret 8
// 004fdbf7  85f6                 test esi, esi
// 004fdbf9  7406                 je 0x4fdc01
// 004fdbfb  8b5604               mov edx, dword ptr [esi + 4]
// 004fdbfe  895108               mov dword ptr [ecx + 8], edx
// 004fdc01  8d442410             lea eax, [esp + 0x10]
// 004fdc05  50                   push eax
// 004fdc06  e8e583ffff           call 0x4f5ff0
// 004fdc0b  5b                   pop ebx
// 004fdc0c  5e                   pop esi
// 004fdc0d  5f                   pop edi
// 004fdc0e  c20800               ret 8
// library openrbx-raknet/DS_HuffmanEncodingTree.cpp (function ?InsertNodeIntoSortedList@HuffmanEncodingTree@@ABEXPAUHuffmanEncodingTreeNode@@PAV?$LinkedList@PAUHuffmanEncodingTreeNode@@@DataStructures@@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet DS_HuffmanEncodingTree.cpp
