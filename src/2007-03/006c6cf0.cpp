// from server: 100% by auto
// roc 2007-03 006c6cf0  unit: seg_006c0000  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006c6cf0
//
// 006c6cf0  c7010c637d00         mov dword ptr [ecx], 0x7d630c
// 006c6cf6  83c108               add ecx, 8
// 006c6cf9  e952e9ffff           jmp 0x6c5650
// library xtp-15.2.1/Source\Calendar\XTPCalendarMAPIDataProvider.cpp (function ??1CXTPMAPIBinary@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Calendar/XTPCalendarMAPIDataProvider.cpp
