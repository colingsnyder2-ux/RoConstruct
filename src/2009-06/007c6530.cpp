// from server: 100% by auto
// roc 2009-06 007c6530  unit: CXTPReportInplaceEdit  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007c6530
//
// 007c6530  56                   push esi
// 007c6531  8bf1                 mov esi, ecx
// 007c6533  837e2000             cmp dword ptr [esi + 0x20], 0
// 007c6537  7414                 je 0x7c654d
// 007c6539  6a00                 push 0
// 007c653b  e8e027f5ff           call 0x718d20
// 007c6540  8b4654               mov eax, dword ptr [esi + 0x54]
// 007c6543  8b5004               mov edx, dword ptr [eax + 4]
// 007c6546  8d4e54               lea ecx, [esi + 0x54]
// 007c6549  6a00                 push 0
// 007c654b  ffd2                 call edx
// 007c654d  5e                   pop esi
// 007c654e  c3                   ret 
// library xtp-15.2.1/Source\ReportControl\XTPReportInplaceEdit.cpp (function ?HideWindow@CXTPReportInplaceEdit@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportInplaceEdit.cpp
