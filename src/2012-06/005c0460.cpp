// roc 2012-06 005c0460  unit: RakNet::RakPeer  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005c0460
//
// 005c0460  6aff                 push -1
// 005c0462  68eb29ad00           push 0xad29eb
// 005c0467  64a100000000         mov eax, dword ptr fs:[0]
// 005c046d  50                   push eax
// 005c046e  64892500000000       mov dword ptr fs:[0], esp
// 005c0475  51                   push ecx
// 005c0476  56                   push esi
// 005c0477  6850010000           push 0x150
// 005c047c  e8991c3c00           call 0x98211a
// 005c0481  8bf0                 mov esi, eax
// 005c0483  83c404               add esp, 4
// 005c0486  89742404             mov dword ptr [esp + 4], esi
// 005c048a  c744241000000000     mov dword ptr [esp + 0x10], 0
// 005c0492  85f6                 test esi, esi
// 005c0494  742d                 je 0x5c04c3
// 005c0496  8bce                 mov ecx, esi
// 005c0498  e89315faff           call 0x561a30
// 005c049d  c7864401000000000000 mov dword ptr [esi + 0x144], 0
// 005c04a7  c7864801000000000000 mov dword ptr [esi + 0x148], 0
// 005c04b1  8bc6                 mov eax, esi
// 005c04b3  5e                   pop esi
// 005c04b4  8b4c2404             mov ecx, dword ptr [esp + 4]
// 005c04b8  64890d00000000       mov dword ptr fs:[0], ecx
// 005c04bf  83c410               add esp, 0x10
// 005c04c2  c3                   ret 
// 005c04c3  8b4c2408             mov ecx, dword ptr [esp + 8]
// 005c04c7  33c0                 xor eax, eax
// 005c04c9  5e                   pop esi
// 005c04ca  64890d00000000       mov dword ptr fs:[0], ecx
// 005c04d1  83c410               add esp, 0x10
// 005c04d4  c3                   ret 
// copied from an identical function in another client (function ??$OP_NEW@URequestedConnectionStruct@RakPeer@RakNet@@@RakNet@@YAPAURequestedConnectionStruct@RakPeer@0@PBDI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-raknet RakPeer.cpp