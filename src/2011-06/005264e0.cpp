// from server: 100% by auto
// roc 2011-06 005264e0  unit: RBX::Network::ProfiledRakPeer  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 005264e0
//
// 005264e0  83790800             cmp dword ptr [ecx + 8], 0
// 005264e4  7625                 jbe 0x52650b
// 005264e6  8b01                 mov eax, dword ptr [ecx]
// 005264e8  85c0                 test eax, eax
// 005264ea  741f                 je 0x52650b
// 005264ec  8b48fc               mov ecx, dword ptr [eax - 4]
// 005264ef  56                   push esi
// 005264f0  8d70fc               lea esi, [eax - 4]
// 005264f3  6800f45000           push 0x50f400
// 005264f8  51                   push ecx
// 005264f9  6a08                 push 8
// 005264fb  50                   push eax
// 005264fc  e8d74c2e00           call 0x80b1d8
// 00526501  56                   push esi
// 00526502  e8fd3d2e00           call 0x80a304
// 00526507  83c404               add esp, 4
// 0052650a  5e                   pop esi
// 0052650b  c3                   ret 
// library openrbx-raknet/ReliabilityLayer.cpp (function ??1?$List@U?$RangeNode@I@DataStructures@@@DataStructures@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet ReliabilityLayer.cpp
