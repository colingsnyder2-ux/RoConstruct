// roc 2012-06 005ba9c0  unit: RakNet::RakPeer  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005ba9c0
//
// 005ba9c0  56                   push esi
// 005ba9c1  8bf1                 mov esi, ecx
// 005ba9c3  57                   push edi
// 005ba9c4  8dbe68020000         lea edi, [esi + 0x268]
// 005ba9ca  8bcf                 mov ecx, edi
// 005ba9cc  e88fe5e5ff           call 0x418f60
// 005ba9d1  83c614               add esi, 0x14
// 005ba9d4  8bce                 mov ecx, esi
// 005ba9d6  e805cdfaff           call 0x5676e0
// 005ba9db  8b44240c             mov eax, dword ptr [esp + 0xc]
// 005ba9df  85c0                 test eax, eax
// 005ba9e1  7411                 je 0x5ba9f4
// 005ba9e3  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005ba9e7  85c9                 test ecx, ecx
// 005ba9e9  7609                 jbe 0x5ba9f4
// 005ba9eb  51                   push ecx
// 005ba9ec  50                   push eax
// 005ba9ed  8bce                 mov ecx, esi
// 005ba9ef  e81cd5faff           call 0x567f10
// 005ba9f4  8bcf                 mov ecx, edi
// 005ba9f6  e875e5e5ff           call 0x418f70
// 005ba9fb  5f                   pop edi
// 005ba9fc  5e                   pop esi
// 005ba9fd  c20800               ret 8
// library raknet-4.081/RakPeer.cpp (function ?SetOfflinePingResponse@RakPeer@RakNet@@UAEXPBDI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 RakPeer.cpp
