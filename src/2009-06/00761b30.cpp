// from server: 100% by auto
// roc 2009-06 00761b30  unit: CXTPControlPopupColor  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00761b30
//
// 00761b30  c7011c818f00         mov dword ptr [ecx], 0x8f811c
// 00761b36  c74120bc808f00       mov dword ptr [ecx + 0x20], 0x8f80bc
// 00761b3d  e94ee2ffff           jmp 0x75fd90
// library xtp-15.2.1/Source\Chart\Styles\Bar\XTPChartStackedBarSeriesStyle.cpp (function ??1CXTPChartStackedBarSeriesView@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Chart/Styles/Bar/XTPChartStackedBarSeriesStyle.cpp
