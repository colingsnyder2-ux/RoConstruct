// from server: 100% by auto
// roc 2010-06 007d7ca0  unit: VCXTPReportRowAllocator::?$CXTPBatchAllocManagerT  size: 71 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007d7ca0
//
// 007d7ca0  56                   push esi
// 007d7ca1  8bf1                 mov esi, ecx
// 007d7ca3  c706908ea500         mov dword ptr [esi], 0xa58e90
// 007d7ca9  e8a2edffff           call 0x7d6a50
// 007d7cae  833da055c20000       cmp dword ptr [0xc255a0], 0
// 007d7cb5  751a                 jne 0x7d7cd1
// 007d7cb7  a19c55c200           mov eax, dword ptr [0xc2559c]
// 007d7cbc  85c0                 test eax, eax
// 007d7cbe  7407                 je 0x7d7cc7
// 007d7cc0  50                   push eax
// 007d7cc1  ff1514a39e00         call dword ptr [0x9ea314]
// 007d7cc7  c7059c55c20000000000 mov dword ptr [0xc2559c], 0
// 007d7cd1  f644240801           test byte ptr [esp + 8], 1
// 007d7cd6  7409                 je 0x7d7ce1
// 007d7cd8  56                   push esi
// 007d7cd9  e8bcfcfcff           call 0x7a799a
// 007d7cde  83c404               add esp, 4
// 007d7ce1  8bc6                 mov eax, esi
// 007d7ce3  5e                   pop esi
// 007d7ce4  c20400               ret 4
// library xtp-13.2.1/Source\ReportControl\XTPReportControl.cpp (function ??_G?$CXTPBatchAllocManagerT@VCXTPReportRowAllocator@@UCXTPReportRow_BatchData@@@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportControl.cpp
