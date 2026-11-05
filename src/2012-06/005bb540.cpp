// roc 2012-06 005bb540  unit: RakNet::RakPeer  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005bb540
//
// 005bb540  56                   push esi
// 005bb541  8bf1                 mov esi, ecx
// 005bb543  8b06                 mov eax, dword ptr [esi]
// 005bb545  8b5020               mov edx, dword ptr [eax + 0x20]
// 005bb548  57                   push edi
// 005bb549  ffd2                 call edx
// 005bb54b  8bce                 mov ecx, esi
// 005bb54d  668bf8               mov di, ax
// 005bb550  e8fbfdffff           call 0x5bb350
// 005bb555  663bc7               cmp ax, di
// 005bb558  5f                   pop edi
// 005bb559  5e                   pop esi
// 005bb55a  1bc0                 sbb eax, eax
// 005bb55c  f7d8                 neg eax
// 005bb55e  c3                   ret 
// copied from an identical function in another client (function ?AllowIncomingConnections@RakPeer@RakNet@@IBE_NXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-raknet RakPeer.cpp