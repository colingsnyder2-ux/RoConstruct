// from server: 100% by auto
// roc 2010-06 007d6dc0  unit: UCXTPReportDataAllocatorData::?$CXTPHeapAllocatorT  size: 66 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007d6dc0
//
// 007d6dc0  56                   push esi
// 007d6dc1  8bf1                 mov esi, ecx
// 007d6dc3  c706c491a500         mov dword ptr [esi], 0xa591c4
// 007d6dc9  833d9055c20000       cmp dword ptr [0xc25590], 0
// 007d6dd0  751a                 jne 0x7d6dec
// 007d6dd2  a18c55c200           mov eax, dword ptr [0xc2558c]
// 007d6dd7  85c0                 test eax, eax
// 007d6dd9  7407                 je 0x7d6de2
// 007d6ddb  50                   push eax
// 007d6ddc  ff1514a39e00         call dword ptr [0x9ea314]
// 007d6de2  c7058c55c20000000000 mov dword ptr [0xc2558c], 0
// 007d6dec  f644240801           test byte ptr [esp + 8], 1
// 007d6df1  7409                 je 0x7d6dfc
// 007d6df3  56                   push esi
// 007d6df4  e8a10bfdff           call 0x7a799a
// 007d6df9  83c404               add esp, 4
// 007d6dfc  8bc6                 mov eax, esi
// 007d6dfe  5e                   pop esi
// 007d6dff  c20400               ret 4
// library xtp-13.2.1/Source\ReportControl\XTPReportControl.cpp (function ??_G?$CXTPHeapAllocatorT@UCXTPReportDataAllocatorData@@@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportControl.cpp
