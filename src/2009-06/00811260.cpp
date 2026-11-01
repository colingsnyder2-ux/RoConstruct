// from server: 100% by auto
// roc 2009-06 00811260  unit: CXTPRibbonGroup  size: 56 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00811260
//
// 00811260  8b5128               mov edx, dword ptr [ecx + 0x28]
// 00811263  33c0                 xor eax, eax
// 00811265  85d2                 test edx, edx
// 00811267  7e29                 jle 0x811292
// 00811269  8da42400000000       lea esp, [esp]
// 00811270  85c0                 test eax, eax
// 00811272  7c11                 jl 0x811285
// 00811274  3bc2                 cmp eax, edx
// 00811276  7d0d                 jge 0x811285
// 00811278  3b4128               cmp eax, dword ptr [ecx + 0x28]
// 0081127b  7d16                 jge 0x811293
// 0081127d  8b5124               mov edx, dword ptr [ecx + 0x24]
// 00811280  8b1482               mov edx, dword ptr [edx + eax*4]
// 00811283  eb02                 jmp 0x811287
// 00811285  33d2                 xor edx, edx
// 00811287  89422c               mov dword ptr [edx + 0x2c], eax
// 0081128a  8b5128               mov edx, dword ptr [ecx + 0x28]
// 0081128d  40                   inc eax
// 0081128e  3bc2                 cmp eax, edx
// 00811290  7cde                 jl 0x811270
// 00811292  c3                   ret 
// 00811293  e94c7af0ff           jmp 0x718ce4
// library xtp-15.2.1/Source\Ribbon\XTPRibbonGroups.cpp (function ?RefreshIndexes@CXTPRibbonGroups@@AAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Ribbon/XTPRibbonGroups.cpp
