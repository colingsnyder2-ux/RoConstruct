// from server: 100% by auto
// roc 2010-06 00858350  unit: VCXTPReportRow::?$CXTPHeapObjectT  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00858350
//
// 00858350  51                   push ecx
// 00858351  8b4924               mov ecx, dword ptr [ecx + 0x24]
// 00858354  e897b8f7ff           call 0x7d3bf0
// 00858359  c3                   ret 
// library xtp-13.2.1/Source\SkinFramework\XTPSkinObject.cpp (function ?Remove@CXTPSkinObjectClassInfo@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/SkinFramework/XTPSkinObject.cpp
