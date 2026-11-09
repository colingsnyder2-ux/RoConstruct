// roc 2012-06 005baf40  unit: RakNet::RakPeer  size: 66 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005baf40
//
// 005baf40  56                   push esi
// 005baf41  8bf1                 mov esi, ecx
// 005baf43  8b06                 mov eax, dword ptr [esi]
// 005baf45  8b503c               mov edx, dword ptr [eax + 0x3c]
// 005baf48  ffd2                 call edx
// 005baf4a  84c0                 test al, al
// 005baf4c  750f                 jne 0x5baf5d
// 005baf4e  8d8698040000         lea eax, [esi + 0x498]
// 005baf54  50                   push eax
// 005baf55  e8867bfeff           call 0x5a2ae0
// 005baf5a  83c404               add esp, 4
// 005baf5d  8b442408             mov eax, dword ptr [esp + 8]
// 005baf61  6a7c                 push 0x7c
// 005baf63  68205ee200           push 0xe25e20
// 005baf68  8d0c80               lea ecx, [eax + eax*4]
// 005baf6b  6a00                 push 0
// 005baf6d  8d8c8e98040000       lea ecx, [esi + ecx*4 + 0x498]
// 005baf74  e8a76afaff           call 0x561a20
// 005baf79  b8205ee200           mov eax, 0xe25e20
// 005baf7e  5e                   pop esi
// 005baf7f  c20400               ret 4
// copied from an identical function in another client (function ?GetLocalIP@RakPeer@RakNet@@UAEPBDI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-raknet RakPeer.cpp