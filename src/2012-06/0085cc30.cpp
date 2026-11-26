// from server: 100% by Xemicl
// roc 2012-06 0085cc30  unit: std::D::V?$allocator::V?$basic_gzip_compressor::?$stream_buffer  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0085cc30
//
// 0085cc30  56                   push esi
// 0085cc31  8bf1                 mov esi, ecx
// 0085cc33  8d4e24               lea ecx, [esi + 0x24]
// 0085cc36  ff15a425b200         call dword ptr [0xb225a4]
// 0085cc3c  33c0                 xor eax, eax
// 0085cc3e  894640               mov dword ptr [esi + 0x40], eax
// 0085cc41  894644               mov dword ptr [esi + 0x44], eax
// 0085cc44  5e                   pop esi
// 0085cc45  c3                   ret 
// copied from an identical function in another client (function ?reset@S@@QAEXXZ)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <string>
struct S {
    char pad[0x24];
    std::string s;
    int a;
    int b;
    void reset();
};
void S::reset() { s.clear(); a = 0; b = 0; }