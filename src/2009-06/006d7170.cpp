// from server: 100% by auto
// roc 2009-06 006d7170  unit: RBX::RotateJoint  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006d7170
//
// 006d7170  c70144d08e00         mov dword ptr [ecx], 0x8ed044
// 006d7176  c7412024d08e00       mov dword ptr [ecx + 0x20], 0x8ed024
// 006d717d  e99e0d0000           jmp 0x6d7f20
// library xtp-15.2.1/Source\Chart\Styles\Bar\XTPChartStackedBarSeriesStyle.cpp (function ??1CXTPChartStackedBarSeriesView@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Chart/Styles/Bar/XTPChartStackedBarSeriesStyle.cpp
