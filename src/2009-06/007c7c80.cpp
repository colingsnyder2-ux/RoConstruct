// from server: 100% by auto
// roc 2009-06 007c7c80  unit: CXTPReportInplaceList  size: 40 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007c7c80
//
// 007c7c80  8b4138               mov eax, dword ptr [ecx + 0x38]
// 007c7c83  c7818000000000000000 mov dword ptr [ecx + 0x80], 0
// 007c7c8d  85c0                 test eax, eax
// 007c7c8f  750a                 jne 0x7c7c9b
// 007c7c91  8b4120               mov eax, dword ptr [ecx + 0x20]
// 007c7c94  50                   push eax
// 007c7c95  ff1598ee8900         call dword ptr [0x89ee98]
// 007c7c9b  50                   push eax
// 007c7c9c  e86110f5ff           call 0x718d02
// 007c7ca1  8bc8                 mov ecx, eax
// 007c7ca3  e93211f5ff           jmp 0x718dda
// library xtp-13.2.1/Source\ReportControl\XTPReportInplaceControls.cpp (function ?Cancel@CXTPReportInplaceList@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportInplaceControls.cpp
