// roc 2012-06 0059a550  unit: RBX::Network::Marker  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0059a550
//
// 0059a550  8b5104               mov edx, dword ptr [ecx + 4]
// 0059a553  8b442404             mov eax, dword ptr [esp + 4]
// 0059a557  c1e204               shl edx, 4
// 0059a55a  0311                 add edx, dword ptr [ecx]
// 0059a55c  8b0a                 mov ecx, dword ptr [edx]
// 0059a55e  8908                 mov dword ptr [eax], ecx
// 0059a560  8b4a04               mov ecx, dword ptr [edx + 4]
// 0059a563  894804               mov dword ptr [eax + 4], ecx
// 0059a566  8b4a08               mov ecx, dword ptr [edx + 8]
// 0059a569  8b520c               mov edx, dword ptr [edx + 0xc]
// 0059a56c  894808               mov dword ptr [eax + 8], ecx
// 0059a56f  89500c               mov dword ptr [eax + 0xc], edx
// 0059a572  c20400               ret 4
// copied from an identical function in another client (function ?Peek@?$Queue@UTimeAndValue@StatisticsHistory@RakNet@@@DataStructures@@QBE?AUTimeAndValue@StatisticsHistory@RakNet@@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 StatisticsHistory.cpp