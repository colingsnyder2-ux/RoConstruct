// from server: 100% by auto
// roc 2009-12 005664d0  unit: RakPeer  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005664d0
//
// 005664d0  56                   push esi
// 005664d1  8bf1                 mov esi, ecx
// 005664d3  8b06                 mov eax, dword ptr [esi]
// 005664d5  8b5020               mov edx, dword ptr [eax + 0x20]
// 005664d8  57                   push edi
// 005664d9  ffd2                 call edx
// 005664db  8bce                 mov ecx, esi
// 005664dd  668bf8               mov di, ax
// 005664e0  e81bffffff           call 0x566400
// 005664e5  663bc7               cmp ax, di
// 005664e8  5f                   pop edi
// 005664e9  5e                   pop esi
// 005664ea  1bc0                 sbb eax, eax
// 005664ec  f7d8                 neg eax
// 005664ee  c3                   ret 
// library rbx2016-raknet/RakPeer.cpp (function ?AllowIncomingConnections@RakPeer@RakNet@@IBE_NXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-raknet RakPeer.cpp
