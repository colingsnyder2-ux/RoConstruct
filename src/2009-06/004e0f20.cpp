// from server: 100% by auto
// roc 2009-06 004e0f20  unit: RBX::Network::IdSerializer  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004e0f20
//
// 004e0f20  8b442404             mov eax, dword ptr [esp + 4]
// 004e0f24  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004e0f28  8b00                 mov eax, dword ptr [eax]
// 004e0f2a  8b09                 mov ecx, dword ptr [ecx]
// 004e0f2c  3bc1                 cmp eax, ecx
// 004e0f2e  7d04                 jge 0x4e0f34
// 004e0f30  83c8ff               or eax, 0xffffffff
// 004e0f33  c3                   ret 
// 004e0f34  33d2                 xor edx, edx
// 004e0f36  3bc1                 cmp eax, ecx
// 004e0f38  0f95c2               setne dl
// 004e0f3b  8bc2                 mov eax, edx
// 004e0f3d  c3                   ret 
// library openrbx-raknet/StringCompressor.cpp (function ??$defaultMapKeyComparison@H@DataStructures@@YAHABH0@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet StringCompressor.cpp
