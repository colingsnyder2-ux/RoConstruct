// from server: 100% by auto
// roc 2009-12 005700e0  unit: CSHA1  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005700e0
//
// 005700e0  8bc1                 mov eax, ecx
// 005700e2  c780c8090000ffffffff mov dword ptr [eax + 0x9c8], 0xffffffff
// 005700ec  c3                   ret 
// library raknet-4.081/Rand.cpp (function ??0RakNetRandom@RakNet@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 Rand.cpp
