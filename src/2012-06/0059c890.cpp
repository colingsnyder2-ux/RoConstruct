// roc 2012-06 0059c890  unit: VAuthoringSettings::?$FactoryProduct  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0059c890
//
// 0059c890  83790800             cmp dword ptr [ecx + 8], 0
// 0059c894  7625                 jbe 0x59c8bb
// 0059c896  8b01                 mov eax, dword ptr [ecx]
// 0059c898  85c0                 test eax, eax
// 0059c89a  741f                 je 0x59c8bb
// 0059c89c  8b48fc               mov ecx, dword ptr [eax - 4]
// 0059c89f  56                   push esi
// 0059c8a0  8d70fc               lea esi, [eax - 4]
// 0059c8a3  6890a75900           push 0x59a790
// 0059c8a8  51                   push ecx
// 0059c8a9  6a08                 push 8
// 0059c8ab  50                   push eax
// 0059c8ac  e8bf693e00           call 0x983270
// 0059c8b1  56                   push esi
// 0059c8b2  e8035b3e00           call 0x9823ba
// 0059c8b7  83c404               add esp, 4
// 0059c8ba  5e                   pop esi
// 0059c8bb  c3                   ret 
// library openrbx-raknet/ReliabilityLayer.cpp (function ??1?$List@U?$RangeNode@I@DataStructures@@@DataStructures@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet ReliabilityLayer.cpp
