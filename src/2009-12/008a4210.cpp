// from server: 100% by auto
// roc 2009-12 008a4210  unit: VCXTPReportRow::?$CXTPHeapObjectT  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008a4210
//
// 008a4210  51                   push ecx
// 008a4211  8b4924               mov ecx, dword ptr [ecx + 0x24]
// 008a4214  e877b9f7ff           call 0x81fb90
// 008a4219  c3                   ret 
// library xtp-15.2.1/Source\SkinFramework\XTPSkinObject.cpp (function ?Remove@CXTPSkinObjectClassInfo@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/SkinFramework/XTPSkinObject.cpp
