// from server: 100% by auto
// roc 2007-03 0071e5e0  unit: seg_00710000  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0071e5e0
//
// 0071e5e0  51                   push ecx
// 0071e5e1  8b4920               mov ecx, dword ptr [ecx + 0x20]
// 0071e5e4  8d0424               lea eax, [esp]
// 0071e5e7  50                   push eax
// 0071e5e8  6800010000           push 0x100
// 0071e5ed  51                   push ecx
// 0071e5ee  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 0071e5f6  ff155cd07700         call dword ptr [0x77d05c]
// 0071e5fc  f7d8                 neg eax
// 0071e5fe  1bc0                 sbb eax, eax
// 0071e600  f7d8                 neg eax
// 0071e602  59                   pop ecx
// 0071e603  c3                   ret 
// library xtp-15.2.1/Source\SkinFramework\XTPSkinObjectFrame.cpp (function ?IsFlatScrollBarInitialized@CXTPSkinObjectFrame@@IBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/SkinFramework/XTPSkinObjectFrame.cpp
