// from server: 100% by auto
// roc 2011-06 0050c790  unit: RBX::Network::ServerReplicator  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0050c790
//
// 0050c790  8b442404             mov eax, dword ptr [esp + 4]
// 0050c794  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0050c798  8b00                 mov eax, dword ptr [eax]
// 0050c79a  8b09                 mov ecx, dword ptr [ecx]
// 0050c79c  3bc1                 cmp eax, ecx
// 0050c79e  7d04                 jge 0x50c7a4
// 0050c7a0  83c8ff               or eax, 0xffffffff
// 0050c7a3  c3                   ret 
// 0050c7a4  33d2                 xor edx, edx
// 0050c7a6  3bc1                 cmp eax, ecx
// 0050c7a8  0f95c2               setne dl
// 0050c7ab  8bc2                 mov eax, edx
// 0050c7ad  c3                   ret 
// library openrbx-raknet/StringCompressor.cpp (function ??$defaultMapKeyComparison@H@DataStructures@@YAHABH0@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet StringCompressor.cpp
