// from server: 100% by EspClaude
// roc 2009-06 004f7cd0  unit: RBX::Network::ClientReplicator  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004f7cd0
//
// 004f7cd0  56                   push esi
// 004f7cd1  8bf1                 mov esi, ecx
// 004f7cd3  837e0800             cmp dword ptr [esi + 8], 0
// 004f7cd7  7430                 je 0x4f7d09
// 004f7cd9  8b06                 mov eax, dword ptr [esi]
// 004f7cdb  50                   push eax
// 004f7cdc  e8fd0f2200           call 0x718cde
// 004f7ce1  83c404               add esp, 4
// 004f7ce4  c7460800000000       mov dword ptr [esi + 8], 0
// 004f7ceb  837e0800             cmp dword ptr [esi + 8], 0
// 004f7cef  c70600000000         mov dword ptr [esi], 0
// 004f7cf5  c7460400000000       mov dword ptr [esi + 4], 0
// 004f7cfc  760b                 jbe 0x4f7d09
// 004f7cfe  8b0e                 mov ecx, dword ptr [esi]
// 004f7d00  51                   push ecx
// 004f7d01  e8d80f2200           call 0x718cde
// 004f7d06  83c404               add esp, 4
// 004f7d09  5e                   pop esi
// 004f7d0a  c3                   ret 
// copied from an identical function in another client (function ??1?$OrderedList@PAUFCM2Participant@FullyConnectedMesh2@RakNet@@PAU123@$1?FCM2ParticipantComp@@YAHABQAU123@0@Z@DataStructures@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 FullyConnectedMesh2.cpp