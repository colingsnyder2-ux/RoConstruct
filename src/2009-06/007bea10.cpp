// from server: 100% by auto
// roc 2009-06 007bea10  unit: CXTPToolBar::CControlButtonHide  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007bea10
//
// 007bea10  c7014c4c9000         mov dword ptr [ecx], 0x904c4c
// 007bea16  c74120ec4b9000       mov dword ptr [ecx + 0x20], 0x904bec
// 007bea1d  e97e2ef6ff           jmp 0x7218a0
// library xtp-15.2.1/Source\Chart\Styles\Bar\XTPChartStackedBarSeriesStyle.cpp (function ??1CXTPChartStackedBarSeriesView@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Chart/Styles/Bar/XTPChartStackedBarSeriesStyle.cpp
