// roc 2012-06 005ba810  unit: RakNet::RakPeer  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005ba810
//
// 005ba810  56                   push esi
// 005ba811  8bf1                 mov esi, ecx
// 005ba813  57                   push edi
// 005ba814  8dbec8050000         lea edi, [esi + 0x5c8]
// 005ba81a  8bcf                 mov ecx, edi
// 005ba81c  e83fe7e5ff           call 0x418f60
// 005ba821  8bb6e0050000         mov esi, dword ptr [esi + 0x5e0]
// 005ba827  8bcf                 mov ecx, edi
// 005ba829  e842e7e5ff           call 0x418f70
// 005ba82e  5f                   pop edi
// 005ba82f  8bc6                 mov eax, esi
// 005ba831  5e                   pop esi
// 005ba832  c3                   ret 
// copied from an identical function in another client (function ?GetNextSendReceipt@RakPeer@RakNet@@UAEIXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-raknet RakPeer.cpp