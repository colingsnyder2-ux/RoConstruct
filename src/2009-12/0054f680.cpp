// from server: 100% by auto
// roc 2009-12 0054f680  unit: RBX::Network::IdSerializer  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0054f680
//
// 0054f680  6aff                 push -1
// 0054f682  68eba59400           push 0x94a5eb
// 0054f687  64a100000000         mov eax, dword ptr fs:[0]
// 0054f68d  50                   push eax
// 0054f68e  64892500000000       mov dword ptr fs:[0], esp
// 0054f695  51                   push ecx
// 0054f696  6804080000           push 0x804
// 0054f69b  e8c0412a00           call 0x7f3860
// 0054f6a0  83c404               add esp, 4
// 0054f6a3  890424               mov dword ptr [esp], eax
// 0054f6a6  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 0054f6ae  85c0                 test eax, eax
// 0054f6b0  7416                 je 0x54f6c8
// 0054f6b2  8bc8                 mov ecx, eax
// 0054f6b4  e847c8f7ff           call 0x4cbf00
// 0054f6b9  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0054f6bd  64890d00000000       mov dword ptr fs:[0], ecx
// 0054f6c4  83c410               add esp, 0x10
// 0054f6c7  c3                   ret 
// 0054f6c8  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0054f6cc  33c0                 xor eax, eax
// 0054f6ce  64890d00000000       mov dword ptr fs:[0], ecx
// 0054f6d5  83c410               add esp, 0x10
// 0054f6d8  c3                   ret 
// library raknet-4.081/StringCompressor.cpp (function ??$OP_NEW@VHuffmanEncodingTree@RakNet@@@RakNet@@YAPAVHuffmanEncodingTree@0@PBDI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 StringCompressor.cpp
