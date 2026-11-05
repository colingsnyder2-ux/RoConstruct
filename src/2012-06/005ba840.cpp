// roc 2012-06 005ba840  unit: RakNet::RakPeer  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005ba840
//
// 005ba840  53                   push ebx
// 005ba841  56                   push esi
// 005ba842  8bf1                 mov esi, ecx
// 005ba844  57                   push edi
// 005ba845  8dbec8050000         lea edi, [esi + 0x5c8]
// 005ba84b  8bcf                 mov ecx, edi
// 005ba84d  e80ee7e5ff           call 0x418f60
// 005ba852  8b9ee0050000         mov ebx, dword ptr [esi + 0x5e0]
// 005ba858  8d4301               lea eax, [ebx + 1]
// 005ba85b  8986e0050000         mov dword ptr [esi + 0x5e0], eax
// 005ba861  85c0                 test eax, eax
// 005ba863  750a                 jne 0x5ba86f
// 005ba865  c786e005000001000000 mov dword ptr [esi + 0x5e0], 1
// 005ba86f  8bcf                 mov ecx, edi
// 005ba871  e8fae6e5ff           call 0x418f70
// 005ba876  5f                   pop edi
// 005ba877  5e                   pop esi
// 005ba878  8bc3                 mov eax, ebx
// 005ba87a  5b                   pop ebx
// 005ba87b  c3                   ret 
// copied from an identical function in another client (function ?IncrementNextSendReceipt@RakPeer@RakNet@@UAEIXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-raknet RakPeer.cpp