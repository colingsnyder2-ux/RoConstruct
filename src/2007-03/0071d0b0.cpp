// from server: 100% by auto
// roc 2007-03 0071d0b0  unit: seg_00710000  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0071d0b0
//
// 0071d0b0  8b4158               mov eax, dword ptr [ecx + 0x58]
// 0071d0b3  83780800             cmp dword ptr [eax + 8], 0
// 0071d0b7  7405                 je 0x71d0be
// 0071d0b9  e982feffff           jmp 0x71cf40
// 0071d0be  c3                   ret 
// library xtp-15.2.1/Source\SkinFramework\XTPSkinObjectListBox.cpp (function ?CheckScrollBarsDraw@CXTPSkinObjectComCtl32Control@@MAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/SkinFramework/XTPSkinObjectListBox.cpp
