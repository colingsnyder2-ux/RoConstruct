// from server: 100% by auto
// roc 2009-06 00740380  unit: PAVCXTPReportInplaceButton::?$CArray  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00740380
//
// 00740380  56                   push esi
// 00740381  8bf1                 mov esi, ecx
// 00740383  e8a2bb1000           call 0x84bf2a
// 00740388  8d4e20               lea ecx, [esi + 0x20]
// 0074038b  c7062c458f00         mov dword ptr [esi], 0x8f452c
// 00740391  e8fafeffff           call 0x740290
// 00740396  8bc6                 mov eax, esi
// 00740398  5e                   pop esi
// 00740399  c3                   ret 
// library xtp-15.2.1/Source\Calendar\XTPCalendarCaptionBarControl.cpp (function ??0?$CXTPCalendarPtrCollectionT@VCXTPCalendarCaptionBarThemePart@@@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Calendar/XTPCalendarCaptionBarControl.cpp
