// from server: 100% by auto
// roc 2009-06 007c6690  unit: CXTPReportInplaceList  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007c6690
//
// 007c6690  56                   push esi
// 007c6691  6a00                 push 0
// 007c6693  8bf1                 mov esi, ecx
// 007c6695  e8d6c3faff           call 0x772a70
// 007c669a  8b4654               mov eax, dword ptr [esi + 0x54]
// 007c669d  8b5004               mov edx, dword ptr [eax + 4]
// 007c66a0  8d4e54               lea ecx, [esi + 0x54]
// 007c66a3  83c404               add esp, 4
// 007c66a6  6a00                 push 0
// 007c66a8  ffd2                 call edx
// 007c66aa  8bce                 mov ecx, esi
// 007c66ac  5e                   pop esi
// 007c66ad  e90c25f5ff           jmp 0x718bbe
// library xtp-15.2.1/Source\ReportControl\XTPReportInplaceControls.cpp (function ?PostNcDestroy@CXTPReportInplaceList@@MAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportInplaceControls.cpp
