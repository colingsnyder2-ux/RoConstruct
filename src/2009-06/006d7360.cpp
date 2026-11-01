// from server: 100% by auto
// roc 2009-06 006d7360  unit: RBX::RotateJoint  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006d7360
//
// 006d7360  56                   push esi
// 006d7361  8bf1                 mov esi, ecx
// 006d7363  c70644d08e00         mov dword ptr [esi], 0x8ed044
// 006d7369  c7462024d08e00       mov dword ptr [esi + 0x20], 0x8ed024
// 006d7370  e8ab0b0000           call 0x6d7f20
// 006d7375  f644240801           test byte ptr [esp + 8], 1
// 006d737a  7409                 je 0x6d7385
// 006d737c  56                   push esi
// 006d737d  e8b0160400           call 0x718a32
// 006d7382  83c404               add esp, 4
// 006d7385  8bc6                 mov eax, esi
// 006d7387  5e                   pop esi
// 006d7388  c20400               ret 4
// library xtp-15.2.1/Source\Chart\Styles\Bar\XTPChartStackedBarSeriesStyle.cpp (function ??_GCXTPChartStackedBarSeriesView@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Chart/Styles/Bar/XTPChartStackedBarSeriesStyle.cpp
