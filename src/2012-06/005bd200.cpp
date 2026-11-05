// roc 2012-06 005bd200  unit: RakNet::RakPeer  size: 188 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005bd200
//
// 005bd200  64a100000000         mov eax, dword ptr fs:[0]
// 005bd206  6aff                 push -1
// 005bd208  68512aab00           push 0xab2a51
// 005bd20d  50                   push eax
// 005bd20e  64892500000000       mov dword ptr fs:[0], esp
// 005bd215  56                   push esi
// 005bd216  8bf1                 mov esi, ecx
// 005bd218  57                   push edi
// 005bd219  8dbe74050000         lea edi, [esi + 0x574]
// 005bd21f  8bcf                 mov ecx, edi
// 005bd221  e83abde5ff           call 0x418f60
// 005bd226  8b442424             mov eax, dword ptr [esp + 0x24]
// 005bd22a  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 005bd22e  50                   push eax
// 005bd22f  51                   push ecx
// 005bd230  8d8e8c050000         lea ecx, [esi + 0x58c]
// 005bd236  e8d5f4ffff           call 0x5bc710
// 005bd23b  8bf0                 mov esi, eax
// 005bd23d  8bcf                 mov ecx, edi
// 005bd23f  89742424             mov dword ptr [esp + 0x24], esi
// 005bd243  e828bde5ff           call 0x418f70
// 005bd248  89742420             mov dword ptr [esp + 0x20], esi
// 005bd24c  c744241000000000     mov dword ptr [esp + 0x10], 0
// 005bd254  85f6                 test esi, esi
// 005bd256  7413                 je 0x5bd26b
// 005bd258  8bce                 mov ecx, esi
// 005bd25a  e8d147faff           call 0x561a30
// 005bd25f  8d4e18               lea ecx, [esi + 0x18]
// 005bd262  e8794afaff           call 0x561ce0
// 005bd267  8bc6                 mov eax, esi
// 005bd269  eb02                 jmp 0x5bd26d
// 005bd26b  33c0                 xor eax, eax
// 005bd26d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 005bd271  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 005bd275  894828               mov dword ptr [eax + 0x28], ecx
// 005bd278  03c9                 add ecx, ecx
// 005bd27a  895030               mov dword ptr [eax + 0x30], edx
// 005bd27d  03c9                 add ecx, ecx
// 005bd27f  c6403401             mov byte ptr [eax + 0x34], 1
// 005bd283  03c9                 add ecx, ecx
// 005bd285  89482c               mov dword ptr [eax + 0x2c], ecx
// 005bd288  8b15f815d900         mov edx, dword ptr [0xd915f8]
// 005bd28e  895018               mov dword ptr [eax + 0x18], edx
// 005bd291  8b0dfc15d900         mov ecx, dword ptr [0xd915fc]
// 005bd297  89481c               mov dword ptr [eax + 0x1c], ecx
// 005bd29a  668b150016d900       mov dx, word ptr [0xd91600]
// 005bd2a1  8b4c2408             mov ecx, dword ptr [esp + 8]
// 005bd2a5  66895020             mov word ptr [eax + 0x20], dx
// 005bd2a9  5f                   pop edi
// 005bd2aa  c6403500             mov byte ptr [eax + 0x35], 0
// 005bd2ae  64890d00000000       mov dword ptr fs:[0], ecx
// 005bd2b5  5e                   pop esi
// 005bd2b6  83c40c               add esp, 0xc
// 005bd2b9  c21000               ret 0x10
// copied from an identical function in another client (function ?AllocPacket@RakPeer@RakNet@@IAEPAUPacket@2@IPAEPBDI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-raknet RakPeer.cpp