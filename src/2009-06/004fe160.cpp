// from server: 100% by auto
// roc 2009-06 004fe160  unit: RakPeerInterface  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004fe160
//
// 004fe160  56                   push esi
// 004fe161  8b74240c             mov esi, dword ptr [esp + 0xc]
// 004fe165  57                   push edi
// 004fe166  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 004fe16a  56                   push esi
// 004fe16b  8bcf                 mov ecx, edi
// 004fe16d  e86e28feff           call 0x4e09e0
// 004fe172  84c0                 test al, al
// 004fe174  7406                 je 0x4fe17c
// 004fe176  5f                   pop edi
// 004fe177  83c8ff               or eax, 0xffffffff
// 004fe17a  5e                   pop esi
// 004fe17b  c3                   ret 
// 004fe17c  56                   push esi
// 004fe17d  8bcf                 mov ecx, edi
// 004fe17f  e8fc27feff           call 0x4e0980
// 004fe184  33c9                 xor ecx, ecx
// 004fe186  84c0                 test al, al
// 004fe188  0f94c1               sete cl
// 004fe18b  5f                   pop edi
// 004fe18c  5e                   pop esi
// 004fe18d  8bc1                 mov eax, ecx
// 004fe18f  c3                   ret 
// library openrbx-raknet/RakPeer.cpp (function ?SystemAddressAndIndexComp@@YAHABUSystemAddress@@ABUSystemAddressAndIndex@@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
