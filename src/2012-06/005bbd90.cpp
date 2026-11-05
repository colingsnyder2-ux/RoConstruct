// roc 2012-06 005bbd90  unit: RakNet::RakPeer  size: 71 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005bbd90
//
// 005bbd90  56                   push esi
// 005bbd91  8bf1                 mov esi, ecx
// 005bbd93  57                   push edi
// 005bbd94  8dbea0050000         lea edi, [esi + 0x5a0]
// 005bbd9a  8bcf                 mov ecx, edi
// 005bbd9c  e8bfd1e5ff           call 0x418f60
// 005bbda1  8b8ebc050000         mov ecx, dword ptr [esi + 0x5bc]
// 005bbda7  8b86c0050000         mov eax, dword ptr [esi + 0x5c0]
// 005bbdad  3bc8                 cmp ecx, eax
// 005bbdaf  7710                 ja 0x5bbdc1
// 005bbdb1  2bc1                 sub eax, ecx
// 005bbdb3  8bcf                 mov ecx, edi
// 005bbdb5  8bf0                 mov esi, eax
// 005bbdb7  e8b4d1e5ff           call 0x418f70
// 005bbdbc  5f                   pop edi
// 005bbdbd  8bc6                 mov eax, esi
// 005bbdbf  5e                   pop esi
// 005bbdc0  c3                   ret 
// 005bbdc1  8bb6c4050000         mov esi, dword ptr [esi + 0x5c4]
// 005bbdc7  2bf1                 sub esi, ecx
// 005bbdc9  8bcf                 mov ecx, edi
// 005bbdcb  03f0                 add esi, eax
// 005bbdcd  e89ed1e5ff           call 0x418f70
// 005bbdd2  5f                   pop edi
// 005bbdd3  8bc6                 mov eax, esi
// 005bbdd5  5e                   pop esi
// 005bbdd6  c3                   ret 
// copied from an identical function in another client (function ?GetReceiveBufferSize@RakPeer@RakNet@@UAEIXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-raknet RakPeer.cpp