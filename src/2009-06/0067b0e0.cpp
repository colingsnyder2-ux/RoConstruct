// from server: 100% by auto
// roc 2009-06 0067b0e0  unit: RBX::RigidJoint  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0067b0e0
//
// 0067b0e0  56                   push esi
// 0067b0e1  8bf1                 mov esi, ecx
// 0067b0e3  c706ec4b8e00         mov dword ptr [esi], 0x8e4bec
// 0067b0e9  c74620cc4b8e00       mov dword ptr [esi + 0x20], 0x8e4bcc
// 0067b0f0  e8dbb50200           call 0x6a66d0
// 0067b0f5  f644240801           test byte ptr [esp + 8], 1
// 0067b0fa  7409                 je 0x67b105
// 0067b0fc  56                   push esi
// 0067b0fd  e830d90900           call 0x718a32
// 0067b102  83c404               add esp, 4
// 0067b105  8bc6                 mov eax, esi
// 0067b107  5e                   pop esi
// 0067b108  c20400               ret 4
// library xtp-15.2.1/Source\Chart\Styles\Bar\XTPChartStackedBarSeriesStyle.cpp (function ??_GCXTPChartStackedBarSeriesView@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Chart/Styles/Bar/XTPChartStackedBarSeriesStyle.cpp
