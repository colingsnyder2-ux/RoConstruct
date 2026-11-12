// from server: 100% by auto
// roc 2010-06 004fdfd0  unit: RBX::Network::IdSerializer  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004fdfd0
//
// 004fdfd0  8b442404             mov eax, dword ptr [esp + 4]
// 004fdfd4  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004fdfd8  8b00                 mov eax, dword ptr [eax]
// 004fdfda  8b09                 mov ecx, dword ptr [ecx]
// 004fdfdc  3bc1                 cmp eax, ecx
// 004fdfde  7d04                 jge 0x4fdfe4
// 004fdfe0  83c8ff               or eax, 0xffffffff
// 004fdfe3  c3                   ret 
// 004fdfe4  33d2                 xor edx, edx
// 004fdfe6  3bc1                 cmp eax, ecx
// 004fdfe8  0f95c2               setne dl
// 004fdfeb  8bc2                 mov eax, edx
// 004fdfed  c3                   ret 
// library openrbx-raknet/StringCompressor.cpp (function ??$defaultMapKeyComparison@H@DataStructures@@YAHABH0@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet StringCompressor.cpp
