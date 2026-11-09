// from server: 100% by auto
// roc 2010-06 00462230  unit: CRobloxReportView::CStatsItemRecord::CValueItem  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00462230
//
// 00462230  56                   push esi
// 00462231  8bf1                 mov esi, ecx
// 00462233  e8c8fdffff           call 0x462000
// 00462238  8bce                 mov ecx, esi
// 0046223a  e8315d3400           call 0x7a7f70
// 0046223f  5e                   pop esi
// 00462240  c20400               ret 4
// library xtp-13.2.1/Source\SyntaxEdit\XTPSyntaxEditColorSampleText.cpp (function ?OnEnable@CXTPSyntaxEditColorSampleText@@QAEXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-13.2.1 Source/SyntaxEdit/XTPSyntaxEditColorSampleText.cpp
