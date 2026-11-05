// from server: 100% by auto
// roc 2009-12 00565800  unit: RakPeerInterface  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00565800
//
// 00565800  56                   push esi
// 00565801  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00565805  57                   push edi
// 00565806  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0056580a  56                   push esi
// 0056580b  8bcf                 mov ecx, edi
// 0056580d  e8fed81a00           call 0x713110
// 00565812  84c0                 test al, al
// 00565814  7406                 je 0x56581c
// 00565816  5f                   pop edi
// 00565817  83c8ff               or eax, 0xffffffff
// 0056581a  5e                   pop esi
// 0056581b  c3                   ret 
// 0056581c  56                   push esi
// 0056581d  8bcf                 mov ecx, edi
// 0056581f  e89c9afeff           call 0x54f2c0
// 00565824  33c9                 xor ecx, ecx
// 00565826  84c0                 test al, al
// 00565828  0f94c1               sete cl
// 0056582b  5f                   pop edi
// 0056582c  5e                   pop esi
// 0056582d  8bc1                 mov eax, ecx
// 0056582f  c3                   ret 
// library raknet-4.081/CloudServer.cpp (function ??$defaultOrderedListComparison@URakNetGUID@RakNet@@U12@@DataStructures@@YAHABURakNetGUID@RakNet@@0@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 CloudServer.cpp
