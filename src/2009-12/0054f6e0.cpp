// from server: 100% by auto
// roc 2009-12 0054f6e0  unit: RBX::Network::IdSerializer  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0054f6e0
//
// 0054f6e0  8b442404             mov eax, dword ptr [esp + 4]
// 0054f6e4  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0054f6e8  8b00                 mov eax, dword ptr [eax]
// 0054f6ea  8b09                 mov ecx, dword ptr [ecx]
// 0054f6ec  3bc1                 cmp eax, ecx
// 0054f6ee  7d04                 jge 0x54f6f4
// 0054f6f0  83c8ff               or eax, 0xffffffff
// 0054f6f3  c3                   ret 
// 0054f6f4  33d2                 xor edx, edx
// 0054f6f6  3bc1                 cmp eax, ecx
// 0054f6f8  0f95c2               setne dl
// 0054f6fb  8bc2                 mov eax, edx
// 0054f6fd  c3                   ret 
// library raknet-4.081/StringCompressor.cpp (function ??$defaultMapKeyComparison@H@DataStructures@@YAHABH0@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 StringCompressor.cpp
