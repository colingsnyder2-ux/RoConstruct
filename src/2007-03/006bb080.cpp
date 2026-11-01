// from server: 100% by auto
// roc 2007-03 006bb080  unit: seg_006b0000  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006bb080
//
// 006bb080  56                   push esi
// 006bb081  6a00                 push 0
// 006bb083  8bf1                 mov esi, ecx
// 006bb085  e8a62bfbff           call 0x66dc30
// 006bb08a  8b4654               mov eax, dword ptr [esi + 0x54]
// 006bb08d  8b5004               mov edx, dword ptr [eax + 4]
// 006bb090  8d4e54               lea ecx, [esi + 0x54]
// 006bb093  83c404               add esp, 4
// 006bb096  6a00                 push 0
// 006bb098  ffd2                 call edx
// 006bb09a  8bce                 mov ecx, esi
// 006bb09c  5e                   pop esi
// 006bb09d  e9da31f6ff           jmp 0x61e27c
// library xtp-15.2.1/Source\ReportControl\XTPReportInplaceControls.cpp (function ?PostNcDestroy@CXTPReportInplaceList@@MAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportInplaceControls.cpp
