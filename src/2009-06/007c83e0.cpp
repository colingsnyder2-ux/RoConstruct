// from server: 100% by auto
// roc 2009-06 007c83e0  unit: CXTPReportHyperlinks  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007c83e0
//
// 007c83e0  56                   push esi
// 007c83e1  8bf1                 mov esi, ecx
// 007c83e3  e8423b0800           call 0x84bf2a
// 007c83e8  8d4e20               lea ecx, [esi + 0x20]
// 007c83eb  c70604559000         mov dword ptr [esi], 0x905504
// 007c83f1  e87afeffff           call 0x7c8270
// 007c83f6  8bc6                 mov eax, esi
// 007c83f8  5e                   pop esi
// 007c83f9  c3                   ret 
// library xtp-15.2.1/Source\Calendar\XTPCalendarCaptionBarControl.cpp (function ??0?$CXTPCalendarPtrCollectionT@VCXTPCalendarCaptionBarThemePart@@@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Calendar/XTPCalendarCaptionBarControl.cpp
