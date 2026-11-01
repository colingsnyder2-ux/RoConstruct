// from server: 100% by auto
// roc 2009-06 006d7f20  unit: RBX::RotatePJoint  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006d7f20
//
// 006d7f20  c701b4d08e00         mov dword ptr [ecx], 0x8ed0b4
// 006d7f26  c7412094d08e00       mov dword ptr [ecx + 0x20], 0x8ed094
// 006d7f2d  e99ee7fcff           jmp 0x6a66d0
// library xtp-15.2.1/Source\Chart\Styles\Bar\XTPChartStackedBarSeriesStyle.cpp (function ??1CXTPChartStackedBarSeriesView@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Chart/Styles/Bar/XTPChartStackedBarSeriesStyle.cpp
