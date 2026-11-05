// from server: 100% by auto
// roc 2009-12 0088c0b0  unit: CXTPCustomizeSheet::CCustomizeEdit  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0088c0b0
//
// 0088c0b0  56                   push esi
// 0088c0b1  8bf1                 mov esi, ecx
// 0088c0b3  e838dcf6ff           call 0x7f9cf0
// 0088c0b8  c706fc2ea000         mov dword ptr [esi], 0xa02efc
// 0088c0be  c7466000000000       mov dword ptr [esi + 0x60], 0
// 0088c0c5  8bc6                 mov eax, esi
// 0088c0c7  5e                   pop esi
// 0088c0c8  c3                   ret 
// library raknet-4.081/RakNetSocket2.cpp (function ??0RNS2_Windows@RakNet@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 RakNetSocket2.cpp
