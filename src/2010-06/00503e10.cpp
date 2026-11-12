// from server: 100% by auto
// roc 2010-06 00503e10  unit: RBX::Network::ClientReplicator  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00503e10
//
// 00503e10  83790800             cmp dword ptr [ecx + 8], 0
// 00503e14  7625                 jbe 0x503e3b
// 00503e16  8b01                 mov eax, dword ptr [ecx]
// 00503e18  85c0                 test eax, eax
// 00503e1a  741f                 je 0x503e3b
// 00503e1c  8b48fc               mov ecx, dword ptr [eax - 4]
// 00503e1f  56                   push esi
// 00503e20  8d70fc               lea esi, [eax - 4]
// 00503e23  68b0454500           push 0x4545b0
// 00503e28  51                   push ecx
// 00503e29  6a08                 push 8
// 00503e2b  50                   push eax
// 00503e2c  e8ad4c2a00           call 0x7a8ade
// 00503e31  56                   push esi
// 00503e32  e80f3e2a00           call 0x7a7c46
// 00503e37  83c404               add esp, 4
// 00503e3a  5e                   pop esi
// 00503e3b  c3                   ret 
// library openrbx-raknet/ReliabilityLayer.cpp (function ??1?$List@U?$RangeNode@I@DataStructures@@@DataStructures@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet ReliabilityLayer.cpp
