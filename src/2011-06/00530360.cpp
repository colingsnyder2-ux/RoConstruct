// from server: 100% by auto
// roc 2011-06 00530360  unit: RBX::Network::ProfiledRakPeer  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00530360
//
// 00530360  83790800             cmp dword ptr [ecx + 8], 0
// 00530364  7625                 jbe 0x53038b
// 00530366  8b01                 mov eax, dword ptr [ecx]
// 00530368  85c0                 test eax, eax
// 0053036a  741f                 je 0x53038b
// 0053036c  8b48fc               mov ecx, dword ptr [eax - 4]
// 0053036f  56                   push esi
// 00530370  8d70fc               lea esi, [eax - 4]
// 00530373  6840b68600           push 0x86b640
// 00530378  51                   push ecx
// 00530379  6a08                 push 8
// 0053037b  50                   push eax
// 0053037c  e857ae2d00           call 0x80b1d8
// 00530381  56                   push esi
// 00530382  e87d9f2d00           call 0x80a304
// 00530387  83c404               add esp, 4
// 0053038a  5e                   pop esi
// 0053038b  c3                   ret 
// library openrbx-raknet/ReliabilityLayer.cpp (function ??1?$List@U?$RangeNode@I@DataStructures@@@DataStructures@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet ReliabilityLayer.cpp
