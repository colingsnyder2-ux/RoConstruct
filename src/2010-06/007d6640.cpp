// from server: 100% by auto
// roc 2010-06 007d6640  unit: UCXTPReportRowAllocatorData::?$CXTPHeapAllocatorT  size: 66 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007d6640
//
// 007d6640  56                   push esi
// 007d6641  8bf1                 mov esi, ecx
// 007d6643  c706cc91a500         mov dword ptr [esi], 0xa591cc
// 007d6649  833da055c20000       cmp dword ptr [0xc255a0], 0
// 007d6650  751a                 jne 0x7d666c
// 007d6652  a19c55c200           mov eax, dword ptr [0xc2559c]
// 007d6657  85c0                 test eax, eax
// 007d6659  7407                 je 0x7d6662
// 007d665b  50                   push eax
// 007d665c  ff1514a39e00         call dword ptr [0x9ea314]
// 007d6662  c7059c55c20000000000 mov dword ptr [0xc2559c], 0
// 007d666c  f644240801           test byte ptr [esp + 8], 1
// 007d6671  7409                 je 0x7d667c
// 007d6673  56                   push esi
// 007d6674  e82113fdff           call 0x7a799a
// 007d6679  83c404               add esp, 4
// 007d667c  8bc6                 mov eax, esi
// 007d667e  5e                   pop esi
// 007d667f  c20400               ret 4
// library xtp-13.2.1/Source\ReportControl\XTPReportControl.cpp (function ??_G?$CXTPHeapAllocatorT@UCXTPReportDataAllocatorData@@@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportControl.cpp
