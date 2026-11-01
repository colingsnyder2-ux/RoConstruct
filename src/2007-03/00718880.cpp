// from server: 100% by auto
// roc 2007-03 00718880  unit: seg_00710000  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00718880
//
// 00718880  56                   push esi
// 00718881  8bf1                 mov esi, ecx
// 00718883  e84a5ef0ff           call 0x61e6d2
// 00718888  6a00                 push 0
// 0071888a  8bce                 mov ecx, esi
// 0071888c  e8ff410000           call 0x71ca90
// 00718891  5e                   pop esi
// 00718892  c20c00               ret 0xc
// library xtp-15.2.1/Source\SkinFramework\XTPSkinObjectMDI.cpp (function ?OnHScroll@CXTPSkinObjectMDIClient@@IAEXIIPAVCScrollBar@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/SkinFramework/XTPSkinObjectMDI.cpp
