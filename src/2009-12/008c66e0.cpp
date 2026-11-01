// from server: 100% by auto
// roc 2009-12 008c66e0  unit: PAVCXTPPropertyGridInplaceButton::?$CArray  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008c66e0
//
// 008c66e0  33c0                 xor eax, eax
// 008c66e2  394128               cmp dword ptr [ecx + 0x28], eax
// 008c66e5  7e18                 jle 0x8c66ff
// 008c66e7  85c0                 test eax, eax
// 008c66e9  7c15                 jl 0x8c6700
// 008c66eb  3b4128               cmp eax, dword ptr [ecx + 0x28]
// 008c66ee  7d10                 jge 0x8c6700
// 008c66f0  8b5124               mov edx, dword ptr [ecx + 0x24]
// 008c66f3  8b1482               mov edx, dword ptr [edx + eax*4]
// 008c66f6  894224               mov dword ptr [edx + 0x24], eax
// 008c66f9  40                   inc eax
// 008c66fa  3b4128               cmp eax, dword ptr [ecx + 0x28]
// 008c66fd  7ce8                 jl 0x8c66e7
// 008c66ff  c3                   ret 
// 008c6700  e907d4f2ff           jmp 0x7f3b0c
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGridInplaceButton.cpp (function ?UpdateIndexes@CXTPPropertyGridInplaceButtons@@AAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGridInplaceButton.cpp
