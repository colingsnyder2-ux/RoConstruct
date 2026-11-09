// from server: 100% by auto
// roc 2010-06 0087a880  unit: PAVCXTPPropertyGridInplaceButton::?$CArray  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0087a880
//
// 0087a880  33c0                 xor eax, eax
// 0087a882  394128               cmp dword ptr [ecx + 0x28], eax
// 0087a885  7e18                 jle 0x87a89f
// 0087a887  85c0                 test eax, eax
// 0087a889  7c15                 jl 0x87a8a0
// 0087a88b  3b4128               cmp eax, dword ptr [ecx + 0x28]
// 0087a88e  7d10                 jge 0x87a8a0
// 0087a890  8b5124               mov edx, dword ptr [ecx + 0x24]
// 0087a893  8b1482               mov edx, dword ptr [edx + eax*4]
// 0087a896  894224               mov dword ptr [edx + 0x24], eax
// 0087a899  40                   inc eax
// 0087a89a  3b4128               cmp eax, dword ptr [ecx + 0x28]
// 0087a89d  7ce8                 jl 0x87a887
// 0087a89f  c3                   ret 
// 0087a8a0  e9a7d3f2ff           jmp 0x7a7c4c
// library xtp-13.2.1/Source\PropertyGrid\XTPPropertyGridInplaceButton.cpp (function ?UpdateIndexes@CXTPPropertyGridInplaceButtons@@AAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/PropertyGrid/XTPPropertyGridInplaceButton.cpp
