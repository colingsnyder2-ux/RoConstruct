// from server: 100% by auto
// roc 2008-06 004ceb60  unit: RBX::Network::PhysicsSender  size: 155 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004ceb60
//
// 004ceb60  51                   push ecx
// 004ceb61  55                   push ebp
// 004ceb62  56                   push esi
// 004ceb63  8bf1                 mov esi, ecx
// 004ceb65  8dae28050000         lea ebp, [esi + 0x528]
// 004ceb6b  57                   push edi
// 004ceb6c  8bcd                 mov ecx, ebp
// 004ceb6e  e81d6e0000           call 0x4d5990
// 004ceb73  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004ceb77  84c0                 test al, al
// 004ceb79  8b07                 mov eax, dword ptr [edi]
// 004ceb7b  7436                 je 0x4cebb3
// 004ceb7d  8b4f0c               mov ecx, dword ptr [edi + 0xc]
// 004ceb80  53                   push ebx
// 004ceb81  8d542410             lea edx, [esp + 0x10]
// 004ceb85  52                   push edx
// 004ceb86  83c007               add eax, 7
// 004ceb89  c1f803               sar eax, 3
// 004ceb8c  51                   push ecx
// 004ceb8d  50                   push eax
// 004ceb8e  51                   push ecx
// 004ceb8f  8bcd                 mov ecx, ebp
// 004ceb91  89442420             mov dword ptr [esp + 0x20], eax
// 004ceb95  8bd8                 mov ebx, eax
// 004ceb97  e8646e0000           call 0x4d5a00
// 004ceb9c  8b442410             mov eax, dword ptr [esp + 0x10]
// 004ceba0  8bc8                 mov ecx, eax
// 004ceba2  2bcb                 sub ecx, ebx
// 004ceba4  03c9                 add ecx, ecx
// 004ceba6  03c9                 add ecx, ecx
// 004ceba8  03c9                 add ecx, ecx
// 004cebaa  898e54040000         mov dword ptr [esi + 0x454], ecx
// 004cebb0  5b                   pop ebx
// 004cebb1  eb0a                 jmp 0x4cebbd
// 004cebb3  83c007               add eax, 7
// 004cebb6  c1f803               sar eax, 3
// 004cebb9  8944240c             mov dword ptr [esp + 0xc], eax
// 004cebbd  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 004cebc1  ff8650040000         inc dword ptr [esi + 0x450]
// 004cebc7  8d0cc500000000       lea ecx, [eax*8]
// 004cebce  018e58040000         add dword ptr [esi + 0x458], ecx
// 004cebd4  018eb0040000         add dword ptr [esi + 0x4b0], ecx
// 004cebda  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004cebde  52                   push edx
// 004cebdf  8b570c               mov edx, dword ptr [edi + 0xc]
// 004cebe2  51                   push ecx
// 004cebe3  50                   push eax
// 004cebe4  8b442420             mov eax, dword ptr [esp + 0x20]
// 004cebe8  52                   push edx
// 004cebe9  50                   push eax
// 004cebea  b9311d9700           mov ecx, 0x971d31
// 004cebef  e88cfbffff           call 0x4ce780
// 004cebf4  5f                   pop edi
// 004cebf5  5e                   pop esi
// 004cebf6  5d                   pop ebp
// 004cebf7  59                   pop ecx
// 004cebf8  c21000               ret 0x10
// library openrbx-raknet/ReliabilityLayer.cpp (function ?SendBitStream@ReliabilityLayer@@AAEXIUSystemAddress@@PAVBitStream@RakNet@@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet ReliabilityLayer.cpp
