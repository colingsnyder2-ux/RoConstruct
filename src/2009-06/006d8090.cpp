// from server: 100% by auto
// roc 2009-06 006d8090  unit: RBX::MultiJoint  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006d8090
//
// 006d8090  56                   push esi
// 006d8091  8bf1                 mov esi, ecx
// 006d8093  c706b4d08e00         mov dword ptr [esi], 0x8ed0b4
// 006d8099  c7462094d08e00       mov dword ptr [esi + 0x20], 0x8ed094
// 006d80a0  e82be6fcff           call 0x6a66d0
// 006d80a5  f644240801           test byte ptr [esp + 8], 1
// 006d80aa  7409                 je 0x6d80b5
// 006d80ac  56                   push esi
// 006d80ad  e880090400           call 0x718a32
// 006d80b2  83c404               add esp, 4
// 006d80b5  8bc6                 mov eax, esi
// 006d80b7  5e                   pop esi
// 006d80b8  c20400               ret 4
// library xtp-15.2.1/Source\Chart\Styles\Bar\XTPChartStackedBarSeriesStyle.cpp (function ??_GCXTPChartStackedBarSeriesView@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Chart/Styles/Bar/XTPChartStackedBarSeriesStyle.cpp
