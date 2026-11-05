// from server: 100% by auto
// roc 2009-12 005553b0  unit: RBX::Network::ClientReplicator  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005553b0
//
// 005553b0  83790800             cmp dword ptr [ecx + 8], 0
// 005553b4  7625                 jbe 0x5553db
// 005553b6  8b01                 mov eax, dword ptr [ecx]
// 005553b8  85c0                 test eax, eax
// 005553ba  741f                 je 0x5553db
// 005553bc  8b48fc               mov ecx, dword ptr [eax - 4]
// 005553bf  56                   push esi
// 005553c0  8d70fc               lea esi, [eax - 4]
// 005553c3  68904a8500           push 0x854a90
// 005553c8  51                   push ecx
// 005553c9  6a08                 push 8
// 005553cb  50                   push eax
// 005553cc  e8d3f52900           call 0x7f49a4
// 005553d1  56                   push esi
// 005553d2  e82fe72900           call 0x7f3b06
// 005553d7  83c404               add esp, 4
// 005553da  5e                   pop esi
// 005553db  c3                   ret 
// library raknet-4.081/CloudClient.cpp (function ??1?$List@UCloudKey@RakNet@@@DataStructures@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 CloudClient.cpp
