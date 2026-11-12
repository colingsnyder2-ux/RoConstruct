// from server: 100% by auto
// roc 2011-06 0051ee30  unit: RBX::Network::InterpolatingPhysicsReceiver::Job  size: 129 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0051ee30
//
// 0051ee30  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0051ee34  57                   push edi
// 0051ee35  8b39                 mov edi, dword ptr [ecx]
// 0051ee37  85ff                 test edi, edi
// 0051ee39  750e                 jne 0x51ee49
// 0051ee3b  8d442408             lea eax, [esp + 8]
// 0051ee3f  50                   push eax
// 0051ee40  e87bfdffff           call 0x51ebc0
// 0051ee45  5f                   pop edi
// 0051ee46  c20800               ret 8
// 0051ee49  56                   push esi
// 0051ee4a  8b7104               mov esi, dword ptr [ecx + 4]
// 0051ee4d  85f6                 test esi, esi
// 0051ee4f  7403                 je 0x51ee54
// 0051ee51  897108               mov dword ptr [ecx + 8], esi
// 0051ee54  8b4108               mov eax, dword ptr [ecx + 8]
// 0051ee57  8b00                 mov eax, dword ptr [eax]
// 0051ee59  8b4004               mov eax, dword ptr [eax + 4]
// 0051ee5c  53                   push ebx
// 0051ee5d  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0051ee61  33d2                 xor edx, edx
// 0051ee63  3b4304               cmp eax, dword ptr [ebx + 4]
// 0051ee66  731f                 jae 0x51ee87
// 0051ee68  8b4108               mov eax, dword ptr [ecx + 8]
// 0051ee6b  8b4008               mov eax, dword ptr [eax + 8]
// 0051ee6e  3bc6                 cmp eax, esi
// 0051ee70  7403                 je 0x51ee75
// 0051ee72  894108               mov dword ptr [ecx + 8], eax
// 0051ee75  42                   inc edx
// 0051ee76  3bd7                 cmp edx, edi
// 0051ee78  741d                 je 0x51ee97
// 0051ee7a  8b4108               mov eax, dword ptr [ecx + 8]
// 0051ee7d  8b00                 mov eax, dword ptr [eax]
// 0051ee7f  8b4004               mov eax, dword ptr [eax + 4]
// 0051ee82  3b4304               cmp eax, dword ptr [ebx + 4]
// 0051ee85  72e1                 jb 0x51ee68
// 0051ee87  8d542410             lea edx, [esp + 0x10]
// 0051ee8b  52                   push edx
// 0051ee8c  e82ffdffff           call 0x51ebc0
// 0051ee91  5b                   pop ebx
// 0051ee92  5e                   pop esi
// 0051ee93  5f                   pop edi
// 0051ee94  c20800               ret 8
// 0051ee97  85f6                 test esi, esi
// 0051ee99  7406                 je 0x51eea1
// 0051ee9b  8b5604               mov edx, dword ptr [esi + 4]
// 0051ee9e  895108               mov dword ptr [ecx + 8], edx
// 0051eea1  8d442410             lea eax, [esp + 0x10]
// 0051eea5  50                   push eax
// 0051eea6  e875040100           call 0x52f320
// 0051eeab  5b                   pop ebx
// 0051eeac  5e                   pop esi
// 0051eead  5f                   pop edi
// 0051eeae  c20800               ret 8
// library openrbx-raknet/DS_HuffmanEncodingTree.cpp (function ?InsertNodeIntoSortedList@HuffmanEncodingTree@@ABEXPAUHuffmanEncodingTreeNode@@PAV?$LinkedList@PAUHuffmanEncodingTreeNode@@@DataStructures@@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet DS_HuffmanEncodingTree.cpp
