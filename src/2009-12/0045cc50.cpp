// from server: 100% by auto
// roc 2009-12 0045cc50  unit: CRobloxReportView::CStatsItemRecord::CValueItem  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0045cc50
//
// 0045cc50  56                   push esi
// 0045cc51  8bf1                 mov esi, ecx
// 0045cc53  e8c8fdffff           call 0x45ca20
// 0045cc58  8bce                 mov ecx, esi
// 0045cc5a  e8d1713900           call 0x7f3e30
// 0045cc5f  5e                   pop esi
// 0045cc60  c20400               ret 4
// library xtp-15.2.1/Source\SyntaxEdit\XTPSyntaxEditColorSampleText.cpp (function ?OnEnable@CXTPSyntaxEditColorSampleText@@QAEXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/SyntaxEdit/XTPSyntaxEditColorSampleText.cpp
