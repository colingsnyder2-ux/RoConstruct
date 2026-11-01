// from server: 100% by auto
// roc 2007-03 006be060  unit: seg_006b0000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006be060
//
// 006be060  51                   push ecx
// 006be061  8b4924               mov ecx, dword ptr [ecx + 0x24]
// 006be064  e8c778f8ff           call 0x645930
// 006be069  c3                   ret 
// library xtp-15.2.1/Source\SkinFramework\XTPSkinObject.cpp (function ?Remove@CXTPSkinObjectClassInfo@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/SkinFramework/XTPSkinObject.cpp
