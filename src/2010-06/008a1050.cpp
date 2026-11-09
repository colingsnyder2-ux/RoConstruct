// from server: 100% by auto
// roc 2010-06 008a1050  unit: CXTPRibbonGroup  size: 56 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008a1050
//
// 008a1050  8b5128               mov edx, dword ptr [ecx + 0x28]
// 008a1053  33c0                 xor eax, eax
// 008a1055  85d2                 test edx, edx
// 008a1057  7e29                 jle 0x8a1082
// 008a1059  8da42400000000       lea esp, [esp]
// 008a1060  85c0                 test eax, eax
// 008a1062  7c11                 jl 0x8a1075
// 008a1064  3bc2                 cmp eax, edx
// 008a1066  7d0d                 jge 0x8a1075
// 008a1068  3b4128               cmp eax, dword ptr [ecx + 0x28]
// 008a106b  7d16                 jge 0x8a1083
// 008a106d  8b5124               mov edx, dword ptr [ecx + 0x24]
// 008a1070  8b1482               mov edx, dword ptr [edx + eax*4]
// 008a1073  eb02                 jmp 0x8a1077
// 008a1075  33d2                 xor edx, edx
// 008a1077  89422c               mov dword ptr [edx + 0x2c], eax
// 008a107a  8b5128               mov edx, dword ptr [ecx + 0x28]
// 008a107d  40                   inc eax
// 008a107e  3bc2                 cmp eax, edx
// 008a1080  7cde                 jl 0x8a1060
// 008a1082  c3                   ret 
// 008a1083  e9c46bf0ff           jmp 0x7a7c4c
// library xtp-13.2.1/Source\Ribbon\XTPRibbonGroups.cpp (function ?RefreshIndexes@CXTPRibbonGroups@@AAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Ribbon/XTPRibbonGroups.cpp
