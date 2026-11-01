// from server: 100% by auto
// roc 2009-06 007d3260  unit: CXTPDockingPaneWindowSelect  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007d3260
//
// 007d3260  c701bc689000         mov dword ptr [ecx], 0x9068bc
// 007d3266  83c108               add ecx, 8
// 007d3269  e972eaffff           jmp 0x7d1ce0
// library xtp-15.2.1/Source\Calendar\XTPCalendarMAPIDataProvider.cpp (function ??1CXTPMAPIBinary@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Calendar/XTPCalendarMAPIDataProvider.cpp
