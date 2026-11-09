// from server: 100% by auto
// roc 2010-06 007d7c50  unit: VCXTPReportRowAllocator::?$CXTPBatchAllocManagerT  size: 71 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007d7c50
//
// 007d7c50  56                   push esi
// 007d7c51  8bf1                 mov esi, ecx
// 007d7c53  c706888ea500         mov dword ptr [esi], 0xa58e88
// 007d7c59  e812ecffff           call 0x7d6870
// 007d7c5e  833da055c20000       cmp dword ptr [0xc255a0], 0
// 007d7c65  751a                 jne 0x7d7c81
// 007d7c67  a19c55c200           mov eax, dword ptr [0xc2559c]
// 007d7c6c  85c0                 test eax, eax
// 007d7c6e  7407                 je 0x7d7c77
// 007d7c70  50                   push eax
// 007d7c71  ff1514a39e00         call dword ptr [0x9ea314]
// 007d7c77  c7059c55c20000000000 mov dword ptr [0xc2559c], 0
// 007d7c81  f644240801           test byte ptr [esp + 8], 1
// 007d7c86  7409                 je 0x7d7c91
// 007d7c88  56                   push esi
// 007d7c89  e80cfdfcff           call 0x7a799a
// 007d7c8e  83c404               add esp, 4
// 007d7c91  8bc6                 mov eax, esi
// 007d7c93  5e                   pop esi
// 007d7c94  c20400               ret 4
// library xtp-13.2.1/Source\ReportControl\XTPReportControl.cpp (function ??_G?$CXTPBatchAllocManagerT@VCXTPReportRowAllocator@@UCXTPReportRow_BatchData@@@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportControl.cpp
