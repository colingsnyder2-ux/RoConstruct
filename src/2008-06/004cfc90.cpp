// from server: 100% by auto
// roc 2008-06 004cfc90  unit: RBX::Network::PhysicsSender  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004cfc90
//
// 004cfc90  83790800             cmp dword ptr [ecx + 8], 0
// 004cfc94  7625                 jbe 0x4cfcbb
// 004cfc96  8b01                 mov eax, dword ptr [ecx]
// 004cfc98  85c0                 test eax, eax
// 004cfc9a  741f                 je 0x4cfcbb
// 004cfc9c  8b48fc               mov ecx, dword ptr [eax - 4]
// 004cfc9f  56                   push esi
// 004cfca0  8d70fc               lea esi, [eax - 4]
// 004cfca3  6810d44700           push 0x47d410
// 004cfca8  51                   push ecx
// 004cfca9  6a08                 push 8
// 004cfcab  50                   push eax
// 004cfcac  e8aa191d00           call 0x6a165b
// 004cfcb1  56                   push esi
// 004cfcb2  e8c3091d00           call 0x6a067a
// 004cfcb7  83c404               add esp, 4
// 004cfcba  5e                   pop esi
// 004cfcbb  c3                   ret 
// library openrbx-raknet/ReliabilityLayer.cpp (function ??1?$List@U?$RangeNode@I@DataStructures@@@DataStructures@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet ReliabilityLayer.cpp
