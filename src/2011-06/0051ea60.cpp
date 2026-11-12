// from server: 100% by auto
// roc 2011-06 0051ea60  unit: RBX::Network::InterpolatingPhysicsReceiver::Job  size: 197 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0051ea60
//
// 0051ea60  64a100000000         mov eax, dword ptr fs:[0]
// 0051ea66  6aff                 push -1
// 0051ea68  680bc39d00           push 0x9dc30b
// 0051ea6d  50                   push eax
// 0051ea6e  64892500000000       mov dword ptr fs:[0], esp
// 0051ea75  81ec14010000         sub esp, 0x114
// 0051ea7b  53                   push ebx
// 0051ea7c  57                   push edi
// 0051ea7d  8bbc2430010000       mov edi, dword ptr [esp + 0x130]
// 0051ea84  8bd9                 mov ebx, ecx
// 0051ea86  85ff                 test edi, edi
// 0051ea88  0f867e000000         jbe 0x51eb0c
// 0051ea8e  8b8c242c010000       mov ecx, dword ptr [esp + 0x12c]
// 0051ea95  56                   push esi
// 0051ea96  6a00                 push 0
// 0051ea98  8d4707               lea eax, [edi + 7]
// 0051ea9b  c1e803               shr eax, 3
// 0051ea9e  50                   push eax
// 0051ea9f  51                   push ecx
// 0051eaa0  8d4c2418             lea ecx, [esp + 0x18]
// 0051eaa4  e8e7ddfcff           call 0x4ec890
// 0051eaa9  8b33                 mov esi, dword ptr [ebx]
// 0051eaab  c784242801000000000000 mov dword ptr [esp + 0x128], 0
// 0051eab6  85ff                 test edi, edi
// 0051eab8  763d                 jbe 0x51eaf7
// 0051eaba  55                   push ebp
// 0051eabb  8bac243c010000       mov ebp, dword ptr [esp + 0x13c]
// 0051eac2  8d4c2410             lea ecx, [esp + 0x10]
// 0051eac6  e885defcff           call 0x4ec950
// 0051eacb  84c0                 test al, al
// 0051eacd  7505                 jne 0x51ead4
// 0051eacf  8b7608               mov esi, dword ptr [esi + 8]
// 0051ead2  eb03                 jmp 0x51ead7
// 0051ead4  8b760c               mov esi, dword ptr [esi + 0xc]
// 0051ead7  837e0800             cmp dword ptr [esi + 8], 0
// 0051eadb  7514                 jne 0x51eaf1
// 0051eadd  837e0c00             cmp dword ptr [esi + 0xc], 0
// 0051eae1  750e                 jne 0x51eaf1
// 0051eae3  6a01                 push 1
// 0051eae5  6a08                 push 8
// 0051eae7  56                   push esi
// 0051eae8  8bcd                 mov ecx, ebp
// 0051eaea  e8e1e4fcff           call 0x4ecfd0
// 0051eaef  8b33                 mov esi, dword ptr [ebx]
// 0051eaf1  83ef01               sub edi, 1
// 0051eaf4  75cc                 jne 0x51eac2
// 0051eaf6  5d                   pop ebp
// 0051eaf7  8d4c240c             lea ecx, [esp + 0xc]
// 0051eafb  c7842428010000ffffffff mov dword ptr [esp + 0x128], 0xffffffff
// 0051eb06  e805defcff           call 0x4ec910
// 0051eb0b  5e                   pop esi
// 0051eb0c  8b8c241c010000       mov ecx, dword ptr [esp + 0x11c]
// 0051eb13  5f                   pop edi
// 0051eb14  5b                   pop ebx
// 0051eb15  64890d00000000       mov dword ptr fs:[0], ecx
// 0051eb1c  81c420010000         add esp, 0x120
// 0051eb22  c20c00               ret 0xc
// library openrbx-raknet/DS_HuffmanEncodingTree.cpp (function ?DecodeArray@HuffmanEncodingTree@@QAEXPAEIPAVBitStream@RakNet@@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-raknet DS_HuffmanEncodingTree.cpp
