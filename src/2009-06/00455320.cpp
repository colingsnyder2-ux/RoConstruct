// from server: 100% by auto
// roc 2009-06 00455320  unit: CRobloxReportView::CStatsItemRecord::CValueItem  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00455320
//
// 00455320  56                   push esi
// 00455321  8bf1                 mov esi, ecx
// 00455323  e8b8fdffff           call 0x4550e0
// 00455328  8bce                 mov ecx, esi
// 0045532a  e8d93c2c00           call 0x719008
// 0045532f  5e                   pop esi
// 00455330  c20400               ret 4
// library xtp-15.2.1/Source\SyntaxEdit\XTPSyntaxEditColorSampleText.cpp (function ?OnEnable@CXTPSyntaxEditColorSampleText@@QAEXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/SyntaxEdit/XTPSyntaxEditColorSampleText.cpp
