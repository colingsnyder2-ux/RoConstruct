// from server: 100% by auto
// roc 2009-12 008adec0  unit: CXTPDockingPaneWindowSelect  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008adec0
//
// 008adec0  c7012c6da000         mov dword ptr [ecx], 0xa06d2c
// 008adec6  83c108               add ecx, 8
// 008adec9  e972eaffff           jmp 0x8ac940
// library xtp-15.2.1/Source\Calendar\XTPCalendarMAPIDataProvider.cpp (function ??1CXTPMAPIBinary@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Calendar/XTPCalendarMAPIDataProvider.cpp
