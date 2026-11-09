// roc 2012-06 005bdef0  unit: RakNet::RakPeer  size: 190 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005bdef0
//
// 005bdef0  56                   push esi
// 005bdef1  8bf1                 mov esi, ecx
// 005bdef3  684c69e200           push 0xe2694c
// 005bdef8  8d4c2410             lea ecx, [esp + 0x10]
// 005bdefc  e89f39faff           call 0x5618a0
// 005bdf01  84c0                 test al, al
// 005bdf03  7410                 je 0x5bdf15
// 005bdf05  8b442420             mov eax, dword ptr [esp + 0x20]
// 005bdf09  8d0480               lea eax, [eax + eax*4]
// 005bdf0c  8d8c8698040000       lea ecx, [esi + eax*4 + 0x498]
// 005bdf13  eb75                 jmp 0x5bdf8a
// 005bdf15  8b54240c             mov edx, dword ptr [esp + 0xc]
// 005bdf19  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005bdf1d  6a01                 push 1
// 005bdf1f  6a00                 push 0
// 005bdf21  83ec14               sub esp, 0x14
// 005bdf24  8bc4                 mov eax, esp
// 005bdf26  8910                 mov dword ptr [eax], edx
// 005bdf28  8b542430             mov edx, dword ptr [esp + 0x30]
// 005bdf2c  894804               mov dword ptr [eax + 4], ecx
// 005bdf2f  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 005bdf33  895008               mov dword ptr [eax + 8], edx
// 005bdf36  8b542438             mov edx, dword ptr [esp + 0x38]
// 005bdf3a  89480c               mov dword ptr [eax + 0xc], ecx
// 005bdf3d  8bce                 mov ecx, esi
// 005bdf3f  895010               mov dword ptr [eax + 0x10], edx
// 005bdf42  e8b9dfffff           call 0x5bbf00
// 005bdf47  85c0                 test eax, eax
// 005bdf49  7534                 jne 0x5bdf7f
// 005bdf4b  8b442408             mov eax, dword ptr [esp + 8]
// 005bdf4f  8b0d4c69e200         mov ecx, dword ptr [0xe2694c]
// 005bdf55  8b155069e200         mov edx, dword ptr [0xe26950]
// 005bdf5b  8908                 mov dword ptr [eax], ecx
// 005bdf5d  8b0d5469e200         mov ecx, dword ptr [0xe26954]
// 005bdf63  895004               mov dword ptr [eax + 4], edx
// 005bdf66  8b155869e200         mov edx, dword ptr [0xe26958]
// 005bdf6c  894808               mov dword ptr [eax + 8], ecx
// 005bdf6f  8b0d5c69e200         mov ecx, dword ptr [0xe2695c]
// 005bdf75  89500c               mov dword ptr [eax + 0xc], edx
// 005bdf78  894810               mov dword ptr [eax + 0x10], ecx
// 005bdf7b  5e                   pop esi
// 005bdf7c  c21c00               ret 0x1c
// 005bdf7f  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 005bdf83  8d1489               lea edx, [ecx + ecx*4]
// 005bdf86  8d4c902c             lea ecx, [eax + edx*4 + 0x2c]
// 005bdf8a  8b442408             mov eax, dword ptr [esp + 8]
// 005bdf8e  8b11                 mov edx, dword ptr [ecx]
// 005bdf90  8910                 mov dword ptr [eax], edx
// 005bdf92  8b5104               mov edx, dword ptr [ecx + 4]
// 005bdf95  895004               mov dword ptr [eax + 4], edx
// 005bdf98  8b5108               mov edx, dword ptr [ecx + 8]
// 005bdf9b  895008               mov dword ptr [eax + 8], edx
// 005bdf9e  8b510c               mov edx, dword ptr [ecx + 0xc]
// 005bdfa1  8b4910               mov ecx, dword ptr [ecx + 0x10]
// 005bdfa4  89500c               mov dword ptr [eax + 0xc], edx
// 005bdfa7  894810               mov dword ptr [eax + 0x10], ecx
// 005bdfaa  5e                   pop esi
// 005bdfab  c21c00               ret 0x1c
// copied from an identical function in another client (function ?GetInternalID@RakPeer@RakNet@@UBE?AUSystemAddress@2@U32@H@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-raknet RakPeer.cpp