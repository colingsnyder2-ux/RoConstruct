// roc 2012-06 005bb180  unit: RakNet::RakPeer  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005bb180
//
// 005bb180  0fb7510e             movzx edx, word ptr [ecx + 0xe]
// 005bb184  8b442404             mov eax, dword ptr [esp + 4]
// 005bb188  3bc2                 cmp eax, edx
// 005bb18a  7d28                 jge 0x5bb1b4
// 005bb18c  8b892c020000         mov ecx, dword ptr [ecx + 0x22c]
// 005bb192  69c008120000         imul eax, eax, 0x1208
// 005bb198  03c1                 add eax, ecx
// 005bb19a  803800               cmp byte ptr [eax], 0
// 005bb19d  7415                 je 0x5bb1b4
// 005bb19f  8b542408             mov edx, dword ptr [esp + 8]
// 005bb1a3  52                   push edx
// 005bb1a4  8d88f8000000         lea ecx, [eax + 0xf8]
// 005bb1aa  e891effdff           call 0x59a140
// 005bb1af  b001                 mov al, 1
// 005bb1b1  c20800               ret 8
// 005bb1b4  32c0                 xor al, al
// 005bb1b6  c20800               ret 8
// copied from an identical function in another client (function ?GetStatistics@RakPeer@RakNet@@UAE_NHPAURakNetStatistics@2@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-raknet RakPeer.cpp