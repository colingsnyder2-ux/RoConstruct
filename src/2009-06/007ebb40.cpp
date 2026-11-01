// from server: 100% by auto
// roc 2009-06 007ebb40  unit: PAVCXTPPropertyGridInplaceButton::?$CArray  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007ebb40
//
// 007ebb40  33c0                 xor eax, eax
// 007ebb42  394128               cmp dword ptr [ecx + 0x28], eax
// 007ebb45  7e18                 jle 0x7ebb5f
// 007ebb47  85c0                 test eax, eax
// 007ebb49  7c15                 jl 0x7ebb60
// 007ebb4b  3b4128               cmp eax, dword ptr [ecx + 0x28]
// 007ebb4e  7d10                 jge 0x7ebb60
// 007ebb50  8b5124               mov edx, dword ptr [ecx + 0x24]
// 007ebb53  8b1482               mov edx, dword ptr [edx + eax*4]
// 007ebb56  894224               mov dword ptr [edx + 0x24], eax
// 007ebb59  40                   inc eax
// 007ebb5a  3b4128               cmp eax, dword ptr [ecx + 0x28]
// 007ebb5d  7ce8                 jl 0x7ebb47
// 007ebb5f  c3                   ret 
// 007ebb60  e97fd1f2ff           jmp 0x718ce4
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGridInplaceButton.cpp (function ?UpdateIndexes@CXTPPropertyGridInplaceButtons@@AAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGridInplaceButton.cpp
