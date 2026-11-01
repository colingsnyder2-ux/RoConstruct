// from server: 100% by auto
// roc 2007-03 006b60d0  unit: seg_006b0000  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006b60d0
//
// 006b60d0  8b442408             mov eax, dword ptr [esp + 8]
// 006b60d4  85c0                 test eax, eax
// 006b60d6  740f                 je 0x6b60e7
// 006b60d8  83c020               add eax, 0x20
// 006b60db  89442408             mov dword ptr [esp + 8], eax
// 006b60df  83c120               add ecx, 0x20
// 006b60e2  e9b9feffff           jmp 0x6b5fa0
// 006b60e7  c20800               ret 8
// library xtp-15.2.1/Source\Calendar\XTPCalendarEventLabel.cpp (function ?InsertAt@?$CXTPArrayT@IIJ@@UAEXHPAV1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Calendar/XTPCalendarEventLabel.cpp
