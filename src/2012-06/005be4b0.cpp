// roc 2012-06 005be4b0  unit: RakNet::RakPeer  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005be4b0
//
// 005be4b0  51                   push ecx
// 005be4b1  56                   push esi
// 005be4b2  8b74240c             mov esi, dword ptr [esp + 0xc]
// 005be4b6  57                   push edi
// 005be4b7  6a01                 push 1
// 005be4b9  6a08                 push 8
// 005be4bb  8d442413             lea eax, [esp + 0x13]
// 005be4bf  8bf9                 mov edi, ecx
// 005be4c1  50                   push eax
// 005be4c2  8bce                 mov ecx, esi
// 005be4c4  c64424170d           mov byte ptr [esp + 0x17], 0xd
// 005be4c9  e8c298faff           call 0x567d90
// 005be4ce  81c758040000         add edi, 0x458
// 005be4d4  57                   push edi
// 005be4d5  8bce                 mov ecx, esi
// 005be4d7  e894dafaff           call 0x56bf70
// 005be4dc  6a10                 push 0x10
// 005be4de  684403b800           push 0xb80344
// 005be4e3  8bce                 mov ecx, esi
// 005be4e5  e8b69afaff           call 0x567fa0
// 005be4ea  5f                   pop edi
// 005be4eb  5e                   pop esi
// 005be4ec  59                   pop ecx
// 005be4ed  c20400               ret 4
// copied from an identical function in another client (function ?WriteOutOfBandHeader@RakPeer@RakNet@@UAEXPAVBitStream@2@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-raknet RakPeer.cpp