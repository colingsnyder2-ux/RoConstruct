// from server: 100% by auto
// roc 2007-03 006f4140  unit: seg_006f0000  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006f4140
//
// 006f4140  8b4920               mov ecx, dword ptr [ecx + 0x20]
// 006f4143  85c9                 test ecx, ecx
// 006f4145  7505                 jne 0x6f414c
// 006f4147  33c0                 xor eax, eax
// 006f4149  c20800               ret 8
// 006f414c  e86fa8f2ff           call 0x61e9c0
// 006f4151  c20800               ret 8
// library xtp-15.2.1/Source\SkinFramework\XTPSkinObject.cpp (function ?CreateObject@CXTPSkinObjectClassInfo@@UAEPAVCXTPSkinObject@@PBDPAUtagCREATESTRUCTA@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/SkinFramework/XTPSkinObject.cpp
