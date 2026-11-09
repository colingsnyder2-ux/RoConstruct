// from server: 100% by auto
// roc 2010-06 00856c10  unit: CXTPReportInplaceList  size: 40 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00856c10
//
// 00856c10  8b4138               mov eax, dword ptr [ecx + 0x38]
// 00856c13  c7818000000000000000 mov dword ptr [ecx + 0x80], 0
// 00856c1d  85c0                 test eax, eax
// 00856c1f  750a                 jne 0x856c2b
// 00856c21  8b4120               mov eax, dword ptr [ecx + 0x20]
// 00856c24  50                   push eax
// 00856c25  ff154cba9e00         call dword ptr [0x9eba4c]
// 00856c2b  50                   push eax
// 00856c2c  e83910f5ff           call 0x7a7c6a
// 00856c31  8bc8                 mov ecx, eax
// 00856c33  e90a11f5ff           jmp 0x7a7d42
// library xtp-13.2.1/Source\ReportControl\XTPReportInplaceControls.cpp (function ?Cancel@CXTPReportInplaceList@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportInplaceControls.cpp
