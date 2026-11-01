// from server: 100% by auto
// roc 2009-12 008a3200  unit: PAVCXTPReportHyperlink::?$CXTPArrayT  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008a3200
//
// 008a3200  8b442408             mov eax, dword ptr [esp + 8]
// 008a3204  85c0                 test eax, eax
// 008a3206  740f                 je 0x8a3217
// 008a3208  83c020               add eax, 0x20
// 008a320b  89442408             mov dword ptr [esp + 8], eax
// 008a320f  83c120               add ecx, 0x20
// 008a3212  e979feffff           jmp 0x8a3090
// 008a3217  c20800               ret 8
// library xtp-15.2.1/Source\Calendar\XTPCalendarEventLabel.cpp (function ?InsertAt@?$CXTPArrayT@IIJ@@UAEXHPAV1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Calendar/XTPCalendarEventLabel.cpp
