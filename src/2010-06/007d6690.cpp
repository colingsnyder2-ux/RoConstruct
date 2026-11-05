// from server: 100% by auto
// roc 2010-06 007d6690  unit: UCXTPReportAllocatorDefaultData::?$CXTPHeapAllocatorT  size: 66 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007d6690
//
// 007d6690  56                   push esi
// 007d6691  8bf1                 mov esi, ecx
// 007d6693  c706d491a500         mov dword ptr [esi], 0xa591d4
// 007d6699  833db055c20000       cmp dword ptr [0xc255b0], 0
// 007d66a0  751a                 jne 0x7d66bc
// 007d66a2  a1ac55c200           mov eax, dword ptr [0xc255ac]
// 007d66a7  85c0                 test eax, eax
// 007d66a9  7407                 je 0x7d66b2
// 007d66ab  50                   push eax
// 007d66ac  ff1514a39e00         call dword ptr [0x9ea314]
// 007d66b2  c705ac55c20000000000 mov dword ptr [0xc255ac], 0
// 007d66bc  f644240801           test byte ptr [esp + 8], 1
// 007d66c1  7409                 je 0x7d66cc
// 007d66c3  56                   push esi
// 007d66c4  e8d112fdff           call 0x7a799a
// 007d66c9  83c404               add esp, 4
// 007d66cc  8bc6                 mov eax, esi
// 007d66ce  5e                   pop esi
// 007d66cf  c20400               ret 4
// library xtp-13.2.1/Source\ReportControl\XTPReportControl.cpp (function ??_G?$CXTPHeapAllocatorT@UCXTPReportDataAllocatorData@@@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportControl.cpp
