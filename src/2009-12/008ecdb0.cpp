// from server: 100% by auto
// roc 2009-12 008ecdb0  unit: CXTPRibbonGroup  size: 56 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008ecdb0
//
// 008ecdb0  8b5128               mov edx, dword ptr [ecx + 0x28]
// 008ecdb3  33c0                 xor eax, eax
// 008ecdb5  85d2                 test edx, edx
// 008ecdb7  7e29                 jle 0x8ecde2
// 008ecdb9  8da42400000000       lea esp, [esp]
// 008ecdc0  85c0                 test eax, eax
// 008ecdc2  7c11                 jl 0x8ecdd5
// 008ecdc4  3bc2                 cmp eax, edx
// 008ecdc6  7d0d                 jge 0x8ecdd5
// 008ecdc8  3b4128               cmp eax, dword ptr [ecx + 0x28]
// 008ecdcb  7d16                 jge 0x8ecde3
// 008ecdcd  8b5124               mov edx, dword ptr [ecx + 0x24]
// 008ecdd0  8b1482               mov edx, dword ptr [edx + eax*4]
// 008ecdd3  eb02                 jmp 0x8ecdd7
// 008ecdd5  33d2                 xor edx, edx
// 008ecdd7  89422c               mov dword ptr [edx + 0x2c], eax
// 008ecdda  8b5128               mov edx, dword ptr [ecx + 0x28]
// 008ecddd  40                   inc eax
// 008ecdde  3bc2                 cmp eax, edx
// 008ecde0  7cde                 jl 0x8ecdc0
// 008ecde2  c3                   ret 
// 008ecde3  e9246df0ff           jmp 0x7f3b0c
// library xtp-15.2.1/Source\Ribbon\XTPRibbonGroups.cpp (function ?RefreshIndexes@CXTPRibbonGroups@@AAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Ribbon/XTPRibbonGroups.cpp
