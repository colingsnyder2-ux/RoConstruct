// roc 2012-06 005c0be0  unit: RakNet::RakPeer  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005c0be0
//
// 005c0be0  83790800             cmp dword ptr [ecx + 8], 0
// 005c0be4  7625                 jbe 0x5c0c0b
// 005c0be6  8b01                 mov eax, dword ptr [ecx]
// 005c0be8  85c0                 test eax, eax
// 005c0bea  741f                 je 0x5c0c0b
// 005c0bec  8b48fc               mov ecx, dword ptr [eax - 4]
// 005c0bef  56                   push esi
// 005c0bf0  8d70fc               lea esi, [eax - 4]
// 005c0bf3  68e0ed5b00           push 0x5bede0
// 005c0bf8  51                   push ecx
// 005c0bf9  6a08                 push 8
// 005c0bfb  50                   push eax
// 005c0bfc  e86f263c00           call 0x983270
// 005c0c01  56                   push esi
// 005c0c02  e8b3173c00           call 0x9823ba
// 005c0c07  83c404               add esp, 4
// 005c0c0a  5e                   pop esi
// 005c0c0b  c3                   ret 
// library openrbx-raknet/ReliabilityLayer.cpp (function ??1?$List@U?$RangeNode@I@DataStructures@@@DataStructures@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet ReliabilityLayer.cpp
