// from server: 100% by auto
// roc 2009-06 00751b20  unit: CInstanceRecord::CNameItem  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00751b20
//
// 00751b20  56                   push esi
// 00751b21  8bf1                 mov esi, ecx
// 00751b23  e8a8d6feff           call 0x73f1d0
// 00751b28  f644240801           test byte ptr [esp + 8], 1
// 00751b2d  742c                 je 0x751b5b
// 00751b2f  833d0c1aa50000       cmp dword ptr [0xa51a0c], 0
// 00751b36  740f                 je 0x751b47
// 00751b38  56                   push esi
// 00751b39  e83291ccff           call 0x41ac70
// 00751b3e  83c404               add esp, 4
// 00751b41  8bc6                 mov eax, esi
// 00751b43  5e                   pop esi
// 00751b44  c20400               ret 4
// 00751b47  68041aa500           push 0xa51a04
// 00751b4c  ff15a4e18900         call dword ptr [0x89e1a4]
// 00751b52  56                   push esi
// 00751b53  e8da6efcff           call 0x718a32
// 00751b58  83c404               add esp, 4
// 00751b5b  8bc6                 mov eax, esi
// 00751b5d  5e                   pop esi
// 00751b5e  c20400               ret 4
// library xtp-15.2.1/Source\Chart\XTPChartSeriesPoint.cpp (function ??_G?$CXTPHeapObjectT@VCXTPChartSeriesPoint@@VCXTPChartSeriesPointAllocator@@@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Chart/XTPChartSeriesPoint.cpp
