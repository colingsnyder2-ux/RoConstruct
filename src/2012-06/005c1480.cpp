// roc 2012-06 005c1480  unit: RakNet::RakPeer  size: 72 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005c1480
//
// 005c1480  56                   push esi
// 005c1481  8b742408             mov esi, dword ptr [esp + 8]
// 005c1485  837e0800             cmp dword ptr [esi + 8], 0
// 005c1489  7439                 je 0x5c14c4
// 005c148b  8b06                 mov eax, dword ptr [esi]
// 005c148d  85c0                 test eax, eax
// 005c148f  741f                 je 0x5c14b0
// 005c1491  8b48fc               mov ecx, dword ptr [eax - 4]
// 005c1494  57                   push edi
// 005c1495  8d78fc               lea edi, [eax - 4]
// 005c1498  68e0ed5b00           push 0x5bede0
// 005c149d  51                   push ecx
// 005c149e  6a08                 push 8
// 005c14a0  50                   push eax
// 005c14a1  e8ca1d3c00           call 0x983270
// 005c14a6  57                   push edi
// 005c14a7  e80e0f3c00           call 0x9823ba
// 005c14ac  83c404               add esp, 4
// 005c14af  5f                   pop edi
// 005c14b0  c7460800000000       mov dword ptr [esi + 8], 0
// 005c14b7  c70600000000         mov dword ptr [esi], 0
// 005c14bd  c7460400000000       mov dword ptr [esi + 4], 0
// 005c14c4  5e                   pop esi
// 005c14c5  c20400               ret 4
// copied from an identical function in another client (function ?ReleaseSockets@RakPeer@RakNet@@UAEXAAV?$List@V?$RakNetSmartPtr@URakNetSocket@RakNet@@@RakNet@@@DataStructures@@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-raknet RakPeer.cpp