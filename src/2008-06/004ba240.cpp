// from server: 100% by auto
// roc 2008-06 004ba240  unit: RBX::Network::IdSerializer  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004ba240
//
// 004ba240  8b442404             mov eax, dword ptr [esp + 4]
// 004ba244  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004ba248  8b00                 mov eax, dword ptr [eax]
// 004ba24a  8b09                 mov ecx, dword ptr [ecx]
// 004ba24c  3bc1                 cmp eax, ecx
// 004ba24e  7d04                 jge 0x4ba254
// 004ba250  83c8ff               or eax, 0xffffffff
// 004ba253  c3                   ret 
// 004ba254  33d2                 xor edx, edx
// 004ba256  3bc1                 cmp eax, ecx
// 004ba258  0f95c2               setne dl
// 004ba25b  8bc2                 mov eax, edx
// 004ba25d  c3                   ret 
// library openrbx-raknet/StringCompressor.cpp (function ??$defaultMapKeyComparison@H@DataStructures@@YAHABH0@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet StringCompressor.cpp
