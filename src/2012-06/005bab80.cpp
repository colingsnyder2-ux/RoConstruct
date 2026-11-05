// roc 2012-06 005bab80  unit: RakNet::RakPeer  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005bab80
//
// 005bab80  8b442404             mov eax, dword ptr [esp + 4]
// 005bab84  8b9158040000         mov edx, dword ptr [ecx + 0x458]
// 005bab8a  8910                 mov dword ptr [eax], edx
// 005bab8c  8b915c040000         mov edx, dword ptr [ecx + 0x45c]
// 005bab92  895004               mov dword ptr [eax + 4], edx
// 005bab95  8b9160040000         mov edx, dword ptr [ecx + 0x460]
// 005bab9b  8b8964040000         mov ecx, dword ptr [ecx + 0x464]
// 005baba1  895008               mov dword ptr [eax + 8], edx
// 005baba4  89480c               mov dword ptr [eax + 0xc], ecx
// 005baba7  c20400               ret 4
// copied from an identical function in another client (function ?GetMyGUID@RakPeer@RakNet@@UBE?BURakNetGUID@2@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-raknet RakPeer.cpp