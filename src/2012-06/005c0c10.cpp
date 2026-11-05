// roc 2012-06 005c0c10  unit: RakNet::RakPeer  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005c0c10
//
// 005c0c10  56                   push esi
// 005c0c11  8b742408             mov esi, dword ptr [esp + 8]
// 005c0c15  85f6                 test esi, esi
// 005c0c17  7447                 je 0x5c0c60
// 005c0c19  8b8648010000         mov eax, dword ptr [esi + 0x148]
// 005c0c1f  85c0                 test eax, eax
// 005c0c21  7434                 je 0x5c0c57
// 005c0c23  8300ff               add dword ptr [eax], -1
// 005c0c26  752f                 jne 0x5c0c57
// 005c0c28  57                   push edi
// 005c0c29  8bbe44010000         mov edi, dword ptr [esi + 0x144]
// 005c0c2f  85ff                 test edi, edi
// 005c0c31  7410                 je 0x5c0c43
// 005c0c33  8bcf                 mov ecx, edi
// 005c0c35  e8a6870000           call 0x5c93e0
// 005c0c3a  57                   push edi
// 005c0c3b  e8d4143c00           call 0x982114
// 005c0c40  83c404               add esp, 4
// 005c0c43  8b8648010000         mov eax, dword ptr [esi + 0x148]
// 005c0c49  5f                   pop edi
// 005c0c4a  85c0                 test eax, eax
// 005c0c4c  7409                 je 0x5c0c57
// 005c0c4e  50                   push eax
// 005c0c4f  e8c0143c00           call 0x982114
// 005c0c54  83c404               add esp, 4
// 005c0c57  56                   push esi
// 005c0c58  e8b7143c00           call 0x982114
// 005c0c5d  83c404               add esp, 4
// 005c0c60  5e                   pop esi
// 005c0c61  c3                   ret 
// copied from an identical function in another client (function ??$OP_DELETE@URequestedConnectionStruct@RakPeer@RakNet@@@RakNet@@YAXPAURequestedConnectionStruct@RakPeer@0@PBDI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-raknet RakPeer.cpp