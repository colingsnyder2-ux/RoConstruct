// roc 2012-06 0059afe0  unit: VAuthoringSettings::?$FactoryProduct  size: 281 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0059afe0
//
// 0059afe0  56                   push esi
// 0059afe1  8bf1                 mov esi, ecx
// 0059afe3  837e0c00             cmp dword ptr [esi + 0xc], 0
// 0059afe7  7550                 jne 0x59b039
// 0059afe9  33c9                 xor ecx, ecx
// 0059afeb  b810000000           mov eax, 0x10
// 0059aff0  8bd0                 mov edx, eax
// 0059aff2  f7e2                 mul edx
// 0059aff4  0f90c1               seto cl
// 0059aff7  f7d9                 neg ecx
// 0059aff9  0bc8                 or ecx, eax
// 0059affb  51                   push ecx
// 0059affc  e8ef733e00           call 0x9823f0
// 0059b001  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0059b005  8906                 mov dword ptr [esi], eax
// 0059b007  c7460400000000       mov dword ptr [esi + 4], 0
// 0059b00e  c7460801000000       mov dword ptr [esi + 8], 1
// 0059b015  8b11                 mov edx, dword ptr [ecx]
// 0059b017  8910                 mov dword ptr [eax], edx
// 0059b019  8b5104               mov edx, dword ptr [ecx + 4]
// 0059b01c  895004               mov dword ptr [eax + 4], edx
// 0059b01f  8b5108               mov edx, dword ptr [ecx + 8]
// 0059b022  895008               mov dword ptr [eax + 8], edx
// 0059b025  8b490c               mov ecx, dword ptr [ecx + 0xc]
// 0059b028  83c404               add esp, 4
// 0059b02b  89480c               mov dword ptr [eax + 0xc], ecx
// 0059b02e  c7460c10000000       mov dword ptr [esi + 0xc], 0x10
// 0059b035  5e                   pop esi
// 0059b036  c20c00               ret 0xc
// 0059b039  8b4608               mov eax, dword ptr [esi + 8]
// 0059b03c  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0059b040  8b11                 mov edx, dword ptr [ecx]
// 0059b042  c1e004               shl eax, 4
// 0059b045  0306                 add eax, dword ptr [esi]
// 0059b047  8910                 mov dword ptr [eax], edx
// 0059b049  8b5104               mov edx, dword ptr [ecx + 4]
// 0059b04c  895004               mov dword ptr [eax + 4], edx
// 0059b04f  8b5108               mov edx, dword ptr [ecx + 8]
// 0059b052  895008               mov dword ptr [eax + 8], edx
// 0059b055  8b490c               mov ecx, dword ptr [ecx + 0xc]
// 0059b058  89480c               mov dword ptr [eax + 0xc], ecx
// 0059b05b  ff4608               inc dword ptr [esi + 8]
// 0059b05e  8b4e08               mov ecx, dword ptr [esi + 8]
// 0059b061  8b460c               mov eax, dword ptr [esi + 0xc]
// 0059b064  3bc8                 cmp ecx, eax
// 0059b066  7507                 jne 0x59b06f
// 0059b068  c7460800000000       mov dword ptr [esi + 8], 0
// 0059b06f  8b5608               mov edx, dword ptr [esi + 8]
// 0059b072  3b5604               cmp edx, dword ptr [esi + 4]
// 0059b075  757e                 jne 0x59b0f5
// 0059b077  03c0                 add eax, eax
// 0059b079  747a                 je 0x59b0f5
// 0059b07b  33c9                 xor ecx, ecx
// 0059b07d  ba10000000           mov edx, 0x10
// 0059b082  f7e2                 mul edx
// 0059b084  0f90c1               seto cl
// 0059b087  53                   push ebx
// 0059b088  f7d9                 neg ecx
// 0059b08a  0bc8                 or ecx, eax
// 0059b08c  51                   push ecx
// 0059b08d  e85e733e00           call 0x9823f0
// 0059b092  8bd8                 mov ebx, eax
// 0059b094  83c404               add esp, 4
// 0059b097  85db                 test ebx, ebx
// 0059b099  7459                 je 0x59b0f4
// 0059b09b  57                   push edi
// 0059b09c  33ff                 xor edi, edi
// 0059b09e  397e0c               cmp dword ptr [esi + 0xc], edi
// 0059b0a1  7631                 jbe 0x59b0d4
// 0059b0a3  8bcb                 mov ecx, ebx
// 0059b0a5  8b4604               mov eax, dword ptr [esi + 4]
// 0059b0a8  03c7                 add eax, edi
// 0059b0aa  33d2                 xor edx, edx
// 0059b0ac  f7760c               div dword ptr [esi + 0xc]
// 0059b0af  47                   inc edi
// 0059b0b0  83c110               add ecx, 0x10
// 0059b0b3  c1e204               shl edx, 4
// 0059b0b6  0316                 add edx, dword ptr [esi]
// 0059b0b8  8b02                 mov eax, dword ptr [edx]
// 0059b0ba  8941f0               mov dword ptr [ecx - 0x10], eax
// 0059b0bd  8b4204               mov eax, dword ptr [edx + 4]
// 0059b0c0  8941f4               mov dword ptr [ecx - 0xc], eax
// 0059b0c3  8b4208               mov eax, dword ptr [edx + 8]
// 0059b0c6  8941f8               mov dword ptr [ecx - 8], eax
// 0059b0c9  8b520c               mov edx, dword ptr [edx + 0xc]
// 0059b0cc  8951fc               mov dword ptr [ecx - 4], edx
// 0059b0cf  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 0059b0d2  72d1                 jb 0x59b0a5
// 0059b0d4  8b460c               mov eax, dword ptr [esi + 0xc]
// 0059b0d7  8b0e                 mov ecx, dword ptr [esi]
// 0059b0d9  894608               mov dword ptr [esi + 8], eax
// 0059b0dc  03c0                 add eax, eax
// 0059b0de  51                   push ecx
// 0059b0df  c7460400000000       mov dword ptr [esi + 4], 0
// 0059b0e6  89460c               mov dword ptr [esi + 0xc], eax
// 0059b0e9  e8cc723e00           call 0x9823ba
// 0059b0ee  83c404               add esp, 4
// 0059b0f1  891e                 mov dword ptr [esi], ebx
// 0059b0f3  5f                   pop edi
// 0059b0f4  5b                   pop ebx
// 0059b0f5  5e                   pop esi
// 0059b0f6  c20c00               ret 0xc
// copied from an identical function in another client (function ?Push@?$Queue@UTimeAndValue@StatisticsHistory@RakNet@@@DataStructures@@QAEXABUTimeAndValue@StatisticsHistory@RakNet@@PBDI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 StatisticsHistory.cpp