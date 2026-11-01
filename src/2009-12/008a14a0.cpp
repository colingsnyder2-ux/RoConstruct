// from server: 100% by auto
// roc 2009-12 008a14a0  unit: CXTPReportInplaceList  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008a14a0
//
// 008a14a0  56                   push esi
// 008a14a1  6a00                 push 0
// 008a14a3  8bf1                 mov esi, ecx
// 008a14a5  e8f6c2faff           call 0x84d7a0
// 008a14aa  8b4654               mov eax, dword ptr [esi + 0x54]
// 008a14ad  8b5004               mov edx, dword ptr [eax + 4]
// 008a14b0  8d4e54               lea ecx, [esi + 0x54]
// 008a14b3  83c404               add esp, 4
// 008a14b6  6a00                 push 0
// 008a14b8  ffd2                 call edx
// 008a14ba  8bce                 mov ecx, esi
// 008a14bc  5e                   pop esi
// 008a14bd  e92425f5ff           jmp 0x7f39e6
// library xtp-15.2.1/Source\ReportControl\XTPReportInplaceControls.cpp (function ?PostNcDestroy@CXTPReportInplaceList@@MAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportInplaceControls.cpp
