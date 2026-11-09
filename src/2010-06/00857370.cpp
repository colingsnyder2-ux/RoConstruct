// from server: 100% by auto
// roc 2010-06 00857370  unit: PAVCXTPReportHyperlink::?$CXTPArrayT  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00857370
//
// 00857370  8b442408             mov eax, dword ptr [esp + 8]
// 00857374  85c0                 test eax, eax
// 00857376  740f                 je 0x857387
// 00857378  83c020               add eax, 0x20
// 0085737b  89442408             mov dword ptr [esp + 8], eax
// 0085737f  83c120               add ecx, 0x20
// 00857382  e979feffff           jmp 0x857200
// 00857387  c20800               ret 8
// library xtp-13.2.1/Source\Calendar\XTPCalendarEventLabel.cpp (function ?InsertAt@?$CXTPArrayT@IIJ@@UAEXHPAV1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Calendar/XTPCalendarEventLabel.cpp
