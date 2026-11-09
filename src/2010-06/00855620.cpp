// from server: 100% by auto
// roc 2010-06 00855620  unit: CXTPReportInplaceList  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00855620
//
// 00855620  56                   push esi
// 00855621  6a00                 push 0
// 00855623  8bf1                 mov esi, ecx
// 00855625  e8d6c1faff           call 0x801800
// 0085562a  8b4654               mov eax, dword ptr [esi + 0x54]
// 0085562d  8b5004               mov edx, dword ptr [eax + 4]
// 00855630  8d4e54               lea ecx, [esi + 0x54]
// 00855633  83c404               add esp, 4
// 00855636  6a00                 push 0
// 00855638  ffd2                 call edx
// 0085563a  8bce                 mov ecx, esi
// 0085563c  5e                   pop esi
// 0085563d  e9e424f5ff           jmp 0x7a7b26
// library xtp-13.2.1/Source\ReportControl\XTPReportInplaceControls.cpp (function ?PostNcDestroy@CXTPReportInplaceList@@MAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportInplaceControls.cpp
