// from server: 100% by auto
// roc 2009-06 0078bf40  unit: CPropertyGridItemBrickColor  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0078bf40
//
// 0078bf40  c70114e88f00         mov dword ptr [ecx], 0x8fe814
// 0078bf46  c74120b4e78f00       mov dword ptr [ecx + 0x20], 0x8fe7b4
// 0078bf4d  e9aefeffff           jmp 0x78be00
// library xtp-15.2.1/Source\Chart\Styles\Bar\XTPChartStackedBarSeriesStyle.cpp (function ??1CXTPChartStackedBarSeriesView@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Chart/Styles/Bar/XTPChartStackedBarSeriesStyle.cpp
