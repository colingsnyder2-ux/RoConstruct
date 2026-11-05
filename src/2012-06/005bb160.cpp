// roc 2012-06 005bb160  unit: RakNet::RakPeer  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005bb160
//
// 005bb160  8b442404             mov eax, dword ptr [esp + 4]
// 005bb164  8b542408             mov edx, dword ptr [esp + 8]
// 005bb168  898164050000         mov dword ptr [ecx + 0x564], eax
// 005bb16e  899168050000         mov dword ptr [ecx + 0x568], edx
// 005bb174  c20800               ret 8
// copied from an identical function in another client (function ?SetUserUpdateThread@RakPeer@RakNet@@UAEXP6AXPAVRakPeerInterface@2@PAX@Z1@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-raknet RakPeer.cpp