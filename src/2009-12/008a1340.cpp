// from server: 100% by auto
// roc 2009-12 008a1340  unit: CXTPReportInplaceEdit  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008a1340
//
// 008a1340  56                   push esi
// 008a1341  8bf1                 mov esi, ecx
// 008a1343  837e2000             cmp dword ptr [esi + 0x20], 0
// 008a1347  7414                 je 0x8a135d
// 008a1349  6a00                 push 0
// 008a134b  e8f827f5ff           call 0x7f3b48
// 008a1350  8b4654               mov eax, dword ptr [esi + 0x54]
// 008a1353  8b5004               mov edx, dword ptr [eax + 4]
// 008a1356  8d4e54               lea ecx, [esi + 0x54]
// 008a1359  6a00                 push 0
// 008a135b  ffd2                 call edx
// 008a135d  5e                   pop esi
// 008a135e  c3                   ret 
// library xtp-15.2.1/Source\ReportControl\XTPReportInplaceEdit.cpp (function ?HideWindow@CXTPReportInplaceEdit@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportInplaceEdit.cpp
