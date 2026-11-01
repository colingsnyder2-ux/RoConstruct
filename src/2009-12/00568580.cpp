// from server: 100% by auto
// roc 2009-12 00568580  unit: RakPeer  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00568580
//
// 00568580  83790800             cmp dword ptr [ecx + 8], 0
// 00568584  7625                 jbe 0x5685ab
// 00568586  8b01                 mov eax, dword ptr [ecx]
// 00568588  85c0                 test eax, eax
// 0056858a  741f                 je 0x5685ab
// 0056858c  8b48fc               mov ecx, dword ptr [eax - 4]
// 0056858f  56                   push esi
// 00568590  8d70fc               lea esi, [eax - 4]
// 00568593  68a0c45500           push 0x55c4a0
// 00568598  51                   push ecx
// 00568599  6a04                 push 4
// 0056859b  50                   push eax
// 0056859c  e803c42800           call 0x7f49a4
// 005685a1  56                   push esi
// 005685a2  e85fb52800           call 0x7f3b06
// 005685a7  83c404               add esp, 4
// 005685aa  5e                   pop esi
// 005685ab  c3                   ret 
// library raknet-4.081/MessageFilter.cpp (function ??1?$List@VRakString@RakNet@@@DataStructures@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 MessageFilter.cpp
