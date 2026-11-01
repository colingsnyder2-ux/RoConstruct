// from server: 100% by auto
// roc 2007-03 0071e790  unit: seg_00710000  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0071e790
//
// 0071e790  e82fc40100           call 0x73abc4
// 0071e795  250000c000           and eax, 0xc00000
// 0071e79a  33c9                 xor ecx, ecx
// 0071e79c  3d0000c000           cmp eax, 0xc00000
// 0071e7a1  0f94c1               sete cl
// 0071e7a4  8bc1                 mov eax, ecx
// 0071e7a6  c3                   ret 
// library xtp-15.2.1/Source\SkinFramework\XTPSkinObjectFrame.cpp (function ?HasCaption@CXTPSkinObjectFrame@@IBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/SkinFramework/XTPSkinObjectFrame.cpp
