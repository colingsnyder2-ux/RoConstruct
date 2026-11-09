// from server: 100% by auto
// roc 2009-12 0054f510  unit: RBX::Network::IdSerializer  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0054f510
//
// 0054f510  56                   push esi
// 0054f511  8bf1                 mov esi, ecx
// 0054f513  837e0800             cmp dword ptr [esi + 8], 0
// 0054f517  7430                 je 0x54f549
// 0054f519  8b06                 mov eax, dword ptr [esi]
// 0054f51b  50                   push eax
// 0054f51c  e8e5452a00           call 0x7f3b06
// 0054f521  83c404               add esp, 4
// 0054f524  c7460800000000       mov dword ptr [esi + 8], 0
// 0054f52b  837e0800             cmp dword ptr [esi + 8], 0
// 0054f52f  c70600000000         mov dword ptr [esi], 0
// 0054f535  c7460400000000       mov dword ptr [esi + 4], 0
// 0054f53c  760b                 jbe 0x54f549
// 0054f53e  8b0e                 mov ecx, dword ptr [esi]
// 0054f540  51                   push ecx
// 0054f541  e8c0452a00           call 0x7f3b06
// 0054f546  83c404               add esp, 4
// 0054f549  5e                   pop esi
// 0054f54a  c3                   ret 
// library raknet-4.081/CloudServer.cpp (function ??1?$OrderedList@URakNetGUID@RakNet@@U12@$1??$defaultOrderedListComparison@URakNetGUID@RakNet@@U12@@DataStructures@@YAHABU12@0@Z@DataStructures@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 CloudServer.cpp
