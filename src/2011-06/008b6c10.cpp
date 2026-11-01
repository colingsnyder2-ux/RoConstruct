// from server: 100% by auto
// roc 2011-06 008b6c10  unit: CXTPReportInplaceList  size: 40 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008b6c10
//
// 008b6c10  8b4138               mov eax, dword ptr [ecx + 0x38]
// 008b6c13  c7818000000000000000 mov dword ptr [ecx + 0x80], 0
// 008b6c1d  85c0                 test eax, eax
// 008b6c1f  750a                 jne 0x8b6c2b
// 008b6c21  8b4120               mov eax, dword ptr [ecx + 0x20]
// 008b6c24  50                   push eax
// 008b6c25  ff15b819a400         call dword ptr [0xa419b8]
// 008b6c2b  50                   push eax
// 008b6c2c  e8f736f5ff           call 0x80a328
// 008b6c31  8bc8                 mov ecx, eax
// 008b6c33  e9c837f5ff           jmp 0x80a400
// library xtp-13.2.1/Source\ReportControl\XTPReportInplaceControls.cpp (function ?Cancel@CXTPReportInplaceList@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportInplaceControls.cpp
