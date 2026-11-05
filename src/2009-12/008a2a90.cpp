// from server: 100% by auto
// roc 2009-12 008a2a90  unit: CXTPReportInplaceList  size: 40 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008a2a90
//
// 008a2a90  8b4138               mov eax, dword ptr [ecx + 0x38]
// 008a2a93  c7818000000000000000 mov dword ptr [ecx + 0x80], 0
// 008a2a9d  85c0                 test eax, eax
// 008a2a9f  750a                 jne 0x8a2aab
// 008a2aa1  8b4120               mov eax, dword ptr [ecx + 0x20]
// 008a2aa4  50                   push eax
// 008a2aa5  ff15bccb9800         call dword ptr [0x98cbbc]
// 008a2aab  50                   push eax
// 008a2aac  e87910f5ff           call 0x7f3b2a
// 008a2ab1  8bc8                 mov ecx, eax
// 008a2ab3  e94a11f5ff           jmp 0x7f3c02
// library xtp-13.2.1/Source\ReportControl\XTPReportInplaceControls.cpp (function ?Cancel@CXTPReportInplaceList@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportInplaceControls.cpp
