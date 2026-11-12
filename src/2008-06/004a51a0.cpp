// from server: 100% by auto
// roc 2008-06 004a51a0  unit: RBX::VHint::?$FactoryProduct::Creator  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004a51a0
//
// 004a51a0  80791000             cmp byte ptr [ecx + 0x10], 0
// 004a51a4  7414                 je 0x4a51ba
// 004a51a6  81790400080000       cmp dword ptr [ecx + 4], 0x800
// 004a51ad  7e0b                 jle 0x4a51ba
// 004a51af  8b410c               mov eax, dword ptr [ecx + 0xc]
// 004a51b2  50                   push eax
// 004a51b3  ff15c0288000         call dword ptr [0x8028c0]
// 004a51b9  59                   pop ecx
// 004a51ba  c3                   ret 
// library openrbx-raknet/BitStream.cpp (function ??1BitStream@RakNet@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet BitStream.cpp
