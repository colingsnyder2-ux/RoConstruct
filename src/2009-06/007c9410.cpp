// from server: 100% by auto
// roc 2009-06 007c9410  unit: VCXTPReportRow::?$CXTPHeapObjectT  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007c9410
//
// 007c9410  51                   push ecx
// 007c9411  8b4924               mov ecx, dword ptr [ecx + 0x24]
// 007c9414  e867b9f7ff           call 0x744d80
// 007c9419  c3                   ret 
// library xtp-15.2.1/Source\SkinFramework\XTPSkinObject.cpp (function ?Remove@CXTPSkinObjectClassInfo@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/SkinFramework/XTPSkinObject.cpp
