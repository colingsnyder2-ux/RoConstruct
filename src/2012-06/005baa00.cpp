// roc 2012-06 005baa00  unit: RakNet::RakPeer  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005baa00
//
// 005baa00  56                   push esi
// 005baa01  8bf1                 mov esi, ecx
// 005baa03  57                   push edi
// 005baa04  8dbe68020000         lea edi, [esi + 0x268]
// 005baa0a  8bcf                 mov ecx, edi
// 005baa0c  e84fe5e5ff           call 0x418f60
// 005baa11  8b4620               mov eax, dword ptr [esi + 0x20]
// 005baa14  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005baa18  8901                 mov dword ptr [ecx], eax
// 005baa1a  8b5614               mov edx, dword ptr [esi + 0x14]
// 005baa1d  8b442410             mov eax, dword ptr [esp + 0x10]
// 005baa21  83c207               add edx, 7
// 005baa24  c1ea03               shr edx, 3
// 005baa27  8bcf                 mov ecx, edi
// 005baa29  8910                 mov dword ptr [eax], edx
// 005baa2b  e840e5e5ff           call 0x418f70
// 005baa30  5f                   pop edi
// 005baa31  5e                   pop esi
// 005baa32  c20800               ret 8
// library raknet-4.081/RakPeer.cpp (function ?GetOfflinePingResponse@RakPeer@RakNet@@UAEXPAPADPAI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 RakPeer.cpp
