// from server: 100% by auto
// roc 2007-03 006bafd0  unit: seg_006b0000  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006bafd0
//
// 006bafd0  56                   push esi
// 006bafd1  8bf1                 mov esi, ecx
// 006bafd3  837e2000             cmp dword ptr [esi + 0x20], 0
// 006bafd7  7414                 je 0x6bafed
// 006bafd9  6a00                 push 0
// 006bafdb  e8f833f6ff           call 0x61e3d8
// 006bafe0  8b4654               mov eax, dword ptr [esi + 0x54]
// 006bafe3  8b5004               mov edx, dword ptr [eax + 4]
// 006bafe6  8d4e54               lea ecx, [esi + 0x54]
// 006bafe9  6a00                 push 0
// 006bafeb  ffd2                 call edx
// 006bafed  5e                   pop esi
// 006bafee  c3                   ret 
// library xtp-15.2.1/Source\ReportControl\XTPReportInplaceEdit.cpp (function ?HideWindow@CXTPReportInplaceEdit@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportInplaceEdit.cpp
