// from server: 100% by auto
// roc 2010-06 0041af00  unit: CXTPReportGroupRow_Batch  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0041af00
//
// 0041af00  8b01                 mov eax, dword ptr [ecx]
// 0041af02  ffa0b8010000         jmp dword ptr [eax + 0x1b8]
// library xtp-13.2.1/Source\Calendar\XTPCalendarControl.cpp (function ??_9CXTPCalendarControl@@$BBLI@AE)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Calendar/XTPCalendarControl.cpp
