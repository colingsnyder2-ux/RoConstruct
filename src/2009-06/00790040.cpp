// from server: 100% by auto
// roc 2009-06 00790040  unit: CXTPPropertyGridItemEnum  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00790040
//
// 00790040  c70124f58f00         mov dword ptr [ecx], 0x8ff524
// 00790046  c74120c4f48f00       mov dword ptr [ecx + 0x20], 0x8ff4c4
// 0079004d  e9aebdffff           jmp 0x78be00
// library xtp-15.2.1/Source\Chart\Styles\Bar\XTPChartStackedBarSeriesStyle.cpp (function ??1CXTPChartStackedBarSeriesView@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Chart/Styles/Bar/XTPChartStackedBarSeriesStyle.cpp
