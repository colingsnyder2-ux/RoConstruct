// from server: 100% by auto
// roc 2010-06 008554c0  unit: CXTPReportInplaceEdit  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008554c0
//
// 008554c0  56                   push esi
// 008554c1  8bf1                 mov esi, ecx
// 008554c3  837e2000             cmp dword ptr [esi + 0x20], 0
// 008554c7  7414                 je 0x8554dd
// 008554c9  6a00                 push 0
// 008554cb  e8b827f5ff           call 0x7a7c88
// 008554d0  8b4654               mov eax, dword ptr [esi + 0x54]
// 008554d3  8b5004               mov edx, dword ptr [eax + 4]
// 008554d6  8d4e54               lea ecx, [esi + 0x54]
// 008554d9  6a00                 push 0
// 008554db  ffd2                 call edx
// 008554dd  5e                   pop esi
// 008554de  c3                   ret 
// library xtp-13.2.1/Source\ReportControl\XTPReportInplaceControls.cpp (function ?HideWindow@CXTPReportInplaceEdit@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportInplaceControls.cpp
