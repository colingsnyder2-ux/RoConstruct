// from server: 100% by tester
// roc 2007-03 004badf0  unit: seg_004b0000  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 004badf0
//
// 004badf0  83790800             cmp dword ptr [ecx + 8], 0
// 004badf4  7625                 jbe 0x4bae1b
// 004badf6  8b01                 mov eax, dword ptr [ecx]
// 004badf8  85c0                 test eax, eax
// 004badfa  741f                 je 0x4bae1b
// 004badfc  8b48fc               mov ecx, dword ptr [eax - 4]
// 004badff  56                   push esi
// 004bae00  8d70fc               lea esi, [eax - 4]
// 004bae03  68c07d6900           push 0x697dc0
// 004bae08  51                   push ecx
// 004bae09  6a04                 push 4
// 004bae0b  50                   push eax
// 004bae0c  e874411600           call 0x61ef85
// 004bae11  56                   push esi
// 004bae12  e8d9321600           call 0x61e0f0
// 004bae17  83c404               add esp, 4
// 004bae1a  5e                   pop esi
// 004bae1b  c3                   ret 
// library raknet-4.081/MessageFilter.cpp (function ??1?$List@VRakString@RakNet@@@DataStructures@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 MessageFilter.cpp
