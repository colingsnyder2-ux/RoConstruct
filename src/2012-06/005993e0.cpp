// roc 2012-06 005993e0  unit: RBX::Network::ServerReplicator  size: 86 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005993e0
//
// 005993e0  6aff                 push -1
// 005993e2  68eb29ad00           push 0xad29eb
// 005993e7  64a100000000         mov eax, dword ptr fs:[0]
// 005993ed  50                   push eax
// 005993ee  64892500000000       mov dword ptr fs:[0], esp
// 005993f5  51                   push ecx
// 005993f6  6a18                 push 0x18
// 005993f8  e81d8d3e00           call 0x98211a
// 005993fd  83c404               add esp, 4
// 00599400  890424               mov dword ptr [esp], eax
// 00599403  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 0059940b  85c0                 test eax, eax
// 0059940d  7416                 je 0x599425
// 0059940f  8bc8                 mov ecx, eax
// 00599411  e89afeffff           call 0x5992b0
// 00599416  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0059941a  64890d00000000       mov dword ptr fs:[0], ecx
// 00599421  83c410               add esp, 0x10
// 00599424  c3                   ret 
// 00599425  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00599429  33c0                 xor eax, eax
// 0059942b  64890d00000000       mov dword ptr fs:[0], ecx
// 00599432  83c410               add esp, 0x10
// 00599435  c3                   ret 
// copied from an identical function in another client (function ??$OP_NEW@VStringCompressor@RakNet@@@RakNet@@YAPAVStringCompressor@0@PBDI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 StringCompressor.cpp