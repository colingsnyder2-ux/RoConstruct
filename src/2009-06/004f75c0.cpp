// from server: 100% by auto
// roc 2009-06 004f75c0  unit: RBX::Network::ClientReplicator  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004f75c0
//
// 004f75c0  83790800             cmp dword ptr [ecx + 8], 0
// 004f75c4  7625                 jbe 0x4f75eb
// 004f75c6  8b01                 mov eax, dword ptr [ecx]
// 004f75c8  85c0                 test eax, eax
// 004f75ca  741f                 je 0x4f75eb
// 004f75cc  8b48fc               mov ecx, dword ptr [eax - 4]
// 004f75cf  56                   push esi
// 004f75d0  8d70fc               lea esi, [eax - 4]
// 004f75d3  68e0496700           push 0x6749e0
// 004f75d8  51                   push ecx
// 004f75d9  6a08                 push 8
// 004f75db  50                   push eax
// 004f75dc  e895252200           call 0x719b76
// 004f75e1  56                   push esi
// 004f75e2  e8f7162200           call 0x718cde
// 004f75e7  83c404               add esp, 4
// 004f75ea  5e                   pop esi
// 004f75eb  c3                   ret 
// library openrbx-raknet/ReliabilityLayer.cpp (function ??1?$List@U?$RangeNode@I@DataStructures@@@DataStructures@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet ReliabilityLayer.cpp
