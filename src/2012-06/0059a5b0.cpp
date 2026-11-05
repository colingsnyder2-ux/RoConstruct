// roc 2012-06 0059a5b0  unit: RBX::Network::Marker  size: 76 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0059a5b0
//
// 0059a5b0  ff4104               inc dword ptr [ecx + 4]
// 0059a5b3  8b4104               mov eax, dword ptr [ecx + 4]
// 0059a5b6  8b510c               mov edx, dword ptr [ecx + 0xc]
// 0059a5b9  3bc2                 cmp eax, edx
// 0059a5bb  7507                 jne 0x59a5c4
// 0059a5bd  c7410400000000       mov dword ptr [ecx + 4], 0
// 0059a5c4  8b4104               mov eax, dword ptr [ecx + 4]
// 0059a5c7  85c0                 test eax, eax
// 0059a5c9  750b                 jne 0x59a5d6
// 0059a5cb  8b01                 mov eax, dword ptr [ecx]
// 0059a5cd  c1e204               shl edx, 4
// 0059a5d0  8d4c02f0             lea ecx, [edx + eax - 0x10]
// 0059a5d4  eb09                 jmp 0x59a5df
// 0059a5d6  8b11                 mov edx, dword ptr [ecx]
// 0059a5d8  c1e004               shl eax, 4
// 0059a5db  8d4c10f0             lea ecx, [eax + edx - 0x10]
// 0059a5df  8b442404             mov eax, dword ptr [esp + 4]
// 0059a5e3  8b11                 mov edx, dword ptr [ecx]
// 0059a5e5  8910                 mov dword ptr [eax], edx
// 0059a5e7  8b5104               mov edx, dword ptr [ecx + 4]
// 0059a5ea  895004               mov dword ptr [eax + 4], edx
// 0059a5ed  8b5108               mov edx, dword ptr [ecx + 8]
// 0059a5f0  8b490c               mov ecx, dword ptr [ecx + 0xc]
// 0059a5f3  895008               mov dword ptr [eax + 8], edx
// 0059a5f6  89480c               mov dword ptr [eax + 0xc], ecx
// 0059a5f9  c20400               ret 4
// copied from an identical function in another client (function ?Pop@?$Queue@UTimeAndValue@StatisticsHistory@RakNet@@@DataStructures@@QAE?AUTimeAndValue@StatisticsHistory@RakNet@@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 StatisticsHistory.cpp