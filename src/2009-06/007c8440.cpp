// from server: 100% by auto
// roc 2009-06 007c8440  unit: PAVCXTPReportHyperlink::?$CXTPArrayT  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007c8440
//
// 007c8440  8b442408             mov eax, dword ptr [esp + 8]
// 007c8444  85c0                 test eax, eax
// 007c8446  740f                 je 0x7c8457
// 007c8448  83c020               add eax, 0x20
// 007c844b  89442408             mov dword ptr [esp + 8], eax
// 007c844f  83c120               add ecx, 0x20
// 007c8452  e979feffff           jmp 0x7c82d0
// 007c8457  c20800               ret 8
// library xtp-15.2.1/Source\Calendar\XTPCalendarEventLabel.cpp (function ?InsertAt@?$CXTPArrayT@IIJ@@UAEXHPAV1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Calendar/XTPCalendarEventLabel.cpp
